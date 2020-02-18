/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** __DESCRIPTION__
*/

#include "my_rpg_hd.h"

char *my_strdup(char *str)
{
    int size = my_strlen(str);
    char *new = malloc(sizeof(char) * (size + 1));
    int i = 0;

    if (size <= 0 || !new)
        return (NULL);
    for (i = 0; str[i]; i++)
        new[i] = str[i];
    new[i] = '\0';
    return (new);
}

char **my_tab_dup(char **tab)
{
    int size = my_tab_len(tab);
    char **new = malloc(sizeof(char *) * (size + 1));
    int i = 0;

    if (size <= 0 || !new)
        return (NULL);
    for (i = 0; tab[i]; i++)
        if ((new[i] = my_strdup(tab[i])) == NULL)
            return (NULL);
    new[i] = 0;
    return (new);
}
