NAME = harlFilter
SRC = main.cpp Harl.cpp
SRC_O = $(SRC:.c=.o)
FLAGS =  -g -std=c++98 -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC)
	c++ $(FLAGS) -o $@ $^

clean:
	rm -f $(NAME)

re: clean all

.PHONY: all clean re