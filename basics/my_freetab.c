/*
** EPITECH PROJECT, 2023
** lib
** File description:
** my_freetab.c
*/

#include "includes/lib.h"

void my_freetab(char **tab)
{
    if (tab) {
        for (int i = 0; tab[i]; i++)
            free(tab[i]);
        free(tab);
    }
}
