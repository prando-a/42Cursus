/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 22:50:41 by prando-a          #+#    #+#             */
/*   Updated: 2024/06/20 22:50:41 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << GREEN << "RobotomyRequestForm default constructor called\n" << RESET;
}

RobotomyRequestForm::RobotomyRequestForm(std::string name) : AForm(name, 72, 45)
{
	std::cout << GREEN << "RobotomyRequestForm constructor called\n" << RESET;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &RobotomyRequestForm) : AForm(RobotomyRequestForm)
{
	std::cout << GREEN << "RobotomyRequestForm copy constructor called\n" << RESET;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &s)
{
	if (this != &s)
	{
		AForm::operator=(s);
	}
    std::cout << GREEN "RobotomyRequestForm copy assignment operator called\n" << RESET;
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);
	std::cout << "\"rizzz, bzzzzzz, rizzz, bzzzzzz\"" << std::endl;
	srand(time(NULL));
	if (rand() % 2)
		std::cout << executor.getName() << " has been robotomized successfully\n";
	else
		std::cout << executor.getName() << " robotomization failed\n";
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << GREEN << "RobotomyRequestForm destructor called\n" << RESET;
}