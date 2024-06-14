NAME = megaphone
SRC = megaphone.cpp
SRC_O = $(SRC:.c=.o)
FLAGS =  -g -std=c++98 -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC)
	c++ $(FLAGS) -o $@ $^

clean:
	rm -f $(NAME)

.PHONY: all clean