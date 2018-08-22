/*
** EPITECH PROJECT, 2018
** dialog duo
** File description:
** project my_rpg
*/

#include "../include/prototype.h"
#include "../include/struct.h"
#include "macrocsfml.h"

void event_dialog_duo(dialog_t *dial, int *i, int *n)
{
	if (KB_IKP(sfKeyReturn) && (dial->dl.ret_ob.top >= dial->rectend) &&
	(*i) != 1) {
		dial->dl.ret_ob.top = 0;
		*n = 1;
	}
	if (KB_IKP(sfKeyReturn) && (dial->dl.ret_ob.top != dial->rectend) &&
	(*i) != 1) {
		dial->dl.ret_ob.top += 192;
		SP_STREC(dial->dl.sp_ob, dial->dl.ret_ob);
		(*i)++;
	}
}

void dialog_duo_func(info_t *ginf, dialog_t *dial,
ob_t *save[2], sfSprite *sp)
{
	s2f pdf[3] = {{0, 726}, {1408, 726}, {222, 716}};

	RW_CLEAR(ginf->window, sfBlack);
	SP_DSP(ginf->window, sp, NULL);
	SP_SPOS(save[1]->sp_ob, pdf[1]);
	SP_SPOS(save[0]->sp_ob, pdf[0]);
	SP_SPOS(dial->dl.sp_ob, pdf[2]);
	print_over(ginf, ginf->village_map);
	SP_DSP(ginf->window, ginf->perso->app->sp_ob, NULL);
	if (ginf->quest.qind == 2) {
		SP_DSP(ginf->window, ginf->pnj[0].app.sp_ob, NULL);
		SP_DSP(ginf->window,
		ginf->perso->next->app->sp_ob, NULL);
	}
	add_fade_rain(ginf->buffer2);
	disp_particules(ginf, ginf->rain);
	SP_DSP(ginf->window, dial->dl.sp_ob, NULL);
	SP_DSP(ginf->window, save[0]->sp_ob, NULL);
	SP_DSP(ginf->window, save[1]->sp_ob, NULL);
}

void dialog_duo(info_t *ginf, dialog_t *dial, ob_t *save[2], sfSprite *sp)
{
	sfEvent event;
	int i[2] = {0, 0};

	while (sfRenderWindow_isOpen(ginf->window)) {
		while (sfRenderWindow_pollEvent(ginf->window, &event))
			event_dialog_duo(dial, &i[0], &i[1]);
		if (i[1] == 1) {
			dial->dl.ret_ob.top = 0;
			SP_STREC(dial->dl.sp_ob, dial->dl.ret_ob);
			return;
		}
		dialog_duo_func(ginf, dial, save, sp);
		i[0] = 0;
		RW_DRW(ginf->window);
	}
}
