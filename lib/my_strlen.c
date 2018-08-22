/*
** EPITECH PROJECT, 2018
** lib
** File description:
** my_strlen
*/

int     my_strlen(char *str)
{
	int i = 0;

	for (; str && str[i]; i += 1);
	return (i);
}
