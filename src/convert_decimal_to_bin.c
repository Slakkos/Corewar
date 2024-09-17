/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-jules.lordet
** File description:
** convert_decimal_to_bin.c
*/

#include "../includes/my.h"

char *int_to_binary(int n)
{
    char *binary = (char *)malloc(9 * sizeof(char));
    int index;

    if (binary == NULL)
        return NULL;
    for (int i = 0; i < 8; i++) {
        binary[i] = '0';
    }
    binary[8] = '\0';
    index = 7;
    while (n > 0 && index >= 0) {
        binary[index] = (n % 2) + '0';
        n /= 2;
        index--;
    }
    return binary;
}