/*
** EPITECH PROJECT, 2023
** lib
** File description:
** my_isalpha.c
*/

#include "includes/lib.h"

int my_isalpha(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (!(str[i] >= '0' && str[i] <= '9') &&
        !(str[i] >= 'A' && str[i] <= 'Z') &&
        !(str[i] >= 'a' && str[i] <= 'z'))
            return FALSE;
    }
    return TRUE;
}
