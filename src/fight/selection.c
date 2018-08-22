/*
** EPITECH PROJECT, 2018
** selection.c
** File description:
** rpg
*/

#include "prototype.h"

void set_arrow_pos(info_t *ginf, mob_t *mob, fight_t *info)
{
	int nb = 0;
	pers_t *tmp = ginf->perso;

	for (nb = 0; mob->health <= 0; nb += 1, mob = mob->next);
	info->pos1 = 540 - nb * 120;
	for (nb = 0; tmp && tmp->health <= 0; nb += 1, tmp = tmp->next);
	info->pos2 = 1100 + nb * 80;
}

void init_arrow_pos(int action, sfSprite *arrow, fight_t *info)
{
	if (action == 1) {
		sfSprite_setPosition(arrow, (sfVector2f){info->pos1, 320});
		sfSprite_setTextureRect(arrow, (sfIntRect){0, 0, 32, 32});
	} else if (action == 3) {
		sfSprite_setPosition(arrow, (sfVector2f){info->pos2, 320});
		sfSprite_setTextureRect(arrow, (sfIntRect){96, 0, 32, 32});
	}
}

void move_arrow_heal(int action, fight_t *info, info_t *ginf, sfSprite *arrow)
{
	pers_t *tmp = ginf->perso;
	int nb = (info->pos2 - 1100) / 80;

	for (int i = 0; i < nb; i += 1, tmp = tmp->next);
	if (action == 10) {
		for (nb = 0; tmp && (tmp->health <= 0 || !nb);
		nb += 1, tmp = tmp->prev);
		if (tmp)
			info->pos2 -= nb * 80;
	}
	if (action == 11) {
		for (nb = 0; tmp && (tmp->health <= 0 || !nb);
		nb += 1, tmp = tmp->next);
		if (tmp)
			info->pos2 += nb * 80;
	}
	sfSprite_setPosition(arrow, (sfVector2f){info->pos2, 320});
}

void move_arrow_attack(int action, fight_t *info, mob_t *mob, sfSprite *arrow)
{
	int nb = (540 - info->pos1) / 120;

	for (int i = 0; i < nb; i += 1, mob = mob->next);
	if (action == 10) {
		for (nb = 0; mob && (mob->health <= 0 || !nb);
		nb += 1, mob = mob->next);
		if (mob)
			info->pos1 -= nb * 120;
	}
	if (action == 11) {
		for (nb = 0; mob && (mob->health <= 0 || !nb);
		nb += 1, mob = mob->prev);
		if (mob)
			info->pos1 += nb * 120;
	}
	sfSprite_setPosition(arrow, (sfVector2f){info->pos1, 320});
}

void manage_arrow(info_t *game_info, fight_t *info, mob_t *mob,
sfSprite *arrow)
{
	if (info->action == 1 || info->action == 3)
		set_arrow_pos(game_info, mob, info);
	init_arrow_pos(info->action, arrow, info);
	info->select = info->action == 1 || info->action == 3 ?
	info->action : info->select;
	if (info->select == 3) {
		move_arrow_heal(info->action, info, game_info, arrow);
		sfRenderWindow_drawSprite(game_info->window, arrow, NULL);
	}
	if (info->select == 1) {
		move_arrow_attack(info->action, info, mob, arrow);
		sfRenderWindow_drawSprite(game_info->window, arrow, NULL);
	}
}
