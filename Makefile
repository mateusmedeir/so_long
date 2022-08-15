SRCS	= main.c screen.c image.c

OBJS	= $(SRCS:.c=.o)

CC	= cc
RM	= rm -f
FLAGS1	= -Wall -Wextra -Werror
FLAGS2	= -I ./mlx -L ./mlx -lmlx -framework OpenGl -framework Appkit
O	= -o
C	= -c

NAME	= so_long

all:		$(NAME)

.c.o:		$(SRCS)
		$(CC) $(FLAGS1) $(C) $< $(O) $(<:.c=.o)

$(NAME):	$(OBJS)
		$(CC) $(FLAGS1) $(FLAGS2) $(OBJS) $(O) $(NAME)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)
