/*
** EPITECH PROJECT, 2018
** create first stack stock
** File description:
** rpg project
*/

#include "inventory.h"

stack 	*create_first_stack(sob *sup)
{
	stack *nws = NULL;

	if (!sup)
		return (NULL);
	nws = malloc(sizeof(stack));
	if (!nws)
		return (NULL);
	nws->prev = NULL;
	nws->next = NULL;
	nws->data = sup;
	return (nws);
}

stock 	*create_first_stock(sob *sup)
{
	stock *nws = NULL;
	sfVector2f p = {-100, -100};

	if (!sup)
		return (NULL);
	nws = malloc(sizeof(stock));
	if (!nws)
		return (NULL);
	nws->prev = NULL;
	nws->next = NULL;
	nws->stack = create_first_stack(sup);
	nws->nb = my_stacklen(nws->stack);
	nws->nbs = sf_buildt(my_itoa(nws->nb), "assets/Timepiece.otf", 20, p);
	return (nws);
}
