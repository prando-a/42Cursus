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

#include "RPN.hpp"

void error(std::string str)
{
	std::cerr << RED << "ERROR: " << str << "\n";
	exit(1);
}



int main(int argc, char **argv)
{
	RPN rpn;

	if (argc != 2 || !*argv[1]) error("WRONG ARG COUNT");

	std::stack<int> &stack = rpn.get_stack();
	char *str = argv[1];
	int len = strlen(str);

	for (int i = 0; i < len; i++)
	{
		switch (rpn.char_type(str[i]))
		{
			case SPACE:
				break;
			case NUM:
				i += rpn.push_num(stack, &str[i]);
				break;
			case OPERATION:
				rpn.make_operation(stack, str[i]);
				break;
			case INVALID:
				error("INVALID CHAR DETECTED");
		}
	}

	if (stack.size() > 1)
		error("NOT ENOUGH OPERATORS FOR PENDING NUMBERS");

	std::cout << GREEN << stack.top() << RESET << "\n";

	return (0);
}