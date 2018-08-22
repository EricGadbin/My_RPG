/*
** EPITECH PROJECT, 2018
** dsad
** File description:
** my_rpg project
*/

#include <stdlib.h>

void	fill_str(char **res, char c, int nb, int len)
{
	(*res)[0] = '(';
	(*res)[1] = c;
	for (int i = len + 1; i >= 2; i--) {
		(*res)[i] = (nb % 10 + 48);
		nb /= 10;
	}
	(*res)[len + 2] = ')';
	(*res)[len + 3] = '\0';
}

char 	*dsad(int nb)
{
	char *res = 0;
	int save = (nb >= 0) ? nb : -nb;
	int len = 0;
	char c = (nb < 0) ? '-' : '+';

	if (nb == 0)
		return ("(+0)");
	nb = (nb < 0) ? -nb : nb;
	while (save > 0) {
		len++;
		save /= 10;
	}
	res = malloc(sizeof(char) * (len + 4));
	if (!res)
		return ("(+0)");
	fill_str(&res, c, nb, len);
	return (res);
}
