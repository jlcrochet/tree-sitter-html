#include "tree_sitter/parser.h"
#include "tree_sitter/alloc.h"
#include "tree_sitter/array.h"
#include <wctype.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include "tables/html_elements.h"

#define XXH_INLINE_ALL
#define XXH_STATIC_LINKING_ONLY
#include "xxHash/xxhash.h"

enum TokenType {
  START_TAG_NAME,
  START_TAG_NAME_SCRIPT,
  START_TAG_NAME_STYLE,
  START_TAG_NAME_VOID,
  END_TAG_NAME,
  ERRONEOUS_END_TAG_NAME,
  SELF_CLOSING_TAG_DELIMITER,
  IMPLICIT_END_TAG,
  RAW_TEXT,
  COMMENT,
};

// Tag stack stores enum Element for known HTML elements
typedef Array(enum Element) TagStack;

// For foreign elements (E_Unknown), we store their xxHash hashes
typedef Array(XXH64_hash_t) HashStack;

typedef struct {
  TagStack tags;
  HashStack hashes;
} Scanner;

// Helper to check if an element is void (self-closing)
static inline bool is_void_element(enum Element element) {
  switch (element) {
    case E_area:
    case E_base:
    case E_br:
    case E_col:
    case E_embed:
    case E_hr:
    case E_img:
    case E_input:
    case E_link:
    case E_meta:
    case E_param:
    case E_source:
    case E_track:
    case E_wbr:
      return true;
    default:
      return false;
  }
}

void *tree_sitter_html_external_scanner_create() {
  Scanner *scanner = ts_calloc(1, sizeof(Scanner));
  array_init(&scanner->tags);
  array_init(&scanner->hashes);
  return scanner;
}

void tree_sitter_html_external_scanner_destroy(void *payload) {
  Scanner *scanner = (Scanner *)payload;
  array_delete(&scanner->tags);
  array_delete(&scanner->hashes);
  ts_free(scanner);
}

unsigned tree_sitter_html_external_scanner_serialize(void *payload, char *buffer) {
  Scanner *scanner = (Scanner *)payload;
  uint32_t size = 0;

  // Serialize tag count
  uint32_t tag_count = scanner->tags.size;
  if (tag_count > UINT8_MAX) tag_count = UINT8_MAX;
  buffer[size++] = (char)tag_count;

  // Serialize tags and hashes
  for (uint32_t i = 0; i < tag_count && size < TREE_SITTER_SERIALIZATION_BUFFER_SIZE - 9; i++) {
    enum Element elem = scanner->tags.contents[i];
    buffer[size++] = (char)elem;

    // If it's a foreign element, serialize its hash
    if (elem == E_Unknown && i < scanner->hashes.size) {
      XXH64_hash_t hash = scanner->hashes.contents[i];
      memcpy(&buffer[size], &hash, sizeof(XXH64_hash_t));
      size += sizeof(XXH64_hash_t);
    }
  }

  return size;
}

void tree_sitter_html_external_scanner_deserialize(void *payload, const char *buffer, unsigned length) {
  Scanner *scanner = (Scanner *)payload;

  array_clear(&scanner->tags);
  array_clear(&scanner->hashes);

  if (length == 0) return;

  uint32_t size = 0;
  uint32_t tag_count = (uint8_t)buffer[size++];

  for (uint32_t i = 0; i < tag_count && size < length; i++) {
    enum Element elem = (enum Element)buffer[size++];
    array_push(&scanner->tags, elem);

    // If it's a foreign element, deserialize its hash
    if (elem == E_Unknown && size + sizeof(XXH64_hash_t) <= length) {
      XXH64_hash_t hash;
      memcpy(&hash, &buffer[size], sizeof(XXH64_hash_t));
      size += sizeof(XXH64_hash_t);
      array_push(&scanner->hashes, hash);
    } else if (elem == E_Unknown) {
      array_push(&scanner->hashes, 0);
    }
  }
}

static void advance(TSLexer *lexer) {
  lexer->advance(lexer, false);
}

static void skip(TSLexer *lexer) {
  lexer->advance(lexer, true);
}

static bool scan_comment(TSLexer *lexer) {
  if (lexer->lookahead != '<') return false;
  advance(lexer);
  if (lexer->lookahead != '!') return false;
  advance(lexer);
  if (lexer->lookahead != '-') return false;
  advance(lexer);
  if (lexer->lookahead != '-') return false;
  advance(lexer);

  unsigned dashes = 0;
  while (lexer->lookahead != 0) {
    if (lexer->lookahead == '-') {
      dashes++;
      advance(lexer);
    } else if (lexer->lookahead == '>' && dashes >= 2) {
      advance(lexer);
      lexer->result_symbol = COMMENT;
      return true;
    } else {
      dashes = 0;
      advance(lexer);
    }
  }
  return false;
}

// Scan a tag name and return its element enum and hash
static bool scan_tag_name(TSLexer *lexer, enum Element *element, XXH64_hash_t *hash) {
  char tag_name[64];
  size_t len = 0;

  // Scan tag name characters
  while (lexer->lookahead != 0 && !iswspace(lexer->lookahead) &&
         lexer->lookahead != '>' && lexer->lookahead != '/' &&
         lexer->lookahead != '<' && len < sizeof(tag_name) - 1) {
    tag_name[len++] = tolower(lexer->lookahead);
    advance(lexer);
  }

  if (len == 0) return false;

  // Lookup element
  *element = lookup_element(tag_name, len);

  // If unknown, compute hash
  if (*element == E_Unknown) {
    *hash = XXH64(tag_name, len, 0);
  } else {
    *hash = 0;
  }

  return true;
}

static bool scan_raw_text(TSLexer *lexer, Scanner *scanner) {
  if (scanner->tags.size == 0) return false;

  enum Element top_element = scanner->tags.contents[scanner->tags.size - 1];

  // Only scan raw text for script and style elements
  if (top_element != E_script && top_element != E_style) {
    return false;
  }

  XXH64_hash_t top_hash = 0;
  if (top_element == E_Unknown && scanner->hashes.size > 0) {
    // Find the corresponding hash by counting E_Unknown elements
    uint32_t unknown_count = 0;
    for (uint32_t i = 0; i < scanner->tags.size; i++) {
      if (scanner->tags.contents[i] == E_Unknown) {
        unknown_count++;
      }
    }
    if (unknown_count > 0 && unknown_count <= scanner->hashes.size) {
      top_hash = scanner->hashes.contents[unknown_count - 1];
    }
  }

  lexer->mark_end(lexer);

  bool has_content = false;
  while (lexer->lookahead != 0) {
    if (lexer->lookahead == '<') {
      lexer->mark_end(lexer);
      advance(lexer);
      if (lexer->lookahead == '/') {
        advance(lexer);
        enum Element end_element;
        XXH64_hash_t end_hash;
        if (scan_tag_name(lexer, &end_element, &end_hash)) {
          // Check if it matches the top of stack
          if (top_element == E_Unknown) {
            if (end_element == E_Unknown && end_hash == top_hash) {
              lexer->result_symbol = RAW_TEXT;
              return has_content;
            }
          } else if (end_element == top_element) {
            lexer->result_symbol = RAW_TEXT;
            return has_content;
          }
        }
      }
    } else {
      has_content = true;
      advance(lexer);
    }
  }

  return false;
}

bool tree_sitter_html_external_scanner_scan(void *payload, TSLexer *lexer, const bool *valid_symbols) {
  Scanner *scanner = (Scanner *)payload;


  if (valid_symbols[COMMENT]) {
    bool result = scan_comment(lexer);
    if (result) return true;
  }

  if (valid_symbols[RAW_TEXT]) {
    bool result = scan_raw_text(lexer, scanner);
    if (result) return true;
  }

  while (iswspace(lexer->lookahead)) {
    skip(lexer);
  }

  // Handle start tag names
  if (valid_symbols[START_TAG_NAME] || valid_symbols[START_TAG_NAME_SCRIPT] ||
      valid_symbols[START_TAG_NAME_STYLE] || valid_symbols[START_TAG_NAME_VOID]) {
    enum Element element;
    XXH64_hash_t hash;

    if (scan_tag_name(lexer, &element, &hash)) {
      if (valid_symbols[START_TAG_NAME_SCRIPT] && element == E_script) {
        array_push(&scanner->tags, element);
        lexer->result_symbol = START_TAG_NAME_SCRIPT;
        lexer->mark_end(lexer);
        return true;
      }
      if (valid_symbols[START_TAG_NAME_STYLE] && element == E_style) {
        array_push(&scanner->tags, element);
        lexer->result_symbol = START_TAG_NAME_STYLE;
        lexer->mark_end(lexer);
        return true;
      }
      // Check for void elements
      if (valid_symbols[START_TAG_NAME_VOID] && is_void_element(element)) {
        // Don't push void elements to the stack
        lexer->result_symbol = START_TAG_NAME_VOID;
        lexer->mark_end(lexer);
        return true;
      }
      if (valid_symbols[START_TAG_NAME]) {
        // Push non-void elements onto the stack
        array_push(&scanner->tags, element);
        if (element == E_Unknown) {
          array_push(&scanner->hashes, hash);
        }
        lexer->result_symbol = START_TAG_NAME;
        lexer->mark_end(lexer);
        return true;
      }
    }
  }

  // Handle end tag names
  if (valid_symbols[END_TAG_NAME] && scanner->tags.size > 0) {
    enum Element top_element = scanner->tags.contents[scanner->tags.size - 1];
    XXH64_hash_t top_hash = 0;

    if (top_element == E_Unknown && scanner->hashes.size > 0) {
      // Find the corresponding hash
      uint32_t unknown_count = 0;
      for (uint32_t i = 0; i < scanner->tags.size; i++) {
        if (scanner->tags.contents[i] == E_Unknown) {
          unknown_count++;
        }
      }
      if (unknown_count > 0 && unknown_count <= scanner->hashes.size) {
        top_hash = scanner->hashes.contents[unknown_count - 1];
      }
    }

    enum Element element;
    XXH64_hash_t hash;
    if (scan_tag_name(lexer, &element, &hash)) {
      // Check if it matches the top of the stack
      bool matches = false;
      if (top_element == E_Unknown) {
        matches = (element == E_Unknown && hash == top_hash);
      } else {
        matches = (element == top_element);
      }

      if (matches) {
        array_pop(&scanner->tags);
        if (top_element == E_Unknown && scanner->hashes.size > 0) {
          array_pop(&scanner->hashes);
        }
        lexer->result_symbol = END_TAG_NAME;
        lexer->mark_end(lexer);
        return true;
      }
    }
  }

  // Handle erroneous end tags
  if (valid_symbols[ERRONEOUS_END_TAG_NAME]) {
    enum Element element;
    XXH64_hash_t hash;
    if (scan_tag_name(lexer, &element, &hash)) {
      lexer->result_symbol = ERRONEOUS_END_TAG_NAME;
      lexer->mark_end(lexer);
      return true;
    }
  }

  // Handle self-closing tag delimiter
  if (valid_symbols[SELF_CLOSING_TAG_DELIMITER] && lexer->lookahead == '/') {
    advance(lexer);
    if (lexer->lookahead == '>') {
      advance(lexer);
      // Pop the tag we just pushed if it's on the stack
      if (scanner->tags.size > 0) {
        enum Element top = scanner->tags.contents[scanner->tags.size - 1];
        array_pop(&scanner->tags);
        if (top == E_Unknown && scanner->hashes.size > 0) {
          array_pop(&scanner->hashes);
        }
      }
      lexer->result_symbol = SELF_CLOSING_TAG_DELIMITER;
      return true;
    }
  }

  // Handle implicit end tags
  // Only return implicit end tag in specific cases, not always when valid
  // For now, we don't automatically close tags
  if (valid_symbols[IMPLICIT_END_TAG] && scanner->tags.size > 0) {
    // TODO: Implement proper HTML5 tag closing rules
    // For now, don't automatically close any tags
  }

  return false;
}
