/*
** EPITECH PROJECT, 2018
** init_character.c
** File description:
** rpg
*/

#include "prototype.h"

void init_stat_boss(mob_t *mob, int id)
{
	mob->stats = malloc(sizeof(stats_t));
	if (id == 4) {
		mob->stats->health = 600;
		mob->stats->strenght = 55;
		mob->stats->supp = 45;
		mob->stats->speed = 190;
	} else if (id == 5) {
		mob->stats->health = 1200;
		mob->stats->strenght = 65;
		mob->stats->supp = 50;
		mob->stats->speed = 290;
	} else if (id == 6) {
		mob->stats->health = 1800;
		mob->stats->strenght = 70;
		mob->stats->supp = 55;
		mob->stats->speed = 490;
	}
	mob->prev = NULL;
}

mob_t *init_boss(info_t *game_info, char *name, char *description)
{
	mob_t *mob = malloc(sizeof(mob_t));
	static int id = 4;

	mob->name = sfText_create();
	sfText_setFont(mob->name, game_info->font);
	sfText_setCharacterSize(mob->name, 30);
	sfText_setString(mob->name, name);
	sfText_setColor(mob->name, sfWhite);
	mob->description = description;
	mob->id = id;
	init_stat_boss(mob, id);
	mob->health = mob->stats->health;
	mob->speed = 0;
	id++;
	return (mob);
}

void create_bosses(info_t *game_info)
{
	mob_t *boss1 = init_boss(game_info,
	"androma", "Oni-san my litle girl");
	mob_t *boss2 = init_boss(game_info, "Cerbere", "doggy dog");
	mob_t *boss3 = init_boss(game_info, "Bael", "eat my spider");

	boss1->app = sf_build("assets/monster/andromalius.png",
	(sfVector2f){1600 / 3, 900 / 3}, (sfIntRect){0, 0, 57, 88},
	(sfVector2f){3.5, 3.5});
	boss2->app = sf_build("assets/monster/doggy.png",
	(sfVector2f){1600 / 3, 900 / 3}, (sfIntRect){0, 0, 128, 128},
	(sfVector2f){4, 4});
	boss3->app = sf_build("assets/monster/bael.png",
	(sfVector2f){1600 / 3, 900 / 3},
	(sfIntRect){0, 0, 83.3333333333, 72.25}, (sfVector2f){4, 4});
	boss1->next = boss3;
	boss3->next = boss2;
	boss2->next = NULL;
	game_info->boss = boss1;
}
