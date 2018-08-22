/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "maze.h"

void	maze_door_delete(door_t *door, int i, int *nb)
{
	*nb -= 1;
	door[i] = door[*nb];
}

void	maze_door_update(door_t *door, node_t *list, int *nb)
{
	for (int i = 0; i < *nb; i += 1) {
		if (maze_node_find_in(list, door[i].node1) &&
		maze_node_find_in(list, door[i].node2)) {
			maze_door_delete(door, i, nb);
			i -= 1;
		}
	}
}

int	maze_generate(maze_t *maze)
{
	int nb_door = 0;
	int all_size = maze->size.x * maze->size.y;
	list_t *all = maze_list_create(maze);
	door_t *door = maze_door_create(maze, &nb_door);
	door_t tmp;

	for (int i = 1; i < maze->size.x * maze->size.y; i += 1) {
		tmp = maze_door_select(door, nb_door);
		all_size = maze_door_open(maze, tmp, all, all_size);
		maze_door_update(door, all[maze_list_find(all,
			tmp.node1, all_size)].begin, &nb_door);
	}
	return (0);
}

maze_t	*maze_create(sfVector2i size)
{
	maze_t *maze = malloc(sizeof(*maze));

	if (!maze)
		return (NULL);
	maze->size = size;
	maze->array = malloc(sizeof(char) * (size.x * size.y));
	if (!maze->array) {
		free(maze);
		return (NULL);
	}
	for (int i = 0; i < size.x * size.y; i += 1)
		maze->array[i] = 0;
	return (maze);
}

maze_t	*get_maze(int x, int y)
{
	maze_t *maze = NULL;

	srand(time(NULL));
	maze = maze_create((sfVector2i){x, y});
	if (!maze)
		return (NULL);
	maze->in = 0;
	maze->out = maze->size.x * (maze->size.y - 1);
	maze_generate(maze);
	return (maze);
}
