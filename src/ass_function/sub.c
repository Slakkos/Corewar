/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** sub.c
*/

#include "../../includes/my.h"

int check_sub_format(char **params)
{
    int count = 0;

    for (int i = 0; params[i] != NULL; i++) {
        count++;
    }
    if (count != 3)
        return 84;
    for (int i = 0; i < 3; i++) {
        if (my_strcmp(params[i], "registre") == 0) {
            return 84;
        }
    }
    return 0;
}

static int handle_registre_case(int *args_sub, char **bytescode_arr,
    robot_t *robot, int *cursor_int, int size)
{
    if (my_strcmp(bytescode_arr[size], "registre") == 0) {
        return 0;
    }
    if (robot->instructions_int[*cursor_int] < 1 ||
        robot->instructions_int[*cursor_int] > 16) {
        return 84;
    }
    args_sub[size] = robot->instructions_int[*cursor_int];
    (*cursor_int)++;
    robot->pc += 1;
    robot->cursor += 1;
    return 0;
}

static int fill_args_sub(int *args_sub, char **bytescode_arr,
    robot_t *robot, int *cursor_int)
{
    for (int size = 0; size < 3; size++) {
        if (handle_registre_case(args_sub, bytescode_arr,
            robot, cursor_int, size) == 84) {
            return 84;
        }
    }
    return 0;
}

static void print_debug_info(char *bytescode, char **bytescode_arr, int *args_sub)
{
    my_putstr("                         --------------------------------\n");
    my_putstr("                                       sub\n");
    my_putstr("                         --------------------------------\n");
    my_putstr("                               bytescode ");
    my_putstr(bytescode);
    my_putstr("\n                         --------------------------------\n");
    my_putstr("                                 bytescode array\n");
    my_putstr("                           ");
    print_array(bytescode_arr);
    my_putstr("                         --------------------------------\n");
    my_putstr("                                  arguments_sub\n");
    my_putstr("                                    ");
    print_int_array(args_sub, 3);
    my_putstr("                         --------------------------------\n");
}

int sub_function(st_t *st, robot_t *robot)
{
    my_putstr("                         --------------------------------\n");
    my_putstr("                                       sub\n");
    int cursor_int = robot->cursor + 2;
    char *bytescode = int_to_binary(robot->instructions_int[robot->cursor + 1]);
    char **bytescode_arr = split_binary_string(bytescode);
    int *args_sub = malloc(sizeof(int) * 3);

    bytescode_arr = rename_content_bytescode(bytescode_arr);
    if (check_sub_format(bytescode_arr) != 0) {
        free(args_sub);
        return 84;
    }
    if (fill_args_sub(args_sub, bytescode_arr, robot, &cursor_int) == 84) {
        free(args_sub);
        return 84;
    }
    print_debug_info(bytescode, bytescode_arr, args_sub);
    robot->registres[args_sub[2]] = (robot->registres[args_sub[0]] - robot->registres[args_sub[1]]);
    robot->pc += 2;
    robot->cursor += 2;
    robot->wait += 10;
    free(args_sub);
    return 0;
}