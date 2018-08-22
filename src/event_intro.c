/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** intro event
*/

#include "prototype.h"
#include "macrocsfml.h"

void check_index(int index, int i, info_t *ginf)
{
	if (index == 1 && i != 1) {
		ginf->introd1->ret_ob.height = 100;
		SP_STREC(ginf->introd1->sp_ob, ginf->introd1->ret_ob);
		ginf->introd1->tex_ob = sfTexture_createFromFile
		("assets/intro/intro2.png", NULL);
		SP_STX(ginf->introd1->sp_ob, ginf->introd1->tex_ob, sfTrue);
		i = 1;
	}
	if (index == 2 && i != 2) {
		ginf->introd1->ret_ob.height = 100;
		SP_STREC(ginf->introd1->sp_ob, ginf->introd1->ret_ob);
		ginf->introd1->tex_ob = sfTexture_createFromFile
		("assets/intro/intro3.png", NULL);
		SP_STX(ginf->introd1->sp_ob, ginf->introd1->tex_ob, sfTrue);
		i = 2;
	}
}

void check_event_intro(info_t *ginf)
{
	sfEvent event;
	static int index = 0;
	static int i = 0;

	while (sfRenderWindow_pollEvent(ginf->window, &event)) {
		if (event.type == sfEvtClosed)
			quit_game(ginf);
		if (event.type == sfEvtKeyPressed &&
		event.key.code == sfKeyReturn)
			index += 1;
		check_index(index, i , ginf);
		if (index == 3)
			enter_house(ginf);
	}
}

void check_index_end(int index, int i, info_t *ginf)
{
	if (index == 1 && i != 1) {
		ginf->introd1->ret_ob.height = 100;
		SP_STREC(ginf->introd1->sp_ob, ginf->introd1->ret_ob);
		ginf->introd1->tex_ob = sfTexture_createFromFile
		("assets/intro/endd2.png", NULL);
		SP_STX(ginf->introd1->sp_ob, ginf->introd1->tex_ob, sfTrue);
		i = 1;
	}
	if (index == 2 && i != 2) {
		ginf->introd1->ret_ob.height = 100;
		SP_STREC(ginf->introd1->sp_ob, ginf->introd1->ret_ob);
		ginf->introd1->tex_ob = sfTexture_createFromFile
		("assets/intro/endd3.png", NULL);
		SP_STX(ginf->introd1->sp_ob, ginf->introd1->tex_ob, sfTrue);
		i = 2;
	}
}

void check_event_end(info_t *ginf)
{
	sfEvent event;
	static int index = 0;
	static int i = 0;

	while (sfRenderWindow_pollEvent(ginf->window, &event)) {
		if (event.type == sfEvtClosed)
			quit_game(ginf);
		if (event.type == sfEvtKeyPressed &&
		event.key.code == sfKeyReturn)
			index += 1;
		check_index_end(index, i , ginf);
		if (index == 3)
			quit_game(ginf);
	}
}
