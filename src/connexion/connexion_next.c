/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** __Window : connexion | Use : event of the window | Status : In progress__
*/

#include "my_rpg_hd.h"

void display_text(char const *str, int x, int y, window_t window)
{
    sfVector2f pos = {0};
    sfText *text = {0};
    sfFont *font = {0};
    sfVector2u screen = sfRenderWindow_getSize(window.window);

    pos.x = x * screen.x / 1920;
    pos.y = y * screen.y / 1080;
    font = sfFont_createFromFile("resources/font/connexion_font.otf");
    text = sfText_create();
    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 40);
    sfText_setPosition(text, pos);
    sfText_setColor(text, sfWhite);
    sfRenderWindow_drawText(window.window, text, NULL);
    sfText_destroy(text);
    sfFont_destroy(font);
}

bool fill_info_user(int op)
{
    write(op, "##Perso\n", 8);
    write(op, "##Inventaire\n", 13);
    write(op, "##Quest\n", 8);
    write(op, "##Setting\n", 6);
}