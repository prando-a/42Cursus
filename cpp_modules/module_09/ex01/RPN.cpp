/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-26 20:58:37 by prando-a          #+#    #+#             */
/*   Updated: 2024-08-26 20:58:37 by prando-a         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

std::stack<int>	&RPN::get_stack(void)
{
	return (this->stack);
}

int RPN::isoperator(int c)
{
	return	c == '+' || c == '-' ||
			c == '/' || c == '*' ;
}

int RPN::char_type(char c)
{
	if (c == ' ')
		return (SPACE);
	if (isdigit(c))
		return (NUM);
	if (this->isoperator(c))
		return (OPERATION);
	return (INVALID);
}

void RPN::make_operation(std::stack<int> &stack, int operator_)
{
	if (stack.size() < 2)
		this->error("FOUND OPERATION WITH TOO FEW ELEMENTS");
	int temp = stack.top();
	stack.pop();
	switch (operator_)
	{
		case '+':
			stack.top() += temp;
			break;
		case '-':
			stack.top() -= temp;
			break;
		case '*':
			stack.top() *= temp;
			break;
		case '/':
			if (temp == 0)
				this->error("DIVISION BY ZERO");
			stack.top() /= temp;
			break;
	}
}

int RPN::push_num(std::stack<int> &stack, char *num)
{
	if (atoi(num) >= 10)
		this->error("NUMBER TOO HIGH");
	stack.push(atoi(num));
	int skip = 0;
	for (int i = 0; isdigit(num[i]); i++)
	{
		skip++;
	}
	return (skip);
}

void RPN::error(std::string str)
{
	std::cerr << RED << "ERROR: " << str << "\n";
	exit(1);
}
RPN::RPN()
{

}

RPN::RPN(const RPN &RPN)
{
	std::cout << GREEN << "Copy constructor called\n" << RESET;
	*this = RPN;
}

RPN &RPN::operator=(const RPN &RPN)
{
    std::cout << GREEN "Copy assignment operator called\n" << RESET;
    this->stack = RPN.stack;
    return *this;
}

RPN::~RPN()
{
	
}