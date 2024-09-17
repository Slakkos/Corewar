/*
** EPITECH PROJECT, 2023
** EPITECH
** File description:
** clean_header.c
*/

#include "includes/lib.h"

void process(char **dest, char **str_cp, int *i, char c)
{
    if (**str_cp != c) {
        **dest = **str_cp;
        (*dest)++;
        *i = 0;
    } else if (!(*i) && **str_cp != '\0' &&
    *(*str_cp + 1) != ' ' && *(*str_cp + 1) != '\t') {
        **dest = ' ';
        (*dest)++;
        *i = 1;
    }
    (*str_cp)++;
}

void clean(char **str, char c)
{
    char *str_cp = *str;
    char *dest = *str;
    int i = 0;

    while (*str_cp) {
        process(&dest, &str_cp, &i, c);
    }
    while (*str != dest && **str == ' ') {
        (*str)++;
    }
    while (*str != dest && *(dest - 1) == ' ') {
        dest--;
    }
    *dest = '\0';
}

void my_clean_str(char **str, char *symbols, int nb)
{
    char *str_copy = my_strdup(*str);

    free(*str);
    for (int i = 0; symbols[i]; i++) {
        clean(&str_copy, symbols[i]);
        *str = str_copy;
    }
    if (nb) {
        clean(&str_copy, '\t');
        *str = str_copy;
        clean(&str_copy, ' ');
        *str = str_copy;
    }
}
