/*
** EPITECH PROJECT, 2023
** lib
** File description:
** main.c
*/

#include <stdio.h>
#include "includes/my.h"
#include <stdlib.h>

void desc_corewar(void)
{
    my_putstr("./corewar [-dump nbr_cycle] [[-n prog_number]");
    my_putstr("[-a load_address] prog_name] ...\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("-dump nbr_cycle dumps the memory after the ");
    my_putstr("nbr_cycle execution (if the round isn’t\nalready ");
    my_putstr("over) with the following format: 32 bytes/line in ");
    my_putstr("hexadecimal (A0BCDEF1DD3...)\n");
    my_putstr("-n prog_number sets the next program’s number. ");
    my_putstr("By default, the first free number in the\n");
    my_putstr("parameter order\n");
    my_putstr("-a load_address sets the next program’s loading ");
    my_putstr("address. When no address is specified,\noptimize ");
    my_putstr("the addresses so that the processes are as far ");
    my_putstr("away from each other as\npossible. The addresses ");
    my_putstr("are MEM_SIZE modulo.\n");
}

void init_struct(int ac, char **av, st_t *st)
{
    st->ac = ac;
    st->av = av;
    st->exit_status = 0;
    st->config.dump_cycle = -1;
    st->config.load_address = 0;
    st->config.prog_number = -1;
    st->config.prog_names = NULL;
    st->config.num_programs = 0;
    st->config.free_prog_number = NULL;
    st->end = 1;
}

int main(int ac, char **av)
{
    st_t st;
    if (ac == 2 && my_strcmp(av[1], "-h")) {
        desc_corewar();
        return 0;
    }
    init_struct(ac, av, &st);
    if (parsing_args(&st)) {
        return 84;
    }
    if (st.config.prog_names == NULL) {
        return 84;
    }
    if (parsing_robot(&st) == EXIT_FAILURE) {
        return 84;
    }
    if (create_map(&st) == EXIT_FAILURE) {
        return 84;
    }
    return st.exit_status;
}
