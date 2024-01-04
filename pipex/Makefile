# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/10 17:20:13 by prando-a          #+#    #+#              #
#    Updated: 2024/01/03 18:15:04 by prando-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
LIBFT_PATH = libft
SRC = src/pipex.c src/exec.c
SRC_BONUS = src_bonus/pipex_bonus.c src_bonus/child_bonus.c src_bonus/init_bonus.c
SRC_O = $(SRC:.c=.o)
BONUS_O = $(SRC_BONUS:.c=.o)
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

bonus: $(BONUS_O) $(LIBFT_PATH)/libft.a 
	gcc -o $(NAME) $^ -L$(LIBFT_PATH)
	@echo
	@echo 100% - BONUS

$(NAME): $(SRC_O) $(LIBFT_PATH)/libft.a
	gcc -o $@ $^ -L$(LIBFT_PATH)
	@echo
	@echo 100%
	@echo

$(LIBFT_PATH)/libft.a:
	$(MAKE) -C $(LIBFT_PATH) all extra crom old
	@echo
	@echo 80%
	@echo

src/%.o : src/%.c
	gcc $(FLAGS) -c $< -o $@

src_bonus/%.o : src_bonus/%.c
	gcc -c $(FLAGS) $< -o $@

clean:
	$(MAKE) -C $(LIBFT_PATH) fclean
	rm -f $(SRC_O)
	rm -rf $(BONUS_O)

fclean:
	$(MAKE) -C $(LIBFT_PATH) fclean
	rm -f $(SRC_O)
	rm -rf $(BONUS_O)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus