/*
** EPITECH PROJECT, 2024
** remove comments
** File description:
** remove comments
*/

#include "include/my.h"

int cut_node(infos_t *cut, infos_t *node)
{
    node->next = cut->next;
    free(cut->labyrinth);
}

int cut_comment(int i, infos_t *cut, infos_t *node)
{
    char *new_labyrinth = malloc((i + 2) * sizeof(char));
    int j;

    for (j = 0; cut->labyrinth[j] != '#'; j++) {
        new_labyrinth[j] = cut->labyrinth[j];
    }
    new_labyrinth[j] = '\n';
    new_labyrinth[j + 1] = '\0';
    free(cut->labyrinth);
    cut->labyrinth = new_labyrinth;
}

int test_comment(infos_t *cut, infos_t *node)
{
    int test = 0;
    int i = 0;

    while (1) {
        if (cut->labyrinth[i] == ' ' || cut->labyrinth[i] == '\t') {
            i++;
        } else {
            break;
        }
    }
    if (cut->labyrinth[i] == '#' && cut->labyrinth[i + 1] != '#') {
        cut_node(cut, node);
    } else {
        for (i; cut->labyrinth[i] != '#'; i++);
        cut_comment(i, cut, node);
    }
}

int test_sharpe(infos_t *cut)
{
    int test = 0;

    for (int i = 0; cut->labyrinth[i] != '\0'; i++) {
        test = 0;
        if (cut->labyrinth[i] == '#' && cut->labyrinth[i + 1] == '#') {
            i = i + 2;
        }
        if (cut->labyrinth[i] == '#' && cut->labyrinth[i + 1] != '#') {
            test++;
        }
        if (test == 1) {
            return 1;
        }
    }
}

int get_out_comment(infos_t *infos)
{
    infos_t *node = infos;
    infos_t *cut = infos->next;

    while (1) {
        if (test_sharpe(cut) == 1) {
            test_comment(cut, node);
        }
        if (cut->next == NULL) {
            break;
        } else {
            node = node->next;
            cut = cut->next;
        }
    }
}
