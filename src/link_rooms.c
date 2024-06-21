/*
** EPITECH PROJECT, 2024
** add comments
** File description:
** add tunnels, rooms, nbr of robots
*/

#include "include/my.h"

void link_append(rooms_t **rooms, int target, int link_id)
{
    rooms_t *current_room = *rooms;
    rooms_t *target_room = NULL;
    rooms_t *linked_room = NULL;
    rooms_t *new_tunnel = malloc(sizeof(rooms_t));

    new_tunnel->next = NULL;
    while (current_room != NULL) {
        if (current_room->node->id == target)
            target_room = current_room;
        if (current_room->node->id == link_id)
            linked_room = current_room;
        current_room = current_room->next;
    }
    new_tunnel->next = target_room->node->tunnels;
    new_tunnel->node = linked_room->node;
    target_room->node->tunnels = new_tunnel;
}

void linking(rooms_t **rooms, int id1, int id2)
{
    link_append(rooms, id1, id2);
    link_append(rooms, id2, id1);
}

void link_rooms(infos_t *liste, rooms_t **rooms)
{
    infos_t *current = liste;
    int rooma;
    int roomb;

    while (current != NULL && my_strncmp(current->labyrinth, "#tunn", 5) != 0)
        current = current->next;
    current = current->next;
    while (current != NULL) {
        rooma = my_getnbr(current->labyrinth);
        roomb = my_getnbr(current->labyrinth + my_int_counter(rooma) + 1);
        linking(rooms, rooma, roomb);
        current = current->next;
    }
}
