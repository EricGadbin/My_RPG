/*
** EPITECH PROJECT, 2018
** change stats with equips
** File description:
** project minishell2
*/

#include "inventory.h"

void	change_stats_aequip(sob *ob, stats_t **stats)
{
	is_up_pers_stats(1, ob->a_life, *stats);
	is_up_pers_stats(2, ob->a_st, *stats);
	is_up_pers_stats(3, ob->a_supp, *stats);
	is_up_pers_stats(4, ob->a_speed, *stats);
}

void	change_stats_mequip(sob *ob, stats_t **stats)
{
	is_up_pers_stats(1, -ob->a_life, *stats);
	is_up_pers_stats(2, -ob->a_st, *stats);
	is_up_pers_stats(3, -ob->a_supp, *stats);
	is_up_pers_stats(4, -ob->a_speed, *stats);
}
