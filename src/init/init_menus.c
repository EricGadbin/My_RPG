/*
** EPITECH PROJECT, 2018
** init_menus.c
** File description:
** rpg
*/

#include "prototype.h"

sfSprite *create_back(int index)
{
	sfSprite *sprite = sfSprite_create();

	if (index == 0) {
		sfSprite_setPosition(sprite, (sfVector2f){0, 0});
		sfSprite_setTexture(sprite, sfTexture_createFromFile(
		"assets/back_menu.png", NULL), sfFalse);
	} else if (index == 1){
		sfSprite_setPosition(sprite, (sfVector2f){30, 110});
		sfSprite_setTexture(sprite, sfTexture_createFromFile(
			"assets/back_pause_menu.png", NULL), sfFalse);
		sfSprite_setScale(sprite, (sfVector2f){0.5, 0.58});
	} else {
		sfSprite_setPosition(sprite, (sfVector2f){1600 / 2 -
		(600 * 0.9 / 2), 900 / 2 - (1000 * 0.6 / 2)});
		sfSprite_setTexture(sprite, sfTexture_createFromFile(
			"assets/back_pause_menu.png", NULL), sfFalse);
		sfSprite_setScale(sprite, (sfVector2f){0.9, 0.65});
	}
	return (sprite);
}

menu_t *init_standard_button(info_t *game_info, int index)
{
	menu_t *menu = malloc(sizeof(*menu));

	menu->next = game_info->menu;
	menu->logo = sfSprite_create();
	sfSprite_setPosition(menu->logo, (sfVector2f){-100, 100});
	sfSprite_setTexture(menu->logo,
	sfTexture_createFromFile("assets/logo.png", NULL), sfFalse);
	menu->back = create_back(index);
	game_info->menu = menu;
	return (menu);
}

void init_menus(info_t *game_info)
{
	menu_t *quit = init_standard_button(game_info, 2);
	menu_t *in_game_settings = init_standard_button(game_info, 2);
	menu_t *restart = init_standard_button(game_info, 2);
	menu_t *pause = init_standard_button(game_info, 1);
	menu_t *settings = init_standard_button(game_info, 0);
	menu_t *start = init_standard_button(game_info, 0);

	init_in_game_settings(game_info, in_game_settings);
	init_start_menu(game_info, start);
	init_settings_menu(game_info, settings);
	init_pause_menu(game_info, pause);
	init_retry_menu(game_info, restart);
	init_quit_menu(game_info, quit);
}
