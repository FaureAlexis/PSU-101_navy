/*
** EPITECH PROJECT, 2021
** convert_to_binary.c
** File description:
** C source file for B-PSU-101-BDX-1-1-navy-alexis.faure
*/

#include "../include/navy.h"

int convert_to_binary(unsigned int nbr)
{
    int i = 1;
    int c = 0;
    int result_int = 0;
    char *result = malloc(sizeof(char) * 32);

    for (c = 0; nbr >= i; c += 1)
        i = i * 2;
    for (; i >= 1; c -= 1) {
        if (nbr >= i) {
            result_int = (nbr / i);
            result[c] = (char) result_int + 48;
            nbr = nbr % i;
            i = i / 2;
        } else {
            result[c] = '0';
            i = i / 2;
        }
    }
    result_int = my_atoi(my_revstr(result));
    free(result);
    return result_int;
}

int binary_to_decimal(int binary)
{
    int result = 0;
    int tmp = 0;
    for (int i = 1; binary  > 0; i *= 2) {
        tmp = (binary % 10) * i;
        binary /= 10;
        result += tmp;
    }
    return result;
}
