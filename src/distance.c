/*
** EPITECH PROJECT, 2024
** distance
** File description:
** add distance from the end
*/

#include "include/my.h"

int add_distance(rooms_t *room, int distance)
{
    rooms_t *current_t = room->node->tunnels;

    if (distance > room->node->distance)
        if (room->node->distance != -1)
            return 1;
    room->node->distance = distance;
    while (current_t != NULL) {
        add_distance(current_t, distance + 1);
        current_t = current_t->next;
    }
}

int distance(rooms_t **rooms)
{
    rooms_t *end = *rooms;

    if (end == NULL)
        return 84;
    while (end->next != NULL)
        end = end->next;
    end->node->finish = 1;
    add_distance(end, 0);
}
