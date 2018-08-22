/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** rpg
*/

#include "../include/prototype.h"
#include "../include/struct.h"
#include "macrocsfml.h"

void my_usleep(float time1)
{
	sfClock *clock = sfClock_create();
	sfTime time = sfClock_getElapsedTime(clock);
	float seconds = time.microseconds / 1000000.0;

	while (seconds < time1) {
		time = sfClock_getElapsedTime(clock);
		seconds = time.microseconds / 1000000.0;
	}
	sfClock_destroy(clock);
}

float	create_born(float basic, int bornrand, int opt)
{
	float res = 0.0;

	if (opt == 1) {
		res = basic + ((basic / 100) * (rand() % bornrand));
		return (res);
	} else if (opt == 2) {
		res = basic - ((basic / 100) * (rand() % bornrand));
		return (res);
	}
	return (res);
}

char	**my_realloc(char **tab)
{
	char **new = NULL;
	int i = -1;

	while (tab[++i] != NULL);
	new = malloc(sizeof(char*) * (i +2));
	if (!new)
		return (NULL);
	return (new);
}

void	check_dialog(info_t *gf, int ind, sfSprite *sp)
{
	ob_t *s[2];

	if (gf->quest.qind != gf->perso->dl[gf->perso->idd].keyd ||
	ind != gf->perso->dl[gf->perso->idd].ind) {
		s[0] = &gf->pnj[ind].face[0];
		s[1] = &gf->perso->face[1];
		dialog_duo(gf, &gf->pnj[ind].dialog, s, sp);
		return;
	}
	if (gf->quest.qind == gf->perso->dl[gf->perso->idd].keyd &&
	ind == gf->perso->dl[gf->perso->idd].ind) {
		s[0] = &gf->pnj[ind].face[0];
		s[1] = &gf->perso->face[1];
		dialog_duo(gf, &gf->perso->dl[gf->perso->idd], s, sp);
		gf->perso->idd++;
		gf->quest.qind++;
		return;
	}
}

int main(void)
{
	info_t game_info;

	game_info.dt = init_all_data();
	srand(time(NULL));
	if (init_game_info(&game_info) == 84)
		return (84);
	sfRenderWindow_setFramerateLimit(game_info.window, 30);
	sfRenderWindow_setMouseCursorVisible(game_info.window, 0);
	create_character(&game_info);
	create_monsters(&game_info);
	create_bosses(&game_info);
	create_spell(&game_info);
	init_menus(&game_info);
	init_inventory(&game_info);
	select_start_menu(&game_info);
	destroy(&game_info);
	return (0);
}
