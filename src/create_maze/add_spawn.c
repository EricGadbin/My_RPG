/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** maze spawn
*/

#include "prototype.h"

void	check_spawn_chest(char **map, int i, int j)
{
	int wall = 0;

	if (map[i][j] == 48)
		return;
	if (map[i + 1][j] == 48)
		wall += 1;
	if (map[i - 1][j] == 48)
		wall += 1;
	if (map[i][j - 1] == 48)
		wall += 1;
	if (map[i][j + 1] == 48)
		wall += 1;
	if (wall == 3 && rand() % 100 >= 80)
		map[i][j] = 50;
}

void	check_spawn_mob(char **map, int i, int j)
{
	if (map[i][j] == 48 || map[i][j] == 50)
		return;
	if (rand() % 100 >= 90)
		map[i][j] = 50 + rand() % 3 + 1;
}

void	spawn_boss_door(char **map)
{
	int x = 0;
	int y = 0;

	while (x + y < 40 || map[y][x] != 48 || map[y + 1][x] == 48) {
		x = rand() % 38 + 1;
		y = rand() % 38 + 1;
	}
	my_printf("Here is a little help for you to correct our RPG: \
	\nCoordinate of the Boss door:\nx = %d\ny = %d\n", x, y);
	map[y][x] = 42;
}

char	**add_spawn(char **map)
{
	for (int i = 1; i < 40; i += 1) {
		for (int j = 1; j < 40; j += 1) {
			check_spawn_chest(map, i, j);
			check_spawn_mob(map, i, j);
		}
	}
	spawn_boss_door(map);
	map[1][1] = 49;
	return (map);
}
