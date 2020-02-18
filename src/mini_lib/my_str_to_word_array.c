/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** __ * Copyright © 2018 Magalie Vandenbriele. All rights reserved.__
*/

#include "my_rpg_hd.h"

int if_alphnum(char const *str, int i, char *param)
{
    if (!str[i])
        return (0);
    for (int j = 0; param[j]; j++) {
        if (param[j] == str[i])
            return (0);
    }
    return (1);
}

int alloc_memo(char const *str, char *param)
{
    int i = 0;
    int k = 0;

    while (str[i]) {
        if (if_alphnum(str, i, param) && !if_alphnum(str, i + 1, param))
            k++;
        i++;
    }
    return (k);
}

char **my_str_to_word_array(char const *str, char *param)
{
    char **dest;
    int i = 0;
    int g = 0;
    int n;

    dest = malloc(sizeof(char *) * (alloc_memo(str, param) + 1) + 1);
    while (str[g]) {
        if (!if_alphnum(str, g, param))
            g++;
        for (n = g; if_alphnum(str, n, param); n++);
        dest[i] = (char *)malloc((n - g) + 2);
        dest[i][0] = 0;
        for (n = 0; if_alphnum(str, g, param); n++)
            dest[i][n] = str[g++];
        dest[i][n] = '\0';
        if (dest[i][0])
            i++;
    }
    dest[i] = 0;
    return (dest);
}
