/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:09:35 by prando-a          #+#    #+#             */
/*   Updated: 2024/07/16 11:09:35 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void testSubject()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void myTest()
{
	Span sp = Span(20000);
	for (int i = 0; i < 20000; i++)
	{
		sp.addNumber(i);
	}
	try 
	{
		sp.addNumber(1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	Span sp2 = Span(1);
	sp2.addNumber(1);
	try
	{
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	Span sp3 = Span(20);
	std::vector<int> v;
	for (int i = 0; i < 30; i++)
	{
		v.push_back(i * i);
	}
	std::vector<int>::iterator it = v.begin();
	std::vector<int>::iterator it2 = it + 20;
	try
	{
		sp3.addRange(it, it2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "SP3 longest span: " << sp3.longestSpan() << std::endl;

}

int main()
{
	testSubject();
	myTest();
	return 0;
}