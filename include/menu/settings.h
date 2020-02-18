/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** __DESCRIPTION__
*/

#ifndef SETTINGS_HEADER
#define SETTINGS_HEADER

void main_settings(window_t *window);
static int manage_sound(window_t *window, my_button_t *butt);
static int recover_bind(sfEvent event, window_t *window, my_button_t *but);
static void change_bind(window_t *window, int nbr_but, int code);
static void display_binding(window_t *window);
static int check_same(window_t *window, int code);

#endif