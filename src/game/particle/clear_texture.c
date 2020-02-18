/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** Apply the same color on all pixels. (clear screen)
*/

#include "../../../include/game/particles.h"

void clear_texture(sfUint8 *framebuffer)
{
    for (int i = 0; i < 1920 * 1080 - 1; i++) {
        framebuffer[0 + 4 * i] = 255;
        framebuffer[1 + 4 * i] = 255;
        framebuffer[2 + 4 * i] = 255;
        framebuffer[3 + 4 * i] = 0;
    }
}
