/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** Change set a new color to a int[4].
*/

#include "../../../include/game/particles.h"

void set_color(int *RGBA, int r, int g, int b)
{
    RGBA[0] = r;
    RGBA[1] = g;
    RGBA[2] = b;
    RGBA[3] = 255;
}
