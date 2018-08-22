/*
** EPITECH PROJECT, 2018
** init_start_menu.c
** File description:
** rpg
*/

#include "prototype.h"

void init_start_menu(info_t *game_info, menu_t *menu)
{
	button_t *start = malloc(sizeof(*start));
	button_t *quit = malloc(sizeof(*quit));
	button_t *settings = malloc(sizeof(*settings));

	create_button(start, "    Game", (sfVector2f){(game_info->width /
	2) + 280,  (game_info->height / 2) - 350}, game_info->font);
	create_button(quit, " Quit Game", (sfVector2f){(game_info->width /
	2) + 280,  (game_info->height / 2) + 170}, game_info->font);
	create_button(settings, "  Settings", (sfVector2f){(game_info->width /
	2) + 280,  (game_info->height / 2) - 90}, game_info->font);
	start->callback = &start_intro;
	quit->callback = &quit_game;
	settings->callback = &select_settings_menu;
	start->index = 1;
	quit->index = 2;
	settings->index = 3;
	start->next = quit;
	quit->next = settings;
	settings->next = NULL;
	menu->button = start;
}
