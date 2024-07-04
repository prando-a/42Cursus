NAME = bureaucrat
SRC = main.cpp Bureaucrat.cpp
FLAGS =  -g -std=c++98 -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC)
	c++ $(FLAGS) -o $@ $^
	echo "Created $(NAME)"
	@echo -n "\033[0m"

clean:
	rm -f $(NAME)

re: clean all

.PHONY: all clean re