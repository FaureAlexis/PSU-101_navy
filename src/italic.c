/*
** EPITECH PROJECT, 2021
** italic.c
** File description:
** C source file for B-PSU-101-BDX-1-1-navy-alexis.faure
*/

#include "../include/navy.h"

void set_italic(void)
{
    my_putchar(27);
    my_putstr("[3m");
}

void rm_italic(void)
{
    my_putchar(27);
    my_putstr("[0m");
}
