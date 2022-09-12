SRCS	= game.c screen.c image.c keys.c map.c

SRCS_GNL	= libraries/gnl/get_next_line.c libraries/gnl/get_next_line_utils.c

OBJS		= $(SRCS:.c=.o)

CC		= cc
RM		= rm -f
FLAGS1		= -Wall -Wextra -Werror
FLAGS2		= -I ./libraries/mlx -L ./libraries/mlx -lmlx -L ./libraries/libft -lft -framework OpenGl -framework Appkit
O		= -o
C		= -c

NAME		= so_long

MLX		= libmlx.a

LIBFT		= libft.a

all:		$(MLX) $(LIBFT) $(NAME)

.c.o:		$(SRCS)
			$(CC) $(FLAGS1) $(C) $< $(O) $(<:.c=.o)

$(NAME):	$(OBJS)
			$(CC) $(FLAGS1) $(FLAGS2) $(OBJS) $(SRCS_GNL) -D BUFFER_SIZE=42 $(O) $(NAME)

$(MLX):
			@make -C libraries/mlx
$(LIBFT):
			@make -C libraries/libft

clean:
			$(RM) $(OBJS)
			@make clean -C libraries/libft

fclean:		clean
			$(RM) $(NAME)
			@make clean -C libraries/mlx
			@make fclean -C libraries/libft

re:			fclean all

valgrind:	re
			@valgrind --leak-check=full --suppressions=val.log ./$(NAME) maps/map.ber

.PHONY:		all clean fclean re valgrind
