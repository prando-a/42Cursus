# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/17 00:35:21 by prando-a          #+#    #+#              #
#    Updated: 2023/09/10 19:13:46 by prando-a         ###   ########.fr        #
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
BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c \
		ft_lstsize_bonus.c ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c ft_lstiter_bonus.c \
		ft_lstmap_bonus.c
EXTRA = ft_printf/ft_printf.c ft_printf/print_cs.c \
		ft_printf/print_diu.c get_next_line.c
CROM =	ft_linecounter.c ft_str_islf.c \
		ft_realloc.c \
		ft_arrnum.c ft_arrlen.c \
		ft_merge.c
SRC_O = $(SRC:.c=.o)
BONUS_O = $(BONUS:.c=.o)
CROM_O  = $(CROM:.c=.o)
EXTRA_O	= $(EXTRA:.c=.o)
FLAGS = -Wall -Wextra -Werror -c -o
A_LIB = @ar rcs

all: $(NAME)

$(NAME): $(SRC_O)
	$(A_LIB) $(NAME) $(SRC_O)
	
bonus: $(BONUS_O)
	$(A_LIB) $(NAME) $(BONUS_O)

extra: $(EXTRA_O)
	$(A_LIB) $(NAME) $(EXTRA_O)

crom: $(CROM_O)
	$(A_LIB) $(NAME) $(CROM_O)

%.o:%.c
	gcc $(FLAGS) $@ $<
	
clean:
	@rm -f $(SRC_O) $(BONUS_O) $(CROM_O) $(EXTRA_O)
fclean:
	@rm -f $(NAME) $(SRC_O) $(BONUS_O) $(CROM_O) $(EXTRA_O)
re: fclean all
.PHONY: all clean fclean re bonus crom extra