/*
** EPITECH PROJECT, 2018
** init_game_struct.c
** File description:
** rpg
*/

#include "prototype.h"

void init_scenes_game_info_next(info_t *game_info)
{
	game_info->chest = sf_build("assets/chest.png", (sfVector2f)
	{1600 / 2, 900 / 2}, (sfIntRect){0, 0, 50, 50},
	(sfVector2f){1.2, 1.2});
	game_info->door = sf_build("assets/door.png", (sfVector2f)
	{1600 / 2, 900/ 2}, (sfIntRect){0, 0, 96, 96},
	(sfVector2f){1.25, 1.25});
	game_info->house = sf_build("assets/house.png", (sfVector2f){255, 90},
	(sfIntRect){0, 0, 2368, 1536}, (sfVector2f){0.46875, 0.46875});
}

void init_scenes_game_info2(info_t *game_info)
{
	game_info->cursor = sf_build("assets/cursor.png", (sfVector2f){0, 0},
	(sfIntRect){0, 0, 29, 44}, (sfVector2f){1, 1});
	game_info->village = sf_build("assets/village.png", (sfVector2f){0, 0},
	(sfIntRect){0, 0, 8320, 5760}, (sfVector2f){0.46875, 0.46875});
	game_info->fight = sf_build("assets/fight_backround2.png",
	(sfVector2f){0, 0}, (sfIntRect){0, 0, 8320, 5760}, (sfVector2f){1, 1});
	game_info->wall = sf_build("assets/wall2.png", (sfVector2f)
	{1600 / 2, 900 / 2}, (sfIntRect){0, 0, 512, 512},
	(sfVector2f){0.3515625, 0.3515625});
	game_info->floor = sf_build("assets/floor.png", (sfVector2f)
	{1600 / 2, 900 / 2}, (sfIntRect){0, 0, 1024, 1024},
	(sfVector2f){0.17578125, 0.17578125});
}

void init_scenes_game_info(info_t *game_info)
{
	game_info->shader = sf_build
	("assets/shader.png", (sfVector2f){0, 0},
	(sfIntRect){0, 0, 3200, 1800}, (sfVector2f){1, 1});
	game_info->intro_back = sf_build
	("assets/intro/intro_back.png", (sfVector2f){0, 0},
	(sfIntRect){0, 0, 1600, 900}, (sfVector2f){1, 1});
	game_info->introd1 = sf_build
	("assets/intro/intro.png", (sfVector2f){0, 180},
	(sfIntRect){0, 0, 3200, 100}, (sfVector2f){0.5, 0.5});
	game_info->chimney = sf_build
	("assets/chimney2.png", (sfVector2f){0, 0},
	(sfIntRect){0, 0, 128, 128}, (sfVector2f){0.46875, 0.46875});
	game_info->tree = sf_build
	("assets/tree2.png", (sfVector2f){0, 0},
	(sfIntRect){0, 0, 128, 768}, (sfVector2f){0.46875, 0.46875});
	init_scenes_game_info2(game_info);
	init_scenes_game_info_next(game_info);
}
