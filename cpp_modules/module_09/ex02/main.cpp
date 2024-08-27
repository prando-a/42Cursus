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

#include "PmergeMe.hpp"

void error(std::string str)
{
	std::cerr << RED << "ERROR: " << str << "\n";
	exit(1);
}

int main(int argc, char **argv)
{
	if (argc < 3) error("WRONG ARG COUNT");

	PmergeMe			merge;

	for (int i = 1; argv[i]; i++)
	{
		try
		{
			merge.add_num(argv[i]);
		}
		catch(const char *what)
		{
			std::cerr << what << '\n';
			return (1);
		}
	}

	merge.sort();
	
	return (0);
}