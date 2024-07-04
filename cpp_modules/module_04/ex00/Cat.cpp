/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:53:26 by prando-a          #+#    #+#             */
/*   Updated: 2024/06/10 20:53:26 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << GREEN << "\t \t \t and turns out to be a cat \n" << RESET;
	this->_type = "Cat";
}

Cat::Cat(const Cat &Cat) : Animal(Cat)
{
	std::cout << GREEN << "Cat copy constructor called \n" << RESET;
}

Cat &Cat::operator=(const Cat &Cat)
{
    std::cout << GREEN "Cat copy assignment operator called \n" << RESET;
    this->_type = Cat._type;
    return *this;
}

Cat::~Cat()
{
	std::cout << GREEN << "\t \t    and it was a cat" << RESET << std::endl;
}

void Cat::makeSound() const
{
	std::cout << GREEN << "~meoooww" << RESET << std::endl;
}
