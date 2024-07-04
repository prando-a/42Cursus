/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:54:03 by prando-a          #+#    #+#             */
/*   Updated: 2024/06/10 20:54:03 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << GREEN << "\t \t \t and turns out to be a dog \n" << RESET;
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(const Dog &Dog) : Animal(Dog)
{
	std::cout << GREEN << "Copy constructor called \n" << RESET;
	this->_brain = new Brain(*Dog._brain);
}

Dog &Dog::operator=(const Dog &Dog)
{
    std::cout << GREEN "Copy assignment operator called \n" << RESET;
    if (this != &Dog)
	{
		delete this->_brain;
		this->_brain = new Brain(*Dog._brain);
    	this->_type = Dog._type;
	}
    return *this;
}

Dog::~Dog()
{
	std::cout << GREEN << "A dog died, and thus..." << RESET << std::endl;
	delete this->_brain;
}

void Dog::makeSound() const
{
	std::cout << GREEN << "WOOF, WOOF!!!" << RESET << std::endl;
}
