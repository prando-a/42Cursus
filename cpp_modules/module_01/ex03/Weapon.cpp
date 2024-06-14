/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-12 10:52:25 by prando-a          #+#    #+#             */
/*   Updated: 2024-06-12 10:52:25 by prando-a         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string param)
{
	this->type = param;
}

void Weapon::setType(std::string param)
{
	this->type = param;
}

const std::string& Weapon::getType()
{
	return (this->type);
}