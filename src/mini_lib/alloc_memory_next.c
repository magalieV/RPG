/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** __Window : None | Use : alloc memory | Status : 3 places__
*/

#include "my_rpg_hd.h"

char *copy_buffer_of_my_realloc(char *buffer, size_t size, char *);

char *my_realloc(char *type, size_t size, char *second)
{
    if (size == 0) {
        if (type != NULL) {
            free(type);
            type = NULL;
            return (type);
        }
    }
    type = copy_buffer_of_my_realloc(type, size, second);
    return (type);
}
