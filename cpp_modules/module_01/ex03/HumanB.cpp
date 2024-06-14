/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-12 10:52:11 by prando-a          #+#    #+#             */
/*   Updated: 2024-06-12 10:52:11 by prando-a         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string param)
{
	this->name = param;
}

void	HumanB::setWeapon(Weapon &param)
{
	this->weapon = &param;
}

void HumanB::attack()
{
	std::cout << this->name << " attacks with their " << this->weapon->getType() << "\n";
}