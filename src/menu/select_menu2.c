/*
** EPITECH PROJECT, 2018
** select_menu.c
** File description:
** rpg
*/

#include "prototype.h"

void select_retry_menu(info_t *game_info)
{
	menu_t *menu = game_info->menu->next->next->next;

	for (button_t *tmp = menu->button; tmp != NULL; tmp = tmp->next) {
		tmp->state = 0;
	}
	game_info->perso->app->pos_ob.x = 600;
	SP_SPOS(game_info->perso->app->sp_ob, game_info->perso->app->pos_ob);
	print_pause_menu(game_info, menu, 2);
}

void select_in_game_settings(info_t *game_info)
{
	menu_t *menu = game_info->menu->next->next->next->next;

	for (button_t *tmp = menu->button; tmp != NULL; tmp = tmp->next) {
		tmp->state = 0;
	}
	print_pause_menu(game_info, menu, 1);
}

void select_tuto_menu(info_t *game_info)
{
	menu_t *menu = game_info->menu->next->next->next->next->next;

	print_tuto(game_info, menu, 0);
}

void select_quest_menu(info_t *game_info)
{
	menu_t *menu = game_info->menu->next->next->next->next->next;

	print_quest(game_info, menu);
}

void select_quit_menu(info_t *game_info)
{
	menu_t *menu = game_info->menu->next->next->next->next->next;

	for (button_t *tmp = menu->button; tmp != NULL; tmp = tmp->next) {
		tmp->state = 0;
	}
	print_pause_menu(game_info, menu, 0);
}
