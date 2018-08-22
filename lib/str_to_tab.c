/*
** EPITECH PROJECT, 2018
** my_str_to_word_array
** File description:
** lib
*/

#include "lib.h"

int	skip(char *str, char end, int i)
{
	while (str[++i] && str[i] != end);
	if (str[i])
		return (i);
	else
		return (-2);
}

int	search_separator(char *str, int *i, char *array, int add)
{
	if (str[*i] == 0)
		return (0);
	if (search_char_in_array(str[*i], array) == 0)
		return (0);
	while (str[*i + 1] && search_char_in_array(str[*i + 1], array))
		*i += 1;
	*i += add;
	if (str[*i] == 0 || str[*i + 1] == 0)
		return (0);
	return (1);
}

int	count_tab_line(char *str, char *cut)
{
	int nb = 0;
	int i = 0;

	for (i = 0; i != -1 && str[i]; i += 1) {
		if (search_separator(str, &i, cut, 0)) {
			nb += 1;
			continue;
		}
	}
	if (i == -1 || str[0] == 0)
		return (-1);
	return (nb + 1);
}

char	*get_next_array(char **tmp, char *cut, int opt)
{
	int i = 0;
	int j = 0;
	int k = 0;
	char *new = NULL;
	char *str = *tmp;

	for (i = 0; str[i] && search_char_in_array(str[i], cut) == 0; i += 1);
	new = malloc(sizeof(char) * (i + 1));
	if (!new)
		return (NULL);
	for (j = 0; j < i; j += 1, k += 1) {
		new[k] = str[j];
		if (new[k] == 34)
			k -= opt;
	}
	new[k] = 0;
	search_separator(str, &i, cut, 1);
	*tmp = str + i;
	return (new);
}

char	**str_to_tab(char *str, char *cut, int opt)
{
	int tab_size = 0;
	char **tab = NULL;
	int i = 0;

	search_separator(str, &i, cut, 1);
	str += i;
	tab_size = count_tab_line(str, cut);
	if (tab_size == -1)
		return (NULL);
	tab = malloc(sizeof(char*) * (tab_size + 1));
	if (!tab)
		return (NULL);
	for (int i = 0; i < tab_size; i += 1) {
		tab[i] = get_next_array(&str, cut, opt);
		if (!tab[i])
			return (NULL);
	}
	tab[tab_size] = NULL;
	return (tab);
}
