/*
** EPITECH PROJECT, 2018
** tablen
** File description:
** lib
*/

#include <stdlib.h>

int	my_tablen(char **tab)
{
	int i = -1;

	if (tab == NULL)
		return (0);
	while (tab[++i] != NULL);
	return (i);
}