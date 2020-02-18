/*
** EPITECH PROJECT, 2018
** my_screensaver
** File description:
** Return a positive number.
*/

double get_pos(double number)
{
    if (number < 0)
        number *= -1;

    return (number);
}
