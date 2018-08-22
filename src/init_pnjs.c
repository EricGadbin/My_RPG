/*
** EPITECH PROJECT, 2018
** init pnj
** File description:
** project my_rpg
*/

#include "../include/prototype.h"
#include "struct.h"
#include "macrocsfml.h"

dialog_t init_dialog(int ind, char *path, sfIR rect)
{
	dialog_t dialog;

	dialog.keyd = ind;
	dialog.ind = 0;
	dialog.rectend = rect.left;
	dialog.st = (rect.top == 1) ? my_strcpy("duo") : my_strcpy("solo");
	rect.top = 0;
	rect.left = 0;
	dialog.dl = build(path, (s2f){0, 0}, rect, (s2f){1, 1});
	return (dialog);
}

pnj_t init_first_pnj(char *app, char *face1, char *face2, sfIR rect[4])
{
	pnj_t pnj;

	pnj.id.tmpname = my_strcpy("Elynda");
	pnj.app = build(app, (s2f){0, 0}, rect[0], (s2f){1.75, 1.75});
	pnj.face[0] = build(face1, (s2f){0, 0}, rect[1], (s2f){2, 2});
	pnj.face[1] = build(face2, (s2f){0, 0}, rect[2], (s2f){2, 2});
	pnj.dialog = init_dialog(0, "assets/dialog/Elynda-diat1.png", rect[3]);
	return (pnj);
}
