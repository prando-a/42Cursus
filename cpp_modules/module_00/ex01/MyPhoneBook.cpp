/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyPhoneBook.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-12 18:27:26 by prando-a          #+#    #+#             */
/*   Updated: 2024-06-12 18:27:26 by prando-a         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "MyPhoneBook.hpp"

void MyPhoneBook::add()
{
	static int i;

	if (i == 8)
		i = 0;
	std::cout << BOLD "Enter first name: " RESET;
	this->contact[i].write_data(this->contact[i], FIRST_NAME);
	std::cout << BOLD "Enter last name: " RESET;
	this->contact[i].write_data(this->contact[i], LAST_NAME);
	std::cout << BOLD "Enter nickname: " RESET;
	this->contact[i].write_data(this->contact[i], NICKNAME);
	std::cout << BOLD "Enter phone number: " RESET;
	this->contact[i].write_data(this->contact[i], PHONE_NUMBER);
	std::cout << BOLD "Enter his/her darkest secret...: " RESET;
	this->contact[i].write_data(this->contact[i], DARKEST_SECRET);
	std::cout << GREEN;
	std::cout << "Added contact in slot " << ++i << "\n" << RESET;
}

void MyPhoneBook::search()
{
	int i = -1;
	while (++i < 8)
	{
		std::cout << i + 1 << ".  ";
		this->contact[i].PrintContactList(this->contact[i]);
	}
	std::string buffer;
	std::cout << BOLD "\nEnter contact number to expand (1-8): " RESET;
	std::cin >> buffer;
	if (atoi(buffer.c_str()) >= 1 && atoi(buffer.c_str()) <= 8)
			this->contact[0].print_contact(this->contact[atoi(buffer.c_str()) - 1]);
		else
			std::cout << RED BOLD "Error:\n" RESET
			<< RED "Invalid data or number out of range\n" RESET;
}
