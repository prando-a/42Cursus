/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-02 15:14:09 by prando-a          #+#    #+#             */
/*   Updated: 2024-07-02 15:14:09 by prando-a         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main() 
{
	std::vector<int> v;
	std::vector<int>::iterator it;

	for (int i = 0; i < 10; ++i) 
		v.push_back(i * i);
	std::cout << "Vector:" << std::endl;
	
	for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i) 
		std::cout << *i << std::endl;
	std::cout << std::endl;

	try
	{
		it = easyfind(v, 42);
		std::cout << "Found element! \n";
	}
	catch (const char *str)
	{
		std::cerr << str << "\n";
	}

	try
	{
		it = easyfind(v, 1);
		std::cout << "Found element! \n";
	}
	catch (const char *str)
	{
		std::cerr << str << "\n";
	}
}
