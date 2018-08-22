/*
** EPITECH PROJECT, 2018
** init_settings_menu.c
** File description:
** rpg
*/

#include "prototype.h"

void init_quit_menu(info_t *game_info, menu_t *menu)
{
	button_t *yes = malloc(sizeof(*yes));
	button_t *no = malloc(sizeof(*no));

	create_button_pause(yes, "     Yes", (sfVector2f){720, 450},
	game_info->font);
	create_button_pause(no, "     no", (sfVector2f){720, 550},
	game_info->font);
	yes->callback = &quit_game;
	no->callback = &resume_game;
	yes->index = 1;
	no->index = 2;
	yes->next = no;
	no->next = NULL;
	menu->button = yes;
}
