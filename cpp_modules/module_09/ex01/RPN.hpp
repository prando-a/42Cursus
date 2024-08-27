/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-26 15:18:18 by prando-a          #+#    #+#             */
/*   Updated: 2024-08-26 15:18:18 by prando-a         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#ifndef FOO_H
#define FOO_H

#include <iostream>
#include <stack>
#include <cstring>
#include <cctype>
#include <cstdlib>

# define INVALID	0
# define SPACE		1
# define NUM		2
# define OPERATION	3

# define RED     	"\x1b[31m"
# define GREEN   	"\x1b[32m"
# define RESET   	"\x1b[0m"

class RPN
{
	private:
		std::stack<int> stack;
		int				isoperator(int);
		void			error(std::string);
	public:
		std::stack<int>	&get_stack();
		int				char_type(char);
		void			make_operation(std::stack<int>&, int);
		int				push_num(std::stack<int>&, char *);
		RPN();
		RPN(const RPN &RPN);
		RPN&			operator=(const RPN&);
		~RPN();
};

#endif