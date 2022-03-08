/*
** EPITECH PROJECT, 2021
** my_atoi
** File description:
** array to int
*/

#include "../include/navy.h"

static int calc(int nbr, int i, int coef, char *str)
{
    while (i < (my_strlen(str))) {
        nbr = nbr + ((str[i] - 48) * coef);
        coef = coef / 10;
        i += 1;
    }
    return nbr;
}

int my_atoi(char *str)
{
    int nbr = 0;
    int len = my_strlen(str);
    int neg = 0;
    int i = 0;
    int coef = 0;

    if (len == 1)
        return str[0] - 48;
    if (str[0] == 45) {
        i = 1;
        neg = 1;
    }
    coef = my_compute_power_rec(10, (len - (1 * (i + 1))));
    nbr = calc(nbr, i, coef, str);
    if (neg == 1)
        nbr = nbr * (-1);
    return nbr;
}

bool isnum(char *str)
{
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (!(str[i] <= '9' && str[i] >= '0'))
            return false;
    }
    return true;
}
