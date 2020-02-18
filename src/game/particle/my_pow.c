/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** Move all pixels on Y Axis.
*/

#include "../../../include/game/particles.h"

int my_pow(double nb, short p)
{
    double result = nb;

    if (p == 0)
        return (1);
    if (p > 0) {
        while (p > 1) {
            result *= nb;
            p--;
        }
    } else {
        while (p < 1) {
            result /= nb;
            p++;
        }
    }
    return ((int)(result));
}
