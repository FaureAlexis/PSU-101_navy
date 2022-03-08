/*
** EPITECH PROJECT, 2021
** attack.c
** File description:
** C source file for B-PSU-101-BDX-1-1-navy-alexis.faure
*/

#include "../include/navy.h"

void is_attack_correct(network_t *network, int *coord)
{
    my_putchar(coord[0] + 64);
    my_put_nbr(coord[1]);
    my_putstr(": ");
    if (network->my_map[coord[1] - 1][coord[0] - 1] != 0) {
        kill(network->enemy->enemy_pid, SIGUSR1);
        network->enemy->enemy_points += 1;
        network->my_map[coord[1] - 1][coord[0] - 1] = 6;
        my_putstr("hit\n");
    }
    else {
        kill(network->enemy->enemy_pid, SIGUSR2);
        network->my_map[coord[1] - 1][coord[0] - 1] = 1;
        my_putstr("missed\n");
    }
}

void send_binary(network_t *network, int binary)
{
    int enemy_pid = network->enemy->enemy_pid;
    int cpy = binary;
    for (; cpy > 0; cpy /= 10) {
        kill(enemy_pid, SIGUSR1);
        usleep(5000);
    }
    kill(enemy_pid, SIGUSR2);
    usleep(5000);
    for (; binary > 0; binary /= 10) {
        if (binary % 10 == 0)
            kill(enemy_pid, SIGUSR2);
        else if (binary % 10 == 1)
            kill(enemy_pid, SIGUSR1);
        usleep(10000);
    }
}

void send_attack(network_t *network, char *attack)
{
    int y = (int) attack[0] - 64;
    int x = (int) attack[1] - 48;

    int binary_y = convert_to_binary(y);
    int binary_x = convert_to_binary(x);

    send_binary(network, binary_y);
    usleep(100000);
    send_binary(network, binary_x);
    process_attack(network, attack, x, y);
}
