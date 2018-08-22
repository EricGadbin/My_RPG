/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** rpg
*/

#include "prototype.h"
#include "../include/struct.h"
#include "macrocsfml.h"

void move_intro(info_t *ginf)
{
	sfTime time = sfClock_getElapsedTime(ginf->clock2);
	float seconds = time.microseconds / 1000000.0;

	if (seconds > 0.1) {
		if (ginf->intro_back->ret_ob.left >= 1600)
			ginf->intro_back->ret_ob.left = 0;
		else
			ginf->intro_back->ret_ob.left += 1;
		sfClock_restart(ginf->clock2);
	}
	ginf->introd1->ret_ob.height += 4;
	SP_STREC(ginf->intro_back->sp_ob, ginf->intro_back->ret_ob);
	SP_STREC(ginf->introd1->sp_ob, ginf->introd1->ret_ob);

}
void display_intro(info_t *game_info)
{
	check_event_intro(game_info);
	move_intro(game_info);
	SP_DSP(game_info->window, game_info->intro_back->sp_ob, NULL);
	SP_DSP(game_info->window, game_info->introd1->sp_ob, NULL);
	RW_DRW(game_info->window);
}

void start_intro(info_t *game_info)
{
	sfMusic_setLoop(game_info->intro_song, 1);
	sfMusic_play(game_info->intro_song);
	sfMusic_stop(game_info->menu_song);
	while (sfRenderWindow_isOpen(game_info->window))
		display_intro(game_info);
}
