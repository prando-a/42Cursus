/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap._cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 02:50:05 by prando-a          #+#    #+#             */
/*   Updated: 2024/05/23 02:50:05 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	std::cout << GREEN << "ClapTrap " << this->_name << " came into this world" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &ClapTrap)
{
	std::cout << GREEN << "Copy constructor called\n" << RESET;
	*this = ClapTrap;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &ClapTrap)
{
    this->_name = ClapTrap._name;
	this->_hitPoints = ClapTrap._hitPoints;
	this->_energyPoints = ClapTrap._energyPoints;
	this->_attackDamage = ClapTrap._attackDamage;
    std::cout << GREEN "This beautiful " << this->_name << " clone was just created\n" << RESET;
    return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoints < 1)
	{
		std::cout << RED << "ClapTrap " << this->_name << " is out of energy" << RESET << std::endl;
		return ;
	}
	if (this->_hitPoints < 1)
	{
		std::cout << RED << "ClapTrap " << this->_name << " is already dead" << RESET << std::endl;
		return ;
	}
	
	std::cout << GREEN << "ClapTrap " << this->_name << " attacked " << target << " causing " << this->_attackDamage << " points of damage!" << RESET << std::endl;
	this->_energyPoints -= 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_energyPoints < 1)
	{
		std::cout << RED << "ClapTrap " << this->_name << " is out of energy" << RESET << std::endl;
		return ;
	}
	if (this->_hitPoints < 1)
	{
		std::cout << RED << "ClapTrap " << this->_name << " is already dead" << RESET << std::endl;
		return ;
	}
	std::cout << GREEN << "ClapTrap " << this->_name << " took " << amount << " points of damage!" << RESET << std::endl;
	this->_hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints < 1)
	{
		std::cout << RED << "ClapTrap " << this->_name << " is out of energy" << RESET << std::endl;
		return ;
	}
	if (this->_hitPoints < 1)
	{
		std::cout << RED << "ClapTrap " << this->_name << " is already dead" << RESET << std::endl;
		return ;
	}
	this->_hitPoints += amount;
	this->_energyPoints -= 1;
}

ClapTrap::~ClapTrap()
{
	std::cout << YELLOW << "ClapTrap " << this->_name << " died, ba'bye!!" << RESET << std::endl;
}
