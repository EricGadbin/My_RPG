/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** animate chest
*/

#include "prototype.h"
#include "macrocsfml.h"

void clear_buff(framebuffer_t *buffer)
{
	for (unsigned int i = 0; i < buffer->width * buffer->height * 4; i++) {
		buffer->pixels[i] = 0;
	}
}

void animate_chest(info_t *game_info, sfIntRect *rect, s2f pos)
{
	display_maze(game_info, game_info->maze);
	SP_STREC(game_info->chest->sp_ob, *rect);
	SP_SPOS(game_info->chest->sp_ob, pos);
	SP_DSP(game_info->window, game_info->chest->sp_ob, NULL);
}

void    start_animation_chest(info_t *game_info, sfIntRect *rect, s2f pos)
{
	sfClock *clock = sfClock_create();
	sfTime time;
	float seconds = 0;
	int a = 0;

	while (a != 46) {
		time = sfClock_getElapsedTime(clock);
		seconds = time.microseconds / 1000000.0;
		if (seconds > 0.50 && rect->left < 150) {
			rect->left += 50;
			sfClock_restart(clock);
		}
		check_event_none(game_info);
		animate_chest(game_info, rect, pos);
		disp_explosion(game_info, (sfVector2i){186, 186});
		SP_DSP(game_info->window, game_info->perso->app->sp_ob, NULL);
		a++;
		RW_DRW(game_info->window);
	}
	clear_buff(game_info->buffer);
	sfClock_destroy(clock);
}

int     open_chest(info_t *game_info, int x, int y, sfVector2i in)
{
	sfIntRect rect = {0, 0, 50, 50};
	s2f pos = {x * 180 + 60 + game_info->map.x, y * 180
		   + 60 + game_info->map.y};

	if (in.y != 90 || in.x > 75 || in.x < 45 ||
	    game_info->perso->app->ret_ob.top != 336)
		return (0);
	sfSprite_setOrigin(game_info->buffer->sprite, (sfVector2f){155, 155});
	SP_SPOS(game_info->buffer->sprite, pos);
	start_animation_chest(game_info, &rect, pos);
	add_new_ent_in_inv(generate_sob
	(game_info->perso->level, game_info->dt), &game_info->perso->persinv);
	return (1);
}
