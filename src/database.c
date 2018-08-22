/*
** EPITECH PROJECT, 2018
** database
** File description:
** project my_rpg
*/

#include "../include/prototype.h"
#include "../include/struct.h"

dt_t	init_dt(void)
{
	dt_t dt;
	dt.lvs[0][0] = 0;
	dt.lvs[0][1] = -1;
	dt.lvs[1][0] = -1;
	dt.lvs[1][1] = -1;
	dt.ns = NULL;
	dt.psp = NULL;
	return (dt);
}

dt_t	*init_all_data(void)
{
	dt_t *dt = malloc(sizeof(dt_t)* 4);
	int fdw = 0;
	int fdc = 0;
	int fdl = 0;
	int fda = 0;

	for (int i = 0; i < 4; i++)
		dt[i] = init_dt();

	fdw = open("src/name_ob_file/weapon.txt", O_RDONLY);
	fdc = open("src/name_ob_file/chestplate.txt", O_RDONLY);
	fdl = open("src/name_ob_file/legsarmor.txt", O_RDONLY);
	fda = open("src/name_ob_file/accessory.txt", O_RDONLY);
	if (fdw == -1 || fdc == -1 || fdl == -1 || fda == -1)
		return (NULL);
	dt[0] = collect_datasob(dt[0], fdw);
	dt[1] = collect_datasob(dt[1], fdc);
	dt[2] = collect_datasob(dt[2], fdl);
	dt[3] = collect_datasob(dt[3], fda);
	return (dt);
}

char	**add_data_tabe(char *data, char **server)
{
	char **new = NULL;
	int i = 0;

	if (!data)
		return (server);
	if (server == NULL) {
		new = malloc(sizeof(char**) * 2);
		if (!new)
			return (server);
		new[0] = my_strcpy(data);
		new[1] = NULL;
		return (new);
	}
	new = my_realloc(server);
	if (!new)
		return (server);
	for (; server[i] != NULL; i++)
		new[i] = my_strcpy(server[i]);
	new[i] = my_strcpy(data);
	new[i +1] = NULL;
	return (new);
}

void	stack_data(char *str, dt_t *dt, int *ble)
{
	char **itab = NULL;

	itab = str_to_tab(str, ",", 0);
	if (my_tablen(itab) != 2)
		return;
	(*dt).ns = add_data_tabe(itab[0], (*dt).ns);
	(*dt).psp = add_data_tabe(itab[1], (*dt).psp);
	(*ble)++;
}

dt_t	collect_datasob(dt_t dt, int fd)
{
	int ble = 0;
	int i = -1;
	char *gnlr = NULL;
	char *ind[2] = {"between 1 to 10", "between 10 to 20"};

	gnlr = get_next_line(fd);
	while (gnlr != NULL) {
		if (i +1 != 2 && my_strcmp(gnlr, ind[i +1]) == 0) {
			i++;
			dt.lvs[i -1][1] = (i != 0) ? ble -1 : dt.lvs[i -1][1];
			dt.lvs[i][0] = (i != 0 && i != 2) ? ble : dt.lvs[i][0];
		} else if (i != -1)
			stack_data(gnlr, &dt, &ble);
		gnlr = NULL;
		gnlr = get_next_line(fd);
	}
	dt.lvs[i][1] = ble -1;
	if (i != 1)
		return (dt);
	return (dt);
}
