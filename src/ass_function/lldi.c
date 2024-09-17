/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** llldi.c
*/

#include "../../includes/my.h"

int check_lldi_format(char **params)
{
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

static int handle_registre_case(int *args_lldi, char **bytescode_arr,
    robot_t *robot, int *cursor_int, int size)
{
    if (my_strcmp(bytescode_arr[size], "registre") == 0) {
        return 0;
    }
    if (robot->instructions_int[*cursor_int] < 1 ||
        robot->instructions_int[*cursor_int] > 16) {
        return 84;
    }
    args_lldi[size] = robot->instructions_int[*cursor_int];
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

static int fill_args_lldi(int *args_lldi, char **bytescode_arr,
    robot_t *robot, int *cursor_int)
{
    for (int size = 0; size < 3; size++) {
        if (handle_registre_case(args_lldi, bytescode_arr,
            robot, cursor_int, size) == 84) {
            return 84;
        }
        if (handle_direct_indirect_case(args_lldi, bytescode_arr,
            robot, cursor_int, size) == 84) {
            return 84;
        }
    }
    return 0;
}

static void print_debug_info(char *bytescode, char **bytescode_arr, int *args_lldi)
{
    my_putstr("                         --------------------------------\n");
    my_putstr("                                       lldi\n");
    my_putstr("                         --------------------------------\n");
    my_putstr("                               bytescode");
    my_putstr(bytescode);
    my_putstr("\n                         --------------------------------\n");
    my_putstr("                                 bytescode array\n");
    my_putstr("                           ");
    print_array(bytescode_arr);
    my_putstr("                         --------------------------------\n");
    my_putstr("                                  arguments_lldi\n");
    print_int_array(args_lldi, 2);
    my_putstr("                         --------------------------------\n");
}

static int lldi_algo(st_t *st, char **bytescode_arr, robot_t* robot, int *args_lldi)
{
    int sum = (args_lldi[0] + args_lldi[1]);
    int value_address = (robot->pc + sum) % MEM_SIZE;
    int value = st->instr[value_address].code;

    robot->registres[args_lldi[2]] = value;
    robot->carry = (value == 0) ? 1 : 0;
    robot->pc += 2;
    robot->cursor += 2;
    return 0;
}

int lldi_function(st_t *st, robot_t *robot)
{
    int cursor_int = robot->cursor + 2;
    char *bytescode = int_to_binary(robot->instructions_int[robot->cursor + 1]);
    char **bytescode_arr = split_binary_string(bytescode);
    int *args_lldi = malloc(sizeof(int) * 3);

    bytescode_arr = rename_content_bytescode(bytescode_arr);
    if (check_lldi_format(bytescode_arr) != 0) {
        free(args_lldi);
        return 84;
    }
    if (fill_args_lldi(args_lldi, bytescode_arr, robot, &cursor_int) == 84) {
        free(args_lldi);
        return 84;
    }
    print_debug_info(bytescode, bytescode_arr, args_lldi);
    lldi_algo(st, bytescode_arr, robot, args_lldi);
    robot->wait += 50;
    free(args_lldi);
    return 0;
}
