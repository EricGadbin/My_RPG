/*
** EPITECH PROJECT, 2018
** macro csfml
** File description:
** my rpg
*/

#include <SFML/Graphics/Color.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/System/InputStream.h>
#include <SFML/System/Time.h>
#include <SFML/System/Vector3.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Keyboard.h>

#ifndef MACRO_H_
#define MACRO_H_

//                all macro functions
#define	SP_DSP (sfRenderWindow_drawSprite)
#define	SP_STREC (sfSprite_setTextureRect)
#define SP_SCOL (sfSprite_setColor)
#define SP_SPOS (sfSprite_setPosition)
#define SP_GPOS (sfSprite_getPosition)
#define SP_SCALE (sfSprite_scale)
#define SP_DSSP (sfSprite_destroy)
#define SP_C (sfSprite_create)
#define SP_STX (sfSprite_setTexture)

#define TX_DSTX (sfTexture_destroy)
#define TX_CFF (sfTexture_createFromFile)

#define TXT_SCOL (sfText_setColor)
#define TXT_SSTR (sfText_setString)
#define TXT_DTXT (sfRenderWindow_drawText)
#define TXT_SPOS (sfText_setPosition)
#define TXT_SFONT (sfText_setFont)
#define TXT_SCSIZE (sfText_setCharacterSize)
#define TXT_C (sfText_create)
#define TXT_DSTXT (sfText_destroy)

#define KB_IKP (sfKeyboard_isKeyPressed)

#define RW_CLEAR (sfRenderWindow_clear)
#define RW_DRW (sfRenderWindow_display)
#define RW_DSRW (sfRenderWindow_destroy)
#define RW_CLOSE (sfRenderWindow_close)

#define MS_GPOSRW (sfMouse_getPositionRenderWindow)

#define MU_DSMU (sfMusic_destroy)

//	               all macro variable
#define	s2f sfVector2f
#define	s2i sfVector2i
#define sfRW sfRenderWindow
#define sfIR sfIntRect

#endif /* MACRO_H_ */