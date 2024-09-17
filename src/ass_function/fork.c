/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** fork.c
*/

#include "../../includes/my.h"

int fork_function(st_t *st, robot_t *robot)
{
    my_putstr("                         --------------------------------\n");
    my_putstr("                                       fork\n");
    my_putstr("                         --------------------------------\n");
    robot->pc += 3;
    robot->cursor += 3;
    robot->wait += 800;
    return 0;
}