/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** mob list
*/

#include "prototype.h"

mob_t	*mob_add(mob_t *mob, mob_t *list)
{
	mob_t *new = malloc(sizeof(*new));

	if (!new)
		return (NULL);
	*new = *mob;
	new->next = list;
	if (list)
		list->prev = new;
	return (new);
}

mob_t	*create_mob_list(info_t *game_info, int first, int nb)
{
	mob_t *tmp = game_info->mob;
	mob_t *list = NULL;

	for (int i = 1; i < first; tmp = tmp->next, i += 1);
	list = mob_add(tmp, list);
	for (int j = 1; j < nb; j += 1) {
		tmp = game_info->mob;
		first = rand() % 3 + 1;
		for (int i = 1; i < first; tmp = tmp->next, i += 1);
		list = mob_add(tmp, list);
	}
	return (list);
}
