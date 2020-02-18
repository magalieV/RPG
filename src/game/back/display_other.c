/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** __DESCRIPTION__
*/

#include "my_rpg_hd.h"

game_t display_back_game(window_t window, game_t gm)
{
    sfRenderWindow_display(window.window);
    sfRenderWindow_clear(window.window, sfBlack);
    for (int i = 0; gm.back.back[i].sprite; i++)
        gm.back.back[i].display(&gm.back.back[i], window.window);
    return (gm);
}

void display_png(window_t window, png_t *my_png, bool real)
{
    for (int i = 0; my_png[i].png.object.sprite; i++) {
        display_all_anim(&my_png[i].png, 1.0);
        my_png[i].png.object.display(&my_png[i].png.object,
        window.window);
    }
}

game_t part_one(game_t gm, window_t *window, linked_list_t **item)
{
    gm.element.quest = moove_button_quest(gm.arr, gm.element.quest);
    (gm.test > 0) ? gm.press = gm.test : 0;
    (gm.test == -1) ? gm.press = -1 : 0;
    if (gm.nb_gate == -2)
        gm.real = (gm.real == true) ? false : true;
    gm.arr = 0;
    if (!gm.real)
        open_interface(&gm.back, window, gm.stat_picture, item);
    gm.real = true;
    gm.nb_gate = 0;
    display_png(*window, gm.png, gm.real);
    display_element(gm.back.font, gm.back, *window);
    return (gm);
}

game_t part_two(game_t gm, window_t *window, animation_t *gate)
{
    display_all_anim(gate, 0.10);
    sfRenderWindow_drawSprite(window->window, gate->object.sprite, NULL);
    display_stats(gm.stat_picture[0], gm.stat_picture[1], gm.stat_picture[2],
    gm.stat_picture[3], window);
    gm.back.button_game->display(*window, gm.back.button_game);
    if (gm.choice == 0) {
        display_talk_sprite(gm.ch, gm.png, *window);
    }
    display_element_game(gm.element, *window, gm.arrow, gm.png);
    if (gm.press != -1)
        print_info_quest(gm.press, *window, gm.png);
    return (gm);
}

game_t part_three(game_t gm, window_t *window, linked_list_t **item, bool *end)
{
    if (gm.element.event_click[0])
        display_item(gm.element.inventory, *item, *window);
    if (gm.choice == 0)
        gm.png = finish_quest(gm.png, item, &gm.back.kill, &window->stats.xp);
    *end = end_game(gm.png);
    return (gm);
}
