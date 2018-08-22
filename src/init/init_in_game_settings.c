/*
** EPITECH PROJECT, 2018
** init_settings_menu.c
** File description:
** rpg
*/

#include "prototype.h"

void init_in_game_settings(info_t *game_info, menu_t *menu)
{
	button_t *sound = malloc(sizeof(*sound));
	button_t *start = malloc(sizeof(*start));

	create_button_pause(sound, "Edit Sound",
	(sfVector2f){725, 400}, game_info->font);
	create_button_pause(start, "Nenu", (sfVector2f){725, 500},
	game_info->font);
	sound->callback = &select_start_menu;
	start->callback = &select_start_menu;
	sound->index = 1;
	start->index = 2;
	sound->next = start;
	start->next = NULL;
	menu->button = sound;
}
