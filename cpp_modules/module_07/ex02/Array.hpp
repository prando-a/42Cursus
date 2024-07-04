/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 22:58:23 by prando-a          #+#    #+#             */
/*   Updated: 2024/07/01 22:58:23 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

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

template <typename T>
class Array
{
	private:
		T* _array;
		unsigned int _size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& copy);
		Array& operator=(const Array& copy);
		T& operator[](unsigned int i);
		~Array();
		unsigned int size(void) const;
};

template <typename T>
Array<T>::Array()
{
	std::cout << GREEN << "Default Array constructor called\n" << RESET;
	_array = NULL;
	_size = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	std::cout << GREEN << "Array constructor called\n" << RESET;
	_array = new T[n](); // () initializes the array with 0, NULL, etc.
	_size = n;
}


template <typename T>
Array<T>::Array(const Array& copy) : _array(new T[copy._size]()), _size(copy._size)
{
	std::cout << GREEN << "Array copy constructor called\n" << RESET;
	for (int i = 0; i < (int)copy._size; i++)
		_array[i] = copy._array[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& copy)
{
	std::cout << GREEN << "Array copy assignment operator called\n" << RESET;
	if (this != &copy)
	{
		delete [] _array;
		_array = new T[copy._size]();
		_size = copy._size;
		for (int i = 0; i < (int)_size; i++)
			_array[i] = copy._array[i];
	}
	return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int i)
{
	if (i >= _size)
		throw std::out_of_range("Index out of range");
	return _array[i];
}


template <typename T>
Array<T>::~Array()
{
	std::cout << GREEN << "Array destructor called\n" << RESET;
	delete [] _array;
}

template <typename T>
unsigned int Array<T>::size(void) const
{
	return (_size);
}

#endif