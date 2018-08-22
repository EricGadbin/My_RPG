/*
** EPITECH PROJECT, 2018
** end_fight.c
** File description:
** rpg
*/

#include "prototype.h"

void increase_stats(info_t *game_info)
{
	for (pers_t *tmp = game_info->perso; tmp; tmp = tmp->next) {
		tmp->health = tmp->stats->health;
		tmp->speed = 0;
		tmp->exp += sqrt(pow(tmp->level, 3) * 0.8) * 2;
		if (tmp->exp >= pow(tmp->level, 3) * 0.8) {
			tmp->exp = 0;
			tmp->level += 1;
		}
	}
}

int get_last_character(info_t *game_info, pers_t *perso)
{
	pers_t *tmp = game_info->perso;
	int i = 0;

	for (; tmp->next; tmp = tmp->next)
		i++;
	if (i == 1) {
		perso->stats->health = 100;
		perso->stats->strenght = 65;
		perso->stats->speed = 110;
		perso->stats->supp = 40;
	} else {
		perso->stats->health = 150;
		perso->stats->strenght = 50;
		perso->stats->speed = 95;
		perso->stats->supp = 65;
	}
	perso->prev = tmp;
	tmp->next = perso;
	return (i);
}

char *add_name_and_sprite(info_t *game_info, pers_t *perso)
{
	int i = get_last_character(game_info, perso);

	if (i == 1) {
		perso->app = sf_build("assets/persosheet.png",
		(s2f){1600 / 2, 900 / 2}, (sfIR){144, 144, 48, 48},
		(s2f){1.25008571, 1.25008571});
		perso->face[1] = build("assets/faces_right.png",
		(s2f){1416, 726}, (sfIR){192, 96, 96, 96}, (s2f){2, 2});
		return ("rose");
	} else {
		perso->app = sf_build("assets/persosheet.png",
		(s2f){1600 / 2, 900 / 2}, (sfIR){432, 432, 48, 48},
		(s2f){1.25008571, 1.25008571});
		perso->face[1] = build("assets/faces_right.png",
		(s2f){1416, 726}, (sfIR){0, 96, 96, 96}, (s2f){2, 2});
		return ("bradly");
	}
	return (NULL);
}

void add_new_teamate(info_t *game_info)
{
	pers_t *perso = malloc(sizeof(pers_t));
	char *name;

	sfMusic_setLoop(game_info->dungeon, 1);
	sfMusic_stop(game_info->battle_theme);
	sfMusic_play(game_info->village_song);
	create_base_2(game_info, perso);
	name = add_name_and_sprite(game_info, perso);
	perso->ident->tmpname = my_strcpy(name);
	sfText_setString(perso->ident->name, name);
	perso->next = NULL;
	SP_DSSP(game_info->fight->sp_ob);
	sfClock_destroy(game_info->fight->perso_clock);
	game_info->fight = sf_build("assets/fight_backround2.png",
	(sfVector2f){0, 0}, (sfIntRect){0, 0, 8320, 5760},
	(sfVector2f){1, 1});
	game_info->boss_fight = 0;
	game_info->boss_nb += 1;
}

void finish_battle(info_t *game_info, mob_t *mob, sprite_t *bar,
button_t *list)
{
	free_sprite_list(bar);
	free_buttons_fight(list);
	sfMusic_stop(game_info->battle_theme);
	if (check_health(game_info->perso, mob) == 2) {
		select_retry_menu(game_info);
		return;
	}
	sfMusic_setLoop(game_info->dungeon, 1);
	sfMusic_play(game_info->dungeon);
	increase_stats(game_info);
	add_new_ent_in_inv(generate_sob(game_info->perso->level,
	game_info->dt), &game_info->perso->persinv);
	if (game_info->boss_fight == 0) {
	} else {
		if (game_info->boss_nb != 3) {
			add_new_teamate(game_info);
			enter_village(game_info);
		} else
			end_game(game_info);
	}
}
