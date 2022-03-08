/*
** EPITECH PROJECT, 2021
** defense.c
** File description:
** C source file for B-PSU-101-BDX-1-1-navy-alexis.faure
*/

#include "../include/navy.h"
my_sig_t *infos;

void sig_handler_stopcount(int sig, siginfo_t *info, void *context)
{
    if (sig == SIGUSR2)
        infos->stop_count = true;
}

void sig_handler_count(int sig, siginfo_t *info, void *context)
{
    if (sig == SIGUSR1)
        infos->count += 1;
}

void binary_handler(int sig, siginfo_t *info, void *context)
{
    if (sig == SIGUSR1)
        infos->binary[infos->idx] = '1';
    else if (sig == SIGUSR2)
        infos->binary[infos->idx] = '0';
    infos->idx += 1;
}

int receive_binary(network_t *network)
{
    struct sigaction sa;
    struct sigaction stwo;

    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sa.sa_sigaction = &binary_handler;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    infos->idx = 0;
    infos->binary = malloc(sizeof(char) * 32);

    while (infos->idx != infos->count) {
        pause();
    }
    infos->binary = my_revstr(infos->binary);
    int decimal = binary_to_decimal(my_atoi(infos->binary));
    return decimal;
}

int receive_attack(network_t *network)
{
    struct sigaction sa;
    struct sigaction stwo;

    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sa.sa_sigaction = &sig_handler_count;
    sigaction(SIGUSR1, &sa, NULL);
    sigemptyset(&stwo.sa_mask);
    stwo.sa_flags = 0;
    stwo.sa_sigaction = &sig_handler_stopcount;
    sigaction(SIGUSR2, &stwo, NULL);

    while (infos->stop_count != true) {
        pause();
    }
    return receive_binary(network);
}

void defense(network_t *network)
{
    my_putstr("\nwaiting for enemy's attack...\n");
    int *coord = malloc(sizeof(int) * 2);
    for (int i = 0; i < 2; i += 1) {
        infos = malloc(sizeof(*infos));
        infos->stop_count = false;
        infos->count = 0;
        coord[i] = receive_attack(network);
        usleep(70000);
    }
    is_attack_correct(network, coord);
}
