/*
** EPITECH PROJECT, 2023
** lib
** File description:
** my_isuppercase.c
*/

#include "includes/lib.h"

int my_isuppercase(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (!(str[i] >= 'A' && str[i] <= 'Z'))
            return FALSE;
    }
    return TRUE;
}
