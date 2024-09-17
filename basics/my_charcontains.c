/*
** EPITECH PROJECT, 2023
** lib
** File description:
** my_charcontains.c
*/

#include "includes/lib.h"

int my_charcontains(char *str, char c)
{
    if (str == NULL || c == '\0')
        return FALSE;
    if (c == '\0')
        return FALSE;
    for (int i = 0; str[i]; i++) {
        if (str[i] == c)
            return TRUE;
    }
    return FALSE;
}
