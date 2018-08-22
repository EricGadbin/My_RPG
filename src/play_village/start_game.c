/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** rpg
*/

#include "prototype.h"
#include "../include/struct.h"
#include "macrocsfml.h"

void clock_perso(info_t *game_info)
{
	sfTime time = sfClock_getElapsedTime(
		game_info->perso->app->perso_clock);
	float seconds = time.microseconds / 1000000.0;
	static int a = 1;

	if (KB_IKP(sfKeyRight) != 1 &&
	KB_IKP(sfKeyLeft) != 1 &&
	KB_IKP(sfKeyUp) != 1 &&
	KB_IKP(sfKeyDown) != 1)
		return;
	if (seconds > 0.3) {
		if (game_info->perso->app->ret_ob.left == 0)
			a = 1;
		if (game_info->perso->app->ret_ob.left == 96)
			a = -1;
		game_info->perso->app->ret_ob.left += 48 * a;
	sfClock_restart(game_info->perso->app->perso_clock);
	}
	SP_STREC(game_info->perso->app->sp_ob,
		game_info->perso->app->ret_ob);
}

void display_house(info_t *game_info)
{
	RW_CLEAR(game_info->window, sfBlack);
	check_event_house(game_info, game_info->house_map);
	clock_perso(game_info);
	game_info->house->pos_ob.x = game_info->map.x;
	game_info->house->pos_ob.y = game_info->map.y;
	SP_DSP(game_info->window,
	game_info->house->sp_ob, NULL);
	SP_DSP(game_info->window,
	game_info->perso->app->sp_ob, NULL);
	RW_DRW(game_info->window);
}

void set_music_and_perso_house(info_t *game_info)
{
	sfMusic_setLoop(game_info->house_theme, 1);
	sfMusic_play(game_info->house_theme);
	sfMusic_stop(game_info->menu_song);
	sfMusic_stop(game_info->dungeon);
	sfMusic_stop(game_info->battle_theme);
	sfMusic_stop(game_info->village_song);
	sfMusic_stop(game_info->intro_song);
	game_info->scene = 2;
	game_info->perso->app->ret_ob.top = 192;
	sfSprite_setTextureRect(game_info->perso->app->sp_ob,
	game_info->perso->app->ret_ob);
	init_inventory(game_info);
}

void enter_house(info_t *game_info)
{
	set_music_and_perso_house(game_info);
	while (sfRenderWindow_isOpen(game_info->window)) {
		display_house(game_info);
		dialog_solo(game_info, game_info->perso,
		&game_info->quest, game_info->house->sp_ob);
		if (game_info->perso->app->pos_ob.x >= 375 &&
		game_info->perso->app->pos_ob.x <= 555 &&
		game_info->perso->app->pos_ob.y >= 760) {
			RW_CLEAR(game_info->window, sfBlack);
			RW_DRW(game_info->window);
			sfMusic_stop(game_info->house_theme);
			sfMusic_play(game_info->door_song);
			my_usleep(0.5);
			enter_village(game_info);
		}
	}
}
