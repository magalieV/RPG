/*
** EPITECH PROJECT, 2018
** action_with_png
** File description:
** Implementation of action_with_png
*/

#include "my_rpg_hd.h"

static void found_png_inter(sfVector2f pl, png_t *png, int *choice)
{
    for (int i = 0; png[i].png.object.sprite; i++) {
        if (png[i].png.coord.x <= (pl.x * 5 + 300)
        && png[i].png.coord.x >= (pl.x * 5 - 300)
        && png[i].png.coord.y <= (pl.y * 5 + 300)
        && png[i].png.coord.y >= (pl.y * 5 - 300))
            *choice = i;
    }
}

static bool found_interaction_around_player(char **pixel_tab,
sfVector2f pl, png_t *png, int *choice)
{
    int y = pl.y - (100 / 5);
    int x = 0;
    bool bolean = false;

    while (pixel_tab && pixel_tab[y] && y < pl.y + (100 / 5)) {
        x = pl.x - (100 / 5);
        while (pixel_tab[y][x] && x < pl.x + (100 / 5)) {
            if (pixel_tab[y][x] == '-') {
                bolean = true;
                break;
            }
            x++;
        }
        if (bolean)
            break;
        y++;
    }
    (!bolean) ? *choice = -1 : found_png_inter(pl, png, choice);
    return (bolean);
}

int action_with_png(png_t *png, window_t window, sfVector2f player_pos,
char **pixel_tab, int choice, int *ch)
{
    if (window.event.type == sfEvtKeyPressed && window.event.key.code == sfKeyE)
        if (found_interaction_around_player(pixel_tab, player_pos, png, ch))
            return (choice == 0 ? -1 : 0);
    return (choice == 0 ? 0 : -1);
}

void display_talk_sprite(int ch, png_t *png, window_t window)
{
    object_t talk_ball = {0};
    sfVector2f pos = {0};
    int i = 0;

    if (ch == -1)
        return;
    pos.x = png[ch].png.object.vectf.x + 128;
    pos.y = png[ch].png.object.vectf.y - 94;
    create_object(DIALOGUE_BUTTON, 0, pos, &talk_ball);
    talk_ball.display(&talk_ball, window.window);
    for (i = 0; png[ch].quest[i].resume; i++)
        if (png[ch].quest[i].finish == false)
            break;
    display_texte(png[ch].quest[i].resume, (int)pos.x + 10, (int)pos.y + 10,
    window, sfBlack, 30);
    talk_ball.destroy(&talk_ball);
}
