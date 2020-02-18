/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** __DESCRIPTION__
*/

#include "my_rpg_hd.h"

static void write_user_pass(char *user, char *pass, int op, char *new_nb_user)
{
    write(op, new_nb_user, my_strlen(new_nb_user));
    write(op, ":", 1);
    write(op, user, my_strlen(user));
    write(op, ":", 1);
    write(op, pass, my_strlen(pass));
    write(op, "\n", 1);
    close(op);
}

bool register_new_user(window_t *wind)
{
    char **number_account = read_doub_file(NB_ACCOUNT, "\n");
    int nb_user = my_getnbr(number_account[0]);
    char *new_nb_user = transform_number_to_string(nb_user + 1);
    int op = 0;
    char *info_user = NULL;

    if (!wind->user.username || !wind->user.password)
        return (false);
    op = open(ALL_ACCOUNT, O_WRONLY | O_APPEND | O_CREAT, 0755);
    write_user_pass(wind->user.username, wind->user.password, op, new_nb_user);
    op = open(NB_ACCOUNT, O_WRONLY | O_TRUNC | O_CREAT, 0755);
    write(op, new_nb_user, my_strlen(new_nb_user));
    close(op);
    wind->warning = my_strdup("Account created");
    info_user = strcat_mall(info_user, "resources/account/");
    info_user = strcat_mall(info_user, new_nb_user);
    info_user = strcat_mall(info_user, ".txt");
    op = open(info_user, O_WRONLY | O_CREAT, 0755);
    fill_info_user(op);
    close(op);
    return (true);
}

static bool error_register(window_t *wind, bool register_or_connect, char **tmp)
{
    if (my_strncmp(tmp[1], wind->user.username) == 0
    && my_strncmp(tmp[2], wind->user.password) == 0) {
        if (!register_or_connect) {
            (wind->warning) ? free(wind->warning) : 0;
            wind->warning = NULL;
            wind->warning = my_strdup("Account already exist\n");
        }
        return (true);
    }
    return (false);
}

static bool user_already(window_t *wind, bool register_or_connect, char **tmp)
{
    if (my_strncmp(tmp[1], wind->user.username) == 0
    && !register_or_connect) {
        (wind->warning) ? free(wind->warning) : 0;
        wind->warning = NULL;
        wind->warning = my_strdup("Account already exist\n");
        return (true);
    }
    return (false);
}

bool account_exist(window_t *wind, bool register_or_connect)
{
    char **tab = read_doub_file(ALL_ACCOUNT, "\n");
    char **tmp = NULL;

    for (int i = 0; tab[i]; i++) {
        tmp = my_str_to_word_array(tab[i], ":");
        if (!wind->user.username || !wind->user.password)
            return (false);
        if (error_register(wind, register_or_connect, tmp))
            return (true);
        if (user_already(wind, register_or_connect, tmp))
            return (true);
        destroy_multi_table(tmp);
    }
    (wind->warning) ? free(wind->warning) : 0;
    wind->warning = NULL;
    if (wind->user.username && wind->user.password && register_or_connect)
        wind->warning = my_strdup("Username or password invalid");
    return (false);
}
