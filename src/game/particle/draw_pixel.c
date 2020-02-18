/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** Draw a pixel.
*/

#include "../../../include/game/particles.h"

void draw_pixel(sfUint8 *framebuffer, int x, int y, int *RGBA)
{
    if (0 + 4 * (x + y * 1920) > 0 &&
    3 + 4 * (x + y * 1920) < 1920 * 1080 * 4) {
        framebuffer[0 + 4 * (x + y * 1920)] = RGBA[0];
        framebuffer[1 + 4 * (x + y * 1920)] = RGBA[1];
        framebuffer[2 + 4 * (x + y * 1920)] = RGBA[2];
        framebuffer[3 + 4 * (x + y * 1920)] = RGBA[3];
    }
}
