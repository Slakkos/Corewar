/*
** EPITECH PROJECT, 2023
** lib
** File description:
** my_findinstr.c
*/

#include "includes/lib.h"

int check_find(char c, char *find)
{
    for (int j = 0; find[j]; j++) {
        if (find[j] == c)
            return TRUE;
    }
    return FALSE;
}

int my_findinstr(char *str, char *find)
{
    int i = 0;

    while (str[i]) {
        if (check_find(str[i], find))
            return TRUE;
        i++;
    }
    return FALSE;
}
