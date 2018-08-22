/*
** EPITECH PROJECT, 2018
** now_type
** File description:
** rpg
*/

#include "inventory.h"

type	type_item_create(int nb)
{
	switch (nb) {
	case 0:
		return (WEAPON);
	case 1
		:return (CHESTPLATE);
	case 2:
		return (LEGSAMOR);
	case 3:
		return (ACCESSORY);
	case 4:
		return (KEY_ITEM);
	default:
		return (WEAPON);
	}
}
