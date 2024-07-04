/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 21:40:53 by prando-a          #+#    #+#             */
/*   Updated: 2024/07/01 21:40:53 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template <typename T>
void	iter(T *arr, size_t length, void (*function)(T&))
{
	for (size_t i = 0; i < length; i++)
		function(arr[i]);
}

// Iter functions examples

template <typename T>
void	print(T& elem)
{
	std::cout << elem << std::endl;
}

template <typename T>
void	increment(T& elem)
{
	elem++;
}

#endif