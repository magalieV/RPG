/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** __DESCRIPTION__
*/

#include "my_rpg_hd.h"

object_t *load_back_ground(void)
{
    char **tab = read_doub_file(BACK_DIV, "\n");
    sfVector2f pos = {0};
    object_t *obj = NULL;
    object_t end = {0};
    int k = 0;

    if (!tab)
        return (NULL);
    obj = malloc(sizeof(object_t) * (my_getnbr(tab[0]) + 1));
    if (!obj)
        return (NULL);
    for (int i = 1; tab[i]; i++) {
        pos.x = my_getnbr(tab[i + 1]);
        pos.y = my_getnbr(tab[i + 2]);
        create_object(tab[i], 0, pos, &obj[k]);
        k++;
        i += 2;
    }
    obj[k] = end;
    return (obj);
}

int found_size_line(char const *str)
{
    int size = 0;

    if (!str)
        return (0);
    for (int i = 0; str[i]; i++) {
        if (str[i] != '.' && str[i] != '0')
            size++;
    }
    return (size);
}

char **file_tab(int x, int y, int size_x, int size_y, char **tab, int c)
{
    int i = y;
    int j = x;

    if (x == 0 && x + size_x == 0 && y == 0 && y + size_y == 0)
        return (tab);
    if (x > 7000 || y > 7000)
        return (tab);
    while (i < 0)
        i++;
    while (tab[i] && i < (y + size_y)) {
        j = x;
        if (i > 7000)
            break;
        while (j < 0)
            j++;
        while (tab[i][j] && j < (x + size_x)) {
            1 ? tab[i][j] = c, j += 1 : 0;
            if (j > 7000)
                return (tab);
        }
        i++;
    }
    return (tab);
}

char **ini_pixel_tab(char **tab)
{
    int j = 0;
    int i = 0;

    tab = malloc(sizeof(char *) * (10000 + 2));
    for (i = 0; i < 10000; i++) {
        tab[i] = malloc(sizeof(char) * (10000 + 2));
        for (j = 0; j < 10000; j++)
            tab[i][j] = '0';
        tab[i][j] = '\0';
    }
    tab[i] = 0;
    return (tab);
}

char *found_path(int c, char **size_tile, int *size)
{
    char **tmp = NULL;

    for (int i = 0; size_tile[i]; i++) {
        if (c == size_tile[i][0]) {
            tmp = my_str_to_word_array(size_tile[i], ":");
            *size = my_getnbr(tmp[5]);
            return (tmp[6]);
        }
    }
    *size = 0;
    return (NULL);
}