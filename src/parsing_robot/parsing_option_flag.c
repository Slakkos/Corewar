/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-jules.lordet
** File description:
** parsing_option_flag.c
*/

#include "../../includes/my.h"

static int handle_dump_option(st_t *st, int *i)
{
    if (my_strcmp(st->av[*i], "-dump")) {
        if (handle_dump_cycle(st, i) == 84)
            return 84;
        return 1;
    }
    return 0;
}

static int handle_n_option(st_t *st, int *i, int *i_prog)
{
    if (my_strcmp(st->av[*i], "-n")) {
        if (handle_prog_number(st, i, i_prog) == 84)
            return 84;
        return 1;
    }
    return 0;
}

static int handle_a_option(st_t *st, int *i, int *i_prog)
{
    if (my_strcmp(st->av[*i], "-a")) {
        st->robot[*i_prog].args.a = false;
        if (handle_load_address(st, i, i_prog) == 84)
            return 84;
        return 1;
    }
    return 0;
}

static int handle_default(st_t *st, int *i, int *i_prog)
{
    if (handle_prog_name(st, i, i_prog) == 84)
        return 84;
    return 1;
}

int handle_options(st_t *st, int *i, int *i_prog, int ret)
{
    ret = handle_dump_option(st, i);
    if (ret == 1)
        return 0;
    ret = handle_n_option(st, i, i_prog);
    if (ret == 84)
        return 84;
    if (ret == 1)
        return 0;
    ret = handle_a_option(st, i, i_prog);
    if (ret == 84)
        return 84;
    if (ret == 1)
        return 0;
    ret = handle_prog_name(st, i, i_prog);
    if (ret == 1) {
        (*i_prog)++;
        return 0;
    }
    return 0;
}

int parse_flag_robot(st_t *st)
{
    int i_prog = 0;
    int ret = 0;

    for (int i = 1; i < st->ac; i++) {
        if (handle_options(st, &i, &i_prog, ret) == 84)
            return 84;
    }
    return 0;
}
