/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-jules.lordet
** File description:
** convert_hexa_to_decimal.c
*/

#include "../includes/my.h"

int *hex_to_decimal(char *hex_string)
{
    size_t length = my_strlen(hex_string);
    size_t instruction_count = 0;
    int *instructions_int;
    int j = 0;

    for (size_t i = 0; i < length; i++) {
        if (hex_string[i] != ' ') {
            instruction_count++;
        }
    }
    instruction_count /= 2;
    instructions_int = malloc(instruction_count * sizeof(int));
    for (size_t i = 0; i < length; i++) {
        if (hex_string[i] == ' ') {
            continue;
        }
        char hex_byte[3] = { hex_string[i], hex_string[i + 1], '\0' };
        instructions_int[j++] = my_strtol(hex_byte, NULL, 16);
        i++;
    }
    return instructions_int;
}

void convert_all_robot_instructions(st_t *st)
{
    for (int i = 0; i < st->count_player; i++) {
        robot_t *robot = &st->robot[i];
        robot->instructions_int = hex_to_decimal(robot->instruction_hexa);
    }
}

void print_robot_instructions(st_t *st)
{
    for (int i = 0; i < st->count_player; i++) {
        robot_t *robot = &st->robot[i];
        size_t length = my_strlen(robot->instruction_hexa);
        size_t instruction_count = 0;

        for (size_t j = 0; j < length; j++) {
            if (robot->instruction_hexa[j] != ' ') {
                instruction_count++;
            }
        }
        instruction_count /= 2;
    }
}