/*
** EPITECH PROJECT, 2018
** Task 05
** File description:
** Function that returns the square root of the
** number given as argument.
*/

double my_compute_square_root(double nb)
{
    double number = 0;
    double i = 0;

    while (number < nb) {
        i += 1;
        number = i * i;
    }
    if (i * i >= nb)
        return (i);
    else
        return (0);
}

int my_sqrt(double nb, double add)
{
    int number = 0;
    int i = 0;

    while (number < nb) {
        i += add;
        number = i * i;
    }
    if (i * i >= nb)
        return (i);
    else
        return (0);
}
