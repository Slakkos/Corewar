/*
** EPITECH PROJECT, 2023
** EPITECH
** File description:
** my_swap_16bytes.c
*/

#include "includes/lib.h"

int my_swap_32bytes(int value)
{
    return ((value & 0x000000FF) << 24) |
    ((value & 0x0000FF00) << 8) |
    ((value & 0x00FF0000) >> 8) |
    ((value & 0xFF000000) >> 24);
}
