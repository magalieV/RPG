/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** __DESCRIPTION__
*/

#include "my_rpg_hd.h"

void moove_perso(int mvt, animation_t *anim)
{
    if (mvt == sfKeyUp && anim->object.vectf.y - MOOVE_BACK > 350)
        anim->object.vectf.y -= MOOVE_BACK;
    if (mvt == sfKeyDown && anim->object.vectf.y + MOOVE_BACK < 930)
        anim->object.vectf.y += MOOVE_BACK;
    if (sfKeyRight && anim->object.vectf.x + MOOVE_BACK < 1920)
        anim->object.vectf.x += MOOVE_BACK;
    if (sfKeyLeft && anim->object.vectf.x - MOOVE_BACK > 0)
        anim->object.vectf.x -= MOOVE_BACK;
    sfSprite_setPosition(anim->object.sprite, anim->object.vectf);
}

animation_t moove_monster(animation_t *monster, bool *up)
{
    if (monster->object.vectf.y - MOOVE_BACK < 350)
        *up = false;
    else if (monster->object.vectf.y + MOOVE_BACK > 930) {
        *up = true;
    }
    if (*up)
        monster->object.vectf.y -= MOOVE_BACK;
    else
        monster->object.vectf.y += MOOVE_BACK;
    sfSprite_setPosition(monster->object.sprite, monster->object.vectf);
    return (*monster);
}

void display_all_text(window_t *window, char *life_monster)
{
    display_texte("Monster life", 1600, 850, *window, sfWhite, 30);
    display_texte(life_monster, 1600, 900, *window, sfWhite, 30);
}
