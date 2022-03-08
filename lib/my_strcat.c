/*
** EPITECH PROJECT, 2021
** my_strcat
** File description:
** concatenate 2 strings
*/

int my_strlen(char *str);

char *my_strcat(char *dest, char *src)
{
    int dest_size = my_strlen(dest);
    int i = 0;

    while (src[i] != '\0') {
        dest[dest_size + i] = src[i];
        i += 1;
    }
    dest[dest_size + i] = '\0';
    return dest;
}
