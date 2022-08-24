SRCS	= main.c screen.c image.c keys.c map.c

SRCS_GNL	= gnl/get_next_line.c gnl/get_next_line_utils.c

OBJS		= $(SRCS:.c=.o)

CC		= cc
RM		= rm -f
FLAGS1		= -Wall -Wextra -Werror
FLAGS2		= -I ./mlx -L ./mlx -lmlx -L ./libft -lft -framework OpenGl -framework Appkit
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
			@make -C mlx
$(LIBFT):
			@make -C libft

clean:
			$(RM) $(OBJS)
			@make clean -C libft

fclean:		clean
			$(RM) $(NAME)
			@make clean -C mlx
			@$(RM) libft/$(LIBFT)

re:			fclean all
