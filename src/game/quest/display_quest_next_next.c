/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** __DESCRIPTION__
*/

#include "my_rpg_hd.h"

my_button_t *init_rect(my_button_t *button, int k, sfVector2f pos)
{
    button[k].rect.top = pos.y;
    button[k].rect.left = pos.x;
    button[k].rect.height = 53;
    button[k].rect.width = 357;
    create_object(BUTTON_INSIDE_QUEST, 0, pos, &button[k].butt);
    button = init_function(k, button);
    return (button);
}

my_button_t *init_button_quest(char **quest)
{
    my_button_t *button = alloc_button(quest);
    my_button_t end = {0};
    int k = 0;
    char **tmp = NULL;
    sfVector2f add = {0};
    sfVector2f pos = {0};

    for (int i = 0; quest[i]; i++) {
        if (found_new_png(quest[i], 0, "##NEW_QUEST")) {
            tmp = my_str_to_word_array(quest[i + 5], "\n\t:");
            if (my_getnbr(tmp[1]) == 1) {
                1 ? pos.x = X_PRIMARY, pos.y = Y_SIZE_QUEST + add.x : 0;
                add.x += 73;
            } else {
                1 ? pos.x = X_SECOND, pos.y = Y_SIZE_QUEST + add.y : 0;
                add.y += 73;
            }
            1 ? button = init_rect(button, k, pos), k += 1 : 0;
        }
    }
    return (1 ? button[k] = end, button : 0);
}

void print_info_quest(int i, window_t window, png_t *png)
{
    int x = 0;
    int y = 0;
    int tot = 0;
    bool stop = false;
    int size = 0;

    for (x = 0; png[x].png.object.sprite; x++) {
        for (y = 0; png[x].quest[y].resume; y++) {
            if (png[x].quest[y].id_quest == i - 1) {
                stop = true;
                break;
            }
        }
        if (stop)
            break;
    }
    for (size = 0; png[x].quest[y].text[size]; size++);
    for (int e = 1; png[x].quest[y].text[e]; e++)
        display_texte(png[x].quest[y].text[e], 1920 / 2 - 400,
        1080 / 5 - (size / 2) + (e * 30), window, sfWhite, 25);
}

void display_button_quest(my_button_t *but, window_t wi, png_t *png)
{
    sfVector2i new = check_pos_mouse(wi.window);
    sfIntRect t = {0};
    int k = 0;
    int e = 0;

    for (int i = 0; but[i].butt.sprite; i++) {
        if (but[i].butt.vectf.y + but[i].rect.height < 277 + 526
        && but[i].butt.vectf.y >= Y_SIZE_QUEST) {
            if (sfIntRect_contains(&but[i].rect, new.x, new.y) == false) {
                1 ? t = but[i].rect, t.left = 0, t.top = 0 : 0;
                sfSprite_setTextureRect(but[i].butt.sprite, t);
            } else {
                1 ? t = but[i].rect, t.left = but[i].rect.width, t.top = 0 : 0;
                sfSprite_setTextureRect(but[i].butt.sprite, t);
            }
            but[i].butt.display(&but[i].butt, wi.window);
            1 ? display_texte(png[k].quest[e].resume, but[i].butt.vectf.x + 15,
            but[i].butt.vectf.y + 15, wi, sfWhite, 18), e += 1 : 0;
        }
        e >= png[k].size_quest ? e = 0, k += 1 : 0;
    }
}
