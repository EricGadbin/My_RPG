/*
** EPITECH PROJECT, 2018
** init_battle.c
** File description:
** rpg
*/

#include "prototype.h"

void fill_info_struct(info_t *game_info, button_t *list, fight_t *info)
{
	pers_t *perso = game_info->perso;

	for (; list->state != 2; perso = perso->next, list = list->next)
		info->id += 1;
	info->perso = perso;
}

sprite_t *init_combat_stats_sprites(void)
{
	sprite_t *bar = malloc(sizeof(*bar));
	sprite_t *life_bar = malloc(sizeof(*life_bar));
	sprite_t *speed_bar = malloc(sizeof(*speed_bar));

	bar->sprite = sfSprite_create();
	life_bar->sprite = sfSprite_create();
	speed_bar->sprite = sfSprite_create();
	sfSprite_setTexture(speed_bar->sprite,
	sfTexture_createFromFile("assets/speed_bar.png", NULL), sfFalse);
	sfSprite_setScale(speed_bar->sprite, (sfVector2f){0, 1});
	sfSprite_setTexture(life_bar->sprite,
	sfTexture_createFromFile("assets/life_bar.png",
	NULL), sfFalse);
	sfSprite_setTexture(bar->sprite,
	sfTexture_createFromFile("assets/bar.png", NULL), sfFalse);
	bar->next = life_bar;
	life_bar->next = speed_bar;
	speed_bar->next = NULL;
	return (bar);
}

void start_battle_music(info_t *game_info)
{
	sfMusic_setLoop(game_info->battle_theme, 1);
	sfMusic_stop(game_info->menu_song);
	sfMusic_stop(game_info->village_song);
	sfMusic_stop(game_info->dungeon);
	sfMusic_play(game_info->battle_theme);
}

void init_battle(info_t *game_info)
{
	int pos_x = 1100;
	int pos_y = 500;
	int count = 1;

	start_battle_music(game_info);
	for (pers_t *p = game_info->perso; p; p = p->next, count++) {
		p->health = p->stats->health;
		p->speed = 0;
		p->app->ret_ob.top = 240;
		sfSprite_setTextureRect(p->app->sp_ob,
		p->app->ret_ob);
		if (count == 2)
			p->pos_fight = (sfVector2f){pos_x, pos_y - 40};
		else if (count == 3)
			p->pos_fight = (sfVector2f){pos_x, pos_y + 40};
		else
			p->pos_fight = (sfVector2f){pos_x, pos_y};
		sfSprite_setPosition(p->app->sp_ob, p->pos_fight);
		pos_x += 80;
	}
}
