/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** __Window : connexion | Use : event of the window | Status : In progress__
*/

#include "my_rpg_hd.h"

static char *user_send_next(window_t *window, char *username, int size,
char *tmp)
{
    if (tmp[0] != 8 && tmp[0] != 13 && tmp[0] != 9) {
        if (username && size + 1 > 20)
            window->warning = my_strdup("Warning : to long username\n");
        if (size + 1 <= 20 && window->warning)
            1 ? free(window->warning), window->warning = NULL : 0;
        username = my_realloc(username, sizeof(char) * (size + 2), tmp);
    }
    return (username);
}

static char *user_send(sfEvent event, window_t *window, char *username)
{
    char *tmp = malloc(sizeof(char) * 2);
    int size = 0;

    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyBack) {
        size = (!username) ? 0 : my_strlen(username) - 1;
        if (size <= 20 && window->warning)
            1 ? free(window->warning), window->warning = NULL : 0;
        username = my_realloc(username, sizeof(char) * (size), NULL);
    } else if (event.type == sfEvtTextEntered) {
        1 ? tmp[0] = (char)event.text.unicode, tmp[1] = '\0' : 0;
        size = (!username) ? 0 : my_strlen(username) - 1;
        username = user_send_next(window, username, size, tmp);
    }
    free(tmp);
    return (username ? my_strdup(username) : username);
}

static void close_my_window(window_t *window)
{
    if (window->event.type == sfEvtKeyPressed
    && window->event.key.code == sfKeyEscape)
        sfRenderWindow_close(window->window);
    if (window->event.type == sfEvtClosed)
        sfRenderWindow_close(window->window);
}

static int pass_tab(window_t *window, int ok, sfVector2i connect, int nb_button)
{
    if (window->event.type == sfEvtKeyPressed
    && window->event.key.code == sfKeyTab) {
        if (ok == 0)
            ok = 1;
        else
            sfMouse_setPositionRenderWindow(connect, window->window);
    }
    if (nb_button == 4)
        ok = 0;
    else if (nb_button == 5)
        ok = 1;
    return (ok);
}

bool loop_event_connexion(window_t *wi, my_button_t *button)
{
    static int ok = 0;
    sfVector2i mouse = {0};
    sfVector2i connect = {630, 730};
    int nb_button = 0;

    mouse = check_pos_mouse(wi->window);
    while (sfRenderWindow_pollEvent(wi->window, &wi->event)) {
        nb_button = button_is_click(wi->event, button, *wi);
        close_my_window(wi);
        if (nb_button == 1 && account_exist(wi, true))
            return (true);
        if (nb_button == 3 && !account_exist(wi, false))
            register_new_user(wi);
        ok = pass_tab(wi, ok, connect, nb_button);
        if (ok == 0)
            wi->user.username = user_send(wi->event, wi, wi->user.username);
        else
            wi->user.password = user_send(wi->event, wi, wi->user.password);
        return (false);
    }
}
