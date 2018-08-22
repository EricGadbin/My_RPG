/*
** EPITECH PROJECT, 2018
** destroy.c
** File description:
** rpg
*/

#include "prototype.h"
#include "macrocsfml.h"

void free_buttons_fight(button_t *button)
{
	button_t *tmp = button;

	while (button) {
		tmp = button;
		button = button->next;
		free(tmp);
	}
}

void free_sprite_list(sprite_t *list)
{
	sprite_t *tmp = list;

	while (list) {
		SP_DSSP(list->sprite);
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

void free_tab(char **tab)
{
	if (tab == NULL)
		return;
	for (int i = 0; tab[i] != NULL; i++) {
		free(tab[i]);
	}
	free(tab);
}

void free_array(int **tab)
{
	if (tab == NULL)
		return;
	for (int i = 0; i != 45; i++) {
		free(tab[i]);
	}
	free(tab);
}

void free_array2(int **tab)
{
	if (tab == NULL)
		return;
	for (int i = 0; i != 26; i++) {
		free(tab[i]);
	}
	free(tab);
}
