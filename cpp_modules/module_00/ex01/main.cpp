/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 07:50:58 by prando-a          #+#    #+#             */
/*   Updated: 2024/04/06 07:50:58 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MyPhoneBook.hpp"

void	intro()
{
	std::cout << BLUE BOLD "Welcome to\n";
	std::cout << "                ___ _                        ___             _    " << "\n";
	std::cout << "  /\\/\\  _   _  / _ \\ |__   ___  _ __   ___  / __\\ ___   ___ | | __" << "\n";
	std::cout << " /    \\| | | |/ /_)/ '_ \\ / _ \\| '_ \\ / _ \\/__\\/// _ \\ / _ \\| |/ /" << "\n";
	std::cout << "/ /\\/\\ \\ |_| / ___/| | | | (_) | | | |  __/ \\/  \\ (_) | (_) |   < " << "\n";
	std::cout << "\\/    \\/\\__, \\/    |_| |_|\\___/|_| |_|\\___\\_____/\\___/ \\___/|_|\\_\\" << "\n";
	std::cout << "        |___/                                                    " << "\n\n" RESET;
}

int	main(void)
{
	std::string buffer;
	MyPhoneBook MyPhoneBook;

	intro();
	while ((std::cout << BOLD "phonebook" GREEN "$  " RESET)
		&& (std::cin >> buffer) && !(buffer == "EXIT"))
	{
		if (buffer == "ADD")
			MyPhoneBook.add();
		if (buffer == "SEARCH")
			MyPhoneBook.search();
	}
	return (std::cout << BLUE BOLD "So long, bye-bye!\n" RESET, 0);
}