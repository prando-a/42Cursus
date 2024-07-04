/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 22:50:41 by prando-a          #+#    #+#             */
/*   Updated: 2024/06/20 22:50:41 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << GREEN << "ShrubberyCreationForm default constructor called\n" << RESET;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name) : AForm(name, 145, 137)
{
	std::cout << GREEN << "ShrubberyCreationForm constructor called\n" << RESET;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &ShrubberyCreationForm) : AForm(ShrubberyCreationForm)
{
	std::cout << GREEN << "ShrubberyCreationForm copy constructor called\n" << RESET;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &s)
{
	if (this != &s)
	{
		AForm::operator=(s);
	}
    std::cout << GREEN "ShrubberyCreationForm copy assignment operator called\n" << RESET;
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);
	std::ofstream	file;
	std::string		name = this->getName() + "_shrubbery";

	file.open(name.c_str());

	// https://ascii.co.uk/art/tree
	file << "     ccee88oo\n";
	file << "  C8O8O8Q8PoOb o8oo\n";
	file << " dOB69QO8PdUOpugoO9bD\n";
	file << "CgggbU8OU qOp qOdoUOdcb\n";
	file << "    6OuU  /p u gcoUodpP\n";
	file << "      \\\\\\//  /douUP\n";
	file << "        \\\\\\////\n";
	file << "         |||/\\\n";
	file << "        |||\\/\n";
	file << "         |||||\n";
	file << "   .....//||||\\....\n";

	file.close();

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << GREEN << "ShrubberyCreationForm destructor called\n" << RESET;
}