/*
** EPITECH PROJECT, 2018
** disp_disr.c
** File description:
** project minishell2
*/

#include "macrocsfml.h"
#include "inventory.h"

void 	is_dis_rae(br_dis_sta *dis_p, sfRW *win)
{
	display_dvalue(dis_p->health, win);
	display_dvalue(dis_p->strength, win);
	display_dvalue(dis_p->supp, win);
	display_dvalue(dis_p->speed, win);
}

void 	is_dis_re(stock *s, br_dis *dis, sfRW *win)
{
	display_dvalue(dis->nameob, win);
	display_dvalue(dis->typeob, win);
	display_dvalue(dis->ad_life, win);
	display_dvalue(dis->ad_st, win);
	display_dvalue(dis->ad_supp, win);
	display_dvalue(dis->ad_speed, win);
	if (s != NULL) {
		SP_SPOS(s->stack->data->s->sp_ob, dis->obsq);
		SP_SCOL(s->stack->data->s->sp_ob, sfWhite);
		SP_DSP(win, s->stack->data->s->sp_ob, NULL);
	}
}

void	change_color(ts *ts)
{
	if (ts->str[1] == '+' && ts->str[2] == '0') {
		TXT_SCOL(ts->t, sfWhite);
		return;
	}
	if (ts->str[1] == '+')
		TXT_SCOL(ts->t, sfGreen);
	if (ts->str[1] == '-')
		TXT_SCOL(ts->t, sfRed);
}

void	is_dis_stadd(dis_stadd *ind, sfRW *win)
{
	change_color(ind->add_h);
	TXT_DTXT(win, ind->add_h->t, NULL);
	change_color(ind->add_st);
	TXT_DTXT(win, ind->add_st->t, NULL);
	change_color(ind->add_supp);
	TXT_DTXT(win, ind->add_supp->t, NULL);
	change_color(ind->add_speed);
	TXT_DTXT(win, ind->add_speed->t, NULL);
}
