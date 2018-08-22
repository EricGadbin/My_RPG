/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** clear_tab
*/

#include "lib.h"

void	clear_tab(char **tab)
{
	for (int i = 0; tab[i]; i += 1)
		free(tab[i]);
	free(tab);
}
