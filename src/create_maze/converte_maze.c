/*
** EPITECH PROJECT, 2018
** maze
** File description:
** converte
*/

#include "maze.h"
#include "printf.h"

char	**fill_map(char **map, maze_t *maze)
{
	int a = 1;
	int b = 1;

	for (int i = 0; i < maze->size.y * maze->size.x;
		i += 1, a += 2, b += a == 1 ? 2 : 0) {
		if ((maze->array[i] & EST) == 0)
			map[b][a + 1] = 48;
		if ((maze->array[i] & SOUTH) == 0)
			map[b + 1][a] = 48;
		if (a == maze->size.x * 2 - 1)
			a = -1;
	}
	for (int i = 2; i < maze->size.y * 2; i += 2) {
		for (int j = 2; j < maze->size.x * 2; j += 2, a = 0)
			map[i][j] = 48;
	}
	map[maze->size.y * 2 + 1] = NULL;
	for (int i = 0; map[i]; i += 1)
		map[i][maze->size.x * 2 + 1] = 0;
	return (add_spawn(map));
}

char	**converte_maze(maze_t *maze)
{
	char **map = malloc(sizeof(char*) * (maze->size.y * 2 + 2));

	if (!map)
		return (NULL);
	for (int i = 0; i < maze->size.y * 2 + 1; i += 1) {
		map[i] = malloc(sizeof(char) * (maze->size.x * 2 + 2));
		if (!map[i])
			return (NULL);
		for (int j = 0; j < maze->size.x * 2 + 1; j += 1)
			map[i][j] = 49;
	}
	for (int i = 0; i < maze->size.x * 2 + 1; i += 1) {
		map[0][i] = 48;
		map[maze->size.y * 2][i] = 48;
	}
	for (int i = 0; i < maze->size.y * 2 + 1; i += 1) {
		map[i][0] = 48;
		map[i][maze->size.x * 2] = 48;
	}
	return (fill_map(map, maze));
}
