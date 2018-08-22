/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** rpg
*/

#include "prototype.h"
#include "../include/struct.h"
#include "macrocsfml.h"

int **create_village_map(void)
{
	int **village_map = malloc(sizeof(int *) * 45);
	int fd = open("assets/village", O_RDONLY);
	char *tmp = NULL;
	char **tmp2 = NULL;

	for (int i = 0; village_map && i != 45; i++) {
		village_map[i] = malloc(sizeof(int) * 65);
		if (!village_map[i])
			return (NULL);
		tmp = get_next_line(fd);
		tmp2 = str_to_tab(tmp, ",", 1);
		for (int j = 0; j != 65; j++)
			village_map[i][j] = my_getnbr(tmp2[j]);
		free(tmp);
		clear_tab(tmp2);
	}
	return (village_map);
}

void	set_music(info_t* game_info)
{
	set_music(game_info);
	sfMusic_setLoop(game_info->village_song, 1);
	sfMusic_play(game_info->village_song);
	sfMusic_stop(game_info->menu_song);
	sfMusic_stop(game_info->dungeon);
	sfMusic_stop(game_info->battle_theme);
	sfMusic_stop(game_info->house_theme);
}

void init_village_settings(info_t *game_info)
{
	free_array(game_info->village_map);
	game_info->village_map = create_village_map();
	game_info->scene = 0;
	game_info->perso->app->tex_ob =
	sfTexture_createFromFile("assets/persosheet_village.png", NULL);
	sfSprite_setTexture(game_info->perso->app->sp_ob,
	game_info->perso->app->tex_ob, sfTrue);
	game_info->perso->app->pos_ob.x = 195;
	game_info->perso->app->pos_ob.y = 420;
	game_info->map.x = 0;
	game_info->map.y = -1275;
	sfSprite_setPosition(game_info->perso->app->sp_ob,
	game_info->perso->app->pos_ob);
	game_info->perso->app->ret_ob.top = 192;
	sfSprite_setTextureRect(game_info->perso->app->sp_ob,
	game_info->perso->app->ret_ob);
	SP_SPOS(game_info->buffer2->sprite,
	(s2f){0, 0});
}

void init_inventory(info_t *game_info)
{
	sfIR rect[4] = {{288, 128, 32, 32},
	{288, 288, 96, 96},
	{0, 288, 96, 96},
	{288, 1, 1156, 192}};
	quest_t tmp;

	tmp.qind = 1;
	tmp.boss1 = 1;
	tmp.boss2 = 1;
	tmp.boss3 = 1;
	game_info->quest = tmp;
	game_info->pnj = malloc(sizeof(pnj_t));
	game_info->pnj[0] = init_first_pnj("assets/pnjsheet.png",
	"assets/faces_left.png", "assets/faces_right.png", rect);
}
