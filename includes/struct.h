/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** struct.h
*/

#ifndef STRUCT_H_
    #define STRUCT_H_
    #include "my.h"

typedef enum bool_s {
    false,
    true,
} bool_t;

typedef struct instr_s {
    char code;
    int prog_number;
    int cycle;
    int address;
    int value;
    int type;
    int size;
    int carry;
    int reg;
    int idx;
    int dir;
    int ind;
    int *params;
    int *params_type;
    int *params_size;
    int *params_value;
    int *params_address;
    int *params_reg;
    int *params_idx;
    int *params_dir;
    int *params_ind;
} instr_t;

typedef struct config_s {
    int dump_cycle;
    int prog_number;
    size_t load_address;
    char **prog_names;
    int num_programs;
    char *free_prog_number;
} config_t;

typedef struct st_s {
    int ac;
    char **av;
    int exit_status;
    bool_t dump;
    struct config_s config;
    struct robot_s *robot;
    struct instr_s *instr;
    int count_player;
    int number_live;
    int end;
} st_t;

typedef struct args_s {
    bool_t a;
    bool_t n;
    bool_t dump;
} args_t;

typedef struct robot_s {
    args_t args;
    int instruction_nbr;
    int *instr_bin;
    char *magic_nbr;
    char *name;
    char *desc;
    char *instructions;
    int *instructions_int;
    char *instruction_hexa;
    int stock;
    int wait;
    int pc;
    int dead;
    int cycle;
    int cursor;
    int carry;
    int live;
    int load_address;
    int init_load_adress;
    int *registres;
    int prog_number;
    char **mnemonics;
    int **mnemonics_bytes;
    size_t address;
} robot_t;

#endif
