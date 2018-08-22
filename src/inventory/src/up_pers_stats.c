/*
** EPITECH PROJECT, 2018
** Project my_rpg
** File description:
** Main file.
*/

#include "inventory.h"

struct ups {
	int key;
	void (*my_func)(stats_t *stats, int add);
};

struct ups funcs_up[4] = {
	{1, &is_up_health},
	{2, &is_up_strenght},
	{3, &is_up_supp},
	{4, &is_up_speed}
};

void	is_up_pers_stats(int ind, int add, stats_t *stats)
{
	for (int i = 0; i < 4; i++) {
		if (ind == funcs_up[i].key) {
			funcs_up[i].my_func(stats, add);
			break;
		}
	}
}
