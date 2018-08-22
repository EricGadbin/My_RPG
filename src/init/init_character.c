/*
** EPITECH PROJECT, 2018
** init_character.c
** File description:
** rpg
*/

#include "prototype.h"

void create_base(info_t *game_info, pers_t *perso)
{
	perso->ident = malloc(sizeof(Identity_t));
	perso->stats = malloc(sizeof(stats_t));
	perso->ident->name = sfText_create();
	sfText_setFont(perso->ident->name, game_info->font);
	sfText_setCharacterSize(perso->ident->name, 30);
	sfText_setColor(perso->ident->name, sfWhite);
	perso->stats->health = 100;
	perso->stats->strenght = 60;
	perso->stats->speed = 102;
	perso->stats->supp = 40;
	perso->health = 100;
	perso->speed = 0;
	perso->level = 1;
	perso->exp = 0;
	perso->eq = is_init_wpt();
	perso->persinv = init_all(perso->stats);
	perso->persinv->stadd = init_dis_stadd(NULL, perso->eq);
}

void create_base_2(info_t *game_info, pers_t *perso)
{
	perso->ident = malloc(sizeof(Identity_t));
	perso->stats = malloc(sizeof(stats_t));
	perso->ident->name = sfText_create();
	sfText_setFont(perso->ident->name, game_info->font);
	sfText_setCharacterSize(perso->ident->name, 30);
	sfText_setColor(perso->ident->name, sfWhite);
	perso->health = 120;
	perso->speed = 0;
	perso->level = 1;
	perso->exp = 0;
	perso->eq = is_init_wpt();
	perso->persinv = game_info->perso->persinv;
}

pers_t *new_character_2(info_t *game_info, pers_t *last)
{
	pers_t *perso = malloc(sizeof(pers_t));

	create_base_2(game_info, perso);
	perso->stats->health = 120;
	perso->stats->strenght = 53;
	perso->stats->speed = 97;
	perso->stats->supp = 45;
	perso->app = sf_build("assets/persosheet.png",
	(s2f){1600 / 2, 900 / 2}, (sfIR){288, 288, 48, 48},
	(s2f){1.25008571, 1.25008571});
	perso->ident->tmpname = my_strcpy("zaveid");
	sfText_setString(perso->ident->name, "zaveid");
	perso->next = NULL;
	perso->prev = last;
	return (perso);
}

pers_t *new_character(info_t *game_info, pers_t *last)
{
	pers_t *perso = malloc(sizeof(pers_t));

	create_base(game_info, perso);
	if (last == NULL) {
		perso->app = sf_build("assets/persosheet.png",
		(sfVector2f){1600 / 2, 900 / 2}, (sfIntRect){0, 0, 48, 48},
		(sfVector2f){1.25008571, 1.25008571});
		perso->ident->tmpname = my_strcpy("vlad");
		sfText_setString(perso->ident->name, "vlad");
	}
	perso->next = NULL;
	perso->prev = last;
	return (perso);
}

void create_character(info_t *game_info)
{
	game_info->perso = new_character(game_info, NULL);
	game_info->perso->next = new_character_2(game_info, game_info->perso);
	game_info->perso->face[0] = build("assets/faces_left.png",
	(s2f){1416, 726}, (sfIR){0, 96, 96, 96}, (s2f){2, 2});
	game_info->perso->face[1] = build("assets/faces_right.png",
	(s2f){1416, 726}, (sfIR){288, 96, 96, 96}, (s2f){2, 2});
	game_info->perso->next->face[1] = build("assets/faces_right.png",
	(s2f){1416, 726}, (sfIR){96, 96, 96, 96}, (s2f){2, 2});
	game_info->perso->idd = 0;
	game_info->perso->dl = malloc(sizeof(dialog_t) * 2);
	game_info->perso->dl[0] = init_dialog(1,
	"assets/dialog/1er-dia-persop.png", (sfIR){288, 0, 1156, 192});
	game_info->perso->dl[1] = init_dialog(2,
	"assets/dialog/2nd-dia-persop.png", (sfIR){1536, 1, 1156, 192});
	game_info->perso->dl[1].ind = 0;
}
