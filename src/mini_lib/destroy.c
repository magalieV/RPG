/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** __DESCRIPTION__
*/

#include "my_rpg_hd.h"

void destroy_multi_table(char **table)
{
    if (!table)
        return;
    for (int i = 0; table[i]; i++)
        free(table[i]);
    free(table);
}
