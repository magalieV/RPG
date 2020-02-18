/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** __Window : None | Use : init struct window | Status : done__
*/

#include "my_rpg_hd.h"
#include "item_hd.h"

bool *manage_inventory(window_t window, my_button_t *button,
my_button_t *inventory, bool *click_inv)
{
    int result = button_is_click(window.event, button, window);

    if (result == 0)
        return (click_inv);
    if (click_inv[result - 1] == false)
        click_inv[result - 1] = true;
    else
        click_inv[result - 1] = false;
    for (int i = 0; i < 3; i++) {
        if (i != result - 1)
            click_inv[i] = false;
    }
    return (click_inv);
}

linked_list_t *add_new_item(linked_list_t *begin, int id_item)
{
    linked_list_t *new_st = malloc(sizeof(linked_list_t));
    sfVector2f pos = {0};

    new_st->id_item = id_item;
    new_st->item_number = 1;
    new_st->next = NULL;
    for (int i = 0; ITEM_PICT[i].path; i++) {
        if (ITEM_PICT[i].id == id_item) {
            create_object(ITEM_PICT[i].path, 0, pos, &new_st->item);
        }
    }
    if (begin == NULL) {
        new_st->prev = NULL;
    } else {
        new_st->prev = begin;
        begin->next = new_st;
    }
    return (new_st);

}

linked_list_t *add_item(linked_list_t *list, int id_item)
{
    bool exist = false;

    while (list && list->prev)
        list = list->prev;
    while (list) {
        if (list->id_item == id_item) {
            exist = true;
            list->item_number += 1;
        }
        if (list-> next == NULL)
            break;
        list = list->next;
    }
    if (!exist) {
        list = add_new_item(list, id_item);
    }
    while (list && list->prev)
        list = list->prev;
    return (list);
}

linked_list_t *remove_item(linked_list_t *list, int id_item)
{
    bool exist = true;
    linked_list_t *after = NULL;
    linked_list_t *before = NULL;
    linked_list_t *node = NULL;

    while (list && list->prev && (list = list->prev));
    while (list) {
        if (list->id_item == id_item) {
            1 ? exist = false, after = list->next, before = list->prev : 0;
            node = list;
            break;
        }
        if (list->next == NULL)
            break;
        list = list->next;
    }
    if (list && !exist) {
        if (list->prev != NULL)
            list->prev->next = after;
        if (list->next != NULL)
            list->next->prev = before;
        if (!after && !before)
            list = NULL;
    }
    while (list && list->prev && (list = list->prev));
    return (list);
}

void display_item(my_button_t *button, linked_list_t *list, window_t window)
{
    sfVector2f pos = {0};
    char *number = NULL;

    while (list && list->prev)
        list = list->prev;
    for (int i = 0; button[i].butt.sprite; i++) {
        if (list) {
            pos.x = button[i].butt.vectf.x;
            pos.y = button[i].butt.vectf.y;
            sfSprite_setPosition(list->item.sprite, pos);
            list->item.display(&list->item, window.window);
            number = transform_number_to_string(list->item_number);
            display_texte(number, pos.x + 60, pos.y + 100, window, sfWhite, 20);
        }
        if (!list || !list->next)
            break;
        list = list->next;
    }
    while (list && list->prev)
        list = list->prev;
}
