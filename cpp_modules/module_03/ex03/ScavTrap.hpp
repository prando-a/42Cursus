/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 03:11:21 by prando-a          #+#    #+#             */
/*   Updated: 2024/05/23 03:11:21 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"

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



class ScavTrap : virtual public ClapTrap
{
	private:
	public:
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap&);
		ScavTrap&	operator=(const ScavTrap&);
		void		takeDamage(unsigned int);
		void		attack(const std::string&);
		void		beRepaired(unsigned int);
		void		guardGate();
		~ScavTrap();
};

#endif