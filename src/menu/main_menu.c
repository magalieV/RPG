/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** __Window : None | Use : init struct window | Status : done__
*/

#include "my_rpg_hd.h"

static bool found_direction(int *direction, window_t window,
my_button_t *button)
{
    while (sfRenderWindow_pollEvent(window.window, &window.event)) {
        *direction = button_is_click(window.event, button, window);
        if (window.event.type == sfEvtKeyPressed
        && window.event.key.code == sfKeyEscape)
            sfRenderWindow_close(window.window);
        if (*direction)
            return (true);
    }
    return (false);
}

static void display_menu(window_t window, object_t menu, my_button_t *button)
{
    sfRenderWindow_display(window.window);
    sfRenderWindow_clear(window.window, sfBlack);
    sfRenderWindow_drawSprite(window.window, menu.sprite, NULL);
    display_button_menu(window, button);
}

void main_menu(window_t window)
{
    sfVector2f pos = {0};
    object_t menu = {0};
    char **tab = read_doub_file(MENU_BUTTON, "\n");
    my_button_t *button = create_my_button(tab, button, window);
    int direction = 0;

    if (!window.music.is_music) {
        sfMusic_play(window.music.music_menu);
        sfMusic_setLoop(window.music.music_menu, sfTrue);
        window.music.is_music = true;
    }
    create_object(BACK_MENU, 0, pos, &menu);
    while (sfRenderWindow_isOpen(window.window)) {
        display_menu(window, menu, button);
        if (found_direction(&direction, window, button))
            break;
    }
    destroy_my_button(button);
    check_direction(window, direction);
}

static int found_mirror(int i)
{
    int value = 0;

    if (i == 0)
        value = 5;
    if (i == 1)
        value = 4;
    if (i == 2)
        value = 3;
    if (i == 3)
        value = 2;
    if (i == 4)
        value = 1;
    return (value);
}

static void display_button_menu(window_t window, my_button_t *but)
{
    sfVector2i new = check_pos_mouse(window.window);
    sfIntRect tmp = {0};
    int temp = -1;
    int mir = 0;

    for (int i = 0; but[i].butt.sprite; i++) {
        if (sfIntRect_contains(&but[i].rect, new.x, new.y) == false) {
            1 ? tmp = but[i].rect, tmp.left = 0, tmp.top = 0 : 0;
            i != temp ? sfSprite_setTextureRect(but[i].butt.sprite, tmp) : 0;
            i != temp ? mir = found_mirror(i) : 0;
            i != temp ? sfSprite_setTextureRect(but[mir].butt.sprite, tmp) : 0;
        } else {
            1 ? tmp = but[i].rect, tmp.left = but[i].rect.width : 0;
            tmp.top = 0;
            sfSprite_setTextureRect(but[i].butt.sprite, tmp);
            1 ? mir = found_mirror(i), temp = mir : 0;
            sfSprite_setTextureRect(but[mir].butt.sprite, tmp);
        }
        but[i].butt.display(&but[i].butt, window.window);
        but[mir].butt.display(&but[mir].butt, window.window);
    }
}
