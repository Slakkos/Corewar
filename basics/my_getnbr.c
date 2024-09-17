/*
** EPITECH PROJECT, 2023
** directory
** File description:
** my_get_nbr.c
*/

#include "includes/lib.h"

int my_getnbr(char const *str)
{
    int result = 0;
    int sign = 1;
    int i = 0;
    int x = 0;

    while (str[i] > '9' && str[i] < '0' && str[i] != '\0')
        i++;
    if (str[i] == '\0')
        return 0;
    if (str[0] == '-')
        sign = -1;
    x = i;
    for (; str[x] != '\0'; x++) {
        if (str[x] <= '9' && str[x] >= '0') {
            result = result + (str[x] - 48);
            result = result * 10;
        }
    }
    result = result / 10;
    return result * sign;
}
