/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** __DESCRIPTION__
*/

#include "my_rpg_hd.h"

int main(void)
{
    window_t window = {0};

    srand(time(NULL));
    init_window(&window);
    init_settings(&window.settings);
    set_music_game(&window.music, window);
    user_want_connect(window);
    sfRenderWindow_close(window.window);
    sfMusic_destroy(window.music.music_menu);
    sfMusic_destroy(window.music.music_game);
    sfMusic_destroy(window.music.leef);
    return (0);
}
