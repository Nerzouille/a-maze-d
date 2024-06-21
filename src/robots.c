/*
** EPITECH PROJECT, 2024
** robots
** File description:
** change robots lists
*/

#include "include/my.h"

void add_robot(rooms_t *room, int id_Rob)
{
    robots_t *new_robot = malloc(sizeof(robots_t));

    new_robot->id = id_Rob;
    new_robot->next = room->node->robots;
    room->node->robots = new_robot;
    room->node->nbR++;
}

void del_robot(rooms_t *room)
{
    robots_t *temp = room->node->robots;

    room->node->robots = temp->next;
    room->node->nbR--;
    free(temp);
}

int move_robot(rooms_t *room, rooms_t *shortest, int nbr_taked, int bdist)
{
    robots_t *robot;

    robot = room->node->robots;
    while (robot != NULL && robot->moved == 1)
        robot = robot->next;
    if (robot == NULL) {
        return 1;
    }
    if ((shortest->node->robots == NULL || shortest->node->finish == 1)
    && (shortest->node->distance < room->node->distance || (nbr_taked != 0
    && shortest->node->distance <= room->node->nbR / nbr_taked + bdist))) {
        add_robot(shortest, robot->id);
        shortest->node->robots->moved = 1;
        del_robot(room);
    } else
        return 1;
}

void clean_moves(rooms_t **rooms)
{
    rooms_t *room = *rooms;
    robots_t *robot;

    while (room != NULL) {
        robot = room->node->robots;
        while (robot != NULL) {
            robot->moved = 0;
            robot = robot->next;
        }
        room = room->next;
    }
}

int nb_robots(infos_t *liste)
{
    infos_t *current = liste;
    int nb_Rob;

    while (current != NULL && my_strncmp(current->labyrinth,
    "#number_of_robots", 17) != 0)
        current = current->next;
    if (current == NULL)
        return 0;
    nb_Rob = my_getnbr(current->next->labyrinth);
    return nb_Rob;
}
