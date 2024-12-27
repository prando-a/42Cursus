/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:46:29 by prando-a          #+#    #+#             */
/*   Updated: 2024/07/16 19:46:29 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

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

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(const MutantStack &to_copy);
		MutantStack &operator=(const MutantStack& to_copy);
		~MutantStack();

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin();
		iterator end();	
};

template<typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
	std::cout << GREEN << "MutantStack Default constructor called" << RESET << std::endl;
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &to_copy) : std::stack<T>(to_copy)
{
	std::cout << GREEN << "MutantStack Copy constructor called" << RESET << std::endl;
}

template<typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T>& to_copy)
{
	std::cout << GREEN << "MutantStack Assignation operator called" << RESET << std::endl;
	if (this == &to_copy)
		return (*this);
	std::stack<T>::operator=(to_copy);
	return (*this);
}

template<typename T>
MutantStack<T>::~MutantStack()
{
	std::cout << RED << "MutantStack Destructor called" << RESET << std::endl;
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (this->c.begin());
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return (this->c.end());
}


#endif