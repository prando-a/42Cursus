/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:18:45 by prando-a          #+#    #+#             */
/*   Updated: 2024/06/19 14:18:45 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
		{ Bureaucrat b("Manuela", 1); }
	catch (std::exception &e)
		{ std::cerr << RED << e.what() << RESET << std::endl; return (1); }


	try
	{
		Bureaucrat b1("Pepe", 20);
		Bureaucrat b2(b1);
		Bureaucrat b3 = b1;

		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
		std::cout << b3 << std::endl;
	}
	catch (std::exception &e)
		{ std::cerr << RED << e.what() << RESET << std::endl; return (1); }
	

	try
	{
		Bureaucrat C("Charo", 150);
		std::cout << BLUE << "Before upgrade:" << std::endl;
		std::cout << C << std::endl;
		for (int i = 0; i < 20; i++)
			C.upGrade();
		std::cout << BLUE << "After upgrade:" << std::endl;
		std::cout << C << std::endl;
	}
	catch (std::exception &e)
		{ std::cerr << RED << e.what() << RESET << std::endl; return (1); }
	

	try
	{
		Bureaucrat C("Manoli", 20);
		std::cout << BLUE << "Before downgrade:" << std::endl;
		std::cout << C << std::endl;
		for (int i = 0; i < 20; i++)
			C.downGrade();
		std::cout << BLUE << "After downgrade:" << std::endl;
		std::cout << C << std::endl;
	}
	catch (std::exception &e)
		{ std::cerr << RED << e.what() << RESET << std::endl; return (1); }

	return (0);
}