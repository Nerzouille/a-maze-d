/*
** EPITECH PROJECT, 2024
** main
** File description:
** main of amazed
*/

#include "src/include/my.h"

int create_nodes(infos_t *infos)
{
    size_t size = 0;
    char *buffer = NULL;
    infos_t *travel;

    travel = infos;
    while (1) {
        if (getline(&buffer, &size, stdin) == -1) {
            break;
        }
        travel->next = malloc(sizeof(infos_t));
        travel->next->labyrinth = my_strdup(buffer);
        travel = travel->next;
    }
    travel->next = NULL;
}

int main(int argc, char **argv)
{
    infos_t *infos;
    int status = 0;

    if (argc == 1) {
        infos = malloc(sizeof(infos_t));
        create_nodes(infos);
        status = case_errors(infos);
        if (status == 84) {
            return 84;
        }
        add_commments(infos);
        infos = infos->next;
        afficher_liste(infos);
        lab(infos);
    } else {
        return 84;
    }
    return 0;
}
