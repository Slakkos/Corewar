/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-jules.lordet
** File description:
** convert_bin_to_decimal.c
*/

#include "../includes/my.h"

int bin_to_str(const char *bin_str)
{
    int result = 0;

    while (*bin_str) {
        result = (result << 1) | (*bin_str - '0');
        bin_str++;
    }
    return result;
}

int calculate_array_size(char **bin_strs)
{
    int size = 0;

    while (bin_strs[size] != NULL) {
        size++;
    }
    return size;
}

int *convert_bin_array(char **bin_strs)
{
    int size = calculate_array_size(bin_strs);
    int *intArray = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        intArray[i] = bin_to_str(bin_strs[i]);
    }
    return intArray;
}

