/*
** EPITECH PROJECT, 2018
** select_menu.c
** File description:
** rpg
*/

#include "prototype.h"

void select_stat_menu(info_t *game_info)
{
	menu_t *menu = game_info->menu->next->next->next->next->next;

	print_stats(game_info, menu);
}

void select_settings_menu(info_t *game_info)
{
	menu_t *menu = game_info->menu->next;

	for (button_t *tmp = menu->button; tmp != NULL; tmp = tmp->next) {
		tmp->state = 0;
	}
	print_tuto(game_info, menu, 1);
}

void select_pause_menu(info_t *game_info)
{
	menu_t *menu = game_info->menu->next->next;

	for (button_t *tmp = menu->button; tmp != NULL; tmp = tmp->next) {
		tmp->state = 0;
	}
	print_pause_menu(game_info, menu, 1);
}

void select_start_menu(info_t *game_info)
{
	menu_t *menu = game_info->menu;

	for (button_t *tmp = menu->button; tmp != NULL; tmp = tmp->next) {
		tmp->state = 0;
	}
	game_info->perso->app->pos_ob = (sfVector2f){1005, 210};
	SP_SPOS(game_info->perso->app->sp_ob, game_info->perso->app->pos_ob);
	print_menu(game_info, menu, 1);
}
