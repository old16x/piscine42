#!/bin/sh
cc -Wall -Wextra -Werror -g -O -c ft_putchar.c -o ft_putchar.o
cc -Wall -Wextra -Werror -g -O -c ft_swap.c -o ft_swap.o
cc -Wall -Wextra -Werror -g -O -c ft_putstr.c -o ft_putstr.o
cc -Wall -Wextra -Werror -g -O -c ft_strlen.c -o ft_strlen.o
cc -Wall -Wextra -Werror -g -O -c ft_strcmp.c -o ft_strcmp.o
ar rc libft.a ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o
ranlib libft.a
rm -rf ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o
