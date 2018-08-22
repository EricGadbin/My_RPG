/*
** EPITECH PROJECT, 2018
** lib
** File description:
** my_getnbr
*/

int	my_getnbr(char *str)
{
	int mult = 1;
	int nbr = 0;
	int i = -1;

	if (!str)
		return (0);
	mult *= str[0] == '-' ? -1 : 1;
	i += str[0] == '-' ? 1 : 0;
	while (str[++i] && str[i] >= '0' && str[i] <= '9')
		nbr = nbr * 10 + str[i] - 48;
	return (nbr);
}
