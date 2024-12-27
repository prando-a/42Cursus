/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:17:25 by prando-a          #+#    #+#             */
/*   Updated: 2024/07/08 14:17:25 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

# define RED     	"\x1b[31m"
# define GREEN   	"\x1b[32m"
# define YELLOW  	"\x1b[33m"
# define BLUE    	"\x1b[34m"
# define MAGENTA	"\x1b[35m"
# define CYAN    	"\x1b[36m"
# define WHITE		"\033[37m"
# define BOLD		"\033[1m"
# define RESET   	"\x1b[0m"
# define CLEAR		"\033[2J"


class Span
{
	private:
		int _N;
		std::vector<int> _data;
	public:
		Span();
		Span(const Span &Span);
		Span(int N);
		Span&				operator=(const Span&);
		void				addNumber(int N);
		int					shortestSpan();
		int					longestSpan();
		void				addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		~Span();
};

#endif