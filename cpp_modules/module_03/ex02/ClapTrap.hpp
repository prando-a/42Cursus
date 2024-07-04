/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 02:21:45 by prando-a          #+#    #+#             */
/*   Updated: 2024/05/23 02:21:45 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
#define CLAPTRAP_H

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


class ClapTrap
{
	protected:
		std::string		name;
		int				hitPoints;
		int				energyPoints;
		int				attackDamage;
	public:
		ClapTrap(std::string);
		ClapTrap(const ClapTrap &ClapTrap);
		ClapTrap&				operator=(const ClapTrap&);
		void	takeDamage(unsigned int);
		void	attack(const std::string&);
		void	beRepaired(unsigned int);
		~ClapTrap();
};

#endif