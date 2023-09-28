NAME		=	libft.a
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

SRCS		=	srcs/ft_putchar.c \
				srcs/ft_swap.c \
				srcs/ft_putstr.c \
				srcs/ft_strlen.c \
				srcs/ft_strcmp.c \

OBJS		=	$(SRCS:.c=.o)

HEADERS		=	includes

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(HEADERS) -c -o $@ $<

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
