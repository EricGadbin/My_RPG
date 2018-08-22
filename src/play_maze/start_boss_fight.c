/*
** EPITECH PROJECT, 2018
** start_boss_fight.c
** File description:
** rpg
*/

#include "prototype.h"

void get_boss_background(info_t *game_info)
{
	if (game_info->boss_nb == 0)
		game_info->fight = sf_build("assets/bossback3.png",
		(sfVector2f){0, 0}, (sfIntRect){0, 0, 8320, 5760},
		(sfVector2f){1, 1});
	if (game_info->boss_nb == 1)
		game_info->fight = sf_build("assets/bossback.png",
		(sfVector2f){0, 0}, (sfIntRect){0, 0, 8320, 5760},
		(sfVector2f){1, 1});
	if (game_info->boss_nb == 2)
		game_info->fight = sf_build("assets/bossback2.png",
		(sfVector2f){0, 0}, (sfIntRect){0, 0, 8320, 5760},
		(sfVector2f){1, 1});
}

void	start_boss_fight(info_t *game_info)
{
	mob_t *boss_list = game_info->boss;
	mob_t *boss;

	SP_DSSP(game_info->fight->sp_ob);
	sfClock_destroy(game_info->fight->perso_clock);
	get_boss_background(game_info);
	for (int i = 0; boss_list && i != game_info->boss_nb; i++,
	boss_list = boss_list->next);
	game_info->boss_fight = 1;
	boss = mob_add(boss_list, NULL);
	start_battle(game_info, boss);
}
