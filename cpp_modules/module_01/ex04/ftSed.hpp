/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftSed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-12 10:52:45 by prando-a          #+#    #+#             */
/*   Updated: 2024-06-12 10:52:45 by prando-a         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTSED_H
#define FTSED_H

#include <iostream>
#include <fstream>
#include <cstring>
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


class ftSed
{
	public:
						ftSed(char*);
						~ftSed();
		void			ftReplace(char*, char*);
		std::fstream	infile;
    	std::fstream	outfile;
    	std::string		content;
};

#endif