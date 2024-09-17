/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** parsing.c
*/

#include "../includes/my.h"

static int parse_dump_cycle(st_t *st, int i)
{
    if (i + 1 >= st->ac)
        return EXIT_FAILURE;
    st->config.dump_cycle = my_getnbr(st->av[i + 1]);
    return EXIT_SUCCESS;
}

static int parse_prog_number(st_t *st, int i)
{
    if (i + 1 >= st->ac)
        return EXIT_FAILURE;
    if (my_isnumber(st->av[i + 1]))
        st->config.prog_number = my_getnbr(st->av[i + 1]);
    return EXIT_SUCCESS;
}

static int parse_load_address(st_t *st, int i)
{
    if (i + 1 >= st->ac)
        return EXIT_FAILURE;
    st->config.load_address = my_getnbr(st->av[i + 1]);
    return EXIT_SUCCESS;
}

static int parse_prog_names(st_t *st, int i, int i_prog)
{
    st->config.prog_names = realloc(st->config.prog_names,
    (i_prog + 2) * sizeof(char *));
    if (st->config.prog_names == NULL)
        return EXIT_FAILURE;
    st->config.prog_names[i_prog] = my_strdup(st->av[i]);
    st->config.prog_names[i_prog + 1] = NULL;
    return EXIT_SUCCESS;
}

static void count_files_args(st_t *st)
{
    for (int i = 1; i < st->ac; i++) {
        if (my_strcmp(st->av[i], "-dump"))
            continue;
        if (my_strcmp(st->av[i], "-n"))
            continue;
        if (my_strcmp(st->av[i], "-a"))
            continue;
        if (my_strcmp(st->av[i], "-prog_name"))
            continue;
        if (my_isnumber(st->av[i]) == 0)
            st->config.num_programs++;
    }
    st->config.prog_names = malloc(sizeof(char *) *
    (st->config.num_programs + 1));
    st->config.prog_names[st->config.num_programs] = 0;
}

int check_prog_name(st_t *st, int i, int *i_prog)
{
    if (my_isnumber(st->av[i]) == 0) {
        if (parse_prog_names(st, i, *i_prog) == EXIT_FAILURE)
            return EXIT_FAILURE;
        (*i_prog)++;
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}

int parse_specific_args(st_t *st, int i, int *i_prog)
{
    if (my_strcmp(st->av[i], "-dump")) {
        if (parse_dump_cycle(st, i) == EXIT_FAILURE)
            return EXIT_FAILURE;
        return EXIT_SUCCESS;
    }
    if (my_strcmp(st->av[i], "-n")) {
        if (parse_prog_number(st, i) == EXIT_FAILURE)
            return EXIT_FAILURE;
        return EXIT_SUCCESS;
    }
    if (my_strcmp(st->av[i], "-a")) {
        if (parse_load_address(st, i) == EXIT_FAILURE)
            return EXIT_FAILURE;
        return EXIT_SUCCESS;
    }
    if (check_prog_name(st, i, i_prog) == EXIT_SUCCESS)
        return EXIT_SUCCESS;
    return EXIT_FAILURE;
}

int parse_args(st_t *st)
{
    int i_prog = 0;

    for (int i = 1; i < st->ac; i++) {
        if (parse_specific_args(st, i, &i_prog) == EXIT_FAILURE) {
            st->config.free_prog_number = my_strdup(st->av[i]);
        }
    }
    return EXIT_SUCCESS;
}

int parsing_args(st_t *st)
{
    if (st->ac < 2)
        return EXIT_FAILURE;
    if (parse_args(st) == EXIT_FAILURE) {
        free(st->config.prog_names);
        st->exit_status = 84;
        return EXIT_FAILURE;
    }
    if (st->config.prog_number == -1) {
        st->config.prog_number = my_getnbr(st->config.free_prog_number);
        free(st->config.free_prog_number);
    }
    return EXIT_SUCCESS;
}
