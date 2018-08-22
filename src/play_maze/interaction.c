/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** check_interaction
*/

#include "prototype.h"
#include "macrocsfml.h"

void animate_door(info_t *game_info, sfIntRect *rect, s2f pos)
{
	rect->top += 96;
	display_maze(game_info, game_info->maze);
	SP_STREC(game_info->door->sp_ob, *rect);
	SP_SPOS(game_info->door->sp_ob, pos);
	SP_DSP(game_info->window,
	game_info->door->sp_ob, NULL);
	SP_DSP(game_info->window,
	game_info->perso->app->sp_ob, NULL);
	RW_DRW(game_info->window);
}

void	start_animation_door(info_t *game_info, sfIntRect *rect, s2f pos)
{
	sfClock *clock = sfClock_create();
	sfTime time;
	float seconds = 0;

	while (rect->top < 288) {
		time = sfClock_getElapsedTime(clock);
		seconds = time.microseconds / 1000000.0;
		if (seconds > 0.25) {
			animate_door(game_info, rect, pos);
			sfClock_restart(clock);
		}
	}
	sfClock_destroy(clock);
}

int	open_door(info_t *game_info, int x, int y, sfVector2i in)
{
	sfIntRect rect = {0, 0, 96, 96};
	s2f pos = {x * 180 + 30 + game_info->map.x, y * 180
		+ 60 + game_info->map.y};

	if (in.y != 150 || in.x > 165 || in.x < 15 ||
		game_info->perso->app->ret_ob.top != 336)
		return (0);
	start_animation_door(game_info, &rect, pos);
	my_usleep(0.4);
	rect.top = 0;
	SP_STREC(game_info->door->sp_ob, rect);
	return (1);
}

void	check_interaction(info_t *game_info, char **map)
{
	int x = (-game_info->map.x + game_info->perso->app->pos_ob.x) / 180;
	int y = (-game_info->map.y + game_info->perso->app->pos_ob.y) / 180;
	int i = (int)((-game_info->map.x +
		game_info->perso->app->pos_ob.x)) % 180;
	int j = (int)((-game_info->map.y +
		game_info->perso->app->pos_ob.y)) % 180;

	if (map[y][x] == 50) {
		if (open_chest(game_info, x, y, (sfVector2i){i, j}))
			map[y][x] = 47;
	}
	if (map[y][x] == 42) {
		if (open_door(game_info, x, y, (sfVector2i){i, j}))
			start_boss_fight(game_info);
	}
}
