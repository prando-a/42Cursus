/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-12 10:51:30 by prando-a          #+#    #+#             */
/*   Updated: 2024-06-12 10:51:30 by prando-a         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie* horde = zombieHorde(5, "Zombie");
	if (!horde)
		return (std::cout << "\nYour horde wasn't undead enough \n", 1);
	std::cout << "\nMeat must be as fresh as this glorious horde was just created!" << "\n";
	std::cout << "\n";
	std::cout << "\nSo, here they're! But fun has ended! Let's kill them all!" << "\n\n";
	delete[] horde;
	std::cout << "\n";
	return (0);
}