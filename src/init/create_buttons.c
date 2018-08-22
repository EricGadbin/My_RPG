/*
** EPITECH PROJECT, 2018
** create_buttons.c
** File description:
** rpg
*/

#include "prototype.h"

void choose_sprite_color(sfSprite *sprite, int state)
{
	if (state == 0) {
		sfSprite_setTexture(sprite,
		sfTexture_createFromFile("assets/play_button_idle.png",
		NULL), sfFalse);
	} else if (state == 1) {
		sfSprite_setTexture(sprite,
		sfTexture_createFromFile("assets/play_button_hover.png",
		NULL), sfFalse);
	} else {
		sfSprite_setTexture(sprite,
		sfTexture_createFromFile("assets/play_button_clicked.png",
		NULL), sfFalse);
	}
}

sfSprite *create_sprite(sfVector2f pos, int state)
{
	sfSprite *sprite = sfSprite_create();

	sfSprite_setPosition(sprite, pos);
	choose_sprite_color(sprite, state);
	return (sprite);
}

sfSprite *create_sprite_sword(sfVector2f pos)
{
	sfSprite *sprite = sfSprite_create();

	sfSprite_setPosition(sprite, (sfVector2f){pos.x + 160, pos.y - 30});
	sfSprite_setTexture(sprite,
	sfTexture_createFromFile("assets/sword.png",
	NULL), sfFalse);
	sfSprite_setScale(sprite, (sfVector2f){0.8, 0.8});
	return (sprite);
}

void create_button(button_t *button, char *text, sfVector2f pos, sfFont *font)
{
	button->state = 0;
	button->pos = pos;
	button->text = sfText_create();
	sfText_setFont(button->text, font);
	sfText_setCharacterSize(button->text, 45);
	sfText_setString(button->text, text);
	sfText_setPosition(button->text, (sfVector2f){pos.x + 40, pos.y + 40});
	sfText_setColor(button->text, sfBlack);
	button->idle = create_sprite(pos, 0);
	button->hover = create_sprite(pos, 1);
	button->clicked = create_sprite(pos, 2);
}

void create_button_pause(button_t *button, char *text, sfVector2f pos,
	sfFont *font)
{
	button->state = 0;
	button->pos = pos;
	button->text = sfText_create();
	sfText_setFont(button->text, font);
	sfText_setCharacterSize(button->text, 30);
	sfText_setString(button->text, text);
	sfText_setPosition(button->text, (sfVector2f){pos.x, pos.y});
	sfText_setColor(button->text, sfWhite);
	button->idle = NULL;
	button->hover = create_sprite_sword(pos);
	button->clicked = NULL;
}
