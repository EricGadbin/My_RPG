/*
** EPITECH PROJECT, 2018
** maze.c
** File description:
** rpg
*/

#include "prototype.h"
#include "maze.h"
#include "macrocsfml.h"

void move_spell3(info_t *game_info, int *finished, fight_t *info)
{
	sfTime time = sfClock_getElapsedTime(game_info->clock3);
	float seconds = time.microseconds / 1000000.0;
	ob_t *tmp = game_info->spell[info->id + 2];
	static int j = 0;

	if (seconds > 0.05) {
		if (j < 10)
			info->perso->pos_fight.x -= 5;
		else
			info->perso->pos_fight.x += 5;
		SP_SPOS(info->perso->app->sp_ob, info->perso->pos_fight);
		j += 1;
		move_rect_spell3(tmp, &j, finished, info);
		sfClock_restart(game_info->clock3);
	}
	SP_STREC(tmp->sp_ob, tmp->ret_ob);
}

void move_spell2(info_t *game_info, int *finished)
{
	sfTime time = sfClock_getElapsedTime(game_info->clock4);
	float seconds = time.microseconds / 1000000.0;

	if (seconds > 0.025) {
		if (game_info->spell[1]->ret_ob.left >= 256 * 7) {
			move_rect_spell2(game_info, finished);
		} else
			game_info->spell[1]->ret_ob.left += 256;
		sfClock_restart(game_info->clock4);
	}
	SP_STREC(game_info->spell[1]->sp_ob,
	game_info->spell[1]->ret_ob);
}

void move_spell(info_t *game_info, int *finished)
{
	sfTime time = sfClock_getElapsedTime(game_info->clock3);
	float seconds = time.microseconds / 1000000.0;

	if (seconds > 0.05) {
		if (game_info->spell[0]->ret_ob.left >= 192 * 4) {
			move_rect_spell(game_info, finished);
		} else
			game_info->spell[0]->ret_ob.left += 192;
		sfClock_restart(game_info->clock3);
	}
	SP_STREC(game_info->spell[0]->sp_ob, game_info->spell[0]->ret_ob);
}
