/*
** EPITECH PROJECT, 2018
** event_of_game
** File description:
** Implementation of event_of_game
*/

#include "my_rpg_hd.h"

static bool interaction_drop(sfVector2f posi, char **pixel_tab,
    linked_list_t **list, window_t *window)
{
    if (search_inter('6', pixel_tab, *window, posi)) {
        *list = add_item(*list, BLUE);
        return (true);
    }
    if (search_inter('7', pixel_tab, *window, posi)) {
        *list = add_item(*list, RED);
        return (true);
    }
    if (search_inter('8', pixel_tab, *window, posi)) {
        *list = add_item(*list, PURPLE);
        return (true);
    }
    if (search_inter('9', pixel_tab, *window, posi)) {
        *list = add_item(*list, YELLOW);
        return (true);
    }
    return (false);
}

static bool different_action(window_t *window, sfVector2f posi, game_t *gm,
    int *nb_gate)
{
    *nb_gate = moove_word(gm->back.pixel_tab, *window, posi);
    gm->test = button_is_click(window->event, gm->element.quest, *window);
    if (window->event.type == sfEvtKeyPressed
    && window->event.key.code == sfKeyReturn) {
        gm->test = -1;
        return (true);
    }
    if (*nb_gate == -2)
        return (true);
    return (false);
}

static bool change_player(back_t *back, window_t *window)
{
    if (window->event.type == sfEvtKeyPressed && window->event.key.code == sfKeyTab) {
        if (back->id_player == 3)
            back->id_player = 0;
        else
            back->id_player += 1;
        return (true);
    }
    return (false);
}

static bool moove_picture(window_t *window, game_t *gm,
    animation_t *gate, monster_t *monster)
{
    if (window->event.type == sfEvtKeyPressed
    && collision(window->event.key.code, &gm->back.x, &gm->back.y, gm->back.pixel_tab)) {
        gm->back.back = moove_back(window->event.key.code, gm->back.back,
        &gm->back.player->player);
        for (int i = 0; (gm->png)[i].png.object.sprite; i++)
            moove_anim(&(gm->png)[i].png, window->event.key.code);
        for (int i = 0; monster->little[i].object.sprite; i++)
            moove_anim(&monster->little[i], window->event.key.code);
        for (int i = 0; monster->medium[i].object.sprite; i++)
            moove_anim(&monster->medium[i], window->event.key.code);
        for (int i = 0; monster->hard[i].object.sprite; i++)
            moove_anim(&monster->hard[i], window->event.key.code);
        moove_anim(gate, window->event.key.code);
        gm->back.font = moove_tile(window->event.key.code, gm->back.font);
        display_animation(&gm->back.player[gm->back.id_player].player,
        window->event.key.code, *window, gm->back.pixel_tab);
        return (true);
    }
    return (false);
}

bool *event_game_loop(window_t *window, game_t *gm,
    animation_t *gate, linked_list_t **list)
{
    sfVector2f posi = {gm->back.x, gm->back.y};

    while (sfRenderWindow_pollEvent(window->window, &window->event)) {
        display_pause_menu(*window, gm->breaking, &gm->quit);
        gm->element.event_click = manage_inventory(*window, gm->back.button_game,
        gm->element.inventory, gm->element.event_click);
        gm->choice = action_with_png(gm->png, *window, posi, gm->back.pixel_tab,
        gm->choice, &gm->ch);
        if (interaction_drop(posi, gm->back.pixel_tab, list, window))
            return (gm->element.event_click);
        if (different_action(window, posi, gm, &gm->nb_gate))
            return (gm->element.event_click);
        gm->arr = button_is_click(window->event, gm->arrow, *window);
        if (change_player(&gm->back, window))
            return (gm->element.event_click);
        moove_picture(window, gm, gate, &gm->monster);
        return (gm->element.event_click);
    }
    return (gm->element.event_click);
}
