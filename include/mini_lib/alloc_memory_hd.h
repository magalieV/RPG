/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** __DESCRIPTION__
*/

#ifndef ALLOC_MEMORY_HEADER
#define ALLOC_MEMORY_HEADER

/*File : alloc_memory*/
char *my_realloc(char *type, size_t size, char *second);
/*  Use :  type : variable how must be realloc
size : a sizeof(***) * the size you need
second : varible you want add to type*/
/*End file : alloc_memory*/
/*In file : number*/
int my_getnbr(char const *str);
/*End file : number*/
void destroy_multi_table(char **table);
int my_strncmp(char const *sa, char const *sb);
char *transform_number_to_string(int nb);
char *strcat_mall(char const *dest, char const *cpy);

#endif
