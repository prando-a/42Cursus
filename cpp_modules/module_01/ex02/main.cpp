/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-12 10:51:48 by prando-a          #+#    #+#             */
/*   Updated: 2024-06-12 10:51:48 by prando-a         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string string = "HI THIS IS BRAIN";

	std::string *stringPTR = &string;

	std::string &stringREF = string;

	std::cout << "Printing addresses (&) of:" << "\n";
	std::cout << "string: " << &string << "\n";
	std::cout << "stringPTR: " << &stringPTR << "\n";
	std::cout << "stringREF: " << &stringREF << "\n";

	std::cout << "\nPrinting values of:" << "\n";
	std::cout << "string: " << string << "\n";
	std::cout << "stringPTR: " << *stringPTR << "\n";
	std::cout << "stringREF: " << stringREF << "\n";

	return (0);
}