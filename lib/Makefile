##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Basic Makfile
##

SRC	=	printf.c	\
		printf_fonction.c	\
		get_next_line.c	\
		my_getnbr.c	\
		my_strlen.c	\
		clear_tab.c	\
		my_strcat.c	\
		str_to_tab.c	\
		search_char_in_array.c	\
		my_tablen.c \

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

CFLAGS	=	-Wall -Wextra -W -I../include/

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: 	fclean all
