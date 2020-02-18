/*
** EPITECH PROJECT, 2018
** load_element
** File description:
** Implementation of load_element
*/


#ifndef MUL_MY_RPG_2018_LOAD_ELEMENT_H
#define MUL_MY_RPG_2018_LOAD_ELEMENT_H

back_t load_back_game(char const *, char const *, window_t, char const *);
object_t *load_back_ground(void);
int found_size_line(char const *str);
char **file_tab(int x, int y, int size_x, int size_y, char **tab, int c);
char **ini_pixel_tab(char **tab);
char *found_path(int c, char **size_tile, int *size);
char **found_info(char c, char **info_size);
char **create_pixel_tab(char const *map, char const *size, int x, int y);
object_t **create_tile_mapping(char const *map, char const *size_map, int x,
int y);


#endif //MUL_MY_RPG_2018_LOAD_ELEMENT_H
