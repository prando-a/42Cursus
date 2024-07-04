/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 22:50:41 by prando-a          #+#    #+#             */
/*   Updated: 2024/06/20 22:50:41 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5)
{
	std::cout << GREEN << "PresidentialPardonForm default constructor called\n" << RESET;
}

PresidentialPardonForm::PresidentialPardonForm(std::string name) : AForm(name, 25, 5)
{
	std::cout << GREEN << "PresidentialPardonForm constructor called\n" << RESET;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &PresidentialPardonForm) : AForm(PresidentialPardonForm)
{
	std::cout << GREEN << "PresidentialPardonForm copy constructor called\n" << RESET;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &s)
{
	if (this != &s)
	{
		AForm::operator=(s);
	}
    std::cout << GREEN "PresidentialPardonForm copy assignment operator called\n" << RESET;
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);
	std::cout << "I, Zaphod Beeblebrox, grant you the pardon. Then you, " << executor.getName() << ", are pardoned" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << GREEN << "PresidentialPardonForm destructor called\n" << RESET;
}