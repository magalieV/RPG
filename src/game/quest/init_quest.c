/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** __DESCRIPTION__
*/

#include "my_rpg_hd.h"
#include "game/no_player_hd.h"

char **add_png_to_quest(sfVector2f pos, char **tab)
{
    int x = pos.x / 5;
    int y = pos.y / 5;
    int i = y - 10;
    int j = 0;

    while (tab[i] && i < y + 10) {
        j = x - 20;
        while (tab[i][j] && j < x + 20) {
            tab[i][j] = '-';
            j++;
        }
        i++;
    }
    return (tab);
}

bool found_new_png(char *str, int i, char *macro)
{
    int k = 0;
    int size = my_strlen(macro);

    for (int j = i; str[j]; j++) {
        if (macro[k] && str[j] != macro[k])
            return (false);
        else if (!macro[k])
            break;
        k++;
    }
    if (k == size)
        return (true);
    return (false);
}

static int size_quest(char **quest)
{
    int size = 0;

    if (!quest)
        return (0);
    for (int i = 0; quest[i]; i++) {
        if (found_new_png(quest[i], 0, ALL_DEF[0].macro))
            size++;
    }
    return (size);
}

static void assign_number_quest(sfVector2f *size, sfVector2f *pos, char **tmp,
char *str)
{
    char **posi = NULL;

    size->x = my_getnbr(tmp[2]);
    size->y = my_getnbr(tmp[3]);
    posi = my_str_to_word_array(str, "\n:");
    pos->x = my_getnbr(posi[1]);
    pos->y = my_getnbr(posi[2]);
}

png_t *init_png(char **quest)
{
    int sizze = 0;
    png_t *my_png = NULL;
    char **tmp = NULL;
    sfVector2f pos = {0};
    sfVector2f size = {0};
    png_t end = {0};

    my_png = malloc(sizeof(png_t) * (size_quest(quest) + 1));
    for (int i = 0; i < sizze; i++)
        1 ? my_png[i].id = i, my_png[i].quest = NULL : 0;
    sizze = 0;
    for (int i = 0; quest[i]; i++) {
        if (found_new_png(quest[i], 0, ALL_DEF[0].macro)) {
            tmp = my_str_to_word_array(quest[i], ":\n");
            assign_number_quest(&size, &pos, tmp, quest[i + 2]);
            my_png[sizze].png = init_all_anim(tmp[1], size, pos,
            my_getnbr(tmp[4]));
            sizze++;
        }
    }
    my_png[sizze] = end;
    return (my_png);
}
