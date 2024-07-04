/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 21:37:10 by prando-a          #+#    #+#             */
/*   Updated: 2024/07/01 21:37:10 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

int main()
{
	char str[6] = "Hello";
	int tab[5] = { 0, 1, 2, 3, 4 };

	std::cout << "Testing with string" << std::endl;
	iter(str, 5, print);
	std::cout << "Before increment: " << str << std::endl;
	iter(str, 5, increment);
	std::cout << "After increment: " << str << std::endl;

	std::cout << "Testing with int array" << std::endl;
	std::cout << "Before increment: " << std::endl;
	iter(tab, 5, print);
	iter(tab, 5, increment);
	std::cout << "After increment: " << std::endl;
	iter(tab, 5, print);
	return 0;
}