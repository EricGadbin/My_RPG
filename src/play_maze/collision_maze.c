/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** collision
*/

#include "prototype.h"
#include "macrocsfml.h"

int	check_node(info_t *game_info, int x, int y, s2f move)
{
	s2f pos;

	pos.x = game_info->perso->app->pos_ob.x;
	pos.y = game_info->perso->app->pos_ob.y + 30;
	x = x * 180 + game_info->map.x + move.x;
	y = y * 180 + game_info->map.y + move.y;
	if (pos.x > x && pos.x < x + 180 && pos.y > y && pos.y < y + 180)
		return (1);
	if (pos.x + 60 > x && pos.x + 60 < x + 180 &&
	pos.y > y && pos.y < y + 180)
		return (1);
	if (pos.x + 60 > x && pos.x + 60 < x + 180 &&
	pos.y + 30 > y && pos.y + 30 < y + 180)
		return (1);
	if (pos.x > x && pos.x < x + 180 &&
	pos.y + 30 > y && pos.y + 30 < y + 180)
		return (1);
	return (0);
}

int	check_chest(info_t *game_info, int x, int y, s2f move)
{
	s2f pos;

	pos.x = game_info->perso->app->pos_ob.x;
	pos.y = game_info->perso->app->pos_ob.y + 30;
	x = x * 180 + game_info->map.x + move.x + 60;
	y = y * 180 + game_info->map.y + move.y + 60;
	if (pos.x >= x && pos.x < x + 60 && pos.y > y && pos.y < y + 60)
		return (1);
	if (pos.x + 60 > x && pos.x + 60 <= x + 60 &&
	pos.y > y && pos.y < y + 60)
		return (1);
	if (pos.x + 60 > x && pos.x + 60 <= x + 60 &&
	pos.y + 30 > y && pos.y + 30 < y + 60)
		return (1);
	if (pos.x >= x && pos.x < x + 60 &&
	pos.y + 30 > y && pos.y + 30 < y + 60)
		return (1);
	return (0);
}

int	check_mob(info_t *game_info, int x, int y, s2f move)
{
	s2f pos;

	pos.x = game_info->perso->app->pos_ob.x;
	pos.y = game_info->perso->app->pos_ob.y + 30;
	x = x * 180 + game_info->map.x + move.x + 15;
	y = y * 180 + game_info->map.y + move.y + 15;
	if (pos.x >= x && pos.x < x + 150 && pos.y > y && pos.y < y + 150)
		return (1);
	if (pos.x + 60 > x && pos.x + 60 <= x + 150 &&
	pos.y > y && pos.y < y + 150)
		return (1);
	if (pos.x + 60 > x && pos.x + 60 <= x + 150 &&
	pos.y + 30 > y && pos.y + 30 < y + 150)
		return (1);
	if (pos.x >= x && pos.x < x + 150 &&
	pos.y + 30 > y && pos.y + 30 < y + 150)
		return (1);
	return (0);
}

int	check_collision(info_t *game_info, char **map, s2f move, int i)
{
	mob_t *mob = NULL;

	for (int j = 0; j < 41;) {
		if  ((map[j][i] == 48 || map[j][i] == 42) &&
		check_node(game_info, i, j, move))
			return (0);
		if ((map[j][i] == 50 || map[j][i] == 47) &&
		check_chest(game_info, i, j, move))
			return (0);
		if (map[j][i] > 50 && check_mob(game_info, i, j, move)) {
			mob = create_mob_list(game_info, map[j][i] - 50,
			get_nb_perso(game_info->perso));
			start_battle(game_info, mob);
			map[j][i] = 49;
		}
		i += 1;
		j += i == 41 ? 1 : 0;
		i = i < 41 ? i : 0;
	}
	return (1);
}
