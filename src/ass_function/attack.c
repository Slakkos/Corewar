/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** sti_attack.c
*/

#include "../../includes/my.h"

void attaque_in_robot(st_t *st, char **arr, int victime, int victime_pos, int map_pos)
{
    int *registre_bin_int = convert_bin_array(arr);

    if (victime == -1 || victime_pos == -1)
        return;
    st->robot[victime].instructions[victime_pos] = registre_bin_int[0];
    if ((victime_pos + 1) < 16) {
        st->robot[victime].instructions[victime_pos + 1] = registre_bin_int[1];
    }
    if ((victime_pos + 2) < 16) {
        st->robot[victime].instructions[victime_pos + 2] = registre_bin_int[2];
    }
    if ((victime_pos + 3) < 16) {
        st->robot[victime].instructions[victime_pos + 3] = registre_bin_int[3];
    }
}

void attaque_in_map(st_t *st, char **arr, int victime, int victime_pos, int map_pos)
{

    if (victime == -1 || victime_pos == -1)
        return;
    st->instr[map_pos].code = arr[0][0];
    if ((map_pos + 1) < MEM_SIZE) {
        st->instr[map_pos + 1].code = arr[1][0];
    }
    if ((map_pos + 2) < MEM_SIZE) {
        st->instr[map_pos + 2].code = arr[2][0];
    }
    if ((map_pos + 3) < MEM_SIZE) {
        st->instr[map_pos + 3].code = arr[3][0];
    }
}

int attack_bytecode(st_t *st, int registre, int map_pos)
{
    int victime = -1;
    int victime_pos = -1;
    char *registre_bin = int_to_binary(registre);
    char **registre_bin_arr = split_binary_string(registre_bin);

    for (int robot = 0; robot < st->count_player; robot++) {
        if (map_pos >= st->robot[robot].load_address &&
        map_pos <= (st->robot[robot].load_address
        + st->robot[robot].instruction_nbr)) {
            victime = robot;
            victime_pos = map_pos - st->robot[robot].load_address;
            break;
        }
    }
    for (int i = 1; i <= 16; i++) {
        if (registre == i) {
            attaque_in_map(st, registre_bin_arr, victime, victime_pos, map_pos);
            attaque_in_robot(st, registre_bin_arr, victime, victime_pos, map_pos);
        }
    }
    return 0;
}
