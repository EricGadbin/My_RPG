/*
** EPITECH PROJECT, 2018
** move re list
** File description:
** project my_rpg
*/

#include "macrocsfml.h"
#include "inventory.h"

void 	move_soind(stock **soind, int i)
{
	if ((*soind) != NULL && (*soind)->next != NULL && i == 1)
		(*soind) = (*soind)->next;
	if ((*soind) != NULL && (*soind)->prev != NULL && i == 0)
		(*soind) = (*soind)->prev;
}

void 	move_stack(stack **ind, int i)
{
	if ((*ind) != NULL && (*ind)->next != NULL && i == 1)
		(*ind) = (*ind)->next;
	if ((*ind) != NULL && (*ind)->prev != NULL && i == 0)
		(*ind) = (*ind)->prev;
}

void	move_all_stack(all **st, int *i, w_pt *eq)
{
	if (KB_IKP(sfKeyDown) && (*i) != 1) {
		if ((*st)->soind != NULL) {
			move_stack(&(*st)->soind->stack, 1);
			br_dis_update(&(*st)->trr, (*st)->soind->stack);
			up_stadd(&(*st)->stadd, (*st)->soind->stack->data, eq);
		}
		(*i)++;
	} else if (KB_IKP(sfKeyUp) && (*i) != 1) {
		if ((*st)->soind != NULL) {
			move_stack(&(*st)->soind->stack, 0);
			br_dis_update(&(*st)->trr, (*st)->soind->stack);
			up_stadd(&(*st)->stadd, (*st)->soind->stack->data, eq);
		}
		(*i)++;
	}
}

void	event_move_in_inv(all **st, int *i, w_pt *eq)
{
	if (KB_IKP(sfKeyRight) && (*i) != 1) {
		if ((*st)->soind != NULL) {
			move_soind(&(*st)->soind, 1);
			br_dis_update(&(*st)->trr, (*st)->soind->stack);
			up_stadd(&(*st)->stadd, (*st)->soind->stack->data, eq);
		}
		(*i)++;
	} else if (KB_IKP(sfKeyLeft) && (*i) != 1) {
		if ((*st)->soind != NULL) {
			move_soind(&(*st)->soind, 0);
			br_dis_update(&(*st)->trr, (*st)->soind->stack);
			up_stadd(&(*st)->stadd, (*st)->soind->stack->data, eq);
		}
		(*i)++;
	}
	move_all_stack(st, i, eq);
}
