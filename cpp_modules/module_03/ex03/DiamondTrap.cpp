/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap._cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:17:19 by prando-a          #+#    #+#             */
/*   Updated: 2024/05/30 18:17:19 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name)
{
	this->_name = name;
	this->ClapTrap::_name = name + "_clap_name";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << GREEN << "DiamondTrap " << name << " came into this world" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &DiamondTrap) : ClapTrap(DiamondTrap), ScavTrap(DiamondTrap), FragTrap(DiamondTrap)
{
	std::cout << GREEN << "Copy constructor called\n" << RESET;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &DiamondTrap)
{
    this->_name = DiamondTrap._name;
	this->_hitPoints = DiamondTrap._hitPoints;
	this->_energyPoints = DiamondTrap._energyPoints;
	this->_attackDamage = DiamondTrap._attackDamage;
    std::cout << GREEN "This beautiful " << this->_name << " clone was just created\n" << RESET;
    return *this;
}

void DiamondTrap::whoAmI()
{
	std::cout << GREEN << "\"DiamondTrap " << this->_name << ", a.k.a. " << this->ClapTrap::_name << " at your service!\"" << RESET << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << YELLOW << "DiamondTrap " << this->_name << " died, ba'bye!!" << RESET << std::endl;
}
