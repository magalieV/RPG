/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** __DESCRIPTION__
*/

#ifndef MY_RPG_HEADER
#define MY_RPG_HEADER

#include "all_macro.h"
#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>

#include <stdbool.h>
#include <unistd.h>
#include <stddef.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structure_header.h"
#include "game/game.h"
/*File include*/
/*In folder : mini_lib*/
#include "mini_lib/alloc_memory_hd.h"
#include "mini_lib/object_hd.h"
/*End folder : mini_lib*/
/*In folder : window*/
#include "window/init_hd.h"
/*End folder : window*/
/*In folder : connexion*/
#include "connexion/connexion_hd.h"
/*End folder : connexion*/
/*In folder : menu/settings*/
#include "menu/settings.h"
#include "menu/menu.h"
/*End folder : menu*/
/*In folder : game*/
#include "game/inventory.h"
#include "load_element.h"
#include "display_element.h"
#include "game/pause_menu_hd.h"
#include "game/quest_hd.h"
/*End folder : game/inventory*/

animation_t init_all_anim(char const *path, sfVector2f size,
sfVector2f pos, int repeat);
png_t *init_png(char **quest);
void display_talk_sprite(int choice, png_t *png, window_t window);
int action_with_png(png_t *png, window_t window, sfVector2f player_pos,
char **pixel_tab, int, int *);
monster_t moove_animation_randomly(monster_t monster, char **pixel_tab,
sfClock **);
static bool interact_is_ok(char inter, sfVector2f player_pos,
char **pixel_tab);
int search_inter(char inter, char **pixel_tab, window_t window,
sfVector2f player_pos);

#endif
