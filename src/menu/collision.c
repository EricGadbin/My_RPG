/*
** EPITECH PROJECT, 2018
** collision.c
** File description:
** rpg
*/

#include "prototype.h"
#include "macrocsfml.h"

int check_point_in_box(s2f button_pos, s2i mouse_pos)
{
	if ((float)mouse_pos.x - button_pos.x >= 0 && (float)mouse_pos.x -
	button_pos.x - 350 <= 0 && (float)mouse_pos.y - button_pos.y >= 0
	&& (float)mouse_pos.y - button_pos.y - 150 <= 0 ) {
		return (1);
	}
	return (0);
}

void mouse_is_on_button(button_t *button, s2i mouse_pos, sfEvent event)
{
	while (button != NULL) {
		if (event.type == sfEvtMouseButtonPressed &&
			check_point_in_box(button->pos, mouse_pos) == 1)
			button->state = 2;
		else if (check_point_in_box(button->pos, mouse_pos) == 1)
			button->state = 1;
		else
			button->state = 0;
		button = button->next;
	}
}

int check_point_in_box2(s2f button_pos, s2i mouse_pos)
{
	if ((float)mouse_pos.x - button_pos.x >= 0 && (float)mouse_pos.x -
	button_pos.x - 140 <= 0 && (float)mouse_pos.y - button_pos.y >= 0
	&& (float)mouse_pos.y - button_pos.y - 30 <= 0 ) {
		return (1);
	}
	return (0);
}

void mouse_is_on_button2(button_t *button, s2i mouse_pos, sfEvent event)
{
	while (button != NULL) {
		if (event.type == sfEvtMouseButtonPressed &&
			check_point_in_box2(button->pos, mouse_pos) == 1)
			button->state = 2;
		else if (check_point_in_box2(button->pos, mouse_pos) == 1)
			button->state = 1;
		else
			button->state = 0;
		button = button->next;
	}
}
