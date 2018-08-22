/*
** EPITECH PROJECT, 2018
** display_stats.c
** File description:
** rpg
*/

#include "prototype.h"
#include "macrocsfml.h"

sfText *create_tuto_text(info_t *game_info)
{
	sfText *text = sfText_create();

	TXT_SFONT(text, game_info->font);
	TXT_SCSIZE(text, 25);
	TXT_SPOS(text, (sfVector2f){580, 183});
	TXT_SCOL(text, sfWhite);
	TXT_SSTR(text, "move: use arrows\npause and go back\
:\npress escape key\ninteractions: press F key\nmove in inventor\
y: press Q and D keys\ndelete items: press S key\nequip: pres\
s E key when\nin inventory\n\n\ntips:\n\n> during fights, wai\
t for your\ncharacters' bluespeed bar\nto fill up to at\
tack\n> exp will enable you to get better\nitems in ches\
ts and at the\nend of fights\n> f\
ind the boss door in the maze to\nstart the boss fight");
	return (text);
}

void print_tuto(info_t *game_info, menu_t *menu, int i)
{
	sfText *text = create_tuto_text(game_info);

	while (sfRenderWindow_isOpen(game_info->window) &&
	game_info->pause == 0) {
		if (i == 1)
			print_background(game_info, menu);
		else
			print_scene_pause(game_info, menu);
		TXT_DTXT(game_info->window, text, NULL);
		SP_DSP(game_info->window,
		game_info->cursor->sp_ob, NULL);
		RW_DRW(game_info->window);
		if (check_event_quest(game_info)) {
			TXT_DSTXT(text);
			return;
		}
	}
}
