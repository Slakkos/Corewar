/*
** EPITECH PROJECT, 2023
** robotfactory
** File description:
** my_str_to_word_array.c
*/

#include "includes/lib.h"

char charactere(char a, char *except)
{
    for (int i = 0; except[i]; i++) {
        if (a != except[i])
            return 1;
    }
    return 0;
}

void remplissage(char *str, int len_mot, char **tab, int current_word)
{
    int i = 0;

    while (i < len_mot) {
        tab[current_word][i] = str[i];
        i++;
    }
    tab[current_word][i] = '\0';
}

void len_word(char *str, int mot, char **tab, char *except)
{
    int len_mot = 0;
    int i = 0;
    int current_word = 0;

    while (str[i] != '\0') {
        len_mot = 0;
        for (; str[i] != '\0' && charactere(str[i], except) == 0; i++);
        for (; str[i] != '\0' && charactere(str[i], except) == 1; i++) {
            len_mot++;
        }
        if (len_mot == 0)
            break;
        tab[current_word] = malloc(sizeof(char) * (len_mot + 1));
        if (len_mot == 0)
            break;
        remplissage(str + i - len_mot, len_mot, tab, current_word);
        current_word++;
    }
}

char **my_str_to_word_array(char *str, char *except)
{
    char **tab;
    int mot = 0;
    int i = 0;
    int j = 0;

    while (str[i] != '\0') {
        for (; str[i] != '\0' && charactere(str[i], except) == 0; i++);
        if (charactere(str[i], except) == 1)
            mot++;
        for (; str[i] != '\0' && charactere(str[i], except) == 1; i++);
    }
    tab = malloc(sizeof(char *) * (mot +1));
    tab[mot] = 0;
    len_word(str, mot, tab, except);
    return tab;
}
