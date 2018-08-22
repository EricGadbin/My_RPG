/*
** EPITECH PROJECT, 2018
** move_player.c
** File description:
** rpg
*/

#include "prototype.h"
#include "macrocsfml.h"

void	move_player(info_t *game_info, s2f move)
{
	s2f tmp;

	tmp.x = game_info->map.x + move.x;
	tmp.y = game_info->map.y + move.y;
	if (tmp.x <= 0 && tmp.x >= -(41 * 180) + 1600 &&
	game_info->perso->app->pos_ob.x == 765)
		game_info->map.x += move.x;
	else
		game_info->perso->app->pos_ob.x += move.x * -1;
	if (tmp.y <= 0 && tmp.y >= -(41 * 180) + 900 &&
	game_info->perso->app->pos_ob.y == 420)
		game_info->map.y += move.y;
	else
		game_info->perso->app->pos_ob.y += move.y * -1;
}

void	move_player_village(info_t *game_info, s2f move, s2f sprite)
{
	s2f tmp;

	tmp.x = game_info->map.x + move.x;
	tmp.y = game_info->map.y + move.y;
	if (tmp.x <= 0 && tmp.x >= -(3900) + 1600 &&
	game_info->perso->app->pos_ob.x == 765) {
		game_info->map.x += move.x;
		SP_SPOS(game_info->buffer2->sprite,
		(sfVector2f){sprite.x + move.x, sprite.y});
	} else
		game_info->perso->app->pos_ob.x += move.x * -1;
	if (tmp.y <= 0 && tmp.y >= -(2700) + 900 &&
	game_info->perso->app->pos_ob.y == 420)
		game_info->map.y += move.y;
	else
		game_info->perso->app->pos_ob.y += move.y * -1;
}
