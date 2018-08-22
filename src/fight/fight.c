/*
** EPITECH PROJECT, 2018
** fight.c
** File description:
** rpg
*/

#include "prototype.h"
#include "macrocsfml.h"

void display_scene(info_t *game_info,
button_t *list, mob_t *mob, sprite_t *bar)
{
	sfRenderWindow_clear(game_info->window, sfBlue);
	move_mob(game_info);
	move_perso_in_fight(game_info);
	sfRenderWindow_drawSprite(game_info->window, game_info->fight->sp_ob,
	NULL);
	display_mobs(game_info, mob);
	display_players(game_info);
	check_buttons(game_info, list);
	animate_main_bar(game_info, mob, bar->sprite);
	animate_life_bar(game_info, mob, bar->next->sprite);
	animate_speed_bar(game_info, mob, bar->next->next->sprite);
}

sfSprite *create_arrow_sprite(void)
{
	sfSprite *arrow = sfSprite_create();

	sfSprite_setTexture(arrow,
	sfTexture_createFromFile("assets/arrow2.png", NULL), sfFalse);
	sfSprite_setScale(arrow, (sfVector2f){2, 2});
	return (arrow);
}

void update_info(info_t *game_info, button_t *list, fight_t *info)
{
	info->action = check_event_attack(game_info, list, info->select);
	if (info->action != 0 && info->select == 0)
		info->select = info->action;
}

void attack_loop(info_t *ginf, button_t *list, mob_t *mob, sprite_t *bar)
{
	fight_t info = {0, 0, 0, 0, 0, 540, 1100, NULL};
	int attack = 0;
	sfSprite *arrow = create_arrow_sprite();

	fill_info_struct(ginf, list, &info);
	while (sfRenderWindow_isOpen(ginf->window) && info.finished == 0) {
		update_info(ginf, list, &info);
		info.target = (info.select == 1 || attack == 1) ?
		(540 - info.pos1) / 120 : (info.pos2 - 1100) / 80;
		if (attack == 0)
			attack = select_attack(ginf, &info, mob,
			info.perso);
		display_scene(ginf, list, mob, bar);
		manage_arrow(ginf, &info, mob, arrow);
		animating_attack(ginf, attack, &info.finished, &info);
		sfRenderWindow_display(ginf->window);
	}
	sfSprite_destroy(arrow);
	for (;list ; list = list->next)
		list->state = 0;
}

void start_battle(info_t *game_info, mob_t *mob)
{
	sfClock *battle_clock = sfClock_create();
	sfTime time;
	float seconds;
	sprite_t *bar = init_combat_stats_sprites();
	button_t *list = create_button_list(game_info);

	init_battle(game_info);
	while (sfRenderWindow_isOpen(game_info->window) &&
		check_health(game_info->perso, mob) == 0) {
		display_scene(game_info, list, mob, bar);
		check_event_battle(game_info);
		time = sfClock_getElapsedTime(battle_clock);
		seconds = time.microseconds / 1000000.0;
		if (seconds > 0.01) {
			add_speed_player(game_info, list, mob, bar);
			sfClock_restart(battle_clock);
		}
		sfRenderWindow_display(game_info->window);
	}
	finish_battle(game_info, mob, bar, list);
}
