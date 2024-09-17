/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** ld.c
*/

#include "../../includes/my.h"

int check_ld_format(char **params)
{
    int count = 0;

    for (int i = 0; params[i] != NULL; i++) {
        count++;
    }
    if (count != 2)
        return 84;
    if (my_strcmp(params[1], "registre") == 0)
        return 84;
    if (!(my_strcmp(params[0], "registre") == 0 ||
          my_strcmp(params[0], "direct") == 0 ||
          my_strcmp(params[0], "indirect") == 0)) {
        return 84;
    }
    return 0;
}

static int handle_registre_case(int *args_ld, char **bytescode_arr,
    robot_t *robot, int *cursor_int, int size)
{
    if (my_strcmp(bytescode_arr[size], "registre") == 0) {
        return 0;
    }
    if (robot->instructions_int[*cursor_int] < 1 ||
        robot->instructions_int[*cursor_int] > 16) {
        return 84;
    }
    args_ld[size] = robot->instructions_int[*cursor_int];
    (*cursor_int)++;
    robot->pc += 1;
    robot->cursor += 1;
    return 0;
}

static int handle_direct_indirect_case(int *args_ld, char **bytescode_arr,
    robot_t *robot, int *cursor_int, int size)
{
    if (!my_strcmp(bytescode_arr[size], "direct") == 0) {
        args_ld[size] = robot->instructions_int[*cursor_int] +
            robot->instructions_int[*cursor_int + 1] +
            robot->instructions_int[*cursor_int + 2] +
            robot->instructions_int[*cursor_int + 3];
        (*cursor_int) += 4;
        robot->pc += 4;
        robot->cursor += 4;
    }
    if (!my_strcmp(bytescode_arr[size], "indirect") == 0) {
        args_ld[size] = robot->instructions_int[*cursor_int] +
            robot->instructions_int[*cursor_int + 1];
        (*cursor_int) += 2;
        robot->pc += 2;
        robot->cursor += 2;
    }
    return 0;
}

static int fill_args_ld(int *args_ld, char **bytescode_arr,
    robot_t *robot, int *cursor_int)
{
    for (int size = 0; size < 2; size++) {
        if (handle_registre_case(args_ld, bytescode_arr,
            robot, cursor_int, size) == 84) {
            return 84;
        }
        if (handle_direct_indirect_case(args_ld, bytescode_arr,
            robot, cursor_int, size) == 84) {
            return 84;
        }
    }
    return 0;
}

static void print_debug_info(char *bytescode, char **bytescode_arr, int *args_ld)
{
    my_putstr("                         --------------------------------\n");
    my_putstr("                                       ld\n");
    my_putstr("                         --------------------------------\n");
    my_putstr("                               bytescode");
    my_putstr(bytescode);
    my_putstr("\n                         --------------------------------\n");
    my_putstr("                                 bytescode array\n");
    my_putstr("                           ");
    print_array(bytescode_arr);
    my_putstr("                         --------------------------------\n");
    my_putstr("                                   arguments_ld\n");
    my_putstr("                                     ");
    print_int_array(args_ld, 2);
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
    return 0;
}

int ld_function(st_t *st, robot_t *robot)
{
    int cursor_int = robot->cursor + 2;
    char *bytescode = int_to_binary(robot->instructions_int[robot->cursor + 1]);
    char **bytescode_arr = split_binary_string(bytescode);
    int *args_ld = malloc(sizeof(int) * 2);

    bytescode_arr = rename_content_bytescode(bytescode_arr);
    if (check_ld_format(bytescode_arr) != 0) {
        free(args_ld);
        return 84;
    }
    if (fill_args_ld(args_ld, bytescode_arr, robot, &cursor_int) == 84) {
        free(args_ld);
        return 84;
    }
    print_debug_info(bytescode, bytescode_arr, args_ld);
    choose_and_param(bytescode_arr, robot, args_ld);
    robot->pc += 2;
    robot->registres[args_ld[1]] = (st->instr[(robot->pc + args_ld[0] % 512)].code);
    robot->cursor += 2;
    robot->wait += 5;
    free(args_ld);
    return 0;
}