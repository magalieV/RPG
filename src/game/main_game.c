/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** __Window : None | Use : init struct window | Status : done__
*/

#include "my_rpg_hd.h"

bool end_of_game(int level, window_t window)
{
    object_t obj = {0};
    sfVector2f pos = {0};

    if (level < 5)
        return (true);
    create_object("resources/picture/game/end.png", 0, pos, &obj);
    while (sfRenderWindow_isOpen(window.window)) {
        sfRenderWindow_display(window.window);
        sfRenderWindow_clear(window.window, sfBlack);
        sfRenderWindow_drawSprite(window.window, obj.sprite, NULL);
        while (sfRenderWindow_pollEvent(window.window, &window.event)) {
            if (window.event.type == sfEvtClosed)
                sfRenderWindow_close(window.window);
            if (window.event.type == sfEvtKeyPressed
            && window.event.key.code == sfKeyEscape)
                sfRenderWindow_close(window.window);
        }
    }
    return (true);
}

void main_game(window_t window)
{
    int direction = 0;
    bool is_menu = false;

    window.music.is_music = false;
    window.particles.sprite = sfSprite_create();
    window.particles.texture = sfTexture_create(1920, 1080);
    sfMusic_setVolume(window.music.music_game, window.settings.sound / 2);
    sfMusic_play(window.music.music_game);
    sfMusic_setLoop(window.music.music_game, sfTrue);
    direction = load_game(window);
    direction == 1 ? init_stats(&window) : init_stats(&window);
    is_menu = display_back(window);
    sfMusic_stop(window.music.music_game);
    if (is_menu)
        main_menu(window);
}

static bool loop_load_game(window_t window, my_button_t *button)
{
    int direction = 0;

    while (sfRenderWindow_pollEvent(window.window, &window.event)) {
        direction = button_is_click(window.event, button, window);
        if (direction)
            return (true);
    }
    return (false);
}

int load_game(window_t window)
{
    sfVector2f pos = {0};
    object_t menu = {0};
    char **tab = read_doub_file(LOAD_GAME_BUTTON, "\n");
    my_button_t *button = create_my_button(tab, button, window);
    int direction = 0;
    bool is_break = false;

    create_object(FINAL_BACK_PLAY, 0, pos, &menu);
    while (sfRenderWindow_isOpen(window.window)) {
        sfRenderWindow_display(window.window);
        sfRenderWindow_clear(window.window, sfWhite);
        sfRenderWindow_drawSprite(window.window, menu.sprite, NULL);
        display_button(window, button);
        if (loop_load_game(window, button))
            break;
    }
    return (direction);
}

void init_stats(window_t *window)
{
    window->stats.life = 100;
    window->stats.stamina = 100;
    window->stats.strength = 1;
    window->stats.level = 1;
    window->stats.xp = 1;
}
