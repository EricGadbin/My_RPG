/*
** EPITECH PROJECT, 2018
** equip item
** File description:
** rpg project
*/

#include "macrocsfml.h"
#include "inventory.h"

void	up_equip_item(w_pt **eq, all *st)
{
	if (st->soind != NULL)
		up_stadd(&st->stadd, st->soind->stack->data, *eq);
	else
		up_stadd(&st->stadd, NULL, *eq);
}

void	equip_item(w_pt **eq, all *st, stats_t **stats)
{
	w_pt *tmp = NULL;

	if (!eq || !st->stock)
		return;
	tmp = find_wpt_ind(*eq, st);
	if (tmp->ob == NULL) {
		tmp->ob = my_sobcpy(st->soind->stack->data);
		change_stats_aequip(tmp->ob, stats);
		br_dis_rae_update(&st->tra, *stats);
		supr_node_in_inv(st);
		up_equip_item(eq, st);
	} else if (tmp->ob != NULL) {
		add_new_ent_in_inv(tmp->ob, &st);
		change_stats_mequip(tmp->ob, stats);
		tmp->ob = my_sobcpy(st->soind->stack->data);
		change_stats_aequip(tmp->ob, stats);
		br_dis_rae_update(&st->tra, *stats);
		supr_node_in_inv(st);
		up_equip_item(eq, st);
	}
}
