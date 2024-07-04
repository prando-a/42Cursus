/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:54:49 by prando-a          #+#    #+#             */
/*   Updated: 2024/06/10 20:54:49 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << GREEN << "A WrongAnimal just spawned" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &WrongAnimal)
{
	std::cout << GREEN << "WrongAnimal copy constructor called \n" << RESET;
	*this = WrongAnimal;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &WrongAnimal)
{
    std::cout << GREEN "WrongAnimal copy assignment operator called \n" << RESET;
    this->_type = WrongAnimal._type;
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << GREEN << "A WrongAnimal just died" << RESET << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (this->_type);
}

void WrongAnimal::makeSound() const
{
	std::cout << GREEN << "\"An evident WrongAnimal sound...\"" << RESET << std::endl;
}
