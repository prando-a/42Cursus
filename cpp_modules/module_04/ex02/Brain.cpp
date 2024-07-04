/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 21:36:41 by prando-a          #+#    #+#             */
/*   Updated: 2024/06/10 21:36:41 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << GREEN << "Brain constructed \n" << RESET;
}

Brain::Brain(const Brain &Brain)
{
	std::cout << GREEN << "Brain copy constructor called \n" << RESET;
	*this = Brain;
}

Brain &Brain::operator=(const Brain &Brain)
{
	std::cout << GREEN " Brain copy assignment operator called \n" << RESET;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = Brain.ideas[i];
    return *this;
}

Brain::~Brain()
{
	std::cout << RED << "Brain destroyed \n" << RESET;
}