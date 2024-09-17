/*
** EPITECH PROJECT, 2023
** EPITECH
** File description:
** my_strlen.c
*/

#include "includes/lib.h"

int my_strlen(char *str)
{
    if (*str == 0)
        return 0;
    return my_strlen(str + 1) + 1;
}
