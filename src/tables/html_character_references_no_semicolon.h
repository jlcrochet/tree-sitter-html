#ifndef TRIE_HASH_lookup_character_reference_no_semicolon
#define TRIE_HASH_lookup_character_reference_no_semicolon
#include <stddef.h>
#include <stdint.h>
enum CharacterReferenceNoSemicolon {
    CharacterReferenceNoSemicolon_AMP = 2,
    CharacterReferenceNoSemicolon_AElig = 1,
    CharacterReferenceNoSemicolon_Aacute = 3,
    CharacterReferenceNoSemicolon_Acirc = 4,
    CharacterReferenceNoSemicolon_Agrave = 5,
    CharacterReferenceNoSemicolon_Aring = 6,
    CharacterReferenceNoSemicolon_Atilde = 7,
    CharacterReferenceNoSemicolon_Auml = 8,
    CharacterReferenceNoSemicolon_COPY = 9,
    CharacterReferenceNoSemicolon_Ccedil = 10,
    CharacterReferenceNoSemicolon_ETH = 11,
    CharacterReferenceNoSemicolon_Eacute = 12,
    CharacterReferenceNoSemicolon_Ecirc = 13,
    CharacterReferenceNoSemicolon_Egrave = 14,
    CharacterReferenceNoSemicolon_Euml = 15,
    CharacterReferenceNoSemicolon_GT = 16,
    CharacterReferenceNoSemicolon_Iacute = 17,
    CharacterReferenceNoSemicolon_Icirc = 18,
    CharacterReferenceNoSemicolon_Igrave = 19,
    CharacterReferenceNoSemicolon_Iuml = 20,
    CharacterReferenceNoSemicolon_LT = 21,
    CharacterReferenceNoSemicolon_Ntilde = 22,
    CharacterReferenceNoSemicolon_Oacute = 23,
    CharacterReferenceNoSemicolon_Ocirc = 24,
    CharacterReferenceNoSemicolon_Ograve = 25,
    CharacterReferenceNoSemicolon_Oslash = 26,
    CharacterReferenceNoSemicolon_Otilde = 27,
    CharacterReferenceNoSemicolon_Ouml = 28,
    CharacterReferenceNoSemicolon_QUOT = 29,
    CharacterReferenceNoSemicolon_REG = 30,
    CharacterReferenceNoSemicolon_THORN = 31,
    CharacterReferenceNoSemicolon_Uacute = 32,
    CharacterReferenceNoSemicolon_Ucirc = 33,
    CharacterReferenceNoSemicolon_Ugrave = 34,
    CharacterReferenceNoSemicolon_Uuml = 35,
    CharacterReferenceNoSemicolon_Yacute = 36,
    CharacterReferenceNoSemicolon_amp = 42,
    CharacterReferenceNoSemicolon_aacute = 37,
    CharacterReferenceNoSemicolon_acirc = 38,
    CharacterReferenceNoSemicolon_acute = 39,
    CharacterReferenceNoSemicolon_aelig = 40,
    CharacterReferenceNoSemicolon_agrave = 41,
    CharacterReferenceNoSemicolon_aring = 43,
    CharacterReferenceNoSemicolon_atilde = 44,
    CharacterReferenceNoSemicolon_auml = 45,
    CharacterReferenceNoSemicolon_brvbar = 46,
    CharacterReferenceNoSemicolon_ccedil = 47,
    CharacterReferenceNoSemicolon_cedil = 48,
    CharacterReferenceNoSemicolon_cent = 49,
    CharacterReferenceNoSemicolon_copy = 50,
    CharacterReferenceNoSemicolon_curren = 51,
    CharacterReferenceNoSemicolon_deg = 52,
    CharacterReferenceNoSemicolon_divide = 53,
    CharacterReferenceNoSemicolon_eth = 57,
    CharacterReferenceNoSemicolon_eacute = 54,
    CharacterReferenceNoSemicolon_ecirc = 55,
    CharacterReferenceNoSemicolon_egrave = 56,
    CharacterReferenceNoSemicolon_euml = 58,
    CharacterReferenceNoSemicolon_frac12 = 59,
    CharacterReferenceNoSemicolon_frac14 = 60,
    CharacterReferenceNoSemicolon_frac34 = 61,
    CharacterReferenceNoSemicolon_gt = 62,
    CharacterReferenceNoSemicolon_iacute = 63,
    CharacterReferenceNoSemicolon_icirc = 64,
    CharacterReferenceNoSemicolon_iexcl = 65,
    CharacterReferenceNoSemicolon_igrave = 66,
    CharacterReferenceNoSemicolon_iquest = 67,
    CharacterReferenceNoSemicolon_iuml = 68,
    CharacterReferenceNoSemicolon_lt = 70,
    CharacterReferenceNoSemicolon_laquo = 69,
    CharacterReferenceNoSemicolon_macr = 71,
    CharacterReferenceNoSemicolon_micro = 72,
    CharacterReferenceNoSemicolon_middot = 73,
    CharacterReferenceNoSemicolon_not = 75,
    CharacterReferenceNoSemicolon_nbsp = 74,
    CharacterReferenceNoSemicolon_ntilde = 76,
    CharacterReferenceNoSemicolon_oacute = 77,
    CharacterReferenceNoSemicolon_ocirc = 78,
    CharacterReferenceNoSemicolon_ograve = 79,
    CharacterReferenceNoSemicolon_ordf = 80,
    CharacterReferenceNoSemicolon_ordm = 81,
    CharacterReferenceNoSemicolon_oslash = 82,
    CharacterReferenceNoSemicolon_otilde = 83,
    CharacterReferenceNoSemicolon_ouml = 84,
    CharacterReferenceNoSemicolon_para = 85,
    CharacterReferenceNoSemicolon_plusmn = 86,
    CharacterReferenceNoSemicolon_pound = 87,
    CharacterReferenceNoSemicolon_quot = 88,
    CharacterReferenceNoSemicolon_reg = 90,
    CharacterReferenceNoSemicolon_raquo = 89,
    CharacterReferenceNoSemicolon_shy = 92,
    CharacterReferenceNoSemicolon_sect = 91,
    CharacterReferenceNoSemicolon_sup1 = 93,
    CharacterReferenceNoSemicolon_sup2 = 94,
    CharacterReferenceNoSemicolon_sup3 = 95,
    CharacterReferenceNoSemicolon_szlig = 96,
    CharacterReferenceNoSemicolon_thorn = 97,
    CharacterReferenceNoSemicolon_times = 98,
    CharacterReferenceNoSemicolon_uml = 102,
    CharacterReferenceNoSemicolon_uacute = 99,
    CharacterReferenceNoSemicolon_ucirc = 100,
    CharacterReferenceNoSemicolon_ugrave = 101,
    CharacterReferenceNoSemicolon_uuml = 103,
    CharacterReferenceNoSemicolon_yen = 105,
    CharacterReferenceNoSemicolon_yacute = 104,
    CharacterReferenceNoSemicolon_yuml = 106,
    CharacterReferenceNoSemicolon_Unknown = 0,
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
            return CharacterReferenceNoSemicolon_GT;
        }
        break;
    case 0| onechar('L', 0, 8):
        switch(string[1]) {
        case 0| onechar('T', 0, 8):
            return CharacterReferenceNoSemicolon_LT;
        }
        break;
    case 0| onechar('g', 0, 8):
        switch(string[1]) {
        case 0| onechar('t', 0, 8):
            return CharacterReferenceNoSemicolon_gt;
        }
        break;
    case 0| onechar('l', 0, 8):
        switch(string[1]) {
        case 0| onechar('t', 0, 8):
            return CharacterReferenceNoSemicolon_lt;
        }
    }
    return CharacterReferenceNoSemicolon_Unknown;
}
static enum CharacterReferenceNoSemicolon lookup_character_reference_no_semicolon3(const char *string)
{
    switch(string[0]) {
    case 0| onechar('A', 0, 8):
        switch(string[1]) {
        case 0| onechar('M', 0, 8):
            switch(string[2]) {
            case 0| onechar('P', 0, 8):
                return CharacterReferenceNoSemicolon_AMP;
            }
        }
        break;
    case 0| onechar('E', 0, 8):
        switch(string[1]) {
        case 0| onechar('T', 0, 8):
            switch(string[2]) {
            case 0| onechar('H', 0, 8):
                return CharacterReferenceNoSemicolon_ETH;
            }
        }
        break;
    case 0| onechar('R', 0, 8):
        switch(string[1]) {
        case 0| onechar('E', 0, 8):
            switch(string[2]) {
            case 0| onechar('G', 0, 8):
                return CharacterReferenceNoSemicolon_REG;
            }
        }
        break;
    case 0| onechar('a', 0, 8):
        switch(string[1]) {
        case 0| onechar('m', 0, 8):
            switch(string[2]) {
            case 0| onechar('p', 0, 8):
                return CharacterReferenceNoSemicolon_amp;
            }
        }
        break;
    case 0| onechar('d', 0, 8):
        switch(string[1]) {
        case 0| onechar('e', 0, 8):
            switch(string[2]) {
            case 0| onechar('g', 0, 8):
                return CharacterReferenceNoSemicolon_deg;
            }
        }
        break;
    case 0| onechar('e', 0, 8):
        switch(string[1]) {
        case 0| onechar('t', 0, 8):
            switch(string[2]) {
            case 0| onechar('h', 0, 8):
                return CharacterReferenceNoSemicolon_eth;
            }
        }
        break;
    case 0| onechar('n', 0, 8):
        switch(string[1]) {
        case 0| onechar('o', 0, 8):
            switch(string[2]) {
            case 0| onechar('t', 0, 8):
                return CharacterReferenceNoSemicolon_not;
            }
        }
        break;
    case 0| onechar('r', 0, 8):
        switch(string[1]) {
        case 0| onechar('e', 0, 8):
            switch(string[2]) {
            case 0| onechar('g', 0, 8):
                return CharacterReferenceNoSemicolon_reg;
            }
        }
        break;
    case 0| onechar('s', 0, 8):
        switch(string[1]) {
        case 0| onechar('h', 0, 8):
            switch(string[2]) {
            case 0| onechar('y', 0, 8):
                return CharacterReferenceNoSemicolon_shy;
            }
        }
        break;
    case 0| onechar('u', 0, 8):
        switch(string[1]) {
        case 0| onechar('m', 0, 8):
            switch(string[2]) {
            case 0| onechar('l', 0, 8):
                return CharacterReferenceNoSemicolon_uml;
            }
        }
        break;
    case 0| onechar('y', 0, 8):
        switch(string[1]) {
        case 0| onechar('e', 0, 8):
            switch(string[2]) {
            case 0| onechar('n', 0, 8):
                return CharacterReferenceNoSemicolon_yen;
            }
        }
    }
    return CharacterReferenceNoSemicolon_Unknown;
}
static enum CharacterReferenceNoSemicolon lookup_character_reference_no_semicolon4(const char *string)
{
    switch(*((triehash_uu32*) &string[0])) {
    case 0| onechar('A', 0, 32)| onechar('u', 8, 32)| onechar('m', 16, 32)| onechar('l', 24, 32):
        return CharacterReferenceNoSemicolon_Auml;
        break;
    case 0| onechar('C', 0, 32)| onechar('O', 8, 32)| onechar('P', 16, 32)| onechar('Y', 24, 32):
        return CharacterReferenceNoSemicolon_COPY;
        break;
    case 0| onechar('E', 0, 32)| onechar('u', 8, 32)| onechar('m', 16, 32)| onechar('l', 24, 32):
        return CharacterReferenceNoSemicolon_Euml;
        break;
    case 0| onechar('I', 0, 32)| onechar('u', 8, 32)| onechar('m', 16, 32)| onechar('l', 24, 32):
        return CharacterReferenceNoSemicolon_Iuml;
        break;
    case 0| onechar('O', 0, 32)| onechar('u', 8, 32)| onechar('m', 16, 32)| onechar('l', 24, 32):
        return CharacterReferenceNoSemicolon_Ouml;
        break;
    case 0| onechar('Q', 0, 32)| onechar('U', 8, 32)| onechar('O', 16, 32)| onechar('T', 24, 32):
        return CharacterReferenceNoSemicolon_QUOT;
        break;
    case 0| onechar('U', 0, 32)| onechar('u', 8, 32)| onechar('m', 16, 32)| onechar('l', 24, 32):
        return CharacterReferenceNoSemicolon_Uuml;
        break;
    case 0| onechar('a', 0, 32)| onechar('u', 8, 32)| onechar('m', 16, 32)| onechar('l', 24, 32):
        return CharacterReferenceNoSemicolon_auml;
        break;
    case 0| onechar('c', 0, 32)| onechar('e', 8, 32)| onechar('n', 16, 32)| onechar('t', 24, 32):
        return CharacterReferenceNoSemicolon_cent;
        break;
    case 0| onechar('c', 0, 32)| onechar('o', 8, 32)| onechar('p', 16, 32)| onechar('y', 24, 32):
        return CharacterReferenceNoSemicolon_copy;
        break;
    case 0| onechar('e', 0, 32)| onechar('u', 8, 32)| onechar('m', 16, 32)| onechar('l', 24, 32):
        return CharacterReferenceNoSemicolon_euml;
        break;
    case 0| onechar('i', 0, 32)| onechar('u', 8, 32)| onechar('m', 16, 32)| onechar('l', 24, 32):
        return CharacterReferenceNoSemicolon_iuml;
        break;
    case 0| onechar('m', 0, 32)| onechar('a', 8, 32)| onechar('c', 16, 32)| onechar('r', 24, 32):
        return CharacterReferenceNoSemicolon_macr;
        break;
    case 0| onechar('n', 0, 32)| onechar('b', 8, 32)| onechar('s', 16, 32)| onechar('p', 24, 32):
        return CharacterReferenceNoSemicolon_nbsp;
        break;
    case 0| onechar('o', 0, 32)| onechar('r', 8, 32)| onechar('d', 16, 32)| onechar('f', 24, 32):
        return CharacterReferenceNoSemicolon_ordf;
        break;
    case 0| onechar('o', 0, 32)| onechar('r', 8, 32)| onechar('d', 16, 32)| onechar('m', 24, 32):
        return CharacterReferenceNoSemicolon_ordm;
        break;
    case 0| onechar('o', 0, 32)| onechar('u', 8, 32)| onechar('m', 16, 32)| onechar('l', 24, 32):
        return CharacterReferenceNoSemicolon_ouml;
        break;
    case 0| onechar('p', 0, 32)| onechar('a', 8, 32)| onechar('r', 16, 32)| onechar('a', 24, 32):
        return CharacterReferenceNoSemicolon_para;
        break;
    case 0| onechar('q', 0, 32)| onechar('u', 8, 32)| onechar('o', 16, 32)| onechar('t', 24, 32):
        return CharacterReferenceNoSemicolon_quot;
        break;
    case 0| onechar('s', 0, 32)| onechar('e', 8, 32)| onechar('c', 16, 32)| onechar('t', 24, 32):
        return CharacterReferenceNoSemicolon_sect;
        break;
    case 0| onechar('s', 0, 32)| onechar('u', 8, 32)| onechar('p', 16, 32)| onechar('1', 24, 32):
        return CharacterReferenceNoSemicolon_sup1;
        break;
    case 0| onechar('s', 0, 32)| onechar('u', 8, 32)| onechar('p', 16, 32)| onechar('2', 24, 32):
        return CharacterReferenceNoSemicolon_sup2;
        break;
    case 0| onechar('s', 0, 32)| onechar('u', 8, 32)| onechar('p', 16, 32)| onechar('3', 24, 32):
        return CharacterReferenceNoSemicolon_sup3;
        break;
    case 0| onechar('u', 0, 32)| onechar('u', 8, 32)| onechar('m', 16, 32)| onechar('l', 24, 32):
        return CharacterReferenceNoSemicolon_uuml;
        break;
    case 0| onechar('y', 0, 32)| onechar('u', 8, 32)| onechar('m', 16, 32)| onechar('l', 24, 32):
        return CharacterReferenceNoSemicolon_yuml;
    }
    return CharacterReferenceNoSemicolon_Unknown;
}
static enum CharacterReferenceNoSemicolon lookup_character_reference_no_semicolon5(const char *string)
{
    switch(*((triehash_uu32*) &string[0])) {
    case 0| onechar('A', 0, 32)| onechar('E', 8, 32)| onechar('l', 16, 32)| onechar('i', 24, 32):
        switch(string[4]) {
        case 0| onechar('g', 0, 8):
            return CharacterReferenceNoSemicolon_AElig;
        }
        break;
    case 0| onechar('A', 0, 32)| onechar('c', 8, 32)| onechar('i', 16, 32)| onechar('r', 24, 32):
        switch(string[4]) {
        case 0| onechar('c', 0, 8):
            return CharacterReferenceNoSemicolon_Acirc;
        }
        break;
    case 0| onechar('A', 0, 32)| onechar('r', 8, 32)| onechar('i', 16, 32)| onechar('n', 24, 32):
        switch(string[4]) {
        case 0| onechar('g', 0, 8):
            return CharacterReferenceNoSemicolon_Aring;
        }
        break;
    case 0| onechar('E', 0, 32)| onechar('c', 8, 32)| onechar('i', 16, 32)| onechar('r', 24, 32):
        switch(string[4]) {
        case 0| onechar('c', 0, 8):
            return CharacterReferenceNoSemicolon_Ecirc;
        }
        break;
    case 0| onechar('I', 0, 32)| onechar('c', 8, 32)| onechar('i', 16, 32)| onechar('r', 24, 32):
        switch(string[4]) {
        case 0| onechar('c', 0, 8):
            return CharacterReferenceNoSemicolon_Icirc;
        }
        break;
    case 0| onechar('O', 0, 32)| onechar('c', 8, 32)| onechar('i', 16, 32)| onechar('r', 24, 32):
        switch(string[4]) {
        case 0| onechar('c', 0, 8):
            return CharacterReferenceNoSemicolon_Ocirc;
        }
        break;
    case 0| onechar('T', 0, 32)| onechar('H', 8, 32)| onechar('O', 16, 32)| onechar('R', 24, 32):
        switch(string[4]) {
        case 0| onechar('N', 0, 8):
            return CharacterReferenceNoSemicolon_THORN;
        }
        break;
    case 0| onechar('U', 0, 32)| onechar('c', 8, 32)| onechar('i', 16, 32)| onechar('r', 24, 32):
        switch(string[4]) {
        case 0| onechar('c', 0, 8):
            return CharacterReferenceNoSemicolon_Ucirc;
        }
        break;
    case 0| onechar('a', 0, 32)| onechar('c', 8, 32)| onechar('i', 16, 32)| onechar('r', 24, 32):
        switch(string[4]) {
        case 0| onechar('c', 0, 8):
            return CharacterReferenceNoSemicolon_acirc;
        }
        break;
    case 0| onechar('a', 0, 32)| onechar('c', 8, 32)| onechar('u', 16, 32)| onechar('t', 24, 32):
        switch(string[4]) {
        case 0| onechar('e', 0, 8):
            return CharacterReferenceNoSemicolon_acute;
        }
        break;
    case 0| onechar('a', 0, 32)| onechar('e', 8, 32)| onechar('l', 16, 32)| onechar('i', 24, 32):
        switch(string[4]) {
        case 0| onechar('g', 0, 8):
            return CharacterReferenceNoSemicolon_aelig;
        }
        break;
    case 0| onechar('a', 0, 32)| onechar('r', 8, 32)| onechar('i', 16, 32)| onechar('n', 24, 32):
        switch(string[4]) {
        case 0| onechar('g', 0, 8):
            return CharacterReferenceNoSemicolon_aring;
        }
        break;
    case 0| onechar('c', 0, 32)| onechar('e', 8, 32)| onechar('d', 16, 32)| onechar('i', 24, 32):
        switch(string[4]) {
        case 0| onechar('l', 0, 8):
            return CharacterReferenceNoSemicolon_cedil;
        }
        break;
    case 0| onechar('e', 0, 32)| onechar('c', 8, 32)| onechar('i', 16, 32)| onechar('r', 24, 32):
        switch(string[4]) {
        case 0| onechar('c', 0, 8):
            return CharacterReferenceNoSemicolon_ecirc;
        }
        break;
    case 0| onechar('i', 0, 32)| onechar('c', 8, 32)| onechar('i', 16, 32)| onechar('r', 24, 32):
        switch(string[4]) {
        case 0| onechar('c', 0, 8):
            return CharacterReferenceNoSemicolon_icirc;
        }
        break;
    case 0| onechar('i', 0, 32)| onechar('e', 8, 32)| onechar('x', 16, 32)| onechar('c', 24, 32):
        switch(string[4]) {
        case 0| onechar('l', 0, 8):
            return CharacterReferenceNoSemicolon_iexcl;
        }
        break;
    case 0| onechar('l', 0, 32)| onechar('a', 8, 32)| onechar('q', 16, 32)| onechar('u', 24, 32):
        switch(string[4]) {
        case 0| onechar('o', 0, 8):
            return CharacterReferenceNoSemicolon_laquo;
        }
        break;
    case 0| onechar('m', 0, 32)| onechar('i', 8, 32)| onechar('c', 16, 32)| onechar('r', 24, 32):
        switch(string[4]) {
        case 0| onechar('o', 0, 8):
            return CharacterReferenceNoSemicolon_micro;
        }
        break;
    case 0| onechar('o', 0, 32)| onechar('c', 8, 32)| onechar('i', 16, 32)| onechar('r', 24, 32):
        switch(string[4]) {
        case 0| onechar('c', 0, 8):
            return CharacterReferenceNoSemicolon_ocirc;
        }
        break;
    case 0| onechar('p', 0, 32)| onechar('o', 8, 32)| onechar('u', 16, 32)| onechar('n', 24, 32):
        switch(string[4]) {
        case 0| onechar('d', 0, 8):
            return CharacterReferenceNoSemicolon_pound;
        }
        break;
    case 0| onechar('r', 0, 32)| onechar('a', 8, 32)| onechar('q', 16, 32)| onechar('u', 24, 32):
        switch(string[4]) {
        case 0| onechar('o', 0, 8):
            return CharacterReferenceNoSemicolon_raquo;
        }
        break;
    case 0| onechar('s', 0, 32)| onechar('z', 8, 32)| onechar('l', 16, 32)| onechar('i', 24, 32):
        switch(string[4]) {
        case 0| onechar('g', 0, 8):
            return CharacterReferenceNoSemicolon_szlig;
        }
        break;
    case 0| onechar('t', 0, 32)| onechar('h', 8, 32)| onechar('o', 16, 32)| onechar('r', 24, 32):
        switch(string[4]) {
        case 0| onechar('n', 0, 8):
            return CharacterReferenceNoSemicolon_thorn;
        }
        break;
    case 0| onechar('t', 0, 32)| onechar('i', 8, 32)| onechar('m', 16, 32)| onechar('e', 24, 32):
        switch(string[4]) {
        case 0| onechar('s', 0, 8):
            return CharacterReferenceNoSemicolon_times;
        }
        break;
    case 0| onechar('u', 0, 32)| onechar('c', 8, 32)| onechar('i', 16, 32)| onechar('r', 24, 32):
        switch(string[4]) {
        case 0| onechar('c', 0, 8):
            return CharacterReferenceNoSemicolon_ucirc;
        }
    }
    return CharacterReferenceNoSemicolon_Unknown;
}
static enum CharacterReferenceNoSemicolon lookup_character_reference_no_semicolon6(const char *string)
{
    switch(*((triehash_uu32*) &string[0])) {
    case 0| onechar('A', 0, 32)| onechar('a', 8, 32)| onechar('c', 16, 32)| onechar('u', 24, 32):
        switch(string[4]) {
        case 0| onechar('t', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return CharacterReferenceNoSemicolon_Aacute;
            }
        }
        break;
    case 0| onechar('A', 0, 32)| onechar('g', 8, 32)| onechar('r', 16, 32)| onechar('a', 24, 32):
        switch(string[4]) {
        case 0| onechar('v', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return CharacterReferenceNoSemicolon_Agrave;
            }
        }
        break;
    case 0| onechar('A', 0, 32)| onechar('t', 8, 32)| onechar('i', 16, 32)| onechar('l', 24, 32):
        switch(string[4]) {
        case 0| onechar('d', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return CharacterReferenceNoSemicolon_Atilde;
            }
        }
        break;
    case 0| onechar('C', 0, 32)| onechar('c', 8, 32)| onechar('e', 16, 32)| onechar('d', 24, 32):
        switch(string[4]) {
        case 0| onechar('i', 0, 8):
            switch(string[5]) {
            case 0| onechar('l', 0, 8):
                return CharacterReferenceNoSemicolon_Ccedil;
            }
        }
        break;
    case 0| onechar('E', 0, 32)| onechar('a', 8, 32)| onechar('c', 16, 32)| onechar('u', 24, 32):
        switch(string[4]) {
        case 0| onechar('t', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return CharacterReferenceNoSemicolon_Eacute;
            }
        }
        break;
    case 0| onechar('E', 0, 32)| onechar('g', 8, 32)| onechar('r', 16, 32)| onechar('a', 24, 32):
        switch(string[4]) {
        case 0| onechar('v', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return CharacterReferenceNoSemicolon_Egrave;
            }
        }
        break;
    case 0| onechar('I', 0, 32)| onechar('a', 8, 32)| onechar('c', 16, 32)| onechar('u', 24, 32):
        switch(string[4]) {
        case 0| onechar('t', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return CharacterReferenceNoSemicolon_Iacute;
            }
        }
        break;
    case 0| onechar('I', 0, 32)| onechar('g', 8, 32)| onechar('r', 16, 32)| onechar('a', 24, 32):
        switch(string[4]) {
        case 0| onechar('v', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return CharacterReferenceNoSemicolon_Igrave;
            }
        }
        break;
    case 0| onechar('N', 0, 32)| onechar('t', 8, 32)| onechar('i', 16, 32)| onechar('l', 24, 32):
        switch(string[4]) {
        case 0| onechar('d', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return CharacterReferenceNoSemicolon_Ntilde;
            }
        }
        break;
    case 0| onechar('O', 0, 32)| onechar('a', 8, 32)| onechar('c', 16, 32)| onechar('u', 24, 32):
        switch(string[4]) {
        case 0| onechar('t', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return CharacterReferenceNoSemicolon_Oacute;
            }
        }
        break;
    case 0| onechar('O', 0, 32)| onechar('g', 8, 32)| onechar('r', 16, 32)| onechar('a', 24, 32):
        switch(string[4]) {
        case 0| onechar('v', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return CharacterReferenceNoSemicolon_Ograve;
            }
        }
        break;
    case 0| onechar('O', 0, 32)| onechar('s', 8, 32)| onechar('l', 16, 32)| onechar('a', 24, 32):
        switch(string[4]) {
        case 0| onechar('s', 0, 8):
            switch(string[5]) {
            case 0| onechar('h', 0, 8):
                return CharacterReferenceNoSemicolon_Oslash;
            }
        }
        break;
    case 0| onechar('O', 0, 32)| onechar('t', 8, 32)| onechar('i', 16, 32)| onechar('l', 24, 32):
        switch(string[4]) {
        case 0| onechar('d', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return CharacterReferenceNoSemicolon_Otilde;
            }
        }
        break;
    case 0| onechar('U', 0, 32)| onechar('a', 8, 32)| onechar('c', 16, 32)| onechar('u', 24, 32):
        switch(string[4]) {
        case 0| onechar('t', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return CharacterReferenceNoSemicolon_Uacute;
            }
        }
        break;
    case 0| onechar('U', 0, 32)| onechar('g', 8, 32)| onechar('r', 16, 32)| onechar('a', 24, 32):
        switch(string[4]) {
        case 0| onechar('v', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return CharacterReferenceNoSemicolon_Ugrave;
            }
        }
        break;
    case 0| onechar('Y', 0, 32)| onechar('a', 8, 32)| onechar('c', 16, 32)| onechar('u', 24, 32):
        switch(string[4]) {
        case 0| onechar('t', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return CharacterReferenceNoSemicolon_Yacute;
            }
        }
        break;
    case 0| onechar('a', 0, 32)| onechar('a', 8, 32)| onechar('c', 16, 32)| onechar('u', 24, 32):
        switch(string[4]) {
        case 0| onechar('t', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return CharacterReferenceNoSemicolon_aacute;
            }
        }
        break;
    case 0| onechar('a', 0, 32)| onechar('g', 8, 32)| onechar('r', 16, 32)| onechar('a', 24, 32):
        switch(string[4]) {
        case 0| onechar('v', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return CharacterReferenceNoSemicolon_agrave;
            }
        }
        break;
    case 0| onechar('a', 0, 32)| onechar('t', 8, 32)| onechar('i', 16, 32)| onechar('l', 24, 32):
        switch(string[4]) {
        case 0| onechar('d', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return CharacterReferenceNoSemicolon_atilde;
            }
        }
        break;
    case 0| onechar('b', 0, 32)| onechar('r', 8, 32)| onechar('v', 16, 32)| onechar('b', 24, 32):
        switch(string[4]) {
        case 0| onechar('a', 0, 8):
            switch(string[5]) {
            case 0| onechar('r', 0, 8):
                return CharacterReferenceNoSemicolon_brvbar;
            }
        }
        break;
    case 0| onechar('c', 0, 32)| onechar('c', 8, 32)| onechar('e', 16, 32)| onechar('d', 24, 32):
        switch(string[4]) {
        case 0| onechar('i', 0, 8):
            switch(string[5]) {
            case 0| onechar('l', 0, 8):
                return CharacterReferenceNoSemicolon_ccedil;
            }
        }
        break;
    case 0| onechar('c', 0, 32)| onechar('u', 8, 32)| onechar('r', 16, 32)| onechar('r', 24, 32):
        switch(string[4]) {
        case 0| onechar('e', 0, 8):
            switch(string[5]) {
            case 0| onechar('n', 0, 8):
                return CharacterReferenceNoSemicolon_curren;
            }
        }
        break;
    case 0| onechar('d', 0, 32)| onechar('i', 8, 32)| onechar('v', 16, 32)| onechar('i', 24, 32):
        switch(string[4]) {
        case 0| onechar('d', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return CharacterReferenceNoSemicolon_divide;
            }
        }
        break;
    case 0| onechar('e', 0, 32)| onechar('a', 8, 32)| onechar('c', 16, 32)| onechar('u', 24, 32):
        switch(string[4]) {
        case 0| onechar('t', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return CharacterReferenceNoSemicolon_eacute;
            }
        }
        break;
    case 0| onechar('e', 0, 32)| onechar('g', 8, 32)| onechar('r', 16, 32)| onechar('a', 24, 32):
        switch(string[4]) {
        case 0| onechar('v', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return CharacterReferenceNoSemicolon_egrave;
            }
        }
        break;
    case 0| onechar('f', 0, 32)| onechar('r', 8, 32)| onechar('a', 16, 32)| onechar('c', 24, 32):
        switch(string[4]) {
        case 0| onechar('1', 0, 8):
            switch(string[5]) {
            case 0| onechar('2', 0, 8):
                return CharacterReferenceNoSemicolon_frac12;
                break;
            case 0| onechar('4', 0, 8):
                return CharacterReferenceNoSemicolon_frac14;
            }
            break;
        case 0| onechar('3', 0, 8):
            switch(string[5]) {
            case 0| onechar('4', 0, 8):
                return CharacterReferenceNoSemicolon_frac34;
            }
        }
        break;
    case 0| onechar('i', 0, 32)| onechar('a', 8, 32)| onechar('c', 16, 32)| onechar('u', 24, 32):
        switch(string[4]) {
        case 0| onechar('t', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return CharacterReferenceNoSemicolon_iacute;
            }
        }
        break;
    case 0| onechar('i', 0, 32)| onechar('g', 8, 32)| onechar('r', 16, 32)| onechar('a', 24, 32):
        switch(string[4]) {
        case 0| onechar('v', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return CharacterReferenceNoSemicolon_igrave;
            }
        }
        break;
    case 0| onechar('i', 0, 32)| onechar('q', 8, 32)| onechar('u', 16, 32)| onechar('e', 24, 32):
        switch(string[4]) {
        case 0| onechar('s', 0, 8):
            switch(string[5]) {
            case 0| onechar('t', 0, 8):
                return CharacterReferenceNoSemicolon_iquest;
            }
        }
        break;
    case 0| onechar('m', 0, 32)| onechar('i', 8, 32)| onechar('d', 16, 32)| onechar('d', 24, 32):
        switch(string[4]) {
        case 0| onechar('o', 0, 8):
            switch(string[5]) {
            case 0| onechar('t', 0, 8):
                return CharacterReferenceNoSemicolon_middot;
            }
        }
        break;
    case 0| onechar('n', 0, 32)| onechar('t', 8, 32)| onechar('i', 16, 32)| onechar('l', 24, 32):
        switch(string[4]) {
        case 0| onechar('d', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return CharacterReferenceNoSemicolon_ntilde;
            }
        }
        break;
    case 0| onechar('o', 0, 32)| onechar('a', 8, 32)| onechar('c', 16, 32)| onechar('u', 24, 32):
        switch(string[4]) {
        case 0| onechar('t', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return CharacterReferenceNoSemicolon_oacute;
            }
        }
        break;
    case 0| onechar('o', 0, 32)| onechar('g', 8, 32)| onechar('r', 16, 32)| onechar('a', 24, 32):
        switch(string[4]) {
        case 0| onechar('v', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return CharacterReferenceNoSemicolon_ograve;
            }
        }
        break;
    case 0| onechar('o', 0, 32)| onechar('s', 8, 32)| onechar('l', 16, 32)| onechar('a', 24, 32):
        switch(string[4]) {
        case 0| onechar('s', 0, 8):
            switch(string[5]) {
            case 0| onechar('h', 0, 8):
                return CharacterReferenceNoSemicolon_oslash;
            }
        }
        break;
    case 0| onechar('o', 0, 32)| onechar('t', 8, 32)| onechar('i', 16, 32)| onechar('l', 24, 32):
        switch(string[4]) {
        case 0| onechar('d', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return CharacterReferenceNoSemicolon_otilde;
            }
        }
        break;
    case 0| onechar('p', 0, 32)| onechar('l', 8, 32)| onechar('u', 16, 32)| onechar('s', 24, 32):
        switch(string[4]) {
        case 0| onechar('m', 0, 8):
            switch(string[5]) {
            case 0| onechar('n', 0, 8):
                return CharacterReferenceNoSemicolon_plusmn;
            }
        }
        break;
    case 0| onechar('u', 0, 32)| onechar('a', 8, 32)| onechar('c', 16, 32)| onechar('u', 24, 32):
        switch(string[4]) {
        case 0| onechar('t', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return CharacterReferenceNoSemicolon_uacute;
            }
        }
        break;
    case 0| onechar('u', 0, 32)| onechar('g', 8, 32)| onechar('r', 16, 32)| onechar('a', 24, 32):
        switch(string[4]) {
        case 0| onechar('v', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return CharacterReferenceNoSemicolon_ugrave;
            }
        }
        break;
    case 0| onechar('y', 0, 32)| onechar('a', 8, 32)| onechar('c', 16, 32)| onechar('u', 24, 32):
        switch(string[4]) {
        case 0| onechar('t', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return CharacterReferenceNoSemicolon_yacute;
            }
        }
    }
    return CharacterReferenceNoSemicolon_Unknown;
}
#else
static enum CharacterReferenceNoSemicolon lookup_character_reference_no_semicolon2(const char *string)
{
    switch(string[0]) {
    case 'G':
        switch(string[1]) {
        case 'T':
            return CharacterReferenceNoSemicolon_GT;
        }
        break;
    case 'L':
        switch(string[1]) {
        case 'T':
            return CharacterReferenceNoSemicolon_LT;
        }
        break;
    case 'g':
        switch(string[1]) {
        case 't':
            return CharacterReferenceNoSemicolon_gt;
        }
        break;
    case 'l':
        switch(string[1]) {
        case 't':
            return CharacterReferenceNoSemicolon_lt;
        }
    }
    return CharacterReferenceNoSemicolon_Unknown;
}
static enum CharacterReferenceNoSemicolon lookup_character_reference_no_semicolon3(const char *string)
{
    switch(string[0]) {
    case 'A':
        switch(string[1]) {
        case 'M':
            switch(string[2]) {
            case 'P':
                return CharacterReferenceNoSemicolon_AMP;
            }
        }
        break;
    case 'E':
        switch(string[1]) {
        case 'T':
            switch(string[2]) {
            case 'H':
                return CharacterReferenceNoSemicolon_ETH;
            }
        }
        break;
    case 'R':
        switch(string[1]) {
        case 'E':
            switch(string[2]) {
            case 'G':
                return CharacterReferenceNoSemicolon_REG;
            }
        }
        break;
    case 'a':
        switch(string[1]) {
        case 'm':
            switch(string[2]) {
            case 'p':
                return CharacterReferenceNoSemicolon_amp;
            }
        }
        break;
    case 'd':
        switch(string[1]) {
        case 'e':
            switch(string[2]) {
            case 'g':
                return CharacterReferenceNoSemicolon_deg;
            }
        }
        break;
    case 'e':
        switch(string[1]) {
        case 't':
            switch(string[2]) {
            case 'h':
                return CharacterReferenceNoSemicolon_eth;
            }
        }
        break;
    case 'n':
        switch(string[1]) {
        case 'o':
            switch(string[2]) {
            case 't':
                return CharacterReferenceNoSemicolon_not;
            }
        }
        break;
    case 'r':
        switch(string[1]) {
        case 'e':
            switch(string[2]) {
            case 'g':
                return CharacterReferenceNoSemicolon_reg;
            }
        }
        break;
    case 's':
        switch(string[1]) {
        case 'h':
            switch(string[2]) {
            case 'y':
                return CharacterReferenceNoSemicolon_shy;
            }
        }
        break;
    case 'u':
        switch(string[1]) {
        case 'm':
            switch(string[2]) {
            case 'l':
                return CharacterReferenceNoSemicolon_uml;
            }
        }
        break;
    case 'y':
        switch(string[1]) {
        case 'e':
            switch(string[2]) {
            case 'n':
                return CharacterReferenceNoSemicolon_yen;
            }
        }
    }
    return CharacterReferenceNoSemicolon_Unknown;
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
                    return CharacterReferenceNoSemicolon_Auml;
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
                    return CharacterReferenceNoSemicolon_COPY;
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
                    return CharacterReferenceNoSemicolon_Euml;
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
                    return CharacterReferenceNoSemicolon_Iuml;
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
                    return CharacterReferenceNoSemicolon_Ouml;
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
                    return CharacterReferenceNoSemicolon_QUOT;
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
                    return CharacterReferenceNoSemicolon_Uuml;
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
                    return CharacterReferenceNoSemicolon_auml;
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
                    return CharacterReferenceNoSemicolon_cent;
                }
            }
            break;
        case 'o':
            switch(string[2]) {
            case 'p':
                switch(string[3]) {
                case 'y':
                    return CharacterReferenceNoSemicolon_copy;
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
                    return CharacterReferenceNoSemicolon_euml;
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
                    return CharacterReferenceNoSemicolon_iuml;
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
                    return CharacterReferenceNoSemicolon_macr;
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
                    return CharacterReferenceNoSemicolon_nbsp;
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
                    return CharacterReferenceNoSemicolon_ordf;
                    break;
                case 'm':
                    return CharacterReferenceNoSemicolon_ordm;
                }
            }
            break;
        case 'u':
            switch(string[2]) {
            case 'm':
                switch(string[3]) {
                case 'l':
                    return CharacterReferenceNoSemicolon_ouml;
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
                    return CharacterReferenceNoSemicolon_para;
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
                    return CharacterReferenceNoSemicolon_quot;
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
                    return CharacterReferenceNoSemicolon_sect;
                }
            }
            break;
        case 'u':
            switch(string[2]) {
            case 'p':
                switch(string[3]) {
                case '1':
                    return CharacterReferenceNoSemicolon_sup1;
                    break;
                case '2':
                    return CharacterReferenceNoSemicolon_sup2;
                    break;
                case '3':
                    return CharacterReferenceNoSemicolon_sup3;
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
                    return CharacterReferenceNoSemicolon_uuml;
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
                    return CharacterReferenceNoSemicolon_yuml;
                }
            }
        }
    }
    return CharacterReferenceNoSemicolon_Unknown;
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
                        return CharacterReferenceNoSemicolon_AElig;
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
                        return CharacterReferenceNoSemicolon_Acirc;
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
                        return CharacterReferenceNoSemicolon_Aring;
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
                        return CharacterReferenceNoSemicolon_Ecirc;
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
                        return CharacterReferenceNoSemicolon_Icirc;
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
                        return CharacterReferenceNoSemicolon_Ocirc;
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
                        return CharacterReferenceNoSemicolon_THORN;
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
                        return CharacterReferenceNoSemicolon_Ucirc;
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
                        return CharacterReferenceNoSemicolon_acirc;
                    }
                }
                break;
            case 'u':
                switch(string[3]) {
                case 't':
                    switch(string[4]) {
                    case 'e':
                        return CharacterReferenceNoSemicolon_acute;
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
                        return CharacterReferenceNoSemicolon_aelig;
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
                        return CharacterReferenceNoSemicolon_aring;
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
                        return CharacterReferenceNoSemicolon_cedil;
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
                        return CharacterReferenceNoSemicolon_ecirc;
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
                        return CharacterReferenceNoSemicolon_icirc;
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
                        return CharacterReferenceNoSemicolon_iexcl;
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
                        return CharacterReferenceNoSemicolon_laquo;
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
                        return CharacterReferenceNoSemicolon_micro;
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
                        return CharacterReferenceNoSemicolon_ocirc;
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
                        return CharacterReferenceNoSemicolon_pound;
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
                        return CharacterReferenceNoSemicolon_raquo;
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
                        return CharacterReferenceNoSemicolon_szlig;
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
                        return CharacterReferenceNoSemicolon_thorn;
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
                        return CharacterReferenceNoSemicolon_times;
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
                        return CharacterReferenceNoSemicolon_ucirc;
                    }
                }
            }
        }
    }
    return CharacterReferenceNoSemicolon_Unknown;
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
                            return CharacterReferenceNoSemicolon_Aacute;
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
                            return CharacterReferenceNoSemicolon_Agrave;
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
                            return CharacterReferenceNoSemicolon_Atilde;
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
                            return CharacterReferenceNoSemicolon_Ccedil;
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
                            return CharacterReferenceNoSemicolon_Eacute;
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
                            return CharacterReferenceNoSemicolon_Egrave;
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
                            return CharacterReferenceNoSemicolon_Iacute;
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
                            return CharacterReferenceNoSemicolon_Igrave;
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
                            return CharacterReferenceNoSemicolon_Ntilde;
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
                            return CharacterReferenceNoSemicolon_Oacute;
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
                            return CharacterReferenceNoSemicolon_Ograve;
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
                            return CharacterReferenceNoSemicolon_Oslash;
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
                            return CharacterReferenceNoSemicolon_Otilde;
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
                            return CharacterReferenceNoSemicolon_Uacute;
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
                            return CharacterReferenceNoSemicolon_Ugrave;
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
                            return CharacterReferenceNoSemicolon_Yacute;
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
                            return CharacterReferenceNoSemicolon_aacute;
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
                            return CharacterReferenceNoSemicolon_agrave;
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
                            return CharacterReferenceNoSemicolon_atilde;
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
                            return CharacterReferenceNoSemicolon_brvbar;
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
                            return CharacterReferenceNoSemicolon_ccedil;
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
                            return CharacterReferenceNoSemicolon_curren;
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
                            return CharacterReferenceNoSemicolon_divide;
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
                            return CharacterReferenceNoSemicolon_eacute;
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
                            return CharacterReferenceNoSemicolon_egrave;
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
                            return CharacterReferenceNoSemicolon_frac12;
                            break;
                        case '4':
                            return CharacterReferenceNoSemicolon_frac14;
                        }
                        break;
                    case '3':
                        switch(string[5]) {
                        case '4':
                            return CharacterReferenceNoSemicolon_frac34;
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
                            return CharacterReferenceNoSemicolon_iacute;
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
                            return CharacterReferenceNoSemicolon_igrave;
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
                            return CharacterReferenceNoSemicolon_iquest;
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
                            return CharacterReferenceNoSemicolon_middot;
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
                            return CharacterReferenceNoSemicolon_ntilde;
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
                            return CharacterReferenceNoSemicolon_oacute;
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
                            return CharacterReferenceNoSemicolon_ograve;
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
                            return CharacterReferenceNoSemicolon_oslash;
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
                            return CharacterReferenceNoSemicolon_otilde;
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
                            return CharacterReferenceNoSemicolon_plusmn;
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
                            return CharacterReferenceNoSemicolon_uacute;
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
                            return CharacterReferenceNoSemicolon_ugrave;
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
                            return CharacterReferenceNoSemicolon_yacute;
                        }
                    }
                }
            }
        }
    }
    return CharacterReferenceNoSemicolon_Unknown;
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
        return CharacterReferenceNoSemicolon_Unknown;
    }
}
#endif                       /* TRIE_HASH_lookup_character_reference_no_semicolon */
