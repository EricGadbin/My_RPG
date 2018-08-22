/*
** EPITECH PROJECT, 2018
** start_menu.c
** File description:
** rpg
*/

#include "prototype.h"
#include "macrocsfml.h"

int check_state_button(info_t *game_info, button_t *button)
{
	if (button->state == 0)
		SP_DSP(game_info->window,
		button->idle, NULL);
	else if (button->state == 1)
		SP_DSP(game_info->window,
		button->hover, NULL);
	else if (button->state == 2) {
		SP_DSP(game_info->window,
		button->clicked, NULL);
		return (button->index);
	}
	return (0);
}

void print_background(info_t *game_info, menu_t *menu)
{
	static int a = 0;
	sfIntRect rect = {0, 0, 1600, 900};
	sfTime time = sfClock_getElapsedTime(game_info->clock);
	float seconds = time.microseconds / 1000000.0;

	if (seconds > 0.4) {
		if (a == 0) {
			a = 1;
			rect.left = 0;
		} else if (a == 1) {
			a = 0;
			rect.left = 1600;
		}
	SP_STREC(menu->back, rect);
	sfClock_restart(game_info->clock);
	}
	SP_DSP(game_info->window, menu->back, NULL);
}

void animate_menu(info_t *game_info, menu_t *menu, int i)
{
	button_t *tmp = menu->button;
	int index = 0;

	check_event_menu(game_info, menu);
	print_background(game_info, menu);
	if (i == 1)
		SP_DSP(game_info->window, menu->logo, NULL);
	for (;tmp != NULL; tmp = tmp->next) {
		index += check_state_button(game_info, tmp);
		TXT_DTXT(game_info->window, tmp->text, NULL);
	}
	SP_DSP(game_info->window, game_info->cursor->sp_ob, NULL);
	RW_DRW(game_info->window);
	if (index != 0) {
		tmp = menu->button;
		for (;tmp && tmp->index != index; tmp = tmp->next);
		my_usleep(0.25);
		tmp->callback(game_info);
	}
}

void print_menu(info_t *game_info, menu_t *menu, int i)
{
	game_info->pause = 0;
	if (i == 1) {
		sfMusic_setLoop(game_info->menu_song, 1);
		sfMusic_stop(game_info->dungeon);
		sfMusic_stop(game_info->village_song);
		sfMusic_stop(game_info->house_theme);
		sfMusic_stop(game_info->battle_theme);
		sfMusic_play(game_info->menu_song);
	}
	while (sfRenderWindow_isOpen(game_info->window) &&
	game_info->pause == 0) {
		animate_menu(game_info, menu, i);
	}
}
