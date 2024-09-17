/*
** EPITECH PROJECT, 2023
** lib
** File description:
** my_tabdup.c
*/

#include "includes/lib.h"

char **my_tabdup(char **tab)
{
    char **result;
    int i = 0;

    result = malloc(sizeof(char *) * (my_tablen(tab) + 1));
    for (; tab[i]; i++)
        result[i] = my_strdup(tab[i]);
    tab[i] = NULL;
    return result;
}
