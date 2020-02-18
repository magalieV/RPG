/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** __Window : All | Use : Animation | __
*/

#include "my_rpg_hd.h"

bool collision(int mvt, int *x, int *y, char **pixel_tab)
{
    int tmp_x = *x;
    int tmp_y = *y;

    if (mvt == sfKeyUp)
        tmp_y -= 3;
    else if (mvt == sfKeyDown)
        tmp_y += 3;
    if (mvt == sfKeyLeft)
        tmp_x -= 3;
    else if (mvt == sfKeyRight)
        tmp_x += 3;
    if (tmp_y >= 0 && tmp_x >= 0 && pixel_tab[tmp_y][tmp_x] != '0')
        return (false);
    *x = tmp_x;
    *y = tmp_y;
    return (true);
}

int moove_anim(animation_t *anim, int mvt)
{
    switch (mvt) {
        case sfKeyUp:
            anim->object.vectf.y += MOOVE_BACK;
            break;
        case sfKeyDown:
            anim->object.vectf.y -= MOOVE_BACK;
            break;
        case sfKeyLeft:
            anim->object.vectf.x += MOOVE_BACK;
            break;
        case sfKeyRight:
            anim->object.vectf.x -= MOOVE_BACK;
            break;
        default:
            break;
    }
    sfSprite_setPosition(anim->object.sprite, anim->object.vectf);
}

int display_all_anim(animation_t *anim, float timing)
{
    sfTime time = {0};
    float speed = 0;

    time = sfClock_getElapsedTime(anim->clock);
    speed = time.microseconds / 1000000.0;
    if (speed > timing) {
        if (anim->save_repeat + 1 < anim->repeat) {
            anim->object.rect.left += anim->x;
            anim->save_repeat += 1;
        } else {
            anim->object.rect.left = 0;
            anim->save_repeat = 0;
        }
        sfClock_restart(anim->clock);
        sfSprite_setTextureRect(anim->object.sprite, anim->object.rect);
        return (1);
    }
}

static void moove_my_player(animation_t *anim, int mvt, bool *bol)
{
    switch (mvt) {
        case sfKeyUp:
            anim->object.rect.top = anim->y * 1;
            1 ? anim->coord.y -= MOOVE_BACK, *bol = true : 0;
            break;
        case sfKeyDown:
            anim->object.rect.top = 0;
            1 ? anim->coord.y += MOOVE_BACK, *bol = true : 0;
            break;
        case sfKeyRight:
            anim->object.rect.top = anim->y * 3;
            1 ? anim->coord.x += MOOVE_BACK, *bol = true : 0;
            break;
        case sfKeyLeft:
            anim->object.rect.top = anim->y * 2;
            1 ? anim->coord.x -= MOOVE_BACK, *bol = true : 0;
            break;
        default:
            break;
    }
}

int display_animation(animation_t *anim, int mvt, window_t window, char **pixel_tab)
{
    sfTime time = {0};
    float speed = 0;
    static int repeat = 0;
    bool bol = false;

    time = sfClock_getElapsedTime(anim->clock);
    speed = time.microseconds / 1000000.0;
    if (speed > 0.030) {
        moove_my_player(anim, mvt, &bol);
        if (repeat + 1 < anim->repeat && bol) {
            anim->object.rect.left += anim->x;
            repeat += 1;
        } else if (bol) {
            anim->object.rect.left = 0;
            repeat = 0;
        }
        if (bol) {
            sfClock_restart(anim->clock);
            sfSprite_setTextureRect(anim->object.sprite, anim->object.rect);
            return (1);
        }
    }
    return (0);
}
