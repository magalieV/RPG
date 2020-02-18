/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** __Window : All | Use : button | Status : Done__
*/

#include "my_rpg_hd.h"/* code */

int button_is_click(sfEvent event, my_button_t *button, window_t wind)
{
    sfVector2i mouse = check_pos_mouse(wind.window);

    if (event.type == sfEvtMouseButtonPressed && \
        sfMouse_isButtonPressed(sfMouseLeft)) {
        for (int i = 0; button[i].butt.sprite; i++) {
            if (sfIntRect_contains(&button[i].rect, mouse.x, mouse.y))
                return (i + 1);
        }
    }
    return (0);
}

int assign_rect(char **tab, int i, sfIntRect *rect)
{
    if (!tab[i + 4] || !tab[i + 1] || !tab[i + 2] || !tab[i + 3])
        return (84);
    (*rect).left = my_getnbr(tab[i + 1]);
    (*rect).width = my_getnbr(tab[i + 3]);
    (*rect).top = my_getnbr(tab[i + 2]);
    (*rect).height = my_getnbr(tab[i + 4]);
}

my_button_t *create_my_button(char **tab, my_button_t *but, window_t window)
{
    sfVector2f vect = {0};
    my_button_t end = {0};
    int i = 0;
    int k = 0;
    sfVector2u screen = sfRenderWindow_getSize(window.window);

    if ((but = malloc(sizeof(my_button_t) * (my_getnbr(tab[0]) + 1))) == NULL)
        return (but->end = true, but);
    for (i = 1; tab[i]; i++) {
        vect.x = my_getnbr(tab[i + 1]) * screen.x / 1920;
        vect.y = my_getnbr(tab[i + 2]) * screen.y / 1080;
        if (create_object(tab[i], 0, vect, &but[k].butt) == -1
        || assign_rect(tab, i, &but[k].rect) == 84)
            return (but->end = true, but);
        but[k].is_click = &button_is_click;
        but[k].display = &display_button;
        but[k].destroy = &destroy_my_button;
        1 ? i += 4, k += 1 : 0;
    }
    but[k] = end;
    return (but->end = false, but);
}

void display_button(window_t window, my_button_t *butt)
{
    sfVector2i new = {0};
    sfIntRect tmp = {0};

    new = check_pos_mouse(window.window);
    for (int i = 0; butt[i].butt.sprite; i++) {
        if (sfIntRect_contains(&butt[i].rect, new.x, new.y) == false) {
            tmp = butt[i].rect;
            tmp.left = 0;
            tmp.top = 0;
            sfSprite_setTextureRect(butt[i].butt.sprite, tmp);
        } else {
            tmp = butt[i].rect;
            tmp.left = butt[i].rect.width;
            tmp.top = 0;
            sfSprite_setTextureRect(butt[i].butt.sprite, tmp);
        }
        butt[i].butt.display(&butt[i].butt, window.window);
    }
}

void destroy_my_button(my_button_t *button)
{
    for (int i = 0; button[i].rect.top; i++)
        destroy_object(&button[i].butt);
    free(button);
}
