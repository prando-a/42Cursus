# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jose-mgo <jose-mgo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/10 17:20:13 by prando-a          #+#    #+#              #
#    Updated: 2024/02/06 10:24:42 by jose-mgo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
LIBFT_PATH = libft
SRC =	src/main.c \
		src/env_utils.c src/init.c \
		src/parser/parser.c src/parser/parser2.c src/parser/parser3.c\
		src/parser/quotes.c src/parser/parser4.c src/parser/parser5.c\
		src/exec/exec.c src/exec/exec_init_and_io.c src/exec/exec_parser.c \
		src/exec/built-in.c src/exec/built-in2.c \
#SRC_BONUS = 
SRC_O = $(SRC:.c=.o)
#BONUS_O = $(SRC_BONUS:.c=.o)
FLAGS = -Wall -Wextra -Werror
READLINE_BREW_COMP = -lreadline -L${HOME}/.brew/opt/readline/lib
READLINE_BREW_OBJS = -I${HOME}/.brew/opt/readline/include

all: $(NAME)

#bonus: $(BONUS_O) $(LIBFT_PATH)/libft.a 
#	gcc -o $(NAME) $^ -L$(LIBFT_PATH)
#	@echo
#	@echo 100% - BONUS

$(NAME): $(SRC_O) $(LIBFT_PATH)/libft.a
	gcc $(FLAGS) -o $@ $^ -L$(LIBFT_PATH) $(READLINE_BREW_COMP) -lreadline
	@echo
	@echo 100%
	@echo

$(LIBFT_PATH)/libft.a:
	$(MAKE) -C $(LIBFT_PATH) all extra crom old
	@echo
	@echo 80%
	@echo

src/%.o : src/%.c
	gcc $(FLAGS) $(READLINE_BREW_OBJS) -c $< -o $@

#src_bonus/%.o : src_bonus/%.c
#	gcc $(FLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_PATH) fclean
	rm -f $(SRC_O)
#	rm -rf $(BONUS_O)

fclean:
	$(MAKE) -C $(LIBFT_PATH) fclean
	rm -f $(SRC_O)
#	rm -rf $(BONUS_O)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

#export LDFLAGS="-L/Users/$(USER)/.brew/opt/readline/lib"
#export CPPFLAGS="-I/Users/$(USER)/.brew/opt/readline/include"
