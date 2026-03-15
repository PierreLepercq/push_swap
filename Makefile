# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/26 15:39:25 by plepercq          #+#    #+#              #
#    Updated: 2026/03/15 01:54:42 by plepercq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= push_swap

CC		= cc
CFLAGS	= -Wall -Werror -Wextra

LIBS	= libft
ARCHIVES = $(foreach lib, $(LIBS), ./$(lib)/$(lib).a)

CFILES 	= push_swap.c
OBJECTS	= $(CFILES:.c=.o)

$(NAME): $(OBJECTS)

all: $(NAME)

clean:
	rm -rf $(OBJECTS)
	$(foreach lib, $(LIBS), $(MAKE) -C ./$(lib) clean;)

fclean:
	rm -rf $(NAME) $(OBJECTS)
	$(foreach lib, $(LIBS), $(MAKE) -C ./$(lib) fclean;)

re: fclean all

test:
	echo "JE SUIS ICI"
	echo $(ARCHIVES)

test2: $(CFILES) $(ARC11HS)
	$(CC) $(CFLAGS) $(CFILES) -L./libft -llibft.a
	$(CC) $(CFLAGS) -I $(ARCHS) $(CFILES)
	./a.out 56 42 27 -51 -7 12 24 -16 35 0
	$(CC) $(CFLAGS) $(CFILES) $(LIBS_PATH) $(ARCHIVES)

%.o: %.c
	$(CC) $(CFLAGS) -I $(LIBS) -c $^ -o $@

./%/%.a:
	make -C $* all

.PHONY: all clean fclean re