NAME = diamondtrap
SRC = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
SRC_O = $(SRC:.c=.o)
FLAGS =  -g -std=c++98 -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC)
	c++ $(FLAGS) -o $@ $^
	echo "Created $(NAME)"

clean:
	rm -f $(NAME)

re: clean all

.PHONY: all clean re