/*
** EPITECH PROJECT, 2018
** move_spell_rect.c
** File description:
** rpg
*/

#include "prototype.h"
#include "macrocsfml.h"

void move_rect_spell3(ob_t *tmp, int *j, int *finished, fight_t *info)
{
	if (tmp->ret_ob.left >= 192 * 4) {
		tmp->ret_ob.left = 0;
		if (tmp->ret_ob.top >= 192 * 2) {
			tmp->ret_ob.top = -192;
			SP_SPOS(info->perso->app->sp_ob,
			info->perso->pos_fight);
			*j = 0;
			*finished = 1;
		} else
			tmp->ret_ob.top += 192;
	} else
		tmp->ret_ob.left += 192;
}

void move_rect_spell2(info_t *game_info, int *finished)
{
	game_info->spell[1]->ret_ob.left = 0;
	if (game_info->spell[1]->ret_ob.top >= 256 * 3) {
		game_info->spell[1]->ret_ob.top = -256;
		*finished = 1;
	} else
		game_info->spell[1]->ret_ob.top += 256;
}

void move_rect_spell(info_t *game_info, int *finished)
{
	game_info->spell[0]->ret_ob.left = 0;
	if (game_info->spell[0]->ret_ob.top >= 192 * 3) {
		game_info->spell[0]->ret_ob.top = -192;
		*finished = 1;
	} else
		game_info->spell[0]->ret_ob.top += 192;
}
