#include <stdint.h>
#include <ctype.h>
#include <string.h>
#include <wctype.h>

#define XXH_INLINE_ALL
// We're only calling XXH32(), so these modifiers are okay:
#define XXH_NO_STDLIB
#define XXH_NO_XXH3
#define XXH_NO_LONG_LONG
#define XXH_NO_STREAM
#include <xxhash.h>

#include "helpers.h"
#include "tables/html_elements.h"
#include "tables/mathml_elements.h"
#include "tables/svg_elements.h"
#include "tables/html_full_character_references.h"
#include "tables/html_short_character_references.h"
#include "tree_sitter/parser.h"
#include "tree_sitter/alloc.h"
#include "tree_sitter/array.h"

enum HtmlTokenType {
    HtmlTokenType_StartTagName,
    HtmlTokenType_VoidStartTagName,
    HtmlTokenType_ScriptStartTagName,
    HtmlTokenType_StyleStartTagName,
    HtmlTokenType_EscapableRawTextStartTagName,
    HtmlTokenType_EndTagName,
    HtmlTokenType_ErroneousEndTagName,
    HtmlTokenType_SelfClosingTagDelimiter,
    // HtmlTokenType_ImpliedEndTag,
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
};

enum ElementNamespace {
    ElementNamespace_HTML,
    ElementNamespace_MathML,
    ElementNamespace_SVG
};

// enum InsertionMode {
//     InsertionMode_Initial,
//     InsertionMode_BeforeHtml,
//     InsertionMode_BeforeHead,
//     InsertionMode_InHead,
//     InsertionMode_InHeadNoscript,
//     InsertionMode_AfterHead,
//     InsertionMode_InBody,
//     InsertionMode_Text,
//     InsertionMode_InTable,
//     InsertionMode_InTableText,
//     InsertionMode_InCaption,
//     InsertionMode_InColumnGroup,
//     InsertionMode_InTableBody,
//     InsertionMode_InRow,
//     InsertionMode_InCell,
//     InsertionMode_InTemplate,
//     InsertionMode_AfterBody,
//     InsertionMode_InFrameset,
//     InsertionMode_AfterFrameset,
//     InsertionMode_AfterAfterBody,
//     InsertionMode_AfterAfterFrameset,
// };

struct Scanner {
    // enum InsertionMode insertion_mode;
    // enum InsertionMode original_insertion_mode;

    // bool next_tag;
    // uint8_t next_tag_name;
    // XXH32_hash_t next_tag_name_hash;

    // #ifndef NO_IMPLIED_END_TAGS
    // uint8_t implied_end_tags;
    // #endif

    Array(uint8_t /* enum ElementNamespace */) namespaces;
    Array(uint8_t) tags;
    Array(XXH32_hash_t) custom_name_hashes;
    // Array(uint8_t /* enum InsertionMode */) template_insertion_modes;
};

static enum ElementNamespace get_current_namespace(struct Scanner *scanner) {
    if (scanner->namespaces.size > 0)
        return scanner->namespaces.contents[scanner->namespaces.size - 1];
    else
        // If no top-level elements have been pushed onto the stack yet, the default namespace is HTML
        return ElementNamespace_HTML;
}

static uint8_t get_current_tag(struct Scanner *scanner) {
    if (scanner->tags.size > 0)
        return scanner->tags.contents[scanner->tags.size - 1];
    else
        // If no elements have been pushed onto the stack yet, the default root element is `html`
        return HtmlElement_html;
}

void *tree_sitter_html_external_scanner_create(void) {
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

    // *offset++ = (char)scanner->insertion_mode;
    // *offset++ = (char)scanner->original_insertion_mode;

    // *offset++ = (char)scanner->next_tag;
    // *offset++ = (char)scanner->next_tag_name;

    // memcpy(offset, &scanner->next_tag_name_hash, sizeof(XXH32_hash_t));
    // offset += sizeof(XXH32_hash_t);

    // #ifndef NO_IMPLIED_END_TAGS
    // *offset++ = (char)scanner->implied_end_tags;
    // #endif

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

    // scanner->insertion_mode = InsertionMode_Initial;
    // scanner->original_insertion_mode = InsertionMode_Initial;

    // scanner->next_tag = false;
    // scanner->next_tag_name = 0;
    // scanner->next_tag_name_hash = 0;

    // #ifndef NO_IMPLIED_END_TAGS
    // scanner->implied_end_tags = 0;
    // #endif

    array_clear(&scanner->namespaces);
    array_clear(&scanner->tags);
    array_clear(&scanner->custom_name_hashes);

    if (length == 0) return;

    const char *offset = buffer;

    // scanner->insertion_mode = (enum InsertionMode)*offset++;
    // scanner->original_insertion_mode = (enum InsertionMode)*offset++;

    // scanner->next_tag = (bool)*offset++;
    // scanner->next_tag_name = (uint8_t)*offset++;

    // memcpy(&scanner->next_tag_name_hash, offset, sizeof(XXH32_hash_t));
    // offset += sizeof(XXH32_hash_t);

    // #ifndef NO_IMPLIED_END_TAGS
    // scanner->implied_end_tags = (uint8_t)*offset++;
    // #endif

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
            case ElementNamespace_HTML:
                *element = lookup_html_element(tag_name.contents, tag_name.size);
                break;
            case ElementNamespace_MathML:
                *element = lookup_mathml_element(tag_name.contents, tag_name.size);
                break;
            case ElementNamespace_SVG:
                *element = lookup_svg_element(tag_name.contents, tag_name.size);
                break;
        }
    }

    // If we don't care about the hash, we can pass NULL for `name_hash` to skip this step
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

    if (valid_symbols[HtmlTokenType_StartTagName]) {
        enum ElementNamespace ns = get_current_namespace(scanner);
        uint8_t e;
        XXH32_hash_t name_hash;

        // // Check for a queued tag:
        // if (ns == ElementNamespace_HTML && scanner->next_tag) {
        //     e = scanner->next_tag_name;
        //     name_hash = scanner->next_tag_name_hash;
        //     while (!is_html_whitespace(lexer->lookahead) && lexer->lookahead != '/' && lexer->lookahead != '>')
        //         advance(lexer);
        //     scanner->next_tag = false;
        // } else {
            ASSERT(scan_tag_name(lexer, ns, &e, &name_hash));
        // }

        // Start with the default token for start tag names and disambiguate below
        lexer->result_symbol = HtmlTokenType_StartTagName;

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
                        break;

                    // Raw text elements
                    case HtmlElement_script:
                        array_push(&scanner->tags, e);
                        lexer->result_symbol = HtmlTokenType_ScriptStartTagName;
                        break;
                    case HtmlElement_style:
                        array_push(&scanner->tags, e);
                        lexer->result_symbol = HtmlTokenType_StyleStartTagName;
                        break;

                    // Escapable raw text elements
                    case HtmlElement_textarea:
                    case HtmlElement_title:
                        array_push(&scanner->tags, e);
                        lexer->result_symbol = HtmlTokenType_EscapableRawTextStartTagName;
                        break;

                    // Top-level elements
                    case HtmlElement_html:
                        array_push(&scanner->tags, HtmlElement_html);
                        array_push(&scanner->namespaces, ElementNamespace_HTML);
                        break;
                    // For top-level elements of foreign namespaces, we need to make sure that we are pushing the value from that namespace's enum onto the stack so that it can be matched with the end tag later. For example, `HtmlElement_math` and `HtmlElement_svg` are used for matching start tag names in HTML, but `MathmlElement_math` and `SvgElement_svg` are what should be pushed onto the stack.
                    case HtmlElement_math:
                        array_push(&scanner->tags, MathmlElement_math);
                        array_push(&scanner->namespaces, ElementNamespace_MathML);
                        break;
                    case HtmlElement_svg:
                        array_push(&scanner->tags, SvgElement_svg);
                        array_push(&scanner->namespaces, ElementNamespace_SVG);
                        break;

                    default:
                        array_push(&scanner->tags, e);
                }
                break;
            case ElementNamespace_MathML:
                array_push(&scanner->tags, e);
                // The top-level `math` element can be nested, so we need to push the MathML namespace again so that we know how many end tags to look for
                if (e == MathmlElement_math)
                    array_push(&scanner->namespaces, ElementNamespace_MathML);
                break;
            case ElementNamespace_SVG:
                array_push(&scanner->tags, e);
                // The top-level `svg` element can be nested, so we need to push the SVG namespace again so that we know how many end tags to look for
                if (e == SvgElement_svg)
                    array_push(&scanner->namespaces, ElementNamespace_SVG);
                break;
        }

        if (e == 0)
            // Again, 0 represents an unknown element in any namespace; push it's name hash onto the stack
            array_push(&scanner->custom_name_hashes, name_hash);

        return true;
    }

    if (valid_symbols[HtmlTokenType_EndTagName]) {
        enum ElementNamespace ns = get_current_namespace(scanner);
        uint8_t e;
        XXH32_hash_t name_hash;

        // // Check for a queued tag:
        // if (ns == ElementNamespace_HTML && scanner->next_tag) {
        //     e = scanner->next_tag_name;
        //     name_hash = scanner->next_tag_name_hash;
        //     while (!is_html_whitespace(lexer->lookahead) && lexer->lookahead != '/' && lexer->lookahead != '>')
        //         advance(lexer);
        //     scanner->next_tag = false;
        // } else {
            ASSERT(scan_tag_name(lexer, ns, &e, &name_hash));
        // }

        uint8_t top_tag = get_current_tag(scanner);
        XXH32_hash_t top_name_hash = 0;
        if (top_tag == 0)
            top_name_hash = *array_back(&scanner->custom_name_hashes);

        if (e == top_tag && name_hash == top_name_hash) {
            array_pop(&scanner->tags);

            if (top_name_hash)
                array_pop(&scanner->custom_name_hashes);

            if (
                (ns == ElementNamespace_HTML && e == HtmlElement_html) ||
                (ns == ElementNamespace_MathML && e == MathmlElement_math) ||
                (ns == ElementNamespace_SVG && e == SvgElement_svg)
            )
                array_pop(&scanner->namespaces);

            lexer->result_symbol = HtmlTokenType_EndTagName;
            return true;
        } else {
            lexer->result_symbol = HtmlTokenType_ErroneousEndTagName;
            return true;
        }
    }

    if (valid_symbols[HtmlTokenType_ErroneousEndTagName]) {
        ASSERT(isalpha(lexer->lookahead));
        advance(lexer);
        while (!lexer->eof(lexer) && !is_html_whitespace(lexer->lookahead) && lexer->lookahead != '/' && lexer->lookahead != '>')
            advance(lexer);
        lexer->result_symbol = HtmlTokenType_ErroneousEndTagName;
        return true;
    }

    if (valid_symbols[HtmlTokenType_SelfClosingTagDelimiter]) {
        #ifndef ALLOW_SELF_CLOSING_HTML_TAGS
        ASSERT(get_current_namespace(scanner) != ElementNamespace_HTML);
        #endif

        // This is necessary for some reason, probably due to a bug in the grammar
        while (is_html_whitespace(lexer->lookahead))
            skip(lexer);

        ASSERT(SCAN('/') && SCAN('>'));
        uint8_t e = array_pop(&scanner->tags);
        if (e == 0)
            array_pop(&scanner->custom_name_hashes);
        lexer->result_symbol = HtmlTokenType_SelfClosingTagDelimiter;
        return true;
    }

    // #ifndef NO_IMPLIED_END_TAGS
    // if (valid_symbols[HtmlTokenType_ImpliedEndTag]) {
    //     if (lexer->eof(lexer)) {
    //         lexer->result_symbol = HtmlTokenType_ImpliedEndTag;
    //         return true;
    //     }

    //     if (scanner->implied_end_tags > 0) {
    //         scanner->implied_end_tags -= 1;
    //         lexer->result_symbol = HtmlTokenType_ImpliedEndTag;
    //         return true;
    //     }

    //     ASSERT(get_current_namespace(scanner) == ElementNamespace_HTML);

    //     ASSERT(scanner->tags.size > 0);
    //     uint8_t *top = array_back(&scanner->tags);
    //     uint8_t e = *top;

    //     // The following elements can have implied end tags:
    //     ASSERT(e == HtmlElement_li ||
    //            e == HtmlElement_dt ||
    //            e == HtmlElement_dd ||
    //            e == HtmlElement_p ||
    //            e == HtmlElement_rt ||
    //            e == HtmlElement_rp ||
    //            e == HtmlElement_optgroup ||
    //            e == HtmlElement_option ||
    //            e == HtmlElement_colgroup ||
    //            e == HtmlElement_caption ||
    //            e == HtmlElement_thead ||
    //            e == HtmlElement_tbody ||
    //            e == HtmlElement_tfoot ||
    //            e == HtmlElement_tr ||
    //            e == HtmlElement_td ||
    //            e == HtmlElement_th);

    //     // This is a zero-width symbol
    //     lexer->mark_end(lexer);
    //     advance(lexer);

    //     uint8_t next;
    //     XXH32_hash_t next_hash;

    //     if (SCAN('/')) {
    //         // The following can have implied end tags if there is no more content in the parent:
    //         ASSERT(e == HtmlElement_li ||
    //                e == HtmlElement_dd ||
    //                e == HtmlElement_p ||
    //                e == HtmlElement_rt ||
    //                e == HtmlElement_rp ||
    //                e == HtmlElement_optgroup ||
    //                e == HtmlElement_option ||
    //                e == HtmlElement_tbody ||
    //                e == HtmlElement_tfoot ||
    //                e == HtmlElement_tr ||
    //                e == HtmlElement_td ||
    //                e == HtmlElement_th);

    //         ASSERT(scanner->tags.size >= 2);
    //         uint8_t parent = *(top - 1);

    //         if (e == HtmlElement_p) {
    //             // The `p` element can only have an implied end tag under this condition if the parent is *not* one of these:
    //             ASSERT(parent != HtmlElement_a &&
    //                    parent != HtmlElement_audio &&
    //                    parent != HtmlElement_del &&
    //                    parent != HtmlElement_ins &&
    //                    parent != HtmlElement_map &&
    //                    parent != HtmlElement_noscript &&
    //                    parent != HtmlElement_video &&
    //                    parent != HtmlElement_Unknown);
    //         }

    //         ASSERT(scan_tag_name(lexer, ElementNamespace_HTML, &next, &next_hash));

    //         if (parent == HtmlElement_Unknown) {
    //             ASSERT(next == parent && next_hash == *array_back(&scanner->custom_name_hashes));
    //         } else {
    //             ASSERT(next == parent);
    //         }
    //     } else {
    //         // The only element from the above list that cannot have an implied end tag under this condition is `tfoot`
    //         ASSERT(e != HtmlElement_tfoot);

    //         ASSERT(scan_tag_name(lexer, ElementNamespace_HTML, &next, NULL));
    //         ASSERT(next != HtmlElement_Unknown);

    //         switch (e) {
    //             case HtmlElement_li:
    //                 ASSERT(next == HtmlElement_li);
    //                 break;
    //             case HtmlElement_dt:
    //                 ASSERT(next == HtmlElement_dt || next == HtmlElement_dd);
    //                 break;
    //             case HtmlElement_dd:
    //                 ASSERT(next == HtmlElement_dd || next == HtmlElement_dt);
    //                 break;
    //             case HtmlElement_p:
    //                 ASSERT(next == HtmlElement_address ||
    //                        next == HtmlElement_article ||
    //                        next == HtmlElement_aside ||
    //                        next == HtmlElement_blockquote ||
    //                        next == HtmlElement_details ||
    //                        next == HtmlElement_dialog ||
    //                        next == HtmlElement_div ||
    //                        next == HtmlElement_dl ||
    //                        next == HtmlElement_fieldset ||
    //                        next == HtmlElement_figcaption ||
    //                        next == HtmlElement_figure ||
    //                        next == HtmlElement_footer ||
    //                        next == HtmlElement_form ||
    //                        next == HtmlElement_h1 ||
    //                        next == HtmlElement_h2 ||
    //                        next == HtmlElement_h3 ||
    //                        next == HtmlElement_h4 ||
    //                        next == HtmlElement_h5 ||
    //                        next == HtmlElement_h6 ||
    //                        next == HtmlElement_header ||
    //                        next == HtmlElement_hgroup ||
    //                        next == HtmlElement_hr ||
    //                        next == HtmlElement_main ||
    //                        next == HtmlElement_menu ||
    //                        next == HtmlElement_nav ||
    //                        next == HtmlElement_ol ||
    //                        next == HtmlElement_p ||
    //                        next == HtmlElement_pre ||
    //                        next == HtmlElement_search ||
    //                        next == HtmlElement_section ||
    //                        next == HtmlElement_table ||
    //                        next == HtmlElement_ul);
    //                 break;
    //             case HtmlElement_rt:
    //                 ASSERT(next == HtmlElement_rt || next == HtmlElement_rp);
    //                 break;
    //             case HtmlElement_rp:
    //                 ASSERT(next == HtmlElement_rt || next == HtmlElement_rp);
    //                 break;
    //             case HtmlElement_optgroup:
    //                 ASSERT(next == HtmlElement_optgroup || next == HtmlElement_hr);
    //                 break;
    //             case HtmlElement_option:
    //                 ASSERT(next == HtmlElement_option || next == HtmlElement_optgroup);
    //                 break;
    //             // case HtmlElement_colgroup:  // TODO
    //             //     break;
    //             // case HtmlElement_caption:  // TODO
    //             //     break;
    //             case HtmlElement_thead:
    //                 ASSERT(next == HtmlElement_tbody || next == HtmlElement_tfoot);
    //                 break;
    //             case HtmlElement_tbody:
    //                 ASSERT(next == HtmlElement_tbody || next == HtmlElement_tfoot);
    //                 break;
    //             case HtmlElement_tr:
    //                 ASSERT(next == HtmlElement_tr);
    //                 break;
    //             case HtmlElement_td:
    //                 ASSERT(next == HtmlElement_td || next == HtmlElement_th);
    //                 break;
    //             case HtmlElement_th:
    //                 ASSERT(next == HtmlElement_td || next == HtmlElement_th);
    //                 break;
    //             default:
    //                 return false;
    //         }
    //     }

    //     scanner->next_tag = true;
    //     scanner->next_tag_name = next;
    //     scanner->next_tag_name_hash = next_hash;
    //     lexer->result_symbol = HtmlTokenType_ImpliedEndTag;
    //     return true;
    // }
    // #endif

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

    if (valid_symbols[HtmlTokenType_RawText]) {
        // Leading whitespace should not be included as part of the text
        while (is_html_whitespace(lexer->lookahead))
            skip(lexer);

        bool text_matched = false;

        enum HtmlElement top_tag = get_current_tag(scanner);

        lexer->mark_end(lexer);

        while (!lexer->eof(lexer)) {
            int c = lexer->lookahead;
            advance(lexer);
    
            if (c == '<') {
                // Check for the end tag
                if (lexer->lookahead == '/') {
                    advance(lexer);
                    if (top_tag == HtmlElement_script) {
                        if (SCAN_ICASE('S') && SCAN_ICASE('C') && SCAN_ICASE('R') && SCAN_ICASE('I') && SCAN_ICASE('P') && SCAN_ICASE('T')) {
                            if (is_html_whitespace(lexer->lookahead) || lexer->lookahead == '>' || lexer->lookahead == '/')
                                break;
                        }
                    } else if (top_tag == HtmlElement_style) {
                        if (SCAN_ICASE('S') && SCAN_ICASE('T') && SCAN_ICASE('Y') && SCAN_ICASE('L') && SCAN_ICASE('E')) {
                            if (is_html_whitespace(lexer->lookahead) || lexer->lookahead == '>' || lexer->lookahead == '/')
                                break;
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
        
        if (text_matched) {
            lexer->result_symbol = HtmlTokenType_RawText;
            return true;
        }
    }

    if (valid_symbols[HtmlTokenType_EscapableRawText] && lexer->lookahead != '&') {
        // Leading whitespace should not be included as part of the text
        while (is_html_whitespace(lexer->lookahead))
            skip(lexer);

        bool text_matched = false;

        enum HtmlElement top_tag = get_current_tag(scanner);
    
        lexer->mark_end(lexer);
    
        while (!lexer->eof(lexer) && lexer->lookahead != '&') {
            int c = lexer->lookahead;
            advance(lexer);

            if (c == '<') {
                // Check for the end tag
                if (lexer->lookahead == '/') {
                    advance(lexer);
                    if (top_tag == HtmlElement_textarea) {
                        if (SCAN_ICASE('T') && SCAN_ICASE('E') && SCAN_ICASE('X') && SCAN_ICASE('T') && SCAN_ICASE('A') && SCAN_ICASE('R') && SCAN_ICASE('E') && SCAN_ICASE('A')) {
                            if (is_html_whitespace(lexer->lookahead) || lexer->lookahead == '>' || lexer->lookahead == '/')
                                break;
                        }
                    } else if (top_tag == HtmlElement_title) {
                        if (SCAN_ICASE('T') && SCAN_ICASE('I') && SCAN_ICASE('T') && SCAN_ICASE('L') && SCAN_ICASE('E')) {
                            if (is_html_whitespace(lexer->lookahead) || lexer->lookahead == '>' || lexer->lookahead == '/')
                                break;
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
        
        if (text_matched) {
            lexer->result_symbol = HtmlTokenType_EscapableRawText;
            return true;
        }
    }

    if ((valid_symbols[HtmlTokenType_FullCharacterReference] || valid_symbols[HtmlTokenType_ShortCharacterReference] || valid_symbols[HtmlTokenType_InvalidCharacterReference]) && lexer->lookahead == '&') {
        advance(lexer);

        if (SCAN('#')) {
            ASSERT(valid_symbols[HtmlTokenType_FullCharacterReference]);
            // Numeric character reference
            if (SCAN_ICASE('X')) {
                // Hexadecimal
                ASSERT(isxdigit(lexer->lookahead));
                do { advance(lexer); } while (isxdigit(lexer->lookahead));
                ASSERT(SCAN(';'));
                lexer->result_symbol = HtmlTokenType_FullCharacterReference;
                return true;
            } else {
                // Decimal
                ASSERT(isdigit(lexer->lookahead));
                do { advance(lexer); } while (isdigit(lexer->lookahead));
                ASSERT(SCAN(';'));
                lexer->result_symbol = HtmlTokenType_FullCharacterReference;
                return true;
            }
        } else {
            // Named character reference
            static Array(char) name = array_new();
            array_clear(&name);

            lexer->mark_end(lexer);

            while (isalnum(lexer->lookahead)) {
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
                            lexer->result_symbol = HtmlTokenType_CommentText;
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
