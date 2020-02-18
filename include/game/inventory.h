/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** __DESCRIPTION__
*/

#ifndef INVENTORY_HEADER
#define INVENTORY_HEADER

bool *manage_inventory(window_t window, my_button_t *button,
my_button_t *inventory, bool *click_inv);
linked_list_t *add_new_item(linked_list_t *begin, int id_item);
linked_list_t *add_item(linked_list_t *list, int id_item);
linked_list_t *remove_item(linked_list_t *list, int id_item);
void display_item(my_button_t *button, linked_list_t *list, window_t);

#endif
