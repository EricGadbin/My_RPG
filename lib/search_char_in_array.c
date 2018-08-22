/*
** EPITECH PROJECT, 2018
** lib
** File description:
** char in array
*/

int     search_char_in_array(char c, char *array)
{
	for (int i = 0; array[i]; i += 1) {
		if (array[i] == c)
			return (1);
	}
	return (0);
}
