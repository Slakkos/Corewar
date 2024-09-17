/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** my_putstr_02x.c
*/

#include "includes/lib.h"

void my_putstr_02x(char value)
{
    char result[3];
    const char hex_digits[] = "0123456789abcdef";

    result[0] = hex_digits[(value >> 4) & 0xF];
    result[1] = hex_digits[value & 0xF];
    result[2] = '\0';
    my_putstr(result);
}
