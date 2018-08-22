/*
** EPITECH PROJECT, 2018
** find first and last
** File description:
** my_rpg project
*/

#include "macrocsfml.h"
#include "inventory.h"

all 	*init_all(stats_t *stats)
{
	all *st = malloc(sizeof(all));
	s2f tmp = {0, 0};
	sfIR rectmp = {0, 0, 1600, 900};

	if (!st)
		return (NULL);
	st->stock = NULL;
	st->lst = NULL;
	st->soind = NULL;
	st->tr = is_init_dis();
	st->trr = init_re_dis();
	st->tra = init_rea_dis(stats);
	st->back = sf_build("assets/inv(1).png", tmp, rectmp, (s2f){1, 1});
	return (st);
}

int 	my_stacklen(stack *stac)
{
	stack *tmp = NULL;
	int e = 0;

	if (!stac)
		return (e);
	tmp = stac;
	while (tmp != NULL) {
		e++;
		tmp = tmp->next;
	}
	return (e);
}

stock 	*verif_sub_exist(stock *stoc, sob *sup)
{
	stock *tmp = NULL;
	int n = 0;

	if (!stoc && !sup)
		return (NULL);
	tmp = stoc;
	while (tmp != NULL) {
		n = my_strcmp(tmp->stack->data->name, sup->name);
		if (n == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
