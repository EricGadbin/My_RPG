/*
** EPITECH PROJECT, 2018
** check_keys.c
** File description:
** rpg
*/

#include "prototype.h"
#include "macrocsfml.h"

void	check_key_left_house(info_t *ginf, sfEvent event, int **map)
{
	if (event.type == sfEvtKeyPressed && event.key.code == sfKeyLeft) {
		ginf->perso->app->ret_ob.top = 240;
		if (check_collision_house(ginf, map, (s2f){15, 0}))
			ginf->perso->app->pos_ob.x -= 15;
	}
}

void	check_key_right_house(info_t *ginf, sfEvent event, int **map)
{
	if (event.type == sfEvtKeyPressed && event.key.code == sfKeyRight) {
		ginf->perso->app->ret_ob.top = 288;
		if (check_collision_house(ginf, map, (s2f){-15, 0}))
			ginf->perso->app->pos_ob.x += 15;
	}
}

void	check_key_up_house(info_t *ginf, sfEvent event, int **map)
{
	if (event.type == sfEvtKeyPressed && event.key.code == sfKeyUp) {
		ginf->perso->app->ret_ob.top = 336;
		if (check_collision_house(ginf, map, (s2f){0, 15}))
			ginf->perso->app->pos_ob.y -= 15;
	}
}
void	check_key_down_house(info_t *ginf, sfEvent event, int **map)
{
	if (event.type == sfEvtKeyPressed && event.key.code == sfKeyDown) {
		ginf->perso->app->ret_ob.top = 192;
		if (check_collision_house(ginf, map, (s2f){0, -15}))
			ginf->perso->app->pos_ob.y += 15;
	}
}

void	check_key_house(info_t *ginf, sfEvent event, int **map)
{
	if (event.type == sfEvtKeyPressed &&
	event.key.code == sfKeyEscape) {
		ginf->pause = 0;
		select_pause_menu(ginf);
	}
	check_key_left_house(ginf, event, map);
	check_key_right_house(ginf, event, map);
	check_key_up_house(ginf, event, map);
	check_key_down_house(ginf, event, map);
}
