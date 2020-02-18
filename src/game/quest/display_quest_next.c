/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** __DESCRIPTION__
*/

#include "my_rpg_hd.h"

png_t *add_diff_element(png_t *png, int *tab, char *str, char **tmp)
{
    int k = tab[0];
    int n = tab[1];

    if (found_new_png(str, 0, "##PLAYER_ID")) {
        if (my_strncmp(tmp[1], "ALL") == 0) {
            png[k].quest[n].id_player = -1;
        } else
            png[k].quest[n].id_player = my_getnbr(tmp[1]);
    }
    if (found_new_png(str, 0, "##STATUS")) {
        if (my_strncmp(tmp[1], "1") == 0)
            png[k].quest[n].principal = true;
        else
            png[k].quest[n].principal = false;
    }
    png = add_diff_element_2(png, tab, str, tmp);
    return (png);
}

png_t *fille_my_png(png_t *png, char **quest)
{
    int k = -1;
    int n = 0;
    char **tmp = NULL;
    int id = 0;
    int size = my_tab_len(quest);
    png_t end = {0};
    int *tab = malloc(sizeof(int) * 3);

    for (int i = 0; quest[i]; i++) {
        (found_new_png(quest[i], 0, "##NEW_PNG") && (i + 1 < size)) ?
        png = alloc_png(png, &k, &n,
        count_quest_for_png(quest, i + 1) + 1) : 0;
        tmp = my_str_to_word_array(quest[i], "\n:\t");
        if (found_new_png(quest[i], 0, "##CONTENT")) {
            png[k].quest[n].resume = (tmp[1]) ? my_strdup(tmp[1]) : NULL;
            1 ? png[k].quest[n].finish = false, png[k].size_quest += 1 : 0;
            1 ? png[k].quest[n].id_quest = id, id += 1, n += 1 : 0;
        }
        1 ? tab[0] = k, tab[1] = n : 0;
        png = add_diff_element(png, tab, quest[i], tmp);
    }
    return (1 ? png[++k] = end, png : 0);
}

my_button_t *moove_button_quest(int mvt, my_button_t *button)
{
    int size = 0;

    for (size = 0; button[size].butt.sprite; size++);
    for (int i = 0; button[i].butt.sprite; i++) {
        if (mvt == 1) {
            button[i].rect.top += 20;
            button[i].butt.vectf.y += 20;
            sfSprite_setPosition(button[i].butt.sprite, button[i].butt.vectf);
        } else if (mvt == 2) {
            button[i].rect.top -= 20;
            button[i].butt.vectf.y -= 20;
            sfSprite_setPosition(button[i].butt.sprite, button[i].butt.vectf);
        }
    }
    return (button);
}

my_button_t *alloc_button(char **quest)
{
    my_button_t *button = NULL;
    int size = 0;

    if (!quest)
        return (0);
    for (int i = 0; quest[i]; i++) {
        if (found_new_png(quest[i], 0, "##NEW_QUEST"))
            size++;
    }
    button = malloc(sizeof(my_button_t) * (size + 1));
    return (button);
}

my_button_t *init_function(int k, my_button_t *button)
{
    button[k].is_click = &button_is_click;
    button[k].display = &display_button;
    button[k].destroy = &destroy_my_button;
    return (button);
}
