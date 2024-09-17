/*
** EPITECH PROJECT, 2023
** EPITECH
** File description:
** my_strdup.c
*/

#include "includes/lib.h"

char *my_strdup(char *src)
{
    char *dest;

    dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    if (dest == NULL)
        return NULL;
    for (int i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[my_strlen(src)] = '\0';
    return dest;
}
