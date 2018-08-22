/*
** EPITECH PROJECT, 2018
** display inv
** File description:
** project my_rpg
*/

#include "macrocsfml.h"
#include "inventory.h"

void 	print_clist(sfRW *win, stack **list, s2f *ref)
{
	SP_SPOS((*list)->data->s->sp_ob, (*ref));
	SP_DSP(win, (*list)->data->s->sp_ob, NULL);
}

void	display_nb_stack(sfRW *win, stock *tmp, s2f *ref, b_dis *tr)
{
	TXT_SPOS(tmp->nbs->t, (*ref));
	TXT_DTXT(win, tmp->nbs->t, NULL);
	if ((*ref).x < tr->xend) {
		(*ref).x += tr->aug;
	} else {
		(*ref).x = tr->xbegin;
		(*ref).y += tr->aug + 4;
	}
}

void	p_list(sfRW *win, stock *sto, stock *soind, b_dis *tr)
{
	s2f vtmp = {tr->xbegin, tr->ybegin};
	stock *tmp = NULL;
	stack *atmp = NULL;

	if (sto == NULL)
		return;
	tmp = sto;
	while (tmp != NULL) {
		if (tmp->stack != NULL && tmp != soind) {
			atmp = tmp->stack;
			sfSprite_setColor(atmp->data->s->sp_ob, sfWhite);
			print_clist(win, &atmp, &vtmp);
			display_nb_stack(win, tmp, &vtmp, tr);
		} else if (tmp->stack != NULL && tmp == soind) {
			atmp = tmp->stack;
			sfSprite_setColor(atmp->data->s->sp_ob, sfRed);
			print_clist(win, &atmp, &vtmp);
			display_nb_stack(win, tmp, &vtmp, tr);
		}
		tmp = tmp->next;
	}
}
