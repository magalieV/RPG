/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** __Window : Connexion | Use : Display | Status : in progress__
*/

#include "my_rpg_hd.h"

static void display_connection_text(window_t window)
{
    if (window.user.username)
        display_text(window.user.username, 340, 420, window);
    if (window.user.password)
        display_text(window.user.password, 1270, 420, window);
    if (window.warning)
        display_texte(window.warning, 700, 300, window, sfRed, 30);
}

bool user_want_connect(window_t window)
{
    sfVector2f pos = {0};
    object_t login = {0};
    char **tab = read_doub_file(BUTTON_CONNECT, "\n");
    my_button_t *button = create_my_button(tab, button, window);

    create_object(BACK_CONNECT, 0, pos, &login);
    while (sfRenderWindow_isOpen(window.window)) {
        sfRenderWindow_display(window.window);
        if (loop_event_connexion(&window, button))
            break;
        if (button->is_click(window.event, button, window) == 2)
            break;
        login.display(&login, window.window);
        button->display(window, button);
        display_connection_text(window);
    }
    1 ? button->destroy(button), main_menu(window): 0;
    return (true);
}
