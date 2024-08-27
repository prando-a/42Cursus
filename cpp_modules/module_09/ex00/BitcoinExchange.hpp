/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-27 16:24:43 by prando-a          #+#    #+#             */
/*   Updated: 2024-08-27 16:24:43 by prando-a         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#ifndef	BITCOINEXCHANGE_H
#define BITCOINEXCHANGE_H

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <iomanip>
#include <ctime>

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

class BitcoinExchange
{
	private:
		std::map <std::string, double>	map;
		void 							printInfo(long long, std::string);
	public:
		BitcoinExchange();
		void 							parse_file(char *);
		void 							printMap();
		BitcoinExchange(const BitcoinExchange &BitcoinExchange);
		BitcoinExchange&				operator=(const BitcoinExchange&);
		~BitcoinExchange();
};

#endif