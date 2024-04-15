#!/bin/sh

gcc -Wall -Wextra -Werror -c *.c 
ar rc libft.a ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o
rm -rf *.o