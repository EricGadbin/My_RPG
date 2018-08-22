/*
** EPITECH PROJECT, 2018
** display_stats.c
** File description:
** rpg
*/

#include "prototype.h"
#include "macrocsfml.h"

void print_quest(info_t *gf, menu_t *menu)
{
	sfText *text = sfText_create();

	TXT_SFONT(text, gf->font);
	TXT_SCSIZE(text, 45);
	TXT_SPOS(text, (sfVector2f){585, 350});
	TXT_SCOL(text, sfWhite);
	(gf->quest.qind >= 3) ?
	TXT_SSTR(text, "        Quest :\n\nDefeat the 3 bosses") :
	TXT_SSTR(text, "        Quest :\n\n      Go outside");
	while (sfRenderWindow_isOpen(gf->window) &&
	gf->pause == 0) {
		print_scene_pause(gf, menu);
		TXT_DTXT(gf->window, text, NULL);
		SP_DSP(gf->window, gf->cursor->sp_ob, NULL);
		RW_DRW(gf->window);
		if (check_event_quest(gf)) {
			TXT_DSTXT(text);
			return;
		}
	}
}
