/*
** EPITECH PROJECT, 2018
** enter_village.c
** File description:
** rpg
*/

#include "prototype.h"

void add_fade_rain(framebuffer_t *buffer)
{
	for (unsigned int i = 3; i < buffer->width *
	buffer->height * 4; i += 4) {
		if (buffer->pixels[i] > 5)
			buffer->pixels[i] -= 5;
		else
			buffer->pixels[i] = 0;
	}
}

void disp_particules(info_t *game_info, rain_t *rain)
{
	rain_particule(game_info, rain);
	sfTexture_updateFromPixels(game_info->buffer2->texture,
	game_info->buffer2->pixels, 8320, 900, 0, 0);
	sfSprite_setTexture(game_info->buffer2->sprite,
	game_info->buffer2->texture, sfTrue);
	sfRenderWindow_drawSprite(game_info->window,
	game_info->buffer2->sprite, NULL);
}

void display_village(info_t *game_info)
{
	RW_CLEAR(game_info->window, sfRed);
	check_event_village(game_info, game_info->village_map);
	clock_perso(game_info);
	game_info->village->pos_ob.x = game_info->map.x;
	game_info->village->pos_ob.y = game_info->map.y;
	SP_SPOS(game_info->village->sp_ob,
	game_info->village->pos_ob);
	SP_DSP(game_info->window,
	game_info->village->sp_ob, NULL);
	SP_DSP(game_info->window,
	game_info->perso->app->sp_ob, NULL);
	print_over(game_info, game_info->village_map);
	add_fade_rain(game_info->buffer2);
	disp_particules(game_info, game_info->rain);
	RW_DRW(game_info->window);
}

void enter_village(info_t *game_info)
{
	init_village_settings(game_info);
	sfMusic_setLoop(game_info->village_song, 1);
	sfMusic_play(game_info->village_song);
	while (sfRenderWindow_isOpen(game_info->window)) {
		display_village(game_info);
		cutscene(game_info);
		if (game_info->perso->app->pos_ob.x == 1455 &&
		game_info->map.y >= -1380 && game_info->map.y <= -915) {
			game_info->map.x = 0;
			game_info->map.y = 0;
			game_info->perso->app->pos_ob.x = 195;
			game_info->perso->app->pos_ob.y = 195;
			game_info->perso->app->ret_ob.top = 192;
			enter_maze(game_info);
		}
	}
}
