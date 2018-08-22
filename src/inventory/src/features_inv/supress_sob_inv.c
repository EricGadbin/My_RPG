/*
** EPITECH PROJECT, 2018
** supress sob inv
** File description:
** project my_rpg
*/

#include "inventory.h"

void 	free_stack(stack *ind)
{
	if (!ind)
		return;
	ind->prev = NULL;
	ind->next = NULL;
	if (ind->data != NULL)
		free_sob(ind->data);
	free(ind);
}

void 	free_stock(stock *ind)
{
	if (!ind)
		return;
	ind->prev = NULL;
	ind->next = NULL;
	if (ind->stack != NULL)
		free_stack(ind->stack);
	free(ind);
}

int 	supr_stack(stack **ind)
{
	stack *tmp = NULL;

	if (!(*ind))
		return (-1);
	tmp = (*ind);
	if ((*ind)->next == NULL && (*ind)->prev == NULL) {
		free_stack(tmp);
		(*ind) = NULL;
		return (-1);
	}
	if ((*ind)->next != NULL)
		(*ind)->next->prev = (*ind)->prev;
	if ((*ind)->prev != NULL)
		(*ind)->prev->next = (*ind)->next;
	(*ind) = ((*ind)->prev != NULL) ? (*ind)->prev : (*ind);
	(*ind) = ((*ind)->next != NULL) ? (*ind)->next : (*ind);
	free_stack(tmp);
	return (0);
}

int 	supr_stock(stock **ind)
{
	stock *tmp = NULL;

	if (!(*ind))
		return (-1);
	tmp = (*ind);
	if ((*ind)->next == NULL && (*ind)->prev == NULL) {
		free_stock(tmp);
		(*ind) = NULL;
		return (-1);
	}
	if ((*ind)->next != NULL)
		(*ind)->next->prev = (*ind)->prev;
	if ((*ind)->prev != NULL)
		(*ind)->prev->next = (*ind)->next;
	(*ind) = ((*ind)->prev != NULL) ? (*ind)->prev : (*ind);
	(*ind) = ((*ind)->next != NULL) ? (*ind)->next : (*ind);
	free_stock(tmp);
	return (0);
}

all 	*supr_node_in_inv(all *st)
{
	int n = 0;

	if (!st->stock)
		return (st);
	n = supr_stack(&st->soind->stack);
	st->soind->nb--;
	update_ts(&st->soind->nbs, my_itoa(st->soind->nb));
	if (n == -1) {
		n = supr_stock(&st->soind);
		st->stock = (n == -1) ? NULL : st->stock;
		st->soind = (n == -1) ? NULL : st->soind;
		st->lst = (n == -1) ? NULL : st->lst;
		if (n == -1)
			br_dis_update(&st->trr, NULL);
		st->stock = find_first_stock(st->soind);
		st->lst = find_last_stock(st->soind);
	} else if (n != -1)
		br_dis_update(&st->trr, st->soind->stack);
	return (st);
}
