/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:23:05 by prando-a          #+#    #+#             */
/*   Updated: 2024/06/20 13:23:05 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_H
#define SHRUBBERY_H

#include <iostream>
#include "AForm.hpp"

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

class ShrubberyCreationForm : public AForm
{
	private:
		
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string name);
		ShrubberyCreationForm(const ShrubberyCreationForm &ShrubberyCreationForm);
		ShrubberyCreationForm&				operator=(const ShrubberyCreationForm&);
		virtual void						execute(Bureaucrat const & executor) const;
		~ShrubberyCreationForm();
};

#endif