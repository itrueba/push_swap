NAME			= push_swap

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -rf

SRCS			= push_swap.c ft_isdigit.c

OBJS			= $(SRCS:.c=.o)

all:	$(NAME)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
			$(CC) -o $@ $^

clean:
		$(RM) $(OBJS) $(BONUS_OBJS)

fclean:	clean
		$(RM) $(NAME)

re:		fclean $(NAME)

.PHONY:	all clean fclean re bonus