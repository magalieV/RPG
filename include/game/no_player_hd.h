/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** __DESCRIPTION__
*/

#ifndef NO_PLAYER_HEADERR
#define NO_PLAYER_HEADERR

enum is_required {optionnal, required, no_required};
enum value_default {none, all};

quest_enum_t const ALL_DEF[] = {
    {required, "##NEW_PNG", 1, none},
    {required, "##LEVEL", 2, none},
    {optionnal, "##POS", 2, none},
    {no_required, "##NEW_QUEST", 0, none},
    {required, "##PLAYER_ID", 1, all},
    {optionnal, "##ELEMENT", -2, none},
    {optionnal, "##ITEM", -2, none},
    {required, "##STATUS", 1, none},
    {required, "##QUEST_ID", 1, none},
    {required, "##XP", 1, none},
    {required, "##CONTENT", 1, none},
    {0, NULL, 0, 0},
};

#endif
