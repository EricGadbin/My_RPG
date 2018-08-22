/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** project
*/

#include "inventory.h"

int 	is_print_weapon(void);
int 	is_print_chestplate(void);
int 	is_print_legsarmor(void);
int 	is_print_accessory(void);
int 	is_print_key_item(void);
char 	*r_weapon(void);
char 	*r_chestplate(void);
char 	*r_legsarmor(void);
char  	*r_accessory(void);
char 	*r_key_item(void);

struct line_cat findcat[5] = {
	{WEAPON, &is_print_weapon},
	{CHESTPLATE, &is_print_chestplate},
	{LEGSAMOR, &is_print_legsarmor},
	{ACCESSORY, &is_print_accessory},
	{KEY_ITEM, &is_print_key_item}
};

struct type_item types[5] = {
	{WEAPON, &r_weapon},
	{CHESTPLATE, &r_chestplate},
	{LEGSAMOR, &r_legsarmor},
	{ACCESSORY, &r_accessory},
	{KEY_ITEM, &r_key_item}
};

int 	my_enumcmp(type cmp, type id)
{
	if (id != cmp)
		return (1);
	return (0);
}

char 	*what_is_type(type type)
{
	char *res = 0;

	for (int i = 0; i < 5; i++) {
		if (type == findcat[i].key) {
			res = types[i].my_func();
			break;
		}
	}
	return (res);
}

int 	is_find_category(type type)
{
	int res = 0;

	for (int i = 0; i < 5; i++) {
		if (type == findcat[i].key) {
			res = findcat[i].my_func();
			break;
		}
	}
	return (res);
}
