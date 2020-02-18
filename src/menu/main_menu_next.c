/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** __Window : None | Use : init struct window | Status : done__
*/

#include "my_rpg_hd.h"

void check_direction(window_t window, int direction)
{
    if (direction == 2 || direction == 5)
        main_settings(&window);
    sfMusic_stop(window.music.music_menu);
    if (direction == 1 || direction == 6) {
        window.particles.i = 0;
        main_game(window);
        sfSprite_destroy(window.particles.sprite);
        sfTexture_destroy(window.particles.texture);
    }
    if (direction == 3 || direction == 4)
        sfRenderWindow_close(window.window);
}