NAME		= so_long

SRCS		= game.c  \
			  close.c \
			  image.c \
			  keys.c  \
			  map1.c  \
			  map2.c

SRCS_GNL	= $(LIBS_PATH)/gnl/get_next_line.c $(LIBS_PATH)/gnl/get_next_line_utils.c

OBJS		= $(SRCS:.c=.o)

MLX			= $(MLX_PATH)/libmlx.a
LIBFT		= $(LIBFT_PATH)/libft.a

LIBS_PATH	= libs
LIBFT_PATH	= $(LIBS_PATH)/libft
MLX_PATH	= $(LIBS_PATH)/mlx-linux

CC			= cc
RM			= rm
FLAGS		= -Wall -Wextra -Werror
LIBS		= -I $(MLX_PATH) -L $(MLX_PATH) -lmlx_linux -L $(LIBFT_PATH) -lft
E_LIBS		= -lXext -lX11 -lm -lz

all:		$(NAME)

.c.o:
			$(CC) $(FLAGS) $(LIBS) $(E_LIBS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS) $(MLX) $(LIBFT)
			$(CC) $(FLAGS) $(OBJS) -o $(NAME)

$(MLX):
			@make -C $(MLX_PATH)
$(LIBFT):
			@make -C $(LIBFT_PATH)

clean:
			$(RM) -f $(OBJS)
			@make clean -C $(MLX_PATH)
			@make clean -C $(LIBFT_PATH)

fclean:		clean
			$(RM) -f $(NAME)
			$(RM) -f $(LIBFT_PATH)/libft.a

re:			fclean all

.PHONY:		all clean fclean re
