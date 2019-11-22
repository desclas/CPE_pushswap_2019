/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** algo
*/

#include "my_pushswap.h"

static int is_in_order(linked_list_t *lnk, char order)
{
    linked_list_t *tmp = lnk;

    if (tmp == NULL)
        return (0);
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

static long int find_min(linked_list_t *lnk, char *direc)
{
    long int min = (long int)lnk->data;
    long int pos = 0;
    long int i = 1;

    for (linked_list_t *tmp = lnk->next; tmp != NULL; tmp = tmp->next, i++)
        if (min > (long int)tmp->data) {
            min = (long int)tmp->data;
            pos = i;
        }
    *direc = ((pos > (i / 2)) ? UP : DOWN);
    pos = ((pos > (i / 2)) ? i - pos : pos);
    return (pos);
}

linked_list_t *algo(linked_list_t *la, linked_list_t *lb)
{
    char *ops = my_strdup("\0");
    char direc = 0;
    long int nb = 0;
    if (!is_in_order(la, UP))
        return (print_ops(ops, la));
    for (;; op_pb(&lb, &la, &ops)) {
        if (la->next == NULL || (lb != NULL && !is_in_order(la, UP) &&
            la->data > lb->data))
            break;
        nb = find_min(la, &direc);
        for (; direc == UP && nb > 0; nb--)
            op_rra(&la, &ops);
        for (; direc == DOWN && nb > 0; nb--)
            if (nb == 1)
                op_sa(la, &ops);
            else
                op_ra(&la, &ops);
    }
    for (; lb != NULL; op_pa(&la, &lb, &ops));
    return (print_ops(ops, la));
}
