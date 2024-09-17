/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** aff.c
*/

#include "../../includes/my.h"

int check_aff_format(char **params)
{
    int count = 0;

    for (int i = 0; params[i] != NULL; i++) {
        count++;
    }
    if (count != 1)
        return 84;
    if (my_strcmp(params[0], "registre") == 0)
        return 84;
    return 0;
}

static int handle_registre_case(int *args_aff, char **bytescode_arr,
    robot_t *robot, int *cursor_int, int size)
{
    if (my_strcmp(bytescode_arr[size], "registre") == 0) {
        return 0;
    }
    if (robot->instructions_int[*cursor_int] < 1 ||
        robot->instructions_int[*cursor_int] > 16) {
        return 84;
    }
    args_aff[size] = robot->instructions_int[*cursor_int];
    (*cursor_int)++;
    robot->pc += 1;
    robot->cursor += 1;
    return 0;
}

static int fill_args_aff(int *args_aff, char **bytescode_arr,
    robot_t *robot, int *cursor_int)
{
    for (int size = 0; size < 1; size++) {
        if (handle_registre_case(args_aff, bytescode_arr,
            robot, cursor_int, size) == 84) {
            return 84;
        }
    }
    return 0;
}

static void print_debug_info(char *bytescode, char **bytescode_arr, int *args_aff)
{
    my_putstr("                         --------------------------------\n");
    my_putstr("                                       aff\n");
    my_putstr("                         --------------------------------\n");
    my_putstr("                               bytescode");
    my_putstr(bytescode);
    my_putstr("\n                         --------------------------------\n");
    my_putstr("                                 bytescode array\n");
    my_putstr("                           ");
    print_array(bytescode_arr);
    my_putstr("                         --------------------------------\n");
    my_putstr("                                  arguments_aff\n");
    my_putstr("                                       ");
    print_int_array(args_aff, 1);
    my_putstr("                         --------------------------------\n");
}

int aff_function(st_t *st, robot_t *robot)
{
    int cursor_int = robot->cursor + 2;
    char *bytescode = int_to_binary(robot->instructions_int[robot->cursor + 1]);
    char **bytescode_arr = split_binary_string(bytescode);
    int *args_aff = malloc(sizeof(int) * 1);
    char character;
    bytescode_arr = rename_content_bytescode(bytescode_arr);

    if (check_aff_format(bytescode_arr) != 0) {
        free(args_aff);
        return 84;
    }
    if (fill_args_aff(args_aff, bytescode_arr, robot, &cursor_int) == 84) {
        free(args_aff);
        return 84;
    }
    print_debug_info(bytescode, bytescode_arr, args_aff);
    character = (char)(robot->registres[args_aff[0]] % 256);
    my_putstr("                               ----->");
    my_putchar(character);
    my_putstr("<-----\n");
    robot->pc += 2;
    robot->cursor += 2;
    robot->wait += 2;
    free(args_aff);
    return 0;
}