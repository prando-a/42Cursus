/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:18:30 by prando-a          #+#    #+#             */
/*   Updated: 2024/06/19 18:18:30 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	std::cout << GREEN << "Bureaucrat constructor called\n" << RESET;
}

Bureaucrat::Bureaucrat(const Bureaucrat &Bureaucrat)
{
	std::cout << GREEN << "Bureaucrat copy constructor called\n" << RESET;
	*this = Bureaucrat;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name), grade(grade)
{
	std::cout << GREEN << "Bureaucrat constructor called\n" << RESET;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &Bureaucrat)
{
    std::cout << GREEN "Bureaucrat assignment operator called\n" << RESET;
    const_cast<std::string&>(this->name) = Bureaucrat.name; // (!) Const_cast is used to remove the constness of the object
	this->grade = Bureaucrat.grade;
    return *this;
}

std::string Bureaucrat::getName() const
{
	return (this->name);
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

void Bureaucrat::upGrade()
{
	if (this->grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
}

void Bureaucrat::downGrade()
{
	if (this->grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
}

void Bureaucrat::signForm(AForm &f)
{
	std::cout << GREEN;

	if (f.getIsSigned())
	{
		std::cout << "Form " << f.getName() << " was already signed" << RESET << "\n";
		return ;
	}
	try
	{
		f.beSigned(*this);
		std::cout << "Bureaucrat " << this->getName() << " signed " << f.getName() << " form\n";
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cout << "Bureaucrat " << this->getName() << " couldn't sign " << f.getName() << " form because " << e.what() << "\n";
	}
	std::cout << RESET;
}

void Bureaucrat::executeForm(AForm const &form)
{
	std::cout << GREEN;

	try
	{
		form.execute(*this);
		std::cout << GREEN;
		std::cout << "Bureaucrat " << this->getName() << " executed " << form.getName() << " form\n";
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cout << "Bureaucrat " << this->getName() << " couldn't execute " << form.getName() << " form because " << e.what() << "\n";
	}
	catch (const char *e)
	{
		std::cout << "Bureaucrat " << this->getName() << " couldn't execute " << form.getName() << " form because " << e << "\n";
	}

	std::cout << RESET;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << RED << "Bureaucrat destructor called\n" << RESET;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &Bureaucrat)
{
	out << GREEN << "Bureaucrat " << Bureaucrat.getName() << "! Grade " << Bureaucrat.getGrade() << RESET << "\n";
	return (out);
}