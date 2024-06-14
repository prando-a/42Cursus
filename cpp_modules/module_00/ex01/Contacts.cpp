/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-12 18:27:08 by prando-a          #+#    #+#             */
/*   Updated: 2024-06-12 18:27:08 by prando-a         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "Contacts.hpp"

void Contacts::write_data(Contacts& contact, int index)
{
	std::cin >> contact.field[index];
}

void Contacts::PrintContactField(std::string field)
{
	int j = field.size();
	while (j++ < 10)
		std::cout << ' ';
	if (field.size() > 10)
	{
		int i = 0;
		while (i < 9)
			std::cout << (char)field[i++];
		std::cout << '.';
	}
	else
		std::cout << field;
	std::cout << BLUE "|" RESET;
}

void Contacts::PrintContactList(Contacts contact)
{
	if (!contact.field[FIRST_NAME].empty())
	{
		std::cout << BLUE "|" RESET;
		PrintContactField(contact.field[FIRST_NAME]);
		PrintContactField(contact.field[LAST_NAME]);
		PrintContactField(contact.field[NICKNAME]);
		PrintContactField(contact.field[PHONE_NUMBER]);
	}
	std::cout << "\n";
}

void Contacts::print_contact(Contacts contact)
{
	if (!contact.field[FIRST_NAME].empty())
	{
		std::cout << BOLD GREEN;
		std::cout << contact.field[FIRST_NAME] << "\n";
		std::cout << contact.field[LAST_NAME] << "\n";
		std::cout << contact.field[NICKNAME] << "\n";
		std::cout << contact.field[PHONE_NUMBER] << "\n";
		std::cout << RESET;
	}
	else
		std::cout << RED BOLD "ERROR\n" RESET <<
		RED "Empty contact slot" RESET << "\n";
}