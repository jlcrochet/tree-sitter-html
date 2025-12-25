#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

static inline bool is_ascii(int c) {
    return (c & ~0x7f) == 0;
}

// Source: <https://stackoverflow.com/a/42013433/11588119>
static size_t codepoint_to_utf8(char* const bytes, const int32_t codepoint) {
    if (codepoint <= 0x7F) {
        bytes[0] = codepoint;
        return 1;
    }
    else if (codepoint <= 0x7FF) {
        bytes[0] = 0xC0 | (codepoint >> 6);            /* 110xxxxx */
        bytes[1] = 0x80 | (codepoint & 0x3F);          /* 10xxxxxx */
        return 2;
    }
    else if (codepoint <= 0xFFFF) {
        bytes[0] = 0xE0 | (codepoint >> 12);           /* 1110xxxx */
        bytes[1] = 0x80 | ((codepoint >> 6) & 0x3F);   /* 10xxxxxx */
        bytes[2] = 0x80 | (codepoint & 0x3F);          /* 10xxxxxx */
        return 3;
    }
    else if (codepoint <= 0x10FFFF) {
        bytes[0] = 0xF0 | (codepoint >> 18);           /* 11110xxx */
        bytes[1] = 0x80 | ((codepoint >> 12) & 0x3F);  /* 10xxxxxx */
        bytes[2] = 0x80 | ((codepoint >> 6) & 0x3F);   /* 10xxxxxx */
        bytes[3] = 0x80 | (codepoint & 0x3F);          /* 10xxxxxx */
        return 4;
    }
    return 0;
}

// Source: <https://rosettacode.org/wiki/Variable-length_quantity#C>
static size_t to_vlq(size_t in, char* const out) {
    if (in < 128) {
        out[0] = in;
        return 1;
    }

    int i, j;

    for (i = 9; i > 0; i--)
        if (in & 127ULL << i * 7) break;
    for (j = 0; j <= i; j++)
        out[j] = ((in >> ((i - j) * 7)) & 127) | 128;
    out[i] ^= 128;

    return i + 1;
}
static size_t from_vlq(const char* in, size_t* out) {
    if ((unsigned char)in[0] < 128) {
        *out = (unsigned char)in[0];
        return 1;
    }

    size_t idx = 0;
    *out = 0;

    do {
        *out = (*out << 7) | (size_t)(in[idx] & 127);
    } while (in[idx++] & 128);

    return idx;
}

static inline bool is_html_whitespace(int32_t c) {
    return c == '\t' || c == '\n' || c == '\f' || c == '\r' || c == ' ';
}
