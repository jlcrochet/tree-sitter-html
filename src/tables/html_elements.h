#ifndef TRIE_HASH_lookup_html_element
#define TRIE_HASH_lookup_html_element
#include <stddef.h>
#include <stdint.h>
enum HtmlElement {
    HtmlElement_a = 1,
    HtmlElement_abbr = 2,
    HtmlElement_address = 3,
    HtmlElement_area = 4,
    HtmlElement_article = 5,
    HtmlElement_aside = 6,
    HtmlElement_audio = 7,
    HtmlElement_b = 8,
    HtmlElement_bdi = 10,
    HtmlElement_bdo = 11,
    HtmlElement_br = 14,
    HtmlElement_base = 9,
    HtmlElement_blockquote = 12,
    HtmlElement_body = 13,
    HtmlElement_button = 15,
    HtmlElement_col = 20,
    HtmlElement_canvas = 16,
    HtmlElement_caption = 17,
    HtmlElement_cite = 18,
    HtmlElement_code = 19,
    HtmlElement_colgroup = 21,
    HtmlElement_dd = 24,
    HtmlElement_del = 25,
    HtmlElement_dfn = 27,
    HtmlElement_div = 29,
    HtmlElement_dl = 30,
    HtmlElement_dt = 31,
    HtmlElement_data = 22,
    HtmlElement_datalist = 23,
    HtmlElement_details = 26,
    HtmlElement_dialog = 28,
    HtmlElement_em = 32,
    HtmlElement_embed = 33,
    HtmlElement_fieldset = 34,
    HtmlElement_figcaption = 35,
    HtmlElement_figure = 36,
    HtmlElement_footer = 37,
    HtmlElement_form = 38,
    HtmlElement_h1 = 42,
    HtmlElement_h2 = 43,
    HtmlElement_h3 = 44,
    HtmlElement_h4 = 45,
    HtmlElement_h5 = 46,
    HtmlElement_h6 = 47,
    HtmlElement_hr = 48,
    HtmlElement_head = 39,
    HtmlElement_header = 40,
    HtmlElement_hgroup = 41,
    HtmlElement_html = 49,
    HtmlElement_i = 50,
    HtmlElement_img = 52,
    HtmlElement_ins = 54,
    HtmlElement_iframe = 51,
    HtmlElement_input = 53,
    HtmlElement_kbd = 55,
    HtmlElement_keygen = 56,
    HtmlElement_li = 59,
    HtmlElement_label = 57,
    HtmlElement_legend = 58,
    HtmlElement_link = 60,
    HtmlElement_map = 62,
    HtmlElement_main = 61,
    HtmlElement_mark = 63,
    HtmlElement_math = 64,
    HtmlElement_menu = 65,
    HtmlElement_menuitem = 66,
    HtmlElement_meta = 67,
    HtmlElement_meter = 68,
    HtmlElement_nav = 69,
    HtmlElement_noscript = 70,
    HtmlElement_ol = 72,
    HtmlElement_object = 71,
    HtmlElement_optgroup = 73,
    HtmlElement_option = 74,
    HtmlElement_output = 75,
    HtmlElement_p = 76,
    HtmlElement_pre = 79,
    HtmlElement_param = 77,
    HtmlElement_picture = 78,
    HtmlElement_progress = 80,
    HtmlElement_q = 81,
    HtmlElement_rp = 82,
    HtmlElement_rt = 83,
    HtmlElement_ruby = 84,
    HtmlElement_s = 85,
    HtmlElement_sub = 95,
    HtmlElement_sup = 97,
    HtmlElement_svg = 98,
    HtmlElement_samp = 86,
    HtmlElement_script = 87,
    HtmlElement_section = 88,
    HtmlElement_select = 89,
    HtmlElement_small = 90,
    HtmlElement_source = 91,
    HtmlElement_span = 92,
    HtmlElement_strong = 93,
    HtmlElement_style = 94,
    HtmlElement_summary = 96,
    HtmlElement_td = 101,
    HtmlElement_th = 105,
    HtmlElement_tr = 109,
    HtmlElement_table = 99,
    HtmlElement_tbody = 100,
    HtmlElement_template = 102,
    HtmlElement_textarea = 103,
    HtmlElement_tfoot = 104,
    HtmlElement_thead = 106,
    HtmlElement_time = 107,
    HtmlElement_title = 108,
    HtmlElement_track = 110,
    HtmlElement_u = 111,
    HtmlElement_ul = 112,
    HtmlElement_var = 113,
    HtmlElement_video = 114,
    HtmlElement_wbr = 115,
    HtmlElement_Unknown = 0,
};
static enum HtmlElement lookup_html_element(const char *string, size_t length);
#ifdef __GNUC__
typedef uint16_t __attribute__((aligned (1))) triehash_uu16;
typedef char static_assert16[__alignof__(triehash_uu16) == 1 ? 1 : -1];
typedef uint32_t __attribute__((aligned (1))) triehash_uu32;
typedef char static_assert32[__alignof__(triehash_uu32) == 1 ? 1 : -1];
typedef uint64_t __attribute__((aligned (1))) triehash_uu64;
typedef char static_assert64[__alignof__(triehash_uu64) == 1 ? 1 : -1];
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#define onechar(c, s, l) (((uint64_t)(c)) << (s))
#else
#define onechar(c, s, l) (((uint64_t)(c)) << (l-8-s))
#endif
#if (!defined(__ARM_ARCH) || defined(__ARM_FEATURE_UNALIGNED)) && !defined(TRIE_HASH_NO_MULTI_BYTE)
#define TRIE_HASH_MULTI_BYTE
#endif
#endif /*GNUC */
#ifdef TRIE_HASH_MULTI_BYTE
static enum HtmlElement lookup_html_element1(const char *string)
{
    switch(string[0]) {
    case 0| onechar('a', 0, 8):
        return HtmlElement_a;
        break;
    case 0| onechar('b', 0, 8):
        return HtmlElement_b;
        break;
    case 0| onechar('i', 0, 8):
        return HtmlElement_i;
        break;
    case 0| onechar('p', 0, 8):
        return HtmlElement_p;
        break;
    case 0| onechar('q', 0, 8):
        return HtmlElement_q;
        break;
    case 0| onechar('s', 0, 8):
        return HtmlElement_s;
        break;
    case 0| onechar('u', 0, 8):
        return HtmlElement_u;
    }
    return HtmlElement_Unknown;
}
static enum HtmlElement lookup_html_element2(const char *string)
{
    switch(string[0]) {
    case 0| onechar('b', 0, 8):
        switch(string[1]) {
        case 0| onechar('r', 0, 8):
            return HtmlElement_br;
        }
        break;
    case 0| onechar('d', 0, 8):
        switch(string[1]) {
        case 0| onechar('d', 0, 8):
            return HtmlElement_dd;
            break;
        case 0| onechar('l', 0, 8):
            return HtmlElement_dl;
            break;
        case 0| onechar('t', 0, 8):
            return HtmlElement_dt;
        }
        break;
    case 0| onechar('e', 0, 8):
        switch(string[1]) {
        case 0| onechar('m', 0, 8):
            return HtmlElement_em;
        }
        break;
    case 0| onechar('h', 0, 8):
        switch(string[1]) {
        case 0| onechar('1', 0, 8):
            return HtmlElement_h1;
            break;
        case 0| onechar('2', 0, 8):
            return HtmlElement_h2;
            break;
        case 0| onechar('3', 0, 8):
            return HtmlElement_h3;
            break;
        case 0| onechar('4', 0, 8):
            return HtmlElement_h4;
            break;
        case 0| onechar('5', 0, 8):
            return HtmlElement_h5;
            break;
        case 0| onechar('6', 0, 8):
            return HtmlElement_h6;
            break;
        case 0| onechar('r', 0, 8):
            return HtmlElement_hr;
        }
        break;
    case 0| onechar('l', 0, 8):
        switch(string[1]) {
        case 0| onechar('i', 0, 8):
            return HtmlElement_li;
        }
        break;
    case 0| onechar('o', 0, 8):
        switch(string[1]) {
        case 0| onechar('l', 0, 8):
            return HtmlElement_ol;
        }
        break;
    case 0| onechar('r', 0, 8):
        switch(string[1]) {
        case 0| onechar('p', 0, 8):
            return HtmlElement_rp;
            break;
        case 0| onechar('t', 0, 8):
            return HtmlElement_rt;
        }
        break;
    case 0| onechar('t', 0, 8):
        switch(string[1]) {
        case 0| onechar('d', 0, 8):
            return HtmlElement_td;
            break;
        case 0| onechar('h', 0, 8):
            return HtmlElement_th;
            break;
        case 0| onechar('r', 0, 8):
            return HtmlElement_tr;
        }
        break;
    case 0| onechar('u', 0, 8):
        switch(string[1]) {
        case 0| onechar('l', 0, 8):
            return HtmlElement_ul;
        }
    }
    return HtmlElement_Unknown;
}
static enum HtmlElement lookup_html_element3(const char *string)
{
    switch(string[0]) {
    case 0| onechar('b', 0, 8):
        switch(string[1]) {
        case 0| onechar('d', 0, 8):
            switch(string[2]) {
            case 0| onechar('i', 0, 8):
                return HtmlElement_bdi;
                break;
            case 0| onechar('o', 0, 8):
                return HtmlElement_bdo;
            }
        }
        break;
    case 0| onechar('c', 0, 8):
        switch(string[1]) {
        case 0| onechar('o', 0, 8):
            switch(string[2]) {
            case 0| onechar('l', 0, 8):
                return HtmlElement_col;
            }
        }
        break;
    case 0| onechar('d', 0, 8):
        switch(string[1]) {
        case 0| onechar('e', 0, 8):
            switch(string[2]) {
            case 0| onechar('l', 0, 8):
                return HtmlElement_del;
            }
            break;
        case 0| onechar('f', 0, 8):
            switch(string[2]) {
            case 0| onechar('n', 0, 8):
                return HtmlElement_dfn;
            }
            break;
        case 0| onechar('i', 0, 8):
            switch(string[2]) {
            case 0| onechar('v', 0, 8):
                return HtmlElement_div;
            }
        }
        break;
    case 0| onechar('i', 0, 8):
        switch(string[1]) {
        case 0| onechar('m', 0, 8):
            switch(string[2]) {
            case 0| onechar('g', 0, 8):
                return HtmlElement_img;
            }
            break;
        case 0| onechar('n', 0, 8):
            switch(string[2]) {
            case 0| onechar('s', 0, 8):
                return HtmlElement_ins;
            }
        }
        break;
    case 0| onechar('k', 0, 8):
        switch(string[1]) {
        case 0| onechar('b', 0, 8):
            switch(string[2]) {
            case 0| onechar('d', 0, 8):
                return HtmlElement_kbd;
            }
        }
        break;
    case 0| onechar('m', 0, 8):
        switch(string[1]) {
        case 0| onechar('a', 0, 8):
            switch(string[2]) {
            case 0| onechar('p', 0, 8):
                return HtmlElement_map;
            }
        }
        break;
    case 0| onechar('n', 0, 8):
        switch(string[1]) {
        case 0| onechar('a', 0, 8):
            switch(string[2]) {
            case 0| onechar('v', 0, 8):
                return HtmlElement_nav;
            }
        }
        break;
    case 0| onechar('p', 0, 8):
        switch(string[1]) {
        case 0| onechar('r', 0, 8):
            switch(string[2]) {
            case 0| onechar('e', 0, 8):
                return HtmlElement_pre;
            }
        }
        break;
    case 0| onechar('s', 0, 8):
        switch(string[1]) {
        case 0| onechar('u', 0, 8):
            switch(string[2]) {
            case 0| onechar('b', 0, 8):
                return HtmlElement_sub;
                break;
            case 0| onechar('p', 0, 8):
                return HtmlElement_sup;
            }
            break;
        case 0| onechar('v', 0, 8):
            switch(string[2]) {
            case 0| onechar('g', 0, 8):
                return HtmlElement_svg;
            }
        }
        break;
    case 0| onechar('v', 0, 8):
        switch(string[1]) {
        case 0| onechar('a', 0, 8):
            switch(string[2]) {
            case 0| onechar('r', 0, 8):
                return HtmlElement_var;
            }
        }
        break;
    case 0| onechar('w', 0, 8):
        switch(string[1]) {
        case 0| onechar('b', 0, 8):
            switch(string[2]) {
            case 0| onechar('r', 0, 8):
                return HtmlElement_wbr;
            }
        }
    }
    return HtmlElement_Unknown;
}
static enum HtmlElement lookup_html_element4(const char *string)
{
    switch(*((triehash_uu32*) &string[0])) {
    case 0| onechar('a', 0, 32)| onechar('b', 8, 32)| onechar('b', 16, 32)| onechar('r', 24, 32):
        return HtmlElement_abbr;
        break;
    case 0| onechar('a', 0, 32)| onechar('r', 8, 32)| onechar('e', 16, 32)| onechar('a', 24, 32):
        return HtmlElement_area;
        break;
    case 0| onechar('b', 0, 32)| onechar('a', 8, 32)| onechar('s', 16, 32)| onechar('e', 24, 32):
        return HtmlElement_base;
        break;
    case 0| onechar('b', 0, 32)| onechar('o', 8, 32)| onechar('d', 16, 32)| onechar('y', 24, 32):
        return HtmlElement_body;
        break;
    case 0| onechar('c', 0, 32)| onechar('i', 8, 32)| onechar('t', 16, 32)| onechar('e', 24, 32):
        return HtmlElement_cite;
        break;
    case 0| onechar('c', 0, 32)| onechar('o', 8, 32)| onechar('d', 16, 32)| onechar('e', 24, 32):
        return HtmlElement_code;
        break;
    case 0| onechar('d', 0, 32)| onechar('a', 8, 32)| onechar('t', 16, 32)| onechar('a', 24, 32):
        return HtmlElement_data;
        break;
    case 0| onechar('f', 0, 32)| onechar('o', 8, 32)| onechar('r', 16, 32)| onechar('m', 24, 32):
        return HtmlElement_form;
        break;
    case 0| onechar('h', 0, 32)| onechar('e', 8, 32)| onechar('a', 16, 32)| onechar('d', 24, 32):
        return HtmlElement_head;
        break;
    case 0| onechar('h', 0, 32)| onechar('t', 8, 32)| onechar('m', 16, 32)| onechar('l', 24, 32):
        return HtmlElement_html;
        break;
    case 0| onechar('l', 0, 32)| onechar('i', 8, 32)| onechar('n', 16, 32)| onechar('k', 24, 32):
        return HtmlElement_link;
        break;
    case 0| onechar('m', 0, 32)| onechar('a', 8, 32)| onechar('i', 16, 32)| onechar('n', 24, 32):
        return HtmlElement_main;
        break;
    case 0| onechar('m', 0, 32)| onechar('a', 8, 32)| onechar('r', 16, 32)| onechar('k', 24, 32):
        return HtmlElement_mark;
        break;
    case 0| onechar('m', 0, 32)| onechar('a', 8, 32)| onechar('t', 16, 32)| onechar('h', 24, 32):
        return HtmlElement_math;
        break;
    case 0| onechar('m', 0, 32)| onechar('e', 8, 32)| onechar('n', 16, 32)| onechar('u', 24, 32):
        return HtmlElement_menu;
        break;
    case 0| onechar('m', 0, 32)| onechar('e', 8, 32)| onechar('t', 16, 32)| onechar('a', 24, 32):
        return HtmlElement_meta;
        break;
    case 0| onechar('r', 0, 32)| onechar('u', 8, 32)| onechar('b', 16, 32)| onechar('y', 24, 32):
        return HtmlElement_ruby;
        break;
    case 0| onechar('s', 0, 32)| onechar('a', 8, 32)| onechar('m', 16, 32)| onechar('p', 24, 32):
        return HtmlElement_samp;
        break;
    case 0| onechar('s', 0, 32)| onechar('p', 8, 32)| onechar('a', 16, 32)| onechar('n', 24, 32):
        return HtmlElement_span;
        break;
    case 0| onechar('t', 0, 32)| onechar('i', 8, 32)| onechar('m', 16, 32)| onechar('e', 24, 32):
        return HtmlElement_time;
    }
    return HtmlElement_Unknown;
}
static enum HtmlElement lookup_html_element5(const char *string)
{
    switch(*((triehash_uu32*) &string[0])) {
    case 0| onechar('a', 0, 32)| onechar('s', 8, 32)| onechar('i', 16, 32)| onechar('d', 24, 32):
        switch(string[4]) {
        case 0| onechar('e', 0, 8):
            return HtmlElement_aside;
        }
        break;
    case 0| onechar('a', 0, 32)| onechar('u', 8, 32)| onechar('d', 16, 32)| onechar('i', 24, 32):
        switch(string[4]) {
        case 0| onechar('o', 0, 8):
            return HtmlElement_audio;
        }
        break;
    case 0| onechar('e', 0, 32)| onechar('m', 8, 32)| onechar('b', 16, 32)| onechar('e', 24, 32):
        switch(string[4]) {
        case 0| onechar('d', 0, 8):
            return HtmlElement_embed;
        }
        break;
    case 0| onechar('i', 0, 32)| onechar('n', 8, 32)| onechar('p', 16, 32)| onechar('u', 24, 32):
        switch(string[4]) {
        case 0| onechar('t', 0, 8):
            return HtmlElement_input;
        }
        break;
    case 0| onechar('l', 0, 32)| onechar('a', 8, 32)| onechar('b', 16, 32)| onechar('e', 24, 32):
        switch(string[4]) {
        case 0| onechar('l', 0, 8):
            return HtmlElement_label;
        }
        break;
    case 0| onechar('m', 0, 32)| onechar('e', 8, 32)| onechar('t', 16, 32)| onechar('e', 24, 32):
        switch(string[4]) {
        case 0| onechar('r', 0, 8):
            return HtmlElement_meter;
        }
        break;
    case 0| onechar('p', 0, 32)| onechar('a', 8, 32)| onechar('r', 16, 32)| onechar('a', 24, 32):
        switch(string[4]) {
        case 0| onechar('m', 0, 8):
            return HtmlElement_param;
        }
        break;
    case 0| onechar('s', 0, 32)| onechar('m', 8, 32)| onechar('a', 16, 32)| onechar('l', 24, 32):
        switch(string[4]) {
        case 0| onechar('l', 0, 8):
            return HtmlElement_small;
        }
        break;
    case 0| onechar('s', 0, 32)| onechar('t', 8, 32)| onechar('y', 16, 32)| onechar('l', 24, 32):
        switch(string[4]) {
        case 0| onechar('e', 0, 8):
            return HtmlElement_style;
        }
        break;
    case 0| onechar('t', 0, 32)| onechar('a', 8, 32)| onechar('b', 16, 32)| onechar('l', 24, 32):
        switch(string[4]) {
        case 0| onechar('e', 0, 8):
            return HtmlElement_table;
        }
        break;
    case 0| onechar('t', 0, 32)| onechar('b', 8, 32)| onechar('o', 16, 32)| onechar('d', 24, 32):
        switch(string[4]) {
        case 0| onechar('y', 0, 8):
            return HtmlElement_tbody;
        }
        break;
    case 0| onechar('t', 0, 32)| onechar('f', 8, 32)| onechar('o', 16, 32)| onechar('o', 24, 32):
        switch(string[4]) {
        case 0| onechar('t', 0, 8):
            return HtmlElement_tfoot;
        }
        break;
    case 0| onechar('t', 0, 32)| onechar('h', 8, 32)| onechar('e', 16, 32)| onechar('a', 24, 32):
        switch(string[4]) {
        case 0| onechar('d', 0, 8):
            return HtmlElement_thead;
        }
        break;
    case 0| onechar('t', 0, 32)| onechar('i', 8, 32)| onechar('t', 16, 32)| onechar('l', 24, 32):
        switch(string[4]) {
        case 0| onechar('e', 0, 8):
            return HtmlElement_title;
        }
        break;
    case 0| onechar('t', 0, 32)| onechar('r', 8, 32)| onechar('a', 16, 32)| onechar('c', 24, 32):
        switch(string[4]) {
        case 0| onechar('k', 0, 8):
            return HtmlElement_track;
        }
        break;
    case 0| onechar('v', 0, 32)| onechar('i', 8, 32)| onechar('d', 16, 32)| onechar('e', 24, 32):
        switch(string[4]) {
        case 0| onechar('o', 0, 8):
            return HtmlElement_video;
        }
    }
    return HtmlElement_Unknown;
}
static enum HtmlElement lookup_html_element6(const char *string)
{
    switch(*((triehash_uu32*) &string[0])) {
    case 0| onechar('b', 0, 32)| onechar('u', 8, 32)| onechar('t', 16, 32)| onechar('t', 24, 32):
        switch(string[4]) {
        case 0| onechar('o', 0, 8):
            switch(string[5]) {
            case 0| onechar('n', 0, 8):
                return HtmlElement_button;
            }
        }
        break;
    case 0| onechar('c', 0, 32)| onechar('a', 8, 32)| onechar('n', 16, 32)| onechar('v', 24, 32):
        switch(string[4]) {
        case 0| onechar('a', 0, 8):
            switch(string[5]) {
            case 0| onechar('s', 0, 8):
                return HtmlElement_canvas;
            }
        }
        break;
    case 0| onechar('d', 0, 32)| onechar('i', 8, 32)| onechar('a', 16, 32)| onechar('l', 24, 32):
        switch(string[4]) {
        case 0| onechar('o', 0, 8):
            switch(string[5]) {
            case 0| onechar('g', 0, 8):
                return HtmlElement_dialog;
            }
        }
        break;
    case 0| onechar('f', 0, 32)| onechar('i', 8, 32)| onechar('g', 16, 32)| onechar('u', 24, 32):
        switch(string[4]) {
        case 0| onechar('r', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return HtmlElement_figure;
            }
        }
        break;
    case 0| onechar('f', 0, 32)| onechar('o', 8, 32)| onechar('o', 16, 32)| onechar('t', 24, 32):
        switch(string[4]) {
        case 0| onechar('e', 0, 8):
            switch(string[5]) {
            case 0| onechar('r', 0, 8):
                return HtmlElement_footer;
            }
        }
        break;
    case 0| onechar('h', 0, 32)| onechar('e', 8, 32)| onechar('a', 16, 32)| onechar('d', 24, 32):
        switch(string[4]) {
        case 0| onechar('e', 0, 8):
            switch(string[5]) {
            case 0| onechar('r', 0, 8):
                return HtmlElement_header;
            }
        }
        break;
    case 0| onechar('h', 0, 32)| onechar('g', 8, 32)| onechar('r', 16, 32)| onechar('o', 24, 32):
        switch(string[4]) {
        case 0| onechar('u', 0, 8):
            switch(string[5]) {
            case 0| onechar('p', 0, 8):
                return HtmlElement_hgroup;
            }
        }
        break;
    case 0| onechar('i', 0, 32)| onechar('f', 8, 32)| onechar('r', 16, 32)| onechar('a', 24, 32):
        switch(string[4]) {
        case 0| onechar('m', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return HtmlElement_iframe;
            }
        }
        break;
    case 0| onechar('k', 0, 32)| onechar('e', 8, 32)| onechar('y', 16, 32)| onechar('g', 24, 32):
        switch(string[4]) {
        case 0| onechar('e', 0, 8):
            switch(string[5]) {
            case 0| onechar('n', 0, 8):
                return HtmlElement_keygen;
            }
        }
        break;
    case 0| onechar('l', 0, 32)| onechar('e', 8, 32)| onechar('g', 16, 32)| onechar('e', 24, 32):
        switch(string[4]) {
        case 0| onechar('n', 0, 8):
            switch(string[5]) {
            case 0| onechar('d', 0, 8):
                return HtmlElement_legend;
            }
        }
        break;
    case 0| onechar('o', 0, 32)| onechar('b', 8, 32)| onechar('j', 16, 32)| onechar('e', 24, 32):
        switch(string[4]) {
        case 0| onechar('c', 0, 8):
            switch(string[5]) {
            case 0| onechar('t', 0, 8):
                return HtmlElement_object;
            }
        }
        break;
    case 0| onechar('o', 0, 32)| onechar('p', 8, 32)| onechar('t', 16, 32)| onechar('i', 24, 32):
        switch(string[4]) {
        case 0| onechar('o', 0, 8):
            switch(string[5]) {
            case 0| onechar('n', 0, 8):
                return HtmlElement_option;
            }
        }
        break;
    case 0| onechar('o', 0, 32)| onechar('u', 8, 32)| onechar('t', 16, 32)| onechar('p', 24, 32):
        switch(string[4]) {
        case 0| onechar('u', 0, 8):
            switch(string[5]) {
            case 0| onechar('t', 0, 8):
                return HtmlElement_output;
            }
        }
        break;
    case 0| onechar('s', 0, 32)| onechar('c', 8, 32)| onechar('r', 16, 32)| onechar('i', 24, 32):
        switch(string[4]) {
        case 0| onechar('p', 0, 8):
            switch(string[5]) {
            case 0| onechar('t', 0, 8):
                return HtmlElement_script;
            }
        }
        break;
    case 0| onechar('s', 0, 32)| onechar('e', 8, 32)| onechar('l', 16, 32)| onechar('e', 24, 32):
        switch(string[4]) {
        case 0| onechar('c', 0, 8):
            switch(string[5]) {
            case 0| onechar('t', 0, 8):
                return HtmlElement_select;
            }
        }
        break;
    case 0| onechar('s', 0, 32)| onechar('o', 8, 32)| onechar('u', 16, 32)| onechar('r', 24, 32):
        switch(string[4]) {
        case 0| onechar('c', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return HtmlElement_source;
            }
        }
        break;
    case 0| onechar('s', 0, 32)| onechar('t', 8, 32)| onechar('r', 16, 32)| onechar('o', 24, 32):
        switch(string[4]) {
        case 0| onechar('n', 0, 8):
            switch(string[5]) {
            case 0| onechar('g', 0, 8):
                return HtmlElement_strong;
            }
        }
    }
    return HtmlElement_Unknown;
}
static enum HtmlElement lookup_html_element7(const char *string)
{
    switch(*((triehash_uu32*) &string[0])) {
    case 0| onechar('a', 0, 32)| onechar('d', 8, 32)| onechar('d', 16, 32)| onechar('r', 24, 32):
        switch(string[4]) {
        case 0| onechar('e', 0, 8):
            switch(string[5]) {
            case 0| onechar('s', 0, 8):
                switch(string[6]) {
                case 0| onechar('s', 0, 8):
                    return HtmlElement_address;
                }
            }
        }
        break;
    case 0| onechar('a', 0, 32)| onechar('r', 8, 32)| onechar('t', 16, 32)| onechar('i', 24, 32):
        switch(string[4]) {
        case 0| onechar('c', 0, 8):
            switch(string[5]) {
            case 0| onechar('l', 0, 8):
                switch(string[6]) {
                case 0| onechar('e', 0, 8):
                    return HtmlElement_article;
                }
            }
        }
        break;
    case 0| onechar('c', 0, 32)| onechar('a', 8, 32)| onechar('p', 16, 32)| onechar('t', 24, 32):
        switch(string[4]) {
        case 0| onechar('i', 0, 8):
            switch(string[5]) {
            case 0| onechar('o', 0, 8):
                switch(string[6]) {
                case 0| onechar('n', 0, 8):
                    return HtmlElement_caption;
                }
            }
        }
        break;
    case 0| onechar('d', 0, 32)| onechar('e', 8, 32)| onechar('t', 16, 32)| onechar('a', 24, 32):
        switch(string[4]) {
        case 0| onechar('i', 0, 8):
            switch(string[5]) {
            case 0| onechar('l', 0, 8):
                switch(string[6]) {
                case 0| onechar('s', 0, 8):
                    return HtmlElement_details;
                }
            }
        }
        break;
    case 0| onechar('p', 0, 32)| onechar('i', 8, 32)| onechar('c', 16, 32)| onechar('t', 24, 32):
        switch(string[4]) {
        case 0| onechar('u', 0, 8):
            switch(string[5]) {
            case 0| onechar('r', 0, 8):
                switch(string[6]) {
                case 0| onechar('e', 0, 8):
                    return HtmlElement_picture;
                }
            }
        }
        break;
    case 0| onechar('s', 0, 32)| onechar('e', 8, 32)| onechar('c', 16, 32)| onechar('t', 24, 32):
        switch(string[4]) {
        case 0| onechar('i', 0, 8):
            switch(string[5]) {
            case 0| onechar('o', 0, 8):
                switch(string[6]) {
                case 0| onechar('n', 0, 8):
                    return HtmlElement_section;
                }
            }
        }
        break;
    case 0| onechar('s', 0, 32)| onechar('u', 8, 32)| onechar('m', 16, 32)| onechar('m', 24, 32):
        switch(string[4]) {
        case 0| onechar('a', 0, 8):
            switch(string[5]) {
            case 0| onechar('r', 0, 8):
                switch(string[6]) {
                case 0| onechar('y', 0, 8):
                    return HtmlElement_summary;
                }
            }
        }
    }
    return HtmlElement_Unknown;
}
static enum HtmlElement lookup_html_element8(const char *string)
{
    switch(*((triehash_uu64*) &string[0])) {
    case 0| onechar('c', 0, 64)| onechar('o', 8, 64)| onechar('l', 16, 64)| onechar('g', 24, 64)| onechar('r', 32, 64)| onechar('o', 40, 64)| onechar('u', 48, 64)| onechar('p', 56, 64):
        return HtmlElement_colgroup;
        break;
    case 0| onechar('d', 0, 64)| onechar('a', 8, 64)| onechar('t', 16, 64)| onechar('a', 24, 64)| onechar('l', 32, 64)| onechar('i', 40, 64)| onechar('s', 48, 64)| onechar('t', 56, 64):
        return HtmlElement_datalist;
        break;
    case 0| onechar('f', 0, 64)| onechar('i', 8, 64)| onechar('e', 16, 64)| onechar('l', 24, 64)| onechar('d', 32, 64)| onechar('s', 40, 64)| onechar('e', 48, 64)| onechar('t', 56, 64):
        return HtmlElement_fieldset;
        break;
    case 0| onechar('m', 0, 64)| onechar('e', 8, 64)| onechar('n', 16, 64)| onechar('u', 24, 64)| onechar('i', 32, 64)| onechar('t', 40, 64)| onechar('e', 48, 64)| onechar('m', 56, 64):
        return HtmlElement_menuitem;
        break;
    case 0| onechar('n', 0, 64)| onechar('o', 8, 64)| onechar('s', 16, 64)| onechar('c', 24, 64)| onechar('r', 32, 64)| onechar('i', 40, 64)| onechar('p', 48, 64)| onechar('t', 56, 64):
        return HtmlElement_noscript;
        break;
    case 0| onechar('o', 0, 64)| onechar('p', 8, 64)| onechar('t', 16, 64)| onechar('g', 24, 64)| onechar('r', 32, 64)| onechar('o', 40, 64)| onechar('u', 48, 64)| onechar('p', 56, 64):
        return HtmlElement_optgroup;
        break;
    case 0| onechar('p', 0, 64)| onechar('r', 8, 64)| onechar('o', 16, 64)| onechar('g', 24, 64)| onechar('r', 32, 64)| onechar('e', 40, 64)| onechar('s', 48, 64)| onechar('s', 56, 64):
        return HtmlElement_progress;
        break;
    case 0| onechar('t', 0, 64)| onechar('e', 8, 64)| onechar('m', 16, 64)| onechar('p', 24, 64)| onechar('l', 32, 64)| onechar('a', 40, 64)| onechar('t', 48, 64)| onechar('e', 56, 64):
        return HtmlElement_template;
        break;
    case 0| onechar('t', 0, 64)| onechar('e', 8, 64)| onechar('x', 16, 64)| onechar('t', 24, 64)| onechar('a', 32, 64)| onechar('r', 40, 64)| onechar('e', 48, 64)| onechar('a', 56, 64):
        return HtmlElement_textarea;
    }
    return HtmlElement_Unknown;
}
static enum HtmlElement lookup_html_element10(const char *string)
{
    switch(*((triehash_uu64*) &string[0])) {
    case 0| onechar('b', 0, 64)| onechar('l', 8, 64)| onechar('o', 16, 64)| onechar('c', 24, 64)| onechar('k', 32, 64)| onechar('q', 40, 64)| onechar('u', 48, 64)| onechar('o', 56, 64):
        switch(string[8]) {
        case 0| onechar('t', 0, 8):
            switch(string[9]) {
            case 0| onechar('e', 0, 8):
                return HtmlElement_blockquote;
            }
        }
        break;
    case 0| onechar('f', 0, 64)| onechar('i', 8, 64)| onechar('g', 16, 64)| onechar('c', 24, 64)| onechar('a', 32, 64)| onechar('p', 40, 64)| onechar('t', 48, 64)| onechar('i', 56, 64):
        switch(string[8]) {
        case 0| onechar('o', 0, 8):
            switch(string[9]) {
            case 0| onechar('n', 0, 8):
                return HtmlElement_figcaption;
            }
        }
    }
    return HtmlElement_Unknown;
}
#else
static enum HtmlElement lookup_html_element1(const char *string)
{
    switch(string[0]) {
    case 'a':
        return HtmlElement_a;
        break;
    case 'b':
        return HtmlElement_b;
        break;
    case 'i':
        return HtmlElement_i;
        break;
    case 'p':
        return HtmlElement_p;
        break;
    case 'q':
        return HtmlElement_q;
        break;
    case 's':
        return HtmlElement_s;
        break;
    case 'u':
        return HtmlElement_u;
    }
    return HtmlElement_Unknown;
}
static enum HtmlElement lookup_html_element2(const char *string)
{
    switch(string[0]) {
    case 'b':
        switch(string[1]) {
        case 'r':
            return HtmlElement_br;
        }
        break;
    case 'd':
        switch(string[1]) {
        case 'd':
            return HtmlElement_dd;
            break;
        case 'l':
            return HtmlElement_dl;
            break;
        case 't':
            return HtmlElement_dt;
        }
        break;
    case 'e':
        switch(string[1]) {
        case 'm':
            return HtmlElement_em;
        }
        break;
    case 'h':
        switch(string[1]) {
        case '1':
            return HtmlElement_h1;
            break;
        case '2':
            return HtmlElement_h2;
            break;
        case '3':
            return HtmlElement_h3;
            break;
        case '4':
            return HtmlElement_h4;
            break;
        case '5':
            return HtmlElement_h5;
            break;
        case '6':
            return HtmlElement_h6;
            break;
        case 'r':
            return HtmlElement_hr;
        }
        break;
    case 'l':
        switch(string[1]) {
        case 'i':
            return HtmlElement_li;
        }
        break;
    case 'o':
        switch(string[1]) {
        case 'l':
            return HtmlElement_ol;
        }
        break;
    case 'r':
        switch(string[1]) {
        case 'p':
            return HtmlElement_rp;
            break;
        case 't':
            return HtmlElement_rt;
        }
        break;
    case 't':
        switch(string[1]) {
        case 'd':
            return HtmlElement_td;
            break;
        case 'h':
            return HtmlElement_th;
            break;
        case 'r':
            return HtmlElement_tr;
        }
        break;
    case 'u':
        switch(string[1]) {
        case 'l':
            return HtmlElement_ul;
        }
    }
    return HtmlElement_Unknown;
}
static enum HtmlElement lookup_html_element3(const char *string)
{
    switch(string[0]) {
    case 'b':
        switch(string[1]) {
        case 'd':
            switch(string[2]) {
            case 'i':
                return HtmlElement_bdi;
                break;
            case 'o':
                return HtmlElement_bdo;
            }
        }
        break;
    case 'c':
        switch(string[1]) {
        case 'o':
            switch(string[2]) {
            case 'l':
                return HtmlElement_col;
            }
        }
        break;
    case 'd':
        switch(string[1]) {
        case 'e':
            switch(string[2]) {
            case 'l':
                return HtmlElement_del;
            }
            break;
        case 'f':
            switch(string[2]) {
            case 'n':
                return HtmlElement_dfn;
            }
            break;
        case 'i':
            switch(string[2]) {
            case 'v':
                return HtmlElement_div;
            }
        }
        break;
    case 'i':
        switch(string[1]) {
        case 'm':
            switch(string[2]) {
            case 'g':
                return HtmlElement_img;
            }
            break;
        case 'n':
            switch(string[2]) {
            case 's':
                return HtmlElement_ins;
            }
        }
        break;
    case 'k':
        switch(string[1]) {
        case 'b':
            switch(string[2]) {
            case 'd':
                return HtmlElement_kbd;
            }
        }
        break;
    case 'm':
        switch(string[1]) {
        case 'a':
            switch(string[2]) {
            case 'p':
                return HtmlElement_map;
            }
        }
        break;
    case 'n':
        switch(string[1]) {
        case 'a':
            switch(string[2]) {
            case 'v':
                return HtmlElement_nav;
            }
        }
        break;
    case 'p':
        switch(string[1]) {
        case 'r':
            switch(string[2]) {
            case 'e':
                return HtmlElement_pre;
            }
        }
        break;
    case 's':
        switch(string[1]) {
        case 'u':
            switch(string[2]) {
            case 'b':
                return HtmlElement_sub;
                break;
            case 'p':
                return HtmlElement_sup;
            }
            break;
        case 'v':
            switch(string[2]) {
            case 'g':
                return HtmlElement_svg;
            }
        }
        break;
    case 'v':
        switch(string[1]) {
        case 'a':
            switch(string[2]) {
            case 'r':
                return HtmlElement_var;
            }
        }
        break;
    case 'w':
        switch(string[1]) {
        case 'b':
            switch(string[2]) {
            case 'r':
                return HtmlElement_wbr;
            }
        }
    }
    return HtmlElement_Unknown;
}
static enum HtmlElement lookup_html_element4(const char *string)
{
    switch(string[0]) {
    case 'a':
        switch(string[1]) {
        case 'b':
            switch(string[2]) {
            case 'b':
                switch(string[3]) {
                case 'r':
                    return HtmlElement_abbr;
                }
            }
            break;
        case 'r':
            switch(string[2]) {
            case 'e':
                switch(string[3]) {
                case 'a':
                    return HtmlElement_area;
                }
            }
        }
        break;
    case 'b':
        switch(string[1]) {
        case 'a':
            switch(string[2]) {
            case 's':
                switch(string[3]) {
                case 'e':
                    return HtmlElement_base;
                }
            }
            break;
        case 'o':
            switch(string[2]) {
            case 'd':
                switch(string[3]) {
                case 'y':
                    return HtmlElement_body;
                }
            }
        }
        break;
    case 'c':
        switch(string[1]) {
        case 'i':
            switch(string[2]) {
            case 't':
                switch(string[3]) {
                case 'e':
                    return HtmlElement_cite;
                }
            }
            break;
        case 'o':
            switch(string[2]) {
            case 'd':
                switch(string[3]) {
                case 'e':
                    return HtmlElement_code;
                }
            }
        }
        break;
    case 'd':
        switch(string[1]) {
        case 'a':
            switch(string[2]) {
            case 't':
                switch(string[3]) {
                case 'a':
                    return HtmlElement_data;
                }
            }
        }
        break;
    case 'f':
        switch(string[1]) {
        case 'o':
            switch(string[2]) {
            case 'r':
                switch(string[3]) {
                case 'm':
                    return HtmlElement_form;
                }
            }
        }
        break;
    case 'h':
        switch(string[1]) {
        case 'e':
            switch(string[2]) {
            case 'a':
                switch(string[3]) {
                case 'd':
                    return HtmlElement_head;
                }
            }
            break;
        case 't':
            switch(string[2]) {
            case 'm':
                switch(string[3]) {
                case 'l':
                    return HtmlElement_html;
                }
            }
        }
        break;
    case 'l':
        switch(string[1]) {
        case 'i':
            switch(string[2]) {
            case 'n':
                switch(string[3]) {
                case 'k':
                    return HtmlElement_link;
                }
            }
        }
        break;
    case 'm':
        switch(string[1]) {
        case 'a':
            switch(string[2]) {
            case 'i':
                switch(string[3]) {
                case 'n':
                    return HtmlElement_main;
                }
                break;
            case 'r':
                switch(string[3]) {
                case 'k':
                    return HtmlElement_mark;
                }
                break;
            case 't':
                switch(string[3]) {
                case 'h':
                    return HtmlElement_math;
                }
            }
            break;
        case 'e':
            switch(string[2]) {
            case 'n':
                switch(string[3]) {
                case 'u':
                    return HtmlElement_menu;
                }
                break;
            case 't':
                switch(string[3]) {
                case 'a':
                    return HtmlElement_meta;
                }
            }
        }
        break;
    case 'r':
        switch(string[1]) {
        case 'u':
            switch(string[2]) {
            case 'b':
                switch(string[3]) {
                case 'y':
                    return HtmlElement_ruby;
                }
            }
        }
        break;
    case 's':
        switch(string[1]) {
        case 'a':
            switch(string[2]) {
            case 'm':
                switch(string[3]) {
                case 'p':
                    return HtmlElement_samp;
                }
            }
            break;
        case 'p':
            switch(string[2]) {
            case 'a':
                switch(string[3]) {
                case 'n':
                    return HtmlElement_span;
                }
            }
        }
        break;
    case 't':
        switch(string[1]) {
        case 'i':
            switch(string[2]) {
            case 'm':
                switch(string[3]) {
                case 'e':
                    return HtmlElement_time;
                }
            }
        }
    }
    return HtmlElement_Unknown;
}
static enum HtmlElement lookup_html_element5(const char *string)
{
    switch(string[0]) {
    case 'a':
        switch(string[1]) {
        case 's':
            switch(string[2]) {
            case 'i':
                switch(string[3]) {
                case 'd':
                    switch(string[4]) {
                    case 'e':
                        return HtmlElement_aside;
                    }
                }
            }
            break;
        case 'u':
            switch(string[2]) {
            case 'd':
                switch(string[3]) {
                case 'i':
                    switch(string[4]) {
                    case 'o':
                        return HtmlElement_audio;
                    }
                }
            }
        }
        break;
    case 'e':
        switch(string[1]) {
        case 'm':
            switch(string[2]) {
            case 'b':
                switch(string[3]) {
                case 'e':
                    switch(string[4]) {
                    case 'd':
                        return HtmlElement_embed;
                    }
                }
            }
        }
        break;
    case 'i':
        switch(string[1]) {
        case 'n':
            switch(string[2]) {
            case 'p':
                switch(string[3]) {
                case 'u':
                    switch(string[4]) {
                    case 't':
                        return HtmlElement_input;
                    }
                }
            }
        }
        break;
    case 'l':
        switch(string[1]) {
        case 'a':
            switch(string[2]) {
            case 'b':
                switch(string[3]) {
                case 'e':
                    switch(string[4]) {
                    case 'l':
                        return HtmlElement_label;
                    }
                }
            }
        }
        break;
    case 'm':
        switch(string[1]) {
        case 'e':
            switch(string[2]) {
            case 't':
                switch(string[3]) {
                case 'e':
                    switch(string[4]) {
                    case 'r':
                        return HtmlElement_meter;
                    }
                }
            }
        }
        break;
    case 'p':
        switch(string[1]) {
        case 'a':
            switch(string[2]) {
            case 'r':
                switch(string[3]) {
                case 'a':
                    switch(string[4]) {
                    case 'm':
                        return HtmlElement_param;
                    }
                }
            }
        }
        break;
    case 's':
        switch(string[1]) {
        case 'm':
            switch(string[2]) {
            case 'a':
                switch(string[3]) {
                case 'l':
                    switch(string[4]) {
                    case 'l':
                        return HtmlElement_small;
                    }
                }
            }
            break;
        case 't':
            switch(string[2]) {
            case 'y':
                switch(string[3]) {
                case 'l':
                    switch(string[4]) {
                    case 'e':
                        return HtmlElement_style;
                    }
                }
            }
        }
        break;
    case 't':
        switch(string[1]) {
        case 'a':
            switch(string[2]) {
            case 'b':
                switch(string[3]) {
                case 'l':
                    switch(string[4]) {
                    case 'e':
                        return HtmlElement_table;
                    }
                }
            }
            break;
        case 'b':
            switch(string[2]) {
            case 'o':
                switch(string[3]) {
                case 'd':
                    switch(string[4]) {
                    case 'y':
                        return HtmlElement_tbody;
                    }
                }
            }
            break;
        case 'f':
            switch(string[2]) {
            case 'o':
                switch(string[3]) {
                case 'o':
                    switch(string[4]) {
                    case 't':
                        return HtmlElement_tfoot;
                    }
                }
            }
            break;
        case 'h':
            switch(string[2]) {
            case 'e':
                switch(string[3]) {
                case 'a':
                    switch(string[4]) {
                    case 'd':
                        return HtmlElement_thead;
                    }
                }
            }
            break;
        case 'i':
            switch(string[2]) {
            case 't':
                switch(string[3]) {
                case 'l':
                    switch(string[4]) {
                    case 'e':
                        return HtmlElement_title;
                    }
                }
            }
            break;
        case 'r':
            switch(string[2]) {
            case 'a':
                switch(string[3]) {
                case 'c':
                    switch(string[4]) {
                    case 'k':
                        return HtmlElement_track;
                    }
                }
            }
        }
        break;
    case 'v':
        switch(string[1]) {
        case 'i':
            switch(string[2]) {
            case 'd':
                switch(string[3]) {
                case 'e':
                    switch(string[4]) {
                    case 'o':
                        return HtmlElement_video;
                    }
                }
            }
        }
    }
    return HtmlElement_Unknown;
}
static enum HtmlElement lookup_html_element6(const char *string)
{
    switch(string[0]) {
    case 'b':
        switch(string[1]) {
        case 'u':
            switch(string[2]) {
            case 't':
                switch(string[3]) {
                case 't':
                    switch(string[4]) {
                    case 'o':
                        switch(string[5]) {
                        case 'n':
                            return HtmlElement_button;
                        }
                    }
                }
            }
        }
        break;
    case 'c':
        switch(string[1]) {
        case 'a':
            switch(string[2]) {
            case 'n':
                switch(string[3]) {
                case 'v':
                    switch(string[4]) {
                    case 'a':
                        switch(string[5]) {
                        case 's':
                            return HtmlElement_canvas;
                        }
                    }
                }
            }
        }
        break;
    case 'd':
        switch(string[1]) {
        case 'i':
            switch(string[2]) {
            case 'a':
                switch(string[3]) {
                case 'l':
                    switch(string[4]) {
                    case 'o':
                        switch(string[5]) {
                        case 'g':
                            return HtmlElement_dialog;
                        }
                    }
                }
            }
        }
        break;
    case 'f':
        switch(string[1]) {
        case 'i':
            switch(string[2]) {
            case 'g':
                switch(string[3]) {
                case 'u':
                    switch(string[4]) {
                    case 'r':
                        switch(string[5]) {
                        case 'e':
                            return HtmlElement_figure;
                        }
                    }
                }
            }
            break;
        case 'o':
            switch(string[2]) {
            case 'o':
                switch(string[3]) {
                case 't':
                    switch(string[4]) {
                    case 'e':
                        switch(string[5]) {
                        case 'r':
                            return HtmlElement_footer;
                        }
                    }
                }
            }
        }
        break;
    case 'h':
        switch(string[1]) {
        case 'e':
            switch(string[2]) {
            case 'a':
                switch(string[3]) {
                case 'd':
                    switch(string[4]) {
                    case 'e':
                        switch(string[5]) {
                        case 'r':
                            return HtmlElement_header;
                        }
                    }
                }
            }
            break;
        case 'g':
            switch(string[2]) {
            case 'r':
                switch(string[3]) {
                case 'o':
                    switch(string[4]) {
                    case 'u':
                        switch(string[5]) {
                        case 'p':
                            return HtmlElement_hgroup;
                        }
                    }
                }
            }
        }
        break;
    case 'i':
        switch(string[1]) {
        case 'f':
            switch(string[2]) {
            case 'r':
                switch(string[3]) {
                case 'a':
                    switch(string[4]) {
                    case 'm':
                        switch(string[5]) {
                        case 'e':
                            return HtmlElement_iframe;
                        }
                    }
                }
            }
        }
        break;
    case 'k':
        switch(string[1]) {
        case 'e':
            switch(string[2]) {
            case 'y':
                switch(string[3]) {
                case 'g':
                    switch(string[4]) {
                    case 'e':
                        switch(string[5]) {
                        case 'n':
                            return HtmlElement_keygen;
                        }
                    }
                }
            }
        }
        break;
    case 'l':
        switch(string[1]) {
        case 'e':
            switch(string[2]) {
            case 'g':
                switch(string[3]) {
                case 'e':
                    switch(string[4]) {
                    case 'n':
                        switch(string[5]) {
                        case 'd':
                            return HtmlElement_legend;
                        }
                    }
                }
            }
        }
        break;
    case 'o':
        switch(string[1]) {
        case 'b':
            switch(string[2]) {
            case 'j':
                switch(string[3]) {
                case 'e':
                    switch(string[4]) {
                    case 'c':
                        switch(string[5]) {
                        case 't':
                            return HtmlElement_object;
                        }
                    }
                }
            }
            break;
        case 'p':
            switch(string[2]) {
            case 't':
                switch(string[3]) {
                case 'i':
                    switch(string[4]) {
                    case 'o':
                        switch(string[5]) {
                        case 'n':
                            return HtmlElement_option;
                        }
                    }
                }
            }
            break;
        case 'u':
            switch(string[2]) {
            case 't':
                switch(string[3]) {
                case 'p':
                    switch(string[4]) {
                    case 'u':
                        switch(string[5]) {
                        case 't':
                            return HtmlElement_output;
                        }
                    }
                }
            }
        }
        break;
    case 's':
        switch(string[1]) {
        case 'c':
            switch(string[2]) {
            case 'r':
                switch(string[3]) {
                case 'i':
                    switch(string[4]) {
                    case 'p':
                        switch(string[5]) {
                        case 't':
                            return HtmlElement_script;
                        }
                    }
                }
            }
            break;
        case 'e':
            switch(string[2]) {
            case 'l':
                switch(string[3]) {
                case 'e':
                    switch(string[4]) {
                    case 'c':
                        switch(string[5]) {
                        case 't':
                            return HtmlElement_select;
                        }
                    }
                }
            }
            break;
        case 'o':
            switch(string[2]) {
            case 'u':
                switch(string[3]) {
                case 'r':
                    switch(string[4]) {
                    case 'c':
                        switch(string[5]) {
                        case 'e':
                            return HtmlElement_source;
                        }
                    }
                }
            }
            break;
        case 't':
            switch(string[2]) {
            case 'r':
                switch(string[3]) {
                case 'o':
                    switch(string[4]) {
                    case 'n':
                        switch(string[5]) {
                        case 'g':
                            return HtmlElement_strong;
                        }
                    }
                }
            }
        }
    }
    return HtmlElement_Unknown;
}
static enum HtmlElement lookup_html_element7(const char *string)
{
    switch(string[0]) {
    case 'a':
        switch(string[1]) {
        case 'd':
            switch(string[2]) {
            case 'd':
                switch(string[3]) {
                case 'r':
                    switch(string[4]) {
                    case 'e':
                        switch(string[5]) {
                        case 's':
                            switch(string[6]) {
                            case 's':
                                return HtmlElement_address;
                            }
                        }
                    }
                }
            }
            break;
        case 'r':
            switch(string[2]) {
            case 't':
                switch(string[3]) {
                case 'i':
                    switch(string[4]) {
                    case 'c':
                        switch(string[5]) {
                        case 'l':
                            switch(string[6]) {
                            case 'e':
                                return HtmlElement_article;
                            }
                        }
                    }
                }
            }
        }
        break;
    case 'c':
        switch(string[1]) {
        case 'a':
            switch(string[2]) {
            case 'p':
                switch(string[3]) {
                case 't':
                    switch(string[4]) {
                    case 'i':
                        switch(string[5]) {
                        case 'o':
                            switch(string[6]) {
                            case 'n':
                                return HtmlElement_caption;
                            }
                        }
                    }
                }
            }
        }
        break;
    case 'd':
        switch(string[1]) {
        case 'e':
            switch(string[2]) {
            case 't':
                switch(string[3]) {
                case 'a':
                    switch(string[4]) {
                    case 'i':
                        switch(string[5]) {
                        case 'l':
                            switch(string[6]) {
                            case 's':
                                return HtmlElement_details;
                            }
                        }
                    }
                }
            }
        }
        break;
    case 'p':
        switch(string[1]) {
        case 'i':
            switch(string[2]) {
            case 'c':
                switch(string[3]) {
                case 't':
                    switch(string[4]) {
                    case 'u':
                        switch(string[5]) {
                        case 'r':
                            switch(string[6]) {
                            case 'e':
                                return HtmlElement_picture;
                            }
                        }
                    }
                }
            }
        }
        break;
    case 's':
        switch(string[1]) {
        case 'e':
            switch(string[2]) {
            case 'c':
                switch(string[3]) {
                case 't':
                    switch(string[4]) {
                    case 'i':
                        switch(string[5]) {
                        case 'o':
                            switch(string[6]) {
                            case 'n':
                                return HtmlElement_section;
                            }
                        }
                    }
                }
            }
            break;
        case 'u':
            switch(string[2]) {
            case 'm':
                switch(string[3]) {
                case 'm':
                    switch(string[4]) {
                    case 'a':
                        switch(string[5]) {
                        case 'r':
                            switch(string[6]) {
                            case 'y':
                                return HtmlElement_summary;
                            }
                        }
                    }
                }
            }
        }
    }
    return HtmlElement_Unknown;
}
static enum HtmlElement lookup_html_element8(const char *string)
{
    switch(string[0]) {
    case 'c':
        switch(string[1]) {
        case 'o':
            switch(string[2]) {
            case 'l':
                switch(string[3]) {
                case 'g':
                    switch(string[4]) {
                    case 'r':
                        switch(string[5]) {
                        case 'o':
                            switch(string[6]) {
                            case 'u':
                                switch(string[7]) {
                                case 'p':
                                    return HtmlElement_colgroup;
                                }
                            }
                        }
                    }
                }
            }
        }
        break;
    case 'd':
        switch(string[1]) {
        case 'a':
            switch(string[2]) {
            case 't':
                switch(string[3]) {
                case 'a':
                    switch(string[4]) {
                    case 'l':
                        switch(string[5]) {
                        case 'i':
                            switch(string[6]) {
                            case 's':
                                switch(string[7]) {
                                case 't':
                                    return HtmlElement_datalist;
                                }
                            }
                        }
                    }
                }
            }
        }
        break;
    case 'f':
        switch(string[1]) {
        case 'i':
            switch(string[2]) {
            case 'e':
                switch(string[3]) {
                case 'l':
                    switch(string[4]) {
                    case 'd':
                        switch(string[5]) {
                        case 's':
                            switch(string[6]) {
                            case 'e':
                                switch(string[7]) {
                                case 't':
                                    return HtmlElement_fieldset;
                                }
                            }
                        }
                    }
                }
            }
        }
        break;
    case 'm':
        switch(string[1]) {
        case 'e':
            switch(string[2]) {
            case 'n':
                switch(string[3]) {
                case 'u':
                    switch(string[4]) {
                    case 'i':
                        switch(string[5]) {
                        case 't':
                            switch(string[6]) {
                            case 'e':
                                switch(string[7]) {
                                case 'm':
                                    return HtmlElement_menuitem;
                                }
                            }
                        }
                    }
                }
            }
        }
        break;
    case 'n':
        switch(string[1]) {
        case 'o':
            switch(string[2]) {
            case 's':
                switch(string[3]) {
                case 'c':
                    switch(string[4]) {
                    case 'r':
                        switch(string[5]) {
                        case 'i':
                            switch(string[6]) {
                            case 'p':
                                switch(string[7]) {
                                case 't':
                                    return HtmlElement_noscript;
                                }
                            }
                        }
                    }
                }
            }
        }
        break;
    case 'o':
        switch(string[1]) {
        case 'p':
            switch(string[2]) {
            case 't':
                switch(string[3]) {
                case 'g':
                    switch(string[4]) {
                    case 'r':
                        switch(string[5]) {
                        case 'o':
                            switch(string[6]) {
                            case 'u':
                                switch(string[7]) {
                                case 'p':
                                    return HtmlElement_optgroup;
                                }
                            }
                        }
                    }
                }
            }
        }
        break;
    case 'p':
        switch(string[1]) {
        case 'r':
            switch(string[2]) {
            case 'o':
                switch(string[3]) {
                case 'g':
                    switch(string[4]) {
                    case 'r':
                        switch(string[5]) {
                        case 'e':
                            switch(string[6]) {
                            case 's':
                                switch(string[7]) {
                                case 's':
                                    return HtmlElement_progress;
                                }
                            }
                        }
                    }
                }
            }
        }
        break;
    case 't':
        switch(string[1]) {
        case 'e':
            switch(string[2]) {
            case 'm':
                switch(string[3]) {
                case 'p':
                    switch(string[4]) {
                    case 'l':
                        switch(string[5]) {
                        case 'a':
                            switch(string[6]) {
                            case 't':
                                switch(string[7]) {
                                case 'e':
                                    return HtmlElement_template;
                                }
                            }
                        }
                    }
                }
                break;
            case 'x':
                switch(string[3]) {
                case 't':
                    switch(string[4]) {
                    case 'a':
                        switch(string[5]) {
                        case 'r':
                            switch(string[6]) {
                            case 'e':
                                switch(string[7]) {
                                case 'a':
                                    return HtmlElement_textarea;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return HtmlElement_Unknown;
}
static enum HtmlElement lookup_html_element10(const char *string)
{
    switch(string[0]) {
    case 'b':
        switch(string[1]) {
        case 'l':
            switch(string[2]) {
            case 'o':
                switch(string[3]) {
                case 'c':
                    switch(string[4]) {
                    case 'k':
                        switch(string[5]) {
                        case 'q':
                            switch(string[6]) {
                            case 'u':
                                switch(string[7]) {
                                case 'o':
                                    switch(string[8]) {
                                    case 't':
                                        switch(string[9]) {
                                        case 'e':
                                            return HtmlElement_blockquote;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        break;
    case 'f':
        switch(string[1]) {
        case 'i':
            switch(string[2]) {
            case 'g':
                switch(string[3]) {
                case 'c':
                    switch(string[4]) {
                    case 'a':
                        switch(string[5]) {
                        case 'p':
                            switch(string[6]) {
                            case 't':
                                switch(string[7]) {
                                case 'i':
                                    switch(string[8]) {
                                    case 'o':
                                        switch(string[9]) {
                                        case 'n':
                                            return HtmlElement_figcaption;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return HtmlElement_Unknown;
}
#endif /* TRIE_HASH_MULTI_BYTE */
static enum HtmlElement lookup_html_element(const char *string, size_t length)
{
    switch (length) {
    case 1:
        return lookup_html_element1(string);
    case 2:
        return lookup_html_element2(string);
    case 3:
        return lookup_html_element3(string);
    case 4:
        return lookup_html_element4(string);
    case 5:
        return lookup_html_element5(string);
    case 6:
        return lookup_html_element6(string);
    case 7:
        return lookup_html_element7(string);
    case 8:
        return lookup_html_element8(string);
    case 10:
        return lookup_html_element10(string);
    default:
        return HtmlElement_Unknown;
    }
}
#endif                       /* TRIE_HASH_lookup_html_element */
