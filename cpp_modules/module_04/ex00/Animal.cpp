/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:52:50 by prando-a          #+#    #+#             */
/*   Updated: 2024/06/10 20:52:50 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << GREEN << "An animal just spawned" << RESET << std::endl;
}

Animal::Animal(const Animal &Animal)
{
	std::cout << GREEN << "Animal copy constructor called \n" << RESET;
	*this = Animal;
}

Animal &Animal::operator=(const Animal &Animal)
{
    std::cout << GREEN "Animal copy assignment operator called \n" << RESET;
    this->_type = Animal._type;
    return (*this);
}

Animal::~Animal()
{
	std::cout << GREEN << "An animal just died" << RESET << std::endl;
}

std::string Animal::getType() const
{
	return (this->_type);
}

void Animal::makeSound() const
{
	std::cout << GREEN << "\"Any other animal sound...\"" << RESET << std::endl;
}
