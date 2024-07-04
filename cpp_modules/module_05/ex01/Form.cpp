/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:00:31 by prando-a          #+#    #+#             */
/*   Updated: 2024/06/20 12:00:31 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form() : name("default"), sigGrade(1), execGrade(1)
{
	std::cout << GREEN << "Form constructor called\n" << RESET;
	this->isSigned = false;
}

Form::Form(const Form &Form) : name(Form.name), sigGrade(Form.sigGrade), execGrade(Form.execGrade)
{
	std::cout << GREEN << "Form copy constructor called\n" << RESET;
}

Form::Form(const std::string name, int execGrade, int sigGrade) : name(name), sigGrade(sigGrade), execGrade(execGrade)
{
	std::cout << GREEN << "Form constructor called\n" << RESET;
	if (execGrade < 1 || sigGrade < 1)
		throw Form::GradeTooHighException();
	else if (execGrade > 150 || sigGrade > 150)
		throw Form::GradeTooLowException();
	this->isSigned = false;
}

Form &Form::operator=(const Form &Form)
{
    std::cout << GREEN "Form assignment operator called\n" << RESET;
    const_cast<std::string&>(this->name) = Form.name; // (!) Const_cast is used to remove the constness of the object
	const_cast<int&>(this->sigGrade) = Form.sigGrade;
	const_cast<int&>(this->execGrade) = Form.execGrade;
	this->isSigned = Form.isSigned;
    return *this;
}

std::string Form::getName() const
{
	return (this->name);
}

int Form::getSigGrade() const
{
	return (this->sigGrade);
}

int Form::getExecGrade() const
{
	return (this->execGrade);
}

bool Form::getIsSigned() const
{
	return (this->isSigned);
}

void Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > this->sigGrade)
		throw Form::GradeTooLowException();
	this->isSigned = true;
}

Form::~Form()
{
	std::cout << RED << "Form destructor called\n" << RESET;
}

std::ostream &operator<<(std::ostream &out, const Form &Form)
{
	out << GREEN;
	out << "Form name: " << Form.getName();
	out << " | Signature grade: " << Form.getSigGrade();
	out << " | Execution grade: " << Form.getExecGrade();
	if (Form.getIsSigned())
		out << " | Form is signed";
	else
		out << " | Form is not signed";
	out << "\n";
	out << RESET;
	return (out);
}