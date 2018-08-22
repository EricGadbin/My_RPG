/*
** EPITECH PROJECT, 2018
** init_pause_menu.c
** File description:
** rpg
*/

#include "prototype.h"

void init_retry_menu(info_t *game_info, menu_t *menu)
{
	button_t *yes = malloc(sizeof(*yes));
	button_t *no = malloc(sizeof(*no));

	create_button_pause(yes, "Go to village",
	(sfVector2f){(game_info->width /
	2) - 100,  (game_info->height / 2) - 50}, game_info->font);
	create_button_pause(no, "Start Menu", (sfVector2f){(game_info->width /
	2) - 100,  (game_info->height / 2) + 50}, game_info->font);
	yes->index = 1;
	no->index = 2;
	yes->callback = &enter_village;
	no->callback =  &select_start_menu;
	yes->next = no;
	no->next = NULL;
	menu->button = yes;
}
