/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
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
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
	std::cout << GREEN << "ClapTrap " << this->name << " came into this world" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &ClapTrap)
{
	std::cout << GREEN << "Copy constructor called\n" << RESET;
	*this = ClapTrap;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &ClapTrap)
{
    this->name = ClapTrap.name;
	this->hitPoints = ClapTrap.hitPoints;
	this->energyPoints = ClapTrap.energyPoints;
	this->attackDamage = ClapTrap.attackDamage;
    std::cout << GREEN "This beautiful " << this->name << " clone was just created\n" << RESET;
    return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->energyPoints < 1)
	{
		std::cout << RED << "ClapTrap " << this->name << " is out of energy" << RESET << std::endl;
		return ;
	}
	if (this->hitPoints < 1)
	{
		std::cout << RED << "ClapTrap " << this->name << " is already dead" << RESET << std::endl;
		return ;
	}
	
	std::cout << GREEN << "ClapTrap " << this->name << " attacked " << target << " causing " << this->attackDamage << " points of damage!" << RESET << std::endl;
	this->energyPoints -= 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->energyPoints < 1)
	{
		std::cout << RED << "ClapTrap " << this->name << " is out of energy" << RESET << std::endl;
		return ;
	}
	if (this->hitPoints < 1)
	{
		std::cout << RED << "ClapTrap " << this->name << " is already dead" << RESET << std::endl;
		return ;
	}
	std::cout << GREEN << "ClapTrap " << this->name << " took " << amount << " points of damage!" << RESET << std::endl;
	this->hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints < 1)
	{
		std::cout << RED << "ClapTrap " << this->name << " is out of energy" << RESET << std::endl;
		return ;
	}
	if (this->hitPoints < 1)
	{
		std::cout << RED << "ClapTrap " << this->name << " is already dead" << RESET << std::endl;
		return ;
	}
	this->hitPoints += amount;
	this->energyPoints -= 1;
}

ClapTrap::~ClapTrap()
{
	std::cout << YELLOW << "ClapTrap " << this->name << " died, ba'bye!!" << RESET << std::endl;
}
