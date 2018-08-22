/*
** EPITECH PROJECT, 2018
** functions add object
** File description:
** my_rpg project
*/

#include "inventory.h"

void 	add_stack(sob *sup, stack **stac)
{
	stack *nws = NULL;
	stack *tmp = NULL;

	if ((*stac) == NULL) {
		(*stac) = create_first_stack(sup);
		return;
	}
	tmp = find_last_stack(*stac);
	if (tmp == NULL)
		return;
	nws = malloc(sizeof(stack));
	if (!nws)
		return;
	nws->data = sup;
	nws->next = NULL;
	nws->prev = tmp;
	tmp->next = nws;
}

int	add_new_stock(sob *sup, stock **st)
{
	stock *nws = NULL;
	sfVector2f p = {-100, -100};
	stock *tmp = NULL;

	tmp = find_last_stock((*st));
	nws = malloc(sizeof(stock));
	if (!nws)
		return (-1);
	nws->next = NULL;
	nws->stack = NULL;
	add_stack(sup, &nws->stack);
	tmp->next = nws;
	nws->prev = tmp;
	nws->nb = 1;
	nws->nbs = sf_buildt(my_itoa(nws->nb), "assets/Timepiece.otf", 20, p);
	return (0);
}

int 	add_stock(sob *sup, stock **st)
{
	stock *tmp = NULL;
	int n = 0;

	if ((*st) == NULL) {
		(*st) = create_first_stock(sup);
		return (1);
	}
	tmp = verif_sub_exist((*st), sup);
	if (tmp != NULL) {
		add_stack(sup, &tmp->stack);
		tmp->nb++;
		update_ts(&tmp->nbs, my_itoa(tmp->nb));
		return (2);
	}
	n = add_new_stock(sup, st);
	return (n);
}

void 	add_new_ent_in_inv(sob *sub, all **st)
{
	int tmp = 0;

	tmp = add_stock(sub, &(*st)->stock);
	(*st)->lst = (tmp == 1) ? (*st)->stock : (*st)->lst;
	(*st)->soind = (tmp == 1) ? (*st)->stock : (*st)->soind;
	if (tmp == 1) {
		br_dis_update(&(*st)->trr, (*st)->soind->stack);
	}
	(*st)->lst = (tmp == 0) ? find_last_stock((*st)->stock) : (*st)->lst;
}
