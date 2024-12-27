/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:14:59 by prando-a          #+#    #+#             */
/*   Updated: 2024/07/16 19:00:28 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
# define EASYFIND_H

#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T &t, int n)
{
	typename T::iterator i = t.begin();
	while (i != t.end())
	{
		if (*i == n)
			return i;
		i++;
	}
	throw "easyfind: Number not found";
}

#endif