/*
** EPITECH PROJECT, 2024
** add comments
** File description:
** add tunnels, rooms, nbr of robots
*/

#include "include/my.h"

int test_dash(char *arg)
{
    for (int i = 0; arg[i] != '\0'; i++) {
        if (arg[i] == '-') {
            return 1;
        }
    }
    return 0;
}

int add_tunnel_comment(infos_t *parcing, infos_t *add)
{
    while (1) {
        if (test_dash(parcing->labyrinth) == 1) {
            break;
        }
        if (parcing->next != NULL) {
            parcing = parcing->next;
            add = add->next;
        } else {
            break;
        }
    }
    parcing = malloc(sizeof(infos_t));
    parcing->next = add->next;
    add->next = parcing;
    parcing->labyrinth = my_strdup("#tunnels\n");
}

int add_commments(infos_t *infos)
{
    infos_t *add;
    infos_t *parcing;

    add = malloc(sizeof(infos_t));
    add->next = infos->next;
    infos->next = add;
    add->labyrinth = my_strdup("#number_of_robots\n");
    add = add->next;
    parcing = add;
    parcing = malloc(sizeof(infos_t));
    parcing->next = add->next;
    add->next = parcing;
    parcing->labyrinth = my_strdup("#rooms\n");
    add_tunnel_comment(parcing, add);
}
