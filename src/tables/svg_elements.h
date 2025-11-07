#ifndef TRIE_HASH_lookup_svg_element
#define TRIE_HASH_lookup_svg_element
#include <stddef.h>
#include <stdint.h>
enum SvgElement {
    SE_a = 1,
    SE_animate = 2,
    SE_animatemotion = 3,
    SE_animatetransform = 4,
    SE_circle = 5,
    SE_clippath = 6,
    SE_defs = 7,
    SE_desc = 8,
    SE_ellipse = 9,
    SE_feblend = 10,
    SE_fecolormatrix = 11,
    SE_fecomponenttransfer = 12,
    SE_fecomposite = 13,
    SE_feconvolvematrix = 14,
    SE_fediffuselighting = 15,
    SE_fedisplacementmap = 16,
    SE_fedistantlight = 17,
    SE_fedropshadow = 18,
    SE_feflood = 19,
    SE_fefunca = 20,
    SE_fefuncb = 21,
    SE_fefuncg = 22,
    SE_fefuncr = 23,
    SE_fegaussianblur = 24,
    SE_feimage = 25,
    SE_femerge = 26,
    SE_femergenode = 27,
    SE_femorphology = 28,
    SE_feoffset = 29,
    SE_fepointlight = 30,
    SE_fespecularlighting = 31,
    SE_fespotlight = 32,
    SE_fetile = 33,
    SE_feturbulence = 34,
    SE_filter = 35,
    SE_foreignobject = 36,
    SE_g = 37,
    SE_image = 38,
    SE_line = 39,
    SE_lineargradient = 40,
    SE_marker = 41,
    SE_mask = 42,
    SE_metadata = 43,
    SE_mpath = 44,
    SE_path = 45,
    SE_pattern = 46,
    SE_polygon = 47,
    SE_polyline = 48,
    SE_radialgradient = 49,
    SE_rect = 50,
    SE_set = 52,
    SE_svg = 55,
    SE_script = 51,
    SE_stop = 53,
    SE_style = 54,
    SE_switch = 56,
    SE_symbol = 57,
    SE_text = 58,
    SE_textpath = 59,
    SE_title = 60,
    SE_tspan = 61,
    SE_use = 62,
    SE_view = 63,
    SE_Unknown = 0,
};
static enum SvgElement lookup_svg_element(const char *string, size_t length);
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
static enum SvgElement lookup_svg_element1(const char *string)
{
    switch(string[0]) {
    case 0| onechar('a', 0, 8):
        return SE_a;
        break;
    case 0| onechar('g', 0, 8):
        return SE_g;
    }
    return SE_Unknown;
}
static enum SvgElement lookup_svg_element3(const char *string)
{
    switch(string[0]) {
    case 0| onechar('s', 0, 8):
        switch(string[1]) {
        case 0| onechar('e', 0, 8):
            switch(string[2]) {
            case 0| onechar('t', 0, 8):
                return SE_set;
            }
            break;
        case 0| onechar('v', 0, 8):
            switch(string[2]) {
            case 0| onechar('g', 0, 8):
                return SE_svg;
            }
        }
        break;
    case 0| onechar('u', 0, 8):
        switch(string[1]) {
        case 0| onechar('s', 0, 8):
            switch(string[2]) {
            case 0| onechar('e', 0, 8):
                return SE_use;
            }
        }
    }
    return SE_Unknown;
}
static enum SvgElement lookup_svg_element4(const char *string)
{
    switch(*((triehash_uu32*) &string[0])) {
    case 0| onechar('d', 0, 32)| onechar('e', 8, 32)| onechar('f', 16, 32)| onechar('s', 24, 32):
        return SE_defs;
        break;
    case 0| onechar('d', 0, 32)| onechar('e', 8, 32)| onechar('s', 16, 32)| onechar('c', 24, 32):
        return SE_desc;
        break;
    case 0| onechar('l', 0, 32)| onechar('i', 8, 32)| onechar('n', 16, 32)| onechar('e', 24, 32):
        return SE_line;
        break;
    case 0| onechar('m', 0, 32)| onechar('a', 8, 32)| onechar('s', 16, 32)| onechar('k', 24, 32):
        return SE_mask;
        break;
    case 0| onechar('p', 0, 32)| onechar('a', 8, 32)| onechar('t', 16, 32)| onechar('h', 24, 32):
        return SE_path;
        break;
    case 0| onechar('r', 0, 32)| onechar('e', 8, 32)| onechar('c', 16, 32)| onechar('t', 24, 32):
        return SE_rect;
        break;
    case 0| onechar('s', 0, 32)| onechar('t', 8, 32)| onechar('o', 16, 32)| onechar('p', 24, 32):
        return SE_stop;
        break;
    case 0| onechar('t', 0, 32)| onechar('e', 8, 32)| onechar('x', 16, 32)| onechar('t', 24, 32):
        return SE_text;
        break;
    case 0| onechar('v', 0, 32)| onechar('i', 8, 32)| onechar('e', 16, 32)| onechar('w', 24, 32):
        return SE_view;
    }
    return SE_Unknown;
}
static enum SvgElement lookup_svg_element5(const char *string)
{
    switch(*((triehash_uu32*) &string[0])) {
    case 0| onechar('i', 0, 32)| onechar('m', 8, 32)| onechar('a', 16, 32)| onechar('g', 24, 32):
        switch(string[4]) {
        case 0| onechar('e', 0, 8):
            return SE_image;
        }
        break;
    case 0| onechar('m', 0, 32)| onechar('p', 8, 32)| onechar('a', 16, 32)| onechar('t', 24, 32):
        switch(string[4]) {
        case 0| onechar('h', 0, 8):
            return SE_mpath;
        }
        break;
    case 0| onechar('s', 0, 32)| onechar('t', 8, 32)| onechar('y', 16, 32)| onechar('l', 24, 32):
        switch(string[4]) {
        case 0| onechar('e', 0, 8):
            return SE_style;
        }
        break;
    case 0| onechar('t', 0, 32)| onechar('i', 8, 32)| onechar('t', 16, 32)| onechar('l', 24, 32):
        switch(string[4]) {
        case 0| onechar('e', 0, 8):
            return SE_title;
        }
        break;
    case 0| onechar('t', 0, 32)| onechar('s', 8, 32)| onechar('p', 16, 32)| onechar('a', 24, 32):
        switch(string[4]) {
        case 0| onechar('n', 0, 8):
            return SE_tspan;
        }
    }
    return SE_Unknown;
}
static enum SvgElement lookup_svg_element6(const char *string)
{
    switch(*((triehash_uu32*) &string[0])) {
    case 0| onechar('c', 0, 32)| onechar('i', 8, 32)| onechar('r', 16, 32)| onechar('c', 24, 32):
        switch(string[4]) {
        case 0| onechar('l', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return SE_circle;
            }
        }
        break;
    case 0| onechar('f', 0, 32)| onechar('e', 8, 32)| onechar('t', 16, 32)| onechar('i', 24, 32):
        switch(string[4]) {
        case 0| onechar('l', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return SE_fetile;
            }
        }
        break;
    case 0| onechar('f', 0, 32)| onechar('i', 8, 32)| onechar('l', 16, 32)| onechar('t', 24, 32):
        switch(string[4]) {
        case 0| onechar('e', 0, 8):
            switch(string[5]) {
            case 0| onechar('r', 0, 8):
                return SE_filter;
            }
        }
        break;
    case 0| onechar('m', 0, 32)| onechar('a', 8, 32)| onechar('r', 16, 32)| onechar('k', 24, 32):
        switch(string[4]) {
        case 0| onechar('e', 0, 8):
            switch(string[5]) {
            case 0| onechar('r', 0, 8):
                return SE_marker;
            }
        }
        break;
    case 0| onechar('s', 0, 32)| onechar('c', 8, 32)| onechar('r', 16, 32)| onechar('i', 24, 32):
        switch(string[4]) {
        case 0| onechar('p', 0, 8):
            switch(string[5]) {
            case 0| onechar('t', 0, 8):
                return SE_script;
            }
        }
        break;
    case 0| onechar('s', 0, 32)| onechar('w', 8, 32)| onechar('i', 16, 32)| onechar('t', 24, 32):
        switch(string[4]) {
        case 0| onechar('c', 0, 8):
            switch(string[5]) {
            case 0| onechar('h', 0, 8):
                return SE_switch;
            }
        }
        break;
    case 0| onechar('s', 0, 32)| onechar('y', 8, 32)| onechar('m', 16, 32)| onechar('b', 24, 32):
        switch(string[4]) {
        case 0| onechar('o', 0, 8):
            switch(string[5]) {
            case 0| onechar('l', 0, 8):
                return SE_symbol;
            }
        }
    }
    return SE_Unknown;
}
static enum SvgElement lookup_svg_element7(const char *string)
{
    switch(*((triehash_uu32*) &string[0])) {
    case 0| onechar('a', 0, 32)| onechar('n', 8, 32)| onechar('i', 16, 32)| onechar('m', 24, 32):
        switch(string[4]) {
        case 0| onechar('a', 0, 8):
            switch(string[5]) {
            case 0| onechar('t', 0, 8):
                switch(string[6]) {
                case 0| onechar('e', 0, 8):
                    return SE_animate;
                }
            }
        }
        break;
    case 0| onechar('e', 0, 32)| onechar('l', 8, 32)| onechar('l', 16, 32)| onechar('i', 24, 32):
        switch(string[4]) {
        case 0| onechar('p', 0, 8):
            switch(string[5]) {
            case 0| onechar('s', 0, 8):
                switch(string[6]) {
                case 0| onechar('e', 0, 8):
                    return SE_ellipse;
                }
            }
        }
        break;
    case 0| onechar('f', 0, 32)| onechar('e', 8, 32)| onechar('b', 16, 32)| onechar('l', 24, 32):
        switch(string[4]) {
        case 0| onechar('e', 0, 8):
            switch(string[5]) {
            case 0| onechar('n', 0, 8):
                switch(string[6]) {
                case 0| onechar('d', 0, 8):
                    return SE_feblend;
                }
            }
        }
        break;
    case 0| onechar('f', 0, 32)| onechar('e', 8, 32)| onechar('f', 16, 32)| onechar('l', 24, 32):
        switch(string[4]) {
        case 0| onechar('o', 0, 8):
            switch(string[5]) {
            case 0| onechar('o', 0, 8):
                switch(string[6]) {
                case 0| onechar('d', 0, 8):
                    return SE_feflood;
                }
            }
        }
        break;
    case 0| onechar('f', 0, 32)| onechar('e', 8, 32)| onechar('f', 16, 32)| onechar('u', 24, 32):
        switch(string[4]) {
        case 0| onechar('n', 0, 8):
            switch(string[5]) {
            case 0| onechar('c', 0, 8):
                switch(string[6]) {
                case 0| onechar('a', 0, 8):
                    return SE_fefunca;
                    break;
                case 0| onechar('b', 0, 8):
                    return SE_fefuncb;
                    break;
                case 0| onechar('g', 0, 8):
                    return SE_fefuncg;
                    break;
                case 0| onechar('r', 0, 8):
                    return SE_fefuncr;
                }
            }
        }
        break;
    case 0| onechar('f', 0, 32)| onechar('e', 8, 32)| onechar('i', 16, 32)| onechar('m', 24, 32):
        switch(string[4]) {
        case 0| onechar('a', 0, 8):
            switch(string[5]) {
            case 0| onechar('g', 0, 8):
                switch(string[6]) {
                case 0| onechar('e', 0, 8):
                    return SE_feimage;
                }
            }
        }
        break;
    case 0| onechar('f', 0, 32)| onechar('e', 8, 32)| onechar('m', 16, 32)| onechar('e', 24, 32):
        switch(string[4]) {
        case 0| onechar('r', 0, 8):
            switch(string[5]) {
            case 0| onechar('g', 0, 8):
                switch(string[6]) {
                case 0| onechar('e', 0, 8):
                    return SE_femerge;
                }
            }
        }
        break;
    case 0| onechar('p', 0, 32)| onechar('a', 8, 32)| onechar('t', 16, 32)| onechar('t', 24, 32):
        switch(string[4]) {
        case 0| onechar('e', 0, 8):
            switch(string[5]) {
            case 0| onechar('r', 0, 8):
                switch(string[6]) {
                case 0| onechar('n', 0, 8):
                    return SE_pattern;
                }
            }
        }
        break;
    case 0| onechar('p', 0, 32)| onechar('o', 8, 32)| onechar('l', 16, 32)| onechar('y', 24, 32):
        switch(string[4]) {
        case 0| onechar('g', 0, 8):
            switch(string[5]) {
            case 0| onechar('o', 0, 8):
                switch(string[6]) {
                case 0| onechar('n', 0, 8):
                    return SE_polygon;
                }
            }
        }
    }
    return SE_Unknown;
}
static enum SvgElement lookup_svg_element8(const char *string)
{
    switch(*((triehash_uu64*) &string[0])) {
    case 0| onechar('c', 0, 64)| onechar('l', 8, 64)| onechar('i', 16, 64)| onechar('p', 24, 64)| onechar('p', 32, 64)| onechar('a', 40, 64)| onechar('t', 48, 64)| onechar('h', 56, 64):
        return SE_clippath;
        break;
    case 0| onechar('f', 0, 64)| onechar('e', 8, 64)| onechar('o', 16, 64)| onechar('f', 24, 64)| onechar('f', 32, 64)| onechar('s', 40, 64)| onechar('e', 48, 64)| onechar('t', 56, 64):
        return SE_feoffset;
        break;
    case 0| onechar('m', 0, 64)| onechar('e', 8, 64)| onechar('t', 16, 64)| onechar('a', 24, 64)| onechar('d', 32, 64)| onechar('a', 40, 64)| onechar('t', 48, 64)| onechar('a', 56, 64):
        return SE_metadata;
        break;
    case 0| onechar('p', 0, 64)| onechar('o', 8, 64)| onechar('l', 16, 64)| onechar('y', 24, 64)| onechar('l', 32, 64)| onechar('i', 40, 64)| onechar('n', 48, 64)| onechar('e', 56, 64):
        return SE_polyline;
        break;
    case 0| onechar('t', 0, 64)| onechar('e', 8, 64)| onechar('x', 16, 64)| onechar('t', 24, 64)| onechar('p', 32, 64)| onechar('a', 40, 64)| onechar('t', 48, 64)| onechar('h', 56, 64):
        return SE_textpath;
    }
    return SE_Unknown;
}
static enum SvgElement lookup_svg_element11(const char *string)
{
    switch(*((triehash_uu64*) &string[0])) {
    case 0| onechar('f', 0, 64)| onechar('e', 8, 64)| onechar('c', 16, 64)| onechar('o', 24, 64)| onechar('m', 32, 64)| onechar('p', 40, 64)| onechar('o', 48, 64)| onechar('s', 56, 64):
        switch(string[8]) {
        case 0| onechar('i', 0, 8):
            switch(string[9]) {
            case 0| onechar('t', 0, 8):
                switch(string[10]) {
                case 0| onechar('e', 0, 8):
                    return SE_fecomposite;
                }
            }
        }
        break;
    case 0| onechar('f', 0, 64)| onechar('e', 8, 64)| onechar('m', 16, 64)| onechar('e', 24, 64)| onechar('r', 32, 64)| onechar('g', 40, 64)| onechar('e', 48, 64)| onechar('n', 56, 64):
        switch(string[8]) {
        case 0| onechar('o', 0, 8):
            switch(string[9]) {
            case 0| onechar('d', 0, 8):
                switch(string[10]) {
                case 0| onechar('e', 0, 8):
                    return SE_femergenode;
                }
            }
        }
        break;
    case 0| onechar('f', 0, 64)| onechar('e', 8, 64)| onechar('s', 16, 64)| onechar('p', 24, 64)| onechar('o', 32, 64)| onechar('t', 40, 64)| onechar('l', 48, 64)| onechar('i', 56, 64):
        switch(string[8]) {
        case 0| onechar('g', 0, 8):
            switch(string[9]) {
            case 0| onechar('h', 0, 8):
                switch(string[10]) {
                case 0| onechar('t', 0, 8):
                    return SE_fespotlight;
                }
            }
        }
    }
    return SE_Unknown;
}
static enum SvgElement lookup_svg_element12(const char *string)
{
    switch(*((triehash_uu64*) &string[0])) {
    case 0| onechar('f', 0, 64)| onechar('e', 8, 64)| onechar('d', 16, 64)| onechar('r', 24, 64)| onechar('o', 32, 64)| onechar('p', 40, 64)| onechar('s', 48, 64)| onechar('h', 56, 64):
        switch(*((triehash_uu32*) &string[8])) {
        case 0| onechar('a', 0, 32)| onechar('d', 8, 32)| onechar('o', 16, 32)| onechar('w', 24, 32):
            return SE_fedropshadow;
        }
        break;
    case 0| onechar('f', 0, 64)| onechar('e', 8, 64)| onechar('m', 16, 64)| onechar('o', 24, 64)| onechar('r', 32, 64)| onechar('p', 40, 64)| onechar('h', 48, 64)| onechar('o', 56, 64):
        switch(*((triehash_uu32*) &string[8])) {
        case 0| onechar('l', 0, 32)| onechar('o', 8, 32)| onechar('g', 16, 32)| onechar('y', 24, 32):
            return SE_femorphology;
        }
        break;
    case 0| onechar('f', 0, 64)| onechar('e', 8, 64)| onechar('p', 16, 64)| onechar('o', 24, 64)| onechar('i', 32, 64)| onechar('n', 40, 64)| onechar('t', 48, 64)| onechar('l', 56, 64):
        switch(*((triehash_uu32*) &string[8])) {
        case 0| onechar('i', 0, 32)| onechar('g', 8, 32)| onechar('h', 16, 32)| onechar('t', 24, 32):
            return SE_fepointlight;
        }
        break;
    case 0| onechar('f', 0, 64)| onechar('e', 8, 64)| onechar('t', 16, 64)| onechar('u', 24, 64)| onechar('r', 32, 64)| onechar('b', 40, 64)| onechar('u', 48, 64)| onechar('l', 56, 64):
        switch(*((triehash_uu32*) &string[8])) {
        case 0| onechar('e', 0, 32)| onechar('n', 8, 32)| onechar('c', 16, 32)| onechar('e', 24, 32):
            return SE_feturbulence;
        }
    }
    return SE_Unknown;
}
static enum SvgElement lookup_svg_element13(const char *string)
{
    switch(*((triehash_uu64*) &string[0])) {
    case 0| onechar('a', 0, 64)| onechar('n', 8, 64)| onechar('i', 16, 64)| onechar('m', 24, 64)| onechar('a', 32, 64)| onechar('t', 40, 64)| onechar('e', 48, 64)| onechar('m', 56, 64):
        switch(*((triehash_uu32*) &string[8])) {
        case 0| onechar('o', 0, 32)| onechar('t', 8, 32)| onechar('i', 16, 32)| onechar('o', 24, 32):
            switch(string[12]) {
            case 0| onechar('n', 0, 8):
                return SE_animatemotion;
            }
        }
        break;
    case 0| onechar('f', 0, 64)| onechar('e', 8, 64)| onechar('c', 16, 64)| onechar('o', 24, 64)| onechar('l', 32, 64)| onechar('o', 40, 64)| onechar('r', 48, 64)| onechar('m', 56, 64):
        switch(*((triehash_uu32*) &string[8])) {
        case 0| onechar('a', 0, 32)| onechar('t', 8, 32)| onechar('r', 16, 32)| onechar('i', 24, 32):
            switch(string[12]) {
            case 0| onechar('x', 0, 8):
                return SE_fecolormatrix;
            }
        }
        break;
    case 0| onechar('f', 0, 64)| onechar('o', 8, 64)| onechar('r', 16, 64)| onechar('e', 24, 64)| onechar('i', 32, 64)| onechar('g', 40, 64)| onechar('n', 48, 64)| onechar('o', 56, 64):
        switch(*((triehash_uu32*) &string[8])) {
        case 0| onechar('b', 0, 32)| onechar('j', 8, 32)| onechar('e', 16, 32)| onechar('c', 24, 32):
            switch(string[12]) {
            case 0| onechar('t', 0, 8):
                return SE_foreignobject;
            }
        }
    }
    return SE_Unknown;
}
static enum SvgElement lookup_svg_element14(const char *string)
{
    switch(*((triehash_uu64*) &string[0])) {
    case 0| onechar('f', 0, 64)| onechar('e', 8, 64)| onechar('d', 16, 64)| onechar('i', 24, 64)| onechar('s', 32, 64)| onechar('t', 40, 64)| onechar('a', 48, 64)| onechar('n', 56, 64):
        switch(*((triehash_uu32*) &string[8])) {
        case 0| onechar('t', 0, 32)| onechar('l', 8, 32)| onechar('i', 16, 32)| onechar('g', 24, 32):
            switch(string[12]) {
            case 0| onechar('h', 0, 8):
                switch(string[13]) {
                case 0| onechar('t', 0, 8):
                    return SE_fedistantlight;
                }
            }
        }
        break;
    case 0| onechar('f', 0, 64)| onechar('e', 8, 64)| onechar('g', 16, 64)| onechar('a', 24, 64)| onechar('u', 32, 64)| onechar('s', 40, 64)| onechar('s', 48, 64)| onechar('i', 56, 64):
        switch(*((triehash_uu32*) &string[8])) {
        case 0| onechar('a', 0, 32)| onechar('n', 8, 32)| onechar('b', 16, 32)| onechar('l', 24, 32):
            switch(string[12]) {
            case 0| onechar('u', 0, 8):
                switch(string[13]) {
                case 0| onechar('r', 0, 8):
                    return SE_fegaussianblur;
                }
            }
        }
        break;
    case 0| onechar('l', 0, 64)| onechar('i', 8, 64)| onechar('n', 16, 64)| onechar('e', 24, 64)| onechar('a', 32, 64)| onechar('r', 40, 64)| onechar('g', 48, 64)| onechar('r', 56, 64):
        switch(*((triehash_uu32*) &string[8])) {
        case 0| onechar('a', 0, 32)| onechar('d', 8, 32)| onechar('i', 16, 32)| onechar('e', 24, 32):
            switch(string[12]) {
            case 0| onechar('n', 0, 8):
                switch(string[13]) {
                case 0| onechar('t', 0, 8):
                    return SE_lineargradient;
                }
            }
        }
        break;
    case 0| onechar('r', 0, 64)| onechar('a', 8, 64)| onechar('d', 16, 64)| onechar('i', 24, 64)| onechar('a', 32, 64)| onechar('l', 40, 64)| onechar('g', 48, 64)| onechar('r', 56, 64):
        switch(*((triehash_uu32*) &string[8])) {
        case 0| onechar('a', 0, 32)| onechar('d', 8, 32)| onechar('i', 16, 32)| onechar('e', 24, 32):
            switch(string[12]) {
            case 0| onechar('n', 0, 8):
                switch(string[13]) {
                case 0| onechar('t', 0, 8):
                    return SE_radialgradient;
                }
            }
        }
    }
    return SE_Unknown;
}
static enum SvgElement lookup_svg_element16(const char *string)
{
    switch(*((triehash_uu64*) &string[0])) {
    case 0| onechar('a', 0, 64)| onechar('n', 8, 64)| onechar('i', 16, 64)| onechar('m', 24, 64)| onechar('a', 32, 64)| onechar('t', 40, 64)| onechar('e', 48, 64)| onechar('t', 56, 64):
        switch(*((triehash_uu64*) &string[8])) {
        case 0| onechar('r', 0, 64)| onechar('a', 8, 64)| onechar('n', 16, 64)| onechar('s', 24, 64)| onechar('f', 32, 64)| onechar('o', 40, 64)| onechar('r', 48, 64)| onechar('m', 56, 64):
            return SE_animatetransform;
        }
        break;
    case 0| onechar('f', 0, 64)| onechar('e', 8, 64)| onechar('c', 16, 64)| onechar('o', 24, 64)| onechar('n', 32, 64)| onechar('v', 40, 64)| onechar('o', 48, 64)| onechar('l', 56, 64):
        switch(*((triehash_uu64*) &string[8])) {
        case 0| onechar('v', 0, 64)| onechar('e', 8, 64)| onechar('m', 16, 64)| onechar('a', 24, 64)| onechar('t', 32, 64)| onechar('r', 40, 64)| onechar('i', 48, 64)| onechar('x', 56, 64):
            return SE_feconvolvematrix;
        }
    }
    return SE_Unknown;
}
static enum SvgElement lookup_svg_element17(const char *string)
{
    switch(*((triehash_uu64*) &string[0])) {
    case 0| onechar('f', 0, 64)| onechar('e', 8, 64)| onechar('d', 16, 64)| onechar('i', 24, 64)| onechar('f', 32, 64)| onechar('f', 40, 64)| onechar('u', 48, 64)| onechar('s', 56, 64):
        switch(*((triehash_uu64*) &string[8])) {
        case 0| onechar('e', 0, 64)| onechar('l', 8, 64)| onechar('i', 16, 64)| onechar('g', 24, 64)| onechar('h', 32, 64)| onechar('t', 40, 64)| onechar('i', 48, 64)| onechar('n', 56, 64):
            switch(string[16]) {
            case 0| onechar('g', 0, 8):
                return SE_fediffuselighting;
            }
        }
        break;
    case 0| onechar('f', 0, 64)| onechar('e', 8, 64)| onechar('d', 16, 64)| onechar('i', 24, 64)| onechar('s', 32, 64)| onechar('p', 40, 64)| onechar('l', 48, 64)| onechar('a', 56, 64):
        switch(*((triehash_uu64*) &string[8])) {
        case 0| onechar('c', 0, 64)| onechar('e', 8, 64)| onechar('m', 16, 64)| onechar('e', 24, 64)| onechar('n', 32, 64)| onechar('t', 40, 64)| onechar('m', 48, 64)| onechar('a', 56, 64):
            switch(string[16]) {
            case 0| onechar('p', 0, 8):
                return SE_fedisplacementmap;
            }
        }
    }
    return SE_Unknown;
}
static enum SvgElement lookup_svg_element18(const char *string)
{
    switch(*((triehash_uu64*) &string[0])) {
    case 0| onechar('f', 0, 64)| onechar('e', 8, 64)| onechar('s', 16, 64)| onechar('p', 24, 64)| onechar('e', 32, 64)| onechar('c', 40, 64)| onechar('u', 48, 64)| onechar('l', 56, 64):
        switch(*((triehash_uu64*) &string[8])) {
        case 0| onechar('a', 0, 64)| onechar('r', 8, 64)| onechar('l', 16, 64)| onechar('i', 24, 64)| onechar('g', 32, 64)| onechar('h', 40, 64)| onechar('t', 48, 64)| onechar('i', 56, 64):
            switch(string[16]) {
            case 0| onechar('n', 0, 8):
                switch(string[17]) {
                case 0| onechar('g', 0, 8):
                    return SE_fespecularlighting;
                }
            }
        }
    }
    return SE_Unknown;
}
static enum SvgElement lookup_svg_element19(const char *string)
{
    switch(*((triehash_uu64*) &string[0])) {
    case 0| onechar('f', 0, 64)| onechar('e', 8, 64)| onechar('c', 16, 64)| onechar('o', 24, 64)| onechar('m', 32, 64)| onechar('p', 40, 64)| onechar('o', 48, 64)| onechar('n', 56, 64):
        switch(*((triehash_uu64*) &string[8])) {
        case 0| onechar('e', 0, 64)| onechar('n', 8, 64)| onechar('t', 16, 64)| onechar('t', 24, 64)| onechar('r', 32, 64)| onechar('a', 40, 64)| onechar('n', 48, 64)| onechar('s', 56, 64):
            switch(string[16]) {
            case 0| onechar('f', 0, 8):
                switch(string[17]) {
                case 0| onechar('e', 0, 8):
                    switch(string[18]) {
                    case 0| onechar('r', 0, 8):
                        return SE_fecomponenttransfer;
                    }
                }
            }
        }
    }
    return SE_Unknown;
}
#else
static enum SvgElement lookup_svg_element1(const char *string)
{
    switch(string[0]) {
    case 'a':
        return SE_a;
        break;
    case 'g':
        return SE_g;
    }
    return SE_Unknown;
}
static enum SvgElement lookup_svg_element3(const char *string)
{
    switch(string[0]) {
    case 's':
        switch(string[1]) {
        case 'e':
            switch(string[2]) {
            case 't':
                return SE_set;
            }
            break;
        case 'v':
            switch(string[2]) {
            case 'g':
                return SE_svg;
            }
        }
        break;
    case 'u':
        switch(string[1]) {
        case 's':
            switch(string[2]) {
            case 'e':
                return SE_use;
            }
        }
    }
    return SE_Unknown;
}
static enum SvgElement lookup_svg_element4(const char *string)
{
    switch(string[0]) {
    case 'd':
        switch(string[1]) {
        case 'e':
            switch(string[2]) {
            case 'f':
                switch(string[3]) {
                case 's':
                    return SE_defs;
                }
                break;
            case 's':
                switch(string[3]) {
                case 'c':
                    return SE_desc;
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
                case 'e':
                    return SE_line;
                }
            }
        }
        break;
    case 'm':
        switch(string[1]) {
        case 'a':
            switch(string[2]) {
            case 's':
                switch(string[3]) {
                case 'k':
                    return SE_mask;
                }
            }
        }
        break;
    case 'p':
        switch(string[1]) {
        case 'a':
            switch(string[2]) {
            case 't':
                switch(string[3]) {
                case 'h':
                    return SE_path;
                }
            }
        }
        break;
    case 'r':
        switch(string[1]) {
        case 'e':
            switch(string[2]) {
            case 'c':
                switch(string[3]) {
                case 't':
                    return SE_rect;
                }
            }
        }
        break;
    case 's':
        switch(string[1]) {
        case 't':
            switch(string[2]) {
            case 'o':
                switch(string[3]) {
                case 'p':
                    return SE_stop;
                }
            }
        }
        break;
    case 't':
        switch(string[1]) {
        case 'e':
            switch(string[2]) {
            case 'x':
                switch(string[3]) {
                case 't':
                    return SE_text;
                }
            }
        }
        break;
    case 'v':
        switch(string[1]) {
        case 'i':
            switch(string[2]) {
            case 'e':
                switch(string[3]) {
                case 'w':
                    return SE_view;
                }
            }
        }
    }
    return SE_Unknown;
}
static enum SvgElement lookup_svg_element5(const char *string)
{
    switch(string[0]) {
    case 'i':
        switch(string[1]) {
        case 'm':
            switch(string[2]) {
            case 'a':
                switch(string[3]) {
                case 'g':
                    switch(string[4]) {
                    case 'e':
                        return SE_image;
                    }
                }
            }
        }
        break;
    case 'm':
        switch(string[1]) {
        case 'p':
            switch(string[2]) {
            case 'a':
                switch(string[3]) {
                case 't':
                    switch(string[4]) {
                    case 'h':
                        return SE_mpath;
                    }
                }
            }
        }
        break;
    case 's':
        switch(string[1]) {
        case 't':
            switch(string[2]) {
            case 'y':
                switch(string[3]) {
                case 'l':
                    switch(string[4]) {
                    case 'e':
                        return SE_style;
                    }
                }
            }
        }
        break;
    case 't':
        switch(string[1]) {
        case 'i':
            switch(string[2]) {
            case 't':
                switch(string[3]) {
                case 'l':
                    switch(string[4]) {
                    case 'e':
                        return SE_title;
                    }
                }
            }
            break;
        case 's':
            switch(string[2]) {
            case 'p':
                switch(string[3]) {
                case 'a':
                    switch(string[4]) {
                    case 'n':
                        return SE_tspan;
                    }
                }
            }
        }
    }
    return SE_Unknown;
}
static enum SvgElement lookup_svg_element6(const char *string)
{
    switch(string[0]) {
    case 'c':
        switch(string[1]) {
        case 'i':
            switch(string[2]) {
            case 'r':
                switch(string[3]) {
                case 'c':
                    switch(string[4]) {
                    case 'l':
                        switch(string[5]) {
                        case 'e':
                            return SE_circle;
                        }
                    }
                }
            }
        }
        break;
    case 'f':
        switch(string[1]) {
        case 'e':
            switch(string[2]) {
            case 't':
                switch(string[3]) {
                case 'i':
                    switch(string[4]) {
                    case 'l':
                        switch(string[5]) {
                        case 'e':
                            return SE_fetile;
                        }
                    }
                }
            }
            break;
        case 'i':
            switch(string[2]) {
            case 'l':
                switch(string[3]) {
                case 't':
                    switch(string[4]) {
                    case 'e':
                        switch(string[5]) {
                        case 'r':
                            return SE_filter;
                        }
                    }
                }
            }
        }
        break;
    case 'm':
        switch(string[1]) {
        case 'a':
            switch(string[2]) {
            case 'r':
                switch(string[3]) {
                case 'k':
                    switch(string[4]) {
                    case 'e':
                        switch(string[5]) {
                        case 'r':
                            return SE_marker;
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
                            return SE_script;
                        }
                    }
                }
            }
            break;
        case 'w':
            switch(string[2]) {
            case 'i':
                switch(string[3]) {
                case 't':
                    switch(string[4]) {
                    case 'c':
                        switch(string[5]) {
                        case 'h':
                            return SE_switch;
                        }
                    }
                }
            }
            break;
        case 'y':
            switch(string[2]) {
            case 'm':
                switch(string[3]) {
                case 'b':
                    switch(string[4]) {
                    case 'o':
                        switch(string[5]) {
                        case 'l':
                            return SE_symbol;
                        }
                    }
                }
            }
        }
    }
    return SE_Unknown;
}
static enum SvgElement lookup_svg_element7(const char *string)
{
    switch(string[0]) {
    case 'a':
        switch(string[1]) {
        case 'n':
            switch(string[2]) {
            case 'i':
                switch(string[3]) {
                case 'm':
                    switch(string[4]) {
                    case 'a':
                        switch(string[5]) {
                        case 't':
                            switch(string[6]) {
                            case 'e':
                                return SE_animate;
                            }
                        }
                    }
                }
            }
        }
        break;
    case 'e':
        switch(string[1]) {
        case 'l':
            switch(string[2]) {
            case 'l':
                switch(string[3]) {
                case 'i':
                    switch(string[4]) {
                    case 'p':
                        switch(string[5]) {
                        case 's':
                            switch(string[6]) {
                            case 'e':
                                return SE_ellipse;
                            }
                        }
                    }
                }
            }
        }
        break;
    case 'f':
        switch(string[1]) {
        case 'e':
            switch(string[2]) {
            case 'b':
                switch(string[3]) {
                case 'l':
                    switch(string[4]) {
                    case 'e':
                        switch(string[5]) {
                        case 'n':
                            switch(string[6]) {
                            case 'd':
                                return SE_feblend;
                            }
                        }
                    }
                }
                break;
            case 'f':
                switch(string[3]) {
                case 'l':
                    switch(string[4]) {
                    case 'o':
                        switch(string[5]) {
                        case 'o':
                            switch(string[6]) {
                            case 'd':
                                return SE_feflood;
                            }
                        }
                    }
                    break;
                case 'u':
                    switch(string[4]) {
                    case 'n':
                        switch(string[5]) {
                        case 'c':
                            switch(string[6]) {
                            case 'a':
                                return SE_fefunca;
                                break;
                            case 'b':
                                return SE_fefuncb;
                                break;
                            case 'g':
                                return SE_fefuncg;
                                break;
                            case 'r':
                                return SE_fefuncr;
                            }
                        }
                    }
                }
                break;
            case 'i':
                switch(string[3]) {
                case 'm':
                    switch(string[4]) {
                    case 'a':
                        switch(string[5]) {
                        case 'g':
                            switch(string[6]) {
                            case 'e':
                                return SE_feimage;
                            }
                        }
                    }
                }
                break;
            case 'm':
                switch(string[3]) {
                case 'e':
                    switch(string[4]) {
                    case 'r':
                        switch(string[5]) {
                        case 'g':
                            switch(string[6]) {
                            case 'e':
                                return SE_femerge;
                            }
                        }
                    }
                }
            }
        }
        break;
    case 'p':
        switch(string[1]) {
        case 'a':
            switch(string[2]) {
            case 't':
                switch(string[3]) {
                case 't':
                    switch(string[4]) {
                    case 'e':
                        switch(string[5]) {
                        case 'r':
                            switch(string[6]) {
                            case 'n':
                                return SE_pattern;
                            }
                        }
                    }
                }
            }
            break;
        case 'o':
            switch(string[2]) {
            case 'l':
                switch(string[3]) {
                case 'y':
                    switch(string[4]) {
                    case 'g':
                        switch(string[5]) {
                        case 'o':
                            switch(string[6]) {
                            case 'n':
                                return SE_polygon;
                            }
                        }
                    }
                }
            }
        }
    }
    return SE_Unknown;
}
static enum SvgElement lookup_svg_element8(const char *string)
{
    switch(string[0]) {
    case 'c':
        switch(string[1]) {
        case 'l':
            switch(string[2]) {
            case 'i':
                switch(string[3]) {
                case 'p':
                    switch(string[4]) {
                    case 'p':
                        switch(string[5]) {
                        case 'a':
                            switch(string[6]) {
                            case 't':
                                switch(string[7]) {
                                case 'h':
                                    return SE_clippath;
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
        case 'e':
            switch(string[2]) {
            case 'o':
                switch(string[3]) {
                case 'f':
                    switch(string[4]) {
                    case 'f':
                        switch(string[5]) {
                        case 's':
                            switch(string[6]) {
                            case 'e':
                                switch(string[7]) {
                                case 't':
                                    return SE_feoffset;
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
            case 't':
                switch(string[3]) {
                case 'a':
                    switch(string[4]) {
                    case 'd':
                        switch(string[5]) {
                        case 'a':
                            switch(string[6]) {
                            case 't':
                                switch(string[7]) {
                                case 'a':
                                    return SE_metadata;
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
        case 'o':
            switch(string[2]) {
            case 'l':
                switch(string[3]) {
                case 'y':
                    switch(string[4]) {
                    case 'l':
                        switch(string[5]) {
                        case 'i':
                            switch(string[6]) {
                            case 'n':
                                switch(string[7]) {
                                case 'e':
                                    return SE_polyline;
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
            case 'x':
                switch(string[3]) {
                case 't':
                    switch(string[4]) {
                    case 'p':
                        switch(string[5]) {
                        case 'a':
                            switch(string[6]) {
                            case 't':
                                switch(string[7]) {
                                case 'h':
                                    return SE_textpath;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return SE_Unknown;
}
static enum SvgElement lookup_svg_element11(const char *string)
{
    switch(string[0]) {
    case 'f':
        switch(string[1]) {
        case 'e':
            switch(string[2]) {
            case 'c':
                switch(string[3]) {
                case 'o':
                    switch(string[4]) {
                    case 'm':
                        switch(string[5]) {
                        case 'p':
                            switch(string[6]) {
                            case 'o':
                                switch(string[7]) {
                                case 's':
                                    switch(string[8]) {
                                    case 'i':
                                        switch(string[9]) {
                                        case 't':
                                            switch(string[10]) {
                                            case 'e':
                                                return SE_fecomposite;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                break;
            case 'm':
                switch(string[3]) {
                case 'e':
                    switch(string[4]) {
                    case 'r':
                        switch(string[5]) {
                        case 'g':
                            switch(string[6]) {
                            case 'e':
                                switch(string[7]) {
                                case 'n':
                                    switch(string[8]) {
                                    case 'o':
                                        switch(string[9]) {
                                        case 'd':
                                            switch(string[10]) {
                                            case 'e':
                                                return SE_femergenode;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                break;
            case 's':
                switch(string[3]) {
                case 'p':
                    switch(string[4]) {
                    case 'o':
                        switch(string[5]) {
                        case 't':
                            switch(string[6]) {
                            case 'l':
                                switch(string[7]) {
                                case 'i':
                                    switch(string[8]) {
                                    case 'g':
                                        switch(string[9]) {
                                        case 'h':
                                            switch(string[10]) {
                                            case 't':
                                                return SE_fespotlight;
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
    }
    return SE_Unknown;
}
static enum SvgElement lookup_svg_element12(const char *string)
{
    switch(string[0]) {
    case 'f':
        switch(string[1]) {
        case 'e':
            switch(string[2]) {
            case 'd':
                switch(string[3]) {
                case 'r':
                    switch(string[4]) {
                    case 'o':
                        switch(string[5]) {
                        case 'p':
                            switch(string[6]) {
                            case 's':
                                switch(string[7]) {
                                case 'h':
                                    switch(string[8]) {
                                    case 'a':
                                        switch(string[9]) {
                                        case 'd':
                                            switch(string[10]) {
                                            case 'o':
                                                switch(string[11]) {
                                                case 'w':
                                                    return SE_fedropshadow;
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
            case 'm':
                switch(string[3]) {
                case 'o':
                    switch(string[4]) {
                    case 'r':
                        switch(string[5]) {
                        case 'p':
                            switch(string[6]) {
                            case 'h':
                                switch(string[7]) {
                                case 'o':
                                    switch(string[8]) {
                                    case 'l':
                                        switch(string[9]) {
                                        case 'o':
                                            switch(string[10]) {
                                            case 'g':
                                                switch(string[11]) {
                                                case 'y':
                                                    return SE_femorphology;
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
            case 'p':
                switch(string[3]) {
                case 'o':
                    switch(string[4]) {
                    case 'i':
                        switch(string[5]) {
                        case 'n':
                            switch(string[6]) {
                            case 't':
                                switch(string[7]) {
                                case 'l':
                                    switch(string[8]) {
                                    case 'i':
                                        switch(string[9]) {
                                        case 'g':
                                            switch(string[10]) {
                                            case 'h':
                                                switch(string[11]) {
                                                case 't':
                                                    return SE_fepointlight;
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
            case 't':
                switch(string[3]) {
                case 'u':
                    switch(string[4]) {
                    case 'r':
                        switch(string[5]) {
                        case 'b':
                            switch(string[6]) {
                            case 'u':
                                switch(string[7]) {
                                case 'l':
                                    switch(string[8]) {
                                    case 'e':
                                        switch(string[9]) {
                                        case 'n':
                                            switch(string[10]) {
                                            case 'c':
                                                switch(string[11]) {
                                                case 'e':
                                                    return SE_feturbulence;
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
        }
    }
    return SE_Unknown;
}
static enum SvgElement lookup_svg_element13(const char *string)
{
    switch(string[0]) {
    case 'a':
        switch(string[1]) {
        case 'n':
            switch(string[2]) {
            case 'i':
                switch(string[3]) {
                case 'm':
                    switch(string[4]) {
                    case 'a':
                        switch(string[5]) {
                        case 't':
                            switch(string[6]) {
                            case 'e':
                                switch(string[7]) {
                                case 'm':
                                    switch(string[8]) {
                                    case 'o':
                                        switch(string[9]) {
                                        case 't':
                                            switch(string[10]) {
                                            case 'i':
                                                switch(string[11]) {
                                                case 'o':
                                                    switch(string[12]) {
                                                    case 'n':
                                                        return SE_animatemotion;
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
            }
        }
        break;
    case 'f':
        switch(string[1]) {
        case 'e':
            switch(string[2]) {
            case 'c':
                switch(string[3]) {
                case 'o':
                    switch(string[4]) {
                    case 'l':
                        switch(string[5]) {
                        case 'o':
                            switch(string[6]) {
                            case 'r':
                                switch(string[7]) {
                                case 'm':
                                    switch(string[8]) {
                                    case 'a':
                                        switch(string[9]) {
                                        case 't':
                                            switch(string[10]) {
                                            case 'r':
                                                switch(string[11]) {
                                                case 'i':
                                                    switch(string[12]) {
                                                    case 'x':
                                                        return SE_fecolormatrix;
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
            }
            break;
        case 'o':
            switch(string[2]) {
            case 'r':
                switch(string[3]) {
                case 'e':
                    switch(string[4]) {
                    case 'i':
                        switch(string[5]) {
                        case 'g':
                            switch(string[6]) {
                            case 'n':
                                switch(string[7]) {
                                case 'o':
                                    switch(string[8]) {
                                    case 'b':
                                        switch(string[9]) {
                                        case 'j':
                                            switch(string[10]) {
                                            case 'e':
                                                switch(string[11]) {
                                                case 'c':
                                                    switch(string[12]) {
                                                    case 't':
                                                        return SE_foreignobject;
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
            }
        }
    }
    return SE_Unknown;
}
static enum SvgElement lookup_svg_element14(const char *string)
{
    switch(string[0]) {
    case 'f':
        switch(string[1]) {
        case 'e':
            switch(string[2]) {
            case 'd':
                switch(string[3]) {
                case 'i':
                    switch(string[4]) {
                    case 's':
                        switch(string[5]) {
                        case 't':
                            switch(string[6]) {
                            case 'a':
                                switch(string[7]) {
                                case 'n':
                                    switch(string[8]) {
                                    case 't':
                                        switch(string[9]) {
                                        case 'l':
                                            switch(string[10]) {
                                            case 'i':
                                                switch(string[11]) {
                                                case 'g':
                                                    switch(string[12]) {
                                                    case 'h':
                                                        switch(string[13]) {
                                                        case 't':
                                                            return SE_fedistantlight;
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
                }
                break;
            case 'g':
                switch(string[3]) {
                case 'a':
                    switch(string[4]) {
                    case 'u':
                        switch(string[5]) {
                        case 's':
                            switch(string[6]) {
                            case 's':
                                switch(string[7]) {
                                case 'i':
                                    switch(string[8]) {
                                    case 'a':
                                        switch(string[9]) {
                                        case 'n':
                                            switch(string[10]) {
                                            case 'b':
                                                switch(string[11]) {
                                                case 'l':
                                                    switch(string[12]) {
                                                    case 'u':
                                                        switch(string[13]) {
                                                        case 'r':
                                                            return SE_fegaussianblur;
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
                case 'e':
                    switch(string[4]) {
                    case 'a':
                        switch(string[5]) {
                        case 'r':
                            switch(string[6]) {
                            case 'g':
                                switch(string[7]) {
                                case 'r':
                                    switch(string[8]) {
                                    case 'a':
                                        switch(string[9]) {
                                        case 'd':
                                            switch(string[10]) {
                                            case 'i':
                                                switch(string[11]) {
                                                case 'e':
                                                    switch(string[12]) {
                                                    case 'n':
                                                        switch(string[13]) {
                                                        case 't':
                                                            return SE_lineargradient;
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
                }
            }
        }
        break;
    case 'r':
        switch(string[1]) {
        case 'a':
            switch(string[2]) {
            case 'd':
                switch(string[3]) {
                case 'i':
                    switch(string[4]) {
                    case 'a':
                        switch(string[5]) {
                        case 'l':
                            switch(string[6]) {
                            case 'g':
                                switch(string[7]) {
                                case 'r':
                                    switch(string[8]) {
                                    case 'a':
                                        switch(string[9]) {
                                        case 'd':
                                            switch(string[10]) {
                                            case 'i':
                                                switch(string[11]) {
                                                case 'e':
                                                    switch(string[12]) {
                                                    case 'n':
                                                        switch(string[13]) {
                                                        case 't':
                                                            return SE_radialgradient;
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
                }
            }
        }
    }
    return SE_Unknown;
}
static enum SvgElement lookup_svg_element16(const char *string)
{
    switch(string[0]) {
    case 'a':
        switch(string[1]) {
        case 'n':
            switch(string[2]) {
            case 'i':
                switch(string[3]) {
                case 'm':
                    switch(string[4]) {
                    case 'a':
                        switch(string[5]) {
                        case 't':
                            switch(string[6]) {
                            case 'e':
                                switch(string[7]) {
                                case 't':
                                    switch(string[8]) {
                                    case 'r':
                                        switch(string[9]) {
                                        case 'a':
                                            switch(string[10]) {
                                            case 'n':
                                                switch(string[11]) {
                                                case 's':
                                                    switch(string[12]) {
                                                    case 'f':
                                                        switch(string[13]) {
                                                        case 'o':
                                                            switch(string[14]) {
                                                            case 'r':
                                                                switch(string[15]) {
                                                                case 'm':
                                                                    return SE_animatetransform;
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
                        }
                    }
                }
            }
        }
        break;
    case 'f':
        switch(string[1]) {
        case 'e':
            switch(string[2]) {
            case 'c':
                switch(string[3]) {
                case 'o':
                    switch(string[4]) {
                    case 'n':
                        switch(string[5]) {
                        case 'v':
                            switch(string[6]) {
                            case 'o':
                                switch(string[7]) {
                                case 'l':
                                    switch(string[8]) {
                                    case 'v':
                                        switch(string[9]) {
                                        case 'e':
                                            switch(string[10]) {
                                            case 'm':
                                                switch(string[11]) {
                                                case 'a':
                                                    switch(string[12]) {
                                                    case 't':
                                                        switch(string[13]) {
                                                        case 'r':
                                                            switch(string[14]) {
                                                            case 'i':
                                                                switch(string[15]) {
                                                                case 'x':
                                                                    return SE_feconvolvematrix;
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
                        }
                    }
                }
            }
        }
    }
    return SE_Unknown;
}
static enum SvgElement lookup_svg_element17(const char *string)
{
    switch(string[0]) {
    case 'f':
        switch(string[1]) {
        case 'e':
            switch(string[2]) {
            case 'd':
                switch(string[3]) {
                case 'i':
                    switch(string[4]) {
                    case 'f':
                        switch(string[5]) {
                        case 'f':
                            switch(string[6]) {
                            case 'u':
                                switch(string[7]) {
                                case 's':
                                    switch(string[8]) {
                                    case 'e':
                                        switch(string[9]) {
                                        case 'l':
                                            switch(string[10]) {
                                            case 'i':
                                                switch(string[11]) {
                                                case 'g':
                                                    switch(string[12]) {
                                                    case 'h':
                                                        switch(string[13]) {
                                                        case 't':
                                                            switch(string[14]) {
                                                            case 'i':
                                                                switch(string[15]) {
                                                                case 'n':
                                                                    switch(string[16]) {
                                                                    case 'g':
                                                                        return SE_fediffuselighting;
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
                            }
                        }
                        break;
                    case 's':
                        switch(string[5]) {
                        case 'p':
                            switch(string[6]) {
                            case 'l':
                                switch(string[7]) {
                                case 'a':
                                    switch(string[8]) {
                                    case 'c':
                                        switch(string[9]) {
                                        case 'e':
                                            switch(string[10]) {
                                            case 'm':
                                                switch(string[11]) {
                                                case 'e':
                                                    switch(string[12]) {
                                                    case 'n':
                                                        switch(string[13]) {
                                                        case 't':
                                                            switch(string[14]) {
                                                            case 'm':
                                                                switch(string[15]) {
                                                                case 'a':
                                                                    switch(string[16]) {
                                                                    case 'p':
                                                                        return SE_fedisplacementmap;
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
                            }
                        }
                    }
                }
            }
        }
    }
    return SE_Unknown;
}
static enum SvgElement lookup_svg_element18(const char *string)
{
    switch(string[0]) {
    case 'f':
        switch(string[1]) {
        case 'e':
            switch(string[2]) {
            case 's':
                switch(string[3]) {
                case 'p':
                    switch(string[4]) {
                    case 'e':
                        switch(string[5]) {
                        case 'c':
                            switch(string[6]) {
                            case 'u':
                                switch(string[7]) {
                                case 'l':
                                    switch(string[8]) {
                                    case 'a':
                                        switch(string[9]) {
                                        case 'r':
                                            switch(string[10]) {
                                            case 'l':
                                                switch(string[11]) {
                                                case 'i':
                                                    switch(string[12]) {
                                                    case 'g':
                                                        switch(string[13]) {
                                                        case 'h':
                                                            switch(string[14]) {
                                                            case 't':
                                                                switch(string[15]) {
                                                                case 'i':
                                                                    switch(string[16]) {
                                                                    case 'n':
                                                                        switch(string[17]) {
                                                                        case 'g':
                                                                            return SE_fespecularlighting;
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
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return SE_Unknown;
}
static enum SvgElement lookup_svg_element19(const char *string)
{
    switch(string[0]) {
    case 'f':
        switch(string[1]) {
        case 'e':
            switch(string[2]) {
            case 'c':
                switch(string[3]) {
                case 'o':
                    switch(string[4]) {
                    case 'm':
                        switch(string[5]) {
                        case 'p':
                            switch(string[6]) {
                            case 'o':
                                switch(string[7]) {
                                case 'n':
                                    switch(string[8]) {
                                    case 'e':
                                        switch(string[9]) {
                                        case 'n':
                                            switch(string[10]) {
                                            case 't':
                                                switch(string[11]) {
                                                case 't':
                                                    switch(string[12]) {
                                                    case 'r':
                                                        switch(string[13]) {
                                                        case 'a':
                                                            switch(string[14]) {
                                                            case 'n':
                                                                switch(string[15]) {
                                                                case 's':
                                                                    switch(string[16]) {
                                                                    case 'f':
                                                                        switch(string[17]) {
                                                                        case 'e':
                                                                            switch(string[18]) {
                                                                            case 'r':
                                                                                return SE_fecomponenttransfer;
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
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return SE_Unknown;
}
#endif /* TRIE_HASH_MULTI_BYTE */
static enum SvgElement lookup_svg_element(const char *string, size_t length)
{
    switch (length) {
    case 1:
        return lookup_svg_element1(string);
    case 3:
        return lookup_svg_element3(string);
    case 4:
        return lookup_svg_element4(string);
    case 5:
        return lookup_svg_element5(string);
    case 6:
        return lookup_svg_element6(string);
    case 7:
        return lookup_svg_element7(string);
    case 8:
        return lookup_svg_element8(string);
    case 11:
        return lookup_svg_element11(string);
    case 12:
        return lookup_svg_element12(string);
    case 13:
        return lookup_svg_element13(string);
    case 14:
        return lookup_svg_element14(string);
    case 16:
        return lookup_svg_element16(string);
    case 17:
        return lookup_svg_element17(string);
    case 18:
        return lookup_svg_element18(string);
    case 19:
        return lookup_svg_element19(string);
    default:
        return SE_Unknown;
    }
}
#endif                       /* TRIE_HASH_lookup_svg_element */
