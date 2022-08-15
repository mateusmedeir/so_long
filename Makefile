SRCS	= main.c

CC	= cc
FLAGS	= -I ./resources -L ./resources -lmlx -framework OpenGl -framework Appkit
O	= -o

NAME	= so_long

all:		$(NAME)

$(NAME):
		${CC} ${FLAGS} ${SRCS} ${O} $(NAME)
