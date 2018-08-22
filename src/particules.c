/*
** EPITECH PROJECT, 2018
** particules.c
** File description:
** rpg
*/

#include "prototype.h"

void draw_line(framebuffer_t *frambuffer, sfVector2i pt_a, sfVector2i pt_b)
{
	double y = 0;
	double x = pt_a.x;
	double i1 = pt_a.y - pt_b.y == 0 ? 1 : pt_a.y - pt_b.y;
	double i2 = pt_a.x - pt_b.x == 0 ? 1 : pt_a.x - pt_b.x;
	double a = i1 / i2;
	double b = pt_a.y - pt_a.x * a;

	while (x != pt_b.x) {
		y = a * x + b;
		my_put_pixe(frambuffer, x, y, (sfColor){0, 0, 0, 0});
		pt_a.x > pt_b.x? x-- : x++;
	}
	x = pt_a.x;
	y = pt_a.y;
	while (y != pt_b.y) {
		x = (y - b) / a;
		my_put_pixe(frambuffer, x, y, (sfColor){0, 0, 0, 0});
		pt_a.y > pt_b.y ? y-- : y++;
	}
}

void check_pos(framebuffer_t *b, sfVector2f pos, sfVector2i c, int rad)
{
	if ((pow(pos.x - c.x, 2) + pow(pos.y - c.y, 2))
	== pow(rad, 2)){
		my_put_pixe(b, pos.x, pos.y, (sfColor){255, 215, 0, 255});
	}

}

void draw_circle2(framebuffer_t *b, sfVector2i center, int radius)
{
	double x = center.x - radius;
	double y = center.y + radius;

	while (y > center.y - radius) {
		while (x < center.x + radius) {
			check_pos(b, (sfVector2f){x, y}, center, radius);
			x++;
		}
		x = center.x - radius;
		y--;
	}
}

void disp_explosion(info_t *gnf, sfVector2i center)
{
	static int radius = 0;
	sfVector2i point_a = {center.x - 90, center.y + 1};
	sfVector2i point_b = {center.x + 1, center.y + 1};
	sfVector2i point_a2 = {center.x + 1, center.y + 90};

	if (radius < 90) {
		draw_circle2(gnf->buffer, center, radius);
		radius++;
		draw_circle2(gnf->buffer, center, radius);
		radius++;
	} else
		radius = 0;
	add_fade(gnf->buffer);
	draw_line(gnf->buffer, point_a, point_b);
	draw_line(gnf->buffer, point_a2, point_b);
	sfTexture_updateFromPixels(gnf->buffer->texture,
	gnf->buffer->pixels, 300, 300, 0, 0);
	SP_STX(gnf->buffer->sprite, gnf->buffer->texture, sfTrue);
	SP_DSP(gnf->window, gnf->buffer->sprite, NULL);
}
