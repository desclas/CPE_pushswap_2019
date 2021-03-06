/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** main
*/

#include "my_pushswap.h"

static int print_usage(char *name)
{
    my_putstr("usage:\n");
    my_putstr(name);
    my_putstr(" [[0-9]]\n");
    return (84);
}

static int all_num(int av, char **ac)
{
    for (int i = 1; i < av; i++)
        for (size_t x = 0; ac[i][x] != 0; x++)
            if (!((ac[i][x] >= '0' && ac[i][x] <= '9') || ac[i][x] == '-'))
                return (1);
    return (0);
}

int main(int av, char **ac)
{
    linked_list_t *la = NULL;

    if (av < 2 || all_num(av, ac))
        return (print_usage(ac[0]));
    for (int i = 1; i < av; i++)
        my_add_at_end_list(&la, (void *)((long int)my_getnbr(ac[i])));
    la = algo(la, NULL);
    my_putchar('\n');
    for (linked_list_t *tmp = la; la != NULL; la = tmp) {
        tmp = (tmp == NULL) ? NULL : tmp->next;
        free(la);
    }
    return (0);
}
