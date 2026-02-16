#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

static inline bool is_ascii(int c) {
    return (c & ~0x7f) == 0;
}

static inline bool is_ascii_alpha(int32_t c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

static inline bool is_ascii_digit(int32_t c) {
    return c >= '0' && c <= '9';
}

static inline bool is_ascii_alnum(int32_t c) {
    return is_ascii_alpha(c) || is_ascii_digit(c);
}

static inline bool is_ascii_xdigit(int32_t c) {
    return is_ascii_digit(c) || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f');
}

static inline int32_t ascii_tolower(int32_t c) {
    return (c >= 'A' && c <= 'Z') ? (c | 0x20) : c;
}

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
    else {
        return 0;
    }
}

static size_t to_vlq(size_t in, char* const out) {
    if (in < 128) {
        out[0] = in;
        return 1;
    }

    // Count bytes needed
    size_t len = 0;
    for (size_t tmp = in; tmp > 0; tmp >>= 7) len++;

    // Write in reverse order (most significant byte first)
    for (size_t i = len; i > 0; i--) {
        out[i - 1] = (in & 127) | (i < len ? 128 : 0);
        in >>= 7;
    }

    return len;
}
static size_t vlq_length(size_t in) {
    size_t len = 1;
    while (in >= 128) {
        len++;
        in >>= 7;
    }
    return len;
}

static bool from_vlq_bounded(const char *in, const char *end, size_t *out, size_t *consumed) {
    if (in >= end)
        return false;

    if ((unsigned char)in[0] < 128) {
        *out = (unsigned char)in[0];
        *consumed = 1;
        return true;
    }

    size_t idx = 0;
    *out = 0;

    while (in + idx < end) {
        unsigned char byte = (unsigned char)in[idx];
        if (*out > (SIZE_MAX >> 7))
            return false;
        *out = (*out << 7) | (size_t)(byte & 127);
        idx++;
        if (!(byte & 128)) {
            *consumed = idx;
            return true;
        }
    }

    return false;
}

static inline bool is_html_whitespace(int32_t c) {
    // Ordered by frequency: space is most common, then newline, tab, carriage return, form feed
    return c == ' ' || c == '\n' || c == '\t' || c == '\r' || c == '\f';
}
