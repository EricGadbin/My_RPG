/*
** EPITECH PROJECT, 2018
** lib wpt
** File description:
** rpg project
*/

#include "macrocsfml.h"
#include "inventory.h"

w_pt	*create_wpt(int catg, type typ)
{
	w_pt *new = malloc(sizeof(w_pt));

	if (!new)
		return (NULL);
	new->ind = catg;
	new->catg = typ;
	new->ob = NULL;
	new->next = NULL;
	return (new);
}

w_pt	*is_init_wpt(void)
{
	w_pt *weapon = create_wpt(0, WEAPON);
	w_pt *chestplate = create_wpt(1, CHESTPLATE);
	weapon->next = chestplate;
	w_pt *legsarmor = create_wpt(2, LEGSAMOR);
	chestplate->next = legsarmor;
	w_pt *accessory = create_wpt(3, ACCESSORY);
	legsarmor->next = accessory;
	w_pt *key_item = create_wpt(4, KEY_ITEM);
	accessory->next = key_item;
	return (weapon);
}

void	dis_wpt(w_pt *eq, sfRenderWindow *win)
{
	w_pt *tmp = NULL;
	s2f pos = {175, 130};

	if (!eq)
		return;
	tmp = eq;
	while (tmp != NULL) {
		if (tmp->ob != NULL) {
			SP_SPOS(tmp->ob->s->sp_ob, pos);
			SP_DSP(win, tmp->ob->s->sp_ob, NULL);
		}
		tmp = tmp->next;
		pos.y += 86;
	}
}

w_pt	*find_wpt_ind(w_pt *eq, all *st)
{
	w_pt *tmp = NULL;

	tmp = eq;
	while (tmp->ind != is_find_category(st->soind->stack->data->type))
		tmp = tmp->next;
	return (tmp);
}
