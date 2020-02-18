/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** __DESCRIPTION__
*/

#include "my_rpg_hd.h"

object_t *create_mutli_object(char const *path, char const *sepa, bool bolean)
{
    char **str = read_doub_file(path, sepa);
    object_t *object = malloc(sizeof(object_t) * (my_getnbr(str[0]) + 1));
    int n = 0;
    sfVector2f pos = {0};
    int x = 0;
    int y = 0;
    object_t end = {0};

    if (!object)
        return (NULL);
    for (int i = 1; str[i]; i++) {
        1 ? pos.x = my_getnbr(str[i + 1]), pos.y = my_getnbr(str[i + 2]) : 0;
        if (bolean) {
            1 ? x = my_getnbr(str[i + 3]), y = my_getnbr(str[i + 4]) : 0;
            create_object_temp(str[i], 0, pos, &object[n], x, y);
            i += 4;
        } else
            1 ? create_object(str[i], 0, pos, &object[n]), i += 2 : 0;
        n++;
    }
    return (1 ? object[n] = end, object : 0);
}

void display_object(object_t *object, sfRenderWindow *window)
{
    sfTime time = sfClock_getElapsedTime(object->clock);
    float speed = time.microseconds / 1000000.0;

    if (speed > 0.005) {
        sfRenderWindow_drawSprite(window, object->sprite, NULL);
        sfClock_restart(object->clock);
    }
}

int create_object(char const *fp, float speed, sfVector2f pos,
    object_t *obj)
{
    if (!(obj->texture = sfTexture_createFromFile(fp, NULL)))
        return (-1);
    obj->vectf = pos;
    obj->sprite = sfSprite_create();
    sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
    sfTexture_setSmooth(obj->texture, sfTrue);
    sfSprite_setPosition(obj->sprite, obj->vectf);
    obj->clock = sfClock_create();
    obj->display = &display_object;
    obj->destroy = &destroy_object;
    return (0);
}

int create_object_temp(char const *fp, float speed, sfVector2f pos,
    object_t *obj, int x, int y)
{
    if (!(obj->texture = sfTexture_createFromFile(fp, NULL)))
        return (-1);
    pos.y -= y;
    obj->vectf = pos;
    obj->sprite = sfSprite_create();
    obj->rect.left = pos.x;
    obj->rect.top = pos.y;
    obj->rect.width = x;
    obj->rect.height = y;
    obj->clock = sfClock_create();
    sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
    sfTexture_setSmooth(obj->texture, sfTrue);
    sfSprite_setPosition(obj->sprite, obj->vectf);
    obj->display = &display_object;
    obj->destroy = &destroy_object;
    return (0);
}

void destroy_object(object_t *object)
{
    sfSprite_destroy(object->sprite);
    sfTexture_destroy(object->texture);
}
