/*
** EPITECH PROJECT, 2018
** animate_bars.c
** File description:
** rpg
*/

#include "prototype.h"

void	animate_life_bar(info_t *ginf, mob_t *mob, sfSprite *life_bar)
{
	float ratio = 0;
	int pos_y = 687;

	for (pers_t *player = ginf->perso; player; player = player->next) {
		sfSprite_setPosition(life_bar, (sfVector2f){1323, pos_y});
		ratio = player->health / player->stats->health;
		ratio = ratio < 0 ? 0 : ratio;
		sfSprite_setScale(life_bar, (sfVector2f){ratio, 1});
		sfRenderWindow_drawSprite(ginf->window, life_bar, NULL);
		pos_y += 50;
	}
	pos_y = 687;
	for (; mob; mob = mob->next) {
		sfSprite_setPosition(life_bar, (sfVector2f){263, pos_y});
		ratio = mob->health / mob->stats->health;
		ratio = ratio < 0 ? 0 : ratio;
		sfSprite_setScale(life_bar, (sfVector2f){ratio , 1});
		sfRenderWindow_drawSprite(ginf->window, life_bar, NULL);
		pos_y += 50;
	}
}
