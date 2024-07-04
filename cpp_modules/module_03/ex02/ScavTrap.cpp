/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scavtrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:17:19 by prando-a          #+#    #+#             */
/*   Updated: 2024/05/30 18:17:19 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << GREEN << "ScavTrap " << name << " came into this world" << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &ScavTrap) : ClapTrap(ScavTrap)
{
	std::cout << GREEN << "Copy constructor called\n" << RESET;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &ScavTrap)
{
    this->name = ScavTrap.name;
	this->hitPoints = ScavTrap.hitPoints;
	this->energyPoints = ScavTrap.energyPoints;
	this->attackDamage = ScavTrap.attackDamage;
    std::cout << GREEN "This beautiful " << this->name << " clone was just created\n" << RESET;
    return *this;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->energyPoints < 1)
	{
		std::cout << RED << "ScavTrap " << this->name << " is out of energy" << RESET << std::endl;
		return ;
	}
	if (this->hitPoints < 1)
	{
		std::cout << RED << "ScavTrap " << this->name << " is already dead" << RESET << std::endl;
		return ;
	}
	
	std::cout << GREEN << "ScavTrap " << this->name << " attacked " << target << " causing " << this->attackDamage << " points of damage!" << RESET << std::endl;
	this->energyPoints -= 1;
}

void ScavTrap::takeDamage(unsigned int amount)
{
	if (this->energyPoints < 1)
	{
		std::cout << RED << "ScavTrap " << this->name << " is out of energy" << RESET << std::endl;
		return ;
	}
	if (this->hitPoints < 1)
	{
		std::cout << RED << "ScavTrap " << this->name << " is already dead" << RESET << std::endl;
		return ;
	}
	std::cout << GREEN << "ScavTrap " << this->name << " took " << amount << " points of damage!" << RESET << std::endl;
	this->hitPoints -= amount;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints < 1)
	{
		std::cout << RED << "ScavTrap " << this->name << " is out of energy" << RESET << std::endl;
		return ;
	}
	if (this->hitPoints < 1)
	{
		std::cout << RED << "ScavTrap " << this->name << " is already dead" << RESET << std::endl;
		return ;
	}
	this->hitPoints += amount;
	this->energyPoints -= 1;
}

void ScavTrap::guardGate()
{
	std::cout << GREEN << "ScavTrap " << this->name << " has entered in 'Gate keeper' mode" << RESET << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << YELLOW << "ScavTrap " << this->name << " died, ba'bye!!" << RESET << std::endl;
}
