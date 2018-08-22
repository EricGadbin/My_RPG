/*
** EPITECH PROJECT, 2018
** display_stats.c
** File description:
** rpg
*/

#include "prototype.h"
#include "macrocsfml.h"

int check_state_pause(info_t *game_info, button_t *button, int i)
{
	if (button->state == 0)
		TXT_SCOL(button->text, sfWhite);
	else if (button->state == 1) {
		TXT_SCOL(button->text, (sfColor){95, 0, 130, 255});
		if (i != 2)
			SP_DSP(game_info->window, button->hover,
			NULL);
	} else if (button->state == 2) {
		TXT_SCOL(button->text, sfRed);
		if (i != 2)
			SP_DSP(game_info->window, button->hover,
			NULL);
		return (button->index);
	}
	return (0);
}

void print_scene_pause(info_t *game_info, menu_t *menu)
{
	RW_CLEAR(game_info->window, sfBlack);
	if (game_info->scene == 0) {
		SP_DSP(game_info->window,
		game_info->village->sp_ob, NULL);
		SP_DSP(game_info->window,
		game_info->perso->app->sp_ob, NULL);
		print_over(game_info, game_info->village_map);
		add_fade_rain(game_info->buffer2);
		disp_particules(game_info, game_info->rain);
	} else if (game_info->scene == 1) {
		display_maze(game_info, game_info->maze);
		SP_DSP(game_info->window,
		game_info->perso->app->sp_ob, NULL);
	} else {
		SP_DSP(game_info->window,
		game_info->house->sp_ob, NULL);
		SP_DSP(game_info->window,
		game_info->perso->app->sp_ob, NULL);
	}
	SP_DSP(game_info->window, menu->back, NULL);
}

void manage_buttons_and_display(info_t *game_info, button_t *button, int i)
{
	int index = 0;

	for (button_t *tmp = button;tmp != NULL; tmp = tmp->next) {
		index += check_state_pause(game_info, tmp, i);
		TXT_DTXT(game_info->window, tmp->text,
		NULL);
	}
	SP_DSP(game_info->window,
	game_info->cursor->sp_ob, NULL);
	RW_DRW(game_info->window);
	if (index != 0) {
		for (;button && button->index != index; button = button->next);
		my_usleep(0.25);
		button->callback(game_info);
		button->state = 0;
		if (i == 1)
			game_info->pause = 0;
	}
}

void print_pause_menu(info_t *game_info, menu_t *menu, int i)
{
	int a = 0;
	sfText *text = sfText_create();

	TXT_SFONT(text, game_info->font);
	TXT_SCSIZE(text, 45);
	TXT_SSTR(text, "Are you sure ?");
	TXT_SPOS(text, (sfVector2f){645, 300});
	TXT_SCOL(text, sfWhite);
	while (sfRenderWindow_isOpen(game_info->window) &&
	game_info->pause == 0) {
		print_scene_pause(game_info, menu);
		if (i == 0)
			TXT_DTXT(game_info->window, text, NULL);
		a = check_event_pause(game_info, menu);
		if (a == 1 && i != 2) {
			TXT_DSTXT(text);
			return;
		}
		manage_buttons_and_display(game_info, menu->button, i);
	}
}
