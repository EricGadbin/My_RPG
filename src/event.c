/*
** EPITECH PROJECT, 2018
** event.c
** File description:
** rpg
*/

#include "prototype.h"
#include "macrocsfml.h"

void check_event_none(info_t *ginf)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(ginf->window, &event)) {
		if (event.type == sfEvtClosed)
			quit_game(ginf);
		if (event.type == sfEvtKeyPressed)
			return;
	}
}

void check_event_menu(info_t *ginf, menu_t *menu)
{
	sfEvent event;
	button_t *tmp = menu->button;
	sfVector2i mouse_pos = MS_GPOSRW(ginf->window);
	s2f mouse = {mouse_pos.x, mouse_pos.y};

	SP_SPOS(ginf->cursor->sp_ob, mouse);
	while (sfRenderWindow_pollEvent(ginf->window, &event)) {
		if (event.type == sfEvtClosed)
			quit_game(ginf);
		mouse_is_on_button(tmp, mouse_pos, event);
	}
}

int check_event_quest(info_t *ginf)
{
	sfEvent event;
	sfVector2i mouse_pos = MS_GPOSRW(ginf->window);
	s2f mouse = {mouse_pos.x, mouse_pos.y};

	SP_SPOS(ginf->cursor->sp_ob, mouse);
	while (sfRenderWindow_pollEvent(ginf->window, &event)) {
		if (event.type == sfEvtClosed)
			quit_game(ginf);
		if (event.type == sfEvtKeyPressed &&
		event.key.code == sfKeyEscape)
			return (1);
	}
	return (0);
}

int check_event_pause(info_t *ginf, menu_t *menu)
{
	sfEvent event;
	sfVector2i mouse_pos = MS_GPOSRW(ginf->window);
	s2f mouse = {mouse_pos.x, mouse_pos.y};
	button_t *tmp = menu->button;

	SP_SPOS(ginf->cursor->sp_ob, mouse);
	while (sfRenderWindow_pollEvent(ginf->window, &event)) {
		if (event.type == sfEvtClosed)
			quit_game(ginf);
		if (event.type == sfEvtKeyPressed &&
		event.key.code == sfKeyEscape)
			return (1);
		mouse_is_on_button2(tmp, mouse_pos, event);
	}
	return (0);
}
