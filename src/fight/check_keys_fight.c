/*
** EPITECH PROJECT, 2018
** check_keys_fight.c
** File description:
** rpg
*/

#include "prototype.h"

void check_key_up_fight(button_t *li, sfEvent event)
{
	if (event.type == sfEvtKeyPressed && event.key.code == sfKeyUp) {
		for (; li->next && li->next->state != 1; li = li->next);
		if (li->next && li->index > 4) {
			li->state = 1;
			li->next->state = 0;
		}
	}
}

void	check_key_down_fight(button_t *list, sfEvent event)
{
	if (event.type == sfEvtKeyPressed && event.key.code == sfKeyDown) {
		for (; list && list->state != 1; list = list->next);
		if (list && list->next && list->index > 4) {
			list->state = 0;
			list->next->state = 1;
		}
	}
}

int	check_key_enter_fight(button_t *list, sfEvent event)
{
	if (event.type == sfEvtKeyPressed && event.key.code == sfKeyReturn) {
		for (;list && list->state != 1; list = list->next);
		list->state = 2;
		return (list->index - 4);
	}
	return (0);
}
