##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile of my_sokoban
##

SRC	=   main.c	\
		src/basics_fonctions.c\
		src/basics_fonctions_two.c\
		src/case_errors.c\
		src/add_comment.c\
		src/remove_comments.c \
		src/my_getnbr.c \
		src/create_rooms.c \
		src/add_rooms.c \
		src/my_strncmp.c \
		src/link_rooms.c \
		src/my_int_counter.c \
		src/distance.c \
		src/trip.c \
		src/robots.c \

OBJ = ${SRC:.c=.o}
NAME = amazed

all: ${NAME}

${NAME}: ${OBJ}

		gcc -o amazed $(SRC) -g3

clean:
	rm ${OBJ}
fclean: clean
	rm ${NAME}
re: fclean all
