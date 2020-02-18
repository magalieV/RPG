/*
** EPITECH PROJECT, 2018
** display_element
** File description:
** Implementation of display_element
*/

#include "my_rpg_hd.h"

void display_element_game(game_el_t element, window_t window,
my_button_t *arrow, png_t *my_png)
{
    if (element.event_click[0]) {
        element.back_elt[0].display(&element.back_elt[0], window.window);
        element.inventory->display(window, element.inventory);
    }
    if (element.event_click[1]) {
        element.back_elt[1].display(&element.back_elt[1], window.window);
        display_button_quest(element.quest, window, my_png);
        arrow->display(window, arrow);
    }
}