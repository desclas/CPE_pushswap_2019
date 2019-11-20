/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** operation_c
*/


#include "my_pushswap.h"

void op_sc(linked_list_t *la, linked_list_t *lb, char **ops)
{
    void *tmp;

    if (la == NULL || la->next == NULL)
        return;
    if (lb == NULL || lb->next == NULL)
        return;
    tmp = la->data;
    la->data = la->next->data;
    la->next->data = tmp;
    tmp = lb->data;
    lb->data = lb->next->data;
    lb->next->data = tmp;
    *ops = my_append_str(*ops, my_strdup("sc;"));
}

void op_rr(linked_list_t **la, linked_list_t **lb, char **ops)
{
    linked_list_t *tmp;
    if (*la == NULL || (*la)->next == NULL || *lb == NULL || (*lb)->next ==NULL)
        return;
    tmp = (*la)->next;
    for (linked_list_t *i = *la;; i = i->next)
        if (i->next == NULL) {
            i->next = tmp;
            break;
        }
    (*la)->next = NULL;
    *la = tmp;
    tmp = (*lb)->next;
    for (linked_list_t *i = *lb;; i = i->next)
        if (i->next == NULL) {
            i->next = tmp;
            break;
        }
    (*lb)->next = NULL;
    *lb = tmp;
    *ops = my_append_str(*ops, my_strdup("rr;"));
}

void op_rrr(linked_list_t **la, linked_list_t **lb, char **ops)
{
    if (*la == NULL || (*la)->next == NULL)
        return;
    if (*lb == NULL || (*lb)->next == NULL)
        return;
    for (linked_list_t *tmp = *la;; tmp = tmp->next)
        if (tmp->next->next == NULL) {
            tmp->next->next = *la;
            *la = tmp->next;
            tmp->next = NULL;
            break;
        }
    for (linked_list_t *tmp = *lb;; tmp = tmp->next)
        if (tmp->next->next == NULL) {
            tmp->next->next = *lb;
            *lb = tmp->next;
            tmp->next = NULL;
            break;
        }
    *ops = my_append_str(*ops, my_strdup("rrr;"));
}
