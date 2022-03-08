/*
** EPITECH PROJECT, 2021
** navy.c
** File description:
** C source file for B-PSU-101-BDX-1-1-navy-alexis.faure
*/

#include "../include/navy.h"

int navy(int ac, char **av)
{
    network_t *network = malloc(sizeof(*network));
    network->enemy = malloc(sizeof(*network->enemy));
    network = parse_params(av, network);
    network->my_pid = getpid();
    int code = error_handler(network);
    if (code == 84)
        return code;
    start_game(network);
    return code;
}

void destroy_game(network_t *network)
{
    free(network);
}
