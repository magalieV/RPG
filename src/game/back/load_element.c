/*
** EPITECH PROJECT, 2018
** load_element
** File description:
** Implementation of load_element
*/

#include "my_rpg_hd.h"

animation_t *init_anim_random(int nb, const char *path, char **pixel_tab)
{
    char **tab = read_doub_file(path, "\n");
    animation_t *anim = malloc(sizeof(animation_t) * (nb + 1));
    animation_t end = {0};
    sfVector2f size = {0};
    sfVector2f pos = {0};
    int x = 0;
    int y = 0;
    int count = 0;

    1 ? size.x = my_getnbr(tab[4]), size.y = my_getnbr(tab[5]) : 0;
    for (int i = 0; i < nb; i++) {
        count = 0;
        do {
            1 ? x = rand() % 7000, y = rand() % 7000 : 0;
            count += 1;
        } while (pixel_tab[y][x] != '.' && count < 1000);
        1 ? pos.x = x, pos.y = y : 0;
        anim[i] = init_all_anim(tab[1], size, pos, my_getnbr(tab[0]));
    }
    anim[nb] = end;
    return (anim);
}

monster_t load_monster(window_t window, char **pixel_tab)
{
    monster_t monster = {0};
    char **tab = read_doub_file(NB_MONSTER, "\n");

    monster.nb_little = my_getnbr(tab[0]);
    monster.nb_medium = my_getnbr(tab[1]);
    monster.nb_hard = my_getnbr(tab[2]);
    monster.little = init_anim_random(monster.nb_little,
    MONSTER_LITTLE, pixel_tab);
    monster.xp_little = 10;
    monster.life_little = 80;
    monster.medium = init_anim_random(monster.nb_medium,
    MONSTER_MEDIUM, pixel_tab);
    monster.xp_medium = 25;
    monster.life_medium = 120;
    monster.hard = init_anim_random(monster.nb_hard,
    MONSTER_HARD, pixel_tab);
    monster.xp_hard = 50;
    monster.life_hard = 180;
    return (monster);
}

player_t *init_player(window_t window)
{
    player_t *player = malloc(sizeof(player_t) * 5);
    player_t end = {0};

    player[0].player = init_animation(PLAYER_1_WALK, window);
    player[0].coeff_life = 1;
    player[0].coeff_stamina = 1;
    player[0].coeff_attk = 1;
    player[1].player = init_animation(PLAYER_DUSTIN, window);
    player[1].coeff_life = 1.5;
    player[1].coeff_stamina = 0.5;
    player[1].coeff_attk = 1;
    player[2].player = init_animation(PLAYER_ELEVEN, window);
    player[2].coeff_life = 1;
    player[2].coeff_stamina = 0.3;
    player[2].coeff_attk = 2;
    player[3].player = init_animation(PLAYER_LUCAS, window);
    player[3].coeff_life = 1;
    player[3].coeff_stamina = 1.5;
    player[3].coeff_attk = 1;
    player[4] = end;
    return (player);
}

back_t load_back_game(char const *map, char const *path_button,
window_t window, char const *path_player)
{
    back_t back = {0};
    sfVector2u screen = sfRenderWindow_getSize(window.window);

    char **string_button = read_doub_file(path_button, "\n\t");
    back.player = init_player(window);
    back.map = read_doub_file(map, "\n\t");
    back.font = create_tile_mapping(MAP, SIZE_TILE, 300, 200);
    back.back = load_back_ground();
    back.button_game = create_my_button(string_button, back.button_game,
    window);
    back.pixel_tab = create_pixel_tab(MAP, SIZE_TILE, 300, 200);
    back.id_player = 0;
    back.x = (screen.x / 2) / 5;
    back.y = (screen.y / 2 + 80) / 5;
    back.kill = 0;
    return (back);
}

game_el_t load_elment_game(char const *button_inventory,
char const *back, char const *button_quest, window_t window)
{
    game_el_t element = {0};
    char **tab = read_doub_file(button_inventory, "\n");

    element.inventory = create_my_button(tab, element.inventory, window);
    element.back_elt = create_mutli_object(back, "\n", false);
    destroy_multi_table(tab);
    tab = read_doub_file(button_quest, "\n");
    element.quest = init_button_quest(tab);
    element.event_click = malloc(sizeof(bool) * 3);
    for (int i = 0; i < 3; i++)
        element.event_click[i] = false;
    return (element);
}
