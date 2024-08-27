/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-26 21:13:07 by prando-a          #+#    #+#             */
/*   Updated: 2024-08-26 21:13:07 by prando-a         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_H
#define PMERGEME_H

#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <algorithm>
#include <limits>
#include <iterator>
#include <ctime>
#include <iomanip>

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

# define LIST	0
# define VECTOR	1

class PmergeMe
{
	private:
		std::vector<int>	vector;
		std::list<int>		list;
		double				time[2];
		size_t				size;
		int					ft_str_islf(char*);
		void				print_vector();
	public:
		std::vector<int>&	get_vector();
		std::list<int>&		get_list();
		void				add_num(char *);
		void				sort();
		void				sort_vector();
		void				sort_list();
		PmergeMe();
		PmergeMe(const PmergeMe &PmergeMe);
		PmergeMe&				operator=(const PmergeMe&);
		~PmergeMe();
};

#endif