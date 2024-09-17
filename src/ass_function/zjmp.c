/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** zjmp.c
*/

#include "../../includes/my.h"

int check_zjmp_format(char **params)
{
    int count = 0;

    for (int i = 0; params[i] != NULL; i++) {
        count++;
    }
    if (count != 1)
        return 84;

    if (!(my_strcmp(params[0], "direct") == 0 ||
          my_strcmp(params[0], "indirect") == 0)) {
        return 84;
    }
    return 0;
}

static int handle_direct_indirect_case(int *args_zjump, char **bytescode_arr,
    robot_t *robot, int *cursor_int, int size)
{
    if (my_strcmp(bytescode_arr[size], "direct") == 0 &&
        my_strcmp(bytescode_arr[size], "indirect") == 0) {
        return 0;
    }
    args_zjump[size] = robot->instructions_int[*cursor_int] +
        robot->instructions_int[*cursor_int + 1];
    (*cursor_int) += 2;
    robot->pc += 2;
    robot->cursor += 2;
    return 0;
}

static int fill_args_zjump(int *args_zjump, char **bytescode_arr,
    robot_t *robot, int *cursor_int)
{
    for (int size = 0; size < 1; size++) {
        if (handle_direct_indirect_case(args_zjump, bytescode_arr,
            robot, cursor_int, size) == 84) {
            return 84;
        }
    }
    return 0;
}

static void print_debug_info(char *bytescode, char **bytescode_arr, int *args_zjmp)
{
    my_putstr("                         --------------------------------\n");
    my_putstr("                                       zjmp\n");
    my_putstr("                         --------------------------------\n");
    my_putstr("                               bytescode ");
    my_putstr(bytescode);
    my_putstr("\n                         --------------------------------\n");
    my_putstr("                                 bytescode array\n");
    my_putstr("                           ");
    print_array(bytescode_arr);
    my_putstr("                         --------------------------------\n");
    my_putstr("                                 arguments_zjpm\n");
    my_putstr("                                      ");
    print_int_array(args_zjmp, 1);
    my_putstr("                         --------------------------------\n");
}

static int prepare_zjmp(st_t *st, robot_t *robot,
    int *args_zjump, char **bytescode_arr)
{
    int cursor_int = robot->cursor + 1;
    char *bytescode = "10";

    bytescode_arr[0] = bytescode;
    bytescode_arr[1] = NULL;
    bytescode_arr = rename_content_bytescode(bytescode_arr);
    if (check_zjmp_format(bytescode_arr) != 0) {
        free(args_zjump);
        return 84;
    }
    if (fill_args_zjump(args_zjump, bytescode_arr, robot, &cursor_int) == 84) {
        free(args_zjump);
        return 84;
    }
    print_debug_info(bytescode, bytescode_arr, args_zjump);
    return 0;
}

int zjmp_function(st_t *st, robot_t *robot)
{
    char **bytescode_arr = malloc(sizeof(char *) * 1);
    int *args_zjump = malloc(sizeof(int) * 1);
    int result;
    if (prepare_zjmp(st, robot, args_zjump, bytescode_arr) != 0) {
        return 84;
    }
    if (args_zjump[0] < 100) {
        robot->pc -= 1;
        robot->cursor -= 1;
    }
    robot->pc -= 1;
    robot->cursor -= 1;
    result = ((robot->pc + args_zjump[0]) % 512);
    robot->pc = result;
    result = ((robot->cursor + args_zjump[0]) % 512);
    robot->cursor = result;
    robot->wait += 20;
    free(args_zjump);
    return 0;
}
