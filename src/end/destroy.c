/*
** EPITECH PROJECT, 2018
** destroy.c
** File description:
** rpg
*/

#include "prototype.h"
#include "macrocsfml.h"

void destroy_spells(info_t *game_info)
{
	SP_DSSP(game_info->spell[0]->sp_ob);
	sfClock_destroy(game_info->spell[0]->perso_clock);
	SP_DSSP(game_info->spell[1]->sp_ob);
	sfClock_destroy(game_info->spell[1]->perso_clock);
	SP_DSSP(game_info->spell[2]->sp_ob);
	sfClock_destroy(game_info->spell[2]->perso_clock);
	SP_DSSP(game_info->spell[3]->sp_ob);
	sfClock_destroy(game_info->spell[3]->perso_clock);
	SP_DSSP(game_info->spell[4]->sp_ob);
	sfClock_destroy(game_info->spell[4]->perso_clock);
	SP_DSSP(game_info->spell[5]->sp_ob);
	sfClock_destroy(game_info->spell[5]->perso_clock);
	SP_DSSP(game_info->spell[6]->sp_ob);
	sfClock_destroy(game_info->spell[6]->perso_clock);
}

void destroy_scenes2(info_t *game_info)
{
	SP_DSSP(game_info->floor->sp_ob);
	sfClock_destroy(game_info->floor->perso_clock);
	SP_DSSP(game_info->shader->sp_ob);
	sfClock_destroy(game_info->shader->perso_clock);
	SP_DSSP(game_info->intro_back->sp_ob);
	sfClock_destroy(game_info->intro_back->perso_clock);
	SP_DSSP(game_info->chimney->sp_ob);
	sfClock_destroy(game_info->chimney->perso_clock);
	SP_DSSP(game_info->introd1->sp_ob);
	sfClock_destroy(game_info->introd1->perso_clock);
	SP_DSSP(game_info->tree->sp_ob);
	sfClock_destroy(game_info->tree->perso_clock);
}

void destroy_scenes(info_t *game_info)
{
	SP_DSSP(game_info->chest->sp_ob);
	sfClock_destroy(game_info->chest->perso_clock);
	SP_DSSP(game_info->door->sp_ob);
	sfClock_destroy(game_info->door->perso_clock);
	SP_DSSP(game_info->house->sp_ob);
	sfClock_destroy(game_info->house->perso_clock);
	SP_DSSP(game_info->cursor->sp_ob);
	sfClock_destroy(game_info->cursor->perso_clock);
	SP_DSSP(game_info->village->sp_ob);
	sfClock_destroy(game_info->village->perso_clock);
	SP_DSSP(game_info->fight->sp_ob);
	sfClock_destroy(game_info->fight->perso_clock);
	SP_DSSP(game_info->wall->sp_ob);
	sfClock_destroy(game_info->wall->perso_clock);
	destroy_scenes2(game_info);
}

void	free_menus(info_t *ginf)
{
	button_t *button_tmp;
	menu_t *menu_tmp;

	while (ginf->menu != NULL) {
		while (ginf->menu->button != NULL) {
			TXT_DSTXT(ginf->menu->button->text);
			SP_DSSP(ginf->menu->button->idle);
			SP_DSSP(ginf->menu->button->hover);
			SP_DSSP(ginf->menu->button->clicked);
			button_tmp = ginf->menu->button;
			ginf->menu->button = ginf->menu->button->next;
			free(button_tmp);
		}
		SP_DSSP(ginf->menu->logo);
		SP_DSSP(ginf->menu->back);
		menu_tmp = ginf->menu;
		ginf->menu = ginf->menu->next;
		free(menu_tmp);
	}
}

void	destroy(info_t *game_info)
{
	destroy_scenes(game_info);
	destroy_spells(game_info);
	destroy_rain(game_info->rain);
	MU_DSMU(game_info->menu_song);
	MU_DSMU(game_info->door_song);
	MU_DSMU(game_info->house_theme);
	MU_DSMU(game_info->dungeon);
	MU_DSMU(game_info->village_song);
	MU_DSMU(game_info->battle_theme);
	MU_DSMU(game_info->intro_song);
	sfFont_destroy(game_info->font);
	free_menus(game_info);
	free_tab(game_info->maze);
	free_array(game_info->village_map);
	free_array2(game_info->house_map);
	free_perso(game_info->perso);
	free(game_info->buffer);
	free(game_info->buffer2);
	RW_DSRW(game_info->window);
}
