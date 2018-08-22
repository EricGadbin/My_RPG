##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c								\
		src/inventory/src/inventory.c 						\
		src/inventory/src/features_inv/find_first_and_last_stock_or_stack.c 	\
		src/inventory/src/lib_for_list.c 					\
		src/inventory/src/lib_wpt_equip.c 					\
		src/inventory/src/lib/my_dsad.c 					\
		src/inventory/src/equip_item.c 						\
		src/inventory/src/my_sobcpy.c 						\
		src/inventory/src/sfbuilsf.c 						\
		src/inventory/src/change_perso_in_inv.c 				\
		src/inventory/src/inventory_event.c 					\
		src/inventory/src/features_inv/add_object_in_inventory.c 		\
		src/inventory/src/features_inv/create_first_stack_stock.c 		\
		src/inventory/src/lib/my_strcmp.c 					\
		src/inventory/src/lib/my_itoa.c 					\
		src/inventory/src/lib/my_strcpy.c 					\
		src/inventory/src/know_type_objects_inventory/now_type.c	 	\
		src/inventory/src/know_type_objects_inventory/function_1_now_type.c	\
		src/inventory/src/know_type_objects_inventory/function_2_now_type.c	\
		src/inventory/src/know_type_objects_inventory/function_3_now_type.c	\
		src/inventory/src/features_inv/supress_sob_inv.c			\
		src/inventory/src/display_inv/display_inv.c				\
		src/inventory/src/move_in_inv/move_in_inv.c				\
		src/inventory/src/display_r/disp_dis_r.c  				\
		src/inventory/src/display_r/init_dis_r.c				\
		src/inventory/src/display_r/init_disadd.c				\
		src/inventory/src/lib_dvalue.c						\
		src/inventory/src/display_r/update_dis_r.c				\
		src/inventory/src/change_stats_with_equips.c  				\
		src/inventory/src/up_pers_stats.c  					\
		src/inventory/src/function_up_pers_stats.c  				\
		src/init/init_start_menu.c						\
		src/init/init_village.c							\
		src/init/init_pause_menu.c						\
		src/init/init_settings_menu.c						\
		src/init/init_in_game_settings.c					\
		src/init/init_restart_menu.c						\
		src/init/init_quit_menu.c						\
		src/init/init_game_struct.c						\
		src/init/init_game_struct_scenes.c					\
		src/init/create_buttons.c						\
		src/init/init_character.c						\
		src/init/init_monsters.c						\
		src/init/init_bosses.c							\
		src/init/init_spell.c							\
		src/init/init_menus.c							\
		src/menu/select_menu.c							\
		src/menu/display_menu.c							\
		src/menu/select_menu2.c							\
		src/menu/display_quest.c						\
		src/menu/display_tuto.c							\
		src/menu/collision.c							\
		src/menu/display_stats.c						\
		src/menu/display_pause.c						\
		src/create_maze/maze.c							\
		src/create_maze/maze_func.c						\
		src/create_maze/door.c							\
		src/create_maze/list.c							\
		src/create_maze/converte_maze.c						\
		src/create_maze/add_spawn.c						\
		src/fight/fight.c							\
		src/fight/move_spells.c							\
		src/fight/animate_bar.c							\
		src/fight/move_perso.c							\
		src/fight/animate_life_bar.c						\
		src/fight/animate_speed_bar.c						\
		src/fight/buttons.c							\
		src/fight/init_battle.c							\
		src/fight/print_buttons.c						\
		src/fight/fight_event.c							\
		src/fight/check_keys_fight.c						\
		src/fight/add_speed.c							\
		src/fight/player_attack.c						\
		src/fight/monster_attack.c						\
		src/fight/animating_attack.c						\
		src/fight/selection.c							\
		src/fight/move_boss.c							\
		src/fight/end_fight.c							\
		src/fight/move_spell_rect.c						\
		src/fight/check_health.c						\
		src/fight/create_mob_list.c						\
		src/fight/display_mob_and_players.c					\
		src/tools/get_nb_perso.c						\
		src/tools/function_ptr.c						\
		src/play_maze/interaction.c						\
		src/play_village/interaction.c						\
		src/play_maze/check_keys_maze.c						\
		src/play_maze/start_boss_fight.c					\
		src/play_maze/collision_maze.c						\
		src/play_maze/display_maze.c						\
		src/play_maze/print_add.c						\
		src/play_maze/animate_chest.c						\
		src/play_village/check_keys_village.c					\
		src/play_village/check_keys_house.c					\
		src/play_village/enter_village.c					\
		src/play_village/collision_village.c					\
		src/play_village/collision_house.c					\
		src/play_village/start_game.c						\
		src/play_village/intro.c						\
		src/play_village/print_over.c						\
		src/end/destroy.c							\
		src/end/free.c								\
		src/end/free_character.c						\
		src/event.c								\
		src/event_intro.c							\
		src/event_move_perso.c							\
		src/particules.c							\
		src/move_player.c							\
		src/function_create_stats_sob.c						\
		src/particules2.c							\
		src/create_sob.c							\
		src/database.c								\
		src/init_pnjs.c								\
		src/dialog_solo.c							\
		src/dialog_duo.c							\
		src/end_game.c								\
		src/play_village/cutscene.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -I./include/ -I./src/inventory/include

MAKELIB =	make -C lib/

NAME	=	my_rpg

all: 	$(NAME)

$(NAME):	$(OBJ)
	$(MAKELIB)
	gcc -o $(NAME) $(OBJ) -lm $(CFLAGS) -lc_graph_prog -L. lib/libmy.a

clean:
	$(MAKELIB) clean
	rm -f $(OBJ)

fclean:		clean
	$(MAKELIB) fclean
	rm -f $(NAME)

re:	fclean all


my_re:	fclean $(OBJ)
	$(MAKELIB)
	gcc -o $(NAME) $(OBJ) -lm $(CFLAGS) -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window -L. lib/libmy.a

my:	$(OBJ)
	gcc -o $(NAME) $(OBJ) -lm $(CFLAGS) -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window -L. lib/libmy.a
