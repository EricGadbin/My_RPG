/*
** EPITECH PROJECT, 2018
** move_boss.c
** File description:
** rpg
*/

#include "prototype.h"

void move_boss1(info_t *ginf, mob_t *boss)
{
	sfTime time = sfClock_getElapsedTime(ginf->clock4);
	float seconds = time.microseconds / 1000000.0;

	if (seconds > 0.15) {
		if (boss->app->ret_ob.left >= 57 * 7)
			boss->app->ret_ob.left = 0;
		else
			boss->app->ret_ob.left += 57;
		sfClock_restart(ginf->clock4);
	}
	SP_STREC(boss->app->sp_ob, boss->app->ret_ob);
}

void move_boss2(info_t *ginf, mob_t *boss)
{
	sfTime time = sfClock_getElapsedTime(ginf->clock4);
	float seconds = time.microseconds / 1000000.0;

	if (seconds > 0.15) {
		if (boss->app->ret_ob.left >= 83.3333333333 * 1)
			boss->app->ret_ob.left = 0;
		else
			boss->app->ret_ob.left += 83.3333333333;
		sfClock_restart(ginf->clock4);
	}
	SP_STREC(boss->app->sp_ob, boss->app->ret_ob);
}

void move_rect_boss3(mob_t *boss)
{
	boss->app->ret_ob.left = 0;
	if (boss->app->ret_ob.top >= 128 * 1)
		boss->app->ret_ob.top = 0;
	else
		boss->app->ret_ob.top += 128;
}

void move_boss3(info_t *ginf, mob_t *boss)
{
	sfTime time = sfClock_getElapsedTime(ginf->clock4);
	float seconds = time.microseconds / 1000000.0;

	if (seconds > 0.15) {
		if (boss->app->ret_ob.left >= 128 * 8) {
			move_rect_boss3(boss);
		}
		else
			boss->app->ret_ob.left += 128;
		sfClock_restart(ginf->clock4);
	}
	SP_STREC(boss->app->sp_ob, boss->app->ret_ob);
}
