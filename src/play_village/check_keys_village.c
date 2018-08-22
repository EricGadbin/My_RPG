/*
** EPITECH PROJECT, 2018
** check_keys.c
** File description:
** rpg
*/

#include "prototype.h"
#include "macrocsfml.h"

void	check_key_left_village(info_t *ginf,
sfEvent event, int **map, s2f sprite)
{
	if (event.type == sfEvtKeyPressed && event.key.code == sfKeyLeft) {
		if (check_collision_village(ginf, map, (s2f){15, 0}))
			move_player_village(ginf, (s2f){15, 0}, sprite);
		ginf->perso->app->ret_ob.top = 240;
	}
}

void	check_key_right_village(info_t *ginf,
sfEvent event, int **map, s2f sprite)
{
	if (event.type == sfEvtKeyPressed && event.key.code == sfKeyRight) {
		if (check_collision_village(ginf, map, (s2f){-15, 0}))
			move_player_village(ginf, (s2f){-15, 0}, sprite);
		ginf->perso->app->ret_ob.top = 288;
	}
}

void	check_key_up_village(info_t *ginf,
sfEvent event, int **map, s2f sprite)
{
	if (event.type == sfEvtKeyPressed && event.key.code == sfKeyUp) {
		if (check_collision_village(ginf, map, (s2f){0, 15}))
			move_player_village(ginf, (s2f){0, 15}, sprite);
		ginf->perso->app->ret_ob.top = 336;
	}
}
void	check_key_down_village(info_t *ginf,
sfEvent event, int **map, s2f sprite)
{
	if (event.type == sfEvtKeyPressed && event.key.code == sfKeyDown) {
		if (check_collision_village(ginf, map, (s2f){0, -15}))
			move_player_village(ginf, (s2f){0, -15}, sprite);
		ginf->perso->app->ret_ob.top = 192;
	}
}

void	check_key_village(info_t *ginf,
sfEvent event, int **map, s2f sprite)
{
	if (event.type == sfEvtKeyPressed &&
	event.key.code == sfKeyEscape) {
		ginf->pause = 0;
		select_pause_menu(ginf);
	}
	if (event.type == sfEvtKeyPressed &&
	event.key.code == sfKeyF)
		check_interaction_village(ginf);
	check_key_left_village(ginf, event, map, sprite);
	check_key_right_village(ginf, event, map, sprite);
	check_key_up_village(ginf, event, map, sprite);
	check_key_down_village(ginf, event, map, sprite);
}
