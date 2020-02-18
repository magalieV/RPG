/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** __DESCRIPTION__
*/

#ifndef QUEST_HEADER
#define QUEST_HEADER

my_button_t *init_button_quest(char **quest);
void display_button_quest(my_button_t *button, window_t, png_t *);
png_t *fille_my_png(png_t *png, char **quest);
void display_texte(char const *str, int x, int y, window_t window,
sfColor color, int size);
int count_quest_for_png(char **quest, int i);
char **found_text(int number);
png_t *alloc_png(png_t *png, int *k, int *n, int temp);
png_t *add_diff_element_2(png_t *png, int *tab, char *str, char **tmp);
png_t *add_diff_element(png_t *png, int *tab, char *str, char **tmp);
png_t *fille_my_png(png_t *png, char **quest);
my_button_t *moove_button_quest(int mvt, my_button_t *button);
my_button_t *alloc_button(char **quest);
my_button_t *init_function(int k, my_button_t *button);
my_button_t *init_rect(my_button_t *button, int k, sfVector2f pos);
my_button_t *init_button_quest(char **quest);
void print_info_quest(int i, window_t window, png_t *png);
void display_button_quest(my_button_t *but, window_t wi, png_t *png);

#endif
