/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 01:10:09 by prando-a          #+#    #+#             */
/*   Updated: 2024/07/01 01:10:09 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << GREEN << "Default constructor called\n" << RESET;
}

Serializer::Serializer(const Serializer &Serializer)
{
	std::cout << GREEN << "Copy constructor called\n" << RESET;
	(void)Serializer;
}

Serializer &Serializer::operator=(const Serializer &Serializer)
{
    std::cout << GREEN "Copy assignment operator called\n" << RESET;
    (void)Serializer;
	return *this;
}

Serializer::~Serializer()
{
	std::cout << RED << "Destructor called\n" << RESET;
}


uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
	return raw;
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data* ptr = reinterpret_cast<Data*>(raw);
	return ptr;
}