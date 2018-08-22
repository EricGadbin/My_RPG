/*
** EPITECH PROJECT, 2018
** update dis r
** File description:
** project my_rpg
*/

#include "inventory.h"

void	br_dis_update(br_dis **re, stack *ind)
{
	if (!re)
		return;
	if (!ind) {
		update_dvalue(&(*re)->nameob, "none", 0);
		update_dvalue(&(*re)->typeob, "none", 0);
		update_dvalue(&(*re)->ad_life, "none", 0);
		update_dvalue(&(*re)->ad_st, "none", 0);
		update_dvalue(&(*re)->ad_supp, "none", 0);
		update_dvalue(&(*re)->ad_speed, "none", 0);
		return;
	}
	update_dvalue(&(*re)->nameob, ind->data->name, 0);
	update_dvalue(&(*re)->typeob, ind->data->catg, 0);
	update_dvalue(&(*re)->ad_life, my_itoa(ind->data->a_life), 0);
	update_dvalue(&(*re)->ad_st, my_itoa(ind->data->a_st), 0);
	update_dvalue(&(*re)->ad_supp, my_itoa(ind->data->a_supp), 0);
	update_dvalue(&(*re)->ad_speed, my_itoa(ind->data->a_speed), 0);
}

void	br_dis_rae_update(br_dis_sta **re, stats_t *stats)
{
	if (!re || !stats)
		return;
	update_dvalue(&(*re)->health, my_itoa(stats->health), 0);
	update_dvalue(&(*re)->strength, my_itoa(stats->strenght), 0);
	update_dvalue(&(*re)->supp, my_itoa(stats->supp), 0);
	update_dvalue(&(*re)->speed, my_itoa(stats->speed), 0);
}

void	up_stadd(dis_stadd **ind, sob *stoc, w_pt *eq)
{
	w_pt *tm = NULL;

	if (!stoc) {
		update_ts(&(*ind)->add_h, "(+0)");
		update_ts(&(*ind)->add_st, "(+0)");
		update_ts(&(*ind)->add_supp, "(+0)");
		update_ts(&(*ind)->add_speed, "(+0)");
		return;
	}
	tm = eq;
	while (tm->ind != is_find_category(stoc->type))
		tm = tm->next;
	update_ts(&(*ind)->add_h, dsad(stoc->a_life -kw(tm->ob)));
	update_ts(&(*ind)->add_st, dsad(stoc->a_st -kw(tm->ob)));
	update_ts(&(*ind)->add_supp, dsad(stoc->a_supp -kw(tm->ob)));
	update_ts(&(*ind)->add_speed, dsad(stoc->a_speed -kw(tm->ob)));
}
