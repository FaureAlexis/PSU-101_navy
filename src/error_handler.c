/*
** EPITECH PROJECT, 2021
** error_handler.c
** File description:
** C source file for B-PSU-101-BDX-1-1-navy-alexis.faure
*/

#include "../include/navy.h"

bool is_pid_correct(network_t *network)
{
    if (network->enemy->enemy_pid) {
        if (network->enemy->enemy_pid < 1000)
            return false;
    }
    if (network->my_pid < 1000)
        return false;
    return true;
}

bool is_pos_correct(char *path)
{
    char *buffer = malloc(sizeof(char) * 1024);
    int fd = open(path, O_RDONLY);
    int f_size = 0;

    if (fd == -1)
        return false;
    f_size = read(fd, buffer, sizeof(buffer));
    if (f_size < 1)
        return false;
    free(buffer);
    return true;
}

int error_handler(network_t *network)
{
    if (network->my_pos[0] == '\0')
        return 84;
    if (!is_pos_correct(network->my_pos))
        return 84;
    if (!is_pid_correct(network))
        return 84;
    return 0;
}
