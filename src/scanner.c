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
    uint8_t implied_end_tags;
    #endif

    Array(uint8_t /* ElementNamespace */) namespaces;
    Array(uint8_t) open_elements;
    Array(XXH32_hash_t) custom_name_hashes;
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

void *tree_sitter_html_external_scanner_create(void) {
    return ts_calloc(1, sizeof(Scanner));
}

void tree_sitter_html_external_scanner_destroy(void *payload) {
    Scanner *scanner = (Scanner *)payload;
    array_delete(&scanner->namespaces);
    array_delete(&scanner->open_elements);
    array_delete(&scanner->custom_name_hashes);
    ts_free(scanner);
}

unsigned tree_sitter_html_external_scanner_serialize(void *payload, char *buffer) {
    Scanner *scanner = (Scanner *)payload;

    char *offset = buffer;

    #ifndef NO_IMPLIED_END_TAGS
    *offset++ = (char)scanner->cached_tag;
    *offset++ = (char)scanner->cached_tag_name;
    memcpy(offset, &scanner->cached_tag_name_hash, sizeof(XXH32_hash_t));
    offset += sizeof(XXH32_hash_t);
    *offset++ = (char)scanner->implied_end_tags;
    #endif

    #define SERIALIZE_ARRAY(ARRAY) \
        { \
            offset += to_vlq(ARRAY.size, offset); \
            if (ARRAY.size > 0) { \
                size_t length = ARRAY.size * array_elem_size(&ARRAY); \
                assert(length + offset - buffer <= TREE_SITTER_SERIALIZATION_BUFFER_SIZE); \
                memcpy(offset, ARRAY.contents, length); \
                offset += length; \
            } \
        }

    SERIALIZE_ARRAY(scanner->namespaces);
    SERIALIZE_ARRAY(scanner->open_elements);
    SERIALIZE_ARRAY(scanner->custom_name_hashes);

    return offset - buffer;
}

void tree_sitter_html_external_scanner_deserialize(void *payload, const char *buffer, unsigned length) {
    Scanner *scanner = (Scanner *)payload;

    #ifndef NO_IMPLIED_END_TAGS
    scanner->cached_tag = false;
    scanner->cached_tag_name = 0;
    scanner->cached_tag_name_hash = 0;
    scanner->implied_end_tags = 0;
    #endif

    array_clear(&scanner->namespaces);
    array_clear(&scanner->open_elements);
    array_clear(&scanner->custom_name_hashes);

    if (length == 0) return;

    const char *offset = buffer;

    #ifndef NO_IMPLIED_END_TAGS
    scanner->cached_tag = (bool)*offset++;
    scanner->cached_tag_name = (uint8_t)*offset++;
    memcpy(&scanner->cached_tag_name_hash, offset, sizeof(XXH32_hash_t));
    offset += sizeof(XXH32_hash_t);
    scanner->implied_end_tags = (uint8_t)*offset++;
    #endif

    #define DESERIALIZE_ARRAY(ARRAY) \
        { \
            size_t size; \
            offset += from_vlq(offset, &size); \
            if (size > 0) { \
                array_extend(&ARRAY, size, offset); \
                offset += size * array_elem_size(&ARRAY); \
            } \
        }

    DESERIALIZE_ARRAY(scanner->namespaces);
    DESERIALIZE_ARRAY(scanner->open_elements);
    DESERIALIZE_ARRAY(scanner->custom_name_hashes);
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
static bool scan_tag_name(TSLexer *lexer, ElementNamespace ns, uint8_t *element, XXH32_hash_t *name_hash) {
    // Tag names must begin with an ASCII alpha character in the tag-open state
    if (!is_ascii_alpha(lexer->lookahead))
        return false;

    static Array(char) tag_name = array_new();
    array_clear(&tag_name);

    // For non-ASCII codepoints, we have to serialize to UTF8 first because our lookup tables only support 8-bit characters:
    #define PUSH_CODEPOINT(CODEPOINT) \
        { \
            char bytes[4]; \
            size_t count = codepoint_to_utf8(bytes, CODEPOINT); \
            array_extend(&tag_name, count, bytes); \
        }

    array_push(&tag_name, (char)ascii_tolower(lexer->lookahead));
    advance(lexer);

    bool must_be_unknown = false;

    while (!lexer->eof(lexer)) {
        if (is_html_whitespace(lexer->lookahead) || lexer->lookahead == '/' || lexer->lookahead == '>') {
            break;
        } else if (lexer->lookahead == '\0') {
            // If NULL is reached before EOF somehow, append U+FFFD REPLACEMENT CHARACTER to the name
            must_be_unknown = true;
            PUSH_CODEPOINT(0xFFFD);
        } else if (is_ascii_alnum(lexer->lookahead)) {
            array_push(&tag_name, (char)ascii_tolower(lexer->lookahead));
        } else if (lexer->lookahead == '-') {
            array_push(&tag_name, '-');
        } else if (is_ascii(lexer->lookahead)) {
            // Any other ASCII character is valid, but indicates an unknown element
            must_be_unknown = true;
            array_push(&tag_name, lexer->lookahead);
        } else {
            // All non-ASCII characters are valid in a tag name, but indicate an unknown element
            must_be_unknown = true;
            PUSH_CODEPOINT(lexer->lookahead);
        }
        advance(lexer);
    }

    // 0 represents an unknown element in any namespace
    *element = must_be_unknown
        ? 0
        : lookup_element(tag_name.contents, tag_name.size, ns);

    *name_hash = *element == 0
        ? XXH32(tag_name.contents, tag_name.size, 0)
        : 0;

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

// Returns true if the given start tag would implicitly close the current element
static inline bool start_tag_closes_element(HtmlElement current, HtmlElement next) {
    switch (current) {
        case HtmlElement_li:
            return next == HtmlElement_li;
        case HtmlElement_dt:
            return next == HtmlElement_dt || next == HtmlElement_dd;
        case HtmlElement_dd:
            return next == HtmlElement_dd || next == HtmlElement_dt;
        case HtmlElement_p:
            return next == HtmlElement_address ||
                   next == HtmlElement_article ||
                   next == HtmlElement_aside ||
                   next == HtmlElement_blockquote ||
                   next == HtmlElement_details ||
                   next == HtmlElement_div ||
                   next == HtmlElement_dl ||
                   next == HtmlElement_fieldset ||
                   next == HtmlElement_figcaption ||
                   next == HtmlElement_figure ||
                   next == HtmlElement_footer ||
                   next == HtmlElement_form ||
                   next == HtmlElement_h1 ||
                   next == HtmlElement_h2 ||
                   next == HtmlElement_h3 ||
                   next == HtmlElement_h4 ||
                   next == HtmlElement_h5 ||
                   next == HtmlElement_h6 ||
                   next == HtmlElement_header ||
                   next == HtmlElement_hgroup ||
                   next == HtmlElement_hr ||
                   next == HtmlElement_main ||
                   next == HtmlElement_menu ||
                   next == HtmlElement_nav ||
                   next == HtmlElement_ol ||
                   next == HtmlElement_p ||
                   next == HtmlElement_pre ||
                   next == HtmlElement_search ||
                   next == HtmlElement_section ||
                   next == HtmlElement_table ||
                   next == HtmlElement_ul;
        case HtmlElement_rt:
        case HtmlElement_rp:
            return next == HtmlElement_rt || next == HtmlElement_rp;
        case HtmlElement_optgroup:
            return next == HtmlElement_optgroup;
        case HtmlElement_option:
            return next == HtmlElement_option || next == HtmlElement_optgroup;
        case HtmlElement_thead:
        case HtmlElement_tbody:
            return next == HtmlElement_tbody || next == HtmlElement_tfoot;
        case HtmlElement_tr:
            return next == HtmlElement_tr;
        case HtmlElement_td:
        case HtmlElement_th:
            return next == HtmlElement_td || next == HtmlElement_th;
        default:
            return false;
    }
}

// Returns true if an end tag for the given element would implicitly close the current element
static inline bool end_tag_closes_element(HtmlElement current, HtmlElement closing) {
    switch (current) {
        case HtmlElement_li:
            return closing == HtmlElement_ul || closing == HtmlElement_ol || closing == HtmlElement_menu;
        case HtmlElement_dt:
        case HtmlElement_dd:
            return closing == HtmlElement_dl;
        case HtmlElement_p:
            // p can be closed by the end tag of most parent elements
            // We'll be permissive here and let it close for any ancestor end tag
            // except for elements that specifically can contain p without closing it
            return closing != HtmlElement_a &&
                   closing != HtmlElement_audio &&
                   closing != HtmlElement_del &&
                   closing != HtmlElement_ins &&
                   closing != HtmlElement_map &&
                   closing != HtmlElement_noscript &&
                   closing != HtmlElement_video;
        case HtmlElement_rt:
        case HtmlElement_rp:
            return closing == HtmlElement_ruby;
        case HtmlElement_optgroup:
        case HtmlElement_option:
            return closing == HtmlElement_select || closing == HtmlElement_datalist || closing == HtmlElement_optgroup;
        case HtmlElement_thead:
        case HtmlElement_tbody:
        case HtmlElement_tfoot:
            return closing == HtmlElement_table;
        case HtmlElement_tr:
            return closing == HtmlElement_thead || closing == HtmlElement_tbody || closing == HtmlElement_tfoot || closing == HtmlElement_table;
        case HtmlElement_td:
        case HtmlElement_th:
            return closing == HtmlElement_tr || closing == HtmlElement_thead || closing == HtmlElement_tbody || closing == HtmlElement_tfoot || closing == HtmlElement_table;
        default:
            return false;
    }
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

// Count how many elements would be implicitly closed by an end tag for an ancestor.
// Searches from top to bottom for the closing element, counting closeable elements along the way.
// Returns the count of elements to close, or 0 if the ancestor is not found or
// if an element that can't have an implied end tag is encountered.
static uint8_t count_end_tag_implied_closes(Scanner *scanner, HtmlElement closing, XXH32_hash_t closing_hash) {
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

        // Check if this element can be implicitly closed
        if (end_tag_closes_element(e, closing) && implied_end_tag_elements[e]) {
            close_count++;
        } else if (!implied_end_tag_elements[e]) {
            // Hit an element that can't have an implied end tag, stop
            return 0;
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
    uint8_t close_count = 0;

    for (size_t i = scanner->open_elements.size; i > 0; i--) {
        uint8_t elem = scanner->open_elements.contents[i - 1];

        if (start_tag_closes_element(elem, opening)) {
            // Found an element that the start tag closes - include it in the count
            return close_count + 1;
        }

        if (!implied_end_tag_elements[elem]) {
            // Hit an element that can't have an implied end tag, stop
            return 0;
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
            // Advance past the tag name in the lexer
            while (!is_html_whitespace(lexer->lookahead) && lexer->lookahead != '/' && lexer->lookahead != '>')
                advance(lexer);
            scanner->cached_tag = false;
        } else {
            ASSERT(scan_tag_name(lexer, ns, &e, &name_hash));
        }
        #else
        ASSERT(scan_tag_name(lexer, ns, &e, &name_hash));
        #endif

        // Start tags
        if (valid_symbols[HtmlTokenType_StartTagName]) {
            // Start with the default token for start tag names and disambiguate below
            lexer->result_symbol = HtmlTokenType_StartTagName;
            array_push(&scanner->open_elements, e);

            switch (ns) {
                case ElementNamespace_HTML:
                    switch (e) {
                        // Void elements
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
                            lexer->result_symbol = HtmlTokenType_VoidStartTagName;
                            array_pop(&scanner->open_elements);
                            break;

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

            if (e == 0)
                // Again, 0 represents an unknown element in any namespace; push its name hash onto the stack
                array_push(&scanner->custom_name_hashes, name_hash);
        }

        // End tags
        else {
            if (scanner->open_elements.size == 0) {
                lexer->result_symbol = HtmlTokenType_ErroneousEndTagName;
                return true;
            }

            uint8_t top_tag = *array_back(&scanner->open_elements);
            XXH32_hash_t top_name_hash = 0;
            if (top_tag == 0)
                top_name_hash = *array_back(&scanner->custom_name_hashes);

            if (e == top_tag && name_hash == top_name_hash) {
                array_pop(&scanner->open_elements);

                switch (ns) {
                    case ElementNamespace_HTML:
                        if (e == HtmlElement_html)
                            array_pop(&scanner->namespaces);
                        break;
                    case ElementNamespace_MathML:
                        if (e == MathmlElement_math)
                            array_pop(&scanner->namespaces);
                        break;
                    case ElementNamespace_SVG:
                        if (e == SvgElement_svg)
                            array_pop(&scanner->namespaces);
                        break;
                }

                if (top_name_hash)
                    array_pop(&scanner->custom_name_hashes);

                lexer->result_symbol = HtmlTokenType_EndTagName;
            } else {
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
        if (scanner->open_elements.size > 0) {
            uint8_t e = array_pop(&scanner->open_elements);
            if (e == 0)
                array_pop(&scanner->custom_name_hashes);
        }
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
        uint8_t e = array_pop(&scanner->open_elements);
        if (e == 0) {
            array_pop(&scanner->custom_name_hashes);
        } else {
            // Pop namespace for self-closing foreign elements
            ElementNamespace ns = get_current_namespace(scanner);
            if ((ns == ElementNamespace_MathML && e == MathmlElement_math) ||
                (ns == ElementNamespace_SVG && e == SvgElement_svg)) {
                array_pop(&scanner->namespaces);
            }
        }
        lexer->result_symbol = HtmlTokenType_SelfClosingTagDelimiter;
        return true;
    }

    #ifndef NO_IMPLIED_END_TAGS
    if (valid_symbols[HtmlTokenType_ImpliedEndTag]) {
        // Fast path: if we already know how many implied end tags to emit, just emit one
        if (scanner->implied_end_tags > 0) {
            scanner->implied_end_tags--;
            uint8_t current = array_pop(&scanner->open_elements);
            if (current == 0)
                array_pop(&scanner->custom_name_hashes);
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

        // Scan the tag name to see what's coming
        uint8_t next;
        XXH32_hash_t next_hash;
        if (!scan_tag_name(lexer, ElementNamespace_HTML, &next, &next_hash)) {
            // If we can't scan a tag name, return false immediately to reset lexer
            return false;
        }

        // Cache the scanned tag name for later use
        scanner->cached_tag = true;
        scanner->cached_tag_name = next;
        scanner->cached_tag_name_hash = next_hash;

        // Count how many elements need to be implicitly closed
        uint8_t close_count = 0;

        if (is_end_tag) {
            // End tag case: count elements that would be implicitly closed
            // by an end tag for an ancestor element
            if (next != current) {
                close_count = count_end_tag_implied_closes(scanner, next, next_hash);
            }
        } else if (implied_end_tag_elements[current]) {
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
            array_pop(&scanner->open_elements);
            if (current == 0)
                array_pop(&scanner->custom_name_hashes);

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

    if ((valid_symbols[HtmlTokenType_FullCharacterReference] || valid_symbols[HtmlTokenType_ShortCharacterReference] || valid_symbols[HtmlTokenType_InvalidCharacterReference]) && lexer->lookahead == '&') {
        advance(lexer);

            if (SCAN('#')) {
                ASSERT(valid_symbols[HtmlTokenType_FullCharacterReference]);
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
                static Array(char) name = array_new();
                array_clear(&name);

                lexer->mark_end(lexer);

                while (is_ascii_alnum(lexer->lookahead)) {
                    array_push(&name, lexer->lookahead);
                    advance(lexer);

                if (valid_symbols[HtmlTokenType_ShortCharacterReference] && lookup_short_character_reference(name.contents, name.size)) {
                    lexer->result_symbol = HtmlTokenType_ShortCharacterReference;
                    lexer->mark_end(lexer);
                }
            }

            ASSERT(name.size > 0);

            if (SCAN(';')) {
                if (lookup_full_character_reference(name.contents, name.size)) {
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

            #define RECONSUME(STATE) \
                { \
                    state = STATE; \
                    goto STATE; \
                }

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

            #define RECONSUME(STATE) \
                { \
                    state = STATE; \
                    goto STATE; \
                }

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

    return false;
}
