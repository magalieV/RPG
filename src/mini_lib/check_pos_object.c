/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** __Window : All | Use : check diff event | Status : In progress__
*/

#include "my_rpg_hd.h"

bool on_rect(sfIntRect rect, sfVector2i pos, int x, int y)
{
    if (x >= 0 && y >= 0) {
        rect.top = x;
        rect.height = y;
    }
    if (pos.x >= rect.left && pos.x <= rect.left + rect.top
        && pos.y >= rect.width && pos.y <= rect.width + rect.height)
        return (true);
    return (false);
}

sfVector2i check_pos_mouse(sfRenderWindow *window)
{
    sfVector2i pos = {0};
    sfVector2u test = {0};
    sfVector2i new = {0};

    test = sfRenderWindow_getSize(window);
    pos = sfMouse_getPositionRenderWindow(window);
    new.x = pos.x * 1920 / test.x;
    new.y = pos.y * 1080 / test.y;
    return (new);
}
