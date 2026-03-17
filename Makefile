# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/26 15:39:25 by plepercq          #+#    #+#              #
#    Updated: 2026/03/17 19:10:01 by plepercq         ###   ########.fr        #
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

CFILES 		= 	push_swap.c				\
				./stack/src/push.c		\
				./stack/src/rotate.c	\
				./stack/src/swap.c		\
				./stack/src/utils1.c	\
				./stack/src/utils2.c	\

OBJECTS		= $(CFILES:.c=.o)

$(NAME): $(ARCHIVES) $(OBJECTS)
	@echo ""
	$(CC) $(CFLAGS) $(INC) $(CFILES) $(LINKS)
	@echo "\n-> $(NAME) : OK"
	./a.out -45 2 27 49 62 35 -65 -20 -16 4 7 2

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