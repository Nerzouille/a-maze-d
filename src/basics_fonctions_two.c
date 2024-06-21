/*
** EPITECH PROJECT, 2024
** basics fonctions two
** File description:
** other basics fonctions
*/

#include "include/my.h"

int compare(int i, char *str, char const *to_find)
{
    int b = 0;

    for (int j = 0; to_find[j] != '\0'; j++) {
        if (str[i] == to_find[j]) {
            i++;
        } else {
            return (0);
        }
    }
    return 1;
}

int afficher_liste(infos_t *liste)
{
    infos_t *disp = liste;

    while (disp != NULL) {
        my_putstr(disp->labyrinth);
        disp = disp->next;
    }
    my_putchar('\n');
    return 0;
}

char *duplicate_string(char const *src)
{
    char *res = malloc(my_strlen(src) * sizeof(char));

    for (int i = 0; src[i] != '\0'; i++) {
        res[i] = src[i];
    }
    return (res);
}
