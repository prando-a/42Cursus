/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:00:31 by prando-a          #+#    #+#             */
/*   Updated: 2024/06/20 12:00:31 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm() : name("default"), sigGrade(1), execGrade(1)
{
	std::cout << GREEN << "AForm constructor called\n" << RESET;
	this->isSigned = false;
}

AForm::AForm(const AForm &AForm) : name(AForm.name), sigGrade(AForm.sigGrade), execGrade(AForm.execGrade)
{
	std::cout << GREEN << "AForm copy constructor called\n" << RESET;
}

AForm::AForm(const std::string name, int sigGrade, int execGrade) : name(name), sigGrade(sigGrade), execGrade(execGrade)
{
	std::cout << GREEN << "AForm constructor called\n" << RESET;
	if (execGrade < 1 || sigGrade < 1)
		throw AForm::GradeTooHighException();
	else if (execGrade > 150 || sigGrade > 150)
		throw AForm::GradeTooLowException();
	this->isSigned = false;
}

AForm &AForm::operator=(const AForm &AForm)
{
    std::cout << GREEN "AForm assignment operator called\n" << RESET;
    const_cast<std::string&>(this->name) = AForm.name; // (!) Const_cast is used to remove the constness of the object
	const_cast<int&>(this->sigGrade) = AForm.sigGrade;
	const_cast<int&>(this->execGrade) = AForm.execGrade;
	this->isSigned = AForm.isSigned;
    return *this;
}

std::string AForm::getName() const
{
	return (this->name);
}

int AForm::getSigGrade() const
{
	return (this->sigGrade);
}

int AForm::getExecGrade() const
{
	return (this->execGrade);
}

bool AForm::getIsSigned() const
{
	return (this->isSigned);
}

void AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > this->sigGrade)
		throw AForm::GradeTooLowException();
	this->isSigned = true;
}

AForm::~AForm()
{
	std::cout << RED << "AForm destructor called\n" << RESET;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->execGrade)
		throw AForm::GradeTooLowException();
	if (!this->isSigned)
		throw "Form is not signed";
}

std::ostream &operator<<(std::ostream &out, const AForm &AForm)
{
	out << GREEN;
	out << "Form name: " << AForm.getName();
	out << " | Signature grade: " << AForm.getSigGrade();
	out << " | Execution grade: " << AForm.getExecGrade();
	if (AForm.getIsSigned())
		out << " | Form is signed";
	else
		out << " | Form is not signed";
	out << "\n";
	out << RESET;
	return (out);
}
