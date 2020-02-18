/*
** EPITECH PROJECT, 2018
** item_hd
** File description:
** Implementation of item_hd
*/

#ifndef MUL_MY_RPG_2018_ITEM_HD_H
#define MUL_MY_RPG_2018_ITEM_HD_H

typedef struct item_picture_s {
    char *path;
    int id;
} item_picture_t;

const item_picture_t ITEM_PICT[] = {
    {"resources/picture/game/inventory/1.png", 1},
    {"resources/picture/game/inventory/2.png", 2},
    {"resources/picture/game/inventory/3.png", 3},
    {"resources/picture/game/inventory/4.png", 4},
    {"resources/picture/game/inventory/5.png", 5},
    {"resources/picture/game/inventory/6.png", 6},
    {NULL, 0},
};

#endif //MUL_MY_RPG_2018_ITEM_HD_H
