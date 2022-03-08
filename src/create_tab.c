/*
** EPITECH PROJECT, 2021
** create_tab.c
** File description:
** C source file for B-PSU-101-BDX-1-1-navy-alexis.faure
*/

#include "../include/navy.h"

void format_output(int nb)
{
    switch (nb) {
        case 6:
            my_putchar('x');
            break;
        case 0:
            my_putchar('.');
            break;
        case 1:
            my_putchar('o');
            break;
        default:
            my_put_nbr(nb);
            break;
    }
}

void display_map(network_t *network)
{
    my_putstr(" | A B C D E F G H\n");
    my_putstr("-+---------------\n");
    for (int x = 0; x < 8; x += 1) {
        my_put_nbr(x + 1);
        my_putchar('|');
        for (int y = 0; y < 8; y += 1) {
            my_putchar(' ');
            format_output(network->my_map[x][y]);
        }
        my_putchar('\n');
    }
}

void create_map(network_t *network)
{
    network->my_map = malloc(sizeof(int *) * 10);
    for (int i = 0; i < 8; i += 1) {
        network->my_map[i] = malloc(sizeof(int) * 9);
        for (int j = 0; j < 8; j += 1) {
            network->my_map[i][j] = 0;
        }
    }
}

void free_map(network_t *network)
{
    for (int i = 0; i < 9; i += 1) {
        free(network->my_map[i]);
    }
    free(network->my_map);
}

void create_tab(network_t *network)
{
    create_map(network);
}
