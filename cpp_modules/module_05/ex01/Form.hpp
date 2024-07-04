/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 22:37:17 by prando-a          #+#    #+#             */
/*   Updated: 2024/06/19 22:37:17 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
#define FORM_H

#include <iostream>
#include <stdexcept>

# define RED     	"\x1b[31m"
# define GREEN   	"\x1b[32m"
# define YELLOW  	"\x1b[33m"
# define BLUE    	"\x1b[34m"
# define MAGENTA	"\x1b[35m"
# define CYAN    	"\x1b[36m"
# define WHITE		"\033[37m"
# define BOLD		"\033[1m"
# define RESET   	"\x1b[0m"
# define CLEAR		"\033[2J"

class Bureaucrat;

class Form
{
	private:
		const std::string	name;
		bool				isSigned;
		const int			sigGrade;
		const int			execGrade;
	public:
		Form();
		Form(const Form &Form);
		Form(const std::string name, int execGrade, int sigGrade);
		Form&					operator=(const Form&);
		std::string				getName() const;
		int 					getSigGrade() const;
		int 					getExecGrade() const;
		bool					getIsSigned() const;
		void 					beSigned(Bureaucrat &b);
		~Form();

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Grade is too high");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Grade is too low");
				}
		};
		
};

std::ostream &operator<<(std::ostream &out, const Form &Form);

#endif