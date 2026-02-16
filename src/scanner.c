#include <stdint.h>
#include <string.h>

#define XXH_INLINE_ALL
// We're only calling XXH32(), so these modifiers are okay:
#define XXH_NO_STDLIB
#define XXH_NO_XXH3
#define XXH_NO_LONG_LONG
#define XXH_NO_STREAM
#include "vendor/xxHash/xxhash.h"

#include "helpers.h"
#include "tables/html_elements.h"
#include "tables/mathml_elements.h"
#include "tables/svg_elements.h"
#include "tables/full_character_references.h"
#include "tables/short_character_references.h"
#include "tree_sitter/parser.h"
#include "tree_sitter/alloc.h"
#include "tree_sitter/array.h"

#define ELEMENT_COUNT_MAX (UINT8_MAX + 1)
#if HtmlElement_Count > ELEMENT_COUNT_MAX || MathmlElement_Count > ELEMENT_COUNT_MAX || SvgElement_Count > ELEMENT_COUNT_MAX
#error "One or more of the element enums has exceeded 256 values; need to upgrade to uint16_t"
#endif

#define TAG_NAME_INLINE_BUFFER_SIZE 32
#define CHARACTER_REFERENCE_INLINE_BUFFER_SIZE 16
#define FULL_CHARACTER_REFERENCE_NAME_MAX 31
#define SHORT_CHARACTER_REFERENCE_NAME_MIN 2
#define SHORT_CHARACTER_REFERENCE_NAME_MAX 6

typedef enum HtmlElement HtmlElement;
typedef enum MathmlElement MathmlElement;
typedef enum SvgElement SvgElement;
typedef enum FullCharacterReference FullCharacterReference;
typedef enum ShortCharacterReference ShortCharacterReference;

typedef enum {
    HtmlTokenType_StartTagName,
    HtmlTokenType_VoidStartTagName,
    HtmlTokenType_RawTextStartTagName,
    HtmlTokenType_EscapableRawTextStartTagName,
    HtmlTokenType_EndTagName,
    HtmlTokenType_ErroneousEndTagName,
    HtmlTokenType_SelfClosingTagDelimiter,
    HtmlTokenType_Equals,
    HtmlTokenType_ImpliedEndTag,
    HtmlTokenType_Text,
    HtmlTokenType_RawText,
    HtmlTokenType_EscapableRawText,
    HtmlTokenType_FullCharacterReference,
    HtmlTokenType_ShortCharacterReference,
    HtmlTokenType_InvalidCharacterReference,
    HtmlTokenType_CdataText,
    HtmlTokenType_CommentText,
    // This is *not* a token type; it is used by scanners for other languages that need to embed this scanner and add more token types.
    _HtmlTokenType_End
} HtmlTokenType;

typedef enum {
    ElementNamespace_HTML,
    ElementNamespace_MathML,
    ElementNamespace_SVG
} ElementNamespace;

typedef struct {
    #ifndef NO_IMPLIED_END_TAGS
    // Cached tag name from lookahead during implied end tag scanning
    bool cached_tag;
    uint8_t cached_tag_name;
    XXH32_hash_t cached_tag_name_hash;
    // Number of codepoints consumed by the cached tag name in the input stream
    uint32_t cached_tag_name_length;
    // Whether the cached tag name was followed by a proper tag-name terminator
    bool cached_tag_has_terminator;
    uint8_t implied_end_tags;
    #endif

    Array(uint8_t /* ElementNamespace */) namespaces;
    Array(uint8_t) open_elements;
    Array(XXH32_hash_t) custom_name_hashes;
    Array(char) tag_name_buffer;
    Array(char) character_reference_buffer;
} Scanner;

static ElementNamespace get_current_namespace(Scanner *scanner) {
    if (scanner->namespaces.size > 0)
        return scanner->namespaces.contents[scanner->namespaces.size - 1];
    else
        // If no top-level elements have been pushed onto the stack yet, the default namespace is HTML
        return ElementNamespace_HTML;
}

static uint8_t get_current_tag(Scanner *scanner) {
    if (scanner->open_elements.size > 0)
        return scanner->open_elements.contents[scanner->open_elements.size - 1];
    else
        // If no elements have been pushed onto the stack yet, the default root element is `html`
        return HtmlElement_html;
}

static uint8_t lookup_element(const char *name, size_t length, ElementNamespace ns) {
    switch (ns) {
        case ElementNamespace_HTML: return lookup_html_element(name, length);
        case ElementNamespace_MathML: return lookup_mathml_element(name, length);
        case ElementNamespace_SVG: return lookup_svg_element(name, length);
        default: return 0;
    }
}

static inline bool is_html_void_element(uint8_t element) {
    switch (element) {
        case HtmlElement_area:
        case HtmlElement_base:
        case HtmlElement_br:
        case HtmlElement_col:
        case HtmlElement_embed:
        case HtmlElement_hr:
        case HtmlElement_img:
        case HtmlElement_input:
        case HtmlElement_link:
        case HtmlElement_meta:
        case HtmlElement_source:
        case HtmlElement_track:
        case HtmlElement_wbr:
            return true;
        default:
            return false;
    }
}

static bool try_get_array_byte_count(size_t size, size_t elem_size, size_t *byte_count) {
    if (elem_size > 0 && size > SIZE_MAX / elem_size)
        return false;
    *byte_count = size * elem_size;
    return true;
}

static bool serialize_array_bounded(
    char **offset,
    const char *end,
    const void *contents,
    size_t size,
    size_t elem_size
) {
    size_t size_len = vlq_length(size);
    if ((size_t)(end - *offset) < size_len)
        return false;
    *offset += to_vlq(size, *offset);

    size_t byte_count = 0;
    if (!try_get_array_byte_count(size, elem_size, &byte_count))
        return false;
    if ((size_t)(end - *offset) < byte_count)
        return false;

    if (byte_count > 0) {
        memcpy(*offset, contents, byte_count);
        *offset += byte_count;
    }

    return true;
}

static bool deserialize_array_bounded(
    const char **offset,
    const char *end,
    Array *array,
    size_t elem_size
) {
    size_t size = 0;
    size_t consumed = 0;
    if (!from_vlq_bounded(*offset, end, &size, &consumed))
        return false;
    *offset += consumed;

    if (size > UINT32_MAX)
        return false;

    size_t byte_count = 0;
    if (!try_get_array_byte_count(size, elem_size, &byte_count))
        return false;
    if ((size_t)(end - *offset) < byte_count)
        return false;

    if (size > 0) {
        _array__splice(array, elem_size, array->size, 0, (uint32_t)size, *offset);
        *offset += byte_count;
    }

    return true;
}

#ifndef NDEBUG
static bool scanner_state_is_valid(Scanner *scanner) {
    uint32_t unknown_count = 0;

    if (scanner->namespaces.size > scanner->open_elements.size)
        return false;

    for (uint32_t i = 0; i < scanner->namespaces.size; i++) {
        if (scanner->namespaces.contents[i] > ElementNamespace_SVG)
            return false;
    }

    for (uint32_t i = 0; i < scanner->open_elements.size; i++) {
        if (scanner->open_elements.contents[i] == 0)
            unknown_count++;
    }

    return scanner->custom_name_hashes.size == unknown_count;
}
#endif

static inline void clear_serialized_scanner_state(Scanner *scanner) {
    #ifndef NO_IMPLIED_END_TAGS
    scanner->cached_tag = false;
    scanner->cached_tag_name = 0;
    scanner->cached_tag_name_hash = 0;
    scanner->cached_tag_name_length = 0;
    scanner->cached_tag_has_terminator = false;
    scanner->implied_end_tags = 0;
    #endif

    array_clear(&scanner->namespaces);
    array_clear(&scanner->open_elements);
    array_clear(&scanner->custom_name_hashes);
}

static inline void push_open_element(Scanner *scanner, uint8_t element, XXH32_hash_t name_hash) {
    array_push(&scanner->open_elements, element);
    if (element == 0)
        array_push(&scanner->custom_name_hashes, name_hash);
}

static inline void maybe_pop_current_namespace(Scanner *scanner, uint8_t element) {
    if (scanner->namespaces.size == 0)
        return;

    ElementNamespace ns = get_current_namespace(scanner);
    bool closes_namespace_root =
        (ns == ElementNamespace_HTML && element == HtmlElement_html) ||
        (ns == ElementNamespace_MathML && element == MathmlElement_math) ||
        (ns == ElementNamespace_SVG && element == SvgElement_svg);

    if (closes_namespace_root)
        (void)array_pop(&scanner->namespaces);
}

static inline uint8_t pop_open_element(Scanner *scanner) {
    uint8_t element = array_pop(&scanner->open_elements);
    if (element == 0 && scanner->custom_name_hashes.size > 0)
        (void)array_pop(&scanner->custom_name_hashes);
    maybe_pop_current_namespace(scanner, element);
    return element;
}

void *tree_sitter_html_external_scanner_create(void) {
    return ts_calloc(1, sizeof(Scanner));
}

void tree_sitter_html_external_scanner_destroy(void *payload) {
    Scanner *scanner = (Scanner *)payload;
    array_delete(&scanner->namespaces);
    array_delete(&scanner->open_elements);
    array_delete(&scanner->custom_name_hashes);
    array_delete(&scanner->tag_name_buffer);
    array_delete(&scanner->character_reference_buffer);
    ts_free(scanner);
}

unsigned tree_sitter_html_external_scanner_serialize(void *payload, char *buffer) {
    Scanner *scanner = (Scanner *)payload;

    char *offset = buffer;
    const char *end = buffer + TREE_SITTER_SERIALIZATION_BUFFER_SIZE;

    #ifndef NO_IMPLIED_END_TAGS
    if ((size_t)(end - offset) < 2 + sizeof(XXH32_hash_t) + sizeof(uint32_t) + 1 + 1)
        return 0;
    *offset++ = (char)scanner->cached_tag;
    *offset++ = (char)scanner->cached_tag_name;
    memcpy(offset, &scanner->cached_tag_name_hash, sizeof(XXH32_hash_t));
    offset += sizeof(XXH32_hash_t);
    memcpy(offset, &scanner->cached_tag_name_length, sizeof(uint32_t));
    offset += sizeof(uint32_t);
    *offset++ = (char)scanner->cached_tag_has_terminator;
    *offset++ = (char)scanner->implied_end_tags;
    #endif

    if (!serialize_array_bounded(
        &offset,
        end,
        scanner->namespaces.contents,
        scanner->namespaces.size,
        array_elem_size(&scanner->namespaces)
    )) return 0;

    if (!serialize_array_bounded(
        &offset,
        end,
        scanner->open_elements.contents,
        scanner->open_elements.size,
        array_elem_size(&scanner->open_elements)
    )) return 0;

    if (!serialize_array_bounded(
        &offset,
        end,
        scanner->custom_name_hashes.contents,
        scanner->custom_name_hashes.size,
        array_elem_size(&scanner->custom_name_hashes)
    )) return 0;

    return offset - buffer;
}

void tree_sitter_html_external_scanner_deserialize(void *payload, const char *buffer, unsigned length) {
    Scanner *scanner = (Scanner *)payload;
    clear_serialized_scanner_state(scanner);

    if (length == 0) return;

    const char *offset = buffer;
    const char *end = buffer + length;

    #ifndef NO_IMPLIED_END_TAGS
    if ((size_t)(end - offset) < 2 + sizeof(XXH32_hash_t) + sizeof(uint32_t) + 1 + 1) return;
    scanner->cached_tag = (bool)*offset++;
    scanner->cached_tag_name = (uint8_t)*offset++;
    memcpy(&scanner->cached_tag_name_hash, offset, sizeof(XXH32_hash_t));
    offset += sizeof(XXH32_hash_t);
    memcpy(&scanner->cached_tag_name_length, offset, sizeof(uint32_t));
    offset += sizeof(uint32_t);
    scanner->cached_tag_has_terminator = (bool)*offset++;
    scanner->implied_end_tags = (uint8_t)*offset++;
    #endif

    if (!deserialize_array_bounded(
        &offset,
        end,
        (Array *)&scanner->namespaces,
        array_elem_size(&scanner->namespaces)
    )) goto invalid_state;

    if (!deserialize_array_bounded(
        &offset,
        end,
        (Array *)&scanner->open_elements,
        array_elem_size(&scanner->open_elements)
    )) goto invalid_state;

    if (!deserialize_array_bounded(
        &offset,
        end,
        (Array *)&scanner->custom_name_hashes,
        array_elem_size(&scanner->custom_name_hashes)
    )) goto invalid_state;

    #ifndef NDEBUG
    if (!scanner_state_is_valid(scanner))
        goto invalid_state;
    #endif

    return;

invalid_state:
    clear_serialized_scanner_state(scanner);
}

static inline void advance(TSLexer *lexer) {
    lexer->advance(lexer, false);
}

static inline void skip(TSLexer *lexer) {
    lexer->advance(lexer, true);
}

static bool scan_char(TSLexer *lexer, int c) {
    if (lexer->lookahead == c) {
        advance(lexer);
        return true;
    } else {
        return false;
    }
}

// Scan a tag name and return its element enum in the given namespace as well as its custom name hash, if any.
// Note: HTML lowercases only ASCII letters; non-ASCII is preserved.
// Ref: https://html.spec.whatwg.org/multipage/parsing.html#tag-name-state
static bool scan_tag_name(
    TSLexer *lexer,
    Scanner *scanner,
    ElementNamespace ns,
    uint8_t *element,
    XXH32_hash_t *name_hash,
    uint32_t *name_length,
    bool *has_terminator
) {
    // Tag names must begin with an ASCII alpha character in the tag-open state
    if (!is_ascii_alpha(lexer->lookahead))
        return false;

    char inline_tag_name_buffer[TAG_NAME_INLINE_BUFFER_SIZE];
    size_t byte_length = 0;
    bool using_dynamic_buffer = false;

    #define APPEND_TAG_NAME_BYTES(BYTES, COUNT) \
        { \
            size_t _count = (COUNT); \
            if (_count > 0) { \
                if (!using_dynamic_buffer && byte_length + _count <= sizeof(inline_tag_name_buffer)) { \
                    memcpy(inline_tag_name_buffer + byte_length, (BYTES), _count); \
                } else { \
                    if (!using_dynamic_buffer) { \
                        array_clear(&scanner->tag_name_buffer); \
                        if (byte_length > 0) \
                            array_extend(&scanner->tag_name_buffer, byte_length, inline_tag_name_buffer); \
                        using_dynamic_buffer = true; \
                    } \
                    array_extend(&scanner->tag_name_buffer, _count, (BYTES)); \
                } \
                byte_length += _count; \
            } \
        }

    char first_char = (char)ascii_tolower(lexer->lookahead);
    APPEND_TAG_NAME_BYTES(&first_char, 1);
    advance(lexer);

    bool must_be_unknown = false;
    uint32_t length = 1;

    while (!lexer->eof(lexer)) {
        if (is_html_whitespace(lexer->lookahead) || lexer->lookahead == '/' || lexer->lookahead == '>') {
            break;
        } else if (lexer->lookahead == '\0') {
            // If NULL is reached before EOF somehow, append U+FFFD REPLACEMENT CHARACTER to the name
            must_be_unknown = true;
            static const char replacement_character_utf8[] = { (char)0xEF, (char)0xBF, (char)0xBD };
            APPEND_TAG_NAME_BYTES(replacement_character_utf8, sizeof(replacement_character_utf8));
        } else if (is_ascii_alnum(lexer->lookahead)) {
            char c = (char)ascii_tolower(lexer->lookahead);
            APPEND_TAG_NAME_BYTES(&c, 1);
        } else if (lexer->lookahead == '-') {
            static const char hyphen = '-';
            APPEND_TAG_NAME_BYTES(&hyphen, 1);
        } else if (is_ascii(lexer->lookahead)) {
            // Any other ASCII character is valid, but indicates an unknown element
            must_be_unknown = true;
            char c = (char)lexer->lookahead;
            APPEND_TAG_NAME_BYTES(&c, 1);
        } else {
            // All non-ASCII characters are valid in a tag name, but indicate an unknown element
            must_be_unknown = true;
            char bytes[4];
            size_t count = codepoint_to_utf8(bytes, lexer->lookahead);
            APPEND_TAG_NAME_BYTES(bytes, count);
        }
        advance(lexer);
        length++;
    }

    const char *name = using_dynamic_buffer
        ? scanner->tag_name_buffer.contents
        : inline_tag_name_buffer;

    // 0 represents an unknown element in any namespace
    *element = must_be_unknown
        ? 0
        : lookup_element(name, byte_length, ns);

    *name_hash = *element == 0
        ? XXH32(name, byte_length, 0)
        : 0;

    if (name_length)
        *name_length = length;
    if (has_terminator)
        *has_terminator = !lexer->eof(lexer);

    #undef APPEND_TAG_NAME_BYTES

    return true;
}

static bool scan_ascii_word_icase(TSLexer *lexer, const char *word, size_t length) {
    for (size_t i = 0; i < length; i++) {
        int32_t c = lexer->lookahead;
        if (!is_ascii(c))
            return false;
        if ((char)ascii_tolower(c) != word[i])
            return false;
        advance(lexer);
    }
    return true;
}

static inline bool is_common_short_character_reference(const char *name, size_t length) {
    switch (length) {
        case 2:
            return
                (name[0] == 'l' && name[1] == 't') ||
                (name[0] == 'g' && name[1] == 't') ||
                (name[0] == 'L' && name[1] == 'T') ||
                (name[0] == 'G' && name[1] == 'T');
        case 3:
            return
                (name[0] == 'a' && name[1] == 'm' && name[2] == 'p') ||
                (name[0] == 'A' && name[1] == 'M' && name[2] == 'P') ||
                (name[0] == 'n' && name[1] == 'o' && name[2] == 't');
        case 4:
            return
                (name[0] == 'q' && name[1] == 'u' && name[2] == 'o' && name[3] == 't') ||
                (name[0] == 'Q' && name[1] == 'U' && name[2] == 'O' && name[3] == 'T') ||
                (name[0] == 'n' && name[1] == 'b' && name[2] == 's' && name[3] == 'p');
        default:
            return false;
    }
}

static inline bool is_common_full_character_reference(const char *name, size_t length) {
    switch (length) {
        case 2:
            return
                (name[0] == 'l' && name[1] == 't') ||
                (name[0] == 'g' && name[1] == 't') ||
                (name[0] == 'L' && name[1] == 'T') ||
                (name[0] == 'G' && name[1] == 'T');
        case 3:
            return
                (name[0] == 'a' && name[1] == 'm' && name[2] == 'p') ||
                (name[0] == 'A' && name[1] == 'M' && name[2] == 'P') ||
                (name[0] == 'n' && name[1] == 'o' && name[2] == 't');
        case 4:
            return
                (name[0] == 'q' && name[1] == 'u' && name[2] == 'o' && name[3] == 't') ||
                (name[0] == 'Q' && name[1] == 'U' && name[2] == 'O' && name[3] == 'T') ||
                (name[0] == 'n' && name[1] == 'b' && name[2] == 's' && name[3] == 'p');
        case 5:
            return name[0] == 'a' && name[1] == 'p' && name[2] == 'o' && name[3] == 's';
        default:
            return false;
    }
}

static bool scan_raw_text_like(
    TSLexer *lexer,
    Scanner *scanner,
    HtmlTokenType result_symbol,
    bool stop_on_amp,
    HtmlElement tag_a,
    const char *name_a,
    size_t name_a_len,
    HtmlElement tag_b,
    const char *name_b,
    size_t name_b_len
) {
    if (stop_on_amp && lexer->lookahead == '&')
        return false;

    // Leading whitespace should not be included as part of the text
    while (is_html_whitespace(lexer->lookahead))
        skip(lexer);

    bool text_matched = false;

    HtmlElement top_tag = get_current_tag(scanner);
    const char *end_name = NULL;
    size_t end_len = 0;
    if (top_tag == tag_a) {
        end_name = name_a;
        end_len = name_a_len;
    } else if (top_tag == tag_b) {
        end_name = name_b;
        end_len = name_b_len;
    }

    lexer->mark_end(lexer);

    while (!lexer->eof(lexer) && (!stop_on_amp || lexer->lookahead != '&')) {
        int32_t c = lexer->lookahead;
        advance(lexer);

        if (c == '<') {
            // Check for the end tag
            if (lexer->lookahead == '/' && end_name) {
                advance(lexer);
                if (scan_ascii_word_icase(lexer, end_name, end_len)) {
                    if (is_html_whitespace(lexer->lookahead) || lexer->lookahead == '>' || lexer->lookahead == '/')
                        break;
                }
            }
            lexer->mark_end(lexer);
            text_matched = true;
        } else if (!is_html_whitespace(c)) {
            lexer->mark_end(lexer);
            text_matched = true;
        }
    }

    if (text_matched) {
        lexer->result_symbol = result_symbol;
        return true;
    }

    return false;
}

typedef enum {
    StartTagClosureClass_None = 0,
    StartTagClosureClass_Li = 1u << 0,
    StartTagClosureClass_DtDd = 1u << 1,
    StartTagClosureClass_PBlock = 1u << 2,
    StartTagClosureClass_RtRp = 1u << 3,
    StartTagClosureClass_Optgroup = 1u << 4,
    StartTagClosureClass_Option = 1u << 5,
    StartTagClosureClass_TbodyTfoot = 1u << 6,
    StartTagClosureClass_Tr = 1u << 7,
    StartTagClosureClass_TdTh = 1u << 8,
} StartTagClosureClass;

typedef enum {
    EndTagClosureClass_None = 0,
    EndTagClosureClass_UlOlMenu = 1u << 0,
    EndTagClosureClass_Dl = 1u << 1,
    EndTagClosureClass_Ruby = 1u << 2,
    EndTagClosureClass_SelectDatalistOptgroup = 1u << 3,
    EndTagClosureClass_Table = 1u << 4,
    EndTagClosureClass_TheadTbodyTfootTable = 1u << 5,
    EndTagClosureClass_TrTheadTbodyTfootTable = 1u << 6,
} EndTagClosureClass;

static const uint16_t start_tag_closing_class_for_opening[HtmlElement_Count] = {
    [HtmlElement_li] = StartTagClosureClass_Li,
    [HtmlElement_dt] = StartTagClosureClass_DtDd,
    [HtmlElement_dd] = StartTagClosureClass_DtDd,
    [HtmlElement_address] = StartTagClosureClass_PBlock,
    [HtmlElement_article] = StartTagClosureClass_PBlock,
    [HtmlElement_aside] = StartTagClosureClass_PBlock,
    [HtmlElement_blockquote] = StartTagClosureClass_PBlock,
    [HtmlElement_details] = StartTagClosureClass_PBlock,
    [HtmlElement_dialog] = StartTagClosureClass_PBlock,
    [HtmlElement_div] = StartTagClosureClass_PBlock,
    [HtmlElement_dl] = StartTagClosureClass_PBlock,
    [HtmlElement_fieldset] = StartTagClosureClass_PBlock,
    [HtmlElement_figcaption] = StartTagClosureClass_PBlock,
    [HtmlElement_figure] = StartTagClosureClass_PBlock,
    [HtmlElement_footer] = StartTagClosureClass_PBlock,
    [HtmlElement_form] = StartTagClosureClass_PBlock,
    [HtmlElement_h1] = StartTagClosureClass_PBlock,
    [HtmlElement_h2] = StartTagClosureClass_PBlock,
    [HtmlElement_h3] = StartTagClosureClass_PBlock,
    [HtmlElement_h4] = StartTagClosureClass_PBlock,
    [HtmlElement_h5] = StartTagClosureClass_PBlock,
    [HtmlElement_h6] = StartTagClosureClass_PBlock,
    [HtmlElement_header] = StartTagClosureClass_PBlock,
    [HtmlElement_hgroup] = StartTagClosureClass_PBlock,
    [HtmlElement_hr] = StartTagClosureClass_PBlock,
    [HtmlElement_main] = StartTagClosureClass_PBlock,
    [HtmlElement_menu] = StartTagClosureClass_PBlock,
    [HtmlElement_nav] = StartTagClosureClass_PBlock,
    [HtmlElement_ol] = StartTagClosureClass_PBlock,
    [HtmlElement_p] = StartTagClosureClass_PBlock,
    [HtmlElement_pre] = StartTagClosureClass_PBlock,
    [HtmlElement_search] = StartTagClosureClass_PBlock,
    [HtmlElement_section] = StartTagClosureClass_PBlock,
    [HtmlElement_table] = StartTagClosureClass_PBlock,
    [HtmlElement_ul] = StartTagClosureClass_PBlock,
    [HtmlElement_rt] = StartTagClosureClass_RtRp,
    [HtmlElement_rp] = StartTagClosureClass_RtRp,
    [HtmlElement_optgroup] = StartTagClosureClass_Optgroup,
    [HtmlElement_option] = StartTagClosureClass_Option,
    [HtmlElement_tbody] = StartTagClosureClass_TbodyTfoot,
    [HtmlElement_tfoot] = StartTagClosureClass_TbodyTfoot,
    [HtmlElement_tr] = StartTagClosureClass_Tr,
    [HtmlElement_td] = StartTagClosureClass_TdTh,
    [HtmlElement_th] = StartTagClosureClass_TdTh,
};

static const uint16_t start_tag_closure_mask_for_current[HtmlElement_Count] = {
    [HtmlElement_li] = StartTagClosureClass_Li,
    [HtmlElement_dt] = StartTagClosureClass_DtDd,
    [HtmlElement_dd] = StartTagClosureClass_DtDd,
    [HtmlElement_p] = StartTagClosureClass_PBlock,
    [HtmlElement_rt] = StartTagClosureClass_RtRp,
    [HtmlElement_rp] = StartTagClosureClass_RtRp,
    [HtmlElement_optgroup] = StartTagClosureClass_Optgroup,
    [HtmlElement_option] = StartTagClosureClass_Optgroup | StartTagClosureClass_Option,
    [HtmlElement_thead] = StartTagClosureClass_TbodyTfoot,
    [HtmlElement_tbody] = StartTagClosureClass_TbodyTfoot,
    [HtmlElement_tr] = StartTagClosureClass_Tr,
    [HtmlElement_td] = StartTagClosureClass_TdTh,
    [HtmlElement_th] = StartTagClosureClass_TdTh,
};

static inline bool start_tag_closes_element(uint8_t current, uint16_t opening_class) {
    return (start_tag_closure_mask_for_current[current] & opening_class) != 0;
}

static const uint16_t end_tag_closing_class_for_closing[HtmlElement_Count] = {
    [HtmlElement_ul] = EndTagClosureClass_UlOlMenu,
    [HtmlElement_ol] = EndTagClosureClass_UlOlMenu,
    [HtmlElement_menu] = EndTagClosureClass_UlOlMenu,
    [HtmlElement_dl] = EndTagClosureClass_Dl,
    [HtmlElement_ruby] = EndTagClosureClass_Ruby,
    [HtmlElement_select] = EndTagClosureClass_SelectDatalistOptgroup,
    [HtmlElement_datalist] = EndTagClosureClass_SelectDatalistOptgroup,
    [HtmlElement_optgroup] = EndTagClosureClass_SelectDatalistOptgroup,
    [HtmlElement_table] = EndTagClosureClass_Table |
                          EndTagClosureClass_TheadTbodyTfootTable |
                          EndTagClosureClass_TrTheadTbodyTfootTable,
    [HtmlElement_thead] = EndTagClosureClass_TheadTbodyTfootTable |
                          EndTagClosureClass_TrTheadTbodyTfootTable,
    [HtmlElement_tbody] = EndTagClosureClass_TheadTbodyTfootTable |
                          EndTagClosureClass_TrTheadTbodyTfootTable,
    [HtmlElement_tfoot] = EndTagClosureClass_TheadTbodyTfootTable |
                          EndTagClosureClass_TrTheadTbodyTfootTable,
    [HtmlElement_tr] = EndTagClosureClass_TrTheadTbodyTfootTable,
};

static const uint16_t end_tag_closure_mask_for_current[HtmlElement_Count] = {
    [HtmlElement_li] = EndTagClosureClass_UlOlMenu,
    [HtmlElement_dt] = EndTagClosureClass_Dl,
    [HtmlElement_dd] = EndTagClosureClass_Dl,
    [HtmlElement_rt] = EndTagClosureClass_Ruby,
    [HtmlElement_rp] = EndTagClosureClass_Ruby,
    [HtmlElement_optgroup] = EndTagClosureClass_SelectDatalistOptgroup,
    [HtmlElement_option] = EndTagClosureClass_SelectDatalistOptgroup,
    [HtmlElement_thead] = EndTagClosureClass_Table,
    [HtmlElement_tbody] = EndTagClosureClass_Table,
    [HtmlElement_tfoot] = EndTagClosureClass_Table,
    [HtmlElement_tr] = EndTagClosureClass_TheadTbodyTfootTable,
    [HtmlElement_td] = EndTagClosureClass_TrTheadTbodyTfootTable,
    [HtmlElement_th] = EndTagClosureClass_TrTheadTbodyTfootTable,
};

static const bool end_tag_p_closure_exclusions[HtmlElement_Count] = {
    [HtmlElement_a] = true,
    [HtmlElement_audio] = true,
    [HtmlElement_del] = true,
    [HtmlElement_ins] = true,
    [HtmlElement_map] = true,
    [HtmlElement_noscript] = true,
    [HtmlElement_video] = true,
};

static inline bool end_tag_closes_element(uint8_t current, uint16_t closing_class, bool p_can_be_closed) {
    if (current == HtmlElement_p) {
        // p can be closed by most ancestor end tags, except this small exclusion set.
        return p_can_be_closed;
    }

    return (end_tag_closure_mask_for_current[current] & closing_class) != 0;
}

// Lookup table for elements that can have an implied end tag
static const bool implied_end_tag_elements[HtmlElement_Count] = {
    [HtmlElement_li] = true,
    [HtmlElement_dt] = true,
    [HtmlElement_dd] = true,
    [HtmlElement_p] = true,
    [HtmlElement_rt] = true,
    [HtmlElement_rp] = true,
    [HtmlElement_optgroup] = true,
    [HtmlElement_option] = true,
    [HtmlElement_thead] = true,
    [HtmlElement_tbody] = true,
    [HtmlElement_tfoot] = true,
    [HtmlElement_tr] = true,
    [HtmlElement_td] = true,
    [HtmlElement_th] = true,
};

static const uint16_t start_tag_closing_class_for_first_char[26] = {
    ['a' - 'a'] = StartTagClosureClass_PBlock,
    ['b' - 'a'] = StartTagClosureClass_PBlock,
    ['d' - 'a'] = StartTagClosureClass_DtDd | StartTagClosureClass_PBlock,
    ['f' - 'a'] = StartTagClosureClass_PBlock,
    ['h' - 'a'] = StartTagClosureClass_PBlock,
    ['l' - 'a'] = StartTagClosureClass_Li,
    ['m' - 'a'] = StartTagClosureClass_PBlock,
    ['n' - 'a'] = StartTagClosureClass_PBlock,
    ['o' - 'a'] = StartTagClosureClass_PBlock |
                  StartTagClosureClass_Optgroup |
                  StartTagClosureClass_Option,
    ['p' - 'a'] = StartTagClosureClass_PBlock,
    ['r' - 'a'] = StartTagClosureClass_RtRp,
    ['s' - 'a'] = StartTagClosureClass_PBlock,
    ['t' - 'a'] = StartTagClosureClass_TbodyTfoot |
                  StartTagClosureClass_Tr |
                  StartTagClosureClass_TdTh,
    ['u' - 'a'] = StartTagClosureClass_PBlock,
};

static const uint16_t end_tag_closing_class_for_first_char[26] = {
    ['d' - 'a'] = EndTagClosureClass_Dl |
                  EndTagClosureClass_SelectDatalistOptgroup,
    ['m' - 'a'] = EndTagClosureClass_UlOlMenu,
    ['o' - 'a'] = EndTagClosureClass_UlOlMenu |
                  EndTagClosureClass_SelectDatalistOptgroup,
    ['r' - 'a'] = EndTagClosureClass_Ruby,
    ['s' - 'a'] = EndTagClosureClass_SelectDatalistOptgroup,
    ['t' - 'a'] = EndTagClosureClass_Table |
                  EndTagClosureClass_TheadTbodyTfootTable |
                  EndTagClosureClass_TrTheadTbodyTfootTable,
    ['u' - 'a'] = EndTagClosureClass_UlOlMenu,
};

static inline uint16_t implied_start_tag_classes_for_first_char(int32_t first_char) {
    if (!is_ascii_alpha(first_char))
        return StartTagClosureClass_None;
    return start_tag_closing_class_for_first_char[ascii_tolower(first_char) - 'a'];
}

static inline uint16_t implied_end_tag_classes_for_first_char(int32_t first_char) {
    if (!is_ascii_alpha(first_char))
        return EndTagClosureClass_None;
    return end_tag_closing_class_for_first_char[ascii_tolower(first_char) - 'a'];
}

// Fast prefilter that avoids scanning a whole tag name when no element in the
// current implied-end chain can possibly be closed by a start tag beginning with
// the observed first character.
static bool maybe_implied_close_on_start_tag_first_char(Scanner *scanner, uint16_t opening_classes) {
    if (opening_classes == StartTagClosureClass_None)
        return false;

    for (size_t i = scanner->open_elements.size; i > 0; i--) {
        uint8_t elem = scanner->open_elements.contents[i - 1];
        if (!implied_end_tag_elements[elem])
            return false;
        if ((start_tag_closure_mask_for_current[elem] & opening_classes) != 0)
            return true;
    }

    return false;
}

// Similar prefilter for end tags based on first character + closure classes.
static bool maybe_implied_close_on_end_tag_first_char(Scanner *scanner, uint16_t closing_classes) {
    for (size_t i = scanner->open_elements.size; i > 0; i--) {
        uint8_t elem = scanner->open_elements.contents[i - 1];
        if (!implied_end_tag_elements[elem])
            return false;
        if (elem == HtmlElement_p)
            return true;
        if ((end_tag_closure_mask_for_current[elem] & closing_classes) != 0)
            return true;
    }

    return false;
}

// Count how many elements would be implicitly closed by an end tag for an ancestor.
// Searches from top to bottom for the closing element, counting closeable elements along the way.
// Returns the count of elements to close, or 0 if the ancestor is not found or
// if an element that can't have an implied end tag is encountered.
static uint8_t count_end_tag_implied_closes(Scanner *scanner, HtmlElement closing, XXH32_hash_t closing_hash) {
    uint16_t closing_class = end_tag_closing_class_for_closing[closing];
    bool p_can_be_closed = !end_tag_p_closure_exclusions[closing];

    if (closing_class == EndTagClosureClass_None && !p_can_be_closed)
        return 0;

    size_t unknown_count = scanner->custom_name_hashes.size;
    uint8_t close_count = 0;

    for (size_t i = scanner->open_elements.size; i > 0; i--) {
        uint8_t e = scanner->open_elements.contents[i - 1];

        bool is_ancestor = e == closing &&
                           (closing != 0 ||
                            (unknown_count > 0 &&
                             scanner->custom_name_hashes.contents[unknown_count - 1] == closing_hash));

        if (is_ancestor) {
            // Found the ancestor - return accumulated count (don't include the ancestor itself)
            return close_count;
        }

        if (!implied_end_tag_elements[e]) {
            // Hit an element that can't have an implied end tag, stop
            return 0;
        }

        // Check if this element can be implicitly closed
        if (end_tag_closes_element(e, closing_class, p_can_be_closed)) {
            close_count++;
        }

        if (e == 0) unknown_count--;
    }

    // Ancestor not found
    return 0;
}

// Count how many elements would be implicitly closed by a start tag.
// Searches from top to bottom for an element that the start tag closes,
// counting closeable elements along the way.
// Returns the count of elements to close, or 0 if no closing element is found or
// if an element that can't have an implied end tag is encountered.
static uint8_t count_start_tag_implied_closes(Scanner *scanner, HtmlElement opening) {
    uint16_t opening_class = start_tag_closing_class_for_opening[opening];
    if (opening_class == StartTagClosureClass_None)
        return 0;

    uint8_t close_count = 0;

    for (size_t i = scanner->open_elements.size; i > 0; i--) {
        uint8_t elem = scanner->open_elements.contents[i - 1];

        if (!implied_end_tag_elements[elem]) {
            // Hit an element that can't have an implied end tag, stop
            return 0;
        }

        if (start_tag_closes_element(elem, opening_class)) {
            // Found an element that the start tag closes - include it in the count
            return close_count + 1;
        }

        close_count++;
    }

    // No element found that the start tag closes
    return 0;
}

bool tree_sitter_html_external_scanner_scan(void *payload, TSLexer *lexer, const bool *valid_symbols) {
    Scanner *scanner = (Scanner *)payload;

    #define ASSERT(CONDITION) \
        if (!(CONDITION)) return false;

    #define SCAN(CHAR) \
        scan_char(lexer, CHAR)

    #define SCAN_ICASE(CHAR /* should be an uppercase ASCII letter */) \
        (SCAN(CHAR) || SCAN(CHAR | 0x0020))

    const bool can_match_short_character_reference = valid_symbols[HtmlTokenType_ShortCharacterReference];
    const bool can_match_full_character_reference = valid_symbols[HtmlTokenType_FullCharacterReference];
    const bool can_match_invalid_character_reference = valid_symbols[HtmlTokenType_InvalidCharacterReference];

    // Handle attribute equals sign - must come early before other checks
    if (valid_symbols[HtmlTokenType_Equals]) {
        // Skip optional whitespace before the equals sign
        while (is_html_whitespace(lexer->lookahead))
            skip(lexer);

        // Only match if we actually see an equals sign
        if (lexer->lookahead == '=') {
            advance(lexer);
            lexer->result_symbol = HtmlTokenType_Equals;
            return true;
        }
        // If no equals sign, fall through to let tree-sitter try other rules
    }

    if (valid_symbols[HtmlTokenType_StartTagName] || valid_symbols[HtmlTokenType_EndTagName]) {
        ElementNamespace ns = get_current_namespace(scanner);
        uint8_t e;
        XXH32_hash_t name_hash;

        #ifndef NO_IMPLIED_END_TAGS
        // Check for a cached tag from implied end tag lookahead
        if (ns == ElementNamespace_HTML && scanner->cached_tag) {
            e = scanner->cached_tag_name;
            name_hash = scanner->cached_tag_name_hash;
            if (!scanner->cached_tag_has_terminator) {
                scanner->cached_tag = false;
                return false;
            }
            // Advance past the tag name in the lexer
            for (uint32_t i = 0; i < scanner->cached_tag_name_length; i++) {
                if (lexer->eof(lexer)) {
                    scanner->cached_tag = false;
                    return false;
                }
                advance(lexer);
            }
            if (lexer->eof(lexer)) {
                scanner->cached_tag = false;
                return false;
            }
            scanner->cached_tag = false;
        } else {
            ASSERT(scan_tag_name(lexer, scanner, ns, &e, &name_hash, NULL, NULL));
        }
        #else
        ASSERT(scan_tag_name(lexer, scanner, ns, &e, &name_hash, NULL, NULL));
        #endif

        // Start tags
        if (valid_symbols[HtmlTokenType_StartTagName]) {
            // Start with the default token for start tag names and disambiguate below
            lexer->result_symbol = HtmlTokenType_StartTagName;
            bool is_void_html_tag = ns == ElementNamespace_HTML && is_html_void_element(e);

            if (is_void_html_tag) {
                lexer->result_symbol = HtmlTokenType_VoidStartTagName;
            } else {
                push_open_element(scanner, e, name_hash);

                switch (ns) {
                    case ElementNamespace_HTML:
                        switch (e) {
                            // Raw text elements
                            case HtmlElement_script:
                            case HtmlElement_style:
                                lexer->result_symbol = HtmlTokenType_RawTextStartTagName;
                                break;

                            // Escapable raw text elements
                            case HtmlElement_textarea:
                            case HtmlElement_title:
                                lexer->result_symbol = HtmlTokenType_EscapableRawTextStartTagName;
                                break;

                            // Top-level elements
                            case HtmlElement_html:
                                array_push(&scanner->namespaces, ElementNamespace_HTML);
                                break;
                            // For top-level elements of foreign namespaces, we need to make sure that we are pushing the value from that namespace's enum onto the stack so that it can be matched with the end tag later. For example, `HtmlElement_math` and `HtmlElement_svg` are used for matching start tag names in HTML, but `MathmlElement_math` and `SvgElement_svg` are what should be pushed onto the stack.
                            case HtmlElement_math:
                                *array_back(&scanner->open_elements) = MathmlElement_math;
                                array_push(&scanner->namespaces, ElementNamespace_MathML);
                                break;
                            case HtmlElement_svg:
                                *array_back(&scanner->open_elements) = SvgElement_svg;
                                array_push(&scanner->namespaces, ElementNamespace_SVG);
                                break;
                        }
                        break;
                    case ElementNamespace_MathML:
                        // The top-level `math` element can be nested, so we need to push the MathML namespace again so that we know how many end tags to look for
                        if (e == MathmlElement_math)
                            array_push(&scanner->namespaces, ElementNamespace_MathML);
                        break;
                    case ElementNamespace_SVG:
                        // The top-level `svg` element can be nested, so we need to push the SVG namespace again so that we know how many end tags to look for
                        if (e == SvgElement_svg)
                            array_push(&scanner->namespaces, ElementNamespace_SVG);
                        break;
                }
            }
        }

        // End tags
        else {
            if (scanner->open_elements.size == 0) {
                lexer->result_symbol = HtmlTokenType_ErroneousEndTagName;
                return true;
            }

            uint8_t top_tag = *array_back(&scanner->open_elements);
            XXH32_hash_t top_name_hash = 0;
            if (top_tag == 0) {
                ASSERT(scanner->custom_name_hashes.size > 0);
                top_name_hash = *array_back(&scanner->custom_name_hashes);
            }

            if (e == top_tag && name_hash == top_name_hash) {
                (void)pop_open_element(scanner);

                lexer->result_symbol = HtmlTokenType_EndTagName;
            } else {
                (void)pop_open_element(scanner);
                lexer->result_symbol = HtmlTokenType_ErroneousEndTagName;
            }
        }

        return true;
    }

    if (valid_symbols[HtmlTokenType_ErroneousEndTagName]) {
        #ifndef NO_IMPLIED_END_TAGS
        // Clear any cached tag from implied end tag lookahead
        scanner->cached_tag = false;
        #endif
        ASSERT(is_ascii_alpha(lexer->lookahead));
        advance(lexer);
        while (!lexer->eof(lexer) && !is_html_whitespace(lexer->lookahead) && lexer->lookahead != '/' && lexer->lookahead != '>')
            advance(lexer);
        // Pop the current element from the stack since the erroneous end tag closes it
        if (scanner->open_elements.size > 0)
            (void)pop_open_element(scanner);
        lexer->result_symbol = HtmlTokenType_ErroneousEndTagName;
        return true;
    }

    if (valid_symbols[HtmlTokenType_SelfClosingTagDelimiter]) {
        #ifndef ALLOW_SELF_CLOSING_HTML_TAGS
        ASSERT(get_current_namespace(scanner) != ElementNamespace_HTML);
        #endif

        // Skip optional whitespace before the delimiter
        while (is_html_whitespace(lexer->lookahead))
            skip(lexer);

        ASSERT(SCAN('/') && SCAN('>'));
        (void)pop_open_element(scanner);
        lexer->result_symbol = HtmlTokenType_SelfClosingTagDelimiter;
        return true;
    }

    #ifndef NO_IMPLIED_END_TAGS
    if (valid_symbols[HtmlTokenType_ImpliedEndTag]) {
        // Fast path: if we already know how many implied end tags to emit, just emit one
        if (scanner->implied_end_tags > 0) {
            scanner->implied_end_tags--;
            (void)pop_open_element(scanner);
            lexer->result_symbol = HtmlTokenType_ImpliedEndTag;
            return true;
        }

        // Only HTML namespace elements can have implied end tags
        if (get_current_namespace(scanner) != ElementNamespace_HTML)
            goto skip_implied_end_tag;
        if (scanner->open_elements.size == 0)
            goto skip_implied_end_tag;

        uint8_t current = *array_back(&scanner->open_elements);

        // Only certain elements can have implied end tags
        if (!implied_end_tag_elements[current])
            goto skip_implied_end_tag;

        // We need to peek ahead to see what's coming - must be a tag
        if (lexer->lookahead != '<')
            goto skip_implied_end_tag;

        // Mark position for zero-width token (before the '<')
        lexer->mark_end(lexer);
        advance(lexer);

        bool is_end_tag = false;
        if (lexer->lookahead == '/') {
            is_end_tag = true;
            advance(lexer);
        }

        if (!is_ascii_alpha(lexer->lookahead))
            return false;

        if (is_end_tag) {
            uint16_t closing_classes = implied_end_tag_classes_for_first_char(lexer->lookahead);
            if (!maybe_implied_close_on_end_tag_first_char(scanner, closing_classes))
                return false;
        } else {
            uint16_t opening_classes = implied_start_tag_classes_for_first_char(lexer->lookahead);
            if (!maybe_implied_close_on_start_tag_first_char(scanner, opening_classes))
                return false;
        }

        // Scan the tag name to see what's coming
        uint8_t next;
        XXH32_hash_t next_hash;
        uint32_t next_length = 0;
        bool next_has_terminator = false;
        if (!scan_tag_name(
            lexer,
            scanner,
            ElementNamespace_HTML,
            &next,
            &next_hash,
            &next_length,
            &next_has_terminator
        )) {
            // If we can't scan a tag name, return false immediately to reset lexer
            return false;
        }

        // Cache the scanned tag name for later use
        scanner->cached_tag = true;
        scanner->cached_tag_name = next;
        scanner->cached_tag_name_hash = next_hash;
        scanner->cached_tag_name_length = next_length;
        scanner->cached_tag_has_terminator = next_has_terminator;

        // Count how many elements need to be implicitly closed
        uint8_t close_count = 0;

        if (is_end_tag) {
            // End tag case: count elements that would be implicitly closed
            // by an end tag for an ancestor element
            if (next != current) {
                close_count = count_end_tag_implied_closes(scanner, next, next_hash);
            }
        } else {
            // Start tag case: only for elements that can have HTML-semantic implied end tags
            // This can happen in two ways:
            // 1. The start tag directly closes the current element (e.g., <li> closes <li>)
            // 2. The start tag closes an ancestor, and intermediate elements must be closed first
            close_count = count_start_tag_implied_closes(scanner, next);
        }

        if (close_count > 0) {
            // Store remaining count (minus one, since we're about to emit one)
            scanner->implied_end_tags = close_count - 1;

            // Pop the current element from the stack
            (void)pop_open_element(scanner);

            // Emit zero-width implied end tag token
            lexer->result_symbol = HtmlTokenType_ImpliedEndTag;
            return true;
        }

        // If we got here, we looked ahead but decided not to emit implied_end_tag.
        // We need to return false so tree-sitter resets the lexer position.
        return false;
    }
    skip_implied_end_tag:
    #endif

    if (valid_symbols[HtmlTokenType_Text] && lexer->lookahead != '<' && lexer->lookahead != '&') {
        // Leading whitespace should not be included as part of the text
        while (is_html_whitespace(lexer->lookahead))
            skip(lexer);

        bool text_matched = false;

        lexer->mark_end(lexer);

        while (!lexer->eof(lexer) && lexer->lookahead != '<' && lexer->lookahead != '&') {
            int c = lexer->lookahead;
            advance(lexer);

            if (!is_html_whitespace(c)) {
                lexer->mark_end(lexer);
                text_matched = true;
            }
        }

        if (text_matched) {
            lexer->result_symbol = HtmlTokenType_Text;
            return true;
        }
    }

    if (valid_symbols[HtmlTokenType_RawText] &&
        scan_raw_text_like(
            lexer,
            scanner,
            HtmlTokenType_RawText,
            false,
            HtmlElement_script,
            "script",
            6,
            HtmlElement_style,
            "style",
            5
        )) {
        return true;
    }

    if (valid_symbols[HtmlTokenType_EscapableRawText] &&
        scan_raw_text_like(
            lexer,
            scanner,
            HtmlTokenType_EscapableRawText,
            true,
            HtmlElement_textarea,
            "textarea",
            8,
            HtmlElement_title,
            "title",
            5
        )) {
        return true;
    }

    if ((can_match_full_character_reference || can_match_short_character_reference || can_match_invalid_character_reference) && lexer->lookahead == '&') {
        advance(lexer);

        if (SCAN('#')) {
            ASSERT(can_match_full_character_reference);
            // Numeric character reference
            if (SCAN_ICASE('X')) {
                // Hexadecimal
                ASSERT(is_ascii_xdigit(lexer->lookahead));
                do { advance(lexer); } while (is_ascii_xdigit(lexer->lookahead));
                ASSERT(SCAN(';'));
                lexer->result_symbol = HtmlTokenType_FullCharacterReference;
                return true;
            } else {
                // Decimal
                ASSERT(is_ascii_digit(lexer->lookahead));
                do { advance(lexer); } while (is_ascii_digit(lexer->lookahead));
                ASSERT(SCAN(';'));
                lexer->result_symbol = HtmlTokenType_FullCharacterReference;
                return true;
            }
        } else {
            // Named character reference
            char inline_reference_buffer[CHARACTER_REFERENCE_INLINE_BUFFER_SIZE];
            size_t ref_length = 0;
            size_t stored_length = 0;
            bool using_dynamic_buffer = false;

            lexer->mark_end(lexer);

            while (is_ascii_alnum(lexer->lookahead)) {
                char c = (char)lexer->lookahead;
                advance(lexer);
                ref_length++;

                if (stored_length < FULL_CHARACTER_REFERENCE_NAME_MAX) {
                    if (!using_dynamic_buffer && stored_length < sizeof(inline_reference_buffer)) {
                        inline_reference_buffer[stored_length] = c;
                    } else {
                        if (!using_dynamic_buffer) {
                            array_clear(&scanner->character_reference_buffer);
                            if (stored_length > 0)
                                array_extend(&scanner->character_reference_buffer, stored_length, inline_reference_buffer);
                            using_dynamic_buffer = true;
                        }
                        array_push(&scanner->character_reference_buffer, c);
                    }
                    stored_length++;
                }

                if (can_match_short_character_reference &&
                    ref_length >= SHORT_CHARACTER_REFERENCE_NAME_MIN &&
                    ref_length <= SHORT_CHARACTER_REFERENCE_NAME_MAX &&
                    (
                        is_common_short_character_reference(
                            using_dynamic_buffer ? scanner->character_reference_buffer.contents : inline_reference_buffer,
                            ref_length
                        ) ||
                        lookup_short_character_reference(
                            using_dynamic_buffer ? scanner->character_reference_buffer.contents : inline_reference_buffer,
                            ref_length
                        )
                    )
                ) {
                    lexer->result_symbol = HtmlTokenType_ShortCharacterReference;
                    lexer->mark_end(lexer);
                }
            }

            ASSERT(ref_length > 0);
            const char *reference_name = using_dynamic_buffer
                ? scanner->character_reference_buffer.contents
                : inline_reference_buffer;

            if (SCAN(';')) {
                if (
                    ref_length <= FULL_CHARACTER_REFERENCE_NAME_MAX &&
                    (
                    is_common_full_character_reference(
                        reference_name,
                        ref_length
                    ) ||
                    lookup_full_character_reference(
                        reference_name,
                        ref_length
                    )
                    )
                ) {
                    lexer->mark_end(lexer);
                    lexer->result_symbol = HtmlTokenType_FullCharacterReference;
                    return true;
                } else if (lexer->result_symbol == HtmlTokenType_ShortCharacterReference) {
                    return true;
                } else {
                    lexer->mark_end(lexer);
                    lexer->result_symbol = HtmlTokenType_InvalidCharacterReference;
                    return true;
                }
            } else if (lexer->result_symbol == HtmlTokenType_ShortCharacterReference) {
                return true;
            }

            return false;
        }
    }

    #define RECONSUME(STATE) \
        { \
            state = STATE; \
            goto STATE; \
        }

    if (valid_symbols[HtmlTokenType_CdataText]) {
        ASSERT(get_current_namespace(scanner) != ElementNamespace_HTML);

        // Ref: https://html.spec.whatwg.org/multipage/parsing.html#cdata-section-state
        enum {
            CdataSection,
            CdataSectionBracket,
            CdataSectionEnd
        } state = CdataSection;

        lexer->mark_end(lexer);

        while (!lexer->eof(lexer)) {
            int c = lexer->lookahead;
            advance(lexer);

            switch (state) {
                case CdataSection: CdataSection:
                    switch (c) {
                        case ']':
                            state = CdataSectionBracket;
                            break;
                        default:
                            lexer->mark_end(lexer);
                    }
                    break;
                case CdataSectionBracket: CdataSectionBracket:
                    switch (c) {
                        case ']':
                            state = CdataSectionEnd;
                            break;
                        default:
                            lexer->mark_end(lexer);
                            RECONSUME(CdataSection);
                    }
                    break;
                case CdataSectionEnd: CdataSectionEnd:
                    switch (c) {
                        case ']':
                            lexer->mark_end(lexer);
                            break;
                        case '>':
                            lexer->result_symbol = HtmlTokenType_CdataText;
                            return true;
                        default:
                            lexer->mark_end(lexer);
                            RECONSUME(CdataSection);
                    }
            }
        }
    }

    if (valid_symbols[HtmlTokenType_CommentText]) {
        // Ref: https://html.spec.whatwg.org/multipage/parsing.html#comment-start-state
        enum {
            CommentStart,
            CommentStartDash,
            Comment,
            CommentLessThanSign,
            CommentLessThanSignBang,
            CommentLessThanSignBangDash,
            CommentLessThanSignBangDashDash,
            CommentEndDash,
            CommentEnd,
            CommentEndBang,
        } state = CommentStart;

        lexer->mark_end(lexer);
        bool text_matched = false;

        while (!lexer->eof(lexer)) {
            int c = lexer->lookahead;
            advance(lexer);

            switch (state) {
                case CommentStart: CommentStart:
                    switch (c) {
                        case '-':
                            state = CommentStartDash;
                            break;
                        case '>':
                            return false;
                        default:
                            RECONSUME(Comment);
                    }
                    break;
                case CommentStartDash: CommentStartDash:
                    switch (c) {
                        case '-':
                            state = CommentEnd;
                            break;
                        case '>':
                            return false;
                        default:
                            lexer->mark_end(lexer);
                            text_matched = true;
                            RECONSUME(Comment);
                    }
                    break;
                case Comment: Comment:
                    switch (c) {
                        case '<':
                            lexer->mark_end(lexer);
                            text_matched = true;
                            state = CommentLessThanSign;
                            break;
                        case '-':
                            state = CommentEndDash;
                            break;
                        case '\0':
                            return false;
                        default:
                            lexer->mark_end(lexer);
                            text_matched = true;
                    }
                    break;
                case CommentLessThanSign: CommentLessThanSign:
                    switch (c) {
                        case '!':
                            lexer->mark_end(lexer);
                            text_matched = true;
                            state = CommentLessThanSignBang;
                            break;
                        case '<':
                            lexer->mark_end(lexer);
                            text_matched = true;
                            break;
                        default:
                            RECONSUME(Comment);
                    }
                    break;
                case CommentLessThanSignBang: CommentLessThanSignBang:
                    switch (c) {
                        case '-':
                            state = CommentLessThanSignBangDash;
                            break;
                        default:
                            RECONSUME(Comment);
                    }
                    break;
                case CommentLessThanSignBangDash: CommentLessThanSignBangDash:
                    switch (c) {
                        case '-':
                            state = CommentLessThanSignBangDashDash;
                            break;
                        default:
                            RECONSUME(CommentEndDash);
                    }
                    break;
                case CommentLessThanSignBangDashDash: CommentLessThanSignBangDashDash:
                    switch (c) {
                        case '>':
                            RECONSUME(CommentEnd);
                        default:
                            return false;
                    }
                    break;
                case CommentEndDash: CommentEndDash:
                    switch (c) {
                        case '-':
                            state = CommentEnd;
                            break;
                        default:
                            lexer->mark_end(lexer);
                            text_matched = true;
                            RECONSUME(Comment);
                    }
                    break;
                case CommentEnd: CommentEnd:
                    switch (c) {
                        case '>':
                            if (text_matched) {
                                lexer->result_symbol = HtmlTokenType_CommentText;
                                return true;
                            }
                            return false;
                        case '!':
                            state = CommentEndBang;
                            break;
                        case '-':
                            lexer->mark_end(lexer);
                            text_matched = true;
                            break;
                        default:
                            lexer->mark_end(lexer);
                            text_matched = true;
                            RECONSUME(Comment);
                    }
                    break;
                case CommentEndBang: CommentEndBang:
                    switch (c) {
                        case '-':
                            lexer->mark_end(lexer);
                            text_matched = true;
                            state = CommentEndDash;
                            break;
                        case '>':
                            return false;
                        default:
                            lexer->mark_end(lexer);
                            text_matched = true;
                            RECONSUME(Comment);
                    }
                    break;
            }
        }
    }

    #undef RECONSUME

    return false;
}
