/*
** EPITECH PROJECT, 2021
** my_put_nbr
** File description:
** function to display a number
*/

void process(int i);

void my_putchar(char c);

int my_isnegative(int i)
{
    int true = 0;
    int false = 1;

    if (i >= 0)
        return false;
    else
        return true;
}

void my_put_nbr(int i)
{
    if (my_isnegative(i) == 0) {
        my_putchar('-');
        i = -i;
        process(i);
    } else
        process(i);
}

void print_numberito(int number)
{
    int n = number + 48;

    my_putchar(n);
}

void process(int i)
{
    int n = i;
    int numero1;
    int numero2 = 0;

    if (n > 9){
        int n_i = n % 10;
        n = n / 10;
        process(n);
        print_numberito(n_i);
    } else {
        print_numberito(n);
    }
}
