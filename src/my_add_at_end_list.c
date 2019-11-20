/*
** EPITECH PROJECT, 2019
** CPool_Day11_2019
** File description:
** my_add_in_sorted_list
*/

#include "my_list.h"

void my_add_at_end_list(linked_list_t **begin, void *data)
{
    linked_list_t *new = malloc(sizeof(*new));
    linked_list_t *tnew = *begin;

    new->data = data;
    new->next = NULL;
    if (tnew == NULL) {
        *begin = new;
        return;
    }
    if (tnew->data == NULL) {
        free(new);
        (*begin)->data = data;
        return;
    }
    for (; tnew->next != NULL; tnew = tnew->next);
    tnew->next = new;
}
