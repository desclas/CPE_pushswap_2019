/*
** EPITECH PROJECT, 2019
** CPool_infinadd_2019
** File description:
** my_strdup
*/

#include <stdlib.h>

int my_strlen(char *);
char *my_strcpy(char *, char *);

char *my_strdup(char *str)
{
    size_t len = my_strlen(str) + 1;
    char *res = malloc(sizeof(char) * len);

    for (size_t i = 0; i < len; i++)
        res[i] = 0;
    my_strcpy(res, str);
    return (res);
}
