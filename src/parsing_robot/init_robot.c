/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-jules.lordet
** File description:
** init_robot.c
*/

#include "../../includes/my.h"

robot_t *realloc_robot(st_t *st, int i)
{
    robot_t *new_robot = realloc(st->robot, (i + 2) * sizeof(robot_t));

    if (new_robot == NULL) {
        return NULL;
    }
    for (int j = i; j < i + 2; j++) {
        init_robot_properties(&new_robot[j]);
    }
    st->robot = new_robot;
    return st->robot;
}

int init_registres(robot_t *robot)
{
    robot->registres = malloc(16 * sizeof(int));
    return robot->registres == NULL ? EXIT_FAILURE : EXIT_SUCCESS;
}

void init_robot_properties(robot_t *robot)
{
    robot->name = NULL;
    robot->desc = NULL;
    robot->instructions = NULL;
    robot->instruction_hexa = NULL;
    robot->magic_nbr = NULL;
    robot->instr_bin = NULL;
    robot->mnemonics = NULL;
    robot->mnemonics_bytes = NULL;
    robot->instructions_int = malloc(sizeof(int));
    robot->cursor = 0;
    robot->live = 0;
    robot->dead = 0;
    robot->pc = 0;
    robot->wait = 0;
    robot->stock = 0;
    robot->load_address = 0;
    robot->prog_number = 0;
    robot->address = 0;
    robot->carry = 0;
}

int init_single_robot(st_t *st, int i)
{
    init_robot_properties(&st->robot[i]);
    if (init_registres(&st->robot[i]) == EXIT_FAILURE) {
        return EXIT_FAILURE;
    }
    st->robot[i].mnemonics = malloc(16 * sizeof(char *));
    st->robot[i].mnemonics_bytes = malloc(16 * sizeof(int *));
    if (st->robot[i].mnemonics == NULL ||
    st->robot[i].mnemonics_bytes == NULL) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int init_robot(st_t *st, int i)
{
    if (realloc_robot(st, i) == NULL) {
        return EXIT_FAILURE;
    }
    if (init_single_robot(st, i) == EXIT_FAILURE) {
        return EXIT_FAILURE;
    }
    if (init_single_robot(st, i + 1) == EXIT_FAILURE) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
