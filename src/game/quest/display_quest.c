/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** __DESCRIPTION__
*/

#include "my_rpg_hd.h"

void display_texte(char const *str, int x, int y, window_t window, sfColor color,
int size)
{
    sfVector2f pos = {0};
    sfText *text = {0};
    sfFont *font = {0};

    pos.x = x;
    pos.y = y;
    font = sfFont_createFromFile("resources/font/connexion_font.otf");
    text = sfText_create();
    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, size);
    sfText_setPosition(text, pos);
    sfText_setColor(text, color);
    sfRenderWindow_drawText(window.window, text, NULL);
    sfText_destroy(text);
    sfFont_destroy(font);
}

int count_quest_for_png(char **quest, int i)
{
    int size = 0;

    while (quest[i] && !found_new_png(quest[i], 0, "##NEW_PNG")) {
        if (found_new_png(quest[i], 0, "##NEW_QUEST"))
            size++;
        i++;
    }
    return (size);
}

char **found_text(int number)
{
    char **tab = read_doub_file(TEXT_CONTENT, "\n");
    char **tmp = NULL;

    for (int i = 0; tab[i]; i++) {
        if (my_getnbr(tab[i]) == number) {
            tmp = my_str_to_word_array(tab[i], ":\t\n");
            break;
        }
    }
    return (my_tab_dup(tmp));
}

png_t *alloc_png(png_t *png, int *k, int *n, int temp)
{
    *k += 1;
    png[*k].quest = malloc(sizeof(quest_t) * (temp));
    png[*k].size_quest = 0;
    png[*k].id = *k;
    *n = 0;
    return (png);
}

png_t *add_diff_element_2(png_t *png, int *tab, char *str, char **tmp)
{
    int k = tab[0];
    int n = tab[1];

    if (found_new_png(str, 0, "##POS")) {
        if (my_strncmp(tmp[1], "None") == 0) {
            1 ? png[k].quest[n].pos.x = 0, png[k].quest[n].pos.y = 0 : 0;
        } else {
            png[k].quest[n].pos.x = my_getnbr(tmp[1]);
            png[k].quest[n].pos.y = my_getnbr(tmp[2]);
        }
    }
    if (found_new_png(str, 0, "##ITEM")) {
        png[k].quest[n].element = my_getnbr(tmp[1]);
    }
    if (found_new_png(str, 0, "##ELEMENT"))
        png[k].quest[n].nb_element = my_getnbr(tmp[1]);
    if (found_new_png(str, 0, "##XP"))
        png[k].quest[n].xp = my_getnbr(tmp[1]);
    if (found_new_png(str, 0, "##QUEST_ID"))
        png[k].quest[n].text = found_text(my_getnbr(tmp[1]));
    return (png);
}