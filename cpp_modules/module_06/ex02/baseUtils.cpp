/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   baseUtils.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:44:08 by prando-a          #+#    #+#             */
/*   Updated: 2024/07/01 15:44:08 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "baseUtils.hpp"

Base *generate(void)
{
	srand(time(NULL));
	switch (rand() % 3)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
	}
	return (NULL);
}

void identify(Base *p)
{
	std::cout << GREEN << "Class* is: ";
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << RED << "Unknown" << std::endl;
	std::cout << RESET;
}

void identify(Base &p)
{
	std::cout << GREEN << "Class& is: ";
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch (const std::exception &e)
	{
		try
		{
			B &b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << "B" << std::endl;
		}
		catch (const std::exception &e)
		{
			try
			{
				C &c = dynamic_cast<C&>(p);
				(void)c;
				std::cout << "C" << std::endl;
			}
			catch (const std::exception &e)
			{
				std::cout << RED << "Unknown" << std::endl;
			}
		}
	}
	std::cout << RESET;
}