/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:37:11 by prando-a          #+#    #+#             */
/*   Updated: 2024/06/08 16:37:11 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_H
#define WRONG_ANIMAL_H

#include <iostream>

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


class WrongAnimal
{
	protected:
		std::string		_type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &WrongAnimal);
		WrongAnimal&			operator=(const WrongAnimal&);
		virtual ~WrongAnimal();
		std::string				getType() const;
		virtual void			makeSound() const;
};

#endif