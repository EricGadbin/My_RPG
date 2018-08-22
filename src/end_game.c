/*
** EPITECH PROJECT, 2018
** end_game.c
** File description:
** rpg
*/

#include "prototype.h"

void	move_end_animation(info_t *ginf)
{
	sfTime time = sfClock_getElapsedTime(ginf->clock4);
	float seconds = time.microseconds / 1000000.0;
	static int a = 1;
	static int i = 0;

	if (seconds > 0.3 && i < 300) {
		if (ginf->perso->app->ret_ob.left == 0)
			a = 1;
		if (ginf->perso->app->ret_ob.left == 96)
			a = -1;
		ginf->perso->app->ret_ob.left += 48 * a;
		sfClock_restart(ginf->clock4);
	}
	if (i < 300) {
		SP_SPOS(ginf->perso->app->sp_ob, (sfVector2f){190, 170 + i});
		i += 2;
	}
	SP_STREC(ginf->perso->app->sp_ob, ginf->perso->app->ret_ob);
	ginf->introd1->ret_ob.height += 4;
	SP_STREC(ginf->introd1->sp_ob, ginf->introd1->ret_ob);
}
void	display_end_animation(info_t *game_info)
{
	check_event_end(game_info);
	move_end_animation(game_info);
	SP_DSP(game_info->window, game_info->intro_back->sp_ob, NULL);
	SP_DSP(game_info->window, game_info->perso->app->sp_ob, NULL);
	SP_DSP(game_info->window, game_info->introd1->sp_ob, NULL);
	RW_DRW(game_info->window);
}

void	end_game(info_t *game_info)
{
	my_usleep(1);
	SP_STREC(game_info->intro_back->sp_ob, (sfIntRect){0, 0, 1900, 900});
	SP_SPOS(game_info->perso->app->sp_ob, (sfVector2f){150, 150});
	sfMusic_setLoop(game_info->intro_song, 1);
	sfMusic_play(game_info->intro_song);
	sfMusic_stop(game_info->menu_song);
	game_info->intro_back->tex_ob =
	sfTexture_createFromFile("assets/end.png", NULL);
	sfSprite_setTexture(game_info->intro_back->sp_ob,
	game_info->intro_back->tex_ob, sfTrue);
	game_info->introd1->tex_ob =
	sfTexture_createFromFile("assets/intro/endd1.png", NULL);
	sfSprite_setTexture(game_info->introd1->sp_ob,
	game_info->introd1->tex_ob, sfTrue);
	while (sfRenderWindow_isOpen(game_info->window))
		display_end_animation(game_info);
}
