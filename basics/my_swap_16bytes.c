/*
** EPITECH PROJECT, 2023
** EPITECH
** File description:
** my_swap_16bytes.c
*/

#include "includes/lib.h"

int my_swap_16bytes(int value)
{
    return ((value & 0x00FF) << 8) |
    ((value & 0xFF00) >> 8);
}
