/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** __DESCRIPTION__
*/

#include "my_rpg_hd.h"

duo_t init_break_picture(char const *button, char const *font, window_t window)
{
    duo_t duo = {0};
    sfVector2f pos = {};
    char **tab = read_doub_file(button, "\n");

    duo.button = create_my_button(tab, duo.button, window);
    destroy_multi_table(tab);
    tab = read_doub_file(font, "\n");
    pos.x = my_getnbr(tab[1]);
    pos.y = my_getnbr(tab[2]);
    create_object(tab[0], 0, pos, &duo.font);
    return (duo);
}

bool action_break(window_t window, int action)
{
    if (action == 3)
        return (true);
    return (false);
}

bool pause_loop(window_t window, my_button_t *break_butt, bool *quit)
{
    int action = 0;

    while (sfRenderWindow_pollEvent(window.window, &window.event)) {
        if (window.event.type == sfEvtClosed) {
            sfRenderWindow_close(window.window);
            return (false);
        }
        if ((window.event.type == sfEvtKeyPressed && window.event.key.code ==
        sfKeyEscape) || (action =
        button_is_click(window.event, break_butt, window))) {
            *quit = action_break(window, action);
            return (false);
        }
    }
    return (true);
}

bool display_pause_menu(window_t window, duo_t breaking, bool *quit)
{
    bool bol = false;

    if ((window.event.type == sfEvtKeyPressed
    && window.event.key.code == sfKeyEscape)) {
        bol = true;
    }
    while (bol) {
        sfRenderWindow_display(window.window);
        breaking.font.display(&breaking.font, window.window);
        display_button(window, breaking.button);
        bol = pause_loop(window, breaking.button, quit);
    }
    return (quit);
}
