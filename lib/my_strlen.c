/*
** EPITECH PROJECT, 2021
** my_strlen
** File description:
** Count char in string
*/

int my_strlen(char const *str)
{
    int i = 0;

    if (str[i] == '\0')
        return 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}
