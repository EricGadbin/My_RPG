/*
** EPITECH PROJECT, 2018
** init_character.c
** File description:
** rpg
*/

#include "prototype.h"
#include "macrocsfml.h"

void create_spell(info_t *ginf)
{
	ginf->spell[0] = sf_build("assets/heal.png",
	(sfVector2f){960, 100}, (sfIntRect){0, -192, 192, 192},
	(sfVector2f){3, 3});
	ginf->spell[1] = sf_build("assets/explosion.png",
	(sfVector2f){220, 250}, (sfIntRect){0, -256, 256, 256},
	(sfVector2f){1.5, 1.5});
	ginf->spell[2] = sf_build("assets/attack/attack1.png",
	(sfVector2f){220, 250}, (sfIntRect){0, -192, 192, 192}, (s2f){1, 1});
	ginf->spell[3] = sf_build("assets/attack/attack2.png",
	(sfVector2f){220, 250}, (sfIntRect){0, -192, 192, 192}, (s2f){1, 1});
	ginf->spell[4] = sf_build("assets/attack/attack3.png",
	(sfVector2f){220, 250}, (sfIntRect){0, -192, 192, 192}, (s2f){1, 1});
	ginf->spell[5] = sf_build("assets/attack/attack4.png",
	(sfVector2f){220, 250}, (sfIntRect){0, -192, 192, 192}, (s2f){1, 1});
	ginf->spell[6] = sf_build("assets/attack/Thunder01.png",
	(sfVector2f){220, 250}, (sfIntRect){0, -192, 192, 192}, (s2f){1, 1});
}
