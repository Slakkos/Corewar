/*
** EPITECH PROJECT, 2023
** EPITECH
** File description:
** my.h
*/

#ifndef LIB_H_
    #define LIB_H_
    #include <stdint.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <string.h>
    #include <syscall.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #define TRUE 1
    #define FALSE 0

void my_clean_str(char **str, char *symbols, int nb);
char *my_strdup(char *src);
char *my_strcat(char *s1, char *s2);
int my_strlen(char *str);
int my_strncmp(char *s1, char *s2, int nb);
int my_strcmp(char *s1, char *s2);
void my_putstr(char *str);
void my_putnbr(int n);
void my_putchar(char c);
char *my_strcpy(char *dest, char *src);
int my_swap_16bytes(int value);
int my_swap_32bytes(int value);
int my_tablen(char **tab);
void my_freetab(char **tab);
char **my_str_to_word_array(char *str, char *except);
char *my_splitstr(char *str, char *split);
int my_findinstr(char *str, char *find);
char **my_tabdup(char **tab);
int my_isnumber(char *str);
int my_isalpha(char *str);
int my_isuppercase(char *str);
int my_islowercase(char *str);
int my_strcontains(char *str, char *contains);
int my_charcontains(char *str, char c);
void my_puttab(char **tab);
int my_getnbr(char const *str);
void my_replace_char(char **str, char c, char r);
void my_putstr_02x(char value);
long my_strtol(const char *__restrict__ nptr,
    char **__restrict__ endptr, int base);

#endif
