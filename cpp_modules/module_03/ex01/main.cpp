/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 02:38:04 by prando-a          #+#    #+#             */
/*   Updated: 2024/05/23 02:38:04 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void )
{
	ClapTrap a("Artorias");
	ClapTrap ml("Meier Link");
	ClapTrap mnt("Mata Nui Titan");
	ScavTrap as("Adam Sandler");

	a.attack("Meier Link");
	ml.takeDamage(10);

	mnt.attack("Artorias");
	a.takeDamage(10);

	as.guardGate();
	as.attack("Artorias");
	a.takeDamage(20);

	ScavTrap as2(as);
	as2.attack("Adam Sandler");
	as.takeDamage(10);
	as.beRepaired(10);
	return 0;
}