#include <stdint.h>
#include <ctype.h>
#include <string.h>
#include <wctype.h>
#include "helpers.h"
#include "tables/html_elements.h"
#include "tables/mathml_elements.h"
#include "tables/svg_elements.h"
#include "tables/html_character_references.h"
#include "tables/html_character_references_no_semicolon.h"
#include "tree_sitter/parser.h"
#include "tree_sitter/alloc.h"
#include "tree_sitter/array.h"

#define XXH_INLINE_ALL
#define XXH_STATIC_LINKING_ONLY
#include "xxHash/xxhash.h"

#define DEBUG

enum TokenType {
    TT_StartTagName,
    TT_VoidStartTagName,
    TT_ScriptStartTagName,
    TT_StyleStartTagName,
    TT_EndTagName,
    TT_ErroneousEndTagName,
    TT_SelfClosingTagDelimiter,
    TT_Text,
    TT_CharacterReference,
    TT_AmbiguousAmpersand,
    TT_CdataText,
    TT_CommentText,
};

enum ElementNamespace {
    EN_HTML,
    EN_MathML,
    EN_SVG
};

struct Scanner {
    Array(uint8_t /* enum ElementNamespace */) namespaces;
    Array(uint8_t) tags;
    Array(XXH32_hash_t) custom_name_hashes;
};

static enum ElementNamespace get_current_namespace(struct Scanner *scanner) {
    if (scanner->namespaces.size > 0)
        return *array_back(&scanner->namespaces);
    else
        // If no top-level elements have been pushed onto the stack yet, the default namespace is HTML
        return EN_HTML;
}

void *tree_sitter_html_external_scanner_create() {
    return ts_calloc(1, sizeof(struct Scanner));
}

void tree_sitter_html_external_scanner_destroy(void *payload) {
    struct Scanner *scanner = payload;
    array_delete(&scanner->namespaces);
    array_delete(&scanner->tags);
    array_delete(&scanner->custom_name_hashes);
    ts_free(scanner);
}

unsigned tree_sitter_html_external_scanner_serialize(void *payload, char *buffer) {
    struct Scanner *scanner = payload;

    char *offset = buffer;

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
    SERIALIZE_ARRAY(scanner->tags);
    SERIALIZE_ARRAY(scanner->custom_name_hashes);

    return offset - buffer;
}

void tree_sitter_html_external_scanner_deserialize(void *payload, const char *buffer, unsigned length) {
    struct Scanner *scanner = payload;

    array_clear(&scanner->namespaces);
    array_clear(&scanner->tags);
    array_clear(&scanner->custom_name_hashes);

    if (length == 0) return;

    const char *offset = buffer;

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
    DESERIALIZE_ARRAY(scanner->tags);
    DESERIALIZE_ARRAY(scanner->custom_name_hashes);
}

static void advance(TSLexer *lexer) {
    lexer->advance(lexer, false);
}

static void skip(TSLexer *lexer) {
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

static bool scan_whitespace(TSLexer *lexer) {
    if (is_html_whitespace(lexer->lookahead)) {
        do { advance(lexer); } while (is_html_whitespace(lexer->lookahead));
        return true;
    } else {
        return false;
    }
}

// Scan a tag name and return its element enum in the given namespace as well as its custom name hash, if any
// Ref: https://html.spec.whatwg.org/multipage/parsing.html#tag-name-state
static bool scan_tag_name(TSLexer *lexer, enum ElementNamespace ns, uint8_t *element, XXH32_hash_t *name_hash) {
    static Array(char) tag_name = array_new();
    array_clear(&tag_name);

    // For non-ASCII codepoints, we have to serialize to UTF8 first because our lookup tables only support 8-bit characters:
    #define PUSH_CODEPOINT(CODEPOINT) \
        { \
            char bytes[4]; \
            size_t count = codepoint_to_utf8(bytes, CODEPOINT); \
            array_extend(&tag_name, count, bytes); \
        }

    // The first letter of any tag name must be an ASCII alpha character
    if (!isalpha(lexer->lookahead))
        return false;

    array_push(&tag_name, lexer->lookahead | 0x0020);
    advance(lexer);
    
    bool must_be_unknown = false;

    while (!lexer->eof(lexer)) {
        if (is_html_whitespace(lexer->lookahead) || lexer->lookahead == '/' || lexer->lookahead == '>') {
            break;
        } else if (lexer->lookahead == '\0') {
            // If NULL is reached before EOF somehow, append U+FFFD REPLACEMENT CHARACTER to the name
            must_be_unknown = true;
            PUSH_CODEPOINT(0xFFFD);
        } else if (isalnum(lexer->lookahead)) {
            array_push(&tag_name, lexer->lookahead | 0x0020);
        } else if (is_ascii(lexer->lookahead)) {
            // Any other ASCII character is valid, but indicates an unknown element
            must_be_unknown = true;
            array_push(&tag_name, lexer->lookahead);
        } else {
            // All non-ASCII characters are valid in a tag name, but indicate an unknown element
            must_be_unknown = true;
            PUSH_CODEPOINT(towlower(lexer->lookahead));
        }
        advance(lexer);
    }

    if (must_be_unknown) {
        // 0 represents an unknown element in any namespace
        *element = 0;
    } else {
        switch (ns) {
            case EN_HTML:
                *element = lookup_html_element(tag_name.contents, tag_name.size);
                break;
            case EN_MathML:
                *element = lookup_mathml_element(tag_name.contents, tag_name.size);
                break;
            case EN_SVG:
                *element = lookup_svg_element(tag_name.contents, tag_name.size);
                break;
        }
    }

    if (name_hash != NULL) {
        if (*element == 0)
            *name_hash = XXH32(tag_name.contents, tag_name.size, 0);
        else
            *name_hash = 0;
    }

    return true;
}

bool tree_sitter_html_external_scanner_scan(void *payload, TSLexer *lexer, const bool *valid_symbols) {
    struct Scanner *scanner = payload;

    #define ASSERT(CONDITION) \
        if (!(CONDITION)) return false;

    #define SCAN(CHAR) \
        scan_char(lexer, CHAR)

    #define SCAN_ICASE(CHAR /* should be an uppercase ASCII letter */) \
        (SCAN(CHAR) || SCAN(CHAR | 0x0020))

    #define SCAN_WHITESPACE() \
        scan_whitespace(lexer)

    #ifdef DEBUG
    fputs("---------------------------------------------\n", stderr);
    fprintf(stderr, "%d %c\n", lexer->get_column(lexer), lexer->lookahead);
    fprintf(stderr, "%d TT_StartTagName\n", valid_symbols[TT_StartTagName]);
    fprintf(stderr, "%d TT_VoidStartTagName\n", valid_symbols[TT_VoidStartTagName]);
    fprintf(stderr, "%d TT_ScriptStartTagName\n", valid_symbols[TT_ScriptStartTagName]);
    fprintf(stderr, "%d TT_StyleStartTagName\n", valid_symbols[TT_StyleStartTagName]);
    fprintf(stderr, "%d TT_EndTagName\n", valid_symbols[TT_EndTagName]);
    fprintf(stderr, "%d TT_ErroneousEndTagName\n", valid_symbols[TT_ErroneousEndTagName]);
    fprintf(stderr, "%d TT_SelfClosingTagDelimiter\n", valid_symbols[TT_SelfClosingTagDelimiter]);
    fprintf(stderr, "%d TT_Text\n", valid_symbols[TT_Text]);
    fprintf(stderr, "%d TT_CharacterReference\n", valid_symbols[TT_CharacterReference]);
    fprintf(stderr, "%d TT_AmbiguousAmpersand\n", valid_symbols[TT_AmbiguousAmpersand]);
    fprintf(stderr, "%d TT_CdataText\n", valid_symbols[TT_CdataText]);
    fprintf(stderr, "%d TT_CommentText\n", valid_symbols[TT_CommentText]);
    #endif

    if (lexer->eof(lexer))
        return false;

    if (valid_symbols[TT_StartTagName]) {
        enum ElementNamespace ns = get_current_namespace(scanner);
        uint8_t e;
        XXH32_hash_t name_hash;

        ASSERT(scan_tag_name(lexer, ns, &e, &name_hash));

        // Start with the default token for start tag names and disambiguate below
        lexer->result_symbol = TT_StartTagName;

        switch (ns) {
            case EN_HTML:
                switch (e) {
                    // Void elements
                    case HE_area:
                    case HE_base:
                    case HE_br:
                    case HE_col:
                    case HE_embed:
                    case HE_hr:
                    case HE_img:
                    case HE_input:
                    case HE_link:
                    case HE_meta:
                    case HE_source:
                    case HE_track:
                    case HE_wbr:
                        lexer->result_symbol = TT_VoidStartTagName;
                        break;

                    // Raw text elements
                    case HE_script:
                        array_push(&scanner->tags, e);
                        lexer->result_symbol = TT_ScriptStartTagName;
                        break;
                    case HE_style:
                        array_push(&scanner->tags, e);
                        lexer->result_symbol = TT_StyleStartTagName;
                        break;

                    // Top-level elements
                    case HE_html:
                        array_push(&scanner->tags, HE_html);
                        array_push(&scanner->namespaces, EN_HTML);
                        break;
                    // For top-level elements of foreign namespaces, we need to make sure that we are pushing the value from that namespace's enum onto the stack so that it can be matched with the end tag later. For example, `HE_math` and `HE_svg` are used for matching start tag names in HTML, but `ME_math` and `SE_svg` are what should be pushed onto the stack.
                    case HE_math:
                        array_push(&scanner->tags, ME_math);
                        array_push(&scanner->namespaces, EN_MathML);
                        break;
                    case HE_svg:
                        array_push(&scanner->tags, SE_svg);
                        array_push(&scanner->namespaces, EN_SVG);
                        break;

                    default:
                        array_push(&scanner->tags, e);
                }
                break;
            case EN_MathML:
                array_push(&scanner->tags, e);
                // The top-level `math` element can be nested, so we need to push the MathML namespace again so that we know how many end tags to look for
                if (e == ME_math)
                    array_push(&scanner->namespaces, EN_MathML);
                break;
            case EN_SVG:
                array_push(&scanner->tags, e);
                // The top-level `svg` element can be nested, so we need to push the SVG namespace again so that we know how many end tags to look for
                if (e == SE_svg)
                    array_push(&scanner->namespaces, EN_SVG);
                break;
        }

        if (e == 0)
            // Again, 0 represents an unknown element in any namespace; push it's name hash onto the stack
            array_push(&scanner->custom_name_hashes, name_hash);

        return true;
    }

    if (valid_symbols[TT_EndTagName]) {
        ASSERT(scanner->tags.size > 0);
        
        enum ElementNamespace ns = get_current_namespace(scanner);
        uint8_t element;
        XXH32_hash_t name_hash;

        ASSERT(scan_tag_name(lexer, ns, &element, &name_hash))

        uint8_t top_element = *array_back(&scanner->tags);
        XXH32_hash_t top_name_hash = 0;
        if (top_element == 0)
            top_name_hash = *array_back(&scanner->custom_name_hashes);

        if (element == top_element && name_hash == top_name_hash) {
            array_pop(&scanner->tags);

            if (top_name_hash)
                array_pop(&scanner->custom_name_hashes);

            if (
                (ns == EN_HTML && element == HE_html) ||
                (ns == EN_MathML && element == ME_math) ||
                (ns == EN_SVG && element == SE_svg)
            )
                array_pop(&scanner->namespaces);

            lexer->result_symbol = TT_EndTagName;
            return true;
        } else {
            lexer->result_symbol = TT_ErroneousEndTagName;
            return true;
        }
    }

    if (valid_symbols[TT_ErroneousEndTagName]) {
        ASSERT(isalpha(lexer->lookahead));
        advance(lexer);
        while (!lexer->eof(lexer) && !is_html_whitespace(lexer->lookahead) && lexer->lookahead != '/' && lexer->lookahead != '>')
            advance(lexer);
        lexer->result_symbol = TT_ErroneousEndTagName;
        return true;
    }

    if (valid_symbols[TT_SelfClosingTagDelimiter]) {
        #ifndef ALLOW_SELF_CLOSING_HTML_TAGS
        ASSERT(get_current_namespace(scanner) != EN_HTML);
        #endif

        // This is necessary for some reason; probably due to a bug in the grammar
        while (is_html_whitespace(lexer->lookahead))
            skip(lexer);

        ASSERT(SCAN('/') && SCAN('>'));
        uint8_t e = array_pop(&scanner->tags);
        if (e == 0)
            array_pop(&scanner->custom_name_hashes);
        lexer->result_symbol = TT_SelfClosingTagDelimiter;
        return true;
    }

    if (valid_symbols[TT_Text]) {
        // Leading whitespace should not be included as part of the text
        while (is_html_whitespace(lexer->lookahead))
            skip(lexer);

        bool text_matched = false;

        lexer->mark_end(lexer);

        enum {
            Normal,
            RawText,
            EscapableRawText
        } text_type = Normal;

        enum HtmlElement top_element;

        if (get_current_namespace(scanner) == EN_HTML) {
            if (scanner->tags.size > 0) {
                top_element = *array_back(&scanner->tags);
                if (top_element == HE_script || top_element == HE_style)
                    text_type = RawText;
                else if (top_element == HE_textarea || top_element == HE_title)
                    text_type = EscapableRawText;
            }
        }

        switch (text_type) {
            case Normal:
                while (!lexer->eof(lexer) && lexer->lookahead != '<' && lexer->lookahead != '&') {
                    int c = lexer->lookahead;
                    advance(lexer);
                    if (!is_html_whitespace(c)) {
                        lexer->mark_end(lexer);
                        text_matched = true;
                    }
                }
                break;

            case RawText:
                while (!lexer->eof(lexer)) {
                    int c = lexer->lookahead;
                    advance(lexer);
            
                    if (c == '<') {
                        // Check for the end tag
                        if (lexer->lookahead == '/') {
                            advance(lexer);
                            if (top_element == HE_script) {
                                if (SCAN_ICASE('S') && SCAN_ICASE('C') && SCAN_ICASE('R') && SCAN_ICASE('I') && SCAN_ICASE('P') && SCAN_ICASE('T')) {
                                    if (is_html_whitespace(lexer->lookahead) || lexer->lookahead == '>' || lexer->lookahead == '/')
                                        goto finish;
                                }
                            } else if (top_element == HE_style) {
                                if (SCAN_ICASE('S') && SCAN_ICASE('T') && SCAN_ICASE('Y') && SCAN_ICASE('L') && SCAN_ICASE('E')) {
                                    if (is_html_whitespace(lexer->lookahead) || lexer->lookahead == '>' || lexer->lookahead == '/')
                                        goto finish;
                                }
                            }
                        }
                        lexer->mark_end(lexer);
                        text_matched = true;
                    } else if (!is_html_whitespace(c)) {
                        lexer->mark_end(lexer);
                        text_matched = true;
                    }
                }
                break;

            case EscapableRawText:
                while (!lexer->eof(lexer) && lexer->lookahead != '&') {
                    int c = lexer->lookahead;
                    advance(lexer);
            
                    if (c == '<') {
                        // Check for the end tag
                        if (lexer->lookahead == '/') {
                            advance(lexer);
                            if (top_element == HE_textarea) {
                                if (SCAN_ICASE('T') && SCAN_ICASE('E') && SCAN_ICASE('X') && SCAN_ICASE('T') && SCAN_ICASE('A') && SCAN_ICASE('R') && SCAN_ICASE('E') && SCAN_ICASE('A')) {
                                    if (is_html_whitespace(lexer->lookahead) || lexer->lookahead == '>' || lexer->lookahead == '/')
                                        goto finish;
                                }
                            } else if (top_element == HE_title) {
                                if (SCAN_ICASE('T') && SCAN_ICASE('I') && SCAN_ICASE('T') && SCAN_ICASE('L') && SCAN_ICASE('E')) {
                                    if (is_html_whitespace(lexer->lookahead) || lexer->lookahead == '>' || lexer->lookahead == '/')
                                        goto finish;
                                }
                            }
                        }
                        lexer->mark_end(lexer);
                        text_matched = true;
                    } else if (!is_html_whitespace(c)) {
                        lexer->mark_end(lexer);
                        text_matched = true;
                    }
                }
                break;
        }
        
        finish: if (text_matched) {
            lexer->result_symbol = TT_Text;
            return true;
        }
    }

    if (valid_symbols[TT_CharacterReference] || valid_symbols[TT_AmbiguousAmpersand]) {
        ASSERT(SCAN('&'));
        
        if (SCAN('#')) {
            // Numeric character reference
            if (SCAN('X') || SCAN('x')) {
                // Hexadecimal
                ASSERT(isxdigit(lexer->lookahead));
                do { advance(lexer); } while (isxdigit(lexer->lookahead));
                ASSERT(SCAN(';'));
                lexer->result_symbol = TT_CharacterReference;
                lexer->mark_end(lexer);
                return true;
            } else {
                // Decimal
                ASSERT(isdigit(lexer->lookahead));
                do { advance(lexer); } while (isdigit(lexer->lookahead));
                ASSERT(SCAN(';'));
                lexer->result_symbol = TT_CharacterReference;
                lexer->mark_end(lexer);
                return true;
            }
        } else {
            // Named character references
            static Array(char) entity_name = array_new();
            array_clear(&entity_name);

            while (isalnum(lexer->lookahead)) {
                array_push(&entity_name, lexer->lookahead);
                advance(lexer);

                if (lookup_character_reference_no_semicolon(entity_name.contents, entity_name.size)) {
                    SCAN(';');
                    lexer->result_symbol = TT_CharacterReference;
                    lexer->mark_end(lexer);
                    return true;
                }
            }

            ASSERT(entity_name.size > 0);
            ASSERT(SCAN(';'));

            if (lookup_character_reference(entity_name.contents, entity_name.size))
                lexer->result_symbol = TT_CharacterReference;
            else
                lexer->result_symbol = TT_AmbiguousAmpersand;

            lexer->mark_end(lexer);
            return true;
        }
    }

    if (valid_symbols[TT_CdataText]) {
        ASSERT(get_current_namespace(scanner) != EN_HTML);
        
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
                            lexer->result_symbol = TT_CdataText;
                            return true;
                        default:
                            lexer->mark_end(lexer);
                            RECONSUME(CdataSection);
                    }
            }
        }
    }

    if (valid_symbols[TT_CommentText]) {
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
                            RECONSUME(Comment);
                    }
                    break;
                case Comment: Comment:
                    switch (c) {
                        case '<':
                            lexer->mark_end(lexer);
                            state = CommentLessThanSign;
                            break;
                        case '-':
                            state = CommentEndDash;
                            break;
                        case '\0':
                            return false;
                        default:
                            lexer->mark_end(lexer);
                    }
                    break;
                case CommentLessThanSign: CommentLessThanSign:
                    switch (c) {
                        case '!':
                            lexer->mark_end(lexer);
                            state = CommentLessThanSignBang;
                            break;
                        case '<':
                            lexer->mark_end(lexer);
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
                            RECONSUME(Comment);
                    }
                    break;
                case CommentEnd: CommentEnd:
                    switch (c) {
                        case '>':
                            lexer->result_symbol = TT_CommentText;
                            return true;
                        case '!':
                            state = CommentEndBang;
                            break;
                        case '-':
                            lexer->mark_end(lexer);
                            break;
                        default:
                            lexer->mark_end(lexer);
                            RECONSUME(Comment);
                    }
                    break;
                case CommentEndBang: CommentEndBang:
                    switch (c) {
                        case '-':
                            lexer->mark_end(lexer);
                            state = CommentEndDash;
                            break;
                        case '>':
                            return false;
                        default:
                            lexer->mark_end(lexer);
                            RECONSUME(Comment);
                    }
                    break;
            }
        }
    }

    return false;
}
