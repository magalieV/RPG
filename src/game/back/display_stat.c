/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** __DESCRIPTION__
*/

#include "my_rpg_hd.h"

void display_stats(object_t bar, object_t life, object_t stamina,
object_t xp, window_t *wi)
{
    sfIntRect tmp = life.rect;
    static int count = 0;
    char *temp = NULL;

    1 ? xp.rect.left = 0, xp.rect.top = 0 : 0;
    tmp = change_rect_stat(&wi->stats, tmp, false, life, wi->stats.life);
    sfSprite_setTextureRect(life.sprite, tmp);
    tmp = stamina.rect;
    tmp = change_rect_stat(&wi->stats, tmp, false, stamina,
    wi->stats.stamina);
    sfSprite_setTextureRect(stamina.sprite, tmp);
    tmp = xp.rect;
    tmp = change_rect_stat(&wi->stats, tmp, true, xp, wi->stats.xp);
    sfSprite_setTextureRect(xp.sprite, tmp);
    bar.display(&bar, wi->window);
    xp.display(&xp, wi->window);
    life.display(&life, wi->window);
    stamina.display(&stamina, wi->window);
    temp = transform_number_to_string(wi->stats.level);
    display_texte(temp, bar.vectf.x + 250, bar.vectf.y + 40, *wi, sfBlack, 30);
}

sfIntRect change_rect_stat(stats_t *stats, sfIntRect tmp, bool bol,
object_t obj, int value)
{
    tmp.width = value * obj.rect.width / 100;
    if (stats->level == 5)
        tmp.top = obj.rect.top;
    if (tmp.width >= obj.rect.width) {
        tmp.width = obj.rect.width;
    }
    if (tmp.width < 0)
        tmp.width = 1;
    if (bol && value >= 99) {
        tmp.width -= obj.rect.width;
        stats->xp -= 100;
        stats->level += 1;
    }
    return (tmp);
}
