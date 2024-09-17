/*
** EPITECH PROJECT, 2023
** lib
** File description:
** my_replace_char.c
*/

#include "includes/lib.h"
#include <stdio.h>

void my_replace_char(char **str, char c, char r)
{
    for (int i = 0; (*str)[i]; i++) {
        if ((*str)[i] == c)
            (*str)[i] = r;
    }
}
