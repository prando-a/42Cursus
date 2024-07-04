/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 00:50:48 by prando-a          #+#    #+#             */
/*   Updated: 2024/07/01 00:50:48 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main(void)
{
	Data data;
	data.str = "Aionios";
	std::cout << GREEN << "Data address: " << &data << std::endl;
	std::cout << GREEN << "Data string: " << data.str << std::endl;
	uintptr_t raw = Serializer::serialize(&data);
	std::cout << GREEN << "Raw address: " << raw << std::endl;
	Data *other = Serializer::deserialize(raw);
	std::cout << GREEN << "Deserialized address: " << other << std::endl;
	std::cout << GREEN << "Deserialized string: " << other->str << std::endl;
	std::cout << "Modifying deserialized string..." << std::endl;
	other->str = "Conduit";
	std::cout << GREEN << "Data string after modifying Serialized: " << data.str << std::endl;
	std::cout << RESET;
	return (0);
}