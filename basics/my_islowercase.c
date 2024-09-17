/*
** EPITECH PROJECT, 2023
** lib
** File description:
** my_islowercase.c
*/

#include "includes/lib.h"

int my_islowercase(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (!(str[i] >= 'a' && str[i] <= 'z'))
            return FALSE;
    }
    return TRUE;
}
