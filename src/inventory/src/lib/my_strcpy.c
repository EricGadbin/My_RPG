/*
** EPITECH PROJECT, 2018
** my_strcpy
** File description:
** project my rpg
*/

#include <unistd.h>
#include <stdlib.h>

char 	*my_strcpy(char *str)
{
	char *new = NULL;
	int i = -1;
	int e = 0;

	if (!str)
		return (NULL);
	while (str[++i] != '\0');
	new = malloc(sizeof(char) * (i + 1));
	if (!new)
		return (NULL);
	for (; e < i; e++) {
		new[e] = str[e];
	}
	new[e] = '\0';
	return (new);
}
