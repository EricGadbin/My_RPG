/*
** EPITECH PROJECT, 2018
** display_mob_and_players.c
** File description:
** rpg
*/

#include "prototype.h"

void	display_players(info_t *game_info)
{
	pers_t *player = game_info->perso;

	for (; player; player = player->next) {
		if (player->health > 0)
			sfRenderWindow_drawSprite(game_info->window,
			player->app->sp_ob, NULL);
	}
}

void	place_boss(info_t *game_info, mob_t *mob)
{
	if (mob->id == 4) {
		SP_SPOS(mob->app->sp_ob, (sfVector2f){500 - 40, 300});
		move_boss1(game_info, mob);
	}
	if (mob->id == 5) {
		SP_SPOS(mob->app->sp_ob, (sfVector2f){500 - 150, 100});
		move_boss3(game_info, mob);
	}
	if (mob->id == 6) {
		SP_SPOS(mob->app->sp_ob, (sfVector2f){500 - 150, 370});
		move_boss2(game_info, mob);
	}
}

void	print_mob_and_name(info_t *game_info, mob_t *mob)
{
	if (mob->health > 0)
		sfRenderWindow_drawSprite(game_info->window,
		mob->app->sp_ob, NULL);
	sfRenderWindow_drawText(game_info->window, mob->name, NULL);
}

void	display_mobs(info_t *game_info, mob_t *mob)
{
	int spot = 500;
	int spot2 = 670;
	int count = 1;

	for (; mob; mob = mob->next) {
		SP_SPOS(mob->app->sp_ob, (sfVector2f){spot, 440});
		place_boss(game_info, mob);
		if (mob->id == 3)
			SP_SPOS(mob->app->sp_ob, (sfVector2f){spot, 400});
		else if (count == 2)
			SP_SPOS(mob->app->sp_ob, (sfVector2f){spot, 420});
		else if (count == 3)
			SP_SPOS(mob->app->sp_ob, (sfVector2f){spot, 460});
		sfText_setPosition(mob->name, (sfVector2f){100, spot2});
		print_mob_and_name(game_info, mob);
		spot2 += 50;
		spot -= 120;
		count++;
	}
}
