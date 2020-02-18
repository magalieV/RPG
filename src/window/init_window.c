/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** __Window : None | Use : init struct window | Status : done__
*/

#include "my_rpg_hd.h"

void init_window(window_t *window)
{
    window->video_mode.width = 1920;
    window->video_mode.height = 1080;
    window->video_mode.bitsPerPixel = 32;
    window->window = sfRenderWindow_create(window->video_mode, "RPG",
    sfResize, NULL);
    sfRenderWindow_setFramerateLimit(window->window, 40);
}

void init_settings(settings_t *set)
{
    set->sound = 15;
    set->up = sfKeyZ;
    set->right = sfKeyD;
    set->down = sfKeyS;
    set->left = sfKeyQ;
    set->left_click = sfMouseLeft;
    set->right_click = sfMouseRight;
    set->interact = sfKeyE;
}

void set_music_game(music_t *music, window_t window)
{
    music->music_menu = sfMusic_createFromFile("resources/song/song_menu.ogg");
    sfMusic_setVolume(music->music_menu, window.settings.sound);
    window.music.is_music = false;
    music->music_game = sfMusic_createFromFile("resources/song/song_game.ogg");
    sfMusic_setVolume(music->music_game, window.settings.sound / 2);
    music->leef = sfMusic_createFromFile("resources/song/leef.ogg");
    sfMusic_setVolume(music->leef, window.settings.sound);
}
