/*
** EPITECH PROJECT, 2018
** maze.c
** File description:
** rpg
*/

#include "prototype.h"
#include "maze.h"
#include "macrocsfml.h"

void move_perso_1(info_t *game_info)
{
	if (game_info->perso->app->ret_ob.left >= 48)
		game_info->perso->app->ret_ob.left = 0;
	else
		game_info->perso->app->ret_ob.left += 48;
}

void move_perso_2(info_t *game_info)
{
	if (game_info->perso->next != NULL &&
	game_info->perso->next->app->ret_ob.left >= 288 + 48)
		game_info->perso->next->app->ret_ob.left = 288;
	else if (game_info->perso->next != NULL)
		game_info->perso->next->app->ret_ob.left += 48;
}

void move_perso_3(info_t *game_info)
{
	if (game_info->perso->next != NULL &&
	game_info->perso->next->next != NULL &&
	game_info->perso->next->next->app->ret_ob.left >= 188)
		game_info->perso->next->next->app->ret_ob.left = 144;
	else if (game_info->perso->next != NULL &&
	game_info->perso->next->next != NULL)
		game_info->perso->next->next->app->ret_ob.left += 48;
}

void move_perso_4(info_t *game_info)
{
	if (game_info->perso->next != NULL &&
	game_info->perso->next->next != NULL &&
	game_info->perso->next->next->next != NULL &&
	game_info->perso->next->next->next->app->ret_ob.left >= 432 + 48)
		game_info->perso->next->next->next->app->ret_ob.left = 432;
	else if (game_info->perso->next != NULL &&
	game_info->perso->next->next != NULL &&
	game_info->perso->next->next->next != NULL)
		game_info->perso->next->next->next->app->ret_ob.left += 48;
	game_info->move_perso = 0;
}

void move_perso_in_fight(info_t *game_info)
{
	if (game_info->move_perso >= 2) {
		move_perso_1(game_info);
		move_perso_2(game_info);
		move_perso_3(game_info);
		move_perso_4(game_info);
	}
	SP_STREC(game_info->perso->app->sp_ob, game_info->perso->app->ret_ob);
	if (game_info->perso->next != NULL)
		SP_STREC(game_info->perso->next->app->sp_ob,
		game_info->perso->next->app->ret_ob);
	if (game_info->perso->next != NULL &&
	game_info->perso->next->next != NULL)
		SP_STREC(game_info->perso->next->next->app->sp_ob,
		game_info->perso->next->next->app->ret_ob);
	if (game_info->perso->next != NULL &&
	game_info->perso->next->next != NULL &&
	game_info->perso->next->next->next != NULL)
		SP_STREC(game_info->perso->next->next->next->app->sp_ob,
		game_info->perso->next->next->next->app->ret_ob);
}
