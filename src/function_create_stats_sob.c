/*
** EPITECH PROJECT, 2018
** create_stats_sob
** File description:
** project minishell2
*/

#include "prototype.h"
#include "../include/struct.h"

float weapon[4] = {0.0, 1.5, 0.25, 0.1};
float chestplate[4] = {3.5, 0.0, 1.5, 0.0};
float legsarmore[4] = {2, 0.0, 1, 1};
float accesssory[4] = {0, 0.5, 0.5, 0.0};

void	generate_weapon(int level, sob **new)
{
	float hbasic = weapon[0] * (log10(level) * 4 + 1);
	float sbasic = weapon[1] * (log10(level) * 4 + 1);
	float subasic = weapon[2] * (log10(level) * 4 + 1);
	float spbasic = weapon[3] * (log10(level) * 4 + 1);

	(*new)->a_life = hbasic;
	(*new)->a_st = sbasic + rand() % level;
	(*new)->a_supp = subasic;
	(*new)->a_speed = spbasic;
}

void	generate_chestplate(int level, sob **new)
{
	float hbasic = chestplate[0] * (log10(level) * 4 + 1);
	float sbasic = chestplate[1] * (log10(level) * 4 + 1);
	float subasic = chestplate[2] * (log10(level) * 4 + 1);
	float spbasic = chestplate[3] * (log10(level) * 4 + 1);

	(*new)->a_life = hbasic + rand() % level;
	(*new)->a_st = sbasic;
	(*new)->a_supp = subasic + rand() % level;
	(*new)->a_speed = spbasic;
}

void    generate_legsarmor(int level, sob **new)
{
	int tmp = (level / 2);
	float hbasic = legsarmore[0] * (log10(level) * 4 + 1);
	float sbasic = legsarmore[1] * (log10(level) * 4 + 1);
	float subasic = legsarmore[2] * (log10(level) * 4 + 1);
	float spbasic = legsarmore[3] * (log10(level) * 4 + 1);
	tmp += tmp == 0 ? 1 : 0;

	(*new)->a_life = hbasic + rand() % tmp;
	(*new)->a_st = sbasic;
	(*new)->a_supp = subasic + rand() % level;
	(*new)->a_speed = spbasic + rand() % level;
}

void	generate_accessory(int level, sob **new)
{
	int tmp = (level / 2);
	float hbasic = accesssory[0] * (log10(level) * 4 + 1);
	float sbasic = accesssory[1] * (log10(level) * 4 + 1);
	float subasic = accesssory[2] * (log10(level) * 4 + 1);
	float spbasic = accesssory[3] * (log10(level) * 4 + 1);

	tmp += tmp == 0 ? 1 : 0;
	(*new)->a_life = hbasic;
	(*new)->a_st = sbasic + rand() % tmp;
	(*new)->a_supp = subasic + rand() % tmp;
	(*new)->a_speed = spbasic;
}
