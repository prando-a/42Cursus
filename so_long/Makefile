# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/10 17:20:13 by prando-a          #+#    #+#              #
#    Updated: 2023/11/24 15:40:56 by prando-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIBFT_PATH = libft
LIBMLX = MLX42
SRC = src/so_long.c src/parser.c src/parser_ii.c src/coreplay.c
SRC_BONUS = src_bonus/so_long_bonus.c src_bonus/parser_bonus.c src_bonus/parser_ii_bonus.c \
			src_bonus/coreplay_bonus.c src_bonus/bonus_bonus.c
SRC_O = $(SRC:.c=.o)
BONUS_O = $(SRC_BONUS:.c=.o)
FLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

bonus: $(BONUS_O) $(LIBFT_PATH)/libft.a $(LIBMLX)/libmlx42.a
	gcc -o $(NAME) $^ -L$(LIBFT_PATH) -ldl -lglfw -I include -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/" -pthread -lm
	@echo
	@echo 100% - BONUS

$(NAME): $(SRC_O) $(LIBFT_PATH)/libft.a $(LIBMLX)/libmlx42.a
	gcc -o $@ $^ -L$(LIBFT_PATH) -ldl -lglfw -I include -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/" -pthread -lm
	@echo
	@echo 100%
	@echo

$(LIBFT_PATH)/libft.a:
	$(MAKE) -C $(LIBFT_PATH) all extra crom old
	@echo
	@echo 80%
	@echo

$(LIBMLX)/libmlx42.a:
	$(MAKE) -C MLX42 all

src/%.o : src/%.c
	gcc $(FLAGS) -c $< -o $@

src_bonus/%.o : src_bonus/%.c
	gcc $(FLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_PATH) fclean
	rm -f $(SRC_O)
	rm -rf $(BONUS_O)

fclean:
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(MAKE) -C MLX42 fclean
	rm -f $(SRC_O)
	rm -rf $(BONUS_O)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re