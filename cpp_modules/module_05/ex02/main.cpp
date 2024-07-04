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
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int test_shrubbery()
{
	ShrubberyCreationForm form("home");
	try
	{
		Bureaucrat C("Charo", 140);
		std::cout << BLUE << "Before upgrade:" << std::endl;
		C.signForm(form);
		std::cout << C;
		for (int i = 0; i < 20; i++)
			C.upGrade();
		std::cout << BLUE << "After upgrade:" << std::endl;
		std::cout << C;
		C.signForm(form);
		C.executeForm(form);
	}
	catch (std::exception &e)
		{ std::cerr << RED << e.what() << RESET << std::endl; return (1); }
	return (0);
}

int test_robotomy()
{
	RobotomyRequestForm form("Funky Solution");
	try
	{
		Bureaucrat C("Mari Ángeles", 55);
		std::cout << BLUE << "Before upgrade:" << std::endl;
		std::cout << C;
		C.signForm(form);
		std::cout << C;
		for (int i = 0; i < 20; i++)
			C.upGrade();
		std::cout << BLUE << "After upgrade:" << std::endl;
		std::cout << C;
		C.signForm(form);
		C.executeForm(form);
	}
	catch (std::exception &e)
		{ std::cerr << RED << e.what() << RESET << std::endl; return (1); }
	return (0);
}

int test_presidential()
{
	PresidentialPardonForm form("Professional Problem");
	try
	{
		Bureaucrat C("Manoli", 25);
		std::cout << BLUE << "Before upgrade:" << std::endl;
		std::cout << C;
		C.signForm(form);
		C.executeForm(form);
		for (int i = 0; i < 20; i++)
			C.upGrade();
		std::cout << BLUE << "After upgrade:" << std::endl;
		std::cout << C;
		C.executeForm(form);
	}
	catch (std::exception &e)
		{ std::cerr << RED << e.what() << RESET << std::endl; return (1); }
	return (0);
}

int main()
{
	std::cout << "----------------------------------------" << std::endl;
	if (test_shrubbery())
		return (1);
	std::cout << "----------------------------------------" << std::endl;
	if (test_robotomy())
		return (1);
	std::cout << "----------------------------------------" << std::endl;
	if (test_presidential())
		return (1);
	return (0);
}