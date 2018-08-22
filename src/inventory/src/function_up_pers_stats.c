/*
** EPITECH PROJECT, 2018
** function_up_pers_stats
** File description:
** rpg project
*/

#include "my_rpg.h"

void	is_up_health(stats_t *stats, int add)
{
	stats->health += add;
}

void	is_up_strenght(stats_t *stats, int add)
{
	stats->strenght += add;
}

void	is_up_supp(stats_t *stats, int add)
{
	stats->supp += add;
}

void	is_up_speed(stats_t *stats, int add)
{
	stats->speed += add;
}