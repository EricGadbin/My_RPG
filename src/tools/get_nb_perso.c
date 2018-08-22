/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** get_nb_perso
*/

#include "prototype.h"

int	get_nb_mob(mob_t *mob)
{
	int i = 0;

	for (; mob; i += 1, mob = mob->next);
	return (i);
}

int	get_nb_perso(pers_t *perso)
{
	int i = 0;

	for (; perso; i += 1, perso = perso->next);
	return (i);
}
