/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** my_strncmp.c
*/

#include "includes/lib.h"

int my_strcmp(char *s1, char *s2)
{
    for (int i = 0; s1[i] || s2[i]; i++) {
        if (s1[i] != s2[i])
            return FALSE;
    }
    return TRUE;
}
