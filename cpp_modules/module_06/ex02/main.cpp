/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:43:03 by prando-a          #+#    #+#             */
/*   Updated: 2024/07/01 15:43:03 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "baseUtils.hpp"

int main()
{
	Base *base = generate();
	std::cout << "Pointer: " << std::endl;
	identify(base);
	std::cout << "Reference: " << std::endl;
	identify(*base);
	delete base;
	return (0);
}