/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** __DESCRIPTION__
*/

#include "my_rpg_hd.h"

fight_t end_fight(window_t *window, linked_list_t **list, back_t *back,
    fight_t fighter)
{
    (fighter.life <= 0) ? back->kill += 1 : 0;
    (fighter.life <= 0) ? window->stats.xp += 50 : 0;
    window->stats.life <= 0 ? window->stats.life = 10 : 0;
    back->player[back->id_player].player.object.vectf = fighter.save_player;
    sfSprite_setPosition(back->player[back->id_player].player.object.sprite,
    back->player[back->id_player].player.object.vectf);
    return (fighter);
}

fight_t part_on_fight(window_t *window, linked_list_t **list, back_t *back,
    fight_t fighter)
{
    sfRenderWindow_display(window->window);
    sfRenderWindow_clear(window->window, sfBlack);
    fighter.font.display(&fighter.font, window->window);
    display_inter(*window, fighter.monster, back, fighter.fight_monster,
    fighter.life);
    fighter.button->display(*window, fighter.button);
    return (fighter);
}

fight_t part_two_fight(window_t *window, linked_list_t **list, back_t *back,
    fight_t fighter)
{
    moove_monster_fight(&fighter.monster, &fighter.mvt, &fighter.fight_monster,
    &fighter.bol, &fighter.ini_mstr, fighter.mnstr);
    anim_fight(&fighter.bol, fighter.plar, &fighter.fight_player, back);
    if (fighter.life > 0) {
        touch_target(fighter.fight_player, fighter.monster, &fighter.life,
        *window);
        touch_target(fighter.fight_monster,
        back->player[back->id_player].player, &window->stats.life, *window);
    }
    return (fighter);
}

fight_t part_three_fight(window_t *window, linked_list_t **list, back_t *back,
    fight_t fighter)
{
    if (!fighter.bol) {
        fighter.fight_player.object.vectf.x =
        back->player[back->id_player].player.object.vectf.x;
        sfSprite_setPosition(fighter.fight_player.object.sprite,
        fighter.fight_player.object.vectf);
    }
    if (window->stats.life < 20)
        particles(window, &window->particles, 0);
    if (fighter.bol)
        fighter.fight_player.object.display(&fighter.fight_player.object,
        window->window);
    return (fighter);
}
