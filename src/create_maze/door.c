/*
** EPITECH PROJECT, 2018
** maze
** File description:
** door
*/

#include "maze.h"

void	maze_door_add_south(maze_t *maze, int index, door_t *tab, int *j)
{
	if (index / maze->size.x + 1 == maze->size.y)
		return;
	tab[*j].node1 = index;
	tab[*j].node2 = index + maze->size.x;
	*j += 1;
}

void	maze_door_add_est(maze_t *maze, int index, door_t *tab, int *j)
{
	if (index % maze->size.x + 1 == maze->size.x)
		return;
	tab[*j].node1 = index;
	tab[*j].node2 = index + 1;
	*j += 1;
}

door_t	*maze_door_create(maze_t *maze, int *nb)
{
	door_t *tab = malloc(sizeof(*tab) * (maze->size.x * maze->size.y
		* 2 - maze->size.x - maze->size.y));
	int j = 0;

	if (!tab)
		return (NULL);
	*nb = maze->size.x * maze->size.y * 2 - maze->size.x - maze->size.y;
	for (int i = 0; i < maze->size.x * maze->size.y; i += 1) {
		maze_door_add_est(maze, i, tab, &j);
		maze_door_add_south(maze, i, tab, &j);
	}
	return (tab);
}

door_t	maze_door_select(door_t *door, int nb)
{
	return (door[rand() % nb]);
}
