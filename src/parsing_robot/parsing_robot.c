/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** jsp.c
*/

#include "../../includes/my.h"

unsigned int find_nbr_int(int *nbr)
{
    unsigned int nbr_int = 0;
    int int_1 = (nbr[0] & 0x000000FF) << 24;
    int int_2 = (nbr[0] & 0x0000FF00) << 8;
    int int_3 = (nbr[0] & 0x00FF0000) >> 8;
    int int_4 = (nbr[0] & 0xFF000000) >> 24;
    int int_5 = (nbr[1] & 0x000000FF) << 24;
    int int_6 = (nbr[1] & 0x0000FF00) << 8;
    int int_7 = (nbr[1] & 0x00FF0000) >> 8;
    int int_8 = (nbr[1] & 0xFF000000) >> 24;

    nbr_int = (int_5 | int_6 | int_7 | int_8 | int_1 | int_2 | int_3 | int_4);
    return nbr_int;
}

void parse_robot_spec(st_t *st, int i, FILE *file)
{
    st->robot[i].name = malloc(sizeof(char) * 129);
    fread(st->robot[i].name, 1, 128, file);
    st->robot[i].name[128] = '\0';
    st->robot[i].instr_bin = malloc(sizeof(char) * 9);
    fread(st->robot[i].instr_bin, 1, 8, file);
    st->robot[i].instr_bin[8] = '\0';
    st->robot[i].instruction_nbr = find_nbr_int(st->robot[i].instr_bin);
    st->robot[i].desc = malloc(sizeof(char) * 2053);
    fread(st->robot[i].desc, sizeof(char), 2052, file);
    st->robot[i].desc[2052] = '\0';
    st->robot[i].instructions = malloc(sizeof(char) *
    (st->robot[i].instruction_nbr + 1));
    fread(st->robot[i].instructions, sizeof(char),
    st->robot[i].instruction_nbr, file);
    st->robot[i].instructions[st->robot[i].instruction_nbr] = '\0';
}

FILE *open_robot_file(st_t *st, int i)
{
    FILE *file = fopen(st->config.prog_names[i], "rb");

    return file;
}

static int check_magic_number(st_t *st, int i, FILE *file)
{
    int is_valid = 0;

    st->robot[i].magic_nbr = malloc(sizeof(char) * 4);
    fread(st->robot[i].magic_nbr, sizeof(char), 4, file);
    is_valid = st->robot[i].magic_nbr[0] == 0 &&
        st->robot[i].magic_nbr[1] == -22 &&
        st->robot[i].magic_nbr[2] == -125 &&
        st->robot[i].magic_nbr[3] == -13;
    free(st->robot[i].magic_nbr);
    return is_valid ? EXIT_SUCCESS : EXIT_FAILURE;
}

static int parse_single_robot(st_t *st, int i)
{
    FILE *file;

    if (init_robot(st, i) == EXIT_FAILURE)
        return EXIT_FAILURE;
    file = open_robot_file(st, i);
    if (file == NULL)
        return EXIT_FAILURE;
    if (check_magic_number(st, i, file) == EXIT_FAILURE)
        return EXIT_FAILURE;
    parse_robot_spec(st, i, file);
    st->count_player++;
    fclose(file);
    return EXIT_SUCCESS;
}

int parsing_robot(st_t *st)
{
    for (int i = 0; st->config.prog_names[i] != NULL; i++) {
        if (parse_single_robot(st, i) == EXIT_FAILURE)
            return EXIT_FAILURE;
    }
    parse_flag_robot(st);
    calculate_default_load_address(st);
    initialiser_registres_robot(st);
    return EXIT_SUCCESS;
}
