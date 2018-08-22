/*
** EPITECH PROJECT, 2018
** init_character.c
** File description:
** rpg
*/

#include "prototype.h"

void init_stat(mob_t *mob, int id)
{
	mob->stats = malloc(sizeof(stats_t));
	if (id == 1) {
		mob->stats->health = 110;
		mob->stats->strenght = 55;
		mob->stats->supp = 40;
		mob->stats->speed = 101;
	} else if (id == 2) {
		mob->stats->health = 105;
		mob->stats->strenght = 55;
		mob->stats->supp = 32;
		mob->stats->speed = 105;
	} else if (id == 3) {
		mob->stats->health = 150;
		mob->stats->strenght = 40;
		mob->stats->supp = 45;
		mob->stats->speed = 98;
	}
	mob->prev = NULL;
}

mob_t *init_mob(info_t *game_info, char *name, char *description)
{
	mob_t *mob = malloc(sizeof(mob_t));
	static int id = 1;

	mob->name = sfText_create();
	sfText_setFont(mob->name, game_info->font);
	sfText_setCharacterSize(mob->name, 30);
	sfText_setString(mob->name, name);
	sfText_setColor(mob->name, sfWhite);
	mob->description = description;
	mob->id = id;
	init_stat(mob, id);
	mob->health = mob->stats->health;
	mob->speed = 0;
	id++;
	return (mob);
}

void create_monsters(info_t *game_info)
{
	mob_t *mob1 = init_mob(game_info, "gorgone", "oh it is really bad");
	mob_t *mob2 = init_mob(game_info, "gut eye", "yes it is not good");
	mob_t *mob3 = init_mob(game_info, "gargoyle", "erf this thing fly");

	mob1->app = sf_build("assets/monster/snake.png",
	(sfVector2f){1600 / 3, 900 / 3}, (sfIntRect){0, 0, 56, 56},
	(sfVector2f){2.2, 2.2});
	mob2->app = sf_build("assets/monster/eye.png",
	(sfVector2f){1600 / 3, 900 / 3}, (sfIntRect){0, 115, 42, 42},
	(sfVector2f){2.2, 2.2});
	mob3->app = sf_build("assets/monster/gragouille.png",
	(sfVector2f){1600 / 3, 900 / 3}, (sfIntRect){0, 102, 84, 102},
	(sfVector2f){1.8, 1.8});
	mob1->next = mob2;
	mob2->next = mob3;
	mob3->next = mob1;
	game_info->mob = mob1;
}
