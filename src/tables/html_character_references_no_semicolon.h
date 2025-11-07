#ifndef TRIE_HASH_lookup_character_reference_no_semicolon
#define TRIE_HASH_lookup_character_reference_no_semicolon
#include <stddef.h>
#include <stdint.h>
enum CharacterReferenceNoSemicolon {
    CRNS_AMP = 2,
    CRNS_AElig = 1,
    CRNS_Aacute = 3,
    CRNS_Acirc = 4,
    CRNS_Agrave = 5,
    CRNS_Aring = 6,
    CRNS_Atilde = 7,
    CRNS_Auml = 8,
    CRNS_COPY = 9,
    CRNS_Ccedil = 10,
    CRNS_ETH = 11,
    CRNS_Eacute = 12,
    CRNS_Ecirc = 13,
    CRNS_Egrave = 14,
    CRNS_Euml = 15,
    CRNS_GT = 16,
    CRNS_Iacute = 17,
    CRNS_Icirc = 18,
    CRNS_Igrave = 19,
    CRNS_Iuml = 20,
    CRNS_LT = 21,
    CRNS_Ntilde = 22,
    CRNS_Oacute = 23,
    CRNS_Ocirc = 24,
    CRNS_Ograve = 25,
    CRNS_Oslash = 26,
    CRNS_Otilde = 27,
    CRNS_Ouml = 28,
    CRNS_QUOT = 29,
    CRNS_REG = 30,
    CRNS_THORN = 31,
    CRNS_Uacute = 32,
    CRNS_Ucirc = 33,
    CRNS_Ugrave = 34,
    CRNS_Uuml = 35,
    CRNS_Yacute = 36,
    CRNS_amp = 42,
    CRNS_aacute = 37,
    CRNS_acirc = 38,
    CRNS_acute = 39,
    CRNS_aelig = 40,
    CRNS_agrave = 41,
    CRNS_aring = 43,
    CRNS_atilde = 44,
    CRNS_auml = 45,
    CRNS_brvbar = 46,
    CRNS_ccedil = 47,
    CRNS_cedil = 48,
    CRNS_cent = 49,
    CRNS_copy = 50,
    CRNS_curren = 51,
    CRNS_deg = 52,
    CRNS_divide = 53,
    CRNS_eth = 57,
    CRNS_eacute = 54,
    CRNS_ecirc = 55,
    CRNS_egrave = 56,
    CRNS_euml = 58,
    CRNS_frac12 = 59,
    CRNS_frac14 = 60,
    CRNS_frac34 = 61,
    CRNS_gt = 62,
    CRNS_iacute = 63,
    CRNS_icirc = 64,
    CRNS_iexcl = 65,
    CRNS_igrave = 66,
    CRNS_iquest = 67,
    CRNS_iuml = 68,
    CRNS_lt = 70,
    CRNS_laquo = 69,
    CRNS_macr = 71,
    CRNS_micro = 72,
    CRNS_middot = 73,
    CRNS_not = 75,
    CRNS_nbsp = 74,
    CRNS_ntilde = 76,
    CRNS_oacute = 77,
    CRNS_ocirc = 78,
    CRNS_ograve = 79,
    CRNS_ordf = 80,
    CRNS_ordm = 81,
    CRNS_oslash = 82,
    CRNS_otilde = 83,
    CRNS_ouml = 84,
    CRNS_para = 85,
    CRNS_plusmn = 86,
    CRNS_pound = 87,
    CRNS_quot = 88,
    CRNS_reg = 90,
    CRNS_raquo = 89,
    CRNS_shy = 92,
    CRNS_sect = 91,
    CRNS_sup1 = 93,
    CRNS_sup2 = 94,
    CRNS_sup3 = 95,
    CRNS_szlig = 96,
    CRNS_thorn = 97,
    CRNS_times = 98,
    CRNS_uml = 102,
    CRNS_uacute = 99,
    CRNS_ucirc = 100,
    CRNS_ugrave = 101,
    CRNS_uuml = 103,
    CRNS_yen = 105,
    CRNS_yacute = 104,
    CRNS_yuml = 106,
    CRNS_Unknown = 0,
};
static enum CharacterReferenceNoSemicolon lookup_character_reference_no_semicolon(const char *string, size_t length);
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
static enum CharacterReferenceNoSemicolon lookup_character_reference_no_semicolon2(const char *string)
{
    switch(string[0]) {
    case 0| onechar('G', 0, 8):
        switch(string[1]) {
        case 0| onechar('T', 0, 8):
            return CRNS_GT;
        }
        break;
    case 0| onechar('L', 0, 8):
        switch(string[1]) {
        case 0| onechar('T', 0, 8):
            return CRNS_LT;
        }
        break;
    case 0| onechar('g', 0, 8):
        switch(string[1]) {
        case 0| onechar('t', 0, 8):
            return CRNS_gt;
        }
        break;
    case 0| onechar('l', 0, 8):
        switch(string[1]) {
        case 0| onechar('t', 0, 8):
            return CRNS_lt;
        }
    }
    return CRNS_Unknown;
}
static enum CharacterReferenceNoSemicolon lookup_character_reference_no_semicolon3(const char *string)
{
    switch(string[0]) {
    case 0| onechar('A', 0, 8):
        switch(string[1]) {
        case 0| onechar('M', 0, 8):
            switch(string[2]) {
            case 0| onechar('P', 0, 8):
                return CRNS_AMP;
            }
        }
        break;
    case 0| onechar('E', 0, 8):
        switch(string[1]) {
        case 0| onechar('T', 0, 8):
            switch(string[2]) {
            case 0| onechar('H', 0, 8):
                return CRNS_ETH;
            }
        }
        break;
    case 0| onechar('R', 0, 8):
        switch(string[1]) {
        case 0| onechar('E', 0, 8):
            switch(string[2]) {
            case 0| onechar('G', 0, 8):
                return CRNS_REG;
            }
        }
        break;
    case 0| onechar('a', 0, 8):
        switch(string[1]) {
        case 0| onechar('m', 0, 8):
            switch(string[2]) {
            case 0| onechar('p', 0, 8):
                return CRNS_amp;
            }
        }
        break;
    case 0| onechar('d', 0, 8):
        switch(string[1]) {
        case 0| onechar('e', 0, 8):
            switch(string[2]) {
            case 0| onechar('g', 0, 8):
                return CRNS_deg;
            }
        }
        break;
    case 0| onechar('e', 0, 8):
        switch(string[1]) {
        case 0| onechar('t', 0, 8):
            switch(string[2]) {
            case 0| onechar('h', 0, 8):
                return CRNS_eth;
            }
        }
        break;
    case 0| onechar('n', 0, 8):
        switch(string[1]) {
        case 0| onechar('o', 0, 8):
            switch(string[2]) {
            case 0| onechar('t', 0, 8):
                return CRNS_not;
            }
        }
        break;
    case 0| onechar('r', 0, 8):
        switch(string[1]) {
        case 0| onechar('e', 0, 8):
            switch(string[2]) {
            case 0| onechar('g', 0, 8):
                return CRNS_reg;
            }
        }
        break;
    case 0| onechar('s', 0, 8):
        switch(string[1]) {
        case 0| onechar('h', 0, 8):
            switch(string[2]) {
            case 0| onechar('y', 0, 8):
                return CRNS_shy;
            }
        }
        break;
    case 0| onechar('u', 0, 8):
        switch(string[1]) {
        case 0| onechar('m', 0, 8):
            switch(string[2]) {
            case 0| onechar('l', 0, 8):
                return CRNS_uml;
            }
        }
        break;
    case 0| onechar('y', 0, 8):
        switch(string[1]) {
        case 0| onechar('e', 0, 8):
            switch(string[2]) {
            case 0| onechar('n', 0, 8):
                return CRNS_yen;
            }
        }
    }
    return CRNS_Unknown;
}
static enum CharacterReferenceNoSemicolon lookup_character_reference_no_semicolon4(const char *string)
{
    switch(*((triehash_uu32*) &string[0])) {
    case 0| onechar('A', 0, 32)| onechar('u', 8, 32)| onechar('m', 16, 32)| onechar('l', 24, 32):
        return CRNS_Auml;
        break;
    case 0| onechar('C', 0, 32)| onechar('O', 8, 32)| onechar('P', 16, 32)| onechar('Y', 24, 32):
        return CRNS_COPY;
        break;
    case 0| onechar('E', 0, 32)| onechar('u', 8, 32)| onechar('m', 16, 32)| onechar('l', 24, 32):
        return CRNS_Euml;
        break;
    case 0| onechar('I', 0, 32)| onechar('u', 8, 32)| onechar('m', 16, 32)| onechar('l', 24, 32):
        return CRNS_Iuml;
        break;
    case 0| onechar('O', 0, 32)| onechar('u', 8, 32)| onechar('m', 16, 32)| onechar('l', 24, 32):
        return CRNS_Ouml;
        break;
    case 0| onechar('Q', 0, 32)| onechar('U', 8, 32)| onechar('O', 16, 32)| onechar('T', 24, 32):
        return CRNS_QUOT;
        break;
    case 0| onechar('U', 0, 32)| onechar('u', 8, 32)| onechar('m', 16, 32)| onechar('l', 24, 32):
        return CRNS_Uuml;
        break;
    case 0| onechar('a', 0, 32)| onechar('u', 8, 32)| onechar('m', 16, 32)| onechar('l', 24, 32):
        return CRNS_auml;
        break;
    case 0| onechar('c', 0, 32)| onechar('e', 8, 32)| onechar('n', 16, 32)| onechar('t', 24, 32):
        return CRNS_cent;
        break;
    case 0| onechar('c', 0, 32)| onechar('o', 8, 32)| onechar('p', 16, 32)| onechar('y', 24, 32):
        return CRNS_copy;
        break;
    case 0| onechar('e', 0, 32)| onechar('u', 8, 32)| onechar('m', 16, 32)| onechar('l', 24, 32):
        return CRNS_euml;
        break;
    case 0| onechar('i', 0, 32)| onechar('u', 8, 32)| onechar('m', 16, 32)| onechar('l', 24, 32):
        return CRNS_iuml;
        break;
    case 0| onechar('m', 0, 32)| onechar('a', 8, 32)| onechar('c', 16, 32)| onechar('r', 24, 32):
        return CRNS_macr;
        break;
    case 0| onechar('n', 0, 32)| onechar('b', 8, 32)| onechar('s', 16, 32)| onechar('p', 24, 32):
        return CRNS_nbsp;
        break;
    case 0| onechar('o', 0, 32)| onechar('r', 8, 32)| onechar('d', 16, 32)| onechar('f', 24, 32):
        return CRNS_ordf;
        break;
    case 0| onechar('o', 0, 32)| onechar('r', 8, 32)| onechar('d', 16, 32)| onechar('m', 24, 32):
        return CRNS_ordm;
        break;
    case 0| onechar('o', 0, 32)| onechar('u', 8, 32)| onechar('m', 16, 32)| onechar('l', 24, 32):
        return CRNS_ouml;
        break;
    case 0| onechar('p', 0, 32)| onechar('a', 8, 32)| onechar('r', 16, 32)| onechar('a', 24, 32):
        return CRNS_para;
        break;
    case 0| onechar('q', 0, 32)| onechar('u', 8, 32)| onechar('o', 16, 32)| onechar('t', 24, 32):
        return CRNS_quot;
        break;
    case 0| onechar('s', 0, 32)| onechar('e', 8, 32)| onechar('c', 16, 32)| onechar('t', 24, 32):
        return CRNS_sect;
        break;
    case 0| onechar('s', 0, 32)| onechar('u', 8, 32)| onechar('p', 16, 32)| onechar('1', 24, 32):
        return CRNS_sup1;
        break;
    case 0| onechar('s', 0, 32)| onechar('u', 8, 32)| onechar('p', 16, 32)| onechar('2', 24, 32):
        return CRNS_sup2;
        break;
    case 0| onechar('s', 0, 32)| onechar('u', 8, 32)| onechar('p', 16, 32)| onechar('3', 24, 32):
        return CRNS_sup3;
        break;
    case 0| onechar('u', 0, 32)| onechar('u', 8, 32)| onechar('m', 16, 32)| onechar('l', 24, 32):
        return CRNS_uuml;
        break;
    case 0| onechar('y', 0, 32)| onechar('u', 8, 32)| onechar('m', 16, 32)| onechar('l', 24, 32):
        return CRNS_yuml;
    }
    return CRNS_Unknown;
}
static enum CharacterReferenceNoSemicolon lookup_character_reference_no_semicolon5(const char *string)
{
    switch(*((triehash_uu32*) &string[0])) {
    case 0| onechar('A', 0, 32)| onechar('E', 8, 32)| onechar('l', 16, 32)| onechar('i', 24, 32):
        switch(string[4]) {
        case 0| onechar('g', 0, 8):
            return CRNS_AElig;
        }
        break;
    case 0| onechar('A', 0, 32)| onechar('c', 8, 32)| onechar('i', 16, 32)| onechar('r', 24, 32):
        switch(string[4]) {
        case 0| onechar('c', 0, 8):
            return CRNS_Acirc;
        }
        break;
    case 0| onechar('A', 0, 32)| onechar('r', 8, 32)| onechar('i', 16, 32)| onechar('n', 24, 32):
        switch(string[4]) {
        case 0| onechar('g', 0, 8):
            return CRNS_Aring;
        }
        break;
    case 0| onechar('E', 0, 32)| onechar('c', 8, 32)| onechar('i', 16, 32)| onechar('r', 24, 32):
        switch(string[4]) {
        case 0| onechar('c', 0, 8):
            return CRNS_Ecirc;
        }
        break;
    case 0| onechar('I', 0, 32)| onechar('c', 8, 32)| onechar('i', 16, 32)| onechar('r', 24, 32):
        switch(string[4]) {
        case 0| onechar('c', 0, 8):
            return CRNS_Icirc;
        }
        break;
    case 0| onechar('O', 0, 32)| onechar('c', 8, 32)| onechar('i', 16, 32)| onechar('r', 24, 32):
        switch(string[4]) {
        case 0| onechar('c', 0, 8):
            return CRNS_Ocirc;
        }
        break;
    case 0| onechar('T', 0, 32)| onechar('H', 8, 32)| onechar('O', 16, 32)| onechar('R', 24, 32):
        switch(string[4]) {
        case 0| onechar('N', 0, 8):
            return CRNS_THORN;
        }
        break;
    case 0| onechar('U', 0, 32)| onechar('c', 8, 32)| onechar('i', 16, 32)| onechar('r', 24, 32):
        switch(string[4]) {
        case 0| onechar('c', 0, 8):
            return CRNS_Ucirc;
        }
        break;
    case 0| onechar('a', 0, 32)| onechar('c', 8, 32)| onechar('i', 16, 32)| onechar('r', 24, 32):
        switch(string[4]) {
        case 0| onechar('c', 0, 8):
            return CRNS_acirc;
        }
        break;
    case 0| onechar('a', 0, 32)| onechar('c', 8, 32)| onechar('u', 16, 32)| onechar('t', 24, 32):
        switch(string[4]) {
        case 0| onechar('e', 0, 8):
            return CRNS_acute;
        }
        break;
    case 0| onechar('a', 0, 32)| onechar('e', 8, 32)| onechar('l', 16, 32)| onechar('i', 24, 32):
        switch(string[4]) {
        case 0| onechar('g', 0, 8):
            return CRNS_aelig;
        }
        break;
    case 0| onechar('a', 0, 32)| onechar('r', 8, 32)| onechar('i', 16, 32)| onechar('n', 24, 32):
        switch(string[4]) {
        case 0| onechar('g', 0, 8):
            return CRNS_aring;
        }
        break;
    case 0| onechar('c', 0, 32)| onechar('e', 8, 32)| onechar('d', 16, 32)| onechar('i', 24, 32):
        switch(string[4]) {
        case 0| onechar('l', 0, 8):
            return CRNS_cedil;
        }
        break;
    case 0| onechar('e', 0, 32)| onechar('c', 8, 32)| onechar('i', 16, 32)| onechar('r', 24, 32):
        switch(string[4]) {
        case 0| onechar('c', 0, 8):
            return CRNS_ecirc;
        }
        break;
    case 0| onechar('i', 0, 32)| onechar('c', 8, 32)| onechar('i', 16, 32)| onechar('r', 24, 32):
        switch(string[4]) {
        case 0| onechar('c', 0, 8):
            return CRNS_icirc;
        }
        break;
    case 0| onechar('i', 0, 32)| onechar('e', 8, 32)| onechar('x', 16, 32)| onechar('c', 24, 32):
        switch(string[4]) {
        case 0| onechar('l', 0, 8):
            return CRNS_iexcl;
        }
        break;
    case 0| onechar('l', 0, 32)| onechar('a', 8, 32)| onechar('q', 16, 32)| onechar('u', 24, 32):
        switch(string[4]) {
        case 0| onechar('o', 0, 8):
            return CRNS_laquo;
        }
        break;
    case 0| onechar('m', 0, 32)| onechar('i', 8, 32)| onechar('c', 16, 32)| onechar('r', 24, 32):
        switch(string[4]) {
        case 0| onechar('o', 0, 8):
            return CRNS_micro;
        }
        break;
    case 0| onechar('o', 0, 32)| onechar('c', 8, 32)| onechar('i', 16, 32)| onechar('r', 24, 32):
        switch(string[4]) {
        case 0| onechar('c', 0, 8):
            return CRNS_ocirc;
        }
        break;
    case 0| onechar('p', 0, 32)| onechar('o', 8, 32)| onechar('u', 16, 32)| onechar('n', 24, 32):
        switch(string[4]) {
        case 0| onechar('d', 0, 8):
            return CRNS_pound;
        }
        break;
    case 0| onechar('r', 0, 32)| onechar('a', 8, 32)| onechar('q', 16, 32)| onechar('u', 24, 32):
        switch(string[4]) {
        case 0| onechar('o', 0, 8):
            return CRNS_raquo;
        }
        break;
    case 0| onechar('s', 0, 32)| onechar('z', 8, 32)| onechar('l', 16, 32)| onechar('i', 24, 32):
        switch(string[4]) {
        case 0| onechar('g', 0, 8):
            return CRNS_szlig;
        }
        break;
    case 0| onechar('t', 0, 32)| onechar('h', 8, 32)| onechar('o', 16, 32)| onechar('r', 24, 32):
        switch(string[4]) {
        case 0| onechar('n', 0, 8):
            return CRNS_thorn;
        }
        break;
    case 0| onechar('t', 0, 32)| onechar('i', 8, 32)| onechar('m', 16, 32)| onechar('e', 24, 32):
        switch(string[4]) {
        case 0| onechar('s', 0, 8):
            return CRNS_times;
        }
        break;
    case 0| onechar('u', 0, 32)| onechar('c', 8, 32)| onechar('i', 16, 32)| onechar('r', 24, 32):
        switch(string[4]) {
        case 0| onechar('c', 0, 8):
            return CRNS_ucirc;
        }
    }
    return CRNS_Unknown;
}
static enum CharacterReferenceNoSemicolon lookup_character_reference_no_semicolon6(const char *string)
{
    switch(*((triehash_uu32*) &string[0])) {
    case 0| onechar('A', 0, 32)| onechar('a', 8, 32)| onechar('c', 16, 32)| onechar('u', 24, 32):
        switch(string[4]) {
        case 0| onechar('t', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return CRNS_Aacute;
            }
        }
        break;
    case 0| onechar('A', 0, 32)| onechar('g', 8, 32)| onechar('r', 16, 32)| onechar('a', 24, 32):
        switch(string[4]) {
        case 0| onechar('v', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return CRNS_Agrave;
            }
        }
        break;
    case 0| onechar('A', 0, 32)| onechar('t', 8, 32)| onechar('i', 16, 32)| onechar('l', 24, 32):
        switch(string[4]) {
        case 0| onechar('d', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return CRNS_Atilde;
            }
        }
        break;
    case 0| onechar('C', 0, 32)| onechar('c', 8, 32)| onechar('e', 16, 32)| onechar('d', 24, 32):
        switch(string[4]) {
        case 0| onechar('i', 0, 8):
            switch(string[5]) {
            case 0| onechar('l', 0, 8):
                return CRNS_Ccedil;
            }
        }
        break;
    case 0| onechar('E', 0, 32)| onechar('a', 8, 32)| onechar('c', 16, 32)| onechar('u', 24, 32):
        switch(string[4]) {
        case 0| onechar('t', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return CRNS_Eacute;
            }
        }
        break;
    case 0| onechar('E', 0, 32)| onechar('g', 8, 32)| onechar('r', 16, 32)| onechar('a', 24, 32):
        switch(string[4]) {
        case 0| onechar('v', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return CRNS_Egrave;
            }
        }
        break;
    case 0| onechar('I', 0, 32)| onechar('a', 8, 32)| onechar('c', 16, 32)| onechar('u', 24, 32):
        switch(string[4]) {
        case 0| onechar('t', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return CRNS_Iacute;
            }
        }
        break;
    case 0| onechar('I', 0, 32)| onechar('g', 8, 32)| onechar('r', 16, 32)| onechar('a', 24, 32):
        switch(string[4]) {
        case 0| onechar('v', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return CRNS_Igrave;
            }
        }
        break;
    case 0| onechar('N', 0, 32)| onechar('t', 8, 32)| onechar('i', 16, 32)| onechar('l', 24, 32):
        switch(string[4]) {
        case 0| onechar('d', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return CRNS_Ntilde;
            }
        }
        break;
    case 0| onechar('O', 0, 32)| onechar('a', 8, 32)| onechar('c', 16, 32)| onechar('u', 24, 32):
        switch(string[4]) {
        case 0| onechar('t', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return CRNS_Oacute;
            }
        }
        break;
    case 0| onechar('O', 0, 32)| onechar('g', 8, 32)| onechar('r', 16, 32)| onechar('a', 24, 32):
        switch(string[4]) {
        case 0| onechar('v', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return CRNS_Ograve;
            }
        }
        break;
    case 0| onechar('O', 0, 32)| onechar('s', 8, 32)| onechar('l', 16, 32)| onechar('a', 24, 32):
        switch(string[4]) {
        case 0| onechar('s', 0, 8):
            switch(string[5]) {
            case 0| onechar('h', 0, 8):
                return CRNS_Oslash;
            }
        }
        break;
    case 0| onechar('O', 0, 32)| onechar('t', 8, 32)| onechar('i', 16, 32)| onechar('l', 24, 32):
        switch(string[4]) {
        case 0| onechar('d', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return CRNS_Otilde;
            }
        }
        break;
    case 0| onechar('U', 0, 32)| onechar('a', 8, 32)| onechar('c', 16, 32)| onechar('u', 24, 32):
        switch(string[4]) {
        case 0| onechar('t', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return CRNS_Uacute;
            }
        }
        break;
    case 0| onechar('U', 0, 32)| onechar('g', 8, 32)| onechar('r', 16, 32)| onechar('a', 24, 32):
        switch(string[4]) {
        case 0| onechar('v', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return CRNS_Ugrave;
            }
        }
        break;
    case 0| onechar('Y', 0, 32)| onechar('a', 8, 32)| onechar('c', 16, 32)| onechar('u', 24, 32):
        switch(string[4]) {
        case 0| onechar('t', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return CRNS_Yacute;
            }
        }
        break;
    case 0| onechar('a', 0, 32)| onechar('a', 8, 32)| onechar('c', 16, 32)| onechar('u', 24, 32):
        switch(string[4]) {
        case 0| onechar('t', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return CRNS_aacute;
            }
        }
        break;
    case 0| onechar('a', 0, 32)| onechar('g', 8, 32)| onechar('r', 16, 32)| onechar('a', 24, 32):
        switch(string[4]) {
        case 0| onechar('v', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return CRNS_agrave;
            }
        }
        break;
    case 0| onechar('a', 0, 32)| onechar('t', 8, 32)| onechar('i', 16, 32)| onechar('l', 24, 32):
        switch(string[4]) {
        case 0| onechar('d', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return CRNS_atilde;
            }
        }
        break;
    case 0| onechar('b', 0, 32)| onechar('r', 8, 32)| onechar('v', 16, 32)| onechar('b', 24, 32):
        switch(string[4]) {
        case 0| onechar('a', 0, 8):
            switch(string[5]) {
            case 0| onechar('r', 0, 8):
                return CRNS_brvbar;
            }
        }
        break;
    case 0| onechar('c', 0, 32)| onechar('c', 8, 32)| onechar('e', 16, 32)| onechar('d', 24, 32):
        switch(string[4]) {
        case 0| onechar('i', 0, 8):
            switch(string[5]) {
            case 0| onechar('l', 0, 8):
                return CRNS_ccedil;
            }
        }
        break;
    case 0| onechar('c', 0, 32)| onechar('u', 8, 32)| onechar('r', 16, 32)| onechar('r', 24, 32):
        switch(string[4]) {
        case 0| onechar('e', 0, 8):
            switch(string[5]) {
            case 0| onechar('n', 0, 8):
                return CRNS_curren;
            }
        }
        break;
    case 0| onechar('d', 0, 32)| onechar('i', 8, 32)| onechar('v', 16, 32)| onechar('i', 24, 32):
        switch(string[4]) {
        case 0| onechar('d', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return CRNS_divide;
            }
        }
        break;
    case 0| onechar('e', 0, 32)| onechar('a', 8, 32)| onechar('c', 16, 32)| onechar('u', 24, 32):
        switch(string[4]) {
        case 0| onechar('t', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return CRNS_eacute;
            }
        }
        break;
    case 0| onechar('e', 0, 32)| onechar('g', 8, 32)| onechar('r', 16, 32)| onechar('a', 24, 32):
        switch(string[4]) {
        case 0| onechar('v', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return CRNS_egrave;
            }
        }
        break;
    case 0| onechar('f', 0, 32)| onechar('r', 8, 32)| onechar('a', 16, 32)| onechar('c', 24, 32):
        switch(string[4]) {
        case 0| onechar('1', 0, 8):
            switch(string[5]) {
            case 0| onechar('2', 0, 8):
                return CRNS_frac12;
                break;
            case 0| onechar('4', 0, 8):
                return CRNS_frac14;
            }
            break;
        case 0| onechar('3', 0, 8):
            switch(string[5]) {
            case 0| onechar('4', 0, 8):
                return CRNS_frac34;
            }
        }
        break;
    case 0| onechar('i', 0, 32)| onechar('a', 8, 32)| onechar('c', 16, 32)| onechar('u', 24, 32):
        switch(string[4]) {
        case 0| onechar('t', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return CRNS_iacute;
            }
        }
        break;
    case 0| onechar('i', 0, 32)| onechar('g', 8, 32)| onechar('r', 16, 32)| onechar('a', 24, 32):
        switch(string[4]) {
        case 0| onechar('v', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return CRNS_igrave;
            }
        }
        break;
    case 0| onechar('i', 0, 32)| onechar('q', 8, 32)| onechar('u', 16, 32)| onechar('e', 24, 32):
        switch(string[4]) {
        case 0| onechar('s', 0, 8):
            switch(string[5]) {
            case 0| onechar('t', 0, 8):
                return CRNS_iquest;
            }
        }
        break;
    case 0| onechar('m', 0, 32)| onechar('i', 8, 32)| onechar('d', 16, 32)| onechar('d', 24, 32):
        switch(string[4]) {
        case 0| onechar('o', 0, 8):
            switch(string[5]) {
            case 0| onechar('t', 0, 8):
                return CRNS_middot;
            }
        }
        break;
    case 0| onechar('n', 0, 32)| onechar('t', 8, 32)| onechar('i', 16, 32)| onechar('l', 24, 32):
        switch(string[4]) {
        case 0| onechar('d', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return CRNS_ntilde;
            }
        }
        break;
    case 0| onechar('o', 0, 32)| onechar('a', 8, 32)| onechar('c', 16, 32)| onechar('u', 24, 32):
        switch(string[4]) {
        case 0| onechar('t', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return CRNS_oacute;
            }
        }
        break;
    case 0| onechar('o', 0, 32)| onechar('g', 8, 32)| onechar('r', 16, 32)| onechar('a', 24, 32):
        switch(string[4]) {
        case 0| onechar('v', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return CRNS_ograve;
            }
        }
        break;
    case 0| onechar('o', 0, 32)| onechar('s', 8, 32)| onechar('l', 16, 32)| onechar('a', 24, 32):
        switch(string[4]) {
        case 0| onechar('s', 0, 8):
            switch(string[5]) {
            case 0| onechar('h', 0, 8):
                return CRNS_oslash;
            }
        }
        break;
    case 0| onechar('o', 0, 32)| onechar('t', 8, 32)| onechar('i', 16, 32)| onechar('l', 24, 32):
        switch(string[4]) {
        case 0| onechar('d', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return CRNS_otilde;
            }
        }
        break;
    case 0| onechar('p', 0, 32)| onechar('l', 8, 32)| onechar('u', 16, 32)| onechar('s', 24, 32):
        switch(string[4]) {
        case 0| onechar('m', 0, 8):
            switch(string[5]) {
            case 0| onechar('n', 0, 8):
                return CRNS_plusmn;
            }
        }
        break;
    case 0| onechar('u', 0, 32)| onechar('a', 8, 32)| onechar('c', 16, 32)| onechar('u', 24, 32):
        switch(string[4]) {
        case 0| onechar('t', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return CRNS_uacute;
            }
        }
        break;
    case 0| onechar('u', 0, 32)| onechar('g', 8, 32)| onechar('r', 16, 32)| onechar('a', 24, 32):
        switch(string[4]) {
        case 0| onechar('v', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return CRNS_ugrave;
            }
        }
        break;
    case 0| onechar('y', 0, 32)| onechar('a', 8, 32)| onechar('c', 16, 32)| onechar('u', 24, 32):
        switch(string[4]) {
        case 0| onechar('t', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return CRNS_yacute;
            }
        }
    }
    return CRNS_Unknown;
}
#else
static enum CharacterReferenceNoSemicolon lookup_character_reference_no_semicolon2(const char *string)
{
    switch(string[0]) {
    case 'G':
        switch(string[1]) {
        case 'T':
            return CRNS_GT;
        }
        break;
    case 'L':
        switch(string[1]) {
        case 'T':
            return CRNS_LT;
        }
        break;
    case 'g':
        switch(string[1]) {
        case 't':
            return CRNS_gt;
        }
        break;
    case 'l':
        switch(string[1]) {
        case 't':
            return CRNS_lt;
        }
    }
    return CRNS_Unknown;
}
static enum CharacterReferenceNoSemicolon lookup_character_reference_no_semicolon3(const char *string)
{
    switch(string[0]) {
    case 'A':
        switch(string[1]) {
        case 'M':
            switch(string[2]) {
            case 'P':
                return CRNS_AMP;
            }
        }
        break;
    case 'E':
        switch(string[1]) {
        case 'T':
            switch(string[2]) {
            case 'H':
                return CRNS_ETH;
            }
        }
        break;
    case 'R':
        switch(string[1]) {
        case 'E':
            switch(string[2]) {
            case 'G':
                return CRNS_REG;
            }
        }
        break;
    case 'a':
        switch(string[1]) {
        case 'm':
            switch(string[2]) {
            case 'p':
                return CRNS_amp;
            }
        }
        break;
    case 'd':
        switch(string[1]) {
        case 'e':
            switch(string[2]) {
            case 'g':
                return CRNS_deg;
            }
        }
        break;
    case 'e':
        switch(string[1]) {
        case 't':
            switch(string[2]) {
            case 'h':
                return CRNS_eth;
            }
        }
        break;
    case 'n':
        switch(string[1]) {
        case 'o':
            switch(string[2]) {
            case 't':
                return CRNS_not;
            }
        }
        break;
    case 'r':
        switch(string[1]) {
        case 'e':
            switch(string[2]) {
            case 'g':
                return CRNS_reg;
            }
        }
        break;
    case 's':
        switch(string[1]) {
        case 'h':
            switch(string[2]) {
            case 'y':
                return CRNS_shy;
            }
        }
        break;
    case 'u':
        switch(string[1]) {
        case 'm':
            switch(string[2]) {
            case 'l':
                return CRNS_uml;
            }
        }
        break;
    case 'y':
        switch(string[1]) {
        case 'e':
            switch(string[2]) {
            case 'n':
                return CRNS_yen;
            }
        }
    }
    return CRNS_Unknown;
}
static enum CharacterReferenceNoSemicolon lookup_character_reference_no_semicolon4(const char *string)
{
    switch(string[0]) {
    case 'A':
        switch(string[1]) {
        case 'u':
            switch(string[2]) {
            case 'm':
                switch(string[3]) {
                case 'l':
                    return CRNS_Auml;
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
                    return CRNS_COPY;
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
                    return CRNS_Euml;
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
                    return CRNS_Iuml;
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
                    return CRNS_Ouml;
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
                    return CRNS_QUOT;
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
                    return CRNS_Uuml;
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
                    return CRNS_auml;
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
                    return CRNS_cent;
                }
            }
            break;
        case 'o':
            switch(string[2]) {
            case 'p':
                switch(string[3]) {
                case 'y':
                    return CRNS_copy;
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
                    return CRNS_euml;
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
                    return CRNS_iuml;
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
                    return CRNS_macr;
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
                    return CRNS_nbsp;
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
                    return CRNS_ordf;
                    break;
                case 'm':
                    return CRNS_ordm;
                }
            }
            break;
        case 'u':
            switch(string[2]) {
            case 'm':
                switch(string[3]) {
                case 'l':
                    return CRNS_ouml;
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
                    return CRNS_para;
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
                    return CRNS_quot;
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
                    return CRNS_sect;
                }
            }
            break;
        case 'u':
            switch(string[2]) {
            case 'p':
                switch(string[3]) {
                case '1':
                    return CRNS_sup1;
                    break;
                case '2':
                    return CRNS_sup2;
                    break;
                case '3':
                    return CRNS_sup3;
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
                    return CRNS_uuml;
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
                    return CRNS_yuml;
                }
            }
        }
    }
    return CRNS_Unknown;
}
static enum CharacterReferenceNoSemicolon lookup_character_reference_no_semicolon5(const char *string)
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
                        return CRNS_AElig;
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
                        return CRNS_Acirc;
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
                        return CRNS_Aring;
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
                        return CRNS_Ecirc;
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
                        return CRNS_Icirc;
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
                        return CRNS_Ocirc;
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
                        return CRNS_THORN;
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
                        return CRNS_Ucirc;
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
                        return CRNS_acirc;
                    }
                }
                break;
            case 'u':
                switch(string[3]) {
                case 't':
                    switch(string[4]) {
                    case 'e':
                        return CRNS_acute;
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
                        return CRNS_aelig;
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
                        return CRNS_aring;
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
                        return CRNS_cedil;
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
                        return CRNS_ecirc;
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
                        return CRNS_icirc;
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
                        return CRNS_iexcl;
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
                        return CRNS_laquo;
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
                        return CRNS_micro;
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
                        return CRNS_ocirc;
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
                        return CRNS_pound;
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
                        return CRNS_raquo;
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
                        return CRNS_szlig;
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
                        return CRNS_thorn;
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
                        return CRNS_times;
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
                        return CRNS_ucirc;
                    }
                }
            }
        }
    }
    return CRNS_Unknown;
}
static enum CharacterReferenceNoSemicolon lookup_character_reference_no_semicolon6(const char *string)
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
                            return CRNS_Aacute;
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
                            return CRNS_Agrave;
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
                            return CRNS_Atilde;
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
                            return CRNS_Ccedil;
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
                            return CRNS_Eacute;
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
                            return CRNS_Egrave;
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
                            return CRNS_Iacute;
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
                            return CRNS_Igrave;
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
                            return CRNS_Ntilde;
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
                            return CRNS_Oacute;
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
                            return CRNS_Ograve;
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
                            return CRNS_Oslash;
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
                            return CRNS_Otilde;
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
                            return CRNS_Uacute;
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
                            return CRNS_Ugrave;
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
                            return CRNS_Yacute;
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
                            return CRNS_aacute;
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
                            return CRNS_agrave;
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
                            return CRNS_atilde;
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
                            return CRNS_brvbar;
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
                            return CRNS_ccedil;
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
                            return CRNS_curren;
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
                            return CRNS_divide;
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
                            return CRNS_eacute;
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
                            return CRNS_egrave;
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
                            return CRNS_frac12;
                            break;
                        case '4':
                            return CRNS_frac14;
                        }
                        break;
                    case '3':
                        switch(string[5]) {
                        case '4':
                            return CRNS_frac34;
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
                            return CRNS_iacute;
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
                            return CRNS_igrave;
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
                            return CRNS_iquest;
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
                            return CRNS_middot;
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
                            return CRNS_ntilde;
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
                            return CRNS_oacute;
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
                            return CRNS_ograve;
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
                            return CRNS_oslash;
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
                            return CRNS_otilde;
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
                            return CRNS_plusmn;
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
                            return CRNS_uacute;
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
                            return CRNS_ugrave;
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
                            return CRNS_yacute;
                        }
                    }
                }
            }
        }
    }
    return CRNS_Unknown;
}
#endif /* TRIE_HASH_MULTI_BYTE */
static enum CharacterReferenceNoSemicolon lookup_character_reference_no_semicolon(const char *string, size_t length)
{
    switch (length) {
    case 2:
        return lookup_character_reference_no_semicolon2(string);
    case 3:
        return lookup_character_reference_no_semicolon3(string);
    case 4:
        return lookup_character_reference_no_semicolon4(string);
    case 5:
        return lookup_character_reference_no_semicolon5(string);
    case 6:
        return lookup_character_reference_no_semicolon6(string);
    default:
        return CRNS_Unknown;
    }
}
#endif                       /* TRIE_HASH_lookup_character_reference_no_semicolon */
