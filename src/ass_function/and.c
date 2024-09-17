/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** and.c
*/

#include "../../includes/my.h"

int check_and_format(char **params) {
    int count = 0;

    for (int i = 0; params[i] != NULL; i++) {
        count++;
    }
    if (count != 3) {
        return 84;
    }
    for (int i = 0; i < 2; i++) {
        if (my_strcmp(params[i], "registre") != 0 &&
            my_strcmp(params[i], "direct") != 0 &&
            my_strcmp(params[i], "indirect") != 0) {
            return 84;
        }
    }
    if (my_strcmp(params[2], "registre") != 0)
        return 84;
    return 0;
}

static int handle_registre_case(int *args_and, char **bytescode_arr,
    robot_t *robot, int *cursor_int, int size)
{
    if (my_strcmp(bytescode_arr[size], "registre") == 0) {
        return 0;
    }
    if (robot->instructions_int[*cursor_int] < 1 ||
        robot->instructions_int[*cursor_int] > 16) {
        return 84;
    }
    args_and[size] = robot->instructions_int[*cursor_int];
    (*cursor_int)++;
    robot->pc += 1;
    robot->cursor += 1;
    return 0;
}

static int handle_direct_indirect_case(int *args_and, char **bytescode_arr,
    robot_t *robot, int *cursor_int, int size)
{
    if (!my_strcmp(bytescode_arr[size], "direct") == 0) {
        args_and[size] = robot->instructions_int[*cursor_int] +
            robot->instructions_int[*cursor_int + 1] +
            robot->instructions_int[*cursor_int + 2] +
            robot->instructions_int[*cursor_int + 3];
        (*cursor_int) += 4;
        robot->pc += 4;}
        robot->cursor += 4;
    if (!my_strcmp(bytescode_arr[size], "indirect") == 0) {
        args_and[size] = robot->instructions_int[*cursor_int] +
            robot->instructions_int[*cursor_int + 1];
        (*cursor_int) += 2;
        robot->pc += 2;
        robot->cursor += 2;
    }
    return 0;
}

static int fill_args_and(int *args_and, char **bytescode_arr,
    robot_t *robot, int *cursor_int)
{
    for (int size = 0; size < 3; size++) {
        if (handle_registre_case(args_and, bytescode_arr,
            robot, cursor_int, size) == 84) {
            return 84;
        }
        if (handle_direct_indirect_case(args_and, bytescode_arr,
            robot, cursor_int, size) == 84) {
            return 84;
        }
    }
    return 0;
}

static void print_debug_info(char *bytescode, char **bytescode_arr, int *args_and)
{
    my_putstr("                         --------------------------------\n");
    my_putstr("                                       and\n");
    my_putstr("                         --------------------------------\n");
    my_putstr("                               bytescode");
    my_putstr(bytescode);
    my_putstr("\n                         --------------------------------\n");
    my_putstr("                                 bytescode array\n");
    my_putstr("                           ");
    print_array(bytescode_arr);
    my_putstr("                         --------------------------------\n");
    my_putstr("                                  arguments_and\n");
    my_putstr("                                     ");
    print_int_array(args_and, 3);
    my_putstr("                         --------------------------------\n");
}

static int choose_and_param(char **bytescode_arr, robot_t* robot, int *args_and)
{
    if (!my_strcmp(bytescode_arr[0], "direct") == 0 ||
        !my_strcmp(bytescode_arr[0], "indirect") == 0) {
        args_and[0] = args_and[0];
    } else {
        args_and[0] = robot->registres[args_and[0]];
    }
    if (!my_strcmp(bytescode_arr[1], "direct") == 0 ||
        !my_strcmp(bytescode_arr[1], "indirect") == 0) {
        args_and[1] = args_and[1];
    } else {
        args_and[1] = robot->registres[args_and[1]];
    }
    return 0;
}

int and_function(st_t *st, robot_t *robot)
{
    int cursor_int = robot->cursor + 2;
    char *bytescode = int_to_binary(robot->instructions_int[robot->cursor + 1]);
    char **bytescode_arr = split_binary_string(bytescode);
    int *args_and = malloc(sizeof(int) * 3);

    bytescode_arr = rename_content_bytescode(bytescode_arr);
    if (check_and_format(bytescode_arr) != 0) {
        free(args_and);
        return 84;
    }
    if (fill_args_and(args_and, bytescode_arr, robot, &cursor_int) == 84) {
        free(args_and);
        return 84;
    }
    print_debug_info(bytescode, bytescode_arr, args_and);
    choose_and_param(bytescode_arr, robot, args_and);
    robot->registres[args_and[2]] = args_and[0] & args_and[1];
    robot->pc += 2;
    robot->cursor += 2;
    robot->wait += 6;
    free(args_and);
    return 0;
}
