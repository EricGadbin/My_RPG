/*
** EPITECH PROJECT, 2018
** buttons.c
** File description:
** rpg
*/

#include "prototype.h"

button_t	*filling_buttons_from_list2(sfVector2f pos, char *name,
	info_t *game_info, int i)
{
	button_t *button;

	button = malloc(sizeof(*button));
	button->index = i;
	button->state = 0;
	button->pos = pos;
	button->text = sfText_create();
	sfText_setFont(button->text, game_info->font);
	sfText_setCharacterSize(button->text, 30);
	sfText_setString(button->text, name);
	sfText_setColor(button->text, sfWhite);;
	sfText_setPosition(button->text, pos);
	return (button);
}

button_t	*filling_buttons_from_list(sfVector2f pos, sfText *text, int i)
{
	button_t *button;

	button = malloc(sizeof(*button));
	button->index = i;
	button->state = 0;
	button->pos = pos;
	button->text = text;
	sfText_setPosition(button->text, pos);
	return (button);
}

void	add_last_character(info_t *ginf, button_t *name3)
{
	button_t *name4;

	if (ginf->perso->next && ginf->perso->next->next &&
		ginf->perso->next->next->next) {
		name4 = filling_buttons_from_list((sfVector2f){1000, 820},
		ginf->perso->next->next->next->ident->name, 1);
		name4->next = name3->next;
		name3->next = name4;
	}
}

void	add_extra_characters(button_t *name, info_t *ginf)
{
	button_t *name3;
	button_t *name2;

	if (ginf->perso->next) {
		name2 = filling_buttons_from_list((sfVector2f){1000, 720},
		ginf->perso->next->ident->name, 3);
		name2->next = name->next;
		name->next = name2;
	}
	if (ginf->perso->next && ginf->perso->next->next) {
		name3 = filling_buttons_from_list((sfVector2f){1000, 770},
		ginf->perso->next->next->ident->name, 2);
		name3->next = name2->next;
		name2->next = name3;
	}
	add_last_character(ginf, name3);
}

button_t	*create_button_list(info_t *game_info)
{
	button_t *name = filling_buttons_from_list((sfVector2f){1000, 670},
	game_info->perso->ident->name, 4);
	button_t *item = filling_buttons_from_list2((sfVector2f){630, 820},
	"group heal", game_info, 8);
	button_t *spell = filling_buttons_from_list2((sfVector2f){630, 670},
	"solo atq", game_info, 5);
	button_t *spell2 = filling_buttons_from_list2((sfVector2f){630, 720},
	"group atq", game_info, 6);
	button_t *spell3 = filling_buttons_from_list2((sfVector2f){630, 770},
	"solo heal", game_info, 7);

	spell->state = 0;
	name->state = 0;
	name->next = spell;
	spell->next = spell2;
	spell2->next = spell3;
	spell3->next = item;
	item->next = NULL;
	add_extra_characters(name, game_info);
	return (name);
}
