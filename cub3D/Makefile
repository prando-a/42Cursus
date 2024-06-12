# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/10 17:20:13 by prando-a          #+#    #+#              #
#    Updated: 2024/05/29 18:07:30 by prando-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

LIBFT_PATH = libft

LIBMLX = MLX42

SRC =		src/main.c 																					\
			src/parser/parser.c 						src/parser/extract.c 							\
			src/parser/map.c							src/parser/closed_map.c 						\
			src/parser/aux_qmaps.c																		\
			src/graphics/ray_casting.c					src/graphics/background.c 						\
			src/graphics/ray_casting_utils.c			src/graphics/images.c							\
			src/general/handlers.c 	    				src/general/walls.c	 							\
			src/general/walls_map_check.c		

SRC_BONUS =	src_bonus/main.c 																			\
			src_bonus/parser/parser.c 					src_bonus/parser/extract.c 						\
			src_bonus/parser/map.c						src_bonus/parser/closed_map.c 					\
			src_bonus/parser/aux_qmaps.c																\
			src_bonus/graphics/ray_casting.c			src_bonus/graphics/background.c 				\
			src_bonus/graphics/ray_casting_utils.c		src_bonus/graphics/images.c						\
			src_bonus/general/handlers.c 	    		src_bonus/general/walls.c	 					\
			src_bonus/general/handlers_mouse.c 			src_bonus/general/walls_map_check.c				\
			src_bonus/bonus/minimap.c 					src_bonus/bonus/minimap_rays.c 					\
			src_bonus/bonus/doors/d_parser.c 			src_bonus/bonus/doors/d_utils.c					\
			src_bonus/bonus/weapons/w_init.c			src_bonus/bonus/weapons/w_handler_and_punch.c	\
			src_bonus/bonus/weapons/w_gun_and_shotgun.c
		
SRC_O = $(SRC:.c=.o)
BONUS_O = $(SRC_BONUS:.c=.o)
FLAGS =  -Wall -Wextra -Werror

all: $(NAME)

bonus: $(BONUS_O) $(LIBFT_PATH)/libft.a $(LIBMLX)/libmlx42.a
	gcc -o $(NAME) $^ -L$(LIBFT_PATH) -ldl -lglfw -I include -lglfw  -pthread -lm
	@echo
	@echo 125% - BONUS
	@echo

$(NAME): $(SRC_O) $(LIBFT_PATH)/libft.a $(LIBMLX)/libmlx42.a
	gcc $(FLAGS) -o $@ $^ -L$(LIBFT_PATH) -Iinclude -ldl -lglfw -pthread -lm
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