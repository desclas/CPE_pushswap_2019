/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** my_pushswap
*/

#ifndef MY_PUSHSWAP_H_
#define MY_PUSHSWAP_H_

#include <stdlib.h>
#include "my.h"
#include "my_list.h"

#define UP 1
#define DOWN 0

void op_sa(linked_list_t *, char **);
void op_pa(linked_list_t **, linked_list_t **, char **);
void op_ra(linked_list_t **, char **);
void op_rra(linked_list_t **, char **);
void op_sb(linked_list_t *, char **);
void op_pb(linked_list_t **, linked_list_t **, char **);
void op_rb(linked_list_t **, char **);
void op_rrb(linked_list_t **, char **);
void op_sc(linked_list_t *, linked_list_t *, char **);
void op_rr(linked_list_t **, linked_list_t **, char **);
void op_rrr(linked_list_t **, linked_list_t **, char **);
linked_list_t *algo(linked_list_t *, linked_list_t *);

#endif /* !MY_PUSHSWAP_H_ */
