/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-jules.lordet
** File description:
** split_binary_string.c
*/

#include "../includes/my.h"

static char **allocate_memory(size_t count)
{
    char **result = (char **)malloc((count + 1) * sizeof(char *));

    if (result == NULL) {
        return NULL;
    }
    return result;
}

static void free_memory(char **result, size_t i)
{
    for (size_t j = 0; j < i; j++) {
        free(result[j]);
    }
    free(result);
}

size_t get_length_and_validate(const char *binary_string)
{
    size_t length = strlen(binary_string);

    if (length % 2 != 0) {
        return 0;
    }
    return length;
}

char **allocate_and_validate_memory(size_t count)
{
    char **result = allocate_memory(count);

    if (result == NULL) {
        return NULL;
    }
    return result;
}

char *allocate_and_copy_string(const char *binary_string, size_t i)
{
    char *result = (char *)malloc(3 * sizeof(char));

    if (result == NULL) {
        return NULL;
    }
    strncpy(result, binary_string + (i * 2), 2);
    result[2] = '\0';
    return result;
}

char **split_binary_string(const char *binary_string)
{
    size_t length = get_length_and_validate(binary_string);
    size_t count;
    char **result;

    if (length == 0)
        return NULL;
    count = length / 2;
    result = allocate_and_validate_memory(count);
    if (result == NULL)
        return NULL;
    for (size_t i = 0; i < count; i++) {
        result[i] = allocate_and_copy_string(binary_string, i);
        if (result[i] == NULL) {
            free_memory(result, i);
            return NULL;
        }
    }
    result[count] = NULL;
    return result;
}
