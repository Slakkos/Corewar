/*
** EPITECH PROJECT, 2023
** EPITECH
** File description:
** my_putnbr.c
*/

#include "includes/lib.h"

void my_putnbr(int n)
{
    int mod;

    if (n < 0) {
        my_putchar('-');
        n = n * (-1);
    }
    if (n >= 10) {
        mod = n % 10;
        n = (n - mod) / 10;
        my_putnbr(n);
        my_putchar(mod + '0');
    } else {
        my_putchar('0' + n);
    }
}
