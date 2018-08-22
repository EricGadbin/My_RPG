/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** print_over
*/

#include "prototype.h"
#include "macrocsfml.h"
#include <stdio.h>

void	print_sprite(sfSprite *sprite, info_t *info, int i, int j)
{
	SP_SPOS(sprite, (sfVector2f){i * 60 +
	info->map.x, j * 60 + info->map.y});
	SP_DSP(info->window, sprite, NULL);
}

rain_t *init_rain(void)
{
	rain_t *list = NULL;
	rain_t *new;

	srand(time(NULL));
	for (int i = 0; i != 300; i++) {
		new = malloc(sizeof(*new));
		new->x = rand() % 8318 + 1;
		new->y = rand() % 898 + 1;
		new->speed = rand() % 5 + 10;
		new->stop = rand() % 598 + 280;
		new->next = list;
		list = new;
	}
	return (list);
}

void print_particule(info_t *game_info, rain_t *rain)
{
	for (int i = 0; i != rain->speed; i++) {
		my_put_pixe(game_info->buffer2, rain->x, rain->y,
		(sfColor){116, 185, 255, 255});
		rain->y++;
	}
}

void rain_particule(info_t *game_info, rain_t *rain)
{
	for (; rain; rain = rain->next) {
		if (rain->y > rain->stop) {
			rain->x = rand() % 8318 + 1;
			rain->speed = rand() % 5 + 10;
			rain->y = 0;
			rain->stop = rand() % 598 + 300;
		}
		else
			print_particule(game_info, rain);
	}
}

void	print_over(info_t *info, int **map)
{
	int i = 0;

	for (int j = 0; j < 45;) {
		if (map[j][i] == 52)
			print_sprite(info->tree->sp_ob, info, i, j);
		if (map[j][i] == 10)
			print_sprite(info->chimney->sp_ob, info, i, j);
		i += 1;
		j += i == 65 ? 1 : 0;
		i = i < 65 ? i : 0;
	}
}
