# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/17 00:35:21 by prando-a          #+#    #+#              #
#    Updated: 2023/09/05 17:16:31 by prando-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_A = libft.a

SRC = ft_isalpha.c ft_toupper.c \
		ft_isdigit.c ft_tolower.c \
		ft_isalnum.c ft_strchr.c \
		ft_isascii.c ft_strrchr.c \
		ft_isprint.c ft_strncmp.c \
		ft_strlen.c  ft_memchr.c \
		ft_memset.c ft_memcmp.c \
		ft_bzero.c ft_strnstr.c\
		ft_memcpy.c ft_atoi.c \
		ft_memmove.c \
		ft_strlcpy.c ft_calloc.c\
		ft_strlcat.c ft_strdup.c\
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
CROM =	ft_linecounter.c ft_str_islf.c \
		ft_realloc.c \
		ft_arrnum.c ft_arrlen.c \
		ft_merge.c
SRC_O = $(SRC:.c=.o)
BONUS_O = $(BONUS:.c=.o)
CROM_O  = $(CROM:.c=.o)
FLAGS = -Wall -Wextra -Werror -c -o
A_LIB = @ar rcs

all: $(LIBFT_A)

$(LIBFT_A): $(SRC_O)
	$(A_LIB) $(LIBFT_A) $(SRC_O)
	
bonus: $(BONUS_O)
	$(A_LIB) $(LIBFT_A) $(BONUS_O)

crom: $(CROM_O)
	$(A_LIB) $(LIBFT_A) $(CROM_O)

%.o:%.c
	gcc $(FLAGS) $@ $<

clean:
	@rm -f $(SRC_O) $(BONUS_O) $(CROM_O)
fclean:
	@rm -f $(LIBFT_A) $(SRC_O) $(BONUS_O) $(CROM_O)
re: fclean all
.PHONY: all clean fclean re bonus crom