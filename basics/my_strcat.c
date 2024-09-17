/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** my_strcat.c
*/

#include "includes/lib.h"

char *my_strcat(char *s1, char *s2)
{
    int i = 0;
    int len_1 = my_strlen(s1);
    int len_2 = my_strlen(s2);
    char *result = malloc(sizeof(char) * (len_1 + len_2 + 1));

    for (; i < len_1; i++)
        result[i] = s1[i];
    i = 0;
    for (; i < len_2; i++)
        result[len_1 + i] = s2[i];
    result[len_1 + i] = '\0';
    free(s1);
    return (result);
}
