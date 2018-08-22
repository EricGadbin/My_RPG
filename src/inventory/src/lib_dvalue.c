/*
** EPITECH PROJECT, 2018
** lib_dvalue.c
** File description:
** project my_rpg
*/

#include "macrocsfml.h"
#include "inventory.h"

dvalue_t *cdvalue(char *data, char *value, s2f datapos, s2f vpos)
{
	dvalue_t *new = malloc(sizeof(dvalue_t));

	if (!new)
		return (NULL);
	new->data = sf_buildt(data, "assets/Timepiece.otf", 25, datapos);
	new->value = sf_buildt(value, "assets/Timepiece.otf", 20, vpos);
	return (new);
}

void	update_dvalue(dvalue_t **re, char *newvalue, int opt)
{
	(*re)->value->str = my_strcpy(newvalue);
	if (opt == 1 || opt == 2)
		free(newvalue);
	TXT_SSTR((*re)->value->t, (*re)->value->str);
}

void	display_dvalue(dvalue_t *node, sfRW *win)
{
	TXT_DTXT(win, node->data->t, NULL);
	TXT_DTXT(win, node->value->t, NULL);
}
