/*
** EPITECH PROJECT, 2018
** sfbuildsf
** File description:
** rpg project
*/

#include "macrocsfml.h"
#include "inventory.h"

ts 	*sf_buildt(char *str, char *font, unsigned int lenght, s2f pos)
{
	ts *res = malloc(sizeof(ts));

	if (!res)
		return (NULL);
	res->str = my_strcpy(str);
	res->t = TXT_C();
	res->f = sfFont_createFromFile(font);
	res->pos = pos;
	TXT_SSTR(res->t, str);
	TXT_SFONT(res->t, res->f);
	TXT_SCSIZE(res->t, lenght);
	TXT_SPOS(res->t, pos);
	return (res);
}

void 	free_obt(ob_t *ob)
{
	SP_DSSP(ob->sp_ob);
	TX_DSTX(ob->tex_ob);
	free(ob);
}

void	update_ts(ts **ind, char *str)
{
	(*ind)->str = my_strcpy(str);
	TXT_SSTR((*ind)->t, str);
}

ob_t 	*sf_build(const char *path, s2f pos, sfIntRect rect, s2f scale)
{
	ob_t *ob = malloc(sizeof(ob_t));

	if (!ob)
		return (NULL);
	ob->sp_ob = SP_C();
	ob->tex_ob = TX_CFF(path, NULL);
	SP_STX(ob->sp_ob, ob->tex_ob, sfTrue);
	ob->pos_ob.x = pos.x;
	ob->pos_ob.y = pos.y;
	ob->ret_ob = rect;
	ob->perso_clock = sfClock_create();
	SP_SCALE(ob->sp_ob, scale);
	SP_SPOS(ob->sp_ob, ob->pos_ob);
	SP_STREC(ob->sp_ob, ob->ret_ob);
	return (ob);
}

ob_t	build(const char *path, s2f pos, sfIntRect rect, s2f scale)
{
	ob_t ob;

	ob.sp_ob = SP_C();
	ob.tex_ob = TX_CFF(path, NULL);
	SP_STX(ob.sp_ob, ob.tex_ob, sfTrue);
	ob.pos_ob.x = pos.x;
	ob.pos_ob.y = pos.y;
	ob.ret_ob = rect;
	ob.perso_clock = sfClock_create();
	SP_SCALE(ob.sp_ob, scale);
	SP_SPOS(ob.sp_ob, ob.pos_ob);
	SP_STREC(ob.sp_ob, ob.ret_ob);
	return (ob);
}
