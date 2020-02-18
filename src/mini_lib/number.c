/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** __DESCRIPTION__
*/

#include "my_rpg_hd.h"

int my_strlen(char *str)
{
    int size = 0;

    while (str && str[size])
        size++;
    return (size);
}

int my_tab_len(char **tab)
{
    int size = 0;

    while (tab && tab[size])
        size++;
    return (size);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int number = 0;
    int a = 1;

    while (str && (str[i] == '-' || str[i] == '+')) {
        if (str[i] == '-')
            a *= -1;
        i++;
    }
    while (str && str[i] >= '0' && str[i] <= '9') {
        if (number == 214748364 && str[i] == 8 + 48 && a == -1 &&
            !(str[i + 1] < 58 && str[i + 1] > 47))
            return (-2147483648);
        else if ((number == 214748364 && str[i] > 7 + 48) ||
        number > 214748364)
            return (0);
        number *= 10;
        number += str[i] - 48;
        i++;
    }
    return (number * a);
}
