/*
** EPITECH PROJECT, 2018
** find first and last
** File description:
** my_rpg project
*/

#include "inventory.h"

stack 	*find_last_stack(stack *stac)
{
	stack *tmp = NULL;

	if (!stac)
		return (NULL);
	tmp = stac;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

stack 	*find_first_stack(stack *stac)
{
	stack *tmp = NULL;

	if (!stac)
		return (NULL);
	tmp = stac;
	while (tmp->prev != NULL)
		tmp = tmp->prev;
	return (tmp);
}

stock 	*find_last_stock(stock *stoc)
{
	stock *tmp = NULL;

	if (!stoc)
		return (NULL);
	tmp = stoc;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

stock 	*find_first_stock(stock *stoc)
{
	stock *tmp = NULL;

	if (!stoc)
		return (NULL);
	tmp = stoc;
	while (tmp->prev != NULL)
		tmp = tmp->prev;
	return (tmp);
}
