# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/26 15:39:25 by plepercq          #+#    #+#              #
#    Updated: 2026/02/27 15:38:33 by plepercq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= push_swap

CC	= cc
CFLAGS	= -Wall -Werror -Wextra

CFILES 	= push_swap.c ft_split.c

OBJECTS	= $(patsubst %.c, %.o, $(CFILES))

all: $(NAME)

clean:
	rm -rf $(OBJECTS)

fclean:
	rm -rf $(NAME) $(OBJECTS)

re: fclean all

bonus: $(BONUS_OBJECTS)
	ar -rcs $@ $^

test: $(CFILES)
	$(CC) $(CFLAGS) -g $(CFILES) main.c
	./a.out

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

.PHONY: all clean fclean re


