/*
** EPITECH PROJECT, 2021
** pos1.c
** File description:
** C source file for B-PSU-101-BDX-1-1-navy-alexis.faure
*/

#include "../include/navy.h"

position_t parse_pos(char *line)
{
    position_t pos;
    int size = 0;

    size = (int) line[0] - 48;
    pos.size = size;
    pos.start_x = (int) line[2] - 64;
    pos.start_y = (int) line[3] - 48;
    pos.end_x = (int) line[5] - 64;
    pos.end_y = (int) line[6] - 48;
    return pos;
}

void fill_pos(network_t *network, position_t *pos)
{
    if (pos->start_x == pos->end_x) {
        for (int y = pos->start_y + 1; y != pos->end_y; y += 1) {
            network->my_map[y][pos->start_x] = pos->size;
        }
    } else if (pos->start_y == pos->end_y) {
        for (int x = pos->start_x + 1; x != pos->end_x; x += 1) {
            network->my_map[pos->start_y][x] = pos->size;
        }
    }
}

void set_pos(network_t *network, position_t *pos)
{
    network->my_goal += pos->size;
    pos->start_x -= 1;
    pos->start_y -= 1;
    pos->end_x -= 1;
    pos->end_y -= 1;
    network->my_map[pos->start_y][pos->start_x] = pos->size;
    network->my_map[pos->end_y][pos->end_x] = pos->size;
    if (pos->size > 2) {
        fill_pos(network, pos);
    }
}

void load_pos(network_t *network)
{
    int fd = open(network->my_pos, O_RDONLY);
    char buffer[1024];
    read(fd, buffer, sizeof(buffer));
    position_t my_pos[4];
    int y = 0;
    int j = 0;
    for (int i = 0; i < 4; i += 1) {
        int x = 0;
        char line[7];
        for (; buffer[j] != '\n'; j += 1) {
            line[x] = buffer[j];
            x += 1;
        }
        line[x] = '\0';
        j += 1;
        my_pos[y] = parse_pos(line);
        set_pos(network, &my_pos[y]);
        y += 1;
    }
    close(fd);
}
