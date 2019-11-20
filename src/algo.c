/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** algo
*/

#include "my_pushswap.h"

static long int pick_first(linked_list_t *lnk)
{
    if (lnk == NULL || lnk->data == NULL)
        return (-(__INT_MAX__ - 2));
    return ((long int)lnk->data);
}

static long int pick_last(linked_list_t *lnk)
{
    linked_list_t *tmp = lnk;

    if (lnk == NULL || lnk->data == NULL)
        return (-(__INT_MAX__ - 2));
    for (; tmp->next != NULL; tmp = tmp->next);
    return ((long int)tmp->data);
}

static int is_in_order(linked_list_t *lnk, char order)
{
    linked_list_t *tmp = lnk;

    for (; tmp->next != NULL; tmp = tmp->next)
        if (((order == UP) ? tmp->data > tmp->next->data :
            tmp->data < tmp->next->data))
            return (1);
    return (0);
}

static linked_list_t *print_ops(char *ops, linked_list_t *la)
{
    size_t i;

    for (i = 0; ops[i] != 0; i++)
        if (ops[i] == ';')
            ops[i] = ' ';
    ops[i - 1] = 0;
    write(1, ops, i);
    free(ops);
    return (la);
}

linked_list_t *algo(linked_list_t *la, linked_list_t *lb)
{
    linked_list_t *tmp;
    char *ops = malloc(sizeof(char));
    ops[0] = '\0';
    while (is_in_order(la, UP) || is_in_order(lb, DOWN)) {
        for (;la != NULL && la->next != NULL && pick_first(la) > pick_last(la);)
            op_ra(&la, &ops);
        for (;lb != NULL && lb->next != NULL && pick_first(lb) < pick_last(lb);)
            op_ra(&lb, &ops);
        for (tmp = la; tmp != NULL; tmp = tmp->next)
            if (tmp->next != NULL && tmp->data > tmp->next->data)
                break;
        if (tmp != NULL) {
            for (; la != tmp; op_pb(&lb, &la, &ops));
            op_sa(la, &ops);
        }
        if (la == NULL)
            for (; lb != NULL; op_pa(&la, &lb, &ops));
    }
    for (; lb != NULL; op_pa(&la, &lb, &ops));
    return (print_ops(ops, la));
}
