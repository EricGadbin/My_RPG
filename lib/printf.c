/*
** EPITECH PROJECT, 2018
** printf
** File description:
** lib
*/

#include "lib.h"

void	disp_variable(va_list list, char c)
{
	switch (c) {
	case 's':
		my_putstr(va_arg(list, char*));
		break;
	case 'd':
		my_put_nbr(va_arg(list, int));
		break;
	case 'c':
		my_putchar((char)va_arg(list, int));
		break;
	default:
		return;
	}
}

void	my_printf(char *str, ...)
{
	int i = 0;
	va_list list;

	va_start(list, str);
	for (i = 0; str[i]; i += 1) {
		if (str[i] == '%')
			disp_variable(list, str[++i]);
		else
			my_putchar(str[i]);
	}
	va_end(list);
}
