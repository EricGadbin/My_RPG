/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** get_nb_perso
*/

#include "prototype.h"
#include "macrocsfml.h"

void quit_game(info_t *game_info)
{
	RW_CLOSE(game_info->window);
}

void	display_inventory_in_game(info_t *game_info)
{
	int j = 0;

	if (game_info->perso->persinv->soind != NULL)
		up_stadd(&game_info->perso->persinv->stadd,
		game_info->perso->persinv->soind->stack->data,
		game_info->perso->eq);
	else
		up_stadd(&game_info->perso->persinv->stadd, NULL,
		game_info->perso->eq);
	display_inventory_2(game_info->window, &game_info->perso, &j);
	if (j == 1)
		quit_game(game_info);
}

void resume_game(info_t *game_info)
{
	game_info->pause = 1;
}
