/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftSed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-12 10:52:39 by prando-a          #+#    #+#             */
/*   Updated: 2024-06-12 10:52:39 by prando-a         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "ftSed.hpp"

ftSed::ftSed(char *filename)
{
	this->infile.open(filename, std::ios::in);
    if (!(this->infile.is_open()))
		throw (std::runtime_error(std::string("Error: ") + filename + ": no such file or directory.\n"));

	this->outfile.open((std::string(filename) + ".replace").c_str(), std::ios::out);
    if (!(this->outfile.is_open()))
        throw (std::runtime_error("Error: Output file wasn't created.\n"));

    getline(this->infile, this->content, '\0');
}

void	ftSed::ftReplace(char *s1, char *s2)
{
	size_t pos = 0;
	while ((pos = this->content.find(s1, pos)) != std::string::npos)
	{
		this->content.erase(pos, strlen(s1));
   		this->content.insert(pos, s2);
		pos += strlen(s2);
	}
	this->outfile << this->content;
}

ftSed::~ftSed()
{
	this->infile.close();
	this->outfile.close();
}