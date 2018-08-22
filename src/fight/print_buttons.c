/*
** EPITECH PROJECT, 2018
** print_button.c
** File description:
** rpg
*/

#include "prototype.h"

void check_state_fight(button_t *button)
{
	if (button->state == 0)
		sfText_setColor(button->text, sfWhite);
	else if (button->state == 1)
		sfText_setColor(button->text, (sfColor){95, 0, 130, 255});
	else if (button->state == 2)
		sfText_setColor(button->text, sfRed);
}

void check_buttons(info_t *game_info, button_t *list)
{
	int disp = 0;

	for (; list->index <= 4; list = list->next) {
		check_state_fight(list);
		sfRenderWindow_drawText(game_info->window, list->text, NULL);
		if (list->state == 2)
			disp = 1;
	}
	for (;disp == 1 && list; list = list->next) {
		check_state_fight(list);
		sfRenderWindow_drawText(game_info->window, list->text,
		NULL);
	}
}
