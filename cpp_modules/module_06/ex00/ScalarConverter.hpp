/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:47:52 by prando-a          #+#    #+#             */
/*   Updated: 2024/06/24 17:47:52 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_H
#define SCALAR_H

#include <iostream>
#include <cstdlib>
#include <cmath>

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

# define INVALID 0
# define NUM 1
# define FRAC 2


class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &ScalarConverter);
		ScalarConverter&				operator=(const ScalarConverter&);
		~ScalarConverter();
	public:
		static void convert(char *literal);
};

#endif