/*
** EPITECH PROJECT, 2024
** case errors
** File description:
** case errors
*/

#include "include/my.h"

int test_dash_error(int i, int status, infos_t *node)
{
    if (node->labyrinth[i] == '-') {
        status = 84;
    }
    return status;
}

int case_none_tunnel(int status, infos_t *infos)
{
    infos_t *node = infos;

    while (1) {
        for (int i = 0; node->labyrinth[i] != '\0'; i++) {
            status = test_dash_error(i, status, node);
        }
        if (node->next != NULL) {
            node = node->next;
        } else {
            break;
        }
    }
    return status;
}

static int test_room(int count, infos_t *node)
{
    count++;
    for (int i = 0; node->next->labyrinth[i] != '\0'; i++) {
        if (node->next->labyrinth[i] == '-') {
            return 84;
        }
    }
    if (node->next->labyrinth[0] < 48 || node->next->labyrinth[0] > 57) {
        return 84;
    }
    return count;
}

int case_none_start_and_end(int status, infos_t *infos)
{
    infos_t *node = infos;
    int count = 0;

    while (1) {
        if (compare(0, node->labyrinth, "##start") == 1) {
            count = test_room(count, node);
        }
        if (compare(0, node->labyrinth, "##end") == 1) {
            count = test_room(count, node);
        }
        if (node->next == NULL) {
            break;
        } else {
            node = node->next;
        }
    }
    if (count != 2)
        return 0;
    return status;
}

int test_robot_number(int status, infos_t *infos)
{
    if (infos->labyrinth[0] == '\n') {
        return 0;
    }
    for (int i = 0; infos->labyrinth[i] != '\n'; i++) {
        if (infos->labyrinth[i] <= 47 || infos->labyrinth[i] >= 58) {
            return 0;
        }
    }
    return status;
}

int case_errors(infos_t *infos)
{
    int status = 0;

    get_out_comment(infos);
    infos = infos->next;
    status = case_none_tunnel(status, infos);
    status = case_none_start_and_end(status, infos);
    status = test_robot_number(status, infos);
    if (status != 84) {
        return 84;
    }
    return 0;
}
