/*
** EPITECH PROJECT, 2018
** particules2.c
** File description:
** rpg
*/

#include "prototype.h"

void my_put_pixe(framebuffer_t *b, unsigned int x, unsigned int y, sfColor c)
{
	unsigned int pos = (b->width * y + x) * 4;

	if (pos > b->width * b->height * 4)
		return;
	b->pixels[pos] = c.r;
	b->pixels[pos + 1] = c.g;
	b->pixels[pos + 2] = c.b;
	b->pixels[pos + 3] = c.a;
}

void add_fade(framebuffer_t *buffer)
{
	for (unsigned int i = 3; i < buffer->width *
	buffer->height * 4; i += 4) {
		if (buffer->pixels[i] > 10)
			buffer->pixels[i] -= 10;
		else
			buffer->pixels[i] = 0;
	}
}
