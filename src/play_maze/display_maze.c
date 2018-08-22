/*
** EPITECH PROJECT, 2018
** maze.c
** File description:
** rpg
*/

#include "prototype.h"
#include "maze.h"
#include "macrocsfml.h"

void print_maze(info_t *ginf, char *map)
{
	for (int j = 0; map[j] != '\0'; j++) {
		if (map[j] == 48 || map[j] == 42)
			SP_DSP(ginf->window,
				ginf->wall->sp_ob, NULL);
		else
			SP_DSP(ginf->window,
				ginf->floor->sp_ob, NULL);
		if (map[j] == 50 || map[j] == 47)
			print_chest(ginf, ginf->floor->pos_ob, map[j]);
		if (map[j] > 50) {
			move_mob(ginf);
			print_mob(ginf, ginf->floor->pos_ob, map[j] - 50);
		}
		if (map[j] == 42)
			print_door(ginf, ginf->wall->pos_ob);
		ginf->wall->pos_ob.x += 180;
		ginf->floor->pos_ob.x += 180;
		SP_SPOS(ginf->wall->sp_ob, ginf->wall->pos_ob);
		SP_SPOS(ginf->floor->sp_ob, ginf->floor->pos_ob);
	}
}

void display_maze(info_t *ginf, char **map)
{
	ginf->floor->pos_ob.x = ginf->map.x;
	ginf->floor->pos_ob.y = ginf->map.y;
	ginf->wall->pos_ob.x = ginf->map.x;
	ginf->wall->pos_ob.y = ginf->map.y;
	SP_SPOS(ginf->wall->sp_ob, ginf->wall->pos_ob);
	for (int i = 0; map[i]; i++) {
		print_maze(ginf, map[i]);
		ginf->wall->pos_ob.x = ginf->map.x;
		ginf->floor->pos_ob.x = ginf->map.x;;
		ginf->wall->pos_ob.y += 180;
		ginf->floor->pos_ob.y += 180;
		SP_SPOS(ginf->wall->sp_ob,
		ginf->wall->pos_ob);
		SP_SPOS(ginf->floor->sp_ob,
		ginf->floor->pos_ob);
	}
	SP_DSP(ginf->window, ginf->perso->app->sp_ob, NULL);
	SP_DSP(ginf->window, ginf->shader->sp_ob, NULL);
}

void init_new_maze(info_t *ginf)
{
	maze_t *maze = get_maze(20, 20);

	ginf->scene = 1;
	ginf->perso->app->tex_ob =
	sfTexture_createFromFile("assets/persosheet.png", NULL);
	SP_STX(ginf->perso->app->sp_ob, ginf->perso->app->tex_ob, sfTrue);
	sfSprite_setTextureRect(ginf->perso->app->sp_ob,
	ginf->perso->app->ret_ob);
	free_tab(ginf->maze);
	ginf->maze = converte_maze(maze);
	free(maze);
	if (!ginf->maze)
		return;
	sfMusic_setLoop(ginf->dungeon, 1);
	sfMusic_stop(ginf->menu_song);
	sfMusic_stop(ginf->village_song);
	sfMusic_stop(ginf->battle_theme);
	sfMusic_play(ginf->dungeon);
}
void enter_maze(info_t *ginf)
{
	init_new_maze(ginf);
	while (sfRenderWindow_isOpen(ginf->window)) {
		ginf->shader->pos_ob.x = ginf->perso->app->pos_ob.x - 1630;
		ginf->shader->pos_ob.y = ginf->perso->app->pos_ob.y - 870;
		SP_SPOS(ginf->shader->sp_ob, ginf->shader->pos_ob);
		SP_SPOS(ginf->shader->sp_ob, ginf->shader->pos_ob);
		RW_CLEAR(ginf->window, sfRed);
		check_event(ginf, ginf->maze);
		clock_perso(ginf);
		display_maze(ginf, ginf->maze);
		RW_DRW(ginf->window);
	}
}
