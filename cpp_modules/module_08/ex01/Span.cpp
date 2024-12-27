/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:41:40 by prando-a          #+#    #+#             */
/*   Updated: 2024/07/16 19:41:40 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{
	std::cout << GREEN << "Default constructor called\n" << RESET;
	this->_N = 0;
	this->_data = std::vector<int>();
}

Span::Span(int N)
{
	std::cout << GREEN << "Parametric constructor called\n" << RESET;
	this->_N = N;
	this->_data = std::vector<int>();
}

Span::~Span()
{
	std::cout << RED << "Destructor called\n" << RESET;
}

Span::Span(const Span &Span) : _N(Span._N), _data(Span._data)
{
	std::cout << GREEN << "Copy constructor called\n" << RESET;
}

Span &Span::operator=(const Span &Span)
{
    std::cout << GREEN "Copy assignment operator called\n" << RESET;
	this->_N = Span._N;
	this->_data = Span._data;
    return *this;
}

void Span::addNumber(int N)
{
	if ((int)this->_data.size() < this->_N)
		this->_data.push_back(N);
	else
		throw std::logic_error("Span is full, element was not added!");
}

int Span::shortestSpan()
{
	if (this->_data.size() < 2)
		throw std::logic_error("Not enough elements to calculate the shortest span!");

	std::vector<int> sortedData = this->_data;
	std::sort(sortedData.begin(), sortedData.end());

	int minSpan = INT_MAX;
	for (size_t i = 0; i < sortedData.size() - 1; ++i)
	{
		int currentSpan = sortedData[i + 1] - sortedData[i];
		if (currentSpan < minSpan)
		{
			minSpan = currentSpan;
		}
    }
    return minSpan;
}

int Span::longestSpan()
{
	if (this->_data.size() < 2)
		throw std::logic_error("Not enough elements to calculate the longest span!");
	
	return *std::max_element(this->_data.begin(), this->_data.end())
		- *std::min_element(this->_data.begin(), this->_data.end());
}



void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	std::vector<int>::iterator copy = begin;
	int size = 0;
	while (copy != end)
	{
		size++;
		copy++;
	}
	if (size + (int)this->_data.size() > this->_N)
		throw std::logic_error("Span is full, elements were not added!");
	
	while (begin != end)
	{
		this->addNumber(*begin);
		begin++;
	}
}