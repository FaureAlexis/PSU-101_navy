/*
** EPITECH PROJECT, 2021
** my_revstr
** File description:
** reverse a string
*/

#include "../include/navy.h"

char *my_revstr(char *str)
{
    int a = 0;
    int b = 0;
    char c;

    b = my_strlen(str) - 1;
    while (a < b) {
        c = str[b];
        str[b] = str[a];
        str[a] = c;
        a += 1;
        b -= 1;
    }
    return str;
}
