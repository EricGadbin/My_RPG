/*
** EPITECH PROJECT, 2017
** my_strcat.c
** File description:
** task02
*/

#include "prototype.h"
#include <stdlib.h>
#include <unistd.h>

void combine_str(char *first, char *second, int *i)
{
	for (int j = 0; second[j] != '\0'; j++) {
		first[*i] = second[j];
		*i += 1;
		first[*i] = '\0';
	}
}

char *my_strcat(char *first, char *second)
{
	int i = 0;
	char *str;

	if (first == NULL)
		return (second);
	 str = malloc(sizeof(char) * (my_strlen(first) + \
	my_strlen(second) + 2));

	combine_str(str, first, &i);
	combine_str(str, second, &i);
	return (str);
}
