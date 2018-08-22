/*
** EPITECH PROJECT, 2017
** mu_radar.h
** File description:
** radar
*/

#ifndef _PROTOTYPE_H_
#define _PROTOTYPE_H_

#include "struct.h"
#include "lib.h"
#include "maze.h"

#define cmp (my_strcmp)

//EVENT
	void check_event_end(info_t *ginf);
	void my_usleep(float time1);
	void check_event_menu(info_t *game_info, menu_t *menu);
	int check_event_pause(info_t *game_info, menu_t *menu);
	void mouse_is_on_button(button_t *, sfVector2i, sfEvent);
	void mouse_is_on_button2(button_t *button, sfVector2i, sfEvent);
	void check_event(info_t *game_info, char **map);
	void check_event_battle(info_t *game_info);
	int check_event_quest(info_t *ginf);
	int check_event_attack(info_t *game_info, button_t *list, int);
	void check_event_village(info_t *game_info, int **map);
	int check_collision_house(info_t *info, int **map, sfVector2f move);
	void check_interaction_village(info_t *game_info);
	void check_event_intro(info_t *game_info);
	void check_event_none(info_t *ginf);

	void check_event_house(info_t *ginf, int **map);
	void move_player(info_t *game_info, sfVector2f move);
	void move_player_village(info_t *game_info, sfVector2f, sfVector2f);

	void check_key(info_t *game_info, sfEvent event, char **map);
	void check_key_left(info_t *game_info, sfEvent event, char **map);
	void check_key_right(info_t *game_info, sfEvent event, char **map);
	void check_key_up(info_t *game_info, sfEvent event, char **map);
	void check_key_down(info_t *game_info, sfEvent event, char **map);
	void check_interaction(info_t *game_info, char **map);

	void check_key_left_village(info_t *game_info, sfEvent, int **, s2f);
	void check_key_right_village(info_t *, sfEvent, int **, s2f);
	void check_key_up_village(info_t *game_info, sfEvent, int **, s2f);
	void check_key_down_village(info_t *game_info, sfEvent, int **, s2f);
	void check_key_village(info_t *game_info, sfEvent, int **, s2f);

	void check_key_left_house(info_t *game_info, sfEvent event, int **map);
	void check_key_right_house(info_t *game_info, sfEvent event, int **);
	void check_key_up_house(info_t *game_info, sfEvent event, int **map);
	void check_key_down_house(info_t *game_info, sfEvent event, int **map);
	void check_key_house(info_t *game_info, sfEvent event, int **map);

	void check_key_up_fight(button_t *list, sfEvent event);
	void check_key_down_fight(button_t *list, sfEvent event);
	int check_key_enter_fight(button_t *list, sfEvent event);

//INIT
	int init_game_info(info_t *game_info);
	void init_inventory(info_t *game_info);
	void init_village_settings(info_t *game_info);
	int **create_village_map(void);
	void init_menus(info_t *game_info);
	void select_tuto_menu(info_t *game_info);
	void init_settings_menu(info_t *game_info, menu_t *menu);
	void init_quit_menu(info_t *game_info, menu_t *menu);
	void init_start_menu(info_t *game_info, menu_t *menu);
	void init_scenes_game_info(info_t *game_info);
	void init_in_game_settings(info_t *game_info, menu_t *menu);
	void init_pause_menu(info_t *game_info, menu_t *menu);
	void create_button(button_t *, char *, sfVector2f, sfFont *);
	void create_button_pause(button_t *, char *, sfVector2f, sfFont *);
	void create_character(info_t *game_info);
	void create_monsters(info_t *game_info);
	void create_bosses(info_t *game_info);
	void create_base(info_t *game_info, pers_t *perso);
	void init_retry_menu(info_t *game_info, menu_t *menu);
//PTR SUR FONCTION
	void start_intro(info_t *game_info);
	void enter_village(info_t *game_info);
	void enter_house(info_t *game_info);
	void enter_maze(info_t *game_info);
	void select_settings_menu(info_t *game_info);
	void select_start_menu(info_t *game_info);
	void select_stat_menu(info_t *game_info);
	void select_pause_menu(info_t *game_info);
	void select_quit_menu(info_t *game_info);
	void select_in_game_settings(info_t *game_info);
	void select_retry_menu(info_t *game_info);
	void display_inventory_in_game(info_t *game_info);
	void quit_game(info_t *game_info);
	void resume_game(info_t *game_info);
//DISPLAY
	void cutscene(info_t *game_info);
	void print_stats(info_t *game_info, menu_t *menu);
	void print_menu(info_t *game_info, menu_t *menu, int index);
	void print_over(info_t *info, int **map);
	void select_quest_menu(info_t *game_info);
	void print_background(info_t *game_info, menu_t *menu);
	void print_quest(info_t *game_info, menu_t *menu);
	void add_fade_rain(framebuffer_t *buffer);
	void disp_particules(info_t *game_info, rain_t *rain);
	void print_pause_menu(info_t *game_info, menu_t *menu, int);
	void print_scene_pause(info_t *game_info, menu_t *menu);
	void display_maze(info_t *game_info, char **map);
	void display_inventory(sfRenderWindow *win, all **st, w_pt **, int *j);
	void display_inventory_2(sfRenderWindow *win, pers_t **pers, int *j);
	void print_chest(info_t *ginf, s2f pos, int j);
	void print_tuto(info_t *game_info, menu_t *menu, int i);
	void print_mob(info_t *ginf, s2f pos, int id);
	void print_door(info_t *ginf, s2f pos);
	void move_mob(info_t *ginf);
//END GAME
	void end_game(info_t *game_info);
	void destroy(info_t *game_info);
	void free_sprite_list(sprite_t *list);
	void free_array(int **tab);
	void free_array2(int **tab);
	void free_tab(char **tab);
	void destroy_rain(rain_t *rain);
	void free_perso(pers_t *perso);
	void free_buttons_fight(button_t *button);
//GAME
	int check_collision(info_t *game_info, char **map, sfVector2f, int);
	int check_collision_village(info_t *game_info, int **map, sfVector2f);
	void start_battle(info_t *game_info, mob_t *mob);
	void clock_perso(info_t *game_info);
	void rain_particule(info_t *game_info, rain_t *rain);
	void start_boss_fight(info_t *game_info);
	rain_t *init_rain(void);
	void move_mob(info_t *game_info);
	void disp_explosion(info_t *game_info, sfVector2i center);
	void my_put_pixe(framebuffer_t *, unsigned int, unsigned int, sfColor);
	void add_fade(framebuffer_t *buffer);
	void add_fade_dirt(framebuffer_t *buffer);
	int open_chest(info_t *game_info, int x, int y, sfVector2i in);
//BATTLE
	void display_players(info_t *game_info);
	void display_mobs(info_t *game_info, mob_t *mob);
	int check_health(pers_t *perso, mob_t *mob);
	void player_attack(pers_t *player, pers_t *perso, mob_t *mob, int);
	void monster_attack(mob_t *mob, pers_t *perso);
	void add_speed_monster(info_t *info, mob_t *mob);
	void add_speed_player(info_t *, button_t *, mob_t *, sprite_t *);
	mob_t *create_mob_list(info_t *game_info, int first, int nb);
	button_t *create_button_list(info_t *game_info);
	void move_spell3(info_t *game_info, int *finished, fight_t *info);
	void init_battle(info_t *game_info);
	void attack_loop(info_t *info, button_t *list, mob_t *mob, sprite_t *);
	sprite_t *init_combat_stats_sprites();
	void animate_main_bar(info_t *game_info, mob_t *, sfSprite *bar);
	void animate_life_bar(info_t *game_info, mob_t *mob, sfSprite *);
	void animate_speed_bar(info_t *game_info, mob_t *mob, sfSprite *);
	void animate_magic_bar(info_t *game_info, mob_t *mob, sfSprite *);
	void animating_attack(info_t *game_info, int, int *, fight_t *);
	void check_buttons(info_t *game_info, button_t *list);
	void manage_arrow(info_t *game_info, fight_t *, mob_t *, sfSprite *);
	void move_perso_in_fight(info_t *game_info);
	mob_t *mob_add(mob_t *mob, mob_t *list);
	void create_spell(info_t *game_info);
	void move_spell2(info_t *game_info, int *finished);
	void move_spell(info_t *game_info, int *finished);
	void move_boss1(info_t *ginf, mob_t *boss);
	void move_boss2(info_t *ginf, mob_t *boss);
	void move_boss3(info_t *ginf, mob_t *boss);
	void finish_battle(info_t *, mob_t *, sprite_t *, button_t *);
	void add_new_teamate(info_t *game_info);
	void fill_info_struct(info_t *game_info, button_t *list, fight_t *);
	int select_attack(info_t *game_info, fight_t *, mob_t *, pers_t *);
	void move_rect_spell3(ob_t *tmp, int *j, int *finished, fight_t *info);
	void move_rect_spell2(info_t *game_info, int *finished);
	void move_rect_spell(info_t *game_info, int *finished);
	void create_base_2(info_t *game_info, pers_t *perso);

//TOOLS
	int get_nb_perso(pers_t *perso);
	int get_nb_mob(mob_t *mob);

//TOOLS OB
	#define wranstp 21
	#define wranstm 11
	#define wransup 11
	#define wransum 21
	#define wranspp 16
	#define wranspm 26
	#define cranhp 21
	#define cranhm 11
	#define cransup 21
	#define cransum 21
	#define cranspp 11
	#define cranspm 21
	#define lranspp 21
	#define lranspm 11
	framebuffer_t *framebuffer_create(unsigned int width, unsigned int);
	sob	*create_sob(sp_info info, char *name, type typeob, int);
	int	create_stat(float basic, int brandp, int brandm);
	void	generate_weapon(int level, sob **new);
	void	generate_chestplate(int level, sob **new);
	void	generate_legsarmor(int level, sob **new);
	void	generate_accessory(int level, sob **new);
	float	create_born(float basic, int bornrand, int opt);
	sob	*generate_sob(int l, dt_t *dt);
	char	**my_realloc(char **tab);
	dt_t	collect_datasob(dt_t dt, int fd);
	dt_t	*init_all_data(void);
//PNJ
	void dialog_solo(info_t *, pers_t *, quest_t *, sfSprite *);
	void event_dialog_solo(pers_t *p, quest_t *q, int *i, int *n);
	void dialog_duo(info_t *game_info, dialog_t *, ob_t **, sfSprite *);
	dialog_t init_dialog(int ind, char *path, sfIR rect);
	void check_dialog(info_t *gf, int ind, sfSprite *sp);
	pnj_t init_first_pnj(char *name, char *app, char *face, sfIR rect[2]);
	char *my_strcat(char *first, char *second);
#endif
