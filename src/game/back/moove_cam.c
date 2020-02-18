/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** __DESCRIPTION__
*/

#include "my_rpg_hd.h"

object_t *moove_back(int moove, object_t *obj, animation_t *anim)
{
    for (int i = 0; obj[i].sprite; i++) {
        if (moove == sfKeyUp) {
            obj[i].vectf.y += MOOVE_BACK;
        } else if (moove == sfKeyDown) {
            obj[i].vectf.y -= MOOVE_BACK;
        }
        if (moove == sfKeyLeft) {
            obj[i].vectf.x += MOOVE_BACK;
        } else if (moove == sfKeyRight) {
            obj[i].vectf.x -= MOOVE_BACK;
        }
        sfSprite_setPosition(obj[i].sprite, obj[i].vectf);
    }
    return (obj);
}

sfVector2f moove_tile_next(int moove, object_t **obj, int i, int j)
{
    if (moove == sfKeyUp)
        obj[i][j].vectf.y += MOOVE_BACK;
    if (moove == sfKeyDown)
        obj[i][j].vectf.y -= MOOVE_BACK;
    if (moove == sfKeyLeft)
        obj[i][j].vectf.x += MOOVE_BACK;
    if (moove == sfKeyRight)
    obj[i][j].vectf.x -= MOOVE_BACK;
    sfSprite_setPosition(obj[i][j].sprite, obj[i][j].vectf);
    return (obj[i][j].vectf);
}

object_t **moove_tile(int moove, object_t **obj)
{
    for (int i = 0; obj[i]; i++) {
        for (int j = 0; obj[i][j].sprite; j++)
            obj[i][j].vectf = moove_tile_next(moove, obj, i, j);
    }
    return (obj);
}
