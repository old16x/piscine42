NAME	=	do-op

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

SRCS	=	main.c \
			operators.c \
			ft_atoi.c \
			ft_putnbr.c \
			ft_putstr.c \

OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

/%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
