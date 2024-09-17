/*
** EPITECH PROJECT, 2023
** lib
** File description:
** my_puttab.c
*/

#include "includes/lib.h"

void my_puttab(char **tab)
{
    if (tab == NULL)
        return;
    for (int i = 0; tab[i]; i++) {
        my_putstr(tab[i]);
        my_putstr("\n");
    }
}
