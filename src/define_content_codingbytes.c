/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-jules.lordet
** File description:
** define_content_codingbytes.c
*/

#include "../includes/my.h"

static char *rename_values(char *value)
{
    switch (value[0]) {
        case '0':
            return (value[1] == '1') ? "registre" : "otherwise";
        case '1':
            return ((value[1] == '0') ? "direct" :
            (value[1] == '1') ? "indirect" : "otherwise");
        default:
            return "otherwise";
    }
}

static size_t count_valid_elements(char **table)
{
    size_t size = 0;
    size_t count = 0;

    for (size = 0; table[size] != NULL; size++) {
        if (!(table[size][0] == '0' && table[size][1] == '0')) {
            count++;
        }
    }
    return count;
}

char **allocate_memory(size_t count)
{
    char **renamed_table = malloc((count + 1) * sizeof(char *));

    return renamed_table;
}

void free_memory_for_renamed_table(char **renamed_table, size_t count)
{
    for (size_t j = 0; j < count; j++) {
        free(renamed_table[j]);
    }
    free(renamed_table);
}

char *rename_value_and_validate(char **table,
    char **renamed_table, size_t i, size_t *count)
{
    if (table[i][0] == '0' && table[i][1] == '0') {
        return "valid";
    }
    renamed_table[*count] = rename_values(table[i]);
    if (renamed_table[*count] == NULL) {
        free_memory_for_renamed_table(renamed_table, *count);
        return NULL;
    }
    (*count)++;
    return "valid";
}

char **rename_content_bytescode(char **table)
{
    size_t count = 0;
    char **renamed_table = allocate_memory(count_valid_elements(table));

    if (renamed_table == NULL) {
        return NULL;
    }
    for (size_t i = 0; table[i] != NULL; i++) {
        if (rename_value_and_validate(table, renamed_table,
        i, &count) == NULL) {
            return NULL;
        }
    }
    renamed_table[count] = NULL;
    return renamed_table;
}
