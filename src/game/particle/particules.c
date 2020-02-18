/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** screen saver.
*/

#include <SFML/Graphics.h>
#include <math.h>
#include <stdlib.h>
#include "../../../include/game/particles.h"

void draw_smooth(particules_t *, int);
int get_distance(int, int);

int particles(window_t *win, particules_t *particles, int color)
{
    particles->framebuffer = malloc(sizeof(sfUint8) * 1920 * 1080 * 4);
    particles->rgba = malloc(sizeof(int) * 4);

    if (color == 0)
        set_color(particles->rgba, 255, 0, 0);
    else
        set_color(particles->rgba, 0, 255, 0);

    clear_texture(particles->framebuffer);
    draw_smooth(particles, particles->i);
    sfTexture_updateFromPixels(win->particles.texture, \
    particles->framebuffer, 1920, 1080, 0, 0);
    sfSprite_setTexture(win->particles.sprite, win->particles.texture, 0);
    sfRenderWindow_drawSprite(win->window, \
    win->particles.sprite, 0);
    free(particles->rgba);
    free(particles->framebuffer);
    return (0);
}

void draw_smooth(particules_t *particules, int i)
{
    int bas_x = 1920 / 2;
    int bas_y = 1080 / 2;
    int ray = 30;

    for (int j = 0; j < i; j++)
        rand();
    for (int k = 0; k < 5; k++) {
        bas_x = 1920 / 2 + (rand() % 250 - 175);
        bas_y = 1080 / 2 + (rand() % 500 - 250 + 1);
        particules->bas_x = bas_x;
        particules->bas_y = bas_y;
        particules->i = i;
        particules->ray = ray;
        draw_smooth_next(particules);
    }
}

void draw_smooth_next(particules_t *particules)
{
    int x = 0;
    int y = 0;

    set_color(particules->rgba, particules->rgba[0], particules->rgba[1], \
    particules->rgba[2]);
    for (int j = 0; j < 500; j++) {
        x = rand() % particules->ray - particules->ray / 2;
        y = rand() % (particules->ray / (x != 0 ? my_pow(x, 2) / x : 1)) - \
        particules->ray / (x != 0 ? my_pow(x, 2) / x : 1) / 2;
        while (--x > particules->ray / 2);
        smooth_values(particules, &x, &y);
        set_color(particules->rgba, particules->rgba[0] + get_distance(x, y) / \
        particules->ray, particules->rgba[1] + \
        get_distance(x, y) / particules->ray, particules->rgba[2] + \
        get_distance(x, y) / particules->ray);
        draw_pixel(particules->framebuffer, particules->bas_x + x, \
        particules->bas_y + y, particules->rgba);
    }
}

void smooth_values(particules_t *particules, int *x, int *y)
{
    while (*x < -1 * (particules->ray / 2))
        *x += 1;
    while (*y > particules->ray / 2)
        *y -= 1;
    while (*y < -1 * (particules->ray / 2))
        *y += 1;
}

int get_distance(int x, int y)
{
    int distance = my_sqrt(my_pow(x, 2) + my_pow(y, 2), 1);

    return (distance);
}
