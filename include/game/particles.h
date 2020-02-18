/*
** EPITECH PROJECT, 2018
** my_screensaver.h
** File description:
** Prototypes to include library
*/

#ifndef PART
#define PART
#include <math.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdbool.h>

typedef struct particules_s {
    int bas_x;
    int bas_y;
    int i;
    int ray;
    int *rgba;
    sfUint8 *framebuffer;
    sfTexture *texture;
    sfSprite *sprite;
} particules_t;

#include "../structure_header.h"

void draw_pixel(sfUint8 *, int, int, int *);
void set_texture_rgba(sfUint8 *, int, int, int);
void clear_texture(sfUint8 *);
void draw_pixel(sfUint8 *, int, int, int *);
void set_color(int *, int, int, int);
int my_pow(double, short);
int my_sqrt(double, double);
void copy_framebuffer(sfUint8 *, sfUint8 *);
void draw_smooth_next(particules_t *);
void smooth_values(particules_t *, int *, int *);
int particles(window_t *, particules_t *, int);
#endif
