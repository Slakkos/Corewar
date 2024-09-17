/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-jules.lordet
** File description:
** convert_hexa_to_bin.c
*/

#include "../includes/my.h"

void hexdump(const char *data, size_t length, char **output) {
    size_t output_size = length * 3;
    *output = (char *)malloc(output_size + 1);
    (*output)[0] = '\0';

    char buffer[4];
    for (size_t i = 0; i < length; i++) {
        snprintf(buffer, sizeof(buffer), "%02x ", (unsigned char)data[i]);
        strcat(*output, buffer);
    }
    (*output)[output_size] = '\0';
}

void process_all_robots(st_t *st) {
    for (int i = 0; i < st->count_player; i++) {
        robot_t *robot = &st->robot[i];
        hexdump(robot->instructions, robot->instruction_nbr, &robot->instruction_hexa);
    }
}
