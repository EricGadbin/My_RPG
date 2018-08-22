/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** check_interaction
*/

#include "prototype.h"
#include "macrocsfml.h"

void	check_pnj(info_t *game_info, int x, int y)
{
	if (game_info->village_map[y][x] >= 0 &&
	game_info->village_map[y][x] <= 4
	&& game_info->perso->app->ret_ob.top == 336)
		check_dialog(game_info, 0, game_info->village->sp_ob);
	if (game_info->village_map[y][x + 1] >= 0 &&
	game_info->village_map[y][x + 1] <= 4
	&& game_info->perso->app->ret_ob.top == 288)
		check_dialog(game_info, 0, game_info->village->sp_ob);
	if (game_info->village_map[y + 1][x] >= 0 &&
	game_info->village_map[y + 1][x] <= 4
	&& game_info->perso->app->ret_ob.top == 192)
		check_dialog(game_info, 0, game_info->village->sp_ob);
	if (game_info->village_map[y][x - 1] >= 0 &&
	game_info->village_map[y][x - 1] <= 4
	&& game_info->perso->app->ret_ob.top == 240)
		check_dialog(game_info, 0, game_info->village->sp_ob);
}

void	check_interaction_village(info_t *game_info)
{
	int x = (-game_info->map.x + game_info->perso->app->pos_ob.x) / 60;
	int y = (-game_info->map.y + game_info->perso->app->pos_ob.y) / 60;

	if (game_info->village_map[y - 1][x] == 12 &&
	game_info->perso->app->ret_ob.top == 336) {
		game_info->perso->app->tex_ob =
		sfTexture_createFromFile("assets/persosheet.png", NULL);
		sfMusic_play(game_info->door_song);
		RW_CLEAR(game_info->window, sfBlack);
		RW_DRW(game_info->window);
		my_usleep(0.5);
		SP_STX(game_info->perso->app->sp_ob,
		game_info->perso->app->tex_ob, sfTrue);
		game_info->perso->app->pos_ob = (sfVector2f){435, 750};
		enter_house(game_info);
	}
	check_pnj(game_info, x, y);
}
