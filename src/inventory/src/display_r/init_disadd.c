/*
** EPITECH PROJECT, 2018
** disadd
** File description:
** my_rpg project
*/

#include "macrocsfml.h"
#include "inventory.h"

void	init_stadd_value(dis_stadd **n, w_pt *tm, sob *st, s2f p)
{
	if (n != NULL) {
		(*n)->add_h = sf_buildt(dsad(st->a_life -kw(tm->ob)),
		"assets/ec.otf", 20, p);
		p.y += 40;
		(*n)->add_st = sf_buildt(dsad(st->a_st -kw(tm->ob)),
		"assets/ec.otf", 20, p);
		p.y += 40;
		(*n)->add_supp = sf_buildt(dsad(st->a_supp -kw(tm->ob)),
		"assets/ec.otf", 20, p);
		p.y += 40;
		(*n)->add_speed = sf_buildt(dsad(st->a_speed -kw(tm->ob)),
		"assets/ec.otf", 20, p);
	}
}

dis_stadd *init_dis_stadd(sob *st, w_pt *eq)
{
	dis_stadd *n = malloc(sizeof(dis_stadd));
	w_pt *tm = NULL;
	s2f p = {300, 613};

	tm = eq;
	if (!st && n != NULL) {
		n->add_h = sf_buildt("(+0)", "assets/ec.otf", 20, p);
		p.y += 40;
		n->add_st = sf_buildt("(+0)", "assets/ec.otf", 20, p);
		p.y += 40;
		n->add_supp = sf_buildt("(+0)", "assets/ec.otf", 20, p);
		p.y += 40;
		n->add_speed = sf_buildt("(+0)", "assets/ec.otf", 20, p);
		return (n);
	}
	while (tm->ind != is_find_category(st->type))
		tm = tm->next;
	init_stadd_value(&n, tm, st, p);
	return (n);
}
