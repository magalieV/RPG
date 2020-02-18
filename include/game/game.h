/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** __DESCRIPTION__
*/

#ifndef GAME_HEADER
#define GAME_HEADER

void main_game(window_t window);
bool display_back(window_t window);
int load_game(window_t window);
void init_stats(window_t *window);
object_t *moove_back(int moove, object_t *obj, animation_t *);
int display_animation(animation_t *anim, int mvt, window_t window, char **);
animation_t init_animation(char const *path, window_t);
char **create_pixel_tab(char const *, char const *, int , int);
char **ini_pixel_tab(char **tab);
bool collision(int mvt, int *x, int *y, char **pixel_tab);
int display_all_anim(animation_t *anim, float);
int moove_anim(animation_t *anim, int mvt);
char **add_png_to_quest(sfVector2f pos, char **tab);
bool found_new_png(char *str, int i, char *macro);
int assign_rect(char **tab, int i, sfIntRect *rect);
my_button_t *moove_button_quest(int mvt, my_button_t *button);
void display_stats(object_t bar, object_t life, object_t stamina,
object_t xp, window_t *window);
sfIntRect change_rect_stat(stats_t *stats, sfIntRect tmp, bool bol,
object_t obj, int value);
void display_texte(char const *str, int x, int y, window_t window,
sfColor color, int size);
int moove_word(char **pixel_char, window_t window, sfVector2f pos_player);
bool collision_tunnel(int mvt, int *x, int *y, char **pixel_tab);
void print_info_quest(int i, window_t window, png_t *png);
monster_t load_monster(window_t window, char **pixel_tab);

//DIALOGUE_QUEST_PNG

enum mvt {UP, DOWN, LEFT, RIGHT};

//EVENT_GAME
bool *event_game_loop(window_t *window, game_t *gm,
animation_t *gate, linked_list_t **list);
void open_interface(back_t *back, window_t *window, object_t *,
linked_list_t **);
game_t part_one(game_t gm, window_t *window, linked_list_t **);
game_t part_two(game_t gm, window_t *window, animation_t *game);
bool display_element(object_t **tile, back_t back, window_t window);
game_t part_three(game_t gm, window_t *window, linked_list_t **item,
bool *end);
game_t display_back_game(window_t window, game_t gm);
png_t *finish_quest(png_t *quest, linked_list_t **item, int *kill, int *xp);
bool end_game(png_t *quest);
bool end_of_game(int level, window_t window);
void anim_fight(bool *pipi, sfClock *plar, animation_t *fight_player,
back_t *back);
bool touch_target(animation_t anim, animation_t target, int *life,
window_t window);
void moove_monster_fight(animation_t *monster, bool *mvt,
animation_t *fight_monster,
bool *pipi, sfVector2f *ini_mstr, sfClock *clock);
void display_inter(window_t window, animation_t monster, back_t *back,
animation_t fight_monster, int life);
animation_t init_monster(int type, sfVector2f size, sfVector2f pos);
bool event_fight(window_t *window, back_t *back, fight_t *,
linked_list_t **list);
linked_list_t *remove_plant(window_t *window, linked_list_t *list);
animation_t moove_monster(animation_t *monster, bool *up);
void moove_perso(int mvt, animation_t *anim);
animation_t moove_anim_fight(bool mvt, animation_t anim, sfVector2f init,
bool *pipi);
fight_t part_on_fight(window_t *window, linked_list_t **list, back_t *back,
fight_t fighter);
fight_t part_two_fight(window_t *window, linked_list_t **list, back_t *back,
fight_t fighter);
fight_t part_three_fight(window_t *window, linked_list_t **list, back_t *back,
fight_t fighter);
fight_t end_fight(window_t *window, linked_list_t **list, back_t *back,
fight_t fighter);
void display_all_text(window_t *window, char *);

#endif
