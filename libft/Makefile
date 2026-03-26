# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/05 17:08:02 by plepercq          #+#    #+#              #
#    Updated: 2026/03/26 12:00:37 by plepercq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft
ARCHIVE		= $(addsuffix .a, $(NAME))

CC 			= cc
CFLAGS		= -Wall -Wextra -Werror

FT_LIB		= 	ft_isalpha		\
				ft_isdigit		\
				ft_isalnum		\
				ft_isascii		\
				ft_isprint		\
				ft_toupper		\
				ft_tolower		\

FT_LIB		+=	ft_strlen		\
				ft_strlcpy		\
				ft_strlcat		\
				ft_strdup		\
				ft_strchr		\
				ft_strrchr		\
				ft_strjoin		\
				ft_strtrim		\
				ft_strmapi		\
				ft_split		\
				ft_substr		\
				ft_strnstr		\
				ft_strncmp		\
				ft_striteri		\

FT_LIB		+=	ft_bzero		\
				ft_calloc		\
				ft_memset		\
				ft_memcpy		\
				ft_memmove		\
				ft_memchr		\
				ft_memcmp		\

FT_LIB		+=	ft_atoi			\
				ft_itoa			\

FT_LIB		+=	ft_putchar_fd	\
				ft_putstr_fd	\
				ft_putendl_fd	\
				ft_putnbr_fd	\

#	FT_PRINTF
FT_PRINTF	=	ft_printf		\
				check_base		\
				w_char			\
				w_nbr_base		\
				w_ptr_adress	\
				w_str			\
				w_unbr_base		\

#	FT_LIST
FT_LIST		=	ft_lstadd_back	\
				ft_lstadd_front	\
				ft_lstclear		\
				ft_lstdelone	\
				ft_lstiter		\
				ft_lstlast		\
				ft_lstmap		\
				ft_lstnew		\
				ft_lstsize		\

CFILES 		= $(addprefix ./src/, $(addsuffix .c, $(FT_LIB)))
CFILES 		+= $(addprefix ./src/ft_printf/, $(addsuffix .c, $(FT_PRINTF)))
CFILES 		+= $(addprefix ./src/ft_list/, $(addsuffix .c, $(FT_LIST)))
OBJECTS		= $(CFILES:.c=.o)

INC			= -I include

$(NAME): $(OBJECTS)
	@ar -rcs $(ARCHIVE) $^
	@echo " - $(NAME) : OK"

all: $(NAME)

clean:
	@echo "\n> removing from $(NAME)"
	@rm -vf $(OBJECTS)

fclean:
	@echo "\n> removing from $(NAME)"
	@rm -vf $(ARCHIVE) $(OBJECTS)

re: fclean all

%.o:%.c
	@$(CC) $(CFLAGS) $(INC) -c -o $@ $^

.PHONY: all clean fclean re bonus