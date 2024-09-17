/*
** EPITECH PROJECT, 2023
** B-CPE-200-LYN-2-1-corewar-jules.lordet
** File description:
** loop_instructions_robot.c
*/

#include "../../includes/my.h"

static void execute_case_13_to_16(int opcode, st_t *st, robot_t *robot)
{
    switch (opcode) {
        case 13:
            lld_function(st, robot);
            break;
        case 14:
            lldi_function(st, robot);
            break;
        case 15:
            lfork_function(st, robot);
            break;
        case 16:
            aff_function(st, robot);
            break;
        default:
            break;
    }
}

static void execute_case_9_to_12(int opcode, st_t *st, robot_t *robot)
{
    switch (opcode) {
        case 9:
            zjmp_function(st, robot);
            break;
        case 10:
            ldi_function(st, robot);
            break;
        case 11:
            sti_function(st, robot);
            break;
        case 12:
            fork_function(st, robot);
            break;
        default:
            execute_case_13_to_16(opcode, st, robot);
            break;
    }
}

static void execute_case_5_to_8(int opcode, st_t *st, robot_t *robot)
{
    switch (opcode) {
        case 5:
            sub_function(st, robot);
            break;
        case 6:
            and_function(st, robot);
            break;
        case 7:
            or_function(st, robot);
            break;
        case 8:
            xor_function(st, robot);
            break;
        default:
            execute_case_9_to_12(opcode, st, robot);
            break;
    }
}

static void execute_case_1_to_4(int opcode, st_t *st, robot_t *robot)
{
    switch (opcode) {
        case 1:
            live_function(st, robot);
            break;
        case 2:
            ld_function(st, robot);
            break;
        case 3:
            st_function(st, robot);
            break;
        case 4:
            add_function(st, robot);
            break;
        default:
            execute_case_5_to_8(opcode, st, robot);
            break;
    }
}

void execute_instruction(st_t *st, robot_t *robot)
{
    int opcode = robot->instructions_int[robot->cursor];

    execute_case_1_to_4(opcode, st, robot);
}

void process_all_robots_in_cycle(st_t *st)
{
    for (int i = 0; i < st->count_player; i++) {
        robot_t *robot = &st->robot[i];
        if (robot->wait == 0 && robot->stock == 0) {
            my_putstr("              8888888888888888888888888888888888888888888888888888888888\n");
            my_putstr("                        ");
            my_putstr(st->robot[i].name);
            my_putstr(" number ");
            my_putnbr(robot->prog_number);
            my_putstr(" is executing instruction ");
            my_putnbr(robot->instructions_int[robot->cursor]);
            my_putstr("\n              8888888888888888888888888888888888888888888888888888888888\n");
            execute_instruction(st, robot);
        } else
            robot->wait -= 1;
    }
}

void player_win(int i, st_t *st)
{
    if (st->robot[i].stock == 0) {
        my_putstr("                           The player ");
        my_putnbr(st->robot[i].prog_number);
        my_putstr(" ( ");
        my_putstr(st->robot[i].name);
        my_putstr(" ) is the winner\n");
        st->end = 0;
    }
}

void check_is_alive(st_t *st)
{
    int count_dead = 0;

    for (int i = 0; i < st->count_player; i++) {
        if (st->robot[i].live == 0) {
            st->robot[i].stock = 1;
        } else {
            my_putstr("                           The player ");
            my_putnbr(st->robot[i].prog_number);
            my_putstr(" ( ");
            my_putstr(st->robot[i].name);
            my_putstr(" ) is alive\n");
            st->robot[i].live = 0;
        }
    }
    for (int i = 0; i < st->count_player; i++) {
        if (st->robot[i].stock == 1)
            count_dead++;
    }
    if (st->count_player - count_dead == 1) {
        for (int i = 0; i < st->count_player; i++) {
            player_win(i, st);
        }
    }
}

void process_all_cycle(st_t *st)
{
    int cycle_to_die_now = CYCLE_TO_DIE;
    int check_dead_time = 0;
    int cycle = 0;

    while (st->end != 0) {
        if (check_dead_time == cycle_to_die_now) {
            check_dead_time = 0;
            check_is_alive(st);
        }
        if (st->number_live == 40) {
            cycle_to_die_now -= CYCLE_DELTA;
            st->number_live = 0;
        }
        my_putstr("/////////////////////////////////////////////////////////////////////////////////////////\n");
        my_putstr("                                  CYCLE ");
        my_putnbr(cycle);
        my_putstr("\n");
        my_putstr("/////////////////////////////////////////////////////////////////////////////////////////\n");
        process_all_robots_in_cycle(st);
        check_dead_time++;
        if (cycle == st->config.dump_cycle) {
            print_map(st);
            cycle = 0;
        }
        cycle++;
    }
}
