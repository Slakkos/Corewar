/*
** EPITECH PROJECT, 2023
** lib
** File description:
** my_splitstr.c
*/

#include "includes/lib.h"

int find_split(char *str, char *split, int i, int len_str)
{
    int len_split = my_strlen(split);

    if (len_str - (len_split + i) < 0)
        return 0;
    for (int j = 0; j < len_split; j++) {
        if (str[i] != split[j])
            return 0;
        i++;
    }
    return 1;
}

void split_string(char *str, int i, int len_str, char **dest)
{
    int j = 0;

    *dest = malloc(sizeof(char) * (len_str - i + 1));
    while (str[i]) {
        (*dest)[j] = str[i];
        i++;
        j++;
    }
    (*dest)[j] = '\0';
}

int check_splitstr(char *str, int i, char *split, char **dest)
{
    int len_str = my_strlen(str);

    if (str[i] == split[0]) {
        if (find_split(str, split, i, len_str)) {
            split_string(str, i, len_str, dest);
            return 1;
        }
    }
    return 0;
}

char *my_splitstr(char *str, char *split)
{
    int len = 0;
    int i = 0;
    int len_str = my_strlen(str);
    char *dest;

    for (; str[i]; i++) {
        if (check_splitstr(str, i, split, &dest))
            break;
    }
    return dest;
}
