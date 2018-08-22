/*
** EPITECH PROJECT, 2018
** maze.c
** File description:
** rpg
*/

#include "prototype.h"
#include "maze.h"
#include "macrocsfml.h"

void print_chest(info_t *ginf, s2f pos, int j)
{
	sfIntRect rect= {0, 0, 50, 50};

	if (j == 47)
		rect.left = 150;
	SP_STREC(ginf->chest->sp_ob, rect);
	SP_SPOS(ginf->chest->sp_ob,
		(s2f){pos.x + 60, pos.y + 60});
	SP_DSP(ginf->window,
		ginf->chest->sp_ob, NULL);
}

void print_mob(info_t *ginf, s2f pos, int id)
{
	mob_t *mob = ginf->mob;

	for (int i = 1; i < id; mob = mob->next, i += 1);
	SP_SPOS(mob->app->sp_ob,
		(s2f){pos.x + 20, pos.y + 20});
	SP_DSP(ginf->window,
		mob->app->sp_ob, NULL);
}

void	set_rec_mob(info_t *ginf)
{
	SP_STREC(ginf->mob->app->sp_ob, ginf->mob->app->ret_ob);
	SP_STREC(ginf->mob->next->app->sp_ob, ginf->mob->next->app->ret_ob);
	SP_STREC(ginf->mob->next->next->app->sp_ob,
	ginf->mob->next->next->app->ret_ob);
}

void move_mob(info_t *ginf)
{
	sfTime time = sfClock_getElapsedTime(ginf->clock2);
	float seconds = time.microseconds / 1000000.0;

	if (seconds > 0.15) {
		if (ginf->mob->app->ret_ob.left >= 55 * 7)
			ginf->mob->app->ret_ob.left = 56;
		else
			ginf->mob->app->ret_ob.left += 55;
		if (ginf->mob->next->app->ret_ob.left >= 42 * 3)
			ginf->mob->next->app->ret_ob.left = 0;
		else
			ginf->mob->next->app->ret_ob.left += 42;
		if (ginf->mob->next->next->app->ret_ob.left >= (84 * 4))
			ginf->mob->next->next->app->ret_ob.left = 84;
		else
			ginf->mob->next->next->app->ret_ob.left += 84;
		ginf->move_perso += 1;
		sfClock_restart(ginf->clock2);
	}
	set_rec_mob(ginf);
}

void	print_door(info_t *ginf, s2f pos)
{
	SP_SPOS(ginf->door->sp_ob,
	(s2f){pos.x + 30, pos.y + 60});
	SP_DSP(ginf->window,
	ginf->door->sp_ob, NULL);
}
