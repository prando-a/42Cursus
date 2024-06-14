#include "Harl.hpp"

Harl::Harl()
{
	this->func[0] = &Harl::debug;
	this->func[1] = &Harl::info;
	this->func[2] = &Harl::warning;
	this->func[3] = &Harl::error;
	this->funcType[0] = "debug";
	this->funcType[1] = "info";
	this->funcType[2] = "warning";
	this->funcType[3] = "error";
}

void Harl::debug()
{
	std::cout << BOLD GREEN << "[DEBUG]\n" << RESET;
	std::cout << GREEN << "I am the milkman. My milk is delicious." << RESET << "\n";
}

void Harl::info()
{
	std::cout << BOLD BLUE << "[INFO]\n" << RESET;
	std::cout << BLUE << "Psst! Hey. I know who you are. Hail Sithis!" << RESET << "\n";
}

void Harl::warning()
{
	std::cout << BOLD YELLOW << "[WARNING]\n" << RESET;
	std::cout << YELLOW << "AHEM! There's SAND on my boots!" << RESET << "\n";
}

void Harl::error()
{
	std::cout << BOLD RED << "[ERROR]\n" << RESET;
	std::cout << RED << "OBJECTION! Go away." << RESET << "\n";
}

void Harl::complain(std::string type)
{
	int i = 0;
	while (i < 4)
  	{
        if (type == this->funcType[i])
            (this->*func[i])();
		i++;
	}
}