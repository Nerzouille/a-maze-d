/*
** EPITECH PROJECT, 2024
** basics fonctions
** File description:
** basics fonctions of minishell
*/

#include "include/my.h"

int my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int a = 0;

    while (str[a] != '\0') {
        my_putchar(str[a]);
        a++;
    }
}

int my_strlen(char const *str)
{
    int a = 0;

    while (str[a] != '\0') {
        a++;
    }
    return (a);
}

char *my_strdup(char const *str)
{
    int len = my_strlen(str);
    char *new_str;

    new_str = malloc((len + 1) * sizeof(char));
    for (int i = 0; i < (len + 1); i++) {
        new_str[i] = str[i];
    }
    new_str[len] = '\0';
    return new_str;
}

int my_put_nbr(int n)
{
    int mod;

    if (n < 0) {
        my_putchar('-');
        n = n * (-1);
    }
    if (n >= 10) {
        mod = n % 10;
        n = (n - mod) / 10;
        my_put_nbr(n);
        my_putchar(mod + '0');
    } else {
        my_putchar('0' + n);
    }
    return 0;
}
