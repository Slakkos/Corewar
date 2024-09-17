/*
** EPITECH PROJECT, 2023
** amazed
** File description:
** my_strcontains.c
*/

#include "includes/lib.h"

int find_contains(char *str, char *contains, int i)
{
    int len = my_strlen(contains);

    for (int j = 0; j < len; j++) {
        if (str[i] != contains[j])
            return FALSE;
        i++;
    }
    return TRUE;
}

int my_strcontains(char *str, char *contains)
{
    if (contains == NULL || str == NULL)
        return FALSE;
    if (contains[0] == '\0')
        return FALSE;
    for (int i = 0; str[i]; i++) {
        if (str[i] == contains[0]) {
            return find_contains(str, contains, i);
        }
    }
    return FALSE;
}
