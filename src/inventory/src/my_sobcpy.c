/*
** EPITECH PROJECT, 2018
** my_sobcpy
** File description:
** rpg project
*/

#include "macrocsfml.h"
#include "inventory.h"

sob	*my_sobcpy(sob *ref)
{
	sob *cpy = malloc(sizeof(sob));
	sfIR rect = {0, 0, 81, 82};

	cpy->name = my_strcpy(ref->name);
	cpy->a_life = ref->a_life;
	cpy->a_st = ref->a_st;
	cpy->a_supp = ref->a_supp;
	cpy->a_speed = ref->a_speed;
	cpy->type = ref->type;
	cpy->catg = my_strcpy(ref->catg);
	cpy->s = sf_build(ref->path, (s2f){-100, -100}, rect, (s2f){1, 1});
	cpy->path = my_strcpy(ref->path);
	cpy->ob = NULL;
	return (cpy);
}

void 	free_sob(sob *id)
{
	if (!id)
		return;
	if (id->ob != NULL)
		free_obt(id->ob);
	if (id->s != NULL)
		free_obt(id->s);
	free(id);
}