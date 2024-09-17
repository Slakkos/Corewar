/*
** EPITECH PROJECT, 2023
** EPITECH
** File description:
** my_strcpy.c
*/

#include "includes/lib.h"

char *my_strcpy(char *dest, char *src)
{
    for (int i = 0; src[i]; i++)
        dest[i] = src[i];
    dest[my_strlen(src)] = '\0';
    return dest;
}
