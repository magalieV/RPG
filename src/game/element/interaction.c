/*
** EPITECH PROJECT, 2018
** interaction
** File description:
** Implementation of interaction
*/

#include "my_rpg_hd.h"

static bool interact_is_ok(char inter, sfVector2f player_pos, char **pixel_tab)
{
    int y = player_pos.y - (100 / 5);
    int x = 0;
    bool bolean = false;

    while (pixel_tab && pixel_tab[y] && y < player_pos.y + (100 / 5)) {
        x = player_pos.x - (100 / 5);
        while (pixel_tab[y][x] && x < player_pos.x + (100 / 5)) {
            if (pixel_tab[y][x] == inter) {
                bolean = true;
                break;
            }
            x++;
        }
        if (bolean)
            break;
        y++;
    }
    return (bolean);
}

int search_inter(char inter, char **pixel_tab, window_t window,
sfVector2f player_pos)
{
    if (window.event.type == sfEvtKeyPressed
    && window.event.key.code == sfKeyE) {
        if (interact_is_ok(inter, player_pos, pixel_tab)) {
            return (1);
        }
    }
    return (0);
}
