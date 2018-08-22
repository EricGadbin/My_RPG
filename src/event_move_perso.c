/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** event move
*/

#include "macrocsfml.h"
#include "prototype.h"

void	check_event_house(info_t *ginf, int **map)
{
	sfEvent event;
	sfVector2i pos = MS_GPOSRW(ginf->window);
	s2f mouse_pos = {pos.x, pos.y};

	SP_SPOS(ginf->cursor->sp_ob, mouse_pos);
	while (sfRenderWindow_pollEvent(ginf->window, &event)) {
		if (event.type == sfEvtClosed)
			quit_game(ginf);
		check_key_house(ginf, event, map);
		sfSprite_setTextureRect(ginf->perso->app->sp_ob,
					ginf->perso->app->ret_ob);
		SP_SPOS(ginf->perso->app->sp_ob,
			ginf->perso->app->pos_ob);
	}
}

void	check_event_village(info_t *ginf, int **map)
{
	sfEvent event;
	sfVector2i pos = MS_GPOSRW(ginf->window);
	s2f mouse_pos = {pos.x, pos.y};
	sfVector2f sprite = sfSprite_getPosition(ginf->buffer2->sprite);

	SP_SPOS(ginf->cursor->sp_ob, mouse_pos);
	while (sfRenderWindow_pollEvent(ginf->window, &event)) {
		if (event.type == sfEvtClosed)
			quit_game(ginf);
		check_key_village(ginf, event, map, sprite);
		sfSprite_setTextureRect(ginf->perso->app->sp_ob,
					ginf->perso->app->ret_ob);
		SP_SPOS(ginf->perso->app->sp_ob, ginf->perso->app->pos_ob);
	}
}

void	check_event(info_t *ginf, char **map)
{
	sfEvent event;
	sfVector2i mouse_pos = MS_GPOSRW(ginf->window);
	s2f mouse = {mouse_pos.x, mouse_pos.y};

	SP_SPOS(ginf->cursor->sp_ob, mouse);
	while (sfRenderWindow_pollEvent(ginf->window, &event)) {
		if (event.type == sfEvtClosed)
			quit_game(ginf);
		check_key(ginf, event, map);
		sfSprite_setTextureRect(ginf->perso->app->sp_ob,
					ginf->perso->app->ret_ob);
		SP_SPOS(ginf->perso->app->sp_ob,
			ginf->perso->app->pos_ob);
	}
}
