/*
** EPITECH PROJECT, 2018
** fight_event.c
** File description:
** rpg
*/

#include "prototype.h"

void check_event_battle(info_t *game_info)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(game_info->window, &event)) {
		if (event.type == sfEvtClosed)
			quit_game(game_info);
	}
}

int get_action(int select, sfEvent event)
{
	if (select == 1 || select == 3) {
		if (event.type == sfEvtKeyPressed &&
			event.key.code == sfKeyLeft)
			return (10);
		if (event.type == sfEvtKeyPressed &&
			event.key.code == sfKeyRight)
			return (11);
		if (event.type == sfEvtKeyPressed &&
			event.key.code == sfKeyReturn)
			return (12);
	}
	return (0);
}

int check_event_attack(info_t *game_info, button_t *list, int select)
{
	sfEvent event;
	int action = 0;

	if (sfRenderWindow_pollEvent(game_info->window, &event)) {
		if (event.type == sfEvtClosed)
			quit_game(game_info);
		if (select == 0) {
			check_key_down_fight(list, event);
			check_key_up_fight(list, event);
			action = check_key_enter_fight(list, event);
		} else
			return (get_action(select, event));
	}
	return (action);
}
