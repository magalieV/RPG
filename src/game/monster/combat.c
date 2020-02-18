/*
** EPITECH PROJECT, 2018
** combat
** File description:
** Implementation of combat
*/

#include "my_rpg_hd.h"

linked_list_t *remove_plant(window_t *window, linked_list_t *list)
{
    while (list && list->prev && (list = list->prev));
    while (list && (window->stats.life < 100 || window->stats.stamina < 100)) {
        if (list && (list->id_item == RED || list->id_item == YELLOW)
        && list->item_number > 0 && window->stats.life < 100) {
            1 ? list->item_number -= 1, window->stats.life += 20 : 0;
        }
        if (list && (list->id_item == PURPLE || list->id_item == BLUE)
        && list->item_number > 0 && window->stats.stamina < 100) {
            list->item_number -= 1;
            window->stats.stamina += 20;
        }
        if (list && list->item_number == 0) {
            list = remove_item(list, list->id_item);
            break;
        }
        if (!list || !list->next)
            break;
        list = list->next;
    }
    while (list && list->prev && (list = list->prev));
    return (list);
}

bool event_fight(window_t *wi, back_t *bk, fight_t *fighter,
    linked_list_t **list)
{
    int value = 0;

    while (sfRenderWindow_pollEvent(wi->window, &wi->event)) {
        value = button_is_click(wi->event, fighter->button, *wi);
        if (wi->event.type == sfEvtClosed)
            sfRenderWindow_close(wi->window);
        if (value == 1) {
            *list = remove_plant(wi, *list);
            return (false);
        }
        if (value == 3)
            return (true);
        if (value == 2 && fighter->bol == false && wi->stats.stamina - 10 > 0)
            1 ? fighter->bol = true, wi->stats.stamina -= 10 : 0;
        if (wi->event.type == sfEvtKeyPressed) {
            display_animation(&bk->player[bk->id_player].player,
            wi->event.key.code, *wi, NULL);
            moove_perso(wi->event.key.code, &bk->player[bk->id_player].player);
        }
    }
    return (false);
}

animation_t init_monster(int type, sfVector2f size, sfVector2f pos)
{
    animation_t monster = {0};

    type = rand() % 3;
    if (type == 0)
        monster = init_all_anim(LITTLE_MONST, size, pos, 8);
    else if (type == 1)
        monster = init_all_anim(MEDIUM_MONST, size, pos, 8);
    else
        monster = init_all_anim(HARD_MONST, size, pos, 8);
    return (monster);
}

fight_t init_fighter(back_t *back, window_t *window)
{
    fight_t fight = {0};
    char **tab = read_doub_file(BUTTON_FIGHT, "\n");

    1 ? fight.pos.x = 1690, fight.pos.y = 690, fight.size.x = 300 : 0;
    1 ? fight.size.y = 300, fight.fight.x = 126, fight.fight.y = 300 : 0;
    1 ? fight.font_pos.x = 0, fight.font_pos.y = 0 : 0;
    create_object(BACK_FIGHT, 0, fight.font_pos, &fight.font);
    fight.monster = init_monster(0, fight.size, fight.pos);
    fight.fight_monster = init_all_anim(MONSTER_FIGHT, fight.fight,
    fight.pos, 6);
    fight.fight_player = init_all_anim(PLAYER_FIGHT, fight.fight,
    back->player[back->id_player].player.object.vectf, 6);
    fight.mnstr = sfClock_create();
    fight.plar = sfClock_create();
    1 ? fight.life = 100, fight.bol = false : 0;
    fight.ini_mstr.x = 1690 - 63;
    fight.ini_mstr.y = 690 - 300;
    fight.mvt = true;
    fight.save_player = back->player[back->id_player].player.object.vectf;
    fight.button = create_my_button(tab, fight.button, *window);
    return (fight);
}

void open_interface(back_t *back, window_t *window, object_t *stat,
    linked_list_t **list)
{
    fight_t fighter = init_fighter(back, window);
    char *life_monster = NULL;

    while (sfRenderWindow_isOpen(window->window)) {
        fighter = part_on_fight(window, list, back, fighter);
        if (event_fight(window, back, &fighter, list))
            break;
        fighter = part_two_fight(window, list, back, fighter);
        display_stats(stat[0], stat[1], stat[2], stat[3], window);
        life_monster = transform_number_to_string(fighter.life);
        display_all_text(window, life_monster);
        fighter = part_three_fight(window, list, back, fighter);
        (fighter.life <= 0) ? particles(window, &window->particles, 1),
        display_texte("YOU WIN!", 1920 / 2 - 200, 1080 / 2, *window,
        sfWhite, 30) : 0;
        if (window->stats.life <= 0) {
            window->stats.life = 0;
            break;
        }
    }
    fighter = end_fight(window, list, back, fighter);
}
