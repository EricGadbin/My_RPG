/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** player_attack
*/

#include "prototype.h"

void	unique_heal(pers_t *player, pers_t *perso)
{
	perso->health += player->stats->supp *0.80;
	perso->health = perso->health > perso->stats->health
	? perso->stats->health : perso->health;
}

void	global_heal(pers_t *player, pers_t *perso)
{
	for (; perso; perso = perso->next) {
		if (perso->health > 0) {
			perso->health += player->stats->supp * 0.50;
			perso->health = perso->health > perso->stats->health
			? perso->stats->health : perso->health;
		}
	}
}

void	unique_attack(pers_t *player, mob_t *mob)
{
	mob->health -= (player->stats->strenght -
	(mob->stats->supp * 0.25));
}

void	global_attack(pers_t *player, mob_t *mob)
{
	for (; mob; mob = mob->next) {
		mob->health -= (player->stats->strenght * 0.6) - (
		mob->stats->supp * 0.25);
	}
}

void	player_attack(pers_t *player, pers_t *perso, mob_t *mob, int type)
{
	switch (type) {
	case 1:
		unique_attack(player, mob);
		break;
	case 2:
		global_attack(player, mob);
		break;
	case 3:
		unique_heal(player, perso);
		break;
	case 4:
		global_heal(player, perso);
	}
}
