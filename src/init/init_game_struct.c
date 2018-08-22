/*
** EPITECH PROJECT, 2018
** init_game_struct.c
** File description:
** rpg
*/

#include "prototype.h"

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
	sfUint8 *pixels = malloc(sizeof(sfUint8) * (width * height * 4));
	framebuffer_t *buffer = malloc(sizeof(framebuffer_t));
	unsigned int i = 0;

	while (i != width * height * 4) {
		pixels[i] = 0;
		i++;
	}
	buffer->width = width;
	buffer->height = height;
	buffer->pixels = pixels;
	buffer->texture = sfTexture_create(width, height);
	buffer->sprite = sfSprite_create();
	return (buffer);
}

void fill_game_struct(info_t *game_info)
{
	game_info->move_perso = 0;
	game_info->width = 1600;
	game_info->height = 900;
	game_info->menu = NULL;
	game_info->pause = 0;
	game_info->boss_fight = 0;
	game_info->house_map = NULL;
	game_info->village_map = NULL;
	game_info->maze = NULL;
	game_info->map.x = 0;
	game_info->map.y = 0;
	game_info->clock = sfClock_create();
	game_info->clock2 = sfClock_create();
	game_info->clock3 = sfClock_create();
	game_info->clock4 = sfClock_create();
}

int **create_house_map(void)
{
	int **house_map = malloc(sizeof(int *) * 26);
	int fd = open("assets/house_map", O_RDONLY);
	char *tmp = NULL;
	char **tmp2 = NULL;

	for (int i = 0; house_map && i != 26; i++) {
		house_map[i] = malloc(sizeof(int) * 37);
		if (!house_map[i])
			return (NULL);
		tmp = get_next_line(fd);
		tmp2 = str_to_tab(tmp, ",", 1);
		for (int j = 0; j != 37; j++)
			house_map[i][j] = my_getnbr(tmp2[j]);
		free(tmp);
		clear_tab(tmp2);
	}
	return (house_map);
}

int init_game_info2(info_t *game_info)
{
	game_info->font = sfFont_createFromFile("assets/Timepiece.otf");
	sfSprite_setColor(game_info->shader->sp_ob,
	(sfColor){255, 255, 255, 160});
	game_info->window = sfRenderWindow_create((sfVideoMode){
	game_info->width, game_info->height, 32}, "Lost Times",
	sfResize | sfClose, NULL);
	game_info->house_map = create_house_map();
	game_info->rain = init_rain();
	game_info->boss_nb = 0;
	if (!game_info->window || !game_info->font)
		return (84);
	return (0);
}

int init_game_info(info_t *game_info)
{
	init_scenes_game_info(game_info);
	game_info->buffer = framebuffer_create(300, 300);
	game_info->buffer2 = framebuffer_create(8320, 900);
	fill_game_struct(game_info);
	game_info->battle_theme =
	sfMusic_createFromFile("./assets/battle_theme.ogg");
	game_info->village_song =
	sfMusic_createFromFile("./assets/village_song.ogg");
	game_info->intro_song = sfMusic_createFromFile
	("./assets/intro/intro_song.ogg");
	game_info->house_theme = sfMusic_createFromFile("./assets/Home.ogg");
	game_info->door_song = sfMusic_createFromFile("./assets/door.ogg");
	game_info->menu_song = sfMusic_createFromFile("./assets/Menu.ogg");
	game_info->dungeon = sfMusic_createFromFile("./assets/dungeon.ogg");
	return (init_game_info2(game_info));
}
