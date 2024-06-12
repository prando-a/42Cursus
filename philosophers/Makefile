# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/10 17:20:13 by prando-a          #+#    #+#              #
#    Updated: 2024/03/21 07:53:04 by prando-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRC = main.c parse_init.c start.c 
#SRC_BONUS = main_bonus.c
SRC_O = $(SRC:.c=.o)
#BONUS_O = $(SRC_BONUS:.c=.o)
FLAGS = -Wall -Wextra -Werror -g -Os

all: $(NAME)

#bonus: $(BONUS_O) $(LIBFT_PATH)/libft.a 
#	gcc -o $(NAME) $^ -L$(LIBFT_PATH)
#	@echo BONUS

$(NAME): $(SRC_O)
	gcc -o $@ $^

src/%.o : src/%.c
	gcc -c $< -o $@

#src_bonus/%.o : src_bonus/%.c
#	gcc -c $< -o $@

clean:
	rm -f $(SRC_O)
#	rm -rf $(BONUS_O)

fclean:
	rm -f $(SRC_O)
#	rm -rf $(BONUS_O)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus