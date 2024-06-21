/*
** EPITECH PROJECT, 2024
** trip
** File description:
** walk the maze
*/

#include "include/my.h"

static void print_move(int space, rooms_t *shortest)
{
    if (space > 0)
        my_putchar(' ');
    my_putchar('P');
    my_put_nbr(shortest->node->robots->id);
    my_putchar('-');
    my_put_nbr(shortest->node->id);
}

void find_shortest(rooms_t **shortest,
    rooms_t *neighbour, int *bdist, int *sdist)
{
    if (neighbour->node->distance < *bdist)
        *bdist = neighbour->node->distance;
    if (neighbour->node->distance <= *sdist
    && (neighbour->node->robots == NULL || neighbour->node->finish == 1)) {
        (*shortest) = neighbour;
        *sdist = *bdist;
    }
}

static int def_neighbours(rooms_t *neighbour, int *sdist, int *bdist)
{
    if (neighbour == NULL)
        return 84;
    *sdist = neighbour->node->distance;
    *bdist = neighbour->node->distance;
    return 0;
}

int func(rooms_t *room, int space)
{
    rooms_t *neighbour = room->node->tunnels;
    rooms_t *shortest = neighbour;
    int sdist;
    int bdist;
    int nbr_taked = 0;

    if (room->node->robots == NULL
    || def_neighbours(neighbour, &sdist, &bdist) == 84)
        return 1;
    while (neighbour != NULL) {
        find_shortest(&shortest, neighbour, &bdist, &sdist);
        if (neighbour->node->robots != NULL)
            nbr_taked++;
        neighbour = neighbour->next;
    }
    if (move_robot(room, shortest, nbr_taked, bdist) == 1)
        return 1;
    else
        print_move(space, shortest);
    return 0;
}

void def_start(rooms_t **rooms, int nb_Rob)
{
    rooms_t *start = *rooms;

    for (int id = nb_Rob; id > 0; id--)
        add_robot(start, id);
    my_putstr("#moves\n");
}

void do_op(rooms_t **rooms, int *space)
{
    rooms_t *cur_r = *rooms;

    while (cur_r->next != NULL) {
        while (func(cur_r, *space) == 0) {
            *space += 2;
        }
        cur_r = cur_r->next;
    }
}

void travel(infos_t *liste, rooms_t **rooms)
{
    int nb_Rob = nb_robots(liste);
    rooms_t *end = *rooms;
    int space = 0;

    def_start(rooms, nb_Rob);
    while (end->next != NULL)
        end = end->next;
    while (end->node->nbR != nb_Rob) {
        for (int i = 0; i < nb_Rob; i++)
            do_op(rooms, &space);
        clean_moves(rooms);
        my_putchar('\n');
        space = 0;
    }
}
