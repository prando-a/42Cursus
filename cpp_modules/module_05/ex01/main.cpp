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
#include "Form.hpp"

int main()
{
	Form h("Hacienda", 20, 20);
	std ::cout << h << RESET << std::endl;

	try
	{
		Bureaucrat C("Charo", 21);
		std::cout << BLUE << "Before upgrade:" << std::endl;
		std::cout << C << std::endl;
		try
		{
			C.signForm(h);
		}
		catch(const std::exception& e) {}

		for (int i = 0; i < 20; i++)
			C.upGrade();
		std::cout << BLUE << "After upgrade:" << std::endl;
		std::cout << C << std::endl;
		try
		{
			C.signForm(h);
		}
		catch(const std::exception& e) {}
		std::cout << h << std::endl;
	}
	catch (std::exception &e)
		{ std::cerr << RED << e.what() << RESET << std::endl; return (1); }

	return (0);
}