/*
** EPITECH PROJECT, 2024
** my_putstr.c
** File description:
** my_putstr
*/

#include "includes/lib.h"

void my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}
