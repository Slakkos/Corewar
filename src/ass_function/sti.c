/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** sti.c
*/

#include "../../includes/my.h"

void print_int_array(int *arr, int size)
{
    my_putstr("[");
    for (int i = 0; i < size; i++) {
        my_putnbr(arr[i]);
        if (i + 1 < size) {
            my_putstr(", ");
        }
    }
    my_putstr("]\n");
}

int check_sti_format(char **params)
{
    int count = 0;

    for (int i = 0; params[i] != NULL; i++) {
        count++;
    }
    if (count != 3)
        return 84;
    if (my_strcmp(params[0], "registre") == 0)
        return 84;
    for (int i = 1; i < 3; i++) {
        if (my_strcmp(params[i], "registre") == 0 &&
            my_strcmp(params[i], "direct") == 0 &&
            my_strcmp(params[i], "indirect") == 0) {
            return 84;
        }
    }
    return 0;
}

static int handle_registre_case(int *args_sti, char **bytescode_arr,
    robot_t *robot, int *cursor_int, int size)
{
    if (my_strcmp(bytescode_arr[size], "registre") == 0) {
        return 0;
    }
    if (robot->instructions_int[*cursor_int] < 1 ||
        robot->instructions_int[*cursor_int] > 16) {
        return 84;
    }
    args_sti[size] = robot->instructions_int[*cursor_int];
    (*cursor_int)++;
    robot->pc += 1;
    robot->cursor += 1;
    return 0;
}

static int handle_direct_indirect_case(int *args_sti, char **bytescode_arr,
    robot_t *robot, int *cursor_int, int size)
{
    if (my_strcmp(bytescode_arr[size], "direct") == 0 &&
        my_strcmp(bytescode_arr[size], "indirect") == 0) {
        return 0;
    }
    args_sti[size] = robot->instructions_int[*cursor_int] +
        robot->instructions_int[*cursor_int + 1];
    (*cursor_int) += 2;
    robot->pc += 2;
    robot->cursor += 2;
    return 0;
}

static int fill_args_sti(int *args_sti, char **bytescode_arr,
    robot_t *robot, int *cursor_int)
{
    for (int size = 0; size < 3; size++) {
        if (handle_registre_case(args_sti, bytescode_arr,
            robot, cursor_int, size) == 84) {
            return 84;
        }
        if (handle_direct_indirect_case(args_sti, bytescode_arr,
            robot, cursor_int, size) == 84) {
            return 84;
        }
    }
    return 0;
}

static void print_debug_info(char *bytescode, char **bytescode_arr, int *args_sti)
{
    my_putstr("                         --------------------------------\n");
    my_putstr("                                       sti\n");
    my_putstr("                         --------------------------------\n");
    my_putstr("                               bytescode");
    my_putstr(bytescode);
    my_putstr("\n                         --------------------------------\n");
    my_putstr("                                 bytescode array\n");
    my_putstr("                           ");
    print_array(bytescode_arr);
    my_putstr("                         --------------------------------\n");
    my_putstr("                                  arguments_sti\n");
    my_putstr("                                     ");
    print_int_array(args_sti, 2);
    my_putstr("                         --------------------------------\n");
}

int sti_function(st_t *st, robot_t *robot)
{
    int cursor_int = robot->cursor + 2;
    char *bytescode = int_to_binary(robot->instructions_int[robot->cursor + 1]);
    char **bytescode_arr = split_binary_string(bytescode);
    int *args_sti = malloc(sizeof(int) * 3);
    bytescode_arr = rename_content_bytescode(bytescode_arr);
    if (check_sti_format(bytescode_arr) != 0) {
        free(args_sti);
        return 84;
    }
    if (fill_args_sti(args_sti, bytescode_arr, robot, &cursor_int) == 84) {
        free(args_sti);
        return 84;
    }
    print_debug_info(bytescode, bytescode_arr, args_sti);
    robot->pc += 2;
    attack_bytecode(st, args_sti[0], (robot->pc + (args_sti[1] + args_sti[2]) % 512));
    robot->cursor += 2;
    robot->wait += 25;
    free(args_sti);
    return 0;
}

