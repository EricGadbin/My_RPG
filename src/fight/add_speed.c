/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** add speed
*/

#include "prototype.h"

void	update_state(int i, button_t *list)
{
	button_t *tmp = NULL;

	for (tmp = list; tmp; tmp = tmp->next)
		tmp->state = 0;
	for (tmp = list; tmp->index != i; tmp = tmp->next);
	tmp->state = 2;
	for (; tmp->index != 5; tmp = tmp->next);
	tmp->state = 1;
}

void	add_speed_monster(info_t *info, mob_t *mob)
{
	mob_t *tmp = mob;

	for (; tmp; tmp = tmp->next) {
		if (tmp->health <= 0)
			continue;
		tmp->speed += tmp->stats->speed / 100;
		tmp->speed = tmp->speed >= 100 ? 100 : tmp->speed;
	}
	for (tmp = mob; tmp; tmp = tmp->next) {
		if (tmp->speed == 100 &&
		check_health(info->perso, mob) == 0) {
			monster_attack(tmp, info->perso);
			tmp->speed = 0;
		}
	}
}

void	add_speed_player(info_t *info, button_t *list,
mob_t *mob, sprite_t *bar)
{
	pers_t *tmp = info->perso;
	int i = 4;

	for (; tmp; tmp = tmp->next) {
		if (tmp->health <= 0)
			continue;
		tmp->speed += tmp->stats->speed / 100;
		tmp->speed = tmp->speed >= 100 ? 100 : tmp->speed;
	}
	for (tmp = info->perso; tmp; i -= 1, tmp = tmp->next) {
		if (tmp->speed == 100 &&
		check_health(info->perso, mob) == 0) {
			update_state(i, list);
			attack_loop(info, list, mob, bar);
			tmp->speed = 0;
		}
	}
	add_speed_monster(info, mob);
}
