/*
** EPITECH PROJECT, 2018
** Project my_rpg
** File description:
** Main file.
*/

#include "macrocsfml.h"
#include "inventory.h"

int	kw(sob *ob)
{
	static int i = 0;

	if (ob != NULL && i == 0) {
		i++;
		return (ob->a_life);
	} else if (ob != NULL && i == 1) {
		i++;
		return (ob->a_st);
	}
	if (ob != NULL && i == 2) {
		i++;
		return (ob->a_supp);
	} else if (ob != NULL && i == 3) {
		i = 0;
		return (ob->a_speed);
	}
	return (0);
}

void	event_inventory(all **st, w_pt **equip, stats_t **stats, int *i)
{
	event_move_in_inv(st, i, *equip);
	event_supr_in_inv(st, *equip, i);
	event_equip_in_inv(st, equip, stats, i);
}

void	event_inventory_2(sfEvent event, int *a, int *j)
{
	if (event.type == sfEvtClosed) {
		*j = 1;
		*a = 1;
	}
	if (KB_IKP(sfKeyEscape))
		*a = 1;
}

void	display_all(sfRW *win, pers_t *id, int *i)
{
	SP_DSP(win, id->persinv->back->sp_ob, NULL);
	SP_SPOS(id->face[1].sp_ob, (sfVector2f){1300, 600});
	SP_DSP(win, id->face[1].sp_ob, NULL);
	p_list(win, id->persinv->stock, id->persinv->soind, id->persinv->tr);
	is_dis_re(id->persinv->soind, id->persinv->trr, win);
	is_dis_rae(id->persinv->tra, win);
	is_dis_stadd(id->persinv->stadd, win);
	dis_wpt(id->eq, win);
	*i = 0;
}

void	display_inventory_2(sfRW *win, pers_t **pers, int *j)
{
	int i = 0;
	sfEvent event;
	int a = 0;
	pers_t *id = *pers;

	while (sfRenderWindow_isOpen(win) && a == 0) {
		while (sfRenderWindow_pollEvent(win, &event)) {
			event_inventory_2(event, &a, j);
			change_perso_in_inv(&id, &i);
			event_inventory(&id->persinv, &id->eq, &id->stats, &i);
		}
		RW_CLEAR(win, sfBlack);
		display_all(win, id, &i);
		RW_DRW(win);
	}
}
