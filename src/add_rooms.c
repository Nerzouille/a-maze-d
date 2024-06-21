/*
** EPITECH PROJECT, 2024
** add comments
** File description:
** add tunnels, rooms, nbr of robots
*/

#include "include/my.h"

void append(rooms_t **head, int id)
{
    rooms_t *room = malloc(sizeof(rooms_t));
    rooms_t *current = *head;

    room->node = malloc(sizeof(linked_t));
    room->node->id = id;
    room->node->nbR = 0;
    room->node->distance = -1;
    room->node->finish = 0;
    room->node->tunnels = NULL;
    room->node->robots = NULL;
    room->next = NULL;
    if (*head == NULL) {
        *head = room;
        return;
    }
    while (current->next != NULL)
        current = current->next;
    current->next = room;
}

void add_elem(infos_t *liste, rooms_t **rooms, char *type)
{
    infos_t *current = liste;

    while (current != NULL && my_strncmp(current->labyrinth,
    type, my_strlen(type)) != 0)
        current = current->next;
    if (current == NULL)
        return;
    current = current->next;
    append(rooms, my_getnbr(current->labyrinth));
}

void add_basroom(infos_t *liste, rooms_t **rooms)
{
    infos_t *current = liste;

    while (current != NULL
    && my_strncmp(current->labyrinth, "#tunnels", 8) != 0) {
        if (my_strncmp(current->labyrinth, "##", 2) == 0) {
            current = current->next->next;
            continue;
        }
        if (my_strncmp(current->labyrinth, "#", 1) == 0) {
            current = current->next;
            continue;
        }
        append(rooms, my_getnbr(current->labyrinth));
        current = current->next;
    }
}
