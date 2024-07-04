/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap._cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:17:19 by prando-a          #+#    #+#             */
/*   Updated: 2024/05/30 18:17:19 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << GREEN << "FragTrap " << name << " came into this world" << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap &FragTrap) : ClapTrap(FragTrap)
{
	std::cout << GREEN << "Copy constructor called\n" << RESET;
}

FragTrap &FragTrap::operator=(const FragTrap &FragTrap)
{
    this->_name = FragTrap._name;
	this->_hitPoints = FragTrap._hitPoints;
	this->_energyPoints = FragTrap._energyPoints;
	this->_attackDamage = FragTrap._attackDamage;
    std::cout << GREEN "This beautiful " << this->_name << " clone was just created\n" << RESET;
    return *this;
}

void FragTrap::attack(const std::string& target)
{
	if (this->_energyPoints < 1)
	{
		std::cout << RED << "FragTrap " << this->_name << " is out of energy" << RESET << std::endl;
		return ;
	}
	if (this->_hitPoints < 1)
	{
		std::cout << RED << "FragTrap " << this->_name << " is already dead" << RESET << std::endl;
		return ;
	}
	
	std::cout << GREEN << "FragTrap " << this->_name << " attacked " << target << " causing " << this->_attackDamage << " points of damage!" << RESET << std::endl;
	this->_energyPoints -= 1;
}

void FragTrap::takeDamage(unsigned int amount)
{
	if (this->_energyPoints < 1)
	{
		std::cout << RED << "FragTrap " << this->_name << " is out of energy" << RESET << std::endl;
		return ;
	}
	if (this->_hitPoints < 1)
	{
		std::cout << RED << "FragTrap " << this->_name << " is already dead" << RESET << std::endl;
		return ;
	}
	std::cout << GREEN << "FragTrap " << this->_name << " took " << amount << " points of damage!" << RESET << std::endl;
	this->_hitPoints -= amount;
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints < 1)
	{
		std::cout << RED << "FragTrap " << this->_name << " is out of energy" << RESET << std::endl;
		return ;
	}
	if (this->_hitPoints < 1)
	{
		std::cout << RED << "FragTrap " << this->_name << " is already dead" << RESET << std::endl;
		return ;
	}
	this->_hitPoints += amount;
	this->_energyPoints -= 1;
}

void FragTrap::highFivesGuys()
{
	std::cout << GREEN << this->_name << ": " << RESET;
	std::cout << GREEN << "\"FragTrap " << this->_name << " wants a hi'5 !\"" << RESET << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << YELLOW << "FragTrap " << this->_name << " died, ba'bye!!" << RESET << std::endl;
}
