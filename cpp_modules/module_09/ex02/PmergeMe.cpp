/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-26 21:13:05 by prando-a          #+#    #+#             */
/*   Updated: 2024-08-26 21:13:05 by prando-a         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<int>& PmergeMe::get_vector()
{
	return (this->vector);
}

std::list<int>& PmergeMe::get_list()
{
	return (this->list);
}

void PmergeMe::print_vector()
{
	size_t times = 0;

	if (this->size <= 5)
		times = this->size;
	else
		times = 4;

	std::cout << GREEN;
	for (size_t i = 0; i < times; i++)
	{
		std::cout << vector[i] << " ";
	}
	std::cout << RESET;

	if (this->size > 5)
		std::cout << "[...]";

	std::cout << std::endl;
}

int	float_checker(char *str, int *i, int *check)
{
	int	sym_lock;

	sym_lock = 0;
	while (str[*i])
	{
		if (str[*i] == '.')
		{
			if (sym_lock++ == 0 && str[*i + 1] >= '0' && str[*i + 1] <= '9')
				(*check)++;
		}
		if (str[*i] >= '0' && str[*i] <= '9')
			(*check)++;
		(*i)++;
	}
	return (sym_lock && (*check == *i));
}

int	PmergeMe::ft_str_islf(char *str)
{
	int	i;
	int	check;
	int	sym_lock;

	i = -1;
	check = 0;
	sym_lock = 0;
	if (!*str)
		return (0);
	while (str[++i] && str[i] != '.')
	{
		if (str[0] == '-' || str[0] == '+')
		{
			if (sym_lock++ == 0 && str[i + 1] >= '0' && str[i + 1] <= '9')
				check++;
		}
		if (str[i] >= '0' && str[i] <= '9')
			check++;
	}
	if (check == 0)
		return (0);
	return (float_checker(str, &i, &check) + (check == i));
}

void PmergeMe::add_num(char *literal)
{
	if (!this->ft_str_islf(literal) )
		throw "WRONG ARGUMENT DETECTED";
	long long num = atoll(literal);
	if (num > std::numeric_limits<int>::max() || num < 0)
		throw "WRONG VALUE DETECTED";
	vector.push_back(num);
	list.push_back(num);
	this->size++;
}

void PmergeMe::sort_vector(void)
{
	clock_t start = clock();

	std::vector<std::vector<int> > matrix;

	for (size_t i = 0; i < this->size; i += 2)
	{
		std::vector<int> sub;
		sub.push_back(this->vector[i]);
		if (i + 1 != size)
			sub.push_back(this->vector[i + 1]);
		matrix.push_back(sub);
	}

	for (size_t i = 0; i < matrix.size(); i++)
	{
		if (matrix[i].size() == 2 && matrix[i][0] > matrix[i][1])
			std::swap(matrix[i][0], matrix[i][1]);
	}

	while (matrix.size() > 1)
	{
		size_t i = 0;
		size_t j = 0;
		std::vector<int> temp;

		while (i < matrix[0].size() && j < matrix[1].size())
		{
			if (matrix[0][i] < matrix[1][j])
				temp.push_back(matrix[0][i++]);
			else
				temp.push_back(matrix[1][j++]);
		}
		while (i < matrix[0].size())
			temp.push_back(matrix[0][i++]);
		while (j < matrix[1].size())
			temp.push_back(matrix[1][j++]);
		matrix.erase(matrix.begin());
		matrix.erase(matrix.begin());
		matrix.push_back(temp);
	}
	this->vector = matrix[0];

	clock_t end = clock();
	this->time[VECTOR] = (static_cast<double>(end - start) / CLOCKS_PER_SEC) * 10;
}

void PmergeMe::sort_list()
{
	clock_t start = clock();

	std::list< std::list<int> >matrix;

	for (std::list<int>::iterator it = this->list.begin(); it != this->list.end(); )
	{
		std::list<int> sub;
		sub.push_back(*it);
		it++;
		if (it != this->list.end())
		{
			sub.push_back(*it);
			it++;
		}
		matrix.push_back(sub);
	}

	for (std::list< std::list<int> >::iterator it = matrix.begin(); it != matrix.end(); it++)
	{
		(*it).sort();
	}

	while (matrix.size() > 1)
    {
        std::list< std::list<int> >::iterator i = matrix.begin();
        std::list< std::list<int> >::iterator j = i;
		j++;
        std::list<int> temp;
        std::merge(i->begin(), i->end(), j->begin(), j->end(), std::back_inserter(temp));
   	 j = matrix.erase(j);
		matrix.erase(i);
		matrix.push_back(temp);
	}

	this->list = matrix.front();
	clock_t end = clock();
	this->time[LIST] = (static_cast<double>(end - start) / CLOCKS_PER_SEC) * 10;
}

void PmergeMe::sort()
{
	std::cout << "Before:\t" ;
	this->print_vector();
	this->sort_list();
	this->sort_vector();
	std::cout << "After:\t" ;
	this->print_vector();
	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << this->size << " elements with std::list   :   " ;
	std::cout << GREEN << time[LIST] << RESET << " us\n";
	std::cout << "Time to process a range of " << this->size << " elements with std::vector :   " ;
	std::cout << GREEN << time[VECTOR] << RESET << " us\n";
	
}

PmergeMe::PmergeMe()
{
	size = 0;
	time[LIST] = 0;
	time[VECTOR] = 0;
}

PmergeMe::PmergeMe(const PmergeMe &PmergeMe)
{
	std::cout << GREEN << "Copy constructor called\n" << RESET;
	*this = PmergeMe;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &PmergeMe)
{
    std::cout << GREEN "Copy assignment operator called\n" << RESET;
    this->vector = PmergeMe.vector;
	this->list = PmergeMe.list;
	this->size = PmergeMe.size;
    return *this;
}

PmergeMe::~PmergeMe()
{

}