/*
** EPITECH PROJECT, 2024
** add comments
** File description:
** add tunnels, rooms, nbr of robots
*/

#include "include/my.h"

int create_rooms(infos_t *liste, rooms_t **rooms)
{
    add_elem(liste, rooms, "##start");
    add_basroom(liste, rooms);
    add_elem(liste, rooms, "##end");
    link_rooms(liste, rooms);
    distance(rooms);
    travel(liste, rooms);
}

int lab(infos_t *liste)
{
    rooms_t *rooms = NULL;

    create_rooms(liste, &rooms);
}
