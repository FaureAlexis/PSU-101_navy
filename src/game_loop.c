/*
** EPITECH PROJECT, 2021
** game_loop.c
** File description:
** C source file for B-PSU-101-BDX-1-1-navy-alexis.faure
*/

#include "../include/navy.h"

void display_maps(network_t *network)
{
    my_putstr("\nmy positions:\n");
    display_map(network);
    my_putstr("\nenemy's positions:\n");
    display_enemy_map(network);
}

void attack(network_t *network)
{
    size_t size = 32;
    char *input = malloc(size * sizeof(char));
    my_putstr("\nattack: ");
    set_italic();
    getline(&input, &size, stdin);
    rm_italic();
    if (my_strlen(input) != 3 ||
    (input[0] < 'A' || input[0] > 'H') ||
    (input[1] < '1' || input[1] > '8')) {
        my_putstr("wrong position");
        attack(network);
    }
    send_attack(network, input);

}

void game_round(network_t *network)
{
    display_maps(network);
    if (!network->my_host) {
        defense(network);
        attack(network);
    }
    else {
        attack(network);
        defense(network);
    }
}


void game_loop(network_t *network)
{
    network->my_points = 0;
    network->enemy->enemy_points = 0;
    create_tab(network);
    load_pos(network);
    create_enemy_map(network);
    while (network->my_points != 14 ||
    network->enemy->enemy_points != 14) {
        game_round(network);
    }
    if (network->my_points == 14)
        my_putstr("\nI won\n");
    else
        my_putstr("\nEnemy won\n");
    free_map(network);
    free_enemy_map(network);
}
