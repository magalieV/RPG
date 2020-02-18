/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** __Window : None | Use : init struct window | Status : done__
*/

#include "my_rpg_hd.h"

static void display_setting_element(window_t *window, object_t settings,
my_button_t *button)
{
    sfRenderWindow_display(window->window);
    sfRenderWindow_clear(window->window, sfBlack);
    sfRenderWindow_drawSprite(window->window, settings.sprite, NULL);
    display_binding(window);
    display_button(*window, button);
}

void loop_setting_next(window_t *window, int *code, int *nbr_but)
{
    if (!check_same(window, *code))
        change_bind(window, *nbr_but, *code);
    *nbr_but = 0;
    *code = 0;
}

static bool loop_setting(window_t *window, int *code, int *nbr_but,
my_button_t *button)
{
    while (sfRenderWindow_pollEvent(window->window, &window->event)) {
        window->settings.sound = manage_sound(window, button);
        if (!*code)
            *code = recover_bind(window->event, window, button);
        if (*nbr_but = button_is_click(window->event, button, *window))
            loop_setting_next(window, code, nbr_but);
        sfMusic_setVolume(window->music.music_menu, window->settings.sound);
        if (window->event.type == sfEvtKeyPressed &&
        window->event.key.code == sfKeyEscape) {
            return (true);
        }
    }
    return (false);
}

void main_settings(window_t *window)
{
    sfVector2f pos = {0};
    object_t settings = {0};
    char **tab = read_doub_file(BUTTON_SETTING, "\n");
    my_button_t *button = create_my_button(tab, button, *window);
    bool is_break = false;
    bool is_click = false;
    int code = 0;
    int nbr_but = 0;

    create_object(FINAL_BACK_SETTING, 0, pos, &settings);
    button[0].rect.width = window->settings.sound * 10;
    while (sfRenderWindow_isOpen(window->window)) {
        display_setting_element(window, settings, button);
        if (loop_setting(window, &code, &nbr_but, button))
            break;
    }
    destroy_my_button(button);
    main_menu(*window);
}

static void display_my_setting(int key, int x, int y, window_t window)
{
    char *str = malloc(sizeof(char) * 2);
    char *left = "mouse left";
    char *right = "mouse right";

    str[0] = key + 97;
    str[1] = '\0';
    if (key == 0)
        display_text(left, x - 100, y, window);
    else if (key == 1)
        display_text(right, x - 100, y, window);
    else
        display_text(str, x, y, window);
}

static void display_binding(window_t *window)
{
    display_my_setting(window->settings.up, 600, 685, *window);
    display_my_setting(window->settings.right, 1535, 685, *window);
    display_my_setting(window->settings.down, 600, 814, *window);
    display_my_setting(window->settings.left, 1535, 814, *window);
    display_my_setting(window->settings.left_click, 600, 943, *window);
    display_my_setting(window->settings.right_click, 1535, 943, *window);
}

static void change_bind(window_t *window, int nbr_but, int code)
{
    if (nbr_but == 2)
        window->settings.up = code;
    if (nbr_but == 3)
        window->settings.right = code;
    if (nbr_but == 4)
        window->settings.down = code;
    if (nbr_but == 5)
        window->settings.left = code;
    if (nbr_but == 6)
        window->settings.left_click = code;
    if (nbr_but == 7)
        window->settings.right_click = code;
}

static int recover_bind(sfEvent event, window_t *window, my_button_t *but)
{
    int test = 0;

    if (event.type == sfEvtKeyPressed)
        test = event.key.code;
    return (test);
}

static int manage_sound(window_t *window, my_button_t *butt)
{
    sfVector2i new = {0};
    sfIntRect tmp = {0};

    new = check_pos_mouse(window->window);
    if (window->event.type == sfEvtMouseButtonPressed &&
    sfMouse_isButtonPressed(sfMouseLeft)) {
        if (new.y >= 96 && new.y <= 404 && new.x >= 590 && new.x <= 1650)
            new.x <= 620 ? butt[0].rect.width = 0 : new.x >= 1620 ?
            butt[0].rect.width = 1000 : (butt[0].rect.width = new.x - 620);
    }
    return (butt[0].rect.width / 10);
}

static int check_same(window_t *window, int code)
{
    if (code != window->settings.up && code != window->settings.right &&
    code != window->settings.down && code != window->settings.left && code
    != window->settings.left_click && code != window->settings.right_click)
        return (0);
    return (1);
}
