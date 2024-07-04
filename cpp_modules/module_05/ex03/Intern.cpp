/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:35:49 by prando-a          #+#    #+#             */
/*   Updated: 2024/06/24 14:35:49 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cout << GREEN << "Intern default constructor called\n" << RESET;
}

Intern::Intern(const Intern &Intern)
{
	std::cout << GREEN << "Intern copy constructor called\n" << RESET;
	*this = Intern;
}

Intern &Intern::operator=(const Intern &Intern)
{
    std::cout << GREEN "Intern copy assignment operator called\n" << RESET;
	(void)Intern;
    return *this;
}

// I would kindly ask why this is better than an ifelse statement

AForm *new_shrubbery(const std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm *new_robotomy(const std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm *new_presidential(const std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string name, std::string target)
{
	std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	typedef AForm *(*constructor)(const std::string);
	constructor constructors[3] = {&new_shrubbery, &new_robotomy, &new_presidential};

	for (int i = 0; i < 3; i++)
	{
		if (name == formNames[i])
		{
			std::cout << GREEN << "Intern creates " << name << " form\n" << RESET;
			return constructors[i](target);
		}
	}
	std::cout << RED << "Intern cannot create " << name << " form\n" << RESET;
	return (NULL);
}

Intern::~Intern()
{
	std::cout << GREEN << "Intern destructor called\n" << RESET;
}
