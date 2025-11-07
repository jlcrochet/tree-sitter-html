#ifndef TRIE_HASH_lookup_html_element
#define TRIE_HASH_lookup_html_element
#include <stddef.h>
#include <stdint.h>
enum HtmlElement {
    HE_a = 1,
    HE_abbr = 2,
    HE_address = 3,
    HE_area = 4,
    HE_article = 5,
    HE_aside = 6,
    HE_audio = 7,
    HE_b = 8,
    HE_bdi = 10,
    HE_bdo = 11,
    HE_br = 14,
    HE_base = 9,
    HE_blockquote = 12,
    HE_body = 13,
    HE_button = 15,
    HE_col = 20,
    HE_canvas = 16,
    HE_caption = 17,
    HE_cite = 18,
    HE_code = 19,
    HE_colgroup = 21,
    HE_dd = 24,
    HE_del = 25,
    HE_dfn = 27,
    HE_div = 29,
    HE_dl = 30,
    HE_dt = 31,
    HE_data = 22,
    HE_datalist = 23,
    HE_details = 26,
    HE_dialog = 28,
    HE_em = 32,
    HE_embed = 33,
    HE_fieldset = 34,
    HE_figcaption = 35,
    HE_figure = 36,
    HE_footer = 37,
    HE_form = 38,
    HE_h1 = 42,
    HE_h2 = 43,
    HE_h3 = 44,
    HE_h4 = 45,
    HE_h5 = 46,
    HE_h6 = 47,
    HE_hr = 48,
    HE_head = 39,
    HE_header = 40,
    HE_hgroup = 41,
    HE_html = 49,
    HE_i = 50,
    HE_img = 52,
    HE_ins = 54,
    HE_iframe = 51,
    HE_input = 53,
    HE_kbd = 55,
    HE_keygen = 56,
    HE_li = 59,
    HE_label = 57,
    HE_legend = 58,
    HE_link = 60,
    HE_map = 62,
    HE_main = 61,
    HE_mark = 63,
    HE_math = 64,
    HE_menu = 65,
    HE_menuitem = 66,
    HE_meta = 67,
    HE_meter = 68,
    HE_nav = 69,
    HE_noscript = 70,
    HE_ol = 72,
    HE_object = 71,
    HE_optgroup = 73,
    HE_option = 74,
    HE_output = 75,
    HE_p = 76,
    HE_pre = 79,
    HE_param = 77,
    HE_picture = 78,
    HE_progress = 80,
    HE_q = 81,
    HE_rp = 82,
    HE_rt = 83,
    HE_ruby = 84,
    HE_s = 85,
    HE_sub = 95,
    HE_sup = 97,
    HE_svg = 98,
    HE_samp = 86,
    HE_script = 87,
    HE_section = 88,
    HE_select = 89,
    HE_small = 90,
    HE_source = 91,
    HE_span = 92,
    HE_strong = 93,
    HE_style = 94,
    HE_summary = 96,
    HE_td = 101,
    HE_th = 105,
    HE_tr = 109,
    HE_table = 99,
    HE_tbody = 100,
    HE_template = 102,
    HE_textarea = 103,
    HE_tfoot = 104,
    HE_thead = 106,
    HE_time = 107,
    HE_title = 108,
    HE_track = 110,
    HE_u = 111,
    HE_ul = 112,
    HE_var = 113,
    HE_video = 114,
    HE_wbr = 115,
    HE_Unknown = 0,
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
        return HE_a;
        break;
    case 0| onechar('b', 0, 8):
        return HE_b;
        break;
    case 0| onechar('i', 0, 8):
        return HE_i;
        break;
    case 0| onechar('p', 0, 8):
        return HE_p;
        break;
    case 0| onechar('q', 0, 8):
        return HE_q;
        break;
    case 0| onechar('s', 0, 8):
        return HE_s;
        break;
    case 0| onechar('u', 0, 8):
        return HE_u;
    }
    return HE_Unknown;
}
static enum HtmlElement lookup_html_element2(const char *string)
{
    switch(string[0]) {
    case 0| onechar('b', 0, 8):
        switch(string[1]) {
        case 0| onechar('r', 0, 8):
            return HE_br;
        }
        break;
    case 0| onechar('d', 0, 8):
        switch(string[1]) {
        case 0| onechar('d', 0, 8):
            return HE_dd;
            break;
        case 0| onechar('l', 0, 8):
            return HE_dl;
            break;
        case 0| onechar('t', 0, 8):
            return HE_dt;
        }
        break;
    case 0| onechar('e', 0, 8):
        switch(string[1]) {
        case 0| onechar('m', 0, 8):
            return HE_em;
        }
        break;
    case 0| onechar('h', 0, 8):
        switch(string[1]) {
        case 0| onechar('1', 0, 8):
            return HE_h1;
            break;
        case 0| onechar('2', 0, 8):
            return HE_h2;
            break;
        case 0| onechar('3', 0, 8):
            return HE_h3;
            break;
        case 0| onechar('4', 0, 8):
            return HE_h4;
            break;
        case 0| onechar('5', 0, 8):
            return HE_h5;
            break;
        case 0| onechar('6', 0, 8):
            return HE_h6;
            break;
        case 0| onechar('r', 0, 8):
            return HE_hr;
        }
        break;
    case 0| onechar('l', 0, 8):
        switch(string[1]) {
        case 0| onechar('i', 0, 8):
            return HE_li;
        }
        break;
    case 0| onechar('o', 0, 8):
        switch(string[1]) {
        case 0| onechar('l', 0, 8):
            return HE_ol;
        }
        break;
    case 0| onechar('r', 0, 8):
        switch(string[1]) {
        case 0| onechar('p', 0, 8):
            return HE_rp;
            break;
        case 0| onechar('t', 0, 8):
            return HE_rt;
        }
        break;
    case 0| onechar('t', 0, 8):
        switch(string[1]) {
        case 0| onechar('d', 0, 8):
            return HE_td;
            break;
        case 0| onechar('h', 0, 8):
            return HE_th;
            break;
        case 0| onechar('r', 0, 8):
            return HE_tr;
        }
        break;
    case 0| onechar('u', 0, 8):
        switch(string[1]) {
        case 0| onechar('l', 0, 8):
            return HE_ul;
        }
    }
    return HE_Unknown;
}
static enum HtmlElement lookup_html_element3(const char *string)
{
    switch(string[0]) {
    case 0| onechar('b', 0, 8):
        switch(string[1]) {
        case 0| onechar('d', 0, 8):
            switch(string[2]) {
            case 0| onechar('i', 0, 8):
                return HE_bdi;
                break;
            case 0| onechar('o', 0, 8):
                return HE_bdo;
            }
        }
        break;
    case 0| onechar('c', 0, 8):
        switch(string[1]) {
        case 0| onechar('o', 0, 8):
            switch(string[2]) {
            case 0| onechar('l', 0, 8):
                return HE_col;
            }
        }
        break;
    case 0| onechar('d', 0, 8):
        switch(string[1]) {
        case 0| onechar('e', 0, 8):
            switch(string[2]) {
            case 0| onechar('l', 0, 8):
                return HE_del;
            }
            break;
        case 0| onechar('f', 0, 8):
            switch(string[2]) {
            case 0| onechar('n', 0, 8):
                return HE_dfn;
            }
            break;
        case 0| onechar('i', 0, 8):
            switch(string[2]) {
            case 0| onechar('v', 0, 8):
                return HE_div;
            }
        }
        break;
    case 0| onechar('i', 0, 8):
        switch(string[1]) {
        case 0| onechar('m', 0, 8):
            switch(string[2]) {
            case 0| onechar('g', 0, 8):
                return HE_img;
            }
            break;
        case 0| onechar('n', 0, 8):
            switch(string[2]) {
            case 0| onechar('s', 0, 8):
                return HE_ins;
            }
        }
        break;
    case 0| onechar('k', 0, 8):
        switch(string[1]) {
        case 0| onechar('b', 0, 8):
            switch(string[2]) {
            case 0| onechar('d', 0, 8):
                return HE_kbd;
            }
        }
        break;
    case 0| onechar('m', 0, 8):
        switch(string[1]) {
        case 0| onechar('a', 0, 8):
            switch(string[2]) {
            case 0| onechar('p', 0, 8):
                return HE_map;
            }
        }
        break;
    case 0| onechar('n', 0, 8):
        switch(string[1]) {
        case 0| onechar('a', 0, 8):
            switch(string[2]) {
            case 0| onechar('v', 0, 8):
                return HE_nav;
            }
        }
        break;
    case 0| onechar('p', 0, 8):
        switch(string[1]) {
        case 0| onechar('r', 0, 8):
            switch(string[2]) {
            case 0| onechar('e', 0, 8):
                return HE_pre;
            }
        }
        break;
    case 0| onechar('s', 0, 8):
        switch(string[1]) {
        case 0| onechar('u', 0, 8):
            switch(string[2]) {
            case 0| onechar('b', 0, 8):
                return HE_sub;
                break;
            case 0| onechar('p', 0, 8):
                return HE_sup;
            }
            break;
        case 0| onechar('v', 0, 8):
            switch(string[2]) {
            case 0| onechar('g', 0, 8):
                return HE_svg;
            }
        }
        break;
    case 0| onechar('v', 0, 8):
        switch(string[1]) {
        case 0| onechar('a', 0, 8):
            switch(string[2]) {
            case 0| onechar('r', 0, 8):
                return HE_var;
            }
        }
        break;
    case 0| onechar('w', 0, 8):
        switch(string[1]) {
        case 0| onechar('b', 0, 8):
            switch(string[2]) {
            case 0| onechar('r', 0, 8):
                return HE_wbr;
            }
        }
    }
    return HE_Unknown;
}
static enum HtmlElement lookup_html_element4(const char *string)
{
    switch(*((triehash_uu32*) &string[0])) {
    case 0| onechar('a', 0, 32)| onechar('b', 8, 32)| onechar('b', 16, 32)| onechar('r', 24, 32):
        return HE_abbr;
        break;
    case 0| onechar('a', 0, 32)| onechar('r', 8, 32)| onechar('e', 16, 32)| onechar('a', 24, 32):
        return HE_area;
        break;
    case 0| onechar('b', 0, 32)| onechar('a', 8, 32)| onechar('s', 16, 32)| onechar('e', 24, 32):
        return HE_base;
        break;
    case 0| onechar('b', 0, 32)| onechar('o', 8, 32)| onechar('d', 16, 32)| onechar('y', 24, 32):
        return HE_body;
        break;
    case 0| onechar('c', 0, 32)| onechar('i', 8, 32)| onechar('t', 16, 32)| onechar('e', 24, 32):
        return HE_cite;
        break;
    case 0| onechar('c', 0, 32)| onechar('o', 8, 32)| onechar('d', 16, 32)| onechar('e', 24, 32):
        return HE_code;
        break;
    case 0| onechar('d', 0, 32)| onechar('a', 8, 32)| onechar('t', 16, 32)| onechar('a', 24, 32):
        return HE_data;
        break;
    case 0| onechar('f', 0, 32)| onechar('o', 8, 32)| onechar('r', 16, 32)| onechar('m', 24, 32):
        return HE_form;
        break;
    case 0| onechar('h', 0, 32)| onechar('e', 8, 32)| onechar('a', 16, 32)| onechar('d', 24, 32):
        return HE_head;
        break;
    case 0| onechar('h', 0, 32)| onechar('t', 8, 32)| onechar('m', 16, 32)| onechar('l', 24, 32):
        return HE_html;
        break;
    case 0| onechar('l', 0, 32)| onechar('i', 8, 32)| onechar('n', 16, 32)| onechar('k', 24, 32):
        return HE_link;
        break;
    case 0| onechar('m', 0, 32)| onechar('a', 8, 32)| onechar('i', 16, 32)| onechar('n', 24, 32):
        return HE_main;
        break;
    case 0| onechar('m', 0, 32)| onechar('a', 8, 32)| onechar('r', 16, 32)| onechar('k', 24, 32):
        return HE_mark;
        break;
    case 0| onechar('m', 0, 32)| onechar('a', 8, 32)| onechar('t', 16, 32)| onechar('h', 24, 32):
        return HE_math;
        break;
    case 0| onechar('m', 0, 32)| onechar('e', 8, 32)| onechar('n', 16, 32)| onechar('u', 24, 32):
        return HE_menu;
        break;
    case 0| onechar('m', 0, 32)| onechar('e', 8, 32)| onechar('t', 16, 32)| onechar('a', 24, 32):
        return HE_meta;
        break;
    case 0| onechar('r', 0, 32)| onechar('u', 8, 32)| onechar('b', 16, 32)| onechar('y', 24, 32):
        return HE_ruby;
        break;
    case 0| onechar('s', 0, 32)| onechar('a', 8, 32)| onechar('m', 16, 32)| onechar('p', 24, 32):
        return HE_samp;
        break;
    case 0| onechar('s', 0, 32)| onechar('p', 8, 32)| onechar('a', 16, 32)| onechar('n', 24, 32):
        return HE_span;
        break;
    case 0| onechar('t', 0, 32)| onechar('i', 8, 32)| onechar('m', 16, 32)| onechar('e', 24, 32):
        return HE_time;
    }
    return HE_Unknown;
}
static enum HtmlElement lookup_html_element5(const char *string)
{
    switch(*((triehash_uu32*) &string[0])) {
    case 0| onechar('a', 0, 32)| onechar('s', 8, 32)| onechar('i', 16, 32)| onechar('d', 24, 32):
        switch(string[4]) {
        case 0| onechar('e', 0, 8):
            return HE_aside;
        }
        break;
    case 0| onechar('a', 0, 32)| onechar('u', 8, 32)| onechar('d', 16, 32)| onechar('i', 24, 32):
        switch(string[4]) {
        case 0| onechar('o', 0, 8):
            return HE_audio;
        }
        break;
    case 0| onechar('e', 0, 32)| onechar('m', 8, 32)| onechar('b', 16, 32)| onechar('e', 24, 32):
        switch(string[4]) {
        case 0| onechar('d', 0, 8):
            return HE_embed;
        }
        break;
    case 0| onechar('i', 0, 32)| onechar('n', 8, 32)| onechar('p', 16, 32)| onechar('u', 24, 32):
        switch(string[4]) {
        case 0| onechar('t', 0, 8):
            return HE_input;
        }
        break;
    case 0| onechar('l', 0, 32)| onechar('a', 8, 32)| onechar('b', 16, 32)| onechar('e', 24, 32):
        switch(string[4]) {
        case 0| onechar('l', 0, 8):
            return HE_label;
        }
        break;
    case 0| onechar('m', 0, 32)| onechar('e', 8, 32)| onechar('t', 16, 32)| onechar('e', 24, 32):
        switch(string[4]) {
        case 0| onechar('r', 0, 8):
            return HE_meter;
        }
        break;
    case 0| onechar('p', 0, 32)| onechar('a', 8, 32)| onechar('r', 16, 32)| onechar('a', 24, 32):
        switch(string[4]) {
        case 0| onechar('m', 0, 8):
            return HE_param;
        }
        break;
    case 0| onechar('s', 0, 32)| onechar('m', 8, 32)| onechar('a', 16, 32)| onechar('l', 24, 32):
        switch(string[4]) {
        case 0| onechar('l', 0, 8):
            return HE_small;
        }
        break;
    case 0| onechar('s', 0, 32)| onechar('t', 8, 32)| onechar('y', 16, 32)| onechar('l', 24, 32):
        switch(string[4]) {
        case 0| onechar('e', 0, 8):
            return HE_style;
        }
        break;
    case 0| onechar('t', 0, 32)| onechar('a', 8, 32)| onechar('b', 16, 32)| onechar('l', 24, 32):
        switch(string[4]) {
        case 0| onechar('e', 0, 8):
            return HE_table;
        }
        break;
    case 0| onechar('t', 0, 32)| onechar('b', 8, 32)| onechar('o', 16, 32)| onechar('d', 24, 32):
        switch(string[4]) {
        case 0| onechar('y', 0, 8):
            return HE_tbody;
        }
        break;
    case 0| onechar('t', 0, 32)| onechar('f', 8, 32)| onechar('o', 16, 32)| onechar('o', 24, 32):
        switch(string[4]) {
        case 0| onechar('t', 0, 8):
            return HE_tfoot;
        }
        break;
    case 0| onechar('t', 0, 32)| onechar('h', 8, 32)| onechar('e', 16, 32)| onechar('a', 24, 32):
        switch(string[4]) {
        case 0| onechar('d', 0, 8):
            return HE_thead;
        }
        break;
    case 0| onechar('t', 0, 32)| onechar('i', 8, 32)| onechar('t', 16, 32)| onechar('l', 24, 32):
        switch(string[4]) {
        case 0| onechar('e', 0, 8):
            return HE_title;
        }
        break;
    case 0| onechar('t', 0, 32)| onechar('r', 8, 32)| onechar('a', 16, 32)| onechar('c', 24, 32):
        switch(string[4]) {
        case 0| onechar('k', 0, 8):
            return HE_track;
        }
        break;
    case 0| onechar('v', 0, 32)| onechar('i', 8, 32)| onechar('d', 16, 32)| onechar('e', 24, 32):
        switch(string[4]) {
        case 0| onechar('o', 0, 8):
            return HE_video;
        }
    }
    return HE_Unknown;
}
static enum HtmlElement lookup_html_element6(const char *string)
{
    switch(*((triehash_uu32*) &string[0])) {
    case 0| onechar('b', 0, 32)| onechar('u', 8, 32)| onechar('t', 16, 32)| onechar('t', 24, 32):
        switch(string[4]) {
        case 0| onechar('o', 0, 8):
            switch(string[5]) {
            case 0| onechar('n', 0, 8):
                return HE_button;
            }
        }
        break;
    case 0| onechar('c', 0, 32)| onechar('a', 8, 32)| onechar('n', 16, 32)| onechar('v', 24, 32):
        switch(string[4]) {
        case 0| onechar('a', 0, 8):
            switch(string[5]) {
            case 0| onechar('s', 0, 8):
                return HE_canvas;
            }
        }
        break;
    case 0| onechar('d', 0, 32)| onechar('i', 8, 32)| onechar('a', 16, 32)| onechar('l', 24, 32):
        switch(string[4]) {
        case 0| onechar('o', 0, 8):
            switch(string[5]) {
            case 0| onechar('g', 0, 8):
                return HE_dialog;
            }
        }
        break;
    case 0| onechar('f', 0, 32)| onechar('i', 8, 32)| onechar('g', 16, 32)| onechar('u', 24, 32):
        switch(string[4]) {
        case 0| onechar('r', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return HE_figure;
            }
        }
        break;
    case 0| onechar('f', 0, 32)| onechar('o', 8, 32)| onechar('o', 16, 32)| onechar('t', 24, 32):
        switch(string[4]) {
        case 0| onechar('e', 0, 8):
            switch(string[5]) {
            case 0| onechar('r', 0, 8):
                return HE_footer;
            }
        }
        break;
    case 0| onechar('h', 0, 32)| onechar('e', 8, 32)| onechar('a', 16, 32)| onechar('d', 24, 32):
        switch(string[4]) {
        case 0| onechar('e', 0, 8):
            switch(string[5]) {
            case 0| onechar('r', 0, 8):
                return HE_header;
            }
        }
        break;
    case 0| onechar('h', 0, 32)| onechar('g', 8, 32)| onechar('r', 16, 32)| onechar('o', 24, 32):
        switch(string[4]) {
        case 0| onechar('u', 0, 8):
            switch(string[5]) {
            case 0| onechar('p', 0, 8):
                return HE_hgroup;
            }
        }
        break;
    case 0| onechar('i', 0, 32)| onechar('f', 8, 32)| onechar('r', 16, 32)| onechar('a', 24, 32):
        switch(string[4]) {
        case 0| onechar('m', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return HE_iframe;
            }
        }
        break;
    case 0| onechar('k', 0, 32)| onechar('e', 8, 32)| onechar('y', 16, 32)| onechar('g', 24, 32):
        switch(string[4]) {
        case 0| onechar('e', 0, 8):
            switch(string[5]) {
            case 0| onechar('n', 0, 8):
                return HE_keygen;
            }
        }
        break;
    case 0| onechar('l', 0, 32)| onechar('e', 8, 32)| onechar('g', 16, 32)| onechar('e', 24, 32):
        switch(string[4]) {
        case 0| onechar('n', 0, 8):
            switch(string[5]) {
            case 0| onechar('d', 0, 8):
                return HE_legend;
            }
        }
        break;
    case 0| onechar('o', 0, 32)| onechar('b', 8, 32)| onechar('j', 16, 32)| onechar('e', 24, 32):
        switch(string[4]) {
        case 0| onechar('c', 0, 8):
            switch(string[5]) {
            case 0| onechar('t', 0, 8):
                return HE_object;
            }
        }
        break;
    case 0| onechar('o', 0, 32)| onechar('p', 8, 32)| onechar('t', 16, 32)| onechar('i', 24, 32):
        switch(string[4]) {
        case 0| onechar('o', 0, 8):
            switch(string[5]) {
            case 0| onechar('n', 0, 8):
                return HE_option;
            }
        }
        break;
    case 0| onechar('o', 0, 32)| onechar('u', 8, 32)| onechar('t', 16, 32)| onechar('p', 24, 32):
        switch(string[4]) {
        case 0| onechar('u', 0, 8):
            switch(string[5]) {
            case 0| onechar('t', 0, 8):
                return HE_output;
            }
        }
        break;
    case 0| onechar('s', 0, 32)| onechar('c', 8, 32)| onechar('r', 16, 32)| onechar('i', 24, 32):
        switch(string[4]) {
        case 0| onechar('p', 0, 8):
            switch(string[5]) {
            case 0| onechar('t', 0, 8):
                return HE_script;
            }
        }
        break;
    case 0| onechar('s', 0, 32)| onechar('e', 8, 32)| onechar('l', 16, 32)| onechar('e', 24, 32):
        switch(string[4]) {
        case 0| onechar('c', 0, 8):
            switch(string[5]) {
            case 0| onechar('t', 0, 8):
                return HE_select;
            }
        }
        break;
    case 0| onechar('s', 0, 32)| onechar('o', 8, 32)| onechar('u', 16, 32)| onechar('r', 24, 32):
        switch(string[4]) {
        case 0| onechar('c', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return HE_source;
            }
        }
        break;
    case 0| onechar('s', 0, 32)| onechar('t', 8, 32)| onechar('r', 16, 32)| onechar('o', 24, 32):
        switch(string[4]) {
        case 0| onechar('n', 0, 8):
            switch(string[5]) {
            case 0| onechar('g', 0, 8):
                return HE_strong;
            }
        }
    }
    return HE_Unknown;
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
                    return HE_address;
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
                    return HE_article;
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
                    return HE_caption;
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
                    return HE_details;
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
                    return HE_picture;
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
                    return HE_section;
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
                    return HE_summary;
                }
            }
        }
    }
    return HE_Unknown;
}
static enum HtmlElement lookup_html_element8(const char *string)
{
    switch(*((triehash_uu64*) &string[0])) {
    case 0| onechar('c', 0, 64)| onechar('o', 8, 64)| onechar('l', 16, 64)| onechar('g', 24, 64)| onechar('r', 32, 64)| onechar('o', 40, 64)| onechar('u', 48, 64)| onechar('p', 56, 64):
        return HE_colgroup;
        break;
    case 0| onechar('d', 0, 64)| onechar('a', 8, 64)| onechar('t', 16, 64)| onechar('a', 24, 64)| onechar('l', 32, 64)| onechar('i', 40, 64)| onechar('s', 48, 64)| onechar('t', 56, 64):
        return HE_datalist;
        break;
    case 0| onechar('f', 0, 64)| onechar('i', 8, 64)| onechar('e', 16, 64)| onechar('l', 24, 64)| onechar('d', 32, 64)| onechar('s', 40, 64)| onechar('e', 48, 64)| onechar('t', 56, 64):
        return HE_fieldset;
        break;
    case 0| onechar('m', 0, 64)| onechar('e', 8, 64)| onechar('n', 16, 64)| onechar('u', 24, 64)| onechar('i', 32, 64)| onechar('t', 40, 64)| onechar('e', 48, 64)| onechar('m', 56, 64):
        return HE_menuitem;
        break;
    case 0| onechar('n', 0, 64)| onechar('o', 8, 64)| onechar('s', 16, 64)| onechar('c', 24, 64)| onechar('r', 32, 64)| onechar('i', 40, 64)| onechar('p', 48, 64)| onechar('t', 56, 64):
        return HE_noscript;
        break;
    case 0| onechar('o', 0, 64)| onechar('p', 8, 64)| onechar('t', 16, 64)| onechar('g', 24, 64)| onechar('r', 32, 64)| onechar('o', 40, 64)| onechar('u', 48, 64)| onechar('p', 56, 64):
        return HE_optgroup;
        break;
    case 0| onechar('p', 0, 64)| onechar('r', 8, 64)| onechar('o', 16, 64)| onechar('g', 24, 64)| onechar('r', 32, 64)| onechar('e', 40, 64)| onechar('s', 48, 64)| onechar('s', 56, 64):
        return HE_progress;
        break;
    case 0| onechar('t', 0, 64)| onechar('e', 8, 64)| onechar('m', 16, 64)| onechar('p', 24, 64)| onechar('l', 32, 64)| onechar('a', 40, 64)| onechar('t', 48, 64)| onechar('e', 56, 64):
        return HE_template;
        break;
    case 0| onechar('t', 0, 64)| onechar('e', 8, 64)| onechar('x', 16, 64)| onechar('t', 24, 64)| onechar('a', 32, 64)| onechar('r', 40, 64)| onechar('e', 48, 64)| onechar('a', 56, 64):
        return HE_textarea;
    }
    return HE_Unknown;
}
static enum HtmlElement lookup_html_element10(const char *string)
{
    switch(*((triehash_uu64*) &string[0])) {
    case 0| onechar('b', 0, 64)| onechar('l', 8, 64)| onechar('o', 16, 64)| onechar('c', 24, 64)| onechar('k', 32, 64)| onechar('q', 40, 64)| onechar('u', 48, 64)| onechar('o', 56, 64):
        switch(string[8]) {
        case 0| onechar('t', 0, 8):
            switch(string[9]) {
            case 0| onechar('e', 0, 8):
                return HE_blockquote;
            }
        }
        break;
    case 0| onechar('f', 0, 64)| onechar('i', 8, 64)| onechar('g', 16, 64)| onechar('c', 24, 64)| onechar('a', 32, 64)| onechar('p', 40, 64)| onechar('t', 48, 64)| onechar('i', 56, 64):
        switch(string[8]) {
        case 0| onechar('o', 0, 8):
            switch(string[9]) {
            case 0| onechar('n', 0, 8):
                return HE_figcaption;
            }
        }
    }
    return HE_Unknown;
}
#else
static enum HtmlElement lookup_html_element1(const char *string)
{
    switch(string[0]) {
    case 'a':
        return HE_a;
        break;
    case 'b':
        return HE_b;
        break;
    case 'i':
        return HE_i;
        break;
    case 'p':
        return HE_p;
        break;
    case 'q':
        return HE_q;
        break;
    case 's':
        return HE_s;
        break;
    case 'u':
        return HE_u;
    }
    return HE_Unknown;
}
static enum HtmlElement lookup_html_element2(const char *string)
{
    switch(string[0]) {
    case 'b':
        switch(string[1]) {
        case 'r':
            return HE_br;
        }
        break;
    case 'd':
        switch(string[1]) {
        case 'd':
            return HE_dd;
            break;
        case 'l':
            return HE_dl;
            break;
        case 't':
            return HE_dt;
        }
        break;
    case 'e':
        switch(string[1]) {
        case 'm':
            return HE_em;
        }
        break;
    case 'h':
        switch(string[1]) {
        case '1':
            return HE_h1;
            break;
        case '2':
            return HE_h2;
            break;
        case '3':
            return HE_h3;
            break;
        case '4':
            return HE_h4;
            break;
        case '5':
            return HE_h5;
            break;
        case '6':
            return HE_h6;
            break;
        case 'r':
            return HE_hr;
        }
        break;
    case 'l':
        switch(string[1]) {
        case 'i':
            return HE_li;
        }
        break;
    case 'o':
        switch(string[1]) {
        case 'l':
            return HE_ol;
        }
        break;
    case 'r':
        switch(string[1]) {
        case 'p':
            return HE_rp;
            break;
        case 't':
            return HE_rt;
        }
        break;
    case 't':
        switch(string[1]) {
        case 'd':
            return HE_td;
            break;
        case 'h':
            return HE_th;
            break;
        case 'r':
            return HE_tr;
        }
        break;
    case 'u':
        switch(string[1]) {
        case 'l':
            return HE_ul;
        }
    }
    return HE_Unknown;
}
static enum HtmlElement lookup_html_element3(const char *string)
{
    switch(string[0]) {
    case 'b':
        switch(string[1]) {
        case 'd':
            switch(string[2]) {
            case 'i':
                return HE_bdi;
                break;
            case 'o':
                return HE_bdo;
            }
        }
        break;
    case 'c':
        switch(string[1]) {
        case 'o':
            switch(string[2]) {
            case 'l':
                return HE_col;
            }
        }
        break;
    case 'd':
        switch(string[1]) {
        case 'e':
            switch(string[2]) {
            case 'l':
                return HE_del;
            }
            break;
        case 'f':
            switch(string[2]) {
            case 'n':
                return HE_dfn;
            }
            break;
        case 'i':
            switch(string[2]) {
            case 'v':
                return HE_div;
            }
        }
        break;
    case 'i':
        switch(string[1]) {
        case 'm':
            switch(string[2]) {
            case 'g':
                return HE_img;
            }
            break;
        case 'n':
            switch(string[2]) {
            case 's':
                return HE_ins;
            }
        }
        break;
    case 'k':
        switch(string[1]) {
        case 'b':
            switch(string[2]) {
            case 'd':
                return HE_kbd;
            }
        }
        break;
    case 'm':
        switch(string[1]) {
        case 'a':
            switch(string[2]) {
            case 'p':
                return HE_map;
            }
        }
        break;
    case 'n':
        switch(string[1]) {
        case 'a':
            switch(string[2]) {
            case 'v':
                return HE_nav;
            }
        }
        break;
    case 'p':
        switch(string[1]) {
        case 'r':
            switch(string[2]) {
            case 'e':
                return HE_pre;
            }
        }
        break;
    case 's':
        switch(string[1]) {
        case 'u':
            switch(string[2]) {
            case 'b':
                return HE_sub;
                break;
            case 'p':
                return HE_sup;
            }
            break;
        case 'v':
            switch(string[2]) {
            case 'g':
                return HE_svg;
            }
        }
        break;
    case 'v':
        switch(string[1]) {
        case 'a':
            switch(string[2]) {
            case 'r':
                return HE_var;
            }
        }
        break;
    case 'w':
        switch(string[1]) {
        case 'b':
            switch(string[2]) {
            case 'r':
                return HE_wbr;
            }
        }
    }
    return HE_Unknown;
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
                    return HE_abbr;
                }
            }
            break;
        case 'r':
            switch(string[2]) {
            case 'e':
                switch(string[3]) {
                case 'a':
                    return HE_area;
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
                    return HE_base;
                }
            }
            break;
        case 'o':
            switch(string[2]) {
            case 'd':
                switch(string[3]) {
                case 'y':
                    return HE_body;
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
                    return HE_cite;
                }
            }
            break;
        case 'o':
            switch(string[2]) {
            case 'd':
                switch(string[3]) {
                case 'e':
                    return HE_code;
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
                    return HE_data;
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
                    return HE_form;
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
                    return HE_head;
                }
            }
            break;
        case 't':
            switch(string[2]) {
            case 'm':
                switch(string[3]) {
                case 'l':
                    return HE_html;
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
                    return HE_link;
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
                    return HE_main;
                }
                break;
            case 'r':
                switch(string[3]) {
                case 'k':
                    return HE_mark;
                }
                break;
            case 't':
                switch(string[3]) {
                case 'h':
                    return HE_math;
                }
            }
            break;
        case 'e':
            switch(string[2]) {
            case 'n':
                switch(string[3]) {
                case 'u':
                    return HE_menu;
                }
                break;
            case 't':
                switch(string[3]) {
                case 'a':
                    return HE_meta;
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
                    return HE_ruby;
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
                    return HE_samp;
                }
            }
            break;
        case 'p':
            switch(string[2]) {
            case 'a':
                switch(string[3]) {
                case 'n':
                    return HE_span;
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
                    return HE_time;
                }
            }
        }
    }
    return HE_Unknown;
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
                        return HE_aside;
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
                        return HE_audio;
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
                        return HE_embed;
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
                        return HE_input;
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
                        return HE_label;
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
                        return HE_meter;
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
                        return HE_param;
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
                        return HE_small;
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
                        return HE_style;
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
                        return HE_table;
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
                        return HE_tbody;
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
                        return HE_tfoot;
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
                        return HE_thead;
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
                        return HE_title;
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
                        return HE_track;
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
                        return HE_video;
                    }
                }
            }
        }
    }
    return HE_Unknown;
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
                            return HE_button;
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
                            return HE_canvas;
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
                            return HE_dialog;
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
                            return HE_figure;
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
                            return HE_footer;
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
                            return HE_header;
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
                            return HE_hgroup;
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
                            return HE_iframe;
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
                            return HE_keygen;
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
                            return HE_legend;
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
                            return HE_object;
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
                            return HE_option;
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
                            return HE_output;
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
                            return HE_script;
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
                            return HE_select;
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
                            return HE_source;
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
                            return HE_strong;
                        }
                    }
                }
            }
        }
    }
    return HE_Unknown;
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
                                return HE_address;
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
                                return HE_article;
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
                                return HE_caption;
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
                                return HE_details;
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
                                return HE_picture;
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
                                return HE_section;
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
                                return HE_summary;
                            }
                        }
                    }
                }
            }
        }
    }
    return HE_Unknown;
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
                                    return HE_colgroup;
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
                                    return HE_datalist;
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
                                    return HE_fieldset;
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
                                    return HE_menuitem;
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
                                    return HE_noscript;
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
                                    return HE_optgroup;
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
                                    return HE_progress;
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
                                    return HE_template;
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
                                    return HE_textarea;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return HE_Unknown;
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
                                            return HE_blockquote;
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
                                            return HE_figcaption;
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
    return HE_Unknown;
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
        return HE_Unknown;
    }
}
#endif                       /* TRIE_HASH_lookup_html_element */
