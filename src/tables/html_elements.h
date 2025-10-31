// Generated with:
// $ triehash --ignore-case --enum-name=Element --function-name=lookup_element --label-prefix=E_ tables/html_elements.txt > tables/html_elements.h

#ifndef TRIE_HASH_lookup_element
#define TRIE_HASH_lookup_element
#include <stddef.h>
#include <stdint.h>
enum Element {
    E_a = 1,
    E_abbr = 2,
    E_address = 3,
    E_area = 4,
    E_article = 5,
    E_aside = 6,
    E_audio = 7,
    E_b = 8,
    E_bdi = 10,
    E_bdo = 11,
    E_br = 14,
    E_base = 9,
    E_blockquote = 12,
    E_body = 13,
    E_button = 15,
    E_col = 20,
    E_canvas = 16,
    E_caption = 17,
    E_cite = 18,
    E_code = 19,
    E_colgroup = 21,
    E_dd = 24,
    E_del = 25,
    E_dfn = 27,
    E_div = 29,
    E_dl = 30,
    E_dt = 31,
    E_data = 22,
    E_datalist = 23,
    E_details = 26,
    E_dialog = 28,
    E_em = 32,
    E_embed = 33,
    E_fieldset = 34,
    E_figcaption = 35,
    E_figure = 36,
    E_footer = 37,
    E_form = 38,
    E_h1 = 42,
    E_h2 = 43,
    E_h3 = 44,
    E_h4 = 45,
    E_h5 = 46,
    E_h6 = 47,
    E_hr = 48,
    E_head = 39,
    E_header = 40,
    E_hgroup = 41,
    E_html = 49,
    E_i = 50,
    E_img = 52,
    E_ins = 54,
    E_iframe = 51,
    E_input = 53,
    E_kbd = 55,
    E_keygen = 56,
    E_li = 59,
    E_label = 57,
    E_legend = 58,
    E_link = 60,
    E_map = 62,
    E_main = 61,
    E_mark = 63,
    E_menu = 64,
    E_menuitem = 65,
    E_meta = 66,
    E_meter = 67,
    E_nav = 68,
    E_noscript = 69,
    E_ol = 71,
    E_object = 70,
    E_optgroup = 72,
    E_option = 73,
    E_output = 74,
    E_p = 75,
    E_pre = 78,
    E_param = 76,
    E_picture = 77,
    E_progress = 79,
    E_q = 80,
    E_rp = 81,
    E_rt = 82,
    E_ruby = 83,
    E_s = 84,
    E_sub = 94,
    E_sup = 96,
    E_svg = 97,
    E_samp = 85,
    E_script = 86,
    E_section = 87,
    E_select = 88,
    E_small = 89,
    E_source = 90,
    E_span = 91,
    E_strong = 92,
    E_style = 93,
    E_summary = 95,
    E_td = 100,
    E_th = 104,
    E_tr = 108,
    E_table = 98,
    E_tbody = 99,
    E_template = 101,
    E_textarea = 102,
    E_tfoot = 103,
    E_thead = 105,
    E_time = 106,
    E_title = 107,
    E_track = 109,
    E_u = 110,
    E_ul = 111,
    E_var = 112,
    E_video = 113,
    E_wbr = 114,
    E_Unknown = 0,
};
static enum Element lookup_element(const char *string, size_t length);
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
static enum Element lookup_element1(const char *string)
{
    switch(string[0] | 0x20) {
    case 0| onechar('a', 0, 8):
        return E_a;
        break;
    case 0| onechar('b', 0, 8):
        return E_b;
        break;
    case 0| onechar('i', 0, 8):
        return E_i;
        break;
    case 0| onechar('p', 0, 8):
        return E_p;
        break;
    case 0| onechar('q', 0, 8):
        return E_q;
        break;
    case 0| onechar('s', 0, 8):
        return E_s;
        break;
    case 0| onechar('u', 0, 8):
        return E_u;
    }
    return E_Unknown;
}
static enum Element lookup_element2(const char *string)
{
    switch(string[0] | 0x20) {
    case 0| onechar('b', 0, 8):
        switch(string[1] | 0x20) {
        case 0| onechar('r', 0, 8):
            return E_br;
        }
        break;
    case 0| onechar('d', 0, 8):
        switch(string[1] | 0x20) {
        case 0| onechar('d', 0, 8):
            return E_dd;
            break;
        case 0| onechar('l', 0, 8):
            return E_dl;
            break;
        case 0| onechar('t', 0, 8):
            return E_dt;
        }
        break;
    case 0| onechar('e', 0, 8):
        switch(string[1] | 0x20) {
        case 0| onechar('m', 0, 8):
            return E_em;
        }
        break;
    case 0| onechar('h', 0, 8):
        switch(string[1]) {
        case 0| onechar('1', 0, 8):
            return E_h1;
            break;
        case 0| onechar('2', 0, 8):
            return E_h2;
            break;
        case 0| onechar('3', 0, 8):
            return E_h3;
            break;
        case 0| onechar('4', 0, 8):
            return E_h4;
            break;
        case 0| onechar('5', 0, 8):
            return E_h5;
            break;
        case 0| onechar('6', 0, 8):
            return E_h6;
            break;
        case 0| onechar('r', 0, 8):
        case 0| onechar('R', 0, 8):
            return E_hr;
        }
        break;
    case 0| onechar('l', 0, 8):
        switch(string[1] | 0x20) {
        case 0| onechar('i', 0, 8):
            return E_li;
        }
        break;
    case 0| onechar('o', 0, 8):
        switch(string[1] | 0x20) {
        case 0| onechar('l', 0, 8):
            return E_ol;
        }
        break;
    case 0| onechar('r', 0, 8):
        switch(string[1] | 0x20) {
        case 0| onechar('p', 0, 8):
            return E_rp;
            break;
        case 0| onechar('t', 0, 8):
            return E_rt;
        }
        break;
    case 0| onechar('t', 0, 8):
        switch(string[1] | 0x20) {
        case 0| onechar('d', 0, 8):
            return E_td;
            break;
        case 0| onechar('h', 0, 8):
            return E_th;
            break;
        case 0| onechar('r', 0, 8):
            return E_tr;
        }
        break;
    case 0| onechar('u', 0, 8):
        switch(string[1] | 0x20) {
        case 0| onechar('l', 0, 8):
            return E_ul;
        }
    }
    return E_Unknown;
}
static enum Element lookup_element3(const char *string)
{
    switch(string[0] | 0x20) {
    case 0| onechar('b', 0, 8):
        switch(string[1] | 0x20) {
        case 0| onechar('d', 0, 8):
            switch(string[2] | 0x20) {
            case 0| onechar('i', 0, 8):
                return E_bdi;
                break;
            case 0| onechar('o', 0, 8):
                return E_bdo;
            }
        }
        break;
    case 0| onechar('c', 0, 8):
        switch(string[1] | 0x20) {
        case 0| onechar('o', 0, 8):
            switch(string[2] | 0x20) {
            case 0| onechar('l', 0, 8):
                return E_col;
            }
        }
        break;
    case 0| onechar('d', 0, 8):
        switch(string[1] | 0x20) {
        case 0| onechar('e', 0, 8):
            switch(string[2] | 0x20) {
            case 0| onechar('l', 0, 8):
                return E_del;
            }
            break;
        case 0| onechar('f', 0, 8):
            switch(string[2] | 0x20) {
            case 0| onechar('n', 0, 8):
                return E_dfn;
            }
            break;
        case 0| onechar('i', 0, 8):
            switch(string[2] | 0x20) {
            case 0| onechar('v', 0, 8):
                return E_div;
            }
        }
        break;
    case 0| onechar('i', 0, 8):
        switch(string[1] | 0x20) {
        case 0| onechar('m', 0, 8):
            switch(string[2] | 0x20) {
            case 0| onechar('g', 0, 8):
                return E_img;
            }
            break;
        case 0| onechar('n', 0, 8):
            switch(string[2] | 0x20) {
            case 0| onechar('s', 0, 8):
                return E_ins;
            }
        }
        break;
    case 0| onechar('k', 0, 8):
        switch(string[1] | 0x20) {
        case 0| onechar('b', 0, 8):
            switch(string[2] | 0x20) {
            case 0| onechar('d', 0, 8):
                return E_kbd;
            }
        }
        break;
    case 0| onechar('m', 0, 8):
        switch(string[1] | 0x20) {
        case 0| onechar('a', 0, 8):
            switch(string[2] | 0x20) {
            case 0| onechar('p', 0, 8):
                return E_map;
            }
        }
        break;
    case 0| onechar('n', 0, 8):
        switch(string[1] | 0x20) {
        case 0| onechar('a', 0, 8):
            switch(string[2] | 0x20) {
            case 0| onechar('v', 0, 8):
                return E_nav;
            }
        }
        break;
    case 0| onechar('p', 0, 8):
        switch(string[1] | 0x20) {
        case 0| onechar('r', 0, 8):
            switch(string[2] | 0x20) {
            case 0| onechar('e', 0, 8):
                return E_pre;
            }
        }
        break;
    case 0| onechar('s', 0, 8):
        switch(string[1] | 0x20) {
        case 0| onechar('u', 0, 8):
            switch(string[2] | 0x20) {
            case 0| onechar('b', 0, 8):
                return E_sub;
                break;
            case 0| onechar('p', 0, 8):
                return E_sup;
            }
            break;
        case 0| onechar('v', 0, 8):
            switch(string[2] | 0x20) {
            case 0| onechar('g', 0, 8):
                return E_svg;
            }
        }
        break;
    case 0| onechar('v', 0, 8):
        switch(string[1] | 0x20) {
        case 0| onechar('a', 0, 8):
            switch(string[2] | 0x20) {
            case 0| onechar('r', 0, 8):
                return E_var;
            }
        }
        break;
    case 0| onechar('w', 0, 8):
        switch(string[1] | 0x20) {
        case 0| onechar('b', 0, 8):
            switch(string[2] | 0x20) {
            case 0| onechar('r', 0, 8):
                return E_wbr;
            }
        }
    }
    return E_Unknown;
}
static enum Element lookup_element4(const char *string)
{
    switch(*((triehash_uu32*) &string[0]) | 0x20202020) {
    case 0| onechar('a', 0, 32)| onechar('b', 8, 32)| onechar('b', 16, 32)| onechar('r', 24, 32):
        return E_abbr;
        break;
    case 0| onechar('a', 0, 32)| onechar('r', 8, 32)| onechar('e', 16, 32)| onechar('a', 24, 32):
        return E_area;
        break;
    case 0| onechar('b', 0, 32)| onechar('a', 8, 32)| onechar('s', 16, 32)| onechar('e', 24, 32):
        return E_base;
        break;
    case 0| onechar('b', 0, 32)| onechar('o', 8, 32)| onechar('d', 16, 32)| onechar('y', 24, 32):
        return E_body;
        break;
    case 0| onechar('c', 0, 32)| onechar('i', 8, 32)| onechar('t', 16, 32)| onechar('e', 24, 32):
        return E_cite;
        break;
    case 0| onechar('c', 0, 32)| onechar('o', 8, 32)| onechar('d', 16, 32)| onechar('e', 24, 32):
        return E_code;
        break;
    case 0| onechar('d', 0, 32)| onechar('a', 8, 32)| onechar('t', 16, 32)| onechar('a', 24, 32):
        return E_data;
        break;
    case 0| onechar('f', 0, 32)| onechar('o', 8, 32)| onechar('r', 16, 32)| onechar('m', 24, 32):
        return E_form;
        break;
    case 0| onechar('h', 0, 32)| onechar('e', 8, 32)| onechar('a', 16, 32)| onechar('d', 24, 32):
        return E_head;
        break;
    case 0| onechar('h', 0, 32)| onechar('t', 8, 32)| onechar('m', 16, 32)| onechar('l', 24, 32):
        return E_html;
        break;
    case 0| onechar('l', 0, 32)| onechar('i', 8, 32)| onechar('n', 16, 32)| onechar('k', 24, 32):
        return E_link;
        break;
    case 0| onechar('m', 0, 32)| onechar('a', 8, 32)| onechar('i', 16, 32)| onechar('n', 24, 32):
        return E_main;
        break;
    case 0| onechar('m', 0, 32)| onechar('a', 8, 32)| onechar('r', 16, 32)| onechar('k', 24, 32):
        return E_mark;
        break;
    case 0| onechar('m', 0, 32)| onechar('e', 8, 32)| onechar('n', 16, 32)| onechar('u', 24, 32):
        return E_menu;
        break;
    case 0| onechar('m', 0, 32)| onechar('e', 8, 32)| onechar('t', 16, 32)| onechar('a', 24, 32):
        return E_meta;
        break;
    case 0| onechar('r', 0, 32)| onechar('u', 8, 32)| onechar('b', 16, 32)| onechar('y', 24, 32):
        return E_ruby;
        break;
    case 0| onechar('s', 0, 32)| onechar('a', 8, 32)| onechar('m', 16, 32)| onechar('p', 24, 32):
        return E_samp;
        break;
    case 0| onechar('s', 0, 32)| onechar('p', 8, 32)| onechar('a', 16, 32)| onechar('n', 24, 32):
        return E_span;
        break;
    case 0| onechar('t', 0, 32)| onechar('i', 8, 32)| onechar('m', 16, 32)| onechar('e', 24, 32):
        return E_time;
    }
    return E_Unknown;
}
static enum Element lookup_element5(const char *string)
{
    switch(*((triehash_uu32*) &string[0]) | 0x20202020) {
    case 0| onechar('a', 0, 32)| onechar('s', 8, 32)| onechar('i', 16, 32)| onechar('d', 24, 32):
        switch(string[4] | 0x20) {
        case 0| onechar('e', 0, 8):
            return E_aside;
        }
        break;
    case 0| onechar('a', 0, 32)| onechar('u', 8, 32)| onechar('d', 16, 32)| onechar('i', 24, 32):
        switch(string[4] | 0x20) {
        case 0| onechar('o', 0, 8):
            return E_audio;
        }
        break;
    case 0| onechar('e', 0, 32)| onechar('m', 8, 32)| onechar('b', 16, 32)| onechar('e', 24, 32):
        switch(string[4] | 0x20) {
        case 0| onechar('d', 0, 8):
            return E_embed;
        }
        break;
    case 0| onechar('i', 0, 32)| onechar('n', 8, 32)| onechar('p', 16, 32)| onechar('u', 24, 32):
        switch(string[4] | 0x20) {
        case 0| onechar('t', 0, 8):
            return E_input;
        }
        break;
    case 0| onechar('l', 0, 32)| onechar('a', 8, 32)| onechar('b', 16, 32)| onechar('e', 24, 32):
        switch(string[4] | 0x20) {
        case 0| onechar('l', 0, 8):
            return E_label;
        }
        break;
    case 0| onechar('m', 0, 32)| onechar('e', 8, 32)| onechar('t', 16, 32)| onechar('e', 24, 32):
        switch(string[4] | 0x20) {
        case 0| onechar('r', 0, 8):
            return E_meter;
        }
        break;
    case 0| onechar('p', 0, 32)| onechar('a', 8, 32)| onechar('r', 16, 32)| onechar('a', 24, 32):
        switch(string[4] | 0x20) {
        case 0| onechar('m', 0, 8):
            return E_param;
        }
        break;
    case 0| onechar('s', 0, 32)| onechar('m', 8, 32)| onechar('a', 16, 32)| onechar('l', 24, 32):
        switch(string[4] | 0x20) {
        case 0| onechar('l', 0, 8):
            return E_small;
        }
        break;
    case 0| onechar('s', 0, 32)| onechar('t', 8, 32)| onechar('y', 16, 32)| onechar('l', 24, 32):
        switch(string[4] | 0x20) {
        case 0| onechar('e', 0, 8):
            return E_style;
        }
        break;
    case 0| onechar('t', 0, 32)| onechar('a', 8, 32)| onechar('b', 16, 32)| onechar('l', 24, 32):
        switch(string[4] | 0x20) {
        case 0| onechar('e', 0, 8):
            return E_table;
        }
        break;
    case 0| onechar('t', 0, 32)| onechar('b', 8, 32)| onechar('o', 16, 32)| onechar('d', 24, 32):
        switch(string[4] | 0x20) {
        case 0| onechar('y', 0, 8):
            return E_tbody;
        }
        break;
    case 0| onechar('t', 0, 32)| onechar('f', 8, 32)| onechar('o', 16, 32)| onechar('o', 24, 32):
        switch(string[4] | 0x20) {
        case 0| onechar('t', 0, 8):
            return E_tfoot;
        }
        break;
    case 0| onechar('t', 0, 32)| onechar('h', 8, 32)| onechar('e', 16, 32)| onechar('a', 24, 32):
        switch(string[4] | 0x20) {
        case 0| onechar('d', 0, 8):
            return E_thead;
        }
        break;
    case 0| onechar('t', 0, 32)| onechar('i', 8, 32)| onechar('t', 16, 32)| onechar('l', 24, 32):
        switch(string[4] | 0x20) {
        case 0| onechar('e', 0, 8):
            return E_title;
        }
        break;
    case 0| onechar('t', 0, 32)| onechar('r', 8, 32)| onechar('a', 16, 32)| onechar('c', 24, 32):
        switch(string[4] | 0x20) {
        case 0| onechar('k', 0, 8):
            return E_track;
        }
        break;
    case 0| onechar('v', 0, 32)| onechar('i', 8, 32)| onechar('d', 16, 32)| onechar('e', 24, 32):
        switch(string[4] | 0x20) {
        case 0| onechar('o', 0, 8):
            return E_video;
        }
    }
    return E_Unknown;
}
static enum Element lookup_element6(const char *string)
{
    switch(*((triehash_uu32*) &string[0]) | 0x20202020) {
    case 0| onechar('b', 0, 32)| onechar('u', 8, 32)| onechar('t', 16, 32)| onechar('t', 24, 32):
        switch(string[4] | 0x20) {
        case 0| onechar('o', 0, 8):
            switch(string[5] | 0x20) {
            case 0| onechar('n', 0, 8):
                return E_button;
            }
        }
        break;
    case 0| onechar('c', 0, 32)| onechar('a', 8, 32)| onechar('n', 16, 32)| onechar('v', 24, 32):
        switch(string[4] | 0x20) {
        case 0| onechar('a', 0, 8):
            switch(string[5] | 0x20) {
            case 0| onechar('s', 0, 8):
                return E_canvas;
            }
        }
        break;
    case 0| onechar('d', 0, 32)| onechar('i', 8, 32)| onechar('a', 16, 32)| onechar('l', 24, 32):
        switch(string[4] | 0x20) {
        case 0| onechar('o', 0, 8):
            switch(string[5] | 0x20) {
            case 0| onechar('g', 0, 8):
                return E_dialog;
            }
        }
        break;
    case 0| onechar('f', 0, 32)| onechar('i', 8, 32)| onechar('g', 16, 32)| onechar('u', 24, 32):
        switch(string[4] | 0x20) {
        case 0| onechar('r', 0, 8):
            switch(string[5] | 0x20) {
            case 0| onechar('e', 0, 8):
                return E_figure;
            }
        }
        break;
    case 0| onechar('f', 0, 32)| onechar('o', 8, 32)| onechar('o', 16, 32)| onechar('t', 24, 32):
        switch(string[4] | 0x20) {
        case 0| onechar('e', 0, 8):
            switch(string[5] | 0x20) {
            case 0| onechar('r', 0, 8):
                return E_footer;
            }
        }
        break;
    case 0| onechar('h', 0, 32)| onechar('e', 8, 32)| onechar('a', 16, 32)| onechar('d', 24, 32):
        switch(string[4] | 0x20) {
        case 0| onechar('e', 0, 8):
            switch(string[5] | 0x20) {
            case 0| onechar('r', 0, 8):
                return E_header;
            }
        }
        break;
    case 0| onechar('h', 0, 32)| onechar('g', 8, 32)| onechar('r', 16, 32)| onechar('o', 24, 32):
        switch(string[4] | 0x20) {
        case 0| onechar('u', 0, 8):
            switch(string[5] | 0x20) {
            case 0| onechar('p', 0, 8):
                return E_hgroup;
            }
        }
        break;
    case 0| onechar('i', 0, 32)| onechar('f', 8, 32)| onechar('r', 16, 32)| onechar('a', 24, 32):
        switch(string[4] | 0x20) {
        case 0| onechar('m', 0, 8):
            switch(string[5] | 0x20) {
            case 0| onechar('e', 0, 8):
                return E_iframe;
            }
        }
        break;
    case 0| onechar('k', 0, 32)| onechar('e', 8, 32)| onechar('y', 16, 32)| onechar('g', 24, 32):
        switch(string[4] | 0x20) {
        case 0| onechar('e', 0, 8):
            switch(string[5] | 0x20) {
            case 0| onechar('n', 0, 8):
                return E_keygen;
            }
        }
        break;
    case 0| onechar('l', 0, 32)| onechar('e', 8, 32)| onechar('g', 16, 32)| onechar('e', 24, 32):
        switch(string[4] | 0x20) {
        case 0| onechar('n', 0, 8):
            switch(string[5] | 0x20) {
            case 0| onechar('d', 0, 8):
                return E_legend;
            }
        }
        break;
    case 0| onechar('o', 0, 32)| onechar('b', 8, 32)| onechar('j', 16, 32)| onechar('e', 24, 32):
        switch(string[4] | 0x20) {
        case 0| onechar('c', 0, 8):
            switch(string[5] | 0x20) {
            case 0| onechar('t', 0, 8):
                return E_object;
            }
        }
        break;
    case 0| onechar('o', 0, 32)| onechar('p', 8, 32)| onechar('t', 16, 32)| onechar('i', 24, 32):
        switch(string[4] | 0x20) {
        case 0| onechar('o', 0, 8):
            switch(string[5] | 0x20) {
            case 0| onechar('n', 0, 8):
                return E_option;
            }
        }
        break;
    case 0| onechar('o', 0, 32)| onechar('u', 8, 32)| onechar('t', 16, 32)| onechar('p', 24, 32):
        switch(string[4] | 0x20) {
        case 0| onechar('u', 0, 8):
            switch(string[5] | 0x20) {
            case 0| onechar('t', 0, 8):
                return E_output;
            }
        }
        break;
    case 0| onechar('s', 0, 32)| onechar('c', 8, 32)| onechar('r', 16, 32)| onechar('i', 24, 32):
        switch(string[4] | 0x20) {
        case 0| onechar('p', 0, 8):
            switch(string[5] | 0x20) {
            case 0| onechar('t', 0, 8):
                return E_script;
            }
        }
        break;
    case 0| onechar('s', 0, 32)| onechar('e', 8, 32)| onechar('l', 16, 32)| onechar('e', 24, 32):
        switch(string[4] | 0x20) {
        case 0| onechar('c', 0, 8):
            switch(string[5] | 0x20) {
            case 0| onechar('t', 0, 8):
                return E_select;
            }
        }
        break;
    case 0| onechar('s', 0, 32)| onechar('o', 8, 32)| onechar('u', 16, 32)| onechar('r', 24, 32):
        switch(string[4] | 0x20) {
        case 0| onechar('c', 0, 8):
            switch(string[5] | 0x20) {
            case 0| onechar('e', 0, 8):
                return E_source;
            }
        }
        break;
    case 0| onechar('s', 0, 32)| onechar('t', 8, 32)| onechar('r', 16, 32)| onechar('o', 24, 32):
        switch(string[4] | 0x20) {
        case 0| onechar('n', 0, 8):
            switch(string[5] | 0x20) {
            case 0| onechar('g', 0, 8):
                return E_strong;
            }
        }
    }
    return E_Unknown;
}
static enum Element lookup_element7(const char *string)
{
    switch(*((triehash_uu32*) &string[0]) | 0x20202020) {
    case 0| onechar('a', 0, 32)| onechar('d', 8, 32)| onechar('d', 16, 32)| onechar('r', 24, 32):
        switch(string[4] | 0x20) {
        case 0| onechar('e', 0, 8):
            switch(string[5] | 0x20) {
            case 0| onechar('s', 0, 8):
                switch(string[6] | 0x20) {
                case 0| onechar('s', 0, 8):
                    return E_address;
                }
            }
        }
        break;
    case 0| onechar('a', 0, 32)| onechar('r', 8, 32)| onechar('t', 16, 32)| onechar('i', 24, 32):
        switch(string[4] | 0x20) {
        case 0| onechar('c', 0, 8):
            switch(string[5] | 0x20) {
            case 0| onechar('l', 0, 8):
                switch(string[6] | 0x20) {
                case 0| onechar('e', 0, 8):
                    return E_article;
                }
            }
        }
        break;
    case 0| onechar('c', 0, 32)| onechar('a', 8, 32)| onechar('p', 16, 32)| onechar('t', 24, 32):
        switch(string[4] | 0x20) {
        case 0| onechar('i', 0, 8):
            switch(string[5] | 0x20) {
            case 0| onechar('o', 0, 8):
                switch(string[6] | 0x20) {
                case 0| onechar('n', 0, 8):
                    return E_caption;
                }
            }
        }
        break;
    case 0| onechar('d', 0, 32)| onechar('e', 8, 32)| onechar('t', 16, 32)| onechar('a', 24, 32):
        switch(string[4] | 0x20) {
        case 0| onechar('i', 0, 8):
            switch(string[5] | 0x20) {
            case 0| onechar('l', 0, 8):
                switch(string[6] | 0x20) {
                case 0| onechar('s', 0, 8):
                    return E_details;
                }
            }
        }
        break;
    case 0| onechar('p', 0, 32)| onechar('i', 8, 32)| onechar('c', 16, 32)| onechar('t', 24, 32):
        switch(string[4] | 0x20) {
        case 0| onechar('u', 0, 8):
            switch(string[5] | 0x20) {
            case 0| onechar('r', 0, 8):
                switch(string[6] | 0x20) {
                case 0| onechar('e', 0, 8):
                    return E_picture;
                }
            }
        }
        break;
    case 0| onechar('s', 0, 32)| onechar('e', 8, 32)| onechar('c', 16, 32)| onechar('t', 24, 32):
        switch(string[4] | 0x20) {
        case 0| onechar('i', 0, 8):
            switch(string[5] | 0x20) {
            case 0| onechar('o', 0, 8):
                switch(string[6] | 0x20) {
                case 0| onechar('n', 0, 8):
                    return E_section;
                }
            }
        }
        break;
    case 0| onechar('s', 0, 32)| onechar('u', 8, 32)| onechar('m', 16, 32)| onechar('m', 24, 32):
        switch(string[4] | 0x20) {
        case 0| onechar('a', 0, 8):
            switch(string[5] | 0x20) {
            case 0| onechar('r', 0, 8):
                switch(string[6] | 0x20) {
                case 0| onechar('y', 0, 8):
                    return E_summary;
                }
            }
        }
    }
    return E_Unknown;
}
static enum Element lookup_element8(const char *string)
{
    switch(*((triehash_uu64*) &string[0]) | 0x2020202020202020) {
    case 0| onechar('c', 0, 64)| onechar('o', 8, 64)| onechar('l', 16, 64)| onechar('g', 24, 64)| onechar('r', 32, 64)| onechar('o', 40, 64)| onechar('u', 48, 64)| onechar('p', 56, 64):
        return E_colgroup;
        break;
    case 0| onechar('d', 0, 64)| onechar('a', 8, 64)| onechar('t', 16, 64)| onechar('a', 24, 64)| onechar('l', 32, 64)| onechar('i', 40, 64)| onechar('s', 48, 64)| onechar('t', 56, 64):
        return E_datalist;
        break;
    case 0| onechar('f', 0, 64)| onechar('i', 8, 64)| onechar('e', 16, 64)| onechar('l', 24, 64)| onechar('d', 32, 64)| onechar('s', 40, 64)| onechar('e', 48, 64)| onechar('t', 56, 64):
        return E_fieldset;
        break;
    case 0| onechar('m', 0, 64)| onechar('e', 8, 64)| onechar('n', 16, 64)| onechar('u', 24, 64)| onechar('i', 32, 64)| onechar('t', 40, 64)| onechar('e', 48, 64)| onechar('m', 56, 64):
        return E_menuitem;
        break;
    case 0| onechar('n', 0, 64)| onechar('o', 8, 64)| onechar('s', 16, 64)| onechar('c', 24, 64)| onechar('r', 32, 64)| onechar('i', 40, 64)| onechar('p', 48, 64)| onechar('t', 56, 64):
        return E_noscript;
        break;
    case 0| onechar('o', 0, 64)| onechar('p', 8, 64)| onechar('t', 16, 64)| onechar('g', 24, 64)| onechar('r', 32, 64)| onechar('o', 40, 64)| onechar('u', 48, 64)| onechar('p', 56, 64):
        return E_optgroup;
        break;
    case 0| onechar('p', 0, 64)| onechar('r', 8, 64)| onechar('o', 16, 64)| onechar('g', 24, 64)| onechar('r', 32, 64)| onechar('e', 40, 64)| onechar('s', 48, 64)| onechar('s', 56, 64):
        return E_progress;
        break;
    case 0| onechar('t', 0, 64)| onechar('e', 8, 64)| onechar('m', 16, 64)| onechar('p', 24, 64)| onechar('l', 32, 64)| onechar('a', 40, 64)| onechar('t', 48, 64)| onechar('e', 56, 64):
        return E_template;
        break;
    case 0| onechar('t', 0, 64)| onechar('e', 8, 64)| onechar('x', 16, 64)| onechar('t', 24, 64)| onechar('a', 32, 64)| onechar('r', 40, 64)| onechar('e', 48, 64)| onechar('a', 56, 64):
        return E_textarea;
    }
    return E_Unknown;
}
static enum Element lookup_element10(const char *string)
{
    switch(*((triehash_uu64*) &string[0]) | 0x2020202020202020) {
    case 0| onechar('b', 0, 64)| onechar('l', 8, 64)| onechar('o', 16, 64)| onechar('c', 24, 64)| onechar('k', 32, 64)| onechar('q', 40, 64)| onechar('u', 48, 64)| onechar('o', 56, 64):
        switch(string[8] | 0x20) {
        case 0| onechar('t', 0, 8):
            switch(string[9] | 0x20) {
            case 0| onechar('e', 0, 8):
                return E_blockquote;
            }
        }
        break;
    case 0| onechar('f', 0, 64)| onechar('i', 8, 64)| onechar('g', 16, 64)| onechar('c', 24, 64)| onechar('a', 32, 64)| onechar('p', 40, 64)| onechar('t', 48, 64)| onechar('i', 56, 64):
        switch(string[8] | 0x20) {
        case 0| onechar('o', 0, 8):
            switch(string[9] | 0x20) {
            case 0| onechar('n', 0, 8):
                return E_figcaption;
            }
        }
    }
    return E_Unknown;
}
#else
static enum Element lookup_element1(const char *string)
{
    switch(string[0] | 0x20) {
    case 'a':
        return E_a;
        break;
    case 'b':
        return E_b;
        break;
    case 'i':
        return E_i;
        break;
    case 'p':
        return E_p;
        break;
    case 'q':
        return E_q;
        break;
    case 's':
        return E_s;
        break;
    case 'u':
        return E_u;
    }
    return E_Unknown;
}
static enum Element lookup_element2(const char *string)
{
    switch(string[0] | 0x20) {
    case 'b':
        switch(string[1] | 0x20) {
        case 'r':
            return E_br;
        }
        break;
    case 'd':
        switch(string[1] | 0x20) {
        case 'd':
            return E_dd;
            break;
        case 'l':
            return E_dl;
            break;
        case 't':
            return E_dt;
        }
        break;
    case 'e':
        switch(string[1] | 0x20) {
        case 'm':
            return E_em;
        }
        break;
    case 'h':
        switch(string[1]) {
        case '1':
            return E_h1;
            break;
        case '2':
            return E_h2;
            break;
        case '3':
            return E_h3;
            break;
        case '4':
            return E_h4;
            break;
        case '5':
            return E_h5;
            break;
        case '6':
            return E_h6;
            break;
        case 'r':
        case 'R':
            return E_hr;
        }
        break;
    case 'l':
        switch(string[1] | 0x20) {
        case 'i':
            return E_li;
        }
        break;
    case 'o':
        switch(string[1] | 0x20) {
        case 'l':
            return E_ol;
        }
        break;
    case 'r':
        switch(string[1] | 0x20) {
        case 'p':
            return E_rp;
            break;
        case 't':
            return E_rt;
        }
        break;
    case 't':
        switch(string[1] | 0x20) {
        case 'd':
            return E_td;
            break;
        case 'h':
            return E_th;
            break;
        case 'r':
            return E_tr;
        }
        break;
    case 'u':
        switch(string[1] | 0x20) {
        case 'l':
            return E_ul;
        }
    }
    return E_Unknown;
}
static enum Element lookup_element3(const char *string)
{
    switch(string[0] | 0x20) {
    case 'b':
        switch(string[1] | 0x20) {
        case 'd':
            switch(string[2] | 0x20) {
            case 'i':
                return E_bdi;
                break;
            case 'o':
                return E_bdo;
            }
        }
        break;
    case 'c':
        switch(string[1] | 0x20) {
        case 'o':
            switch(string[2] | 0x20) {
            case 'l':
                return E_col;
            }
        }
        break;
    case 'd':
        switch(string[1] | 0x20) {
        case 'e':
            switch(string[2] | 0x20) {
            case 'l':
                return E_del;
            }
            break;
        case 'f':
            switch(string[2] | 0x20) {
            case 'n':
                return E_dfn;
            }
            break;
        case 'i':
            switch(string[2] | 0x20) {
            case 'v':
                return E_div;
            }
        }
        break;
    case 'i':
        switch(string[1] | 0x20) {
        case 'm':
            switch(string[2] | 0x20) {
            case 'g':
                return E_img;
            }
            break;
        case 'n':
            switch(string[2] | 0x20) {
            case 's':
                return E_ins;
            }
        }
        break;
    case 'k':
        switch(string[1] | 0x20) {
        case 'b':
            switch(string[2] | 0x20) {
            case 'd':
                return E_kbd;
            }
        }
        break;
    case 'm':
        switch(string[1] | 0x20) {
        case 'a':
            switch(string[2] | 0x20) {
            case 'p':
                return E_map;
            }
        }
        break;
    case 'n':
        switch(string[1] | 0x20) {
        case 'a':
            switch(string[2] | 0x20) {
            case 'v':
                return E_nav;
            }
        }
        break;
    case 'p':
        switch(string[1] | 0x20) {
        case 'r':
            switch(string[2] | 0x20) {
            case 'e':
                return E_pre;
            }
        }
        break;
    case 's':
        switch(string[1] | 0x20) {
        case 'u':
            switch(string[2] | 0x20) {
            case 'b':
                return E_sub;
                break;
            case 'p':
                return E_sup;
            }
            break;
        case 'v':
            switch(string[2] | 0x20) {
            case 'g':
                return E_svg;
            }
        }
        break;
    case 'v':
        switch(string[1] | 0x20) {
        case 'a':
            switch(string[2] | 0x20) {
            case 'r':
                return E_var;
            }
        }
        break;
    case 'w':
        switch(string[1] | 0x20) {
        case 'b':
            switch(string[2] | 0x20) {
            case 'r':
                return E_wbr;
            }
        }
    }
    return E_Unknown;
}
static enum Element lookup_element4(const char *string)
{
    switch(string[0] | 0x20) {
    case 'a':
        switch(string[1] | 0x20) {
        case 'b':
            switch(string[2] | 0x20) {
            case 'b':
                switch(string[3] | 0x20) {
                case 'r':
                    return E_abbr;
                }
            }
            break;
        case 'r':
            switch(string[2] | 0x20) {
            case 'e':
                switch(string[3] | 0x20) {
                case 'a':
                    return E_area;
                }
            }
        }
        break;
    case 'b':
        switch(string[1] | 0x20) {
        case 'a':
            switch(string[2] | 0x20) {
            case 's':
                switch(string[3] | 0x20) {
                case 'e':
                    return E_base;
                }
            }
            break;
        case 'o':
            switch(string[2] | 0x20) {
            case 'd':
                switch(string[3] | 0x20) {
                case 'y':
                    return E_body;
                }
            }
        }
        break;
    case 'c':
        switch(string[1] | 0x20) {
        case 'i':
            switch(string[2] | 0x20) {
            case 't':
                switch(string[3] | 0x20) {
                case 'e':
                    return E_cite;
                }
            }
            break;
        case 'o':
            switch(string[2] | 0x20) {
            case 'd':
                switch(string[3] | 0x20) {
                case 'e':
                    return E_code;
                }
            }
        }
        break;
    case 'd':
        switch(string[1] | 0x20) {
        case 'a':
            switch(string[2] | 0x20) {
            case 't':
                switch(string[3] | 0x20) {
                case 'a':
                    return E_data;
                }
            }
        }
        break;
    case 'f':
        switch(string[1] | 0x20) {
        case 'o':
            switch(string[2] | 0x20) {
            case 'r':
                switch(string[3] | 0x20) {
                case 'm':
                    return E_form;
                }
            }
        }
        break;
    case 'h':
        switch(string[1] | 0x20) {
        case 'e':
            switch(string[2] | 0x20) {
            case 'a':
                switch(string[3] | 0x20) {
                case 'd':
                    return E_head;
                }
            }
            break;
        case 't':
            switch(string[2] | 0x20) {
            case 'm':
                switch(string[3] | 0x20) {
                case 'l':
                    return E_html;
                }
            }
        }
        break;
    case 'l':
        switch(string[1] | 0x20) {
        case 'i':
            switch(string[2] | 0x20) {
            case 'n':
                switch(string[3] | 0x20) {
                case 'k':
                    return E_link;
                }
            }
        }
        break;
    case 'm':
        switch(string[1] | 0x20) {
        case 'a':
            switch(string[2] | 0x20) {
            case 'i':
                switch(string[3] | 0x20) {
                case 'n':
                    return E_main;
                }
                break;
            case 'r':
                switch(string[3] | 0x20) {
                case 'k':
                    return E_mark;
                }
            }
            break;
        case 'e':
            switch(string[2] | 0x20) {
            case 'n':
                switch(string[3] | 0x20) {
                case 'u':
                    return E_menu;
                }
                break;
            case 't':
                switch(string[3] | 0x20) {
                case 'a':
                    return E_meta;
                }
            }
        }
        break;
    case 'r':
        switch(string[1] | 0x20) {
        case 'u':
            switch(string[2] | 0x20) {
            case 'b':
                switch(string[3] | 0x20) {
                case 'y':
                    return E_ruby;
                }
            }
        }
        break;
    case 's':
        switch(string[1] | 0x20) {
        case 'a':
            switch(string[2] | 0x20) {
            case 'm':
                switch(string[3] | 0x20) {
                case 'p':
                    return E_samp;
                }
            }
            break;
        case 'p':
            switch(string[2] | 0x20) {
            case 'a':
                switch(string[3] | 0x20) {
                case 'n':
                    return E_span;
                }
            }
        }
        break;
    case 't':
        switch(string[1] | 0x20) {
        case 'i':
            switch(string[2] | 0x20) {
            case 'm':
                switch(string[3] | 0x20) {
                case 'e':
                    return E_time;
                }
            }
        }
    }
    return E_Unknown;
}
static enum Element lookup_element5(const char *string)
{
    switch(string[0] | 0x20) {
    case 'a':
        switch(string[1] | 0x20) {
        case 's':
            switch(string[2] | 0x20) {
            case 'i':
                switch(string[3] | 0x20) {
                case 'd':
                    switch(string[4] | 0x20) {
                    case 'e':
                        return E_aside;
                    }
                }
            }
            break;
        case 'u':
            switch(string[2] | 0x20) {
            case 'd':
                switch(string[3] | 0x20) {
                case 'i':
                    switch(string[4] | 0x20) {
                    case 'o':
                        return E_audio;
                    }
                }
            }
        }
        break;
    case 'e':
        switch(string[1] | 0x20) {
        case 'm':
            switch(string[2] | 0x20) {
            case 'b':
                switch(string[3] | 0x20) {
                case 'e':
                    switch(string[4] | 0x20) {
                    case 'd':
                        return E_embed;
                    }
                }
            }
        }
        break;
    case 'i':
        switch(string[1] | 0x20) {
        case 'n':
            switch(string[2] | 0x20) {
            case 'p':
                switch(string[3] | 0x20) {
                case 'u':
                    switch(string[4] | 0x20) {
                    case 't':
                        return E_input;
                    }
                }
            }
        }
        break;
    case 'l':
        switch(string[1] | 0x20) {
        case 'a':
            switch(string[2] | 0x20) {
            case 'b':
                switch(string[3] | 0x20) {
                case 'e':
                    switch(string[4] | 0x20) {
                    case 'l':
                        return E_label;
                    }
                }
            }
        }
        break;
    case 'm':
        switch(string[1] | 0x20) {
        case 'e':
            switch(string[2] | 0x20) {
            case 't':
                switch(string[3] | 0x20) {
                case 'e':
                    switch(string[4] | 0x20) {
                    case 'r':
                        return E_meter;
                    }
                }
            }
        }
        break;
    case 'p':
        switch(string[1] | 0x20) {
        case 'a':
            switch(string[2] | 0x20) {
            case 'r':
                switch(string[3] | 0x20) {
                case 'a':
                    switch(string[4] | 0x20) {
                    case 'm':
                        return E_param;
                    }
                }
            }
        }
        break;
    case 's':
        switch(string[1] | 0x20) {
        case 'm':
            switch(string[2] | 0x20) {
            case 'a':
                switch(string[3] | 0x20) {
                case 'l':
                    switch(string[4] | 0x20) {
                    case 'l':
                        return E_small;
                    }
                }
            }
            break;
        case 't':
            switch(string[2] | 0x20) {
            case 'y':
                switch(string[3] | 0x20) {
                case 'l':
                    switch(string[4] | 0x20) {
                    case 'e':
                        return E_style;
                    }
                }
            }
        }
        break;
    case 't':
        switch(string[1] | 0x20) {
        case 'a':
            switch(string[2] | 0x20) {
            case 'b':
                switch(string[3] | 0x20) {
                case 'l':
                    switch(string[4] | 0x20) {
                    case 'e':
                        return E_table;
                    }
                }
            }
            break;
        case 'b':
            switch(string[2] | 0x20) {
            case 'o':
                switch(string[3] | 0x20) {
                case 'd':
                    switch(string[4] | 0x20) {
                    case 'y':
                        return E_tbody;
                    }
                }
            }
            break;
        case 'f':
            switch(string[2] | 0x20) {
            case 'o':
                switch(string[3] | 0x20) {
                case 'o':
                    switch(string[4] | 0x20) {
                    case 't':
                        return E_tfoot;
                    }
                }
            }
            break;
        case 'h':
            switch(string[2] | 0x20) {
            case 'e':
                switch(string[3] | 0x20) {
                case 'a':
                    switch(string[4] | 0x20) {
                    case 'd':
                        return E_thead;
                    }
                }
            }
            break;
        case 'i':
            switch(string[2] | 0x20) {
            case 't':
                switch(string[3] | 0x20) {
                case 'l':
                    switch(string[4] | 0x20) {
                    case 'e':
                        return E_title;
                    }
                }
            }
            break;
        case 'r':
            switch(string[2] | 0x20) {
            case 'a':
                switch(string[3] | 0x20) {
                case 'c':
                    switch(string[4] | 0x20) {
                    case 'k':
                        return E_track;
                    }
                }
            }
        }
        break;
    case 'v':
        switch(string[1] | 0x20) {
        case 'i':
            switch(string[2] | 0x20) {
            case 'd':
                switch(string[3] | 0x20) {
                case 'e':
                    switch(string[4] | 0x20) {
                    case 'o':
                        return E_video;
                    }
                }
            }
        }
    }
    return E_Unknown;
}
static enum Element lookup_element6(const char *string)
{
    switch(string[0] | 0x20) {
    case 'b':
        switch(string[1] | 0x20) {
        case 'u':
            switch(string[2] | 0x20) {
            case 't':
                switch(string[3] | 0x20) {
                case 't':
                    switch(string[4] | 0x20) {
                    case 'o':
                        switch(string[5] | 0x20) {
                        case 'n':
                            return E_button;
                        }
                    }
                }
            }
        }
        break;
    case 'c':
        switch(string[1] | 0x20) {
        case 'a':
            switch(string[2] | 0x20) {
            case 'n':
                switch(string[3] | 0x20) {
                case 'v':
                    switch(string[4] | 0x20) {
                    case 'a':
                        switch(string[5] | 0x20) {
                        case 's':
                            return E_canvas;
                        }
                    }
                }
            }
        }
        break;
    case 'd':
        switch(string[1] | 0x20) {
        case 'i':
            switch(string[2] | 0x20) {
            case 'a':
                switch(string[3] | 0x20) {
                case 'l':
                    switch(string[4] | 0x20) {
                    case 'o':
                        switch(string[5] | 0x20) {
                        case 'g':
                            return E_dialog;
                        }
                    }
                }
            }
        }
        break;
    case 'f':
        switch(string[1] | 0x20) {
        case 'i':
            switch(string[2] | 0x20) {
            case 'g':
                switch(string[3] | 0x20) {
                case 'u':
                    switch(string[4] | 0x20) {
                    case 'r':
                        switch(string[5] | 0x20) {
                        case 'e':
                            return E_figure;
                        }
                    }
                }
            }
            break;
        case 'o':
            switch(string[2] | 0x20) {
            case 'o':
                switch(string[3] | 0x20) {
                case 't':
                    switch(string[4] | 0x20) {
                    case 'e':
                        switch(string[5] | 0x20) {
                        case 'r':
                            return E_footer;
                        }
                    }
                }
            }
        }
        break;
    case 'h':
        switch(string[1] | 0x20) {
        case 'e':
            switch(string[2] | 0x20) {
            case 'a':
                switch(string[3] | 0x20) {
                case 'd':
                    switch(string[4] | 0x20) {
                    case 'e':
                        switch(string[5] | 0x20) {
                        case 'r':
                            return E_header;
                        }
                    }
                }
            }
            break;
        case 'g':
            switch(string[2] | 0x20) {
            case 'r':
                switch(string[3] | 0x20) {
                case 'o':
                    switch(string[4] | 0x20) {
                    case 'u':
                        switch(string[5] | 0x20) {
                        case 'p':
                            return E_hgroup;
                        }
                    }
                }
            }
        }
        break;
    case 'i':
        switch(string[1] | 0x20) {
        case 'f':
            switch(string[2] | 0x20) {
            case 'r':
                switch(string[3] | 0x20) {
                case 'a':
                    switch(string[4] | 0x20) {
                    case 'm':
                        switch(string[5] | 0x20) {
                        case 'e':
                            return E_iframe;
                        }
                    }
                }
            }
        }
        break;
    case 'k':
        switch(string[1] | 0x20) {
        case 'e':
            switch(string[2] | 0x20) {
            case 'y':
                switch(string[3] | 0x20) {
                case 'g':
                    switch(string[4] | 0x20) {
                    case 'e':
                        switch(string[5] | 0x20) {
                        case 'n':
                            return E_keygen;
                        }
                    }
                }
            }
        }
        break;
    case 'l':
        switch(string[1] | 0x20) {
        case 'e':
            switch(string[2] | 0x20) {
            case 'g':
                switch(string[3] | 0x20) {
                case 'e':
                    switch(string[4] | 0x20) {
                    case 'n':
                        switch(string[5] | 0x20) {
                        case 'd':
                            return E_legend;
                        }
                    }
                }
            }
        }
        break;
    case 'o':
        switch(string[1] | 0x20) {
        case 'b':
            switch(string[2] | 0x20) {
            case 'j':
                switch(string[3] | 0x20) {
                case 'e':
                    switch(string[4] | 0x20) {
                    case 'c':
                        switch(string[5] | 0x20) {
                        case 't':
                            return E_object;
                        }
                    }
                }
            }
            break;
        case 'p':
            switch(string[2] | 0x20) {
            case 't':
                switch(string[3] | 0x20) {
                case 'i':
                    switch(string[4] | 0x20) {
                    case 'o':
                        switch(string[5] | 0x20) {
                        case 'n':
                            return E_option;
                        }
                    }
                }
            }
            break;
        case 'u':
            switch(string[2] | 0x20) {
            case 't':
                switch(string[3] | 0x20) {
                case 'p':
                    switch(string[4] | 0x20) {
                    case 'u':
                        switch(string[5] | 0x20) {
                        case 't':
                            return E_output;
                        }
                    }
                }
            }
        }
        break;
    case 's':
        switch(string[1] | 0x20) {
        case 'c':
            switch(string[2] | 0x20) {
            case 'r':
                switch(string[3] | 0x20) {
                case 'i':
                    switch(string[4] | 0x20) {
                    case 'p':
                        switch(string[5] | 0x20) {
                        case 't':
                            return E_script;
                        }
                    }
                }
            }
            break;
        case 'e':
            switch(string[2] | 0x20) {
            case 'l':
                switch(string[3] | 0x20) {
                case 'e':
                    switch(string[4] | 0x20) {
                    case 'c':
                        switch(string[5] | 0x20) {
                        case 't':
                            return E_select;
                        }
                    }
                }
            }
            break;
        case 'o':
            switch(string[2] | 0x20) {
            case 'u':
                switch(string[3] | 0x20) {
                case 'r':
                    switch(string[4] | 0x20) {
                    case 'c':
                        switch(string[5] | 0x20) {
                        case 'e':
                            return E_source;
                        }
                    }
                }
            }
            break;
        case 't':
            switch(string[2] | 0x20) {
            case 'r':
                switch(string[3] | 0x20) {
                case 'o':
                    switch(string[4] | 0x20) {
                    case 'n':
                        switch(string[5] | 0x20) {
                        case 'g':
                            return E_strong;
                        }
                    }
                }
            }
        }
    }
    return E_Unknown;
}
static enum Element lookup_element7(const char *string)
{
    switch(string[0] | 0x20) {
    case 'a':
        switch(string[1] | 0x20) {
        case 'd':
            switch(string[2] | 0x20) {
            case 'd':
                switch(string[3] | 0x20) {
                case 'r':
                    switch(string[4] | 0x20) {
                    case 'e':
                        switch(string[5] | 0x20) {
                        case 's':
                            switch(string[6] | 0x20) {
                            case 's':
                                return E_address;
                            }
                        }
                    }
                }
            }
            break;
        case 'r':
            switch(string[2] | 0x20) {
            case 't':
                switch(string[3] | 0x20) {
                case 'i':
                    switch(string[4] | 0x20) {
                    case 'c':
                        switch(string[5] | 0x20) {
                        case 'l':
                            switch(string[6] | 0x20) {
                            case 'e':
                                return E_article;
                            }
                        }
                    }
                }
            }
        }
        break;
    case 'c':
        switch(string[1] | 0x20) {
        case 'a':
            switch(string[2] | 0x20) {
            case 'p':
                switch(string[3] | 0x20) {
                case 't':
                    switch(string[4] | 0x20) {
                    case 'i':
                        switch(string[5] | 0x20) {
                        case 'o':
                            switch(string[6] | 0x20) {
                            case 'n':
                                return E_caption;
                            }
                        }
                    }
                }
            }
        }
        break;
    case 'd':
        switch(string[1] | 0x20) {
        case 'e':
            switch(string[2] | 0x20) {
            case 't':
                switch(string[3] | 0x20) {
                case 'a':
                    switch(string[4] | 0x20) {
                    case 'i':
                        switch(string[5] | 0x20) {
                        case 'l':
                            switch(string[6] | 0x20) {
                            case 's':
                                return E_details;
                            }
                        }
                    }
                }
            }
        }
        break;
    case 'p':
        switch(string[1] | 0x20) {
        case 'i':
            switch(string[2] | 0x20) {
            case 'c':
                switch(string[3] | 0x20) {
                case 't':
                    switch(string[4] | 0x20) {
                    case 'u':
                        switch(string[5] | 0x20) {
                        case 'r':
                            switch(string[6] | 0x20) {
                            case 'e':
                                return E_picture;
                            }
                        }
                    }
                }
            }
        }
        break;
    case 's':
        switch(string[1] | 0x20) {
        case 'e':
            switch(string[2] | 0x20) {
            case 'c':
                switch(string[3] | 0x20) {
                case 't':
                    switch(string[4] | 0x20) {
                    case 'i':
                        switch(string[5] | 0x20) {
                        case 'o':
                            switch(string[6] | 0x20) {
                            case 'n':
                                return E_section;
                            }
                        }
                    }
                }
            }
            break;
        case 'u':
            switch(string[2] | 0x20) {
            case 'm':
                switch(string[3] | 0x20) {
                case 'm':
                    switch(string[4] | 0x20) {
                    case 'a':
                        switch(string[5] | 0x20) {
                        case 'r':
                            switch(string[6] | 0x20) {
                            case 'y':
                                return E_summary;
                            }
                        }
                    }
                }
            }
        }
    }
    return E_Unknown;
}
static enum Element lookup_element8(const char *string)
{
    switch(string[0] | 0x20) {
    case 'c':
        switch(string[1] | 0x20) {
        case 'o':
            switch(string[2] | 0x20) {
            case 'l':
                switch(string[3] | 0x20) {
                case 'g':
                    switch(string[4] | 0x20) {
                    case 'r':
                        switch(string[5] | 0x20) {
                        case 'o':
                            switch(string[6] | 0x20) {
                            case 'u':
                                switch(string[7] | 0x20) {
                                case 'p':
                                    return E_colgroup;
                                }
                            }
                        }
                    }
                }
            }
        }
        break;
    case 'd':
        switch(string[1] | 0x20) {
        case 'a':
            switch(string[2] | 0x20) {
            case 't':
                switch(string[3] | 0x20) {
                case 'a':
                    switch(string[4] | 0x20) {
                    case 'l':
                        switch(string[5] | 0x20) {
                        case 'i':
                            switch(string[6] | 0x20) {
                            case 's':
                                switch(string[7] | 0x20) {
                                case 't':
                                    return E_datalist;
                                }
                            }
                        }
                    }
                }
            }
        }
        break;
    case 'f':
        switch(string[1] | 0x20) {
        case 'i':
            switch(string[2] | 0x20) {
            case 'e':
                switch(string[3] | 0x20) {
                case 'l':
                    switch(string[4] | 0x20) {
                    case 'd':
                        switch(string[5] | 0x20) {
                        case 's':
                            switch(string[6] | 0x20) {
                            case 'e':
                                switch(string[7] | 0x20) {
                                case 't':
                                    return E_fieldset;
                                }
                            }
                        }
                    }
                }
            }
        }
        break;
    case 'm':
        switch(string[1] | 0x20) {
        case 'e':
            switch(string[2] | 0x20) {
            case 'n':
                switch(string[3] | 0x20) {
                case 'u':
                    switch(string[4] | 0x20) {
                    case 'i':
                        switch(string[5] | 0x20) {
                        case 't':
                            switch(string[6] | 0x20) {
                            case 'e':
                                switch(string[7] | 0x20) {
                                case 'm':
                                    return E_menuitem;
                                }
                            }
                        }
                    }
                }
            }
        }
        break;
    case 'n':
        switch(string[1] | 0x20) {
        case 'o':
            switch(string[2] | 0x20) {
            case 's':
                switch(string[3] | 0x20) {
                case 'c':
                    switch(string[4] | 0x20) {
                    case 'r':
                        switch(string[5] | 0x20) {
                        case 'i':
                            switch(string[6] | 0x20) {
                            case 'p':
                                switch(string[7] | 0x20) {
                                case 't':
                                    return E_noscript;
                                }
                            }
                        }
                    }
                }
            }
        }
        break;
    case 'o':
        switch(string[1] | 0x20) {
        case 'p':
            switch(string[2] | 0x20) {
            case 't':
                switch(string[3] | 0x20) {
                case 'g':
                    switch(string[4] | 0x20) {
                    case 'r':
                        switch(string[5] | 0x20) {
                        case 'o':
                            switch(string[6] | 0x20) {
                            case 'u':
                                switch(string[7] | 0x20) {
                                case 'p':
                                    return E_optgroup;
                                }
                            }
                        }
                    }
                }
            }
        }
        break;
    case 'p':
        switch(string[1] | 0x20) {
        case 'r':
            switch(string[2] | 0x20) {
            case 'o':
                switch(string[3] | 0x20) {
                case 'g':
                    switch(string[4] | 0x20) {
                    case 'r':
                        switch(string[5] | 0x20) {
                        case 'e':
                            switch(string[6] | 0x20) {
                            case 's':
                                switch(string[7] | 0x20) {
                                case 's':
                                    return E_progress;
                                }
                            }
                        }
                    }
                }
            }
        }
        break;
    case 't':
        switch(string[1] | 0x20) {
        case 'e':
            switch(string[2] | 0x20) {
            case 'm':
                switch(string[3] | 0x20) {
                case 'p':
                    switch(string[4] | 0x20) {
                    case 'l':
                        switch(string[5] | 0x20) {
                        case 'a':
                            switch(string[6] | 0x20) {
                            case 't':
                                switch(string[7] | 0x20) {
                                case 'e':
                                    return E_template;
                                }
                            }
                        }
                    }
                }
                break;
            case 'x':
                switch(string[3] | 0x20) {
                case 't':
                    switch(string[4] | 0x20) {
                    case 'a':
                        switch(string[5] | 0x20) {
                        case 'r':
                            switch(string[6] | 0x20) {
                            case 'e':
                                switch(string[7] | 0x20) {
                                case 'a':
                                    return E_textarea;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return E_Unknown;
}
static enum Element lookup_element10(const char *string)
{
    switch(string[0] | 0x20) {
    case 'b':
        switch(string[1] | 0x20) {
        case 'l':
            switch(string[2] | 0x20) {
            case 'o':
                switch(string[3] | 0x20) {
                case 'c':
                    switch(string[4] | 0x20) {
                    case 'k':
                        switch(string[5] | 0x20) {
                        case 'q':
                            switch(string[6] | 0x20) {
                            case 'u':
                                switch(string[7] | 0x20) {
                                case 'o':
                                    switch(string[8] | 0x20) {
                                    case 't':
                                        switch(string[9] | 0x20) {
                                        case 'e':
                                            return E_blockquote;
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
        switch(string[1] | 0x20) {
        case 'i':
            switch(string[2] | 0x20) {
            case 'g':
                switch(string[3] | 0x20) {
                case 'c':
                    switch(string[4] | 0x20) {
                    case 'a':
                        switch(string[5] | 0x20) {
                        case 'p':
                            switch(string[6] | 0x20) {
                            case 't':
                                switch(string[7] | 0x20) {
                                case 'i':
                                    switch(string[8] | 0x20) {
                                    case 'o':
                                        switch(string[9] | 0x20) {
                                        case 'n':
                                            return E_figcaption;
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
    return E_Unknown;
}
#endif /* TRIE_HASH_MULTI_BYTE */
static enum Element lookup_element(const char *string, size_t length)
{
    switch (length) {
    case 1:
        return lookup_element1(string);
    case 2:
        return lookup_element2(string);
    case 3:
        return lookup_element3(string);
    case 4:
        return lookup_element4(string);
    case 5:
        return lookup_element5(string);
    case 6:
        return lookup_element6(string);
    case 7:
        return lookup_element7(string);
    case 8:
        return lookup_element8(string);
    case 10:
        return lookup_element10(string);
    default:
        return E_Unknown;
    }
}
#endif                       /* TRIE_HASH_lookup_element */
