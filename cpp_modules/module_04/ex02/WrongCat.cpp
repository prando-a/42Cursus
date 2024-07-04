/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:55:32 by prando-a          #+#    #+#             */
/*   Updated: 2024/06/10 20:55:32 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << GREEN << "\t \t \t and turns out to be a Wrongcat \n" << RESET;
	this->_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &WrongCat) : WrongAnimal(WrongCat)
{
	std::cout << GREEN << "WrongCat copy constructor called \n" << RESET;
}

WrongCat &WrongCat::operator=(const WrongCat &WrongCat)
{
    std::cout << GREEN "WrongCat copy assignment operator called \n" << RESET;
    this->_type = WrongCat._type;
    return *this;
}

WrongCat::~WrongCat()
{
	std::cout << GREEN << "\t \t    and it was a Wrongcat" << RESET << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << GREEN << "wwoooeom~" << RESET << std::endl;
}