/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** Apply a color on all existants pixels.
*/

#include "../../../include/game/particles.h"

void set_texture_rgba(sfUint8 *framebuffer, int r, int g, int b)
{
    for (int i = 0; i < 1920 * 1080; i++)
        if (framebuffer[3 + 4 * i] != 0) {
            framebuffer[0 + 4 * i] = r;
            framebuffer[1 + 4 * i] = g;
            framebuffer[2 + 4 * i] = b;
            framebuffer[3 + 4 * i] = 255;
        }
}
