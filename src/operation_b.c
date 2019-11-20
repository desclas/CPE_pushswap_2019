/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** operation_b
*/


#include "my_pushswap.h"

void op_sb(linked_list_t *lb, char **ops)
{
    void *tmp;

    if (lb == NULL || lb->next == NULL)
        return;
    tmp = lb->data;
    lb->data = lb->next->data;
    lb->next->data = tmp;
    *ops = my_append_str(*ops, my_strdup("sb;"));
}

void op_pb(linked_list_t **lb, linked_list_t **la, char **ops)
{
    linked_list_t *tmp;

    if (*la == NULL)
        return;
    tmp = (*la)->next;
    (*la)->next = *lb;
    *lb = *la;
    *la = tmp;
    *ops = my_append_str(*ops, my_strdup("pb;"));
}

void op_rb(linked_list_t **lb, char **ops)
{
    linked_list_t *tmp;

    if (*lb == NULL || (*lb)->next == NULL)
        return;
    tmp = (*lb)->next;
    for (linked_list_t *i = *lb;; i = i->next)
        if (i->next == NULL) {
            i->next = tmp;
            break;
        }
    (*lb)->next = NULL;
    *lb = tmp;
    *ops = my_append_str(*ops, my_strdup("rb;"));
}

void op_rrb(linked_list_t **lb, char **ops)
{
    if (*lb == NULL || (*lb)->next == NULL)
        return;
    for (linked_list_t *tmp = *lb;; tmp = tmp->next)
        if (tmp->next->next == NULL) {
            tmp->next->next = *lb;
            *lb = tmp->next;
            tmp->next = NULL;
            break;
        }
    *ops = my_append_str(*ops, my_strdup("rrb;"));
}
