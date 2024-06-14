/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 23:23:27 by prando-a          #+#    #+#             */
/*   Updated: 2024/04/05 23:23:27 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
	int i = 0;
	if (argc == 1)
		return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n", 0);
	while (argv[++i])
	{
		int j = -1;
		while (argv[i][++j])
			std::cout << (char)toupper(argv[i][j]);
		std::cout << ' ';
	}
	return (std::cout << "\n", 0);
}