/*
** EPITECH PROJECT, 2018
** animate_bars.c
** File description:
** rpg
*/

#include "prototype.h"

void	animate_main_bar(info_t *ginf, mob_t *mob, sfSprite *bar)
{
	int pos_y = 685;

	for (pers_t *player = ginf->perso; player; player = player->next) {
		sfSprite_setPosition(bar, (sfVector2f){1320, pos_y});
		sfRenderWindow_drawSprite(ginf->window, bar, NULL);
		sfSprite_setPosition(bar, (sfVector2f){1450, pos_y});
		sfRenderWindow_drawSprite(ginf->window, bar, NULL);
		pos_y += 50;
	}
	pos_y = 685;
	for (; mob; mob = mob->next) {
		sfSprite_setPosition(bar, (sfVector2f){260, pos_y});
		sfRenderWindow_drawSprite(ginf->window, bar, NULL);
		sfSprite_setPosition(bar, (sfVector2f){390, pos_y});
		sfRenderWindow_drawSprite(ginf->window, bar, NULL);
		pos_y += 50;
	}
}
