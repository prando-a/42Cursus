/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scavtrap._cpp                                       :+:      :+:    :+:   */
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
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << GREEN << "ScavTrap " << name << " came into this world" << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &ScavTrap) : ClapTrap(ScavTrap)
{
	std::cout << GREEN << "Copy constructor called\n" << RESET;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &ScavTrap)
{
    this->_name = ScavTrap._name;
	this->_hitPoints = ScavTrap._hitPoints;
	this->_energyPoints = ScavTrap._energyPoints;
	this->_attackDamage = ScavTrap._attackDamage;
    std::cout << GREEN "This beautiful " << this->_name << " clone was just created\n" << RESET;
    return *this;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_energyPoints < 1)
	{
		std::cout << RED << "ScavTrap " << this->_name << " is out of energy" << RESET << std::endl;
		return ;
	}
	if (this->_hitPoints < 1)
	{
		std::cout << RED << "ScavTrap " << this->_name << " is already dead" << RESET << std::endl;
		return ;
	}
	
	std::cout << GREEN << "ScavTrap " << this->_name << " attacked " << target << " causing " << this->_attackDamage << " points of damage!" << RESET << std::endl;
	this->_energyPoints -= 1;
}

void ScavTrap::takeDamage(unsigned int amount)
{
	if (this->_energyPoints < 1)
	{
		std::cout << RED << "ScavTrap " << this->_name << " is out of energy" << RESET << std::endl;
		return ;
	}
	if (this->_hitPoints < 1)
	{
		std::cout << RED << "ScavTrap " << this->_name << " is already dead" << RESET << std::endl;
		return ;
	}
	std::cout << GREEN << "ScavTrap " << this->_name << " took " << amount << " points of damage!" << RESET << std::endl;
	this->_hitPoints -= amount;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints < 1)
	{
		std::cout << RED << "ScavTrap " << this->_name << " is out of energy" << RESET << std::endl;
		return ;
	}
	if (this->_hitPoints < 1)
	{
		std::cout << RED << "ScavTrap " << this->_name << " is already dead" << RESET << std::endl;
		return ;
	}
	this->_hitPoints += amount;
	this->_energyPoints -= 1;
}

void ScavTrap::guardGate()
{
	std::cout << GREEN << "ScavTrap " << this->_name << " has entered in 'Gate keeper' mode" << RESET << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << YELLOW << "Scavtrap " << this->_name << " died, ba'bye!!" << RESET << std::endl;
}
