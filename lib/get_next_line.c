/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** get_next_line
*/

#include "lib.h"

void	reset_get_line(char **save, long *i, int *ret)
{
	free(*save);
	*save = NULL;
	*i = 0;
	*ret = 1;
}

char	*my_strcate(char *s, char *buf)
{
	char *save = malloc(sizeof(char) * (my_strlen(s) + my_strlen(buf) + 1));
	int i = -1;
	int j = -1;

	if (save == NULL)
		return (NULL);
	while (s && s[++i])
		save[i] = s[i];
	if (s) {
		i -= 1;
		free(s);
	}
	while (buf && buf[++j])
		save[++i] = buf[j];
	save[++i] = 0;
	return (save);
}

int	check_line(char *save, long i, int opt)
{
	long j = i;

	while (save && save[i]) {
		if (save[i] == '\n')
			return (i - j);
		i += 1;
	}
	if (opt == 0)
		return (i - j);
	return (-1);
}

char	*get_new_line(char *save, long *i, int ret)
{
	int j = -1;
	int size = check_line(save, *i, 0) + 1;
	char *res = malloc(sizeof(char) * size);

	if (res == NULL)
		return (NULL);
	if (save == NULL || (save[*i] == 0 && ret == 0)) {
		free(res);
		return (NULL);
	}
	while (save[*i] && save[*i] != '\n') {
		res[++j] = save[*i];
		*i += 1;
	}
	res[++j] = 0;
	*i += 1;
	return (res);
}

char	*get_next_line(int fd)
{
	static char *save = NULL;
	char buffer[128];
	char *res = NULL;
	static long i = 0;
	static int ret = 1;

	while (ret != 0 && check_line(save, i, 1) == -1) {
		ret = read(fd, buffer, 127);
		if (ret == -1)
			return (NULL);
		buffer[ret] = 0;
		save = my_strcate(save, buffer);
	}
	res = get_new_line(save, &i, ret);
	if (ret == 0)
		reset_get_line(&save, &i, &ret);
	return (res);
}
