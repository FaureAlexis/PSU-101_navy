/*
** EPITECH PROJECT, 2021
** game.c
** File description:
** C source file for B-PSU-101-BDX-1-1-navy-alexis.faure
*/

#include "../include/navy.h"

void set_enemy_pid(network_t *network)
{
    int fd = open("./data/pid.txt", O_RDONLY);
    char *buffer = malloc(sizeof(char) * 7);
    if (fd == -1)
        return;
    read(fd, buffer, sizeof(buffer));
    network->enemy->enemy_pid = my_atoi(buffer);
}

void handler(int sig, siginfo_t *info, void *context)
{
    if (info->si_pid == 0)
        return;
    int pid = info->si_pid;
    int i = 0;
    char *pid_str = malloc(sizeof(char) * 7);
    for (; pid > 0; i += 1) {
        pid_str[i] = (pid % 10) + 48;
        pid = pid / 10;
    }
    pid_str[i] = '\0';
    pid_str = my_revstr(pid_str);
    int fd = open("./data/pid.txt", O_RDWR|O_CREAT, 0666);
    write(fd, pid_str, sizeof(pid_str));
    close(fd);
}

int init_game_host(network_t *network)
{
    struct sigaction sa;
    network->my_host = true;
    my_putstr("my_pid: ");
    my_put_nbr(network->my_pid);
    my_putstr("\nwaiting for enemy connection...\n");
    sa.sa_sigaction = &handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGUSR1, &sa, NULL);
    pause();
    set_enemy_pid(network);
    my_putstr("\nenemy connected\n");
    game_loop(network);
    return 0;
}

int init_game_guest(network_t *network)
{
    network->my_host = false;
    my_putstr("my_pid: ");
    my_put_nbr(network->my_pid);
    kill(network->enemy->enemy_pid, SIGUSR1);
    my_putstr("\nsuccessfully connected\n");
    game_loop(network);
    return 0;
}

int start_game(network_t *network)
{
    int code = 0;
    if (!network->enemy->enemy_pid)
        code = init_game_host(network);
    else
        code = init_game_guest(network);
    destroy_game(network);
    return code;
}
