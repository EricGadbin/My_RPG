/*
** EPITECH PROJECT, 2018
** init dis_r
** File description:
** project minishell2
*/

#include "macrocsfml.h"
#include "inventory.h"

void	update_sfvector_for_init(s2f *tmp, s2f *tmp2, float valu)
{
	(*tmp2).x += valu;
	(*tmp).y += 40;
	(*tmp2).y += 40;
}

b_dis *is_init_dis(void)
{
	b_dis *init = malloc(sizeof(*init));

	if (!init)
		return (NULL);
	init->xbegin = 465;
	init->xend = 1000;
	init->ybegin = 100;
	init->aug = 84;
	return (init);
}

br_dis 	*init_re_dis(void)
{
	br_dis *res = malloc(sizeof(br_dis));
	s2f tmp = {1250, 280};
	s2f tmp2 = {1250 + 85, 280 +5};

	if (!res)
		return (NULL);
	res->obsq = (s2f){1350, 150};
	res->nameob = cdvalue("name : ", "none", tmp, tmp2);
	update_sfvector_for_init(&tmp, &tmp2, -5);
	res->typeob = cdvalue("type : ", "none", tmp, tmp2);
	update_sfvector_for_init(&tmp, &tmp2, 40);
	res->ad_life = cdvalue("add life : ", "none", tmp, tmp2);
	update_sfvector_for_init(&tmp, &tmp2, 65);
	res->ad_st = cdvalue("add strength : ", "none", tmp, tmp2);
	update_sfvector_for_init(&tmp, &tmp2, -60);
	res->ad_supp = cdvalue("add supp : ", "none", tmp, tmp2);
	update_sfvector_for_init(&tmp, &tmp2, 10);
	res->ad_speed = cdvalue("add speed : ", "none", tmp, tmp2);
	return (res);
}

br_dis_sta *init_rea_dis(stats_t *sta)
{
	br_dis_sta *res = malloc(sizeof(br_dis_sta));
	s2f t = {80, 610};
	s2f tm2 = t;

	tm2.x += 110;
	tm2.y += 5;
	if (!res)
		return (NULL);
	res->health = cdvalue("health : ", my_itoa(sta->health), t, tm2);
	update_sfvector_for_init(&t, &tm2, 25);
	res->strength = cdvalue("strength : ", my_itoa(sta->strenght), t, tm2);
	update_sfvector_for_init(&t, &tm2, -55);
	res->supp = cdvalue("supp : ", my_itoa(sta->supp), t, tm2);
	update_sfvector_for_init(&t, &tm2, 10);
	res->speed = cdvalue("speed : ", my_itoa(sta->speed), t, tm2);
	return (res);
}
