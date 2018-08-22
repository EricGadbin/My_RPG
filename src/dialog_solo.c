/*
** EPITECH PROJECT, 2018
** dialog solo
** File description:
** project my_rpg
*/

#include "../include/prototype.h"
#include "../include/struct.h"
#include "macrocsfml.h"

void	event_dialog_solo(pers_t *p, quest_t *q, int *i, int *n)
{
	if (KB_IKP(sfKeyReturn) &&
	(p->dl[p->idd].dl.ret_ob.top >= p->dl[p->idd].rectend) &&
	(*i) != 1) {
		(*i)++;
		p->idd++;
		(*q).qind++;
		*n = 1;
		return;
	}
	if (KB_IKP(sfKeyReturn) &&
	(p->dl[p->idd].dl.ret_ob.top != p->dl[p->idd].rectend) &&
	(*i) != 1) {
		p->dl[p->idd].dl.ret_ob.top += 192;
		SP_STREC(p->dl[p->idd].dl.sp_ob, p->dl[p->idd].dl.ret_ob);
		(*i)++;
	}
}

void	dialog_solo(info_t *ginf, pers_t *p, quest_t *q, sfSprite *sp)
{
	sfEvent event;
	int i[2] = {0, 0};
	s2f pdf[2] = {{0, 726}, {222, 716}};

	if (q->qind != p->dl[p->idd].keyd || cmp(p->dl[p->idd].st, "duo") == 0)
		return;
	while (sfRenderWindow_isOpen(ginf->window)) {
		while (sfRenderWindow_pollEvent(ginf->window, &event))
			event_dialog_solo(p, q, &i[0], &i[1]);
		if (i[1] == 1)
			return;
		RW_CLEAR(ginf->window, sfBlack);
		SP_DSP(ginf->window, sp, NULL);
		SP_SPOS(p->face[0].sp_ob, pdf[0]);
		SP_SPOS(p->dl[p->idd].dl.sp_ob, pdf[1]);
		SP_DSP(ginf->window, ginf->perso->app->sp_ob, NULL);
		SP_DSP(ginf->window, p->dl[p->idd].dl.sp_ob, NULL);
		SP_DSP(ginf->window, p->face[0].sp_ob, NULL);
		i[0] = 0;
		RW_DRW(ginf->window);
	}
}
