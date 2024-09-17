/*
** EPITECH PROJECT, 2023
** EPITECH
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_
    #include "lib.h"
    #include <stdint.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <string.h>
    #include <syscall.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include "struct.h"
    #include "../E_op/op.h"
    #define TRUE 1
    #define FALSE 0

int parsing_args(st_t *st);
int parse_flag_robot(st_t *st);
int init_robot(st_t *st, int i);
int parsing_robot(st_t *st);
int parsing_robot_name(st_t *st, int j, FILE *file);
int create_map(st_t *st);

void calculate_default_load_address(st_t *st);
void initialiser_registres_robot(st_t *st);

int handle_dump_cycle(st_t *st, int *i);
int handle_prog_number(st_t *st, int *i, int *i_prog);
int handle_load_address(st_t *st, int *i, int *i_prog);
int handle_prog_name(st_t *st, int *i, int *i_prog);

void process_all_robots(st_t *st);
void print_robot_hexdumps(const st_t *st);
void convert_all_robot_instructions(st_t *st);
void print_robot_instructions(st_t *st);
void process_all_cycle(st_t *st);
char **split_binary_string(const char *binary_string);
char **rename_content_bytescode(char **table);
void print_array(char **arr);
void print_int_array(int *arr, int size);
char *int_to_binary(int n);
int *convert_bin_array(char **bin_strs);

int add_function(st_t *st, robot_t *robot);
int aff_function(st_t *st, robot_t *robot);
int and_function(st_t *st, robot_t *robot);
int fork_function(st_t *st, robot_t *robot);
int ld_function(st_t *st, robot_t *robot);
int ldi_function(st_t *st, robot_t *robot);
int lfork_function(st_t *st, robot_t *robot);
int live_function(st_t *st, robot_t *robot);
int lld_function(st_t *st, robot_t *robot);
int lldi_function(st_t *st, robot_t *robot);
int or_function(st_t *st, robot_t *robot);
int st_function(st_t *st, robot_t *robot);
int sti_function(st_t *st, robot_t *robot);
int sub_function(st_t *st, robot_t *robot);
int xor_function(st_t *st, robot_t *robot);
int zjmp_function(st_t *st, robot_t *robot);

int attack_bytecode(st_t *st, int registre, int map_pos);

void init_robot_properties(robot_t *robot);
void print_map(st_t *st);

#endif
