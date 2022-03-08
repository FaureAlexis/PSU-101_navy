/*
** EPITECH PROJECT, 2021
** enemy.c
** File description:
** C source file for B-PSU-101-BDX-1-1-navy-alexis.faure
*/

#include "../include/navy.h"

void create_enemy_map(network_t *network)
{
    network->enemy->enemy_map = malloc(sizeof(int *) * 10);
    for (int i = 0; i < 8; i += 1) {
        network->enemy->enemy_map[i] = malloc(sizeof(int) * 9);
        for (int j = 0; j < 8; j += 1) {
            network->enemy->enemy_map[i][j] = 0;
        }
    }
}

void format_output_enemy(int nb)
{
    if (nb == 0)
        my_putchar('.');
    else if (nb == 1)
        my_putchar('o');
    else
        my_putchar('x');
}

void display_enemy_map(network_t *network)
{
    my_putstr(" | A B C D E F G H\n");
    my_putstr("-+---------------\n");
    for (int x = 0; x < 8; x += 1) {
        my_put_nbr(x + 1);
        my_putchar('|');
        for (int y = 0; y < 8; y += 1) {
            my_putchar(' ');
            format_output_enemy(network->enemy->enemy_map[x][y]);
        }
        my_putchar('\n');
    }
}

void free_enemy_map(network_t *network)
{
    for (int i = 0; i < 9; i += 1) {
        free(network->enemy->enemy_map[i]);
    }
    free(network->enemy->enemy_map);
}
