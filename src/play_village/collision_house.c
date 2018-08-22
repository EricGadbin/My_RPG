/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** collision
*/

#include "prototype.h"

int	manage_collision_house1(sfVector2f pos, int x, int y)
{
	if (x > pos.x && x < pos.x + 60 && y > pos.y && y < pos.y + 60)
		return (1);
	if (x + 30 > pos.x && x + 30 < pos.x +
	60 && y > pos.y && y < pos.y + 60)
		return (1);
	if (x + 30 > pos.x && x + 30 < pos.x + 60 && y +
	30 > pos.y && y + 30 < pos.y + 60)
		return (1);
	if (x > pos.x && x < pos.x + 60 && y + 30 >
	pos.y && y + 30 < pos.y + 60)
		return (1);
	return (0);
}

int	check_node_house(info_t *game_info, int x, int y, sfVector2f move)
{
	sfVector2f pos;
	int a = 0;

	pos.x = game_info->perso->app->pos_ob.x;
	pos.y = game_info->perso->app->pos_ob.y + 30;
	x = x * 30 + move.x + 255;
	y = y * 30 + move.y + 90;
	a += manage_collision_house1(pos, x, y);
	return ((a > 0) ? 1 : 0);
}

int	check_collision_house(info_t *info, int **map, sfVector2f move)
{
	int i = 0;

	for (int j = 0; j < 26;) {
		if (map[j][i] == 2 &&
		check_node_house(info, i, j, move))
			return (0);
		i += 1;
		j += i == 37 ? 1 : 0;
		i = i < 37 ? i : 0;
	}
	return (1);
}
