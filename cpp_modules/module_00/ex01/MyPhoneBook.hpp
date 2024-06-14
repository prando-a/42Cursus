/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyPhoneBook.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 07:51:23 by prando-a          #+#    #+#             */
/*   Updated: 2024/04/06 07:51:23 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYPHONEBOOK_H
#define MYPHONEBOOK_H

#include <iostream>
#include <cstdlib>
#include "Contacts.hpp"

class MyPhoneBook
{
	private:
		Contacts	contact[8];
	public:
		MyPhoneBook(){}
		~MyPhoneBook(){}
		void		add();
		void		search();
};

#endif