NAME = btc
SRC =	main.cpp BitcoinExchange.cpp
FLAGS =  -g -std=c++98

all: $(NAME)

$(NAME): $(SRC)
	c++ $(FLAGS) -o $@ $^
	echo "Created $(NAME)"
	@echo -n "\033[0m"

clean:
	rm -f $(NAME) $(NAME).dSYM

re: clean all

.PHONY: all clean re