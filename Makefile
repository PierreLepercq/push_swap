# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/26 15:39:25 by plepercq          #+#    #+#              #
#    Updated: 2026/03/13 19:52:37 by plepercq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= push_swap

CC		= cc
CFLAGS	= -Wall -Werror -Wextra

LIBS	= libft coucou
ARCHS	= $(patsubst %, %.a, $(LIBS))

CFILES 	= push_swap.c
OBJECTS	= $(CFILES:.c=.o)

RESULT	:= $(subst /, ,$(LIBS))
LIB_PATH:= $(word 1, $(RESULT))
ARCHIVE	:= $(word 2, $(RESULT))




$(NAME): $(OBJECTS)

all: $(NAME)

clean:
	rm -rf $(OBJECTS)
	make -C $(LIBS) clean

fclean:
	rm -rf $(NAME) $(OBJECTS)
	make -C $(LIBS) fclean

re: fclean all

test: $(LIBS)
	echo $(LIBS)
	echo $(ARCHS)

test2: $(CFILES) $(ARCHS)
	$(CC) $(CFLAGS) $(CFILES) -L./libft -llibft.a
	$(CC) $(CFLAGS) -I $(ARCHS) $(CFILES)
	./a.out 56 42 27 -51 -7 12 24 -16 35 0

%.o: %.c
	$(CC) $(CFLAGS) -I $(LIBS) -c $^ -o $@

%.a:
	touch test_$@

.PHONY: all clean fclean re