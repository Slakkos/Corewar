/*
** EPITECH PROJECT, 2023
** lib
** File description:
** my_tablen.c
*/

#include "includes/lib.h"

int my_tablen(char **tab)
{
    int i = 0;

    while (tab[i]) {
        i++;
    }
    return i;
}
