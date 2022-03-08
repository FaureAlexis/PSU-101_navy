/*
** EPITECH PROJECT, 2021
** my_compute_power_rec
** File description:
** power recursive
*/

int my_compute_power_rec(int nb, int p)
{
    int i = 1;

    if (p < 0)
        return 0;
    if (i <= (p - 1)) {
        nb = nb * my_compute_power_rec(nb, p - 1);
    }
    return nb;
}
