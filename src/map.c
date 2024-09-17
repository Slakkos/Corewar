/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** map.c
*/

#include "../includes/my.h"
#include "../E_op/op.h"

void print_map(st_t *st)
{
    for (int i = 0; i < MEM_SIZE; i++) {
        my_putstr_02x(st->instr[i].code);
        if (i < MEM_SIZE - 1)
            my_putchar(' ');
        if ((i + 1) % 32 == 0)
            my_putchar('\n');
    }
}

void place_robot(st_t *st)
{
    int robot = 0;
    int i = 0;
    int map = 0;
    int dist = MEM_SIZE / st->count_player;

    while (robot < st->count_player) {
        st->robot[robot].init_load_adress = map;
        while (i < st->robot[robot].instruction_nbr) {
            st->instr[map].code = st->robot[robot].instructions[i];
            i++;
            map++;
        }
        map += dist - st->robot[robot].instruction_nbr;
        i = 0;
        st->robot[robot].registres = malloc(sizeof(int) * 16);
        robot++;
    }
}

void print_array(char **arr)
{
    if (arr == NULL || *arr == NULL) {
        my_putstr("String array is empty.\n");
        return;
    }
    my_putstr("[");
    for (int i = 0; arr[i] != NULL; i++) {
        my_putstr(arr[i]);
        if (arr[i + 1] != NULL) {
            my_putstr(", ");
        }
    }
    my_putstr("]\n");
}

int change_map(st_t *st, int *robot, int local_adress)
{
    if (!st->robot[*robot].args.a) {
        (*robot)++;
        return EXIT_SUCCESS;
    }
    local_adress = st->robot[*robot].load_address;
    for (int i = 0; i < st->robot[*robot].instruction_nbr; i++) {
        if (st->instr[local_adress].code != 0)
            return EXIT_FAILURE;
        st->instr[local_adress].code = st->robot[*robot].instructions[i];
        local_adress++;
    }
    local_adress = st->robot[*robot].init_load_adress;
    for (int i = 0; i < st->robot[*robot].instruction_nbr; i++) {
        st->instr[local_adress].code = 0;
        local_adress++;
    }
    (*robot)++;
    return EXIT_SUCCESS;
}

int place_robot_at_load_adresse(st_t *st)
{
    int robot = 0;
    int local_adress = 0;

    while (robot < st->count_player) {
        if (change_map(st, &robot, local_adress) == EXIT_FAILURE)
            return EXIT_FAILURE;
    }
    process_all_robots(st);
    // print_robot_hexdumps(st);
    // fill_robot_instructions(st, 3);
    convert_all_robot_instructions(st);
    my_putstr("//////////////////////////////////////////////////////////////////////////////////////////\n");
    print_robot_instructions(st);
    my_putstr("//////////////////////////////////////////////////////////////////////////////////////////\n");
    process_all_cycle(st);
    return EXIT_SUCCESS;
}

int create_map(st_t *st)
{
    st->instr = malloc(sizeof(instr_t) * MEM_SIZE + 1);
    if (st->instr == NULL)
        return EXIT_FAILURE;
    for (int i = 0; i < MEM_SIZE + 1; i++) {
        st->instr[i].code = 0;
    }
    place_robot(st);
    if (place_robot_at_load_adresse(st) == EXIT_FAILURE)
        return EXIT_FAILURE;
    my_putstr("///////////////////////////////////////////////////////////////////////////////////////////////\n");
    my_putstr("                                            MAP\n");
    my_putstr("///////////////////////////////////////////////////////////////////////////////////////////////\n\n");
    print_map(st);
    return EXIT_SUCCESS;
}
