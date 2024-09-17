/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** live.c
*/

#include "../../includes/my.h"

int live_function(st_t *st, robot_t *robot)
{
    st->number_live++;
    robot->live = 1;
    my_putstr("                         --------------------------------\n");
    my_putstr("                                       live\n");
    my_putstr("                         --------------------------------\n");
    robot->pc = robot->pc + 5;
    robot->cursor = robot->cursor + 5;
    robot->wait += 10;
    return 0;
}