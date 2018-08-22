/*
** EPITECH PROJECT, 2018
** Project my_rpg
** File description:
** Main file.
*/

#include <stdlib.h>
#include <stdio.h>

char 	*my_itoa(int nb)
{
	char *res = 0;
	int save = nb;
	int len = 0;

	if (nb <= 0)
		return ("0");
	while (save > 0) {
		len++;
		save /= 10;
	}
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return ("0");
	for (int i = len -1; i >= 0; i--) {
		res[i] = (nb % 10 + 48);
		nb /= 10;
	}
	res[len] = '\0';
	return (res);
}
