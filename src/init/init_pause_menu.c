/*
** EPITECH PROJECT, 2018
** init_pause_menu.c
** File description:
** rpg
*/

#include "prototype.h"

void fill_pause_menu2(button_t *stats, button_t *quest,
button_t *tuto, menu_t *menu)
{
	quest->index = 5;
	quest->callback = &select_quest_menu;
	quest->next = stats;
	tuto->index = 6;
	tuto->callback = &select_tuto_menu;
	tuto->next = quest;
	menu->button = tuto;
}

void fill_pause_menu(button_t *strt, button_t *qt,
button_t *inv, button_t *stats)
{
	qt->index = 2;
	stats->index = 7;
	strt->index = 4;
	qt->callback = &select_quit_menu;
	strt->callback = &select_start_menu;
	stats->callback = &select_stat_menu;
	stats->next = inv;
	strt->next = qt;
	qt->next = NULL;
	inv->index = 1;
	inv->callback = &display_inventory_in_game;
	inv->next = strt;
}

void init_buttons(button_t *stats, button_t *quest,
button_t *tuto, info_t *game_info)
{
	create_button_pause(quest, "Quest", (sfVector2f){60, 330},
	game_info->font);
	create_button_pause(tuto, "Tutorial", (sfVector2f){60, 420},
	game_info->font);
	create_button_pause(stats, "Stats", (sfVector2f){60, 240},
	game_info->font);
}

void init_pause_menu(info_t *game_info, menu_t *menu)
{
	button_t *inv = malloc(sizeof(*inv));
	button_t *quit = malloc(sizeof(*quit));
	button_t *start = malloc(sizeof(*start));
	button_t *quest = malloc(sizeof(*quest));
	button_t *tuto = malloc(sizeof(*tuto));
	button_t *stats = malloc(sizeof(*stats));

	create_button_pause(quit, "Quit Game", (sfVector2f){60, 600},
	game_info->font);
	create_button_pause(start, "Nenu", (sfVector2f){60, 510},
	game_info->font);
	create_button_pause(inv, "Inventory", (sfVector2f){60, 150},
	game_info->font);
	init_buttons(stats, quest, tuto, game_info);
	fill_pause_menu(start, quit, inv, stats);
	fill_pause_menu2(stats, quest, tuto, menu);
}
