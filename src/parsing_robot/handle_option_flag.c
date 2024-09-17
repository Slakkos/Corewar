/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-jules.lordet
** File description:
** handle_option_flag.c
*/

#include "../../includes/my.h"

int handle_dump_cycle(st_t *st, int *i)
{
    if (*i + 1 >= st->ac)
        return 84;
    st->config.dump_cycle = my_getnbr(st->av[*i + 1]);
    (*i)++;
    return 0;
}

int handle_prog_number(st_t *st, int *i, int *i_prog)
{
    if (*i + 1 >= st->ac)
        return 84;
    if (my_isnumber(st->av[*i + 1])) {
        st->robot[*i_prog].prog_number = my_getnbr(st->av[*i + 1]);
        (*i)++;
        return 0;
    }
    return 84;
}

int handle_load_address(st_t *st, int *i, int *i_prog)
{
    if (*i + 1 >= st->ac)
        return 84;
    if (my_isnumber(st->av[*i + 1])) {
        st->robot[*i_prog].load_address = my_getnbr(st->av[*i + 1]);
        st->robot[*i_prog].args.a = true;
        (*i)++;
        return 0;
    }
    return 84;
}

int handle_prog_name(st_t *st, int *i, int *i_prog)
{
    if (*i >= st->ac)
        return 84;
    (*i_prog)++;
    return 0;
}
