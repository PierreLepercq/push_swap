# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/05 17:08:02 by plepercq          #+#    #+#              #
#    Updated: 2026/03/18 15:03:00 by plepercq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft
ARCHIVE		= $(addsuffix .a, $(NAME))

CC 			= cc
CFLAGS		= -Wall -Wextra -Werror

FUNCTIONS 	= 	ft_atoi 		\
				ft_split 		\
				ft_strchr 		\
				ft_strlen		\
				ft_strncmp		\
				ft_substr 		\
				ft_printf		\
				check_base		\
				w_char			\
				w_nbr_base		\
				w_ptr_adress	\
				w_str			\
				w_unbr_base		\

CFILES 		= $(addprefix ./src/, $(addsuffix .c, $(FUNCTIONS)))
OBJECTS		= $(CFILES:.c=.o)

INC			= -I include

$(NAME): $(OBJECTS)
	@ar -rcs $(ARCHIVE) $^
	@echo " - $(NAME) : OK"

all: $(NAME)

clean:
	@echo "\nfrom $(NAME)"
	@rm -vf $(OBJECTS)

fclean:
	@echo "\nfrom $(NAME)"
	@rm -vf $(ARCHIVE) $(OBJECTS)

re: fclean all

%.o:%.c
	@$(CC) $(CFLAGS) $(INC) -c -o $@ $^

.PHONY: all clean fclean re bonus