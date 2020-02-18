/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** __WINDOW : Game | Use : do tile_mapping | Status : in progress__
*/

#include "my_rpg_hd.h"

static bool display_first_line(int y_perso, object_t **my_tile, back_t back,
    window_t window)
{
    if (y_perso < my_tile[0][0].vectf.y + my_tile[0][0].rect.height) {
        sfRenderWindow_drawSprite(window.window,
        back.player[back.id_player].player.object.sprite, NULL);
        return (false);
    }
    return (true);
}

static void set_size(object_t **my_tile, int *y_object_before,
    int *y_object_after, int i)
{
    if (my_tile[i + 1]) {
        *y_object_before = my_tile[i][0].vectf.y + (my_tile[i][0].rect.height);
        *y_object_after = my_tile[i + 1][0].vectf.y + (my_tile[i + 1][0].rect.height);
    }
}

bool display_element(object_t **tile, back_t back, window_t window)
{
    bool is_display = true;
    int y_object_before = 0;
    int y_object_after = 0;
    sfVector2u screen = sfRenderWindow_getSize(window.window);
    int y_perso = screen.y / 2 + 80;

    for (int i = 0; tile[i]; i++) {
        if (i == 0 && is_display)
            is_display = display_first_line(y_perso, tile, back, window);
        for (int j = 0; tile[i][j].sprite; j++)
            sfRenderWindow_drawSprite(window.window, tile[i][j].sprite, NULL);
        set_size(tile, &y_object_before, &y_object_after, i);
        if (y_perso >= y_object_before && tile[i + 1] && tile[i + 1][0].sprite
        && y_perso <= y_object_after && is_display) {
            1 ? is_display = false, sfRenderWindow_drawSprite(window.window,
            back.player[back.id_player].player.object.sprite, NULL) : 0;
        }
    }
    if (is_display == true)
        sfRenderWindow_drawSprite(window.window,
        back.player[back.id_player].player.object.sprite, NULL);
}

static void init_gate(back_t back, sfVector2f *pos)
{
    bool quit = false;

    for (int i = 0; back.map[i]; i++) {
        for (int j = 0; back.map[i][j]; j++) {
            if (back.map[i][j] == 'P') {
                pos->x = j * 300 + 300;
                pos->y = i * 200 + 300;
                quit = true;
                break;
            }
        }
        if (quit)
            break;
    }
}

bool found_item_on_inventory(linked_list_t **list, int item, int nb_item)
{
    bool found = false;

    while (*list && (*list)->prev)
        *list = (*list)->prev;
    while (*list) {
        if ((*list)->id_item == item && (*list)->item_number >= nb_item) {
            (*list)->item_number -= nb_item;
            if ((*list)->item_number < 0)
                *list = remove_item((*list), (*list)->id_item);
            found = true;
        }
        if (!(*list)->next)
            break;
        *list = (*list)->next;
    }
    while (*list && (*list)->prev)
        *list = (*list)->prev;
    return (found);
}

png_t *finish_quest(png_t *quest, linked_list_t **item, int *kill, int *xp)
{
    for (int i = 0; quest[i].png.object.sprite; i++) {
        for (int j = 0; j < quest[i].size_quest; j++) {
            if (quest[i].quest[j].finish == false
            && quest[i].quest[j].element != 7) {
                quest[i].quest[j].finish = found_item_on_inventory(item,
                quest[i].quest[j].element, quest[i].quest[j].nb_element);
                if (quest[i].quest[j].finish) {
                    *xp += quest[i].quest[j].xp;
                }
            } else if (quest[i].quest[j].finish == false
            && quest[i].quest[j].element == 7
            && *kill >= quest[i].quest[j].nb_element) {
                quest[i].quest[j].finish = true;
                *kill -= quest[i].quest[j].nb_element;
                *xp += quest[i].quest[j].xp;
            }
        }
    }
    return (quest);
}

bool end_game(png_t *quest)
{
    bool end = true;

    for (int i = 0; quest[i].png.object.sprite; i++) {
        for (int j = 0; j < quest[i].size_quest; j++) {
            if (quest[i].quest[j].finish == false)
                end = false;
        }
    }
    return (end);
}

game_t ini_game(window_t window)
{
    game_t game = {0};

    game.element = load_elment_game(BUTTON_INVENTORY, BACK_ELEMENT, BUTTON_QUEST, window);
    game.breaking = init_break_picture(BUTTON_BREAK, BACK_BREAK, window);
    game.choice = -1;
    game.ch = 0;
    game.test = 0;
    game.nb_gate = 0;
    game.quit = false;
    game.back = load_back_game(MAP, BUTTON_GAME, window, PLAYER_1_WALK);
    game.png = init_png(read_doub_file(PNG_QUEST, "\n\t"));
    game.monster = load_monster(window, game.back.pixel_tab);
    game.arrow = create_my_button(
    read_doub_file("resources/file/game/quest/button_arrow.txt", "\n"),
    game.arrow, window);
    game.stat_picture = create_mutli_object(STATS_PICTURE, "\n", true);
    game.real = true;
    game.press = -1;
    return (game);
}

game_t add_png_to_pixel(game_t gm)
{
    sfVector2f pixel_pos = {0};

    for (int i = 0; gm.png[i].png.object.sprite; i++) {
        pixel_pos = gm.png[i].png.object.vectf;
        1 ? pixel_pos.x += 145, pixel_pos.y += 220 : 0;
        gm.back.pixel_tab = add_png_to_quest(pixel_pos, gm.back.pixel_tab);
    }
    return (gm);
}

bool display_back(window_t window)
{
    game_t gm = ini_game(window);
    sfVector2f sz = {300, 300};
    sfVector2f ps = {0};
    animation_t gate = {0};
    linked_list_t *item = NULL;
    bool end_gam = false;

    init_gate(gm.back, &ps);
    gate = init_all_anim(GATE, sz, ps, 21);
    gm = add_png_to_pixel(gm);
    gm.png = fille_my_png(gm.png, read_doub_file(PNG_QUEST, "\n\t"));
    while (sfRenderWindow_isOpen(window.window)) {
        gm = display_back_game(window, gm);
        gm.element.event_click = event_game_loop(&window, &gm, &gate, &item);
        gm = part_one(gm, &window, &item);
        gm = part_two(gm, &window, &gate);
        gm = part_three(gm, &window, &item, &end_gam);
        if (window.stats.level >= 5 || gm.quit)
            break;
    }
    return (end_of_game(window.stats.level, window));
}
