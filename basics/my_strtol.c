/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-jules.lordet
** File description:
** my_strtol.c
*/

#include "includes/lib.h"
#include <limits.h>

const char *skip_whitespace(const char *s)
{
    while (*s == ' ' || *s == '\t' || *s == '\n' ||
        *s == '\v' || *s == '\f' || *s == '\r') {
        s++;
    }
    return s;
}

int handle_sign(const char **s)
{
    int sign = 1;

    if (**s == '-') {
        sign = -1;
        (*s)++;
    } else if (**s == '+') {
        (*s)++;
    }
    return sign;
}

static int handle_base_zero(const char **s)
{
    int base;

    if (**s == '0') {
        if (*(*s + 1) == 'x' || *(*s + 1) == 'X') {
            base = 16;
            *s += 2;
        } else {
            base = 8;
            (*s)++;
        }
    } else {
        base = 10;
    }
    return base;
}

static int handle_base_sixteen(const char **s)
{
    if (**s == '0' && (*(*s + 1) == 'x' || *(*s + 1) == 'X')) {
        *s += 2;
    }
    return 16;
}

static int detect_base(const char **s, int base)
{
    if (base == 0) {
        base = handle_base_zero(s);
    } else if (base == 16) {
        base = handle_base_sixteen(s);
    }
    return base;
}

int convert_char_to_digit(char c, int base, int *digit)
{
    if (c >= '0' && c <= '9') {
        *digit = c - '0';
        return (*digit < base);
    }
    if (c >= 'a' && c <= 'z') {
        *digit = c - 'a' + 10;
        return (*digit < base);
    }
    if (c >= 'A' && c <= 'Z') {
        *digit = c - 'A' + 10;
        return (*digit < base);
    }
    return 0;
}

static long convert_str_to_long(const char *s, int base,
    int sign, int *overflow)
{
    long result = 0;
    int digit;

    while (*s) {
        if (!convert_char_to_digit(*s, base, &digit)) {
            break;
        }
        if (result > (LONG_MAX - digit) / base) {
            *overflow = 1;
        } else {
            result = result * base + digit;
        }
        s++;
    }
    return sign * result;
}

long my_strtol(const char *__restrict__ nptr,
    char **__restrict__ endptr, int base)
{
    const char *s = nptr;
    int sign, overflow = 0;
    long result;

    s = skip_whitespace(s);
    sign = handle_sign(&s);
    base = detect_base(&s, base);
    result = convert_str_to_long(s, base, sign, &overflow);
    if (endptr)
        *endptr = (char *)s;
    if (overflow)
        return (sign == 1) ? LONG_MAX : LONG_MIN;
    return result;
}
