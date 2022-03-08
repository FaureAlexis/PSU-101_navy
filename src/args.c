/*
** EPITECH PROJECT, 2021
** args.c
** File description:
** C source file for B-PSU-101-BDX-1-1-navy-alexis.faure
*/

#include "../include/navy.h"

void display_help(void)
{
    my_putstr("USAGE\n     ./navy [first_player_pid] navy_positions\n");
    my_putstr("DESCRIPTION\n     first_player_pid:");
    my_putstr(" only for the 2nd player. pid of the first player.\n");
    my_putstr("     navy_positions: file representing");
    my_putstr(" the positions of the ships.");
}

network_t *parse_params(char **av, network_t *network)
{
    network->my_pos = "";
    for (int i = 1; av[i] != NULL; i += 1) {
        if (av[i][0] == '-' && av[i][1] == 'h') {
            display_help();
        } else if (isnum(av[i])) {
            network->enemy->enemy_pid = my_atoi(av[i]);
        } else {
            network->my_pos = av[i];
        }
    }
    return network;
}
