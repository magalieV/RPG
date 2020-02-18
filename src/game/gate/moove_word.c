/*
** EPITECH PROJECT, 2018
** moove_word
** File description:
** Implementation of moove_word
*/

#include "my_rpg_hd.h"

static bool found_gate(sfVector2f player_pos, char **pixel_tab)
{
    int y = player_pos.y - (100 / 5);
    int x = 0;
    bool bolean = false;

    while (pixel_tab && pixel_tab[y] && y < player_pos.y + (100 / 5)) {
        x = player_pos.x - (100 / 5);
        while (pixel_tab[y][x] && x < player_pos.x + (100 / 5)) {
            if (pixel_tab[y][x] == 'P') {
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

int moove_word(char **pixel_tab, window_t window, sfVector2f player_pos)
{
    if (window.event.type == sfEvtKeyPressed
    && window.event.key.code == sfKeyE) {
        if (found_gate(player_pos, pixel_tab)) {
            return (-2);
        }
    }
    return (-1);
}
