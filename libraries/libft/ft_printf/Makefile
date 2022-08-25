SRCS		= ft_printf.c ft_conversions.c ft_prints_pt1.c ft_prints_pt2.c

OBJS		= $(SRCS:.c=.o)

NAME		= libftprintf.a

AR			= ar rc
CC			= cc
FLAGS		= -Wall -Wextra -Werror -c
RM			= rm -f
O			= -o

all:		$(NAME)

.c.o:		$(SRCS)
			$(CC) $(FLAGS) $< $(O) $(<:.c=.o)

$(NAME):	${OBJS}
			$(AR) $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re

