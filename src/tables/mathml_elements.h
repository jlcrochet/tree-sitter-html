#ifndef TRIE_HASH_lookup_mathml_element
#define TRIE_HASH_lookup_mathml_element
#include <stddef.h>
#include <stdint.h>
enum { MathmlElement_Count = 31 };
enum MathmlElement {
    MathmlElement_annotation = 1,
    MathmlElement_annotation_xml = 2,
    MathmlElement_mi = 7,
    MathmlElement_mn = 9,
    MathmlElement_mo = 10,
    MathmlElement_ms = 17,
    MathmlElement_mtd = 25,
    MathmlElement_mtr = 27,
    MathmlElement_maction = 3,
    MathmlElement_math = 4,
    MathmlElement_merror = 5,
    MathmlElement_mfrac = 6,
    MathmlElement_mmultiscripts = 8,
    MathmlElement_mover = 11,
    MathmlElement_mpadded = 12,
    MathmlElement_mphantom = 13,
    MathmlElement_mprescripts = 14,
    MathmlElement_mroot = 15,
    MathmlElement_mrow = 16,
    MathmlElement_mspace = 18,
    MathmlElement_msqrt = 19,
    MathmlElement_mstyle = 20,
    MathmlElement_msub = 21,
    MathmlElement_msubsup = 22,
    MathmlElement_msup = 23,
    MathmlElement_mtable = 24,
    MathmlElement_mtext = 26,
    MathmlElement_munder = 28,
    MathmlElement_munderover = 29,
    MathmlElement_semantics = 30,
    MathmlElement_Unknown = 0,
};
static enum MathmlElement lookup_mathml_element(const char *string, size_t length);
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
static enum MathmlElement lookup_mathml_element2(const char *string)
{
    switch(string[0]) {
    case 0| onechar('m', 0, 8):
        switch(string[1]) {
        case 0| onechar('i', 0, 8):
            return MathmlElement_mi;
            break;
        case 0| onechar('n', 0, 8):
            return MathmlElement_mn;
            break;
        case 0| onechar('o', 0, 8):
            return MathmlElement_mo;
            break;
        case 0| onechar('s', 0, 8):
            return MathmlElement_ms;
        }
    }
    return MathmlElement_Unknown;
}
static enum MathmlElement lookup_mathml_element3(const char *string)
{
    switch(string[0]) {
    case 0| onechar('m', 0, 8):
        switch(string[1]) {
        case 0| onechar('t', 0, 8):
            switch(string[2]) {
            case 0| onechar('d', 0, 8):
                return MathmlElement_mtd;
                break;
            case 0| onechar('r', 0, 8):
                return MathmlElement_mtr;
            }
        }
    }
    return MathmlElement_Unknown;
}
static enum MathmlElement lookup_mathml_element4(const char *string)
{
    switch(*((triehash_uu32*) &string[0])) {
    case 0| onechar('m', 0, 32)| onechar('a', 8, 32)| onechar('t', 16, 32)| onechar('h', 24, 32):
        return MathmlElement_math;
        break;
    case 0| onechar('m', 0, 32)| onechar('r', 8, 32)| onechar('o', 16, 32)| onechar('w', 24, 32):
        return MathmlElement_mrow;
        break;
    case 0| onechar('m', 0, 32)| onechar('s', 8, 32)| onechar('u', 16, 32)| onechar('b', 24, 32):
        return MathmlElement_msub;
        break;
    case 0| onechar('m', 0, 32)| onechar('s', 8, 32)| onechar('u', 16, 32)| onechar('p', 24, 32):
        return MathmlElement_msup;
    }
    return MathmlElement_Unknown;
}
static enum MathmlElement lookup_mathml_element5(const char *string)
{
    switch(*((triehash_uu32*) &string[0])) {
    case 0| onechar('m', 0, 32)| onechar('f', 8, 32)| onechar('r', 16, 32)| onechar('a', 24, 32):
        switch(string[4]) {
        case 0| onechar('c', 0, 8):
            return MathmlElement_mfrac;
        }
        break;
    case 0| onechar('m', 0, 32)| onechar('o', 8, 32)| onechar('v', 16, 32)| onechar('e', 24, 32):
        switch(string[4]) {
        case 0| onechar('r', 0, 8):
            return MathmlElement_mover;
        }
        break;
    case 0| onechar('m', 0, 32)| onechar('r', 8, 32)| onechar('o', 16, 32)| onechar('o', 24, 32):
        switch(string[4]) {
        case 0| onechar('t', 0, 8):
            return MathmlElement_mroot;
        }
        break;
    case 0| onechar('m', 0, 32)| onechar('s', 8, 32)| onechar('q', 16, 32)| onechar('r', 24, 32):
        switch(string[4]) {
        case 0| onechar('t', 0, 8):
            return MathmlElement_msqrt;
        }
        break;
    case 0| onechar('m', 0, 32)| onechar('t', 8, 32)| onechar('e', 16, 32)| onechar('x', 24, 32):
        switch(string[4]) {
        case 0| onechar('t', 0, 8):
            return MathmlElement_mtext;
        }
    }
    return MathmlElement_Unknown;
}
static enum MathmlElement lookup_mathml_element6(const char *string)
{
    switch(*((triehash_uu32*) &string[0])) {
    case 0| onechar('m', 0, 32)| onechar('e', 8, 32)| onechar('r', 16, 32)| onechar('r', 24, 32):
        switch(string[4]) {
        case 0| onechar('o', 0, 8):
            switch(string[5]) {
            case 0| onechar('r', 0, 8):
                return MathmlElement_merror;
            }
        }
        break;
    case 0| onechar('m', 0, 32)| onechar('s', 8, 32)| onechar('p', 16, 32)| onechar('a', 24, 32):
        switch(string[4]) {
        case 0| onechar('c', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return MathmlElement_mspace;
            }
        }
        break;
    case 0| onechar('m', 0, 32)| onechar('s', 8, 32)| onechar('t', 16, 32)| onechar('y', 24, 32):
        switch(string[4]) {
        case 0| onechar('l', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return MathmlElement_mstyle;
            }
        }
        break;
    case 0| onechar('m', 0, 32)| onechar('t', 8, 32)| onechar('a', 16, 32)| onechar('b', 24, 32):
        switch(string[4]) {
        case 0| onechar('l', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                return MathmlElement_mtable;
            }
        }
        break;
    case 0| onechar('m', 0, 32)| onechar('u', 8, 32)| onechar('n', 16, 32)| onechar('d', 24, 32):
        switch(string[4]) {
        case 0| onechar('e', 0, 8):
            switch(string[5]) {
            case 0| onechar('r', 0, 8):
                return MathmlElement_munder;
            }
        }
    }
    return MathmlElement_Unknown;
}
static enum MathmlElement lookup_mathml_element7(const char *string)
{
    switch(*((triehash_uu32*) &string[0])) {
    case 0| onechar('m', 0, 32)| onechar('a', 8, 32)| onechar('c', 16, 32)| onechar('t', 24, 32):
        switch(string[4]) {
        case 0| onechar('i', 0, 8):
            switch(string[5]) {
            case 0| onechar('o', 0, 8):
                switch(string[6]) {
                case 0| onechar('n', 0, 8):
                    return MathmlElement_maction;
                }
            }
        }
        break;
    case 0| onechar('m', 0, 32)| onechar('p', 8, 32)| onechar('a', 16, 32)| onechar('d', 24, 32):
        switch(string[4]) {
        case 0| onechar('d', 0, 8):
            switch(string[5]) {
            case 0| onechar('e', 0, 8):
                switch(string[6]) {
                case 0| onechar('d', 0, 8):
                    return MathmlElement_mpadded;
                }
            }
        }
        break;
    case 0| onechar('m', 0, 32)| onechar('s', 8, 32)| onechar('u', 16, 32)| onechar('b', 24, 32):
        switch(string[4]) {
        case 0| onechar('s', 0, 8):
            switch(string[5]) {
            case 0| onechar('u', 0, 8):
                switch(string[6]) {
                case 0| onechar('p', 0, 8):
                    return MathmlElement_msubsup;
                }
            }
        }
    }
    return MathmlElement_Unknown;
}
static enum MathmlElement lookup_mathml_element8(const char *string)
{
    switch(*((triehash_uu64*) &string[0])) {
    case 0| onechar('m', 0, 64)| onechar('p', 8, 64)| onechar('h', 16, 64)| onechar('a', 24, 64)| onechar('n', 32, 64)| onechar('t', 40, 64)| onechar('o', 48, 64)| onechar('m', 56, 64):
        return MathmlElement_mphantom;
    }
    return MathmlElement_Unknown;
}
static enum MathmlElement lookup_mathml_element9(const char *string)
{
    switch(*((triehash_uu64*) &string[0])) {
    case 0| onechar('s', 0, 64)| onechar('e', 8, 64)| onechar('m', 16, 64)| onechar('a', 24, 64)| onechar('n', 32, 64)| onechar('t', 40, 64)| onechar('i', 48, 64)| onechar('c', 56, 64):
        switch(string[8]) {
        case 0| onechar('s', 0, 8):
            return MathmlElement_semantics;
        }
    }
    return MathmlElement_Unknown;
}
static enum MathmlElement lookup_mathml_element10(const char *string)
{
    switch(*((triehash_uu64*) &string[0])) {
    case 0| onechar('a', 0, 64)| onechar('n', 8, 64)| onechar('n', 16, 64)| onechar('o', 24, 64)| onechar('t', 32, 64)| onechar('a', 40, 64)| onechar('t', 48, 64)| onechar('i', 56, 64):
        switch(string[8]) {
        case 0| onechar('o', 0, 8):
            switch(string[9]) {
            case 0| onechar('n', 0, 8):
                return MathmlElement_annotation;
            }
        }
        break;
    case 0| onechar('m', 0, 64)| onechar('u', 8, 64)| onechar('n', 16, 64)| onechar('d', 24, 64)| onechar('e', 32, 64)| onechar('r', 40, 64)| onechar('o', 48, 64)| onechar('v', 56, 64):
        switch(string[8]) {
        case 0| onechar('e', 0, 8):
            switch(string[9]) {
            case 0| onechar('r', 0, 8):
                return MathmlElement_munderover;
            }
        }
    }
    return MathmlElement_Unknown;
}
static enum MathmlElement lookup_mathml_element11(const char *string)
{
    switch(*((triehash_uu64*) &string[0])) {
    case 0| onechar('m', 0, 64)| onechar('p', 8, 64)| onechar('r', 16, 64)| onechar('e', 24, 64)| onechar('s', 32, 64)| onechar('c', 40, 64)| onechar('r', 48, 64)| onechar('i', 56, 64):
        switch(string[8]) {
        case 0| onechar('p', 0, 8):
            switch(string[9]) {
            case 0| onechar('t', 0, 8):
                switch(string[10]) {
                case 0| onechar('s', 0, 8):
                    return MathmlElement_mprescripts;
                }
            }
        }
    }
    return MathmlElement_Unknown;
}
static enum MathmlElement lookup_mathml_element13(const char *string)
{
    switch(*((triehash_uu64*) &string[0])) {
    case 0| onechar('m', 0, 64)| onechar('m', 8, 64)| onechar('u', 16, 64)| onechar('l', 24, 64)| onechar('t', 32, 64)| onechar('i', 40, 64)| onechar('s', 48, 64)| onechar('c', 56, 64):
        switch(*((triehash_uu32*) &string[8])) {
        case 0| onechar('r', 0, 32)| onechar('i', 8, 32)| onechar('p', 16, 32)| onechar('t', 24, 32):
            switch(string[12]) {
            case 0| onechar('s', 0, 8):
                return MathmlElement_mmultiscripts;
            }
        }
    }
    return MathmlElement_Unknown;
}
static enum MathmlElement lookup_mathml_element14(const char *string)
{
    switch(*((triehash_uu64*) &string[0])) {
    case 0| onechar('a', 0, 64)| onechar('n', 8, 64)| onechar('n', 16, 64)| onechar('o', 24, 64)| onechar('t', 32, 64)| onechar('a', 40, 64)| onechar('t', 48, 64)| onechar('i', 56, 64):
        switch(*((triehash_uu32*) &string[8])) {
        case 0| onechar('o', 0, 32)| onechar('n', 8, 32)| onechar('-', 16, 32)| onechar('x', 24, 32):
            switch(string[12]) {
            case 0| onechar('m', 0, 8):
                switch(string[13]) {
                case 0| onechar('l', 0, 8):
                    return MathmlElement_annotation_xml;
                }
            }
        }
    }
    return MathmlElement_Unknown;
}
#else
static enum MathmlElement lookup_mathml_element2(const char *string)
{
    switch(string[0]) {
    case 'm':
        switch(string[1]) {
        case 'i':
            return MathmlElement_mi;
            break;
        case 'n':
            return MathmlElement_mn;
            break;
        case 'o':
            return MathmlElement_mo;
            break;
        case 's':
            return MathmlElement_ms;
        }
    }
    return MathmlElement_Unknown;
}
static enum MathmlElement lookup_mathml_element3(const char *string)
{
    switch(string[0]) {
    case 'm':
        switch(string[1]) {
        case 't':
            switch(string[2]) {
            case 'd':
                return MathmlElement_mtd;
                break;
            case 'r':
                return MathmlElement_mtr;
            }
        }
    }
    return MathmlElement_Unknown;
}
static enum MathmlElement lookup_mathml_element4(const char *string)
{
    switch(string[0]) {
    case 'm':
        switch(string[1]) {
        case 'a':
            switch(string[2]) {
            case 't':
                switch(string[3]) {
                case 'h':
                    return MathmlElement_math;
                }
            }
            break;
        case 'r':
            switch(string[2]) {
            case 'o':
                switch(string[3]) {
                case 'w':
                    return MathmlElement_mrow;
                }
            }
            break;
        case 's':
            switch(string[2]) {
            case 'u':
                switch(string[3]) {
                case 'b':
                    return MathmlElement_msub;
                    break;
                case 'p':
                    return MathmlElement_msup;
                }
            }
        }
    }
    return MathmlElement_Unknown;
}
static enum MathmlElement lookup_mathml_element5(const char *string)
{
    switch(string[0]) {
    case 'm':
        switch(string[1]) {
        case 'f':
            switch(string[2]) {
            case 'r':
                switch(string[3]) {
                case 'a':
                    switch(string[4]) {
                    case 'c':
                        return MathmlElement_mfrac;
                    }
                }
            }
            break;
        case 'o':
            switch(string[2]) {
            case 'v':
                switch(string[3]) {
                case 'e':
                    switch(string[4]) {
                    case 'r':
                        return MathmlElement_mover;
                    }
                }
            }
            break;
        case 'r':
            switch(string[2]) {
            case 'o':
                switch(string[3]) {
                case 'o':
                    switch(string[4]) {
                    case 't':
                        return MathmlElement_mroot;
                    }
                }
            }
            break;
        case 's':
            switch(string[2]) {
            case 'q':
                switch(string[3]) {
                case 'r':
                    switch(string[4]) {
                    case 't':
                        return MathmlElement_msqrt;
                    }
                }
            }
            break;
        case 't':
            switch(string[2]) {
            case 'e':
                switch(string[3]) {
                case 'x':
                    switch(string[4]) {
                    case 't':
                        return MathmlElement_mtext;
                    }
                }
            }
        }
    }
    return MathmlElement_Unknown;
}
static enum MathmlElement lookup_mathml_element6(const char *string)
{
    switch(string[0]) {
    case 'm':
        switch(string[1]) {
        case 'e':
            switch(string[2]) {
            case 'r':
                switch(string[3]) {
                case 'r':
                    switch(string[4]) {
                    case 'o':
                        switch(string[5]) {
                        case 'r':
                            return MathmlElement_merror;
                        }
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
                    case 'c':
                        switch(string[5]) {
                        case 'e':
                            return MathmlElement_mspace;
                        }
                    }
                }
                break;
            case 't':
                switch(string[3]) {
                case 'y':
                    switch(string[4]) {
                    case 'l':
                        switch(string[5]) {
                        case 'e':
                            return MathmlElement_mstyle;
                        }
                    }
                }
            }
            break;
        case 't':
            switch(string[2]) {
            case 'a':
                switch(string[3]) {
                case 'b':
                    switch(string[4]) {
                    case 'l':
                        switch(string[5]) {
                        case 'e':
                            return MathmlElement_mtable;
                        }
                    }
                }
            }
            break;
        case 'u':
            switch(string[2]) {
            case 'n':
                switch(string[3]) {
                case 'd':
                    switch(string[4]) {
                    case 'e':
                        switch(string[5]) {
                        case 'r':
                            return MathmlElement_munder;
                        }
                    }
                }
            }
        }
    }
    return MathmlElement_Unknown;
}
static enum MathmlElement lookup_mathml_element7(const char *string)
{
    switch(string[0]) {
    case 'm':
        switch(string[1]) {
        case 'a':
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
                                return MathmlElement_maction;
                            }
                        }
                    }
                }
            }
            break;
        case 'p':
            switch(string[2]) {
            case 'a':
                switch(string[3]) {
                case 'd':
                    switch(string[4]) {
                    case 'd':
                        switch(string[5]) {
                        case 'e':
                            switch(string[6]) {
                            case 'd':
                                return MathmlElement_mpadded;
                            }
                        }
                    }
                }
            }
            break;
        case 's':
            switch(string[2]) {
            case 'u':
                switch(string[3]) {
                case 'b':
                    switch(string[4]) {
                    case 's':
                        switch(string[5]) {
                        case 'u':
                            switch(string[6]) {
                            case 'p':
                                return MathmlElement_msubsup;
                            }
                        }
                    }
                }
            }
        }
    }
    return MathmlElement_Unknown;
}
static enum MathmlElement lookup_mathml_element8(const char *string)
{
    switch(string[0]) {
    case 'm':
        switch(string[1]) {
        case 'p':
            switch(string[2]) {
            case 'h':
                switch(string[3]) {
                case 'a':
                    switch(string[4]) {
                    case 'n':
                        switch(string[5]) {
                        case 't':
                            switch(string[6]) {
                            case 'o':
                                switch(string[7]) {
                                case 'm':
                                    return MathmlElement_mphantom;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return MathmlElement_Unknown;
}
static enum MathmlElement lookup_mathml_element9(const char *string)
{
    switch(string[0]) {
    case 's':
        switch(string[1]) {
        case 'e':
            switch(string[2]) {
            case 'm':
                switch(string[3]) {
                case 'a':
                    switch(string[4]) {
                    case 'n':
                        switch(string[5]) {
                        case 't':
                            switch(string[6]) {
                            case 'i':
                                switch(string[7]) {
                                case 'c':
                                    switch(string[8]) {
                                    case 's':
                                        return MathmlElement_semantics;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return MathmlElement_Unknown;
}
static enum MathmlElement lookup_mathml_element10(const char *string)
{
    switch(string[0]) {
    case 'a':
        switch(string[1]) {
        case 'n':
            switch(string[2]) {
            case 'n':
                switch(string[3]) {
                case 'o':
                    switch(string[4]) {
                    case 't':
                        switch(string[5]) {
                        case 'a':
                            switch(string[6]) {
                            case 't':
                                switch(string[7]) {
                                case 'i':
                                    switch(string[8]) {
                                    case 'o':
                                        switch(string[9]) {
                                        case 'n':
                                            return MathmlElement_annotation;
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
        switch(string[1]) {
        case 'u':
            switch(string[2]) {
            case 'n':
                switch(string[3]) {
                case 'd':
                    switch(string[4]) {
                    case 'e':
                        switch(string[5]) {
                        case 'r':
                            switch(string[6]) {
                            case 'o':
                                switch(string[7]) {
                                case 'v':
                                    switch(string[8]) {
                                    case 'e':
                                        switch(string[9]) {
                                        case 'r':
                                            return MathmlElement_munderover;
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
    return MathmlElement_Unknown;
}
static enum MathmlElement lookup_mathml_element11(const char *string)
{
    switch(string[0]) {
    case 'm':
        switch(string[1]) {
        case 'p':
            switch(string[2]) {
            case 'r':
                switch(string[3]) {
                case 'e':
                    switch(string[4]) {
                    case 's':
                        switch(string[5]) {
                        case 'c':
                            switch(string[6]) {
                            case 'r':
                                switch(string[7]) {
                                case 'i':
                                    switch(string[8]) {
                                    case 'p':
                                        switch(string[9]) {
                                        case 't':
                                            switch(string[10]) {
                                            case 's':
                                                return MathmlElement_mprescripts;
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
    return MathmlElement_Unknown;
}
static enum MathmlElement lookup_mathml_element13(const char *string)
{
    switch(string[0]) {
    case 'm':
        switch(string[1]) {
        case 'm':
            switch(string[2]) {
            case 'u':
                switch(string[3]) {
                case 'l':
                    switch(string[4]) {
                    case 't':
                        switch(string[5]) {
                        case 'i':
                            switch(string[6]) {
                            case 's':
                                switch(string[7]) {
                                case 'c':
                                    switch(string[8]) {
                                    case 'r':
                                        switch(string[9]) {
                                        case 'i':
                                            switch(string[10]) {
                                            case 'p':
                                                switch(string[11]) {
                                                case 't':
                                                    switch(string[12]) {
                                                    case 's':
                                                        return MathmlElement_mmultiscripts;
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
    return MathmlElement_Unknown;
}
static enum MathmlElement lookup_mathml_element14(const char *string)
{
    switch(string[0]) {
    case 'a':
        switch(string[1]) {
        case 'n':
            switch(string[2]) {
            case 'n':
                switch(string[3]) {
                case 'o':
                    switch(string[4]) {
                    case 't':
                        switch(string[5]) {
                        case 'a':
                            switch(string[6]) {
                            case 't':
                                switch(string[7]) {
                                case 'i':
                                    switch(string[8]) {
                                    case 'o':
                                        switch(string[9]) {
                                        case 'n':
                                            switch(string[10]) {
                                            case '-':
                                                switch(string[11]) {
                                                case 'x':
                                                    switch(string[12]) {
                                                    case 'm':
                                                        switch(string[13]) {
                                                        case 'l':
                                                            return MathmlElement_annotation_xml;
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
    return MathmlElement_Unknown;
}
#endif /* TRIE_HASH_MULTI_BYTE */
static enum MathmlElement lookup_mathml_element(const char *string, size_t length)
{
    switch (length) {
    case 2:
        return lookup_mathml_element2(string);
    case 3:
        return lookup_mathml_element3(string);
    case 4:
        return lookup_mathml_element4(string);
    case 5:
        return lookup_mathml_element5(string);
    case 6:
        return lookup_mathml_element6(string);
    case 7:
        return lookup_mathml_element7(string);
    case 8:
        return lookup_mathml_element8(string);
    case 9:
        return lookup_mathml_element9(string);
    case 10:
        return lookup_mathml_element10(string);
    case 11:
        return lookup_mathml_element11(string);
    case 13:
        return lookup_mathml_element13(string);
    case 14:
        return lookup_mathml_element14(string);
    default:
        return MathmlElement_Unknown;
    }
}
#endif                       /* TRIE_HASH_lookup_mathml_element */
