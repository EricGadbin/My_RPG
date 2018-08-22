/*
** EPITECH PROJECT, 2018
** inventory event
** File description:
** rpg project
*/

#include "macrocsfml.h"
#include "inventory.h"

void	event_supr_in_inv(all **st, w_pt *eq, int *i)
{
	if (KB_IKP(sfKeyS) && (*i) != 1) {
		(*st) = supr_node_in_inv(*st);
		if ((*st)->soind != NULL)
			up_stadd(&(*st)->stadd, (*st)->soind->stack->data, eq);
		else
			up_stadd(&(*st)->stadd, NULL, eq);
		(*i)++;
	}
}

void	event_equip_in_inv(all **st, w_pt **equip, stats_t **stats, int *i)
{
	if (KB_IKP(sfKeyE) && (*i) != 1) {
		equip_item(equip, *st, stats);
		(*i)++;
	}
}
