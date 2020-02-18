/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** __Window : All | Use : Init Animation | Status : Done__
*/

#include "my_rpg_hd.h"

animation_t init_all_anim(char const *path, sfVector2f size,
sfVector2f pos, int repeat)
{
    animation_t anim = {0};

    anim.clock = sfClock_create();
    pos.x -= size.x;
    pos.y -= size.y;
    create_object(path, 0, pos, &anim.object);
    anim.x = size.x;
    anim.y = size.y;
    anim.repeat = repeat,
    anim.object.rect.top = 0;
    anim.object.rect.left = 0;
    anim.object.rect.width = anim.x;
    anim.object.rect.height = anim.y;
    sfSprite_setTextureRect(anim.object.sprite, anim.object.rect);
    anim.vector_x = pos.x / 5;
    anim.vector_y = pos.y / 5;
    anim.coord.x = pos.x;
    anim.coord.y = pos.y;
    return (anim);
}

animation_t init_animation(char const *path, window_t window)
{
    char **tab = read_doub_file(path, "\n");
    animation_t an = {0};
    sfVector2f pos = {0};
    sfVector2u screen = sfRenderWindow_getSize(window.window);

    if (!tab)
        return (an);
    pos.x = screen.x / 2 - my_getnbr(tab[2]) / 2;
    pos.y = screen.y / 2 - my_getnbr(tab[3]) / 2;
    create_object(tab[1], 0, pos, &an.object);
    an.clock = sfClock_create();
    1 ? an.x = my_getnbr(tab[2]), an.y = my_getnbr(tab[3]) : 0;
    an.repeat = my_getnbr(tab[0]);
    1 ? an.object.rect.top = an.y, an.object.rect.left = 0 : 0;
    1 ? an.object.rect.width = an.x, an.object.rect.height = an.y : 0;
    sfSprite_setTextureRect(an.object.sprite, an.object.rect);
    an.vector_x = (screen.x / 2) / 5;
    an.vector_y = (screen.y / 2 + 80) / 5;
    an.save_repeat = 0;
    1 ? an.coord.x = (screen.x / 2), an.coord.y = (screen.y / 2 + 80) : 0;
    return (an);
}
