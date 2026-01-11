#ifndef TRIE_HASH_lookup_short_character_reference
#define TRIE_HASH_lookup_short_character_reference
#include <stddef.h>
#include <stdint.h>
enum ShortCharacterReference {
    ShortCharacterReference_AMP = 2,
    ShortCharacterReference_AElig = 1,
    ShortCharacterReference_Aacute = 3,
    ShortCharacterReference_Acirc = 4,
    ShortCharacterReference_Agrave = 5,
    ShortCharacterReference_Aring = 6,
    ShortCharacterReference_Atilde = 7,
    ShortCharacterReference_Auml = 8,
    ShortCharacterReference_COPY = 9,
    ShortCharacterReference_Ccedil = 10,
    ShortCharacterReference_ETH = 11,
    ShortCharacterReference_Eacute = 12,
    ShortCharacterReference_Ecirc = 13,
    ShortCharacterReference_Egrave = 14,
    ShortCharacterReference_Euml = 15,
    ShortCharacterReference_GT = 16,
    ShortCharacterReference_Iacute = 17,
    ShortCharacterReference_Icirc = 18,
    ShortCharacterReference_Igrave = 19,
    ShortCharacterReference_Iuml = 20,
    ShortCharacterReference_LT = 21,
    ShortCharacterReference_Ntilde = 22,
    ShortCharacterReference_Oacute = 23,
    ShortCharacterReference_Ocirc = 24,
    ShortCharacterReference_Ograve = 25,
    ShortCharacterReference_Oslash = 26,
    ShortCharacterReference_Otilde = 27,
    ShortCharacterReference_Ouml = 28,
    ShortCharacterReference_QUOT = 29,
    ShortCharacterReference_REG = 30,
    ShortCharacterReference_THORN = 31,
    ShortCharacterReference_Uacute = 32,
    ShortCharacterReference_Ucirc = 33,
    ShortCharacterReference_Ugrave = 34,
    ShortCharacterReference_Uuml = 35,
    ShortCharacterReference_Yacute = 36,
    ShortCharacterReference_amp = 42,
    ShortCharacterReference_aacute = 37,
    ShortCharacterReference_acirc = 38,
    ShortCharacterReference_acute = 39,
    ShortCharacterReference_aelig = 40,
    ShortCharacterReference_agrave = 41,
    ShortCharacterReference_aring = 43,
    ShortCharacterReference_atilde = 44,
    ShortCharacterReference_auml = 45,
    ShortCharacterReference_brvbar = 46,
    ShortCharacterReference_ccedil = 47,
    ShortCharacterReference_cedil = 48,
    ShortCharacterReference_cent = 49,
    ShortCharacterReference_copy = 50,
    ShortCharacterReference_curren = 51,
    ShortCharacterReference_deg = 52,
    ShortCharacterReference_divide = 53,
    ShortCharacterReference_eth = 57,
    ShortCharacterReference_eacute = 54,
    ShortCharacterReference_ecirc = 55,
    ShortCharacterReference_egrave = 56,
    ShortCharacterReference_euml = 58,
    ShortCharacterReference_frac12 = 59,
    ShortCharacterReference_frac14 = 60,
    ShortCharacterReference_frac34 = 61,
    ShortCharacterReference_gt = 62,
    ShortCharacterReference_iacute = 63,
    ShortCharacterReference_icirc = 64,
    ShortCharacterReference_iexcl = 65,
    ShortCharacterReference_igrave = 66,
    ShortCharacterReference_iquest = 67,
    ShortCharacterReference_iuml = 68,
    ShortCharacterReference_lt = 70,
    ShortCharacterReference_laquo = 69,
    ShortCharacterReference_macr = 71,
    ShortCharacterReference_micro = 72,
    ShortCharacterReference_middot = 73,
    ShortCharacterReference_not = 75,
    ShortCharacterReference_nbsp = 74,
    ShortCharacterReference_ntilde = 76,
    ShortCharacterReference_oacute = 77,
    ShortCharacterReference_ocirc = 78,
    ShortCharacterReference_ograve = 79,
    ShortCharacterReference_ordf = 80,
    ShortCharacterReference_ordm = 81,
    ShortCharacterReference_oslash = 82,
    ShortCharacterReference_otilde = 83,
    ShortCharacterReference_ouml = 84,
    ShortCharacterReference_para = 85,
    ShortCharacterReference_plusmn = 86,
    ShortCharacterReference_pound = 87,
    ShortCharacterReference_quot = 88,
    ShortCharacterReference_reg = 90,
    ShortCharacterReference_raquo = 89,
    ShortCharacterReference_shy = 92,
    ShortCharacterReference_sect = 91,
    ShortCharacterReference_sup1 = 93,
    ShortCharacterReference_sup2 = 94,
    ShortCharacterReference_sup3 = 95,
    ShortCharacterReference_szlig = 96,
    ShortCharacterReference_thorn = 97,
    ShortCharacterReference_times = 98,
    ShortCharacterReference_uml = 102,
    ShortCharacterReference_uacute = 99,
    ShortCharacterReference_ucirc = 100,
    ShortCharacterReference_ugrave = 101,
    ShortCharacterReference_uuml = 103,
    ShortCharacterReference_yen = 105,
    ShortCharacterReference_yacute = 104,
    ShortCharacterReference_yuml = 106,
    ShortCharacterReference_Unknown = 0,
};
static enum ShortCharacterReference lookup_short_character_reference(const char *string, size_t length);
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
static enum ShortCharacterReference lookup_short_character_reference2(const char *string)
{
    switch(string[0]) {
    case 0| onechar('G', 0, 8):
        switch(string[1]) {
        case 0| onechar('T', 0, 8):
            return ShortCharacterReference_GT;
        }
        break;
    case 0| onechar('L', 0, 8):
        switch(string[1]) {
        case 0| onechar('T', 0, 8):
            return ShortCharacterReference_LT;
        }
        break;
    case 0| onechar('g', 0, 8):
        switch(string[1]) {
        case 0| onechar('t', 0, 8):
            return ShortCharacterReference_gt;
        }
        break;
    case 0| onechar('l', 0, 8):
        switch(string[1]) {
        case 0| onechar('t', 0, 8):
            return ShortCharacterReference_lt;
        }
    }
    return ShortCharacterReference_Unknown;
}
static enum ShortCharacterReference lookup_short_character_reference3(const char *string)
{
    switch(string[0]) {
    case 0| onechar('A', 0, 8):
        switch(string[1]) {
        case 0| onechar('M', 0, 8):
            switch(string[2]) {
            case 0| onechar('P', 0, 8):
                return ShortCharacterReference_AMP;
            }
        }
        break;
    case 0| onechar('E', 0, 8):
        switch(string[1]) {
        case 0| onechar('T', 0, 8):
            switch(string[2]) {
            case 0| onechar('H', 0, 8):
                return ShortCharacterReference_ETH;
            }
        }
        break;
    case 0| onechar('R', 0, 8):
        switch(string[1]) {
        case 0| onechar('E', 0, 8):
            switch(string[2]) {
            case 0| onechar('G', 0, 8):
                return ShortCharacterReference_REG;
            }
        }
        break;
    case 0| onechar('a', 0, 8):
        switch(string[1]) {
        case 0| onechar('m', 0, 8):
            switch(string[2]) {
            case 0| onechar('p', 0, 8):
                return ShortCharacterReference_amp;
            }
        }
        break;
    case 0| onechar('d', 0, 8):
        switch(string[1]) {
        case 0| onechar('e', 0, 8):
            switch(string[2]) {
            case 0| onechar('g', 0, 8):
                return ShortCharacterReference_deg;
            }
        }
        break;
    case 0| onechar('e', 0, 8):
        switch(string[1]) {
        case 0| onechar('t', 0, 8):
            switch(string[2]) {
            case 0| onechar('h', 0, 8):
                return ShortCharacterReference_eth;
            }
        }
        break;
    case 0| onechar('n', 0, 8):
        switch(string[1]) {
        case 0| onechar('o', 0, 8):
            switch(string[2]) {
            case 0| onechar('t', 0, 8):
                return ShortCharacterReference_not;
            }
        }
        break;
    case 0| onechar('r', 0, 8):
        switch(string[1]) {
        case 0| onechar('e', 0, 8):
            switch(string[2]) {
            case 0| onechar('g', 0, 8):
                return ShortCharacterReference_reg;
            }
        }
        break;
    case 0| onechar('s', 0, 8):
        switch(string[1]) {
        case 0| onechar('h', 0, 8):
            switch(string[2]) {
            case 0| onechar('y', 0, 8):
                return ShortCharacterReference_shy;
            }
        }
        break;
    case 0| onechar('u', 0, 8):
        switch(string[1]) {
        case 0| onechar('m', 0, 8):
            switch(string[2]) {
            case 0| onechar('l', 0, 8):
                return ShortCharacterReference_uml;
            }
        }
        break;
    case 0| onechar('y', 0, 8):
        switch(string[1]) {
        case 0| onechar('e', 0, 8):
            switch(string[2]) {
            case 0| onechar('n', 0, 8):
                return ShortCharacterReference_yen;
            }
        }
    }
    return ShortCharacterReference_Unknown;
}
static enum ShortCharacterReference lookup_short_character_reference4(const char *string)
{
    switch(*((triehash_uu32*) &string[0])) {
    case 0| onechar('A', 0, 32)| onechar('u', 8, 32)| onechar('m', 16, 32)| onechar('l', 24, 32):
        return ShortCharacterReference_Auml;
        break;
    case 0| onechar('C', 0, 32)| onechar('O', 8, 32)| onechar('P', 16, 32)| onechar('Y', 24, 32):
        return ShortCharacterReference_COPY;
        break;
    case 0| onechar('E', 0, 32)| onechar('u', 8, 32)| onechar('m', 16, 32)| onechar('l', 24, 32):
        return ShortCharacterReference_Euml;
        break;
    case 0| onechar('I', 0, 32)| onechar('u', 8, 32)| onechar('m', 16, 32)| onechar('l', 24, 32):
        return ShortCharacterReference_Iuml;
        break;
    case 0| onechar('O', 0, 32)| onechar('u', 8, 32)| onechar('m', 16, 32)| onechar('l', 24, 32):
        return ShortCharacterReference_Ouml;
        break;
    case 0| onechar('Q', 0, 32)| onechar('U', 8, 32)| onechar('O', 16, 32)| onechar('T', 24, 32):
        return ShortCharacterReference_QUOT;
        break;
    case 0| onechar('U', 0, 32)| onechar('u', 8, 32)| onechar('m', 16, 32)| onechar('l', 24, 32):
        return ShortCharacterReference_Uuml;
        break;
    case 0| onechar('a', 0, 32)| onechar('u', 8, 32)| onechar('m', 16, 32)| onechar('l', 24, 32):
        return ShortCharacterReference_auml;
        break;
    case 0| onechar('c', 0, 32)| onechar('e', 8, 32)| onechar('n', 16, 32)| onechar('t', 24, 32):
        return ShortCharacterReference_cent;
        break;
    case 0| onechar('c', 0, 32)| onechar('o', 8, 32)| onechar('p', 16, 32)| onechar('y', 24, 32):
        return ShortCharacterReference_copy;
        break;
    case 0| onechar('e', 0, 32)| onechar('u', 8, 32)| onechar('m', 16, 32)| onechar('l', 24, 32):
        return ShortCharacterReference_euml;
        break;
    case 0| onechar('i', 0, 32)| onechar('u', 8, 32)| onechar('m', 16, 32)| onechar('l', 24, 32):
        return ShortCharacterReference_iuml;
        break;
    case 0| onechar('m', 0, 32)| onechar('a', 8, 32)| onechar('c', 16, 32)| onechar('r', 24, 32):
        return ShortCharacterReference_macr;
        break;
    case 0| onechar('n', 0, 32)| onechar('b', 8, 32)| onechar('s', 16, 32)| onechar('p', 24, 32):
        return ShortCharacterReference_nbsp;
        break;
    case 0| onechar('o', 0, 32)| onechar('r', 8, 32)| onechar('d', 16, 32)| onechar('f', 24, 32):
        return ShortCharacterReference_ordf;
        break;
    case 0| onechar('o', 0, 32)| onechar('r', 8, 32)| onechar('d', 16, 32)| onechar('m', 24, 32):
        return ShortCharacterReference_ordm;
        break;
    case 0| onechar('o', 0, 32)| onechar('u', 8, 32)| onechar('m', 16, 32)| onechar('l', 24, 32):
        return ShortCharacterReference_ouml;
        break;
    case 0| onechar('p', 0, 32)| onechar('a', 8, 32)| onechar('r', 16, 32)| onechar('a', 24, 32):
        return ShortCharacterReference_para;
        break;
    case 0| onechar('q', 0, 32)| onechar('u', 8, 32)| onechar('o', 16, 32)| onechar('t', 24, 32):
        return ShortCharacterReference_quot;
        break;
    case 0| onechar('s', 0, 32)| onechar('e', 8, 32)| onechar('c', 16, 32)| onechar('t', 24, 32):
        return ShortCharacterReference_sect;
        break;
    case 0| onechar('s', 0, 32)| onechar('u', 8, 32)| onechar('p', 16, 32)| onechar('1', 24, 32):
        return ShortCharacterReference_sup1;
        break;
    case 0| onechar('s', 0, 32)| onechar('u', 8, 32)| onechar('p', 16, 32)| onechar('2', 24, 32):
        return ShortCharacterReference_sup2;
        break;
    case 0| onechar('s', 0, 32)| onechar('u', 8, 32)| onechar('p', 16, 32)| onechar('3', 24, 32):
        return ShortCharacterReference_sup3;
        break;
    case 0| onechar('u', 0, 32)| onechar('u', 8, 32)| onechar('m', 16, 32)| onechar('l', 24, 32):
        return ShortCharacterReference_uuml;
        break;
    case 0| onechar('y', 0, 32)| onechar('u', 8, 32)| onechar('m', 16, 32)| onechar('l', 24, 32):
        return ShortCharacterReference_yuml;
    }
    return ShortCharacterReference_Unknown;
}
static enum ShortCharacterReference lookup_short_character_reference5(const char *string)
{
    switch(*((triehash_uu32*) &string[0])) {
    case 0| onechar('A', 0, 32)| onechar('E', 8, 32)| onechar('l', 16, 32)| onechar('i', 24, 32):
        switch(string[4]) {
        case 0| onechar('g', 0, 8):
            return ShortCharacterReference_AElig;
        }
        break;
    case 0| onechar('A', 0, 32)| onechar('c', 8, 32)| onechar('i', 16, 32)| onechar('r', 24, 32):
        switch(string[4]) {
        case 0| onechar('c', 0, 8):
            return ShortCharacterReference_Acirc;
        }
        break;
    case 0| onechar('A', 0, 32)| onechar('r', 8, 32)| onechar('i', 16, 32)| onechar('n', 24, 32):
        switch(string[4]) {
        case 0| onechar('g', 0, 8):
            return ShortCharacterReference_Aring;
        }
        break;
    case 0| onechar('E', 0, 32)| onechar('c', 8, 32)| onechar('i', 16, 32)| onechar('r', 24, 32):
        switch(string[4]) {
        case 0| onechar('c', 0, 8):
            return ShortCharacterReference_Ecirc;
        }
        break;
    case 0| onechar('I', 0, 32)| onechar('c', 8, 32)| onechar('i', 16, 32)| onechar('r', 24, 32):
        switch(string[4]) {
        case 0| onechar('c', 0, 8):
            return ShortCharacterReference_Icirc;
        }
        break;
    case 0| onechar('O', 0, 32)| onechar('c', 8, 32)| onechar('i', 16, 32)| onechar('r', 24, 32):
        switch(string[4]) {
        case 0| onechar('c', 0, 8):
            return ShortCharacterReference_Ocirc;
        }
        break;
    case 0| onechar('T', 0, 32)| onechar('H', 8, 32)| onechar('O', 16, 32)| onechar('R', 24, 32):
        switch(string[4]) {
        case 0| onechar('N', 0, 8):
            return ShortCharacterReference_THORN;
        }
        break;
    case 0| onechar('U', 0, 32)| onechar('c', 8, 32)| onechar('i', 16, 32)| onechar('r', 24, 32):
        switch(string[4]) {
        case 0| onechar('c', 0, 8):
            return ShortCharacterReference_Ucirc;
        }
        break;
    case 0| onechar('a', 0, 32)| onechar('c', 8, 32)| onechar('i', 16, 32)| onechar('r', 24, 32):
        switch(string[4]) {
        case 0| onechar('c', 0, 8):
            return ShortCharacterReference_acirc;
        }
        break;
    case 0| onechar('a', 0, 32)| onechar('c', 8, 32)| onechar('u', 16, 32)| onechar('t', 24, 32):
        switch(string[4]) {
        case 0| onechar('e', 0, 8):
            return ShortCharacterReference_acute;
        }
        break;
    case 0| onechar('a', 0, 32)| onechar('e', 8, 32)| onechar('l', 16, 32)| onechar('i', 24, 32):
        switch(string[4]) {
        case 0| onechar('g', 0, 8):
            return ShortCharacterReference_aelig;
        }
        break;
    case 0| onechar('a', 0, 32)| onechar('r', 8, 32)| onechar('i', 16, 32)| onechar('n', 24, 32):
        switch(string[4]) {
        case 0| onechar('g', 0, 8):
            return ShortCharacterReference_aring;
        }
        break;
    case 0| onechar('c', 0, 32)| onechar('e', 8, 32)| onechar('d', 16, 32)| onechar('i', 24, 32):
        switch(string[4]) {
        case 0| onechar('l', 0, 8):
            return ShortCharacterReference_cedil;
        }
        break;
    case 0| onechar('e', 0, 32)| onechar('c', 8, 32)| onechar('i', 16, 32)| onechar('r', 24, 32):
        switch(string[4]) {
        case 0| onechar('c', 0, 8):
            return ShortCharacterReference_ecirc;
        }
        break;
    case 0| onechar('i', 0, 32)| onechar('c', 8, 32)| onechar('i', 16, 32)| onechar('r', 24, 32):
        switch(string[4]) {
        case 0| onechar('c', 0, 8):
            return ShortCharacterReference_icirc;
        }
        break;
    case 0| onechar('i', 0, 32)| onechar('e', 8, 32)| onechar('x', 16, 32)| onechar('c', 24, 32):
        switch(string[4]) {
        case 0| onechar('l', 0, 8):
            return ShortCharacterReference_iexcl;
        }
        break;
    case 0| onechar('l', 0, 32)| onechar('a', 8, 32)| onechar('q', 16, 32)| onechar('u', 24, 32):
        switch(string[4]) {
        case 0| onechar('o', 0, 8):
            return ShortCharacterReference_laquo;
        }
        break;
    case 0| onechar('m', 0, 32)| onechar('i', 8, 32)| onechar('c', 16, 32)| onechar('r', 24, 32):
        switch(string[4]) {
        case 0| onechar('o', 0, 8):
            return ShortCharacterReference_micro;
        }
        break;
    case 0| onechar('o', 0, 32)| onechar('c', 8, 32)| onechar('i', 16, 32)| onechar('r', 24, 32):
        switch(string[4]) {
        case 0| onechar('c', 0, 8):
            return ShortCharacterReference_ocirc;
        }
        break;
    case 0| onechar('p', 0, 32)| onechar('o', 8, 32)| onechar('u', 16, 32)| onechar('n', 24, 32):
        switch(string[4]) {
        case 0| onechar('d', 0, 8):
            return ShortCharacterReference_pound;
        }
        break;
    case 0| onechar('r', 0, 32)| onechar('a', 8, 32)| onechar('q', 16, 32)| onechar('u', 24, 32):
        switch(string[4]) {
        case 0| onechar('o', 0, 8):
            return ShortCharacterReference_raquo;
        }
        break;
    case 0| onechar('s', 0, 32)| onechar('z', 8, 32)| onechar('l', 16, 32)| onechar('i', 24, 32):
        switch(string[4]) {
        case 0| onechar('g', 0, 8):
            return ShortCharacterReference_szlig;
        }
        break;
    case 0| onechar('t', 0, 32)| onechar('h', 8, 32)| onechar('o', 16, 32)| onechar('r', 24, 32):
        switch(string[4]) {
        case 0| onechar('n', 0, 8):
            return ShortCharacterReference_thorn;
        }
        break;
    case 0| onechar('t', 0, 32)| onechar('i', 8, 32)| onechar('m', 16, 32)| onechar('e', 24, 32):
        switch(string[4]) {
        case 0| onechar('s', 0, 8):
            return ShortCharacterReference_times;
        }
        break;
    case 0| onechar('u', 0, 32)| onechar('c', 8, 32)| onechar('i', 16, 32)| onechar('r', 24, 32):
        switch(string[4]) {
        case 0| onechar('c', 0, 8):
            return ShortCharacterReference_ucirc;
        }
    }
    return ShortCharacterReference_Unknown;
}
static enum ShortCharacterReference lookup_short_character_reference6(const char *string)
{
    switch(*((triehash_uu32*) &string[0])) {
    case 0| onechar('A', 0, 32)| onechar('a', 8, 32)| onechar('c', 16, 32)| onechar('u', 24, 32):
        switch(string[4]) {
        case 0| onechar('t', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return ShortCharacterReference_Aacute;
            }
        }
        break;
    case 0| onechar('A', 0, 32)| onechar('g', 8, 32)| onechar('r', 16, 32)| onechar('a', 24, 32):
        switch(string[4]) {
        case 0| onechar('v', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return ShortCharacterReference_Agrave;
            }
        }
        break;
    case 0| onechar('A', 0, 32)| onechar('t', 8, 32)| onechar('i', 16, 32)| onechar('l', 24, 32):
        switch(string[4]) {
        case 0| onechar('d', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return ShortCharacterReference_Atilde;
            }
        }
        break;
    case 0| onechar('C', 0, 32)| onechar('c', 8, 32)| onechar('e', 16, 32)| onechar('d', 24, 32):
        switch(string[4]) {
        case 0| onechar('i', 0, 8):
            switch(string[5]) {
            case 0| onechar('l', 0, 8):
                return ShortCharacterReference_Ccedil;
            }
        }
        break;
    case 0| onechar('E', 0, 32)| onechar('a', 8, 32)| onechar('c', 16, 32)| onechar('u', 24, 32):
        switch(string[4]) {
        case 0| onechar('t', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return ShortCharacterReference_Eacute;
            }
        }
        break;
    case 0| onechar('E', 0, 32)| onechar('g', 8, 32)| onechar('r', 16, 32)| onechar('a', 24, 32):
        switch(string[4]) {
        case 0| onechar('v', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return ShortCharacterReference_Egrave;
            }
        }
        break;
    case 0| onechar('I', 0, 32)| onechar('a', 8, 32)| onechar('c', 16, 32)| onechar('u', 24, 32):
        switch(string[4]) {
        case 0| onechar('t', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return ShortCharacterReference_Iacute;
            }
        }
        break;
    case 0| onechar('I', 0, 32)| onechar('g', 8, 32)| onechar('r', 16, 32)| onechar('a', 24, 32):
        switch(string[4]) {
        case 0| onechar('v', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return ShortCharacterReference_Igrave;
            }
        }
        break;
    case 0| onechar('N', 0, 32)| onechar('t', 8, 32)| onechar('i', 16, 32)| onechar('l', 24, 32):
        switch(string[4]) {
        case 0| onechar('d', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return ShortCharacterReference_Ntilde;
            }
        }
        break;
    case 0| onechar('O', 0, 32)| onechar('a', 8, 32)| onechar('c', 16, 32)| onechar('u', 24, 32):
        switch(string[4]) {
        case 0| onechar('t', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return ShortCharacterReference_Oacute;
            }
        }
        break;
    case 0| onechar('O', 0, 32)| onechar('g', 8, 32)| onechar('r', 16, 32)| onechar('a', 24, 32):
        switch(string[4]) {
        case 0| onechar('v', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return ShortCharacterReference_Ograve;
            }
        }
        break;
    case 0| onechar('O', 0, 32)| onechar('s', 8, 32)| onechar('l', 16, 32)| onechar('a', 24, 32):
        switch(string[4]) {
        case 0| onechar('s', 0, 8):
            switch(string[5]) {
            case 0| onechar('h', 0, 8):
                return ShortCharacterReference_Oslash;
            }
        }
        break;
    case 0| onechar('O', 0, 32)| onechar('t', 8, 32)| onechar('i', 16, 32)| onechar('l', 24, 32):
        switch(string[4]) {
        case 0| onechar('d', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return ShortCharacterReference_Otilde;
            }
        }
        break;
    case 0| onechar('U', 0, 32)| onechar('a', 8, 32)| onechar('c', 16, 32)| onechar('u', 24, 32):
        switch(string[4]) {
        case 0| onechar('t', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return ShortCharacterReference_Uacute;
            }
        }
        break;
    case 0| onechar('U', 0, 32)| onechar('g', 8, 32)| onechar('r', 16, 32)| onechar('a', 24, 32):
        switch(string[4]) {
        case 0| onechar('v', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return ShortCharacterReference_Ugrave;
            }
        }
        break;
    case 0| onechar('Y', 0, 32)| onechar('a', 8, 32)| onechar('c', 16, 32)| onechar('u', 24, 32):
        switch(string[4]) {
        case 0| onechar('t', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return ShortCharacterReference_Yacute;
            }
        }
        break;
    case 0| onechar('a', 0, 32)| onechar('a', 8, 32)| onechar('c', 16, 32)| onechar('u', 24, 32):
        switch(string[4]) {
        case 0| onechar('t', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return ShortCharacterReference_aacute;
            }
        }
        break;
    case 0| onechar('a', 0, 32)| onechar('g', 8, 32)| onechar('r', 16, 32)| onechar('a', 24, 32):
        switch(string[4]) {
        case 0| onechar('v', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return ShortCharacterReference_agrave;
            }
        }
        break;
    case 0| onechar('a', 0, 32)| onechar('t', 8, 32)| onechar('i', 16, 32)| onechar('l', 24, 32):
        switch(string[4]) {
        case 0| onechar('d', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return ShortCharacterReference_atilde;
            }
        }
        break;
    case 0| onechar('b', 0, 32)| onechar('r', 8, 32)| onechar('v', 16, 32)| onechar('b', 24, 32):
        switch(string[4]) {
        case 0| onechar('a', 0, 8):
            switch(string[5]) {
            case 0| onechar('r', 0, 8):
                return ShortCharacterReference_brvbar;
            }
        }
        break;
    case 0| onechar('c', 0, 32)| onechar('c', 8, 32)| onechar('e', 16, 32)| onechar('d', 24, 32):
        switch(string[4]) {
        case 0| onechar('i', 0, 8):
            switch(string[5]) {
            case 0| onechar('l', 0, 8):
                return ShortCharacterReference_ccedil;
            }
        }
        break;
    case 0| onechar('c', 0, 32)| onechar('u', 8, 32)| onechar('r', 16, 32)| onechar('r', 24, 32):
        switch(string[4]) {
        case 0| onechar('e', 0, 8):
            switch(string[5]) {
            case 0| onechar('n', 0, 8):
                return ShortCharacterReference_curren;
            }
        }
        break;
    case 0| onechar('d', 0, 32)| onechar('i', 8, 32)| onechar('v', 16, 32)| onechar('i', 24, 32):
        switch(string[4]) {
        case 0| onechar('d', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return ShortCharacterReference_divide;
            }
        }
        break;
    case 0| onechar('e', 0, 32)| onechar('a', 8, 32)| onechar('c', 16, 32)| onechar('u', 24, 32):
        switch(string[4]) {
        case 0| onechar('t', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return ShortCharacterReference_eacute;
            }
        }
        break;
    case 0| onechar('e', 0, 32)| onechar('g', 8, 32)| onechar('r', 16, 32)| onechar('a', 24, 32):
        switch(string[4]) {
        case 0| onechar('v', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return ShortCharacterReference_egrave;
            }
        }
        break;
    case 0| onechar('f', 0, 32)| onechar('r', 8, 32)| onechar('a', 16, 32)| onechar('c', 24, 32):
        switch(string[4]) {
        case 0| onechar('1', 0, 8):
            switch(string[5]) {
            case 0| onechar('2', 0, 8):
                return ShortCharacterReference_frac12;
                break;
            case 0| onechar('4', 0, 8):
                return ShortCharacterReference_frac14;
            }
            break;
        case 0| onechar('3', 0, 8):
            switch(string[5]) {
            case 0| onechar('4', 0, 8):
                return ShortCharacterReference_frac34;
            }
        }
        break;
    case 0| onechar('i', 0, 32)| onechar('a', 8, 32)| onechar('c', 16, 32)| onechar('u', 24, 32):
        switch(string[4]) {
        case 0| onechar('t', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return ShortCharacterReference_iacute;
            }
        }
        break;
    case 0| onechar('i', 0, 32)| onechar('g', 8, 32)| onechar('r', 16, 32)| onechar('a', 24, 32):
        switch(string[4]) {
        case 0| onechar('v', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return ShortCharacterReference_igrave;
            }
        }
        break;
    case 0| onechar('i', 0, 32)| onechar('q', 8, 32)| onechar('u', 16, 32)| onechar('e', 24, 32):
        switch(string[4]) {
        case 0| onechar('s', 0, 8):
            switch(string[5]) {
            case 0| onechar('t', 0, 8):
                return ShortCharacterReference_iquest;
            }
        }
        break;
    case 0| onechar('m', 0, 32)| onechar('i', 8, 32)| onechar('d', 16, 32)| onechar('d', 24, 32):
        switch(string[4]) {
        case 0| onechar('o', 0, 8):
            switch(string[5]) {
            case 0| onechar('t', 0, 8):
                return ShortCharacterReference_middot;
            }
        }
        break;
    case 0| onechar('n', 0, 32)| onechar('t', 8, 32)| onechar('i', 16, 32)| onechar('l', 24, 32):
        switch(string[4]) {
        case 0| onechar('d', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return ShortCharacterReference_ntilde;
            }
        }
        break;
    case 0| onechar('o', 0, 32)| onechar('a', 8, 32)| onechar('c', 16, 32)| onechar('u', 24, 32):
        switch(string[4]) {
        case 0| onechar('t', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return ShortCharacterReference_oacute;
            }
        }
        break;
    case 0| onechar('o', 0, 32)| onechar('g', 8, 32)| onechar('r', 16, 32)| onechar('a', 24, 32):
        switch(string[4]) {
        case 0| onechar('v', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return ShortCharacterReference_ograve;
            }
        }
        break;
    case 0| onechar('o', 0, 32)| onechar('s', 8, 32)| onechar('l', 16, 32)| onechar('a', 24, 32):
        switch(string[4]) {
        case 0| onechar('s', 0, 8):
            switch(string[5]) {
            case 0| onechar('h', 0, 8):
                return ShortCharacterReference_oslash;
            }
        }
        break;
    case 0| onechar('o', 0, 32)| onechar('t', 8, 32)| onechar('i', 16, 32)| onechar('l', 24, 32):
        switch(string[4]) {
        case 0| onechar('d', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return ShortCharacterReference_otilde;
            }
        }
        break;
    case 0| onechar('p', 0, 32)| onechar('l', 8, 32)| onechar('u', 16, 32)| onechar('s', 24, 32):
        switch(string[4]) {
        case 0| onechar('m', 0, 8):
            switch(string[5]) {
            case 0| onechar('n', 0, 8):
                return ShortCharacterReference_plusmn;
            }
        }
        break;
    case 0| onechar('u', 0, 32)| onechar('a', 8, 32)| onechar('c', 16, 32)| onechar('u', 24, 32):
        switch(string[4]) {
        case 0| onechar('t', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return ShortCharacterReference_uacute;
            }
        }
        break;
    case 0| onechar('u', 0, 32)| onechar('g', 8, 32)| onechar('r', 16, 32)| onechar('a', 24, 32):
        switch(string[4]) {
        case 0| onechar('v', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return ShortCharacterReference_ugrave;
            }
        }
        break;
    case 0| onechar('y', 0, 32)| onechar('a', 8, 32)| onechar('c', 16, 32)| onechar('u', 24, 32):
        switch(string[4]) {
        case 0| onechar('t', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return ShortCharacterReference_yacute;
            }
        }
    }
    return ShortCharacterReference_Unknown;
}
#else
static enum ShortCharacterReference lookup_short_character_reference2(const char *string)
{
    switch(string[0]) {
    case 'G':
        switch(string[1]) {
        case 'T':
            return ShortCharacterReference_GT;
        }
        break;
    case 'L':
        switch(string[1]) {
        case 'T':
            return ShortCharacterReference_LT;
        }
        break;
    case 'g':
        switch(string[1]) {
        case 't':
            return ShortCharacterReference_gt;
        }
        break;
    case 'l':
        switch(string[1]) {
        case 't':
            return ShortCharacterReference_lt;
        }
    }
    return ShortCharacterReference_Unknown;
}
static enum ShortCharacterReference lookup_short_character_reference3(const char *string)
{
    switch(string[0]) {
    case 'A':
        switch(string[1]) {
        case 'M':
            switch(string[2]) {
            case 'P':
                return ShortCharacterReference_AMP;
            }
        }
        break;
    case 'E':
        switch(string[1]) {
        case 'T':
            switch(string[2]) {
            case 'H':
                return ShortCharacterReference_ETH;
            }
        }
        break;
    case 'R':
        switch(string[1]) {
        case 'E':
            switch(string[2]) {
            case 'G':
                return ShortCharacterReference_REG;
            }
        }
        break;
    case 'a':
        switch(string[1]) {
        case 'm':
            switch(string[2]) {
            case 'p':
                return ShortCharacterReference_amp;
            }
        }
        break;
    case 'd':
        switch(string[1]) {
        case 'e':
            switch(string[2]) {
            case 'g':
                return ShortCharacterReference_deg;
            }
        }
        break;
    case 'e':
        switch(string[1]) {
        case 't':
            switch(string[2]) {
            case 'h':
                return ShortCharacterReference_eth;
            }
        }
        break;
    case 'n':
        switch(string[1]) {
        case 'o':
            switch(string[2]) {
            case 't':
                return ShortCharacterReference_not;
            }
        }
        break;
    case 'r':
        switch(string[1]) {
        case 'e':
            switch(string[2]) {
            case 'g':
                return ShortCharacterReference_reg;
            }
        }
        break;
    case 's':
        switch(string[1]) {
        case 'h':
            switch(string[2]) {
            case 'y':
                return ShortCharacterReference_shy;
            }
        }
        break;
    case 'u':
        switch(string[1]) {
        case 'm':
            switch(string[2]) {
            case 'l':
                return ShortCharacterReference_uml;
            }
        }
        break;
    case 'y':
        switch(string[1]) {
        case 'e':
            switch(string[2]) {
            case 'n':
                return ShortCharacterReference_yen;
            }
        }
    }
    return ShortCharacterReference_Unknown;
}
static enum ShortCharacterReference lookup_short_character_reference4(const char *string)
{
    switch(string[0]) {
    case 'A':
        switch(string[1]) {
        case 'u':
            switch(string[2]) {
            case 'm':
                switch(string[3]) {
                case 'l':
                    return ShortCharacterReference_Auml;
                }
            }
        }
        break;
    case 'C':
        switch(string[1]) {
        case 'O':
            switch(string[2]) {
            case 'P':
                switch(string[3]) {
                case 'Y':
                    return ShortCharacterReference_COPY;
                }
            }
        }
        break;
    case 'E':
        switch(string[1]) {
        case 'u':
            switch(string[2]) {
            case 'm':
                switch(string[3]) {
                case 'l':
                    return ShortCharacterReference_Euml;
                }
            }
        }
        break;
    case 'I':
        switch(string[1]) {
        case 'u':
            switch(string[2]) {
            case 'm':
                switch(string[3]) {
                case 'l':
                    return ShortCharacterReference_Iuml;
                }
            }
        }
        break;
    case 'O':
        switch(string[1]) {
        case 'u':
            switch(string[2]) {
            case 'm':
                switch(string[3]) {
                case 'l':
                    return ShortCharacterReference_Ouml;
                }
            }
        }
        break;
    case 'Q':
        switch(string[1]) {
        case 'U':
            switch(string[2]) {
            case 'O':
                switch(string[3]) {
                case 'T':
                    return ShortCharacterReference_QUOT;
                }
            }
        }
        break;
    case 'U':
        switch(string[1]) {
        case 'u':
            switch(string[2]) {
            case 'm':
                switch(string[3]) {
                case 'l':
                    return ShortCharacterReference_Uuml;
                }
            }
        }
        break;
    case 'a':
        switch(string[1]) {
        case 'u':
            switch(string[2]) {
            case 'm':
                switch(string[3]) {
                case 'l':
                    return ShortCharacterReference_auml;
                }
            }
        }
        break;
    case 'c':
        switch(string[1]) {
        case 'e':
            switch(string[2]) {
            case 'n':
                switch(string[3]) {
                case 't':
                    return ShortCharacterReference_cent;
                }
            }
            break;
        case 'o':
            switch(string[2]) {
            case 'p':
                switch(string[3]) {
                case 'y':
                    return ShortCharacterReference_copy;
                }
            }
        }
        break;
    case 'e':
        switch(string[1]) {
        case 'u':
            switch(string[2]) {
            case 'm':
                switch(string[3]) {
                case 'l':
                    return ShortCharacterReference_euml;
                }
            }
        }
        break;
    case 'i':
        switch(string[1]) {
        case 'u':
            switch(string[2]) {
            case 'm':
                switch(string[3]) {
                case 'l':
                    return ShortCharacterReference_iuml;
                }
            }
        }
        break;
    case 'm':
        switch(string[1]) {
        case 'a':
            switch(string[2]) {
            case 'c':
                switch(string[3]) {
                case 'r':
                    return ShortCharacterReference_macr;
                }
            }
        }
        break;
    case 'n':
        switch(string[1]) {
        case 'b':
            switch(string[2]) {
            case 's':
                switch(string[3]) {
                case 'p':
                    return ShortCharacterReference_nbsp;
                }
            }
        }
        break;
    case 'o':
        switch(string[1]) {
        case 'r':
            switch(string[2]) {
            case 'd':
                switch(string[3]) {
                case 'f':
                    return ShortCharacterReference_ordf;
                    break;
                case 'm':
                    return ShortCharacterReference_ordm;
                }
            }
            break;
        case 'u':
            switch(string[2]) {
            case 'm':
                switch(string[3]) {
                case 'l':
                    return ShortCharacterReference_ouml;
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
                    return ShortCharacterReference_para;
                }
            }
        }
        break;
    case 'q':
        switch(string[1]) {
        case 'u':
            switch(string[2]) {
            case 'o':
                switch(string[3]) {
                case 't':
                    return ShortCharacterReference_quot;
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
                    return ShortCharacterReference_sect;
                }
            }
            break;
        case 'u':
            switch(string[2]) {
            case 'p':
                switch(string[3]) {
                case '1':
                    return ShortCharacterReference_sup1;
                    break;
                case '2':
                    return ShortCharacterReference_sup2;
                    break;
                case '3':
                    return ShortCharacterReference_sup3;
                }
            }
        }
        break;
    case 'u':
        switch(string[1]) {
        case 'u':
            switch(string[2]) {
            case 'm':
                switch(string[3]) {
                case 'l':
                    return ShortCharacterReference_uuml;
                }
            }
        }
        break;
    case 'y':
        switch(string[1]) {
        case 'u':
            switch(string[2]) {
            case 'm':
                switch(string[3]) {
                case 'l':
                    return ShortCharacterReference_yuml;
                }
            }
        }
    }
    return ShortCharacterReference_Unknown;
}
static enum ShortCharacterReference lookup_short_character_reference5(const char *string)
{
    switch(string[0]) {
    case 'A':
        switch(string[1]) {
        case 'E':
            switch(string[2]) {
            case 'l':
                switch(string[3]) {
                case 'i':
                    switch(string[4]) {
                    case 'g':
                        return ShortCharacterReference_AElig;
                    }
                }
            }
            break;
        case 'c':
            switch(string[2]) {
            case 'i':
                switch(string[3]) {
                case 'r':
                    switch(string[4]) {
                    case 'c':
                        return ShortCharacterReference_Acirc;
                    }
                }
            }
            break;
        case 'r':
            switch(string[2]) {
            case 'i':
                switch(string[3]) {
                case 'n':
                    switch(string[4]) {
                    case 'g':
                        return ShortCharacterReference_Aring;
                    }
                }
            }
        }
        break;
    case 'E':
        switch(string[1]) {
        case 'c':
            switch(string[2]) {
            case 'i':
                switch(string[3]) {
                case 'r':
                    switch(string[4]) {
                    case 'c':
                        return ShortCharacterReference_Ecirc;
                    }
                }
            }
        }
        break;
    case 'I':
        switch(string[1]) {
        case 'c':
            switch(string[2]) {
            case 'i':
                switch(string[3]) {
                case 'r':
                    switch(string[4]) {
                    case 'c':
                        return ShortCharacterReference_Icirc;
                    }
                }
            }
        }
        break;
    case 'O':
        switch(string[1]) {
        case 'c':
            switch(string[2]) {
            case 'i':
                switch(string[3]) {
                case 'r':
                    switch(string[4]) {
                    case 'c':
                        return ShortCharacterReference_Ocirc;
                    }
                }
            }
        }
        break;
    case 'T':
        switch(string[1]) {
        case 'H':
            switch(string[2]) {
            case 'O':
                switch(string[3]) {
                case 'R':
                    switch(string[4]) {
                    case 'N':
                        return ShortCharacterReference_THORN;
                    }
                }
            }
        }
        break;
    case 'U':
        switch(string[1]) {
        case 'c':
            switch(string[2]) {
            case 'i':
                switch(string[3]) {
                case 'r':
                    switch(string[4]) {
                    case 'c':
                        return ShortCharacterReference_Ucirc;
                    }
                }
            }
        }
        break;
    case 'a':
        switch(string[1]) {
        case 'c':
            switch(string[2]) {
            case 'i':
                switch(string[3]) {
                case 'r':
                    switch(string[4]) {
                    case 'c':
                        return ShortCharacterReference_acirc;
                    }
                }
                break;
            case 'u':
                switch(string[3]) {
                case 't':
                    switch(string[4]) {
                    case 'e':
                        return ShortCharacterReference_acute;
                    }
                }
            }
            break;
        case 'e':
            switch(string[2]) {
            case 'l':
                switch(string[3]) {
                case 'i':
                    switch(string[4]) {
                    case 'g':
                        return ShortCharacterReference_aelig;
                    }
                }
            }
            break;
        case 'r':
            switch(string[2]) {
            case 'i':
                switch(string[3]) {
                case 'n':
                    switch(string[4]) {
                    case 'g':
                        return ShortCharacterReference_aring;
                    }
                }
            }
        }
        break;
    case 'c':
        switch(string[1]) {
        case 'e':
            switch(string[2]) {
            case 'd':
                switch(string[3]) {
                case 'i':
                    switch(string[4]) {
                    case 'l':
                        return ShortCharacterReference_cedil;
                    }
                }
            }
        }
        break;
    case 'e':
        switch(string[1]) {
        case 'c':
            switch(string[2]) {
            case 'i':
                switch(string[3]) {
                case 'r':
                    switch(string[4]) {
                    case 'c':
                        return ShortCharacterReference_ecirc;
                    }
                }
            }
        }
        break;
    case 'i':
        switch(string[1]) {
        case 'c':
            switch(string[2]) {
            case 'i':
                switch(string[3]) {
                case 'r':
                    switch(string[4]) {
                    case 'c':
                        return ShortCharacterReference_icirc;
                    }
                }
            }
            break;
        case 'e':
            switch(string[2]) {
            case 'x':
                switch(string[3]) {
                case 'c':
                    switch(string[4]) {
                    case 'l':
                        return ShortCharacterReference_iexcl;
                    }
                }
            }
        }
        break;
    case 'l':
        switch(string[1]) {
        case 'a':
            switch(string[2]) {
            case 'q':
                switch(string[3]) {
                case 'u':
                    switch(string[4]) {
                    case 'o':
                        return ShortCharacterReference_laquo;
                    }
                }
            }
        }
        break;
    case 'm':
        switch(string[1]) {
        case 'i':
            switch(string[2]) {
            case 'c':
                switch(string[3]) {
                case 'r':
                    switch(string[4]) {
                    case 'o':
                        return ShortCharacterReference_micro;
                    }
                }
            }
        }
        break;
    case 'o':
        switch(string[1]) {
        case 'c':
            switch(string[2]) {
            case 'i':
                switch(string[3]) {
                case 'r':
                    switch(string[4]) {
                    case 'c':
                        return ShortCharacterReference_ocirc;
                    }
                }
            }
        }
        break;
    case 'p':
        switch(string[1]) {
        case 'o':
            switch(string[2]) {
            case 'u':
                switch(string[3]) {
                case 'n':
                    switch(string[4]) {
                    case 'd':
                        return ShortCharacterReference_pound;
                    }
                }
            }
        }
        break;
    case 'r':
        switch(string[1]) {
        case 'a':
            switch(string[2]) {
            case 'q':
                switch(string[3]) {
                case 'u':
                    switch(string[4]) {
                    case 'o':
                        return ShortCharacterReference_raquo;
                    }
                }
            }
        }
        break;
    case 's':
        switch(string[1]) {
        case 'z':
            switch(string[2]) {
            case 'l':
                switch(string[3]) {
                case 'i':
                    switch(string[4]) {
                    case 'g':
                        return ShortCharacterReference_szlig;
                    }
                }
            }
        }
        break;
    case 't':
        switch(string[1]) {
        case 'h':
            switch(string[2]) {
            case 'o':
                switch(string[3]) {
                case 'r':
                    switch(string[4]) {
                    case 'n':
                        return ShortCharacterReference_thorn;
                    }
                }
            }
            break;
        case 'i':
            switch(string[2]) {
            case 'm':
                switch(string[3]) {
                case 'e':
                    switch(string[4]) {
                    case 's':
                        return ShortCharacterReference_times;
                    }
                }
            }
        }
        break;
    case 'u':
        switch(string[1]) {
        case 'c':
            switch(string[2]) {
            case 'i':
                switch(string[3]) {
                case 'r':
                    switch(string[4]) {
                    case 'c':
                        return ShortCharacterReference_ucirc;
                    }
                }
            }
        }
    }
    return ShortCharacterReference_Unknown;
}
static enum ShortCharacterReference lookup_short_character_reference6(const char *string)
{
    switch(string[0]) {
    case 'A':
        switch(string[1]) {
        case 'a':
            switch(string[2]) {
            case 'c':
                switch(string[3]) {
                case 'u':
                    switch(string[4]) {
                    case 't':
                        switch(string[5]) {
                        case 'e':
                            return ShortCharacterReference_Aacute;
                        }
                    }
                }
            }
            break;
        case 'g':
            switch(string[2]) {
            case 'r':
                switch(string[3]) {
                case 'a':
                    switch(string[4]) {
                    case 'v':
                        switch(string[5]) {
                        case 'e':
                            return ShortCharacterReference_Agrave;
                        }
                    }
                }
            }
            break;
        case 't':
            switch(string[2]) {
            case 'i':
                switch(string[3]) {
                case 'l':
                    switch(string[4]) {
                    case 'd':
                        switch(string[5]) {
                        case 'e':
                            return ShortCharacterReference_Atilde;
                        }
                    }
                }
            }
        }
        break;
    case 'C':
        switch(string[1]) {
        case 'c':
            switch(string[2]) {
            case 'e':
                switch(string[3]) {
                case 'd':
                    switch(string[4]) {
                    case 'i':
                        switch(string[5]) {
                        case 'l':
                            return ShortCharacterReference_Ccedil;
                        }
                    }
                }
            }
        }
        break;
    case 'E':
        switch(string[1]) {
        case 'a':
            switch(string[2]) {
            case 'c':
                switch(string[3]) {
                case 'u':
                    switch(string[4]) {
                    case 't':
                        switch(string[5]) {
                        case 'e':
                            return ShortCharacterReference_Eacute;
                        }
                    }
                }
            }
            break;
        case 'g':
            switch(string[2]) {
            case 'r':
                switch(string[3]) {
                case 'a':
                    switch(string[4]) {
                    case 'v':
                        switch(string[5]) {
                        case 'e':
                            return ShortCharacterReference_Egrave;
                        }
                    }
                }
            }
        }
        break;
    case 'I':
        switch(string[1]) {
        case 'a':
            switch(string[2]) {
            case 'c':
                switch(string[3]) {
                case 'u':
                    switch(string[4]) {
                    case 't':
                        switch(string[5]) {
                        case 'e':
                            return ShortCharacterReference_Iacute;
                        }
                    }
                }
            }
            break;
        case 'g':
            switch(string[2]) {
            case 'r':
                switch(string[3]) {
                case 'a':
                    switch(string[4]) {
                    case 'v':
                        switch(string[5]) {
                        case 'e':
                            return ShortCharacterReference_Igrave;
                        }
                    }
                }
            }
        }
        break;
    case 'N':
        switch(string[1]) {
        case 't':
            switch(string[2]) {
            case 'i':
                switch(string[3]) {
                case 'l':
                    switch(string[4]) {
                    case 'd':
                        switch(string[5]) {
                        case 'e':
                            return ShortCharacterReference_Ntilde;
                        }
                    }
                }
            }
        }
        break;
    case 'O':
        switch(string[1]) {
        case 'a':
            switch(string[2]) {
            case 'c':
                switch(string[3]) {
                case 'u':
                    switch(string[4]) {
                    case 't':
                        switch(string[5]) {
                        case 'e':
                            return ShortCharacterReference_Oacute;
                        }
                    }
                }
            }
            break;
        case 'g':
            switch(string[2]) {
            case 'r':
                switch(string[3]) {
                case 'a':
                    switch(string[4]) {
                    case 'v':
                        switch(string[5]) {
                        case 'e':
                            return ShortCharacterReference_Ograve;
                        }
                    }
                }
            }
            break;
        case 's':
            switch(string[2]) {
            case 'l':
                switch(string[3]) {
                case 'a':
                    switch(string[4]) {
                    case 's':
                        switch(string[5]) {
                        case 'h':
                            return ShortCharacterReference_Oslash;
                        }
                    }
                }
            }
            break;
        case 't':
            switch(string[2]) {
            case 'i':
                switch(string[3]) {
                case 'l':
                    switch(string[4]) {
                    case 'd':
                        switch(string[5]) {
                        case 'e':
                            return ShortCharacterReference_Otilde;
                        }
                    }
                }
            }
        }
        break;
    case 'U':
        switch(string[1]) {
        case 'a':
            switch(string[2]) {
            case 'c':
                switch(string[3]) {
                case 'u':
                    switch(string[4]) {
                    case 't':
                        switch(string[5]) {
                        case 'e':
                            return ShortCharacterReference_Uacute;
                        }
                    }
                }
            }
            break;
        case 'g':
            switch(string[2]) {
            case 'r':
                switch(string[3]) {
                case 'a':
                    switch(string[4]) {
                    case 'v':
                        switch(string[5]) {
                        case 'e':
                            return ShortCharacterReference_Ugrave;
                        }
                    }
                }
            }
        }
        break;
    case 'Y':
        switch(string[1]) {
        case 'a':
            switch(string[2]) {
            case 'c':
                switch(string[3]) {
                case 'u':
                    switch(string[4]) {
                    case 't':
                        switch(string[5]) {
                        case 'e':
                            return ShortCharacterReference_Yacute;
                        }
                    }
                }
            }
        }
        break;
    case 'a':
        switch(string[1]) {
        case 'a':
            switch(string[2]) {
            case 'c':
                switch(string[3]) {
                case 'u':
                    switch(string[4]) {
                    case 't':
                        switch(string[5]) {
                        case 'e':
                            return ShortCharacterReference_aacute;
                        }
                    }
                }
            }
            break;
        case 'g':
            switch(string[2]) {
            case 'r':
                switch(string[3]) {
                case 'a':
                    switch(string[4]) {
                    case 'v':
                        switch(string[5]) {
                        case 'e':
                            return ShortCharacterReference_agrave;
                        }
                    }
                }
            }
            break;
        case 't':
            switch(string[2]) {
            case 'i':
                switch(string[3]) {
                case 'l':
                    switch(string[4]) {
                    case 'd':
                        switch(string[5]) {
                        case 'e':
                            return ShortCharacterReference_atilde;
                        }
                    }
                }
            }
        }
        break;
    case 'b':
        switch(string[1]) {
        case 'r':
            switch(string[2]) {
            case 'v':
                switch(string[3]) {
                case 'b':
                    switch(string[4]) {
                    case 'a':
                        switch(string[5]) {
                        case 'r':
                            return ShortCharacterReference_brvbar;
                        }
                    }
                }
            }
        }
        break;
    case 'c':
        switch(string[1]) {
        case 'c':
            switch(string[2]) {
            case 'e':
                switch(string[3]) {
                case 'd':
                    switch(string[4]) {
                    case 'i':
                        switch(string[5]) {
                        case 'l':
                            return ShortCharacterReference_ccedil;
                        }
                    }
                }
            }
            break;
        case 'u':
            switch(string[2]) {
            case 'r':
                switch(string[3]) {
                case 'r':
                    switch(string[4]) {
                    case 'e':
                        switch(string[5]) {
                        case 'n':
                            return ShortCharacterReference_curren;
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
            case 'v':
                switch(string[3]) {
                case 'i':
                    switch(string[4]) {
                    case 'd':
                        switch(string[5]) {
                        case 'e':
                            return ShortCharacterReference_divide;
                        }
                    }
                }
            }
        }
        break;
    case 'e':
        switch(string[1]) {
        case 'a':
            switch(string[2]) {
            case 'c':
                switch(string[3]) {
                case 'u':
                    switch(string[4]) {
                    case 't':
                        switch(string[5]) {
                        case 'e':
                            return ShortCharacterReference_eacute;
                        }
                    }
                }
            }
            break;
        case 'g':
            switch(string[2]) {
            case 'r':
                switch(string[3]) {
                case 'a':
                    switch(string[4]) {
                    case 'v':
                        switch(string[5]) {
                        case 'e':
                            return ShortCharacterReference_egrave;
                        }
                    }
                }
            }
        }
        break;
    case 'f':
        switch(string[1]) {
        case 'r':
            switch(string[2]) {
            case 'a':
                switch(string[3]) {
                case 'c':
                    switch(string[4]) {
                    case '1':
                        switch(string[5]) {
                        case '2':
                            return ShortCharacterReference_frac12;
                            break;
                        case '4':
                            return ShortCharacterReference_frac14;
                        }
                        break;
                    case '3':
                        switch(string[5]) {
                        case '4':
                            return ShortCharacterReference_frac34;
                        }
                    }
                }
            }
        }
        break;
    case 'i':
        switch(string[1]) {
        case 'a':
            switch(string[2]) {
            case 'c':
                switch(string[3]) {
                case 'u':
                    switch(string[4]) {
                    case 't':
                        switch(string[5]) {
                        case 'e':
                            return ShortCharacterReference_iacute;
                        }
                    }
                }
            }
            break;
        case 'g':
            switch(string[2]) {
            case 'r':
                switch(string[3]) {
                case 'a':
                    switch(string[4]) {
                    case 'v':
                        switch(string[5]) {
                        case 'e':
                            return ShortCharacterReference_igrave;
                        }
                    }
                }
            }
            break;
        case 'q':
            switch(string[2]) {
            case 'u':
                switch(string[3]) {
                case 'e':
                    switch(string[4]) {
                    case 's':
                        switch(string[5]) {
                        case 't':
                            return ShortCharacterReference_iquest;
                        }
                    }
                }
            }
        }
        break;
    case 'm':
        switch(string[1]) {
        case 'i':
            switch(string[2]) {
            case 'd':
                switch(string[3]) {
                case 'd':
                    switch(string[4]) {
                    case 'o':
                        switch(string[5]) {
                        case 't':
                            return ShortCharacterReference_middot;
                        }
                    }
                }
            }
        }
        break;
    case 'n':
        switch(string[1]) {
        case 't':
            switch(string[2]) {
            case 'i':
                switch(string[3]) {
                case 'l':
                    switch(string[4]) {
                    case 'd':
                        switch(string[5]) {
                        case 'e':
                            return ShortCharacterReference_ntilde;
                        }
                    }
                }
            }
        }
        break;
    case 'o':
        switch(string[1]) {
        case 'a':
            switch(string[2]) {
            case 'c':
                switch(string[3]) {
                case 'u':
                    switch(string[4]) {
                    case 't':
                        switch(string[5]) {
                        case 'e':
                            return ShortCharacterReference_oacute;
                        }
                    }
                }
            }
            break;
        case 'g':
            switch(string[2]) {
            case 'r':
                switch(string[3]) {
                case 'a':
                    switch(string[4]) {
                    case 'v':
                        switch(string[5]) {
                        case 'e':
                            return ShortCharacterReference_ograve;
                        }
                    }
                }
            }
            break;
        case 's':
            switch(string[2]) {
            case 'l':
                switch(string[3]) {
                case 'a':
                    switch(string[4]) {
                    case 's':
                        switch(string[5]) {
                        case 'h':
                            return ShortCharacterReference_oslash;
                        }
                    }
                }
            }
            break;
        case 't':
            switch(string[2]) {
            case 'i':
                switch(string[3]) {
                case 'l':
                    switch(string[4]) {
                    case 'd':
                        switch(string[5]) {
                        case 'e':
                            return ShortCharacterReference_otilde;
                        }
                    }
                }
            }
        }
        break;
    case 'p':
        switch(string[1]) {
        case 'l':
            switch(string[2]) {
            case 'u':
                switch(string[3]) {
                case 's':
                    switch(string[4]) {
                    case 'm':
                        switch(string[5]) {
                        case 'n':
                            return ShortCharacterReference_plusmn;
                        }
                    }
                }
            }
        }
        break;
    case 'u':
        switch(string[1]) {
        case 'a':
            switch(string[2]) {
            case 'c':
                switch(string[3]) {
                case 'u':
                    switch(string[4]) {
                    case 't':
                        switch(string[5]) {
                        case 'e':
                            return ShortCharacterReference_uacute;
                        }
                    }
                }
            }
            break;
        case 'g':
            switch(string[2]) {
            case 'r':
                switch(string[3]) {
                case 'a':
                    switch(string[4]) {
                    case 'v':
                        switch(string[5]) {
                        case 'e':
                            return ShortCharacterReference_ugrave;
                        }
                    }
                }
            }
        }
        break;
    case 'y':
        switch(string[1]) {
        case 'a':
            switch(string[2]) {
            case 'c':
                switch(string[3]) {
                case 'u':
                    switch(string[4]) {
                    case 't':
                        switch(string[5]) {
                        case 'e':
                            return ShortCharacterReference_yacute;
                        }
                    }
                }
            }
        }
    }
    return ShortCharacterReference_Unknown;
}
#endif /* TRIE_HASH_MULTI_BYTE */
static enum ShortCharacterReference lookup_short_character_reference(const char *string, size_t length)
{
    switch (length) {
    case 2:
        return lookup_short_character_reference2(string);
    case 3:
        return lookup_short_character_reference3(string);
    case 4:
        return lookup_short_character_reference4(string);
    case 5:
        return lookup_short_character_reference5(string);
    case 6:
        return lookup_short_character_reference6(string);
    default:
        return ShortCharacterReference_Unknown;
    }
}
#endif                       /* TRIE_HASH_lookup_short_character_reference */
