/*
** EPITECH PROJECT, 2023
** lib
** File description:
** my_isnumber.c
*/

#include "includes/lib.h"

int my_isnumber(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return FALSE;
    }
    return TRUE;
}
