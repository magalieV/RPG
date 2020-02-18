/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** __DESCRIPTION__
*/

#include "my_rpg_hd.h"

char **found_info(char c, char **info_size)
{
    char **tmp = NULL;

    for (int i = 0; info_size[i]; i++) {
        if (c == info_size[i][0]) {
            tmp = my_str_to_word_array(info_size[i], ":");
            return (tmp);
        }
    }
    return (NULL);
}

char **create_pixel_tab(char const *map, char const *size, int x, int y)
{
    char **tab = read_doub_file(map, "\n");
    char **pixel_tab = NULL;
    char **info_size = read_doub_file(size, "\n");
    char **tmp = NULL;

    pixel_tab = ini_pixel_tab(pixel_tab);
    if (!pixel_tab || !tab || !info_size)
        return (NULL);
    for (int i = 0; tab[i]; i++) {
        for (int j = 0; tab[i][j]; j++) {
            tmp = found_info(tab[i][j], info_size);
            tmp ? pixel_tab = file_tab(((j * x) + my_getnbr(tmp[1])) / 5,
            ((i * y) + my_getnbr(tmp[2])) / 5 - my_getnbr(tmp[5]) / 5,
            my_getnbr(tmp[3]) / 5, my_getnbr(tmp[4]) / 5, pixel_tab, tab[i][j])
            : 0;
        }
    }
    return (pixel_tab);
}

object_t **create_tile_mapping(char const *map, char const *size_map, int x,
int y)
{
    char **tab = read_doub_file(map, "\n");
    char **size_tile = read_doub_file(size_map, "\n");
    int size = 0;
    object_t **obj = NULL;
    object_t end_line = {0};
    sfVector2f pos = {0};
    int k = 0;
    int e = 0;
    char *path = NULL;
    int sizee = 0;

    for (size; tab[size]; size++);
    obj = malloc(sizeof(object_t *) * (size + 1));
    for (int i = 0; tab[i]; i++) {
        size = found_size_line(tab[i]);
        if (size != 0) {
            obj[e] = malloc(sizeof(object_t) * (size + 1));
            k = 0;
            for (int j = 0; tab[i][j]; j++) {
                if (tab[i][j] != '.' && tab[i][j] != '0') {
                    pos.x = j * x;
                    pos.y = i * y;
                    path = found_path(tab[i][j], size_tile, &sizee);
                    create_object_temp(path, 0, pos, &obj[e][k], 0, sizee);
                    k++;
                }
            }
            1 ? obj[e][k] = end_line, e += 1 : 0;
        }
    }
    obj[e] = 0;
    return (obj);
}
