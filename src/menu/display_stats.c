/*
** EPITECH PROJECT, 2018
** display_stats.c
** File description:
** rpg
*/

#include "prototype.h"
#include "macrocsfml.h"

char *fill_str_stats(info_t *game_info)
{
	char *str = NULL;
	int y = 200;

	for (pers_t *perso = game_info->perso; perso; perso = perso->next) {
		str = my_strcat(str, my_strcat(my_strcat(my_strcat
		("Level: ", my_itoa(perso->level)), "\n"), my_strcat
		(my_strcat(my_strcat(my_strcat("Exp: ", my_itoa(perso->exp)),
		"/"), my_itoa(pow(perso->level, 3) * 0.8)), "\n\n\n")));
		TXT_SCOL(perso->ident->name, sfWhite);
		TXT_SPOS(perso->ident->name, (sfVector2f){585, y});
		SP_SPOS(perso->face[1].sp_ob, (sfVector2f){900, y + 5});
		SP_SCALE(perso->face[1].sp_ob, (sfVector2f){0.5, 0.5});
		y += 139;
	}
	return (str);
}

sfText *create_text_stats(info_t *game_info)
{
	sfText *text = sfText_create();
	char *str = fill_str_stats(game_info);

	TXT_SFONT(text, game_info->font);
	TXT_SCSIZE(text, 30);
	TXT_SPOS(text, (sfVector2f){585, 240});
	TXT_SCOL(text, sfWhite);
	TXT_SSTR(text , str);
	return (text);
}

void text_set(info_t *game_info)
{
	SP_DSP(game_info->window, game_info->cursor->sp_ob, NULL);
	RW_DRW(game_info->window);
}

void print_stats(info_t *game_info, menu_t *menu)
{
	sfText *text = create_text_stats(game_info);

	while (sfRenderWindow_isOpen(game_info->window) &&
	game_info->pause == 0) {
		print_scene_pause(game_info, menu);
		for (pers_t *p = game_info->perso; p; p = p->next) {
			TXT_DTXT(game_info->window, p->ident->name, NULL);
			SP_DSP(game_info->window,
			p->face[1].sp_ob, NULL);
		}
		TXT_DTXT(game_info->window, text, NULL);
		text_set(game_info);
		if (check_event_quest(game_info)) {
			for (pers_t *perso = game_info->perso;
			perso; perso = perso->next)
			SP_SCALE(perso->face[1].sp_ob, (sfVector2f){2, 2});
			TXT_DSTXT(text);
			return;
		}
	}
}
