/*
** EPITECH PROJECT, 2018
** change perso in inv
** File description:
** rpg project
*/

#include "macrocsfml.h"
#include "inventory.h"

void	change_perso_right(pers_t **ind, int *i)
{
	*ind = ((*ind)->next != NULL) ? (*ind)->next : (*ind);
	br_dis_rae_update(&(*ind)->persinv->tra, (*ind)->stats);
	if ((*ind)->persinv->soind != NULL)
		up_stadd(&(*ind)->persinv->stadd,
		(*ind)->persinv->soind->stack->data, (*ind)->eq);
	else
		up_stadd(&(*ind)->persinv->stadd, NULL, (*ind)->eq);
	(*i)++;
}

void	change_perso_left(pers_t **ind, int *i)
{
	*ind = ((*ind)->prev != NULL) ? (*ind)->prev : (*ind);
	br_dis_rae_update(&(*ind)->persinv->tra, (*ind)->stats);
	if ((*ind)->persinv->soind != NULL)
		up_stadd(&(*ind)->persinv->stadd,
		(*ind)->persinv->soind->stack->data, (*ind)->eq);
	else
		up_stadd(&(*ind)->persinv->stadd, NULL, (*ind)->eq);
	(*i)++;
}

void	change_perso_in_inv(pers_t **ind, int *i)
{
	if (KB_IKP(sfKeyD) && (*i) != 1)
		change_perso_right(ind, i);
	if (KB_IKP(sfKeyQ) && (*i) != 1)
		change_perso_left(ind, i);
}
