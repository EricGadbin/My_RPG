/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** collision
*/

#include "prototype.h"

int manage_collision_village1(sfVector2f pos, int x, int y)
{
	if (pos.x >= x && pos.x < x + 60 && pos.y > y && pos.y < y + 60)
		return (1);
	if (pos.x + 60 > x && pos.x + 60 <= x + 60 &&
	pos.y > y && pos.y < y + 60)
		return (1);
	if (pos.x + 60 > x && pos.x + 60 <= x + 60 &&
	pos.y + 30 > y && pos.y + 30 < y + 60)
		return (1);
	return (0);
}

int manage_collision_village2(sfVector2f pos, sfVector2f move, int x, int y)
{
	if (pos.x >= x && pos.x < x + 60 && pos.y + 30 > y
	&& pos.y + 30 < y + 60)
		return (1);
	if (pos.x + move.x * -1 < 0 || pos.x + move.x * -1 >= 1600 - 45)
		return (1);
	if (pos.y - 30 + move.y * -1 < 0 || pos.y + move.y * -1 >= 900 - 15)
		return (1);
	return (0);
}

int     check_node_village(info_t *game_info, int x, int y, sfVector2f move)
{
	sfVector2f pos;
	int a = 0;

	pos.x = game_info->perso->app->pos_ob.x;
	pos.y = game_info->perso->app->pos_ob.y + 30;
	x = x * 60 + game_info->map.x + move.x;
	y = y * 60 + game_info->map.y + move.y;
	a += manage_collision_village1(pos, x, y);
	a += manage_collision_village2(pos, move, x, y);
	return ((a > 0) ? 1 : 0);
}

int	check_tile(int tile)
{
	int tab[23] = {364, 192, 214, 236, 238, 183, 182, 52, 165, 166,
	140, 118, 96, 74, 109, 284, 87, 131, 153, 175, 197, 10, 12};

	for (int i = 0; i < 23; i += 1) {
		if (tile == tab[i])
			return (0);
	}
	return (1);
}

int     check_collision_village(info_t *info, int **map, sfVector2f move)
{
	int i = 0;

	for (int j = 0; j < 45;) {
		if (check_tile(map[j][i]) &&
		check_node_village(info, i, j, move))
			return (0);
		i += 1;
		j += i == 65 ? 1 : 0;
		i = i < 65 ? i : 0;
	}
	return (1);
}
