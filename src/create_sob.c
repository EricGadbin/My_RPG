/*
** EPITECH PROJECT, 2018
** create sob
** File description:
** porject my_rpg
*/

#include "../include/prototype.h"
#include "../include/struct.h"

csob_t funcreate[4] = {
	{WEAPON, &generate_weapon},
	{CHESTPLATE, &generate_chestplate},
	{LEGSAMOR, &generate_legsarmor},
	{ACCESSORY, &generate_accessory}
};

int	elue(int level)
{
	if (level > -1 && level < 21)
		return (0);
	if (level > 20 && level < 31)
		return (1);
	return (0);
}

sob	*generate_sob(int a, dt_t *dt)
{
	int randi = 0;
	sp_info test;
	int elu = 0;
	int tmp = 0;
	sob *new = NULL;

	test.path = NULL;
	test.pos = (sfVector2f){-100, -100};
	test.rect = (sfIntRect){0, 0, 81, 82};
	test.scale = (sfVector2f){1, 1};
	randi = rand() % 4;
	elu = elue(a);
	tmp = rand() % ((dt[randi].lvs[elu][1] + 1) - dt[randi].lvs[elu][0])
	+ dt[randi].lvs[elu][0];
	test.path = my_strcpy(dt[randi].psp[tmp]);
	new = create_sob(test, dt[randi].ns[tmp], type_item_create(randi), a);
	return (new);
}

sob	*create_sob(sp_info info, char *name, type typeob, int level)
{
	sob *new = malloc(sizeof(sob));

	if (!new)
		return (NULL);
	new->name = my_strcpy(name);
	new->type = typeob;
	for (int i = 0; i < 4; i++) {
		if (new->type == funcreate[i].typeob)
			funcreate[i].my_func(level, &new);
	}
	new->catg = my_strcpy(what_is_type(new->type));
	new->s = sf_build(info.path, info.pos, info.rect, info.scale);
	new->path = my_strcpy(info.path);
	new->ob = NULL;
	return (new);
}
