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
#include "Intern.hpp"

int test_intern()
{
	Intern intern;
	try
	{
		AForm *form;
		Bureaucrat a("Dolores", 1);

		form = intern.makeForm("shrubbery creation", "Ontos");
		a.signForm(*form);
		a.executeForm(*form);
		delete form;

		form = intern.makeForm("robotomy request", "Logos");
		a.signForm(*form);
		a.executeForm(*form);
		delete form;

		form = intern.makeForm("presidential pardon", "Pneuma");
		a.signForm(*form);
		a.executeForm(*form);
		delete form;

		form = intern.makeForm("unknown", "Unknown");
	}
	catch (std::exception &e)
		{ std::cerr << RED << e.what() << RESET << std::endl; return (1); }
	return (0);
}

int main()
{
	return (test_intern());
}