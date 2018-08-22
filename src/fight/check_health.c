/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** check health
*/

#include "prototype.h"

int	check_health(pers_t *perso, mob_t *mob)
{
	float total = 0;

	for (;perso; perso = perso->next)
		total += perso->health > 0 ? 1 : 0;
	if (!total)
		return (2);
	for (total = 0; mob; mob = mob->next)
		total += mob->health > 0 ? 1 : 0;
	if (!total)
		return (1);
	return (0);
}
