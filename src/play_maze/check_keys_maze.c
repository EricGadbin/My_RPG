/*
** EPITECH PROJECT, 2018
** check_keys.c
** File description:
** rpg
*/

#include "prototype.h"

void check_key_left(info_t *game_info, sfEvent event, char **map)
{
	if (event.type == sfEvtKeyPressed && event.key.code == sfKeyLeft) {
		if (check_collision(game_info, map, (sfVector2f){15, 0}, 0))
			move_player(game_info, (sfVector2f){15, 0});
		game_info->perso->app->ret_ob.top = 240;
	}
}

void check_key_right(info_t *game_info, sfEvent event, char **map)
{
	if (event.type == sfEvtKeyPressed && event.key.code == sfKeyRight) {
		if (check_collision(game_info, map, (sfVector2f){-15, 0}, 0))
			move_player(game_info, (sfVector2f){-15, 0});
		game_info->perso->app->ret_ob.top = 288;
	}
}

void check_key_up(info_t *game_info, sfEvent event, char **map)
{
	if (event.type == sfEvtKeyPressed && event.key.code == sfKeyUp) {
		if (check_collision(game_info, map, (sfVector2f){0, 15}, 0))
			move_player(game_info, (sfVector2f){0, 15});
		game_info->perso->app->ret_ob.top = 336;
	}
}
void check_key_down(info_t *game_info, sfEvent event, char **map)
{
	if (event.type == sfEvtKeyPressed && event.key.code == sfKeyDown) {
		if (check_collision(game_info, map, (sfVector2f){0, -15}, 0))
			move_player(game_info, (sfVector2f){0, -15});
		game_info->perso->app->ret_ob.top = 192;
	}
}

void check_key(info_t *ginf, sfEvent event, char **map)
{
	if (event.type == sfEvtKeyPressed &&
	    event.key.code == sfKeyEscape) {
		ginf->pause = 0;
		select_pause_menu(ginf);
	}
	if (event.type == sfEvtKeyPressed &&
	    event.key.code == sfKeyF)
		check_interaction(ginf, map);
	check_key_left(ginf, event, map);
	check_key_right(ginf, event, map);
	check_key_up(ginf, event, map);
	check_key_down(ginf, event, map);
}
