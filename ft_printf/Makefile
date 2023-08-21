# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/24 13:06:57 by prando-a          #+#    #+#              #
#    Updated: 2023/07/26 17:26:12 by prando-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FILES = ft_printf.c print_cs.c print_diu.c print_hex.c ft_putchar.c
OBJECTS = $(FILES:.c=.o)
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS)

%.o:%.c
	gcc $(FLAGS) -c $<

clean:
	@rm -f $(OBJECTS)
fclean:
	@rm -f $(NAME) $(OBJECTS)
re: fclean all
.PHONY: all clean fclean re