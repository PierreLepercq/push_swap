# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/05 17:08:02 by plepercq          #+#    #+#              #
#    Updated: 2026/03/05 17:11:07 by plepercq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

CC 		= cc
CFLAGS	= -Wall -Wextra -Werror

FUNCTIONS = atoi split strchr substr

CFILES = $(patsubst %, ft_%.c, $(FUNCTIONS))
OBJECTS	= $(patsubst %.c, %.o, $(CFILES))

$(NAME): $(OBJECTS)
	ar -rcs $@ $^

all: $(NAME)

clean:
	rm -rf $(OBJECTS)

fclean:
	rm -rf $(NAME) $(OBJECTS)

re: fclean all

%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $^

.PHONY: all clean fclean re bonus