/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** header
*/

#ifndef MY_H_
#define MY_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>
#include <time.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>

#define NORTH 1
#define EST 2
#define SOUTH 4
#define OUEST 8
#define CHECK 16
#define FAST 32
#define SCALING 50

typedef struct fast_s {
	int nb;
	struct fast_s *next;
	struct fast_s *prev;
} fast_t;

typedef struct door_s {
	int node1;
	int node2;
} door_t;

typedef struct node_s {
	int nb;
	struct node_s *next;
} node_t;

typedef struct list_s {
	node_t *begin;
	node_t *end;
} list_t;

typedef struct path_s {
	int nb;
	struct path_s *next;
	struct path_s *prev;
} path_t;

typedef struct maze_s {
	sfVector2i size;
	char *array;
	int in;
	int out;
} maze_t;

char    **add_spawn(char **map);
char	**converte_maze(maze_t *maze);
char	**add_spawn(char **map);
maze_t	*get_maze(int x, int y);
void    maze_fast_generate(maze_t *maze, sfRenderWindow *window);
path_t	*maze_solve(maze_t *maze, sfRenderWindow *window);
door_t  maze_door_select(door_t *door, int nb);
door_t  *maze_door_create(maze_t *maze, int *nb);
list_t  *maze_list_create(maze_t *maze);
void    maze_draw(maze_t *maze, sfRenderWindow *window, path_t *path, int);
int	my_getnbr(char *str);
int     my_strlen(char *str);
char	*get_next_line(int fd);
int     maze_door_open(maze_t *maze, door_t door, list_t *all, int all_size);
int     maze_list_link(list_t *all, door_t door, int all_size);
int     maze_list_find(list_t *all, int nb, int all_size);
int     maze_node_find_in(node_t *list, int nb);
void    maze_open_node(maze_t *maze, door_t door);

#endif /* MY_H_ */
