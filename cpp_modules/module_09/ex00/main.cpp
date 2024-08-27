/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-26 15:12:15 by prando-a          #+#    #+#             */
/*   Updated: 2024-08-26 15:12:15 by prando-a         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void error(std::string str)
{
	std::cerr << RED << "ERROR: " << str << "\n";
	exit(1);
}

int main(int argc, char **argv)
{
	if (argc != 2) error("could not open file.");

	try
	{
		BitcoinExchange exchange;
		exchange.parse_file(argv[1]);
	}
	catch(const char *e)
	{
		error(e);
	}
	
	//exchange.printMap();

	return (0);
}