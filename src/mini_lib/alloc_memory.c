/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** __Window : None | Use : alloc memory | Status : 3 places__
*/

#include "my_rpg_hd.h"

char *reverse_str(char const *path)
{
    char *new = NULL;
    int size = 0;
    int cp = 0;

    if (!path)
        return (NULL);
    for (size = 0; path[size]; size++);
    cp = size;
    new = malloc(sizeof(char) * (size + 1));
    for (int i = 0; size > 0; i++)
        new[i] = path[--size];
    new[cp] = '\0';
    return (new);
}

void number_of_digit(int nb, int *count)
{
    int copy = nb;

    while (copy > 0) {
        copy /= 10;
        *count += 1;
    }
    if (nb == 0)
        *count = 1;
}

char *transform_number_to_string(int nb)
{
    int count = 0;
    int k = 0;
    char *new = NULL;
    char *string = NULL;

    number_of_digit(nb, &count);
    string = malloc(sizeof(char) * (count + 1));
    for (int i = 0; i < count; i++) {
        string[k++] = nb % 10 + 48;
        nb /= 10;
    }
    string[k] = '\0';
    string = reverse_str(string);
    return (string);
}

int my_strncmp(char const *sa, char const *sb)
{
    return (!*sa || (*sa != *sb) ? (*sa - *sb) : my_strncmp(sa + 1, sb + 1));
}

char *copy_buffer_of_my_realloc(char *buffer, size_t size, char *second)
{
    char *new = malloc(size + 1);
    int i = 0;
    int j = 0;

    if (!new)
        return (NULL);
    while (buffer && buffer[i] && i < size) {
        new[i] = buffer[i];
        i++;
    }
    while (second && second[j] && i < size) {
        new[i] = second[j];
        i++;
        j++;
    }
    new[i] = '\0';
    free(buffer);
    return (new);
}
