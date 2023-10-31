# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crom <crom@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/10 17:20:13 by prando-a          #+#    #+#              #
#    Updated: 2023/10/21 18:37:39 by crom             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT_PATH = libft
SRC = push_swap.c operations.c lst_utils.c sort_nums.c sort_utils.c
SRC_O = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC_O) $(LIBFT_PATH)/libft.a
	gcc -o $@ $^ -L$(LIBFT_PATH) -lft
	@echo
	@echo 100%
	@echo

$(LIBFT_PATH)/libft.a:
	$(MAKE) -C $(LIBFT_PATH) all bonus extra crom old
	@echo
	@echo 80%
	@echo

%.o:%.c
	gcc $(FLAGS) -c -o $@ $<

clean:
	$(MAKE) -C $(LIBFT_PATH) fclean
	rm -f $(SRC_O)

fclean:
	$(MAKE) -C $(LIBFT_PATH) fclean
	rm -f $(SRC_O)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re