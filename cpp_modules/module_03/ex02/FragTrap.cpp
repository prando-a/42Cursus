/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
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
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << GREEN << "FragTrap " << name << " came into this world" << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap &FragTrap) : ClapTrap(FragTrap)
{
	std::cout << GREEN << "Copy constructor called\n" << RESET;
}

FragTrap &FragTrap::operator=(const FragTrap &FragTrap)
{
    this->name = FragTrap.name;
	this->hitPoints = FragTrap.hitPoints;
	this->energyPoints = FragTrap.energyPoints;
	this->attackDamage = FragTrap.attackDamage;
    std::cout << GREEN "This beautiful " << this->name << " clone was just created\n" << RESET;
    return *this;
}

void FragTrap::attack(const std::string& target)
{
	if (this->energyPoints < 1)
	{
		std::cout << RED << "FragTrap " << this->name << " is out of energy" << RESET << std::endl;
		return ;
	}
	if (this->hitPoints < 1)
	{
		std::cout << RED << "FragTrap " << this->name << " is already dead" << RESET << std::endl;
		return ;
	}
	
	std::cout << GREEN << "FragTrap " << this->name << " attacked " << target << " causing " << this->attackDamage << " points of damage!" << RESET << std::endl;
	this->energyPoints -= 1;
}

void FragTrap::takeDamage(unsigned int amount)
{
	if (this->energyPoints < 1)
	{
		std::cout << RED << "FragTrap " << this->name << " is out of energy" << RESET << std::endl;
		return ;
	}
	if (this->hitPoints < 1)
	{
		std::cout << RED << "FragTrap " << this->name << " is already dead" << RESET << std::endl;
		return ;
	}
	std::cout << GREEN << "FragTrap " << this->name << " took " << amount << " points of damage!" << RESET << std::endl;
	this->hitPoints -= amount;
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints < 1)
	{
		std::cout << RED << "FragTrap " << this->name << " is out of energy" << RESET << std::endl;
		return ;
	}
	if (this->hitPoints < 1)
	{
		std::cout << RED << "FragTrap " << this->name << " is already dead" << RESET << std::endl;
		return ;
	}
	this->hitPoints += amount;
	this->energyPoints -= 1;
}

void FragTrap::highFivesGuys()
{
	std::cout << GREEN << this->name << ": " << RESET;
	std::cout << GREEN << "\"FragTrap " << this->name << " wants a hi'5 !\"" << RESET << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << YELLOW << "ScavTrap " << this->name << " died, ba'bye!!" << RESET << std::endl;
}
