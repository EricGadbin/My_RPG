/*
** EPITECH PROJECT, 2018
** animating_attack.c
** File description:
** rpg
*/

#include "prototype.h"
#include "macrocsfml.h"

void animating_group_attack(info_t *game_info, int attack, int *finished)
{
	if (attack == 4) {
		sfSprite_setScale(game_info->spell[0]->sp_ob,
		(sfVector2f){3, 3});
		SP_SPOS(game_info->spell[0]->sp_ob,
		(sfVector2f){960, 100});
		move_spell(game_info, finished);
		SP_DSP(game_info->window,
		game_info->spell[0]->sp_ob, NULL);
	} else if (attack == 2) {
		move_spell2(game_info, finished);
		SP_DSP(game_info->window,
		game_info->spell[1]->sp_ob, NULL);
	}
}

void	animating_perso1(info_t *game_info, int attack, int *finished,
	fight_t *info)
{
	if (attack == 1 && info->id == 0) {
		SP_SPOS(game_info->spell[2]->sp_ob,
		(sfVector2f){500 - 120 * info->target, 400});
		move_spell3(game_info, finished, info);
		SP_DSP(game_info->window,
		game_info->spell[2]->sp_ob, NULL);
	} else if (attack == 1 && info->id == 1) {
		SP_SPOS(game_info->spell[3]->sp_ob,
		(sfVector2f){500 - 120 * info->target, 400});
		move_spell3(game_info, finished, info);
		SP_DSP(game_info->window,
		game_info->spell[3]->sp_ob, NULL);
	}
}

void	animating_perso2(info_t *game_info, int attack, int *finished,
	fight_t *info)
{
	if (attack == 1 && info->id == 2) {
		SP_SPOS(game_info->spell[4]->sp_ob,
		(sfVector2f){500 - 120 * info->target, 400});
		move_spell3(game_info, finished, info);
		SP_DSP(game_info->window,
		game_info->spell[4]->sp_ob, NULL);
	} else if (attack == 1 && info->id == 3) {
		SP_SPOS(game_info->spell[5]->sp_ob,
		(sfVector2f){500 - 120 * info->target, 400});
		move_spell3(game_info, finished, info);
		SP_DSP(game_info->window,
		game_info->spell[5]->sp_ob, NULL);
	}
}

void	animating_attack(info_t *game_info, int attack, int *finished,
	fight_t *info)
{
	pers_t *tmp = game_info->perso;

	for (int i = 0; i < info->target && tmp; i += 1, tmp = tmp->next);
	animating_group_attack(game_info, attack, finished);
	if (attack == 3) {
		sfSprite_setScale(game_info->spell[0]->sp_ob,
		(sfVector2f){0.7, 0.7});
		SP_SPOS(game_info->spell[0]->sp_ob,
		(sfVector2f){tmp->pos_fight.x - 35,
		tmp->pos_fight.y - 35});
		move_spell(game_info, finished);
		SP_DSP(game_info->window,
		game_info->spell[0]->sp_ob, NULL);
	}
	animating_perso1(game_info, attack, finished, info);
	animating_perso2(game_info, attack, finished, info);
}

int	select_attack(info_t *game_info,
fight_t *info, mob_t *mob, pers_t *perso)
{
	pers_t *player = game_info->perso;

	if (info->action == 12 && info->select == 1) {
		for (int i = info->target; i != 0; i--, mob = mob->next);
		player_attack(perso, game_info->perso, mob, 1);
		info->select = 84;
		return (1);
	}
	if (info->action == 12 && info->select == 3) {
		for (int i = info->target; i != 0; i--, player = player->next);
		player_attack(perso, player, mob, 3);
		info->select = 84;
		return (3);
	}
	if (info->action == 2 || info->action == 4) {
		player_attack(perso, game_info->perso, mob, info->action);
		return (info->action);
	}
	return (0);
}
