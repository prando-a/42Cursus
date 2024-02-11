# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crom <crom@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/17 00:35:21 by prando-a          #+#    #+#              #
#    Updated: 2024/01/07 02:45:07 by crom             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = 	ft_isalpha.c ft_toupper.c \
		ft_isdigit.c ft_tolower.c \
		ft_isalnum.c ft_strchr.c \
		ft_isascii.c ft_strrchr.c \
		ft_isprint.c ft_strncmp.c \
		ft_strlen.c  ft_memchr.c \
		ft_memset.c ft_memcmp.c \
		ft_bzero.c ft_strnstr.c\
		ft_memcpy.c ft_atoi.c \
		ft_memmove.c \
		ft_strlcpy.c ft_calloc.c \
		ft_strlcat.c ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c
BONUS = ft_lstsize_bonus.c ft_lstlast_bonus.c
#		ft_lstnew_bonus.c ft_lstadd_front_bonus.c \
		ft_lstsize_bonus.c ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c ft_lstiter_bonus.c \
		ft_lstmap_bonus.c
EXTRA = ft_printf/ft_printf.c ft_printf/print_cs.c \
		ft_printf/print_diu.c get_next_line.c
CROM =	crom/ft_fndchr.c crom/ft_linecounter.c \
		crom/ft_str_islf.c crom/ft_realloc.c \
		crom/ft_arrnum.c crom/ft_arrlen.c crom/ft_arrdup.c \
		crom/ft_merge.c crom/ft_arr_islf.c crom/ft_atoll.c crom/ft_arrjoin.c \
		crom/ft_putmatrix.c crom/ft_chrdel.c crom/ft_chrcnt.c \
		crom/ft_tridel.c crom/ft_put_triarr.c crom/ft_isalpha_sp.c\
		crom/ft_file_to_str.c crom/ft_file_to_arr.c \
		crom/ft_putfd.c crom/ft_putfd_fd.c
OLD =	old/ft_memdel.c old/ft_strdel.c old/ft_strclr.c \
		old/ft_striter.c old/ft_strmap.c \
		old/ft_strequ.c old/ft_strnequ.c
SRC_O = $(SRC:.c=.o)
BONUS_O = $(BONUS:.c=.o)
EXTRA_O	= $(EXTRA:.c=.o)
OLD_O	= $(OLD:.c=.o)
CROM_O  = $(CROM:.c=.o)
FLAGS = -Wall -Wextra -Werror -g -c -o
A_LIB = @ar rcs

all: $(NAME)

$(NAME): $(SRC_O)
	@$(A_LIB) $(NAME) $(SRC_O)
	@echo
	@echo 35%
	@echo
	@echo F*ck you, libft bonus.
	@echo

bonus: $(BONUS_O)
	@$(A_LIB) $(NAME) $(BONUS_O)
	@echo
	@echo 40%
	@echo

extra: $(EXTRA_O)
	@$(A_LIB) $(NAME) $(EXTRA_O)
	@echo
	@echo 50%
	@echo

old: $(OLD_O)
	@$(A_LIB) $(NAME) $(OLD_O)
	@echo
	@echo 60%
	@echo

crom: $(CROM_O)
	@$(A_LIB) $(NAME) $(CROM_O)
	@echo
	@echo 70%
	@echo

%.o:%.c
	gcc $(FLAGS) $@ $<


clean:
	@rm -f $(SRC_O) $(BONUS_O) $(EXTRA_O) $(OLD_O) $(CROM_O)

fclean: clean
	@rm -f $(NAME)

re: fclean all


.PHONY: all clean fclean re bonus extra old crom