/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** monster_attack
*/

#include "prototype.h"

void	monster_attack(mob_t *mob, pers_t *perso)
{
	int rd = rand() % get_nb_perso(perso);
	pers_t *tmp = perso;

	for (int i = 0; i != rd; i += 1, tmp = tmp->next);
	if (tmp->health <= 0)
		for (tmp = perso; tmp->health <= 0; tmp = tmp->next);
	tmp->health -= (mob->stats->strenght - tmp->stats->supp *0.25);
}
