/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** lfork.c
*/

#include "../../includes/my.h"

int lfork_function(st_t *st, robot_t *robot)
{
    my_putstr("                         --------------------------------\n");
    my_putstr("                                       lfork\n");
    my_putstr("                         --------------------------------\n");
    robot->pc += 3;
    robot->cursor += 3;
    robot->wait += 1000;
    return 0;
}