/*
** EPITECH PROJECT, 2018
** maze
** File description:
** list
*/

#include "maze.h"

list_t	*maze_list_create(maze_t *maze)
{
	list_t *all = malloc(sizeof(*all) * maze->size.x * maze->size.y);

	if (!all)
		return (NULL);
	for (int i = 0; i < maze->size.x * maze->size.y; i += 1) {
		all[i].begin = malloc(sizeof(node_t));
		if (!all[i].begin)
			return (NULL);
		all[i].begin->nb = i;
		all[i].begin->next = NULL;
		all[i].end = all[i].begin;
	}
	return (all);
}
