/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** lib.h
*/

#ifndef LIB_H_
#define LIB_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

void	my_printf(char *str, ...);
void	my_putstr(char *str);
void	my_put_nbr(int nb);
void	my_putchar(char c);
int	my_strlen(char *str);
char	*get_next_line(int fd);
int	my_getnbr(char *str);
char	**str_to_tab(char *str, char *cat, int opt);
int     search_char_in_array(char c, char *array);
void	clear_tab(char **tab);
int		my_tablen(char **tab);

#endif /* LIB_H_ */
