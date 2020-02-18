/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** __DESCRIPTION__
*/

#include "my_rpg_hd.h"

animation_t moove_anim_fight(bool mvt, animation_t anim, sfVector2f init,
    bool *bol)
{
    if (mvt) {
        if (anim.object.vectf.x > 1920) {
            anim.object.vectf = init;
            *bol = false;
        }
        anim.object.vectf.x += 30;
        sfSprite_setPosition(anim.object.sprite, anim.object.vectf);
    } else {
        if (anim.object.vectf.x < 0)
            anim.object.vectf = init;
        anim.object.vectf.x -= 30;
        sfSprite_setPosition(anim.object.sprite, anim.object.vectf);
    }
    return (anim);
}

void display_inter(window_t window, animation_t monster, back_t *back,
    animation_t fight_monster, int life)
{
    if (life > 0) {
        display_all_anim(&monster, 0.10);
        monster.object.display(&monster.object, window.window);
        fight_monster.object.display(&fight_monster.object, window.window);
    }
    back->player[back->id_player].player.object.display(
    &back->player[back->id_player].player.object, window.window);
}

void moove_monster_fight(animation_t *monster, bool *mvt, animation_t *fight_monster,
    bool *pipi, sfVector2f *ini_mstr, sfClock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float speed = time.microseconds / 1000000.0;

    if (speed > 0.05) {
        *monster = moove_monster(monster, mvt);
        *fight_monster = moove_anim_fight(false, *fight_monster, *ini_mstr, pipi);
        sfClock_restart(clock);
        ini_mstr->y = monster->object.vectf.y;
    }
}

bool touch_target(animation_t anim, animation_t target, int *life,
    window_t window)
{
    float x = anim.object.vectf.x + (anim.object.rect.width / 2.0);
    float y = anim.object.vectf.y + (anim.object.rect.height / 2.0);

    if (x > target.object.vectf.x && y > target.object.vectf.y
    && x < target.object.vectf.x + target.object.rect.width
    && y < target.object.vectf.y + target.object.rect.height) {
        *life -= 1;
        display_texte("TOUCH", 1920 / 2, 1080 / 2, window, sfWhite, 30);
    }
}

void anim_fight(bool *pipi, sfClock *plar, animation_t *fight_player,
    back_t *back)
{
    sfTime time = sfClock_getElapsedTime(plar);
    float speed = time.microseconds / 1000000.0;

    if (*pipi && speed > 0.05) {
        *fight_player = moove_anim_fight(true, *fight_player,
        back->player[back->id_player].player.object.vectf, pipi);
        sfClock_restart(plar);
    }
}
