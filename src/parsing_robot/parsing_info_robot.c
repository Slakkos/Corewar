/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-jules.lordet
** File description:
** parsing_info_robot.c
*/

#include "../../includes/my.h"

void calculate_default_load_address(st_t *st)
{
    int value = MEM_SIZE / st->config.prog_number;

    for (int i = 0; i < st->config.prog_number; i++) {
        if (st->robot[i].load_address == 0) {
            st->robot[i].load_address = i * value;
        }
    }
    for (int i = 0; i < st->count_player; i++) {
        st->robot[i].pc = st->robot[i].load_address;
    }
    for (int i = 0; i < st->config.prog_number; i++) {
        st->robot[i].carry = 0;
    }
}

void initialiser_registres_robot(st_t *st)
{
    for (int i = 0; i < st->config.prog_number; i++) {
        st->robot[i].registres[0] = 0;
        st->robot[i].registres[1] = st->robot[i].prog_number;
        for (int j = 2; j < 16; j++) {
            st->robot[i].registres[j] = 0;
        }
    }
}
