/*
** EPITECH PROJECT, 2021
** navy.h
** File description:
** C source file for B-PSU-101-BDX-1-1-navy-alexis.faure
*/

#ifndef B_PSU_101_BDX_1_1_NAVY_ALEXIS_FAURE_NAVY_H
#define B_PSU_101_BDX_1_1_NAVY_ALEXIS_FAURE_NAVY_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

typedef struct enemy
{
    int **enemy_map;
    int enemy_pid;
    int enemy_points;
    int enemy_goal;
} enemy_t;

typedef struct network
{
    int my_points;
    int my_goal;
    bool my_host;
    int my_pid;
    int **my_map;
    char *my_pos;
    enemy_t *enemy;
} network_t;

typedef struct position
{
    int size;
    int start_x;
    int start_y;
    int end_x;
    int end_y;
} position_t;

typedef struct signal_receiver
{
    int count;
    int idx;
    bool stop_count;
    char *binary;
} my_sig_t;

void my_putstr(char *str);

int my_arrlen(char **arr);

int my_atoi(char *str);

void my_putchar(char c);

char *my_revstr(char *str);

int my_compute_power_rec(int nb, int p);

char *my_strcat(char *dest, char *src);

int my_put_nbr(int nb);

int start_game(network_t *network);

int error_handler(network_t *network);

int my_strlen(char *str);

network_t *parse_params(char **av, network_t *network);

bool isnum(char *str);

void set_pos(network_t *network, position_t *pos);

void create_tab(network_t *network);

void print_tab(char **tab, int max);

void destroy_tab(char **tab);

void load_pos(network_t *network);

void my_print_array(char **);

void destroy_game(network_t *network);

void game_loop(network_t *network);

void display_map(network_t *network);

void display_enemy_map(network_t *network);

void free_map(network_t *network);

void display_enemy_map(network_t *network);

void free_enemy_map(network_t *network);

void create_enemy_map(network_t *network);

void rm_italic(void);

void set_italic(void);

int convert_to_binary(unsigned int nbr);

void send_attack(network_t *network, char *attack);

int my_binary_len(int *array);

void defense(network_t *network);

void is_attack_correct(network_t *network, int *coord);

int binary_to_decimal(int binary);

void process_attack(network_t *network, char *attack, int x, int y);

#endif
