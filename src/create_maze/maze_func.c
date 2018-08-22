/*
** EPITECH PROJECT, 2018
** maze
** File description:
** func
*/

#include "maze.h"

void	maze_open_node(maze_t *maze, door_t door)
{
	if (door.node2 - door.node1 == 1 && maze->size.x != 1) {
		maze->array[door.node1] += EST;
		maze->array[door.node2] += OUEST;
	} else {
		maze->array[door.node1] += SOUTH;
		maze->array[door.node2] += NORTH;
	}
}

int	maze_node_find_in(node_t *list, int nb)
{
	for (; list; list = list->next) {
		if (list->nb == nb)
			return (1);
	}
	return (0);
}

int	maze_list_find(list_t *all, int nb, int all_size)
{
	for (int i = 0; i < all_size; i += 1) {
		if (maze_node_find_in(all[i].begin, nb))
			return (i);
	}
	return (-1);
}

int	maze_list_link(list_t *all, door_t door, int all_size)
{
	int tmp1= maze_list_find(all, door.node1, all_size);
	int tmp2 = maze_list_find(all, door.node2, all_size);

	if (tmp1 == -1 || tmp2 == -1)
		return (all_size);
	all[tmp1].end->next = all[tmp2].begin;
	all[tmp1].end = all[tmp2].end;
	all_size -= 1;
	all[tmp2] = all[all_size];
	return (all_size);
}

int	maze_door_open(maze_t *maze, door_t door, list_t *all, int all_size)
{
	maze_open_node(maze , door);
	all_size = maze_list_link(all, door, all_size);
	return (all_size);
}
