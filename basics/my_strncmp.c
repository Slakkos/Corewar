/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** my_strncmp.c
*/

#include "includes/lib.h"

int my_strncmp(char *s1, char *s2, int nb)
{
    for (int i = 0; i < nb || (s1[i] && s2[i]); i++) {
        if (s1[i] != s2[i])
            return FALSE;
    }
    return TRUE;
}
