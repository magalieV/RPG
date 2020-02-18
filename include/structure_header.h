/*
** EPITECH PROJECT, 2018
** structure_header
** File description:
** Implementation of structure_header
*/

#include "game/particles.h"

#ifndef MUL_MY_RPG_2018_STRUCTURE_HEADER_H
#define MUL_MY_RPG_2018_STRUCTURE_HEADER_H

#ifndef READ_SIZE
#define READ_SIZE 128
#endif

#ifndef Y_SIZE_QUEST
#define Y_SIZE_QUEST 392
#endif

#ifndef X_PRIMARY
#define X_PRIMARY 540
#endif

#ifndef X_SECOND
#define X_SECOND 1032
#endif

enum item {YELLOW = 1, PURPLE = 2, RED = 3,
BLUE = 4, BATTERY = 5, LAMP = 6, MONSTER = 7};

typedef struct real_coord_s {
    float x;
    float y;
} real_coord_t;

typedef struct object {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfVector2f vectf;
    sfClock *clock;
    void (*display)(struct object *, sfRenderWindow *);
    void (*destroy)(struct object *);
} object_t;

typedef struct settings {
    int sound;
    int up;
    int right;
    int down;
    int left;
    int left_click;
    int right_click;
    int interact;
} settings_t;

typedef struct id_user {
    char *username;
    char *password;
    int id;
} id_user_t;

typedef struct music {
    sfMusic *music_menu;
    bool is_music;
    sfMusic *music_game;
    sfMusic *leef;
} music_t;

typedef struct stats {
    int life;
    int strength;
    int stamina;
    int xp;
    int level;
} stats_t;

typedef struct linked_list_s
{
    object_t item;
    int item_number;
    int id_item;
    struct linked_list_s *next;
    struct linked_list_s *prev;
} linked_list_t;

typedef struct window {
    sfRenderWindow *window;
    sfEvent event;
    sfVideoMode video_mode;
    id_user_t user;
    char *warning;
    settings_t settings;
    music_t music;
    stats_t stats;
    linked_list_t *list;
    particules_t particles;
} window_t;

typedef struct my_button_s {
    sfIntRect rect;
    object_t butt;
    bool end;
    int (*is_click)(sfEvent, struct my_button_s *, window_t);
    void (*display)(window_t, struct my_button_s *);
    void (*destroy)(struct my_button_s *);
} my_button_t;

typedef struct duo_s {
    my_button_t *button;
    object_t font;
} duo_t;

typedef struct game_el_s {
    my_button_t *inventory;
    object_t *back_elt;
    my_button_t *quest;
    bool *event_click;
} game_el_t;

typedef struct animation_s {
    sfClock *clock;
    object_t object;
    sfIntRect rect;
    int x;
    int y;
    int repeat;
    int vector_x;
    int vector_y;
    int save_repeat;
    real_coord_t coord;
} animation_t;

typedef struct player_s {
    float coeff_stamina;
    float coeff_life;
    float coeff_attk;
    animation_t player;
} player_t;

typedef struct monster_s {
    animation_t *little;
    int xp_little;
    int nb_little;
    int life_little;
    animation_t *medium;
    int xp_medium;
    int nb_medium;
    int life_medium;
    animation_t *hard;
    int xp_hard;
    int nb_hard;
    int life_hard;
} monster_t;

typedef struct back {
    object_t **font;
    object_t *back;
    int id_player;
    my_button_t *button_game;
    char **map;
    player_t *player;
    int x;
    int kill;
    int y;
    char **pixel_tab;
} back_t;

typedef struct quest_enum_s {
    int required;
    char *macro;
    int number_arg;
    int default_value;
} quest_enum_t;

typedef struct quest_s {
    char **text;
    sfVector2f pos;
    int id_player;
    bool principal;
    int xp;
    int element;
    int nb_element;
    char *resume;
    int *advanced;
    int id_quest;
    bool finish;
} quest_t;

typedef struct png_s {
    animation_t png;
    int id;
    int level[2];
    int size_quest;
    quest_t *quest;
} png_t;

typedef struct game_s {
    game_el_t element;
    duo_t breaking;
    int choice;
    int ch;
    int test;
    int arr;
    int nb_gate;
    bool quit;
    back_t back;
    png_t *png;
    monster_t monster;
    my_button_t *arrow;
    object_t *stat_picture;
    bool real;
    int press;
} game_t;

typedef struct fight_s {
    sfVector2f pos;
    sfVector2f size;
    sfVector2f fight;
    object_t font;
    sfVector2f font_pos;
    animation_t monster;
    animation_t fight_monster;
    animation_t fight_player;
    sfClock *mnstr;
    sfClock *plar;
    int life;
    bool bol;
    sfVector2f ini_mstr;
    bool mvt;
    sfVector2f save_player;
    my_button_t *button;
} fight_t;

#endif //MUL_MY_RPG_2018_STRUCTURE_HEADER_H
