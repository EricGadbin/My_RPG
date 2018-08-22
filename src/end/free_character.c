/*
** EPITECH PROJECT, 2018
** free_charaters.c
** File description:
** rpg
*/

#include "prototype.h"
#include "macrocsfml.h"

void free_perso(pers_t *perso)
{
	pers_t *tmp;

	while (perso) {
		tmp = perso;
		perso = perso->next;
		SP_DSSP(tmp->app->sp_ob);
		sfClock_destroy(tmp->app->perso_clock);
		TXT_DSTXT(tmp->ident->name);
		free(tmp->app);
		free(tmp->ident);
		free(tmp->stats);
		free(tmp);
	}
}

void destroy_rain(rain_t *rain)
{
	rain_t *tmp;

	while (rain) {
		tmp = rain;
		rain = rain->next;
		free(tmp);
	}
}
