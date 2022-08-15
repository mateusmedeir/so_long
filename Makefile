SRCS	= main.c window.c

CC	= cc
FLAGS	= -I ./mlx -L ./mlx -lmlx -framework OpenGl -framework Appkit
O	= -o

NAME	= so_long

all:		$(NAME)

$(NAME):
		${CC} ${FLAGS} ${SRCS} ${O} $(NAME)
