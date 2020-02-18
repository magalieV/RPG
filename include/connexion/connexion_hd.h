/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** __DESCRIPTION__
*/

#ifndef CONNECTION_HEADER
#define CONNECTION_HEADER

/*File : get_event_connexion_window*/
bool loop_event_connexion(window_t *window, my_button_t *button);
/*Use : window = struct type window
check event of the window connexion*/
/*End file : get_event_connexion_window*/
/*File : display_connexion_window*/
bool user_want_connect(window_t window);
/*Use : window = struct type window
display connexion window*/
/*End file : display_connexion_window*/

/*TMP*/
void display_text(char const *, int x, int y, window_t);
bool account_exist(window_t *wind, bool);
bool register_new_user(window_t *wind);
bool fill_info_user(int op);

#endif
