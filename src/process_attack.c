/*
** EPITECH PROJECT, 2021
** process-attack.c
** File description:
** C source file for B-PSU-101-BDX-1-1-navy-alexis.faure
*/

#include "../include/navy.h"
int res = 0;

void handle_result(int sig, siginfo_t *info, void *context)
{
    if (sig == SIGUSR1) {
        res = 1;
    } else if (sig == SIGUSR2) {
        res = 0;
    }
}

void process_attack(network_t *network, char *attack, int x, int y)
{
    struct sigaction sa;
    sa.sa_sigaction = &handle_result;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    pause();
    attack[2] = '\0';
    my_putstr(attack);
    my_putstr(": ");
    if (res != 1) {
        my_putstr("missed\n");
        network->enemy->enemy_map[x - 1][y - 1] = 1;
    }
    else {
        my_putstr("hit\n");
        network->enemy->enemy_map[x - 1][y - 1] = 2;
    }
}