NAME = sedIsForLosers
SRC = main.cpp ftSed.cpp
SRC_O = $(SRC:.c=.o)
FLAGS =  -g -std=c++98 -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC)
	c++ $(FLAGS) -o $@ $^
	@echo "¿Hacia dónde vas, riachuelo? \n\
	Lejos, muy lejos. \n\
	Llévame contigo, río. \n\
	Llévame en tu oscuro viaje. \n\
	Señor nuestro, Arquitecto, \n\
	llévame hasta el corazón de la luz. \n\
	Te entrego mi vida, mi aliento, mi silencio...\n" > test.txt

clean:
	rm -f $(NAME) test.txt

re: clean all

.PHONY: all clean re