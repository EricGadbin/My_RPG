/*
** EPITECH PROJECT, 2017
** mu_radar.h
** File description:
** radar
*/

#ifndef _STRUCT_H_
#define _STRUCT_H_

#include <stdio.h>
#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include "my_rpg.h"

typedef struct button_s {
	int index;
	sfSprite *idle;
	sfSprite *hover;
	sfSprite *clicked;
	void (*callback)();
	sfText *text;
	int state;
	sfVector2f pos;
	struct button_s *next;
}button_t;

typedef struct menu_s {
	sfSprite *logo;
	sfSprite *back;
	struct button_s *button;
	struct menu_s *next;
}menu_t;

typedef struct database_name_sob {
	int lvs[2][2];
	char **ns;
	char **psp;
} dt_t;

typedef struct rain_s {
	unsigned int x;
	unsigned int y;
	unsigned int stop;
	int speed;
	struct rain_s *next;
} rain_t;

typedef struct fight_s {
	int id;
	int finished;
	int action;
	int select;
	int target;
	int pos1;
	int pos2;
	pers_t *perso;
} fight_t;

struct framebuffer {
	sfTexture *texture;
	sfSprite *sprite;
	unsigned int width;
	unsigned int height;
	sfUint8	*pixels;
};
typedef struct framebuffer framebuffer_t;

typedef struct info_s {
	sfRenderWindow *window;
	int height;
	int width;
	char **maze;
	int **village_map;
	int **house_map;
	int scene;
	sfMusic *menu_song;
	sfMusic *house_theme;
	sfMusic *dungeon;
	sfMusic *village_song;
	sfMusic *battle_theme;
	sfMusic *door_song;
	sfMusic *intro_song;
	sfFont *font;
	sfClock *clock;
	sfClock *clock2;
	sfClock *clock3;
	sfClock *clock4;
	sfVector2f map;
	int pause;
	int boss_fight;
	int colide;
	int boss_nb;
	int move_perso;
	struct menu_s *menu;
	struct mob_s *mob;
	struct mob_s *boss;
	struct pers_s *perso;
	struct ob_s *spell[7];
	struct ob_s *wall;
	struct ob_s *floor;
	struct ob_s *village;
	struct ob_s *house;
	struct ob_s *fight;
	struct ob_s *tree;
	struct ob_s *chimney;
	struct ob_s *shader;
	struct ob_s *cursor;
	struct ob_s *chest;
	struct ob_s *intro_back;
	struct ob_s *introd1;
	rain_t *rain;
	dt_t *dt;
	framebuffer_t *buffer;
	framebuffer_t *buffer2;
	struct ob_s *door;
	quest_t quest;
	pnj_t *pnj;
} info_t;

typedef struct info_create {
	char *path;
	sfVector2f pos;
	sfIntRect rect;
	sfVector2f scale;
} sp_info;

typedef struct create_sob {
	type typeob;
	void (*my_func)(int , sob**);
} csob_t;

#endif
