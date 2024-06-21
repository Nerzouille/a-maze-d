/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** my.h of minishell one
*/

#ifndef MY_H
    #define MY_H
    #define MAX_SIZE 1024
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>

typedef struct robots_s {
    int moved;
    int id;
    struct robots_s *next;
} robots_t;


typedef struct linked_s {
    int nbR;
    int id;
    int distance;
    int finish;
    struct robots_s *robots;
    struct rooms_s *tunnels;
} linked_t;

typedef struct rooms_s {
    struct linked_s *node;
    struct rooms_s *next;
} rooms_t;

typedef struct labyrinth_s {
    char *nbr_robots;
    char **start;
    char **end;
    char **tunnel;
}labyrinth_t;

typedef struct infos_s {
    char *labyrinth;
    struct infos_s *next;
}infos_t;

int my_getnbr(char const *str);
int my_strncmp(char const *s1, char const *s2, int n);
int my_int_counter(int nb);
char *my_strdup(char const *str);
int my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_put_nbr(int n);
int afficher_liste(infos_t *liste);
int compare(int i, char *str, char const *to_find);
int case_errors(infos_t *infos);
int add_commments(infos_t *infos);
int get_out_comment(infos_t *infos);
char *duplicate_string(char const *src);



// lab linked list
void add_elem(infos_t *liste, rooms_t **rooms, char *type);
void add_basroom(infos_t *liste, rooms_t **rooms);
void link_rooms(infos_t *liste, rooms_t **rooms);
int distance(rooms_t **rooms);
void displayList(rooms_t *head);

// robots
void add_robot(rooms_t *room, int id_Rob);
void del_robot(rooms_t *room);
int move_robot(rooms_t *room, rooms_t *shortest, int nbr_taked, int bdist);
void clean_moves(rooms_t **rooms);
int nb_robots(infos_t *liste);

// travel
void travel(infos_t *liste, rooms_t **rooms);

// labyrinthe
int lab(infos_t *liste);

#endif /* !MY_H */
