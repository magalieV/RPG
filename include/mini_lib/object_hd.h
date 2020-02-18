/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** __DESCRIPTION__
*/

#ifndef OBJECT_HEADER
#define OBJECT_HEADER

#ifndef MOOVE_BACK
#define MOOVE_BACK (15)
#endif

/*All structure object*/


/*In file : button*/
my_button_t *create_my_button(char **tab, my_button_t *button, window_t);
void display_button(window_t window, my_button_t *butt);
void destroy_my_button(my_button_t *button);
int button_is_click(sfEvent event, my_button_t *button, window_t wind);
/*End file : button*/
/*In file : check_pos_object*/
bool on_rect(sfIntRect rect, sfVector2i pos, int x, int y);
sfVector2i check_pos_mouse(sfRenderWindow *window);
/*End file : check_pos_object*/
/*In file : create_object*/
int create_object(char const *fp, float speed, sfVector2f pos,
object_t *obj);
void destroy_object(object_t *object);
/*End file : create_object*/
char *get_next_line(int fd);
char **read_doub_file(char const *str, char const *);
char *my_read_file(char const *str);
char **my_str_to_word_array(char const *str, char *param);
int create_to_big_object(char const *fp, sfVector2f pos, object_t *object);
object_t *load_back_ground(void);
object_t **create_tile_mapping(char const *, char const *, int, int);
object_t **moove_tile(int moove, object_t **obj);
int create_object_temp(char const *fp, float speed, sfVector2f pos,
object_t *obj, int x, int y);
char **my_tab_dup(char **tab);
char *my_strdup(char *str);
int my_tab_len(char **tab);
int my_strlen(char *str);
object_t *create_mutli_object(char const *path, char const *sepa, bool);
game_el_t load_elment_game(char const *button_inventory,
char const *back, char const *button_quest, window_t window);
#endif
