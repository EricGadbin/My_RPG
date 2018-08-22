/*
** EPITECH PROJECT, 2017
** libmy
** File description:
** header
*/

#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <math.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/System/InputStream.h>
#include <SFML/System/Time.h>
#include <SFML/System/Vector3.h>
#include <stddef.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Keyboard.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>
#include "my_rpg.h"
#include "macrocsfml.h"

#ifndef INVENTORY_H_
#define INVENTORY_H_

typedef struct pers_s pers_t;

typedef struct ob_s {
	sfSprite *sp_ob;
	sfTexture *tex_ob;
	sfVector2f pos_ob;
	sfIntRect ret_ob;
	sfClock *perso_clock;
	float basic;
} ob_t;

typedef struct text_print {
	sfText 		*t;
	sfFont 		*f;
	char 		*str;
	int 		lenght;
	sfVector2f 	pos;
} ts;

typedef struct square_dis_stat {
	ts *data;
	ts *value;
} dvalue_t;

typedef struct stats_s {
	float health;
	float strenght;
	float supp;
	float speed;
} stats_t;

typedef enum type_s
{
	WEAPON,
	CHESTPLATE,
	LEGSAMOR,
	ACCESSORY,
	KEY_ITEM,
} type;

typedef struct entity {
	type 			type;
	ob_t 			*ob;
	ob_t 			*s;
	char	 		*path;
	char 			*name;
	char 			*catg;
	int 			a_life;
	int			a_st;
	int			a_supp;
	int			a_speed;
} sob;

typedef struct equi_per {
		type catg;
		int ind;
		sob *ob;
		struct equi_per *next;
} w_pt;

typedef struct listv {
	struct listv 	*prev;
	sob 		*data;
	struct listv 	*next;
} stack;

typedef struct stock {
	struct stock 	*prev;
	stack		*stack;
	int 		nb;
	ts		*nbs;
	struct stock 	*next;
} stock;

typedef struct display_inv {
	float 		xbegin;
	float 		xend;
	float 		ybegin;
	float 		aug;
} b_dis;

struct  line_cat {
	type key;
	int (*my_func)(void);
};

struct  type_item {
	type key;
	char *(*my_func)(void);
};

struct	inter_to_type {
	int key;
	type (*my_func)(int);
};

typedef struct dis_stat {
	dvalue_t *life;
	dvalue_t *strength;
	dvalue_t *supp;
	dvalue_t *speed;
} disp_stat;

typedef struct display_re {
	sfVector2f 	obs;
	sfVector2f 	obsq;
	dvalue_t 	*nameob;
	dvalue_t	*typeob;
	dvalue_t	*ad_life;
	dvalue_t	*ad_st;
	dvalue_t	*ad_supp;
	dvalue_t	*ad_speed;
} br_dis;

typedef struct display_sta {
	sfVector2f 	obs;
	dvalue_t	*health;
	dvalue_t	*strength;
	dvalue_t	*supp;
	dvalue_t	*speed;
} br_dis_sta;

typedef struct display_sta_add {
	sfVector2f 	obs;
	ts		*add_h;
	ts		*add_st;
	ts		*add_supp;
	ts		*add_speed;
} dis_stadd;

typedef struct inventory {
	ob_t   *back;
	stock  *stock;
	stock  *lst;
	stock  *soind;
	b_dis *tr;
	br_dis *trr;
	br_dis_sta *tra;
	dis_stadd *stadd;
} all;

ts 	*sf_buildt(char *, char *, unsigned int, sfVector2f);
ob_t 	build(const char *, sfVector2f, sfIntRect, sfVector2f);
void	update_ts(ts **ind, char *str);
char 	*dsad(int nb);
ob_t 	*sf_build(const char *path, sfVector2f pos,
	sfIntRect rect, sfVector2f scale);

//--------------> lib
void 	my_printf(char *str, ...);
char 	*my_itoa(int nb);
int 	my_strcmp(char *cmp, char *ind);
char 	*my_strcpy(char *str);

//--------------> add object inventory
void 	add_new_ent_in_inv(sob *sub, all **st);
int 	add_stock(sob *sup, stock **st);
void 	add_stack(sob *sup, stack **stac);
stock 	*create_first_stock(sob *sup);
stack 	*create_first_stack(sob *sup);
b_dis 	*is_init_dis(void);

//-------------> lib for list
stock 	*verif_sub_exist(stock *stoc, sob *sup);
int 	my_stacklen(stack *stac);
all 	*init_all(stats_t *stats);

//-------------> find first and last list
stock 	*find_first_stock(stock *stoc);
stock 	*find_last_stock(stock *stoc);
stack 	*find_first_stack(stack *stac);
stack 	*find_last_stack(stack *stac);

//--------------> know the cathegory of an object
char 	*what_is_type(type type);
int 	is_find_category(type type);

//--------------> display_inv
void	p_list(sfRenderWindow *win, stock *stoc, stock *, b_dis *tr);
void	br_dis_first_time(br_dis **re, stack *ind);
void	br_dis_update(br_dis **re, stack *ind);
void 	is_dis_re(stock *soind, br_dis *dis_p, sfRenderWindow *win);

//--------------> move re of inventory list
void 	move_soind(stock **soind, int i);
void 	move_stack(stack **ind, int i);

//--------------> event in inventory
void	event_equip_in_inv(all **st, w_pt **, stats_t **, int *);
void	event_supr_in_inv(all **st, w_pt *eq, int *i);
void	event_move_in_inv(all **st, int *i, w_pt *eq);

//--------------> lib dvalue
void	update_dvalue(dvalue_t **re, char *newvalue, int opt);
dvalue_t *create_dvalue(char *, char *, sfVector2f, sfVector2f);
void 	display_dvalue(dvalue_t *node, sfRenderWindow *win);

//--------------> stats and equip
void	change_stats_aequip(sob *ob, stats_t **stats);
void	change_stats_mequip(sob *ob, stats_t **stats);
void	is_up_pers_stats(int ind, int add, stats_t *stats);
w_pt	*is_init_wpt(void);
void	equip_item(w_pt **eq, all *st, stats_t **stats);
void	dis_wpt(w_pt *eq, sfRenderWindow *win);
w_pt	*find_wpt_ind(w_pt *eq, all *st);
void 	is_dis_rae(br_dis_sta *dis_p, sfRenderWindow *win);
void	br_dis_rae_update(br_dis_sta **re, stats_t *stats);
void	up_stadd(dis_stadd **ind, sob *stoc, w_pt *eq);
void	is_dis_stadd(dis_stadd *ind, sfRenderWindow *win);
dis_stadd *init_dis_stadd(sob *st, w_pt *eq);
br_dis_sta *init_rea_dis(stats_t *stats);
br_dis *init_re_dis(void);
all 	*supr_node_in_inv(all *st);
void 	free_sob(sob *ind);
dvalue_t *cdvalue(char *data, char *value, sfVector2f datapos, sfVector2f);
void	update_sfvector_for_init(sfVector2f *tmp, sfVector2f *tmp2, float);
int	kw(sob *ob);
type	type_item_create(int nb);
sob	*my_sobcpy(sob *ref);
void 	free_obt(ob_t *ob);
void	change_perso_in_inv(pers_t **id, int *i);
void    is_up_health(stats_t *stats, int);
void    is_up_strenght(stats_t *stats, int);
void    is_up_supp(stats_t *stats, int);
void    is_up_speed(stats_t *stats, int);
void 	free_sob(sob *id);

#endif /* INVENTORY_H_ */
