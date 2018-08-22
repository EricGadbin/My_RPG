/*
** EPITECH PROJECT, 2018
** init_settings_menu.c
** File description:
** rpg
*/

#include "prototype.h"

void init_settings_menu(info_t *game_info, menu_t *menu)
{
	button_t *sound = malloc(sizeof(*sound));
	button_t *start = malloc(sizeof(*start));

	create_button(sound, "Edit Sound", (sfVector2f){(game_info->width /
	2) - 200,  (game_info->height / 2) - 200}, game_info->font);
	create_button(start, "   Go Back", (sfVector2f){
	(game_info->width / 2) - 200,  (game_info->height / 2) - 40},
	game_info->font);
	sound->callback = &select_start_menu;
	start->callback = &select_start_menu;
	sound->index = 1;
	start->index = 2;
	sound->next = start;
	start->next = NULL;
	menu->button = sound;
}
