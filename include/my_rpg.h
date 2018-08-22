/*
** EPITECH PROJECT, 2018
** Project my_rpg
** File description:
** Header file
*/

#ifndef MAIN_H_
	#define MAIN_H_
	#include <stdlib.h>
	#include <stdio.h>
	#include "inventory.h"

typedef struct Identity_s {
	sfText *name;
	char *tmpname;
	char *race;
	char *genre;
	char *char_traits;
	char **history;
} Identity_t;

typedef struct quest_s {
	int qind;
	int boss1;
	int boss2;
	int boss3;
} quest_t;

typedef struct dialogue_s {
	int keyd;
	int ind;
	char *st;
	ob_t dl;
	ts *pnj;
	ts *perso;
	int rectend;
} dialog_t;

typedef struct animation_s {
	char *name;
	ob_t *app;
} animation_t;

typedef struct sprite_s {
	sfSprite *sprite;
	struct sprite_s *next;
} sprite_t;

typedef struct pers_s {
	Identity_t *ident;
	ob_t *app;
	ob_t face[2];
	all *persinv;
	w_pt *eq;
	sfVector2f pos_fight;
	stats_t *stats;
	float health;
	float speed;
	int level;
	int exp;
	dialog_t *dl;
	int idd;
	struct pers_s *next;
	struct pers_s *prev;
} pers_t;

typedef struct mob_s {
	sfText *name;
	char *description;
	int id;
	ob_t *app;
	animation_t **spels;
	stats_t *stats;
	float health;
	float speed;
	struct mob_s *next;
	struct mob_s *prev;
} mob_t;

typedef struct pnj_s {
	Identity_t id;
	int ind;
	int idd;
	ob_t app;
	ob_t face[2];
	dialog_t dialog;
} pnj_t;

#endif
