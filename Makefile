# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/26 15:39:25 by plepercq          #+#    #+#              #
#    Updated: 2026/03/23 15:50:18 by plepercq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= push_swap

CC			= cc
CFLAGS		= -Wall -Werror -Wextra -g

LIBS		= ft
LIBS_DIR	= $(foreach lib, $(LIBS), lib$(lib))
ARCHIVES 	= $(foreach lib, $(LIBS_DIR), ./$(lib)/$(lib).a)
LINKS		= $(foreach lib, $(LIBS),-L lib$(lib) -l $(lib))

INC			= $(foreach lib, $(LIBS_DIR),-I $(lib)/include)
INC			+= -I stack/include
INC			+= -I sort_algorithms/include

CFILES 		= 	push_swap.c								\
				./stack/src/push.c						\
				./stack/src/rotate.c					\
				./stack/src/swap.c						\
				./stack/src/utils1.c					\
				./stack/src/utils2.c					\
				./stack/src/utils3.c					\
				./sort_algorithms/src/test_algorithm.c	\
				./sort_algorithms/src/turk_algorithm.c	\

OBJECTS		= $(CFILES:.c=.o)

$(NAME): $(ARCHIVES) $(OBJECTS)
	@echo ""
	$(CC) $(CFLAGS) $(INC) $(CFILES) $(LINKS)
	@echo "\n-> $(NAME) : OK"
	./a.out -45 2 7 27 58 62 34 15 01 56

$(ARCHIVES):
	@echo "\nBuilding required libraries :"
	@$(foreach lib, $(LIBS_DIR), $(MAKE) -s -C ./$(lib) all;)

%.o: %.c
	@$(CC) $(CFLAGS) $(INC) -c $^ -o $@

all: $(NAME)

clean:
	@rm -vf $(OBJECTS)
	@$(foreach lib, $(LIBS_DIR), $(MAKE) -s -C ./$(lib) clean;)

fclean:
	@rm -vf $(NAME) $(OBJECTS)
	@$(foreach lib, $(LIBS_DIR), $(MAKE) -s -C ./$(lib) fclean;)

re: fclean all

.PHONY: all clean fclean re