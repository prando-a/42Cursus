/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 21:14:25 by prando-a          #+#    #+#             */
/*   Updated: 2024/07/01 21:14:25 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

int subjectTests( void ) {
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	std::cout << std::endl;
	return 0;
}

int main()
{
	std::cout << GREEN << std::endl;
	std::cout << "Testing with int" << std::endl;
	int n = 42;
	int n2 = 21;
	std::cout << "n = " << n << ", n2 = " << n2 << std::endl;
	swap(n, n2);
	std::cout << "After swap..." << std::endl;
	std::cout << "n = " << n << ", n2 = " << n2 << std::endl;
	std::cout << "min value is " << min(n, n2) << std::endl;
	std::cout << "max value is " << max(n, n2) << std::endl;

	std::cout << std::endl << "Testing with char" << std::endl;
	char c = 'a';
	char c2 = 'b';
	std::cout << "c = " << c << ", c2 = " << c2 << std::endl;
	swap(c, c2);
	std::cout << "After swap..." << std::endl;
	std::cout << "c = " << c << ", c2 = " << c2 << std::endl;
	std::cout << "min value is " << min(c, c2) << std::endl;
	std::cout << "max value is " << max(c, c2) << std::endl;

	std::cout << std::endl << "Testing with float" << std::endl;
	float f = 42.42f;
	float f2 = 21.21f;
	std::cout << "f = " << f << ", f2 = " << f2 << std::endl;
	swap(f, f2);
	std::cout << "After swap..." << std::endl;
	std::cout << "f = " << f << ", f2 = " << f2 << std::endl;
	std::cout << "min value is " << min(f, f2) << std::endl;
	std::cout << "max value is " << max(f, f2) << std::endl;

	std::cout << std::endl << "Testing with double" << std::endl;
	double d = 42.42;
	double d2 = 21.21;
	std::cout << "d = " << d << ", d2 = " << d2 << std::endl;
	swap(d, d2);
	std::cout << "After swap..." << std::endl;
	std::cout << "d = " << d << ", d2 = " << d2 << std::endl;
	std::cout << "min value is " << min(d, d2) << std::endl;
	std::cout << "max value is " << max(d, d2) << std::endl;

	std::cout << RESET << std::endl;

	std::cout << "Subject tests... \n" << std::endl;
	subjectTests();
	return 0;
}