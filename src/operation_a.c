/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** operation_a
*/

#include "my_pushswap.h"

void op_sa(linked_list_t *la, char **ops)
{
    void *tmp;

    if (la == NULL || la->next == NULL)
        return;
    tmp = la->data;
    la->data = la->next->data;
    la->next->data = tmp;
    *ops = my_append_str(*ops, my_strdup("sa;"));
}

void op_pa(linked_list_t **la, linked_list_t **lb, char **ops)
{
    linked_list_t *tmp;

    if (*lb == NULL)
        return;
    tmp = (*lb)->next;
    (*lb)->next = *la;
    *la = *lb;
    *lb = tmp;
    *ops = my_append_str(*ops, my_strdup("pa;"));
}

void op_ra(linked_list_t **la, char **ops)
{
    linked_list_t *tmp;

    if (*la == NULL || (*la)->next == NULL)
        return;
    tmp = (*la)->next;
    for (linked_list_t *i = *la;; i = i->next)
        if (i->next == NULL) {
            i->next = tmp;
            break;
        }
    (*la)->next = NULL;
    *la = tmp;
    *ops = my_append_str(*ops, my_strdup("ra;"));
}

void op_rra(linked_list_t **la, char **ops)
{
    if (*la == NULL || (*la)->next == NULL)
        return;
    for (linked_list_t *tmp = *la;; tmp = tmp->next)
        if (tmp->next->next == NULL) {
            tmp->next->next = *la;
            *la = tmp->next;
            tmp->next = NULL;
            break;
        }
    *ops = my_append_str(*ops, my_strdup("rra;"));
}
