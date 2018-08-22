/*
** EPITECH PROJECT, 2018
** enter_village.c
** File description:
** rpg
*/

#include "prototype.h"

void move_magi(info_t *ginf)
{
	sfTime time = sfClock_getElapsedTime(ginf->clock4);
	float seconds = time.microseconds / 1000000.0;
	static int a = 1;

	if (seconds > 0.3) {
		if (ginf->pnj[0].app.ret_ob.left == 288)
			a = 1;
		if (ginf->pnj[0].app.ret_ob.left == 352)
			a = -1;
		ginf->pnj[0].app.ret_ob.left += 32 * a;
		ginf->perso->next->app->ret_ob.left += 48 * a;
		sfClock_restart(ginf->clock4);
	}
	SP_STREC(ginf->pnj[0].app.sp_ob, ginf->pnj[0].app.ret_ob);
	SP_STREC(ginf->perso->next->app->sp_ob,
	ginf->perso->next->app->ret_ob);
}

void cutscene_display2(info_t *game_info, int *a)
{
	static int i = 0;
	static int b = 0;

	if (i == 0) {
		b = *a;
		i++;
	}
	SP_DSP(game_info->window, game_info->village->sp_ob, NULL);
	SP_DSP(game_info->window, game_info->perso->app->sp_ob, NULL);
	SP_DSP(game_info->window, game_info->perso->next->app->sp_ob, NULL);
	print_over(game_info, game_info->village_map);
	SP_SPOS(game_info->pnj[0].app.sp_ob, (sfVector2f){250, 800 - (*a)});
	SP_SPOS(game_info->perso->next->app->sp_ob,
	(sfVector2f){195, 800 - b});
	SP_DSP(game_info->window, game_info->pnj[0].app.sp_ob, NULL);
	add_fade_rain(game_info->buffer2);
	disp_particules(game_info, game_info->rain);
	RW_DRW(game_info->window);
	b += 2;
}

void cutscene2(info_t *game_info, int *i, int *j, int *a)
{
	if (*i == 0 && *j != 0) {
		check_dialog(game_info, 0, game_info->village->sp_ob);
		(*i)++;
	}
	while (*j == 1) {
		check_event_none(game_info);
		move_magi(game_info);
		game_info->pnj[0].app.ret_ob.top = 128;
		cutscene_display2(game_info, a);
		*a -= 2;
		if (*a <= -100)
			(*j)++;
	}
}

void cutscene_display(info_t *game_info, int *a)
{
	game_info->pnj[0].app.ret_ob.top = 224;
	game_info->perso->next->app->ret_ob.top = 336;
	SP_DSP(game_info->window, game_info->village->sp_ob, NULL);
	SP_DSP(game_info->window, game_info->perso->app->sp_ob, NULL);
	print_over(game_info, game_info->village_map);
	SP_SPOS(game_info->pnj[0].app.sp_ob, (sfVector2f){250, 800 - (*a)});
	SP_SPOS(game_info->perso->next->app->sp_ob,
	(sfVector2f){195, 800 - (*a)});
	SP_DSP(game_info->window, game_info->pnj[0].app.sp_ob, NULL);
	SP_DSP(game_info->window, game_info->perso->next->app->sp_ob, NULL);
	add_fade_rain(game_info->buffer2);
	disp_particules(game_info, game_info->rain);
	RW_DRW(game_info->window);
}

void cutscene(info_t *game_info)
{
	static int i = 0;
	static int j = 0;
	static int a = 0;

	while (j == 0) {
		check_event_none(game_info);
		cutscene_display(game_info, &a);
		move_magi(game_info);
		a += 2;
		if (a == 140)
			j += 1;
	}
	cutscene2(game_info, &i, &j, &a);
}
