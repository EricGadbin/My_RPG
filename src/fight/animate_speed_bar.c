/*
** EPITECH PROJECT, 2018
** animate_bars.c
** File description:
** rpg
*/

#include "prototype.h"

void animate_speed_bar(info_t *ginf, mob_t *mob, sfSprite *speed_bar)
{
	int pos_y = 687;

	for (pers_t *player = ginf->perso; player; player = player->next) {
		sfSprite_setPosition(speed_bar, (sfVector2f){1453, pos_y});
		sfSprite_setScale(speed_bar,
		(sfVector2f){player->speed / 100, 1});
		sfRenderWindow_drawSprite(ginf->window, speed_bar, NULL);
		pos_y += 50;
	}
	pos_y = 687;
	for (; mob; mob = mob->next) {
		sfSprite_setPosition(speed_bar, (sfVector2f){393, pos_y});
		sfSprite_setScale(speed_bar,
		(sfVector2f){mob->speed / 100, 1});
		sfRenderWindow_drawSprite(ginf->window, speed_bar, NULL);
		pos_y += 50;
	}
}
