/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 12:36:13 by prando-a          #+#    #+#             */
/*   Updated: 2024/10/04 12:36:13 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/command.hpp"

command::command(std::string cmd)
{
	this->has_trailing = false;
	this->trailing = "";
	std::stringstream ss(cmd);
	std::string word;

	while (ss >> word)
	{
		if (word[0] == ':')
		{
			this->trailing = cmd.substr(cmd.find(word) + 1);
			this->has_trailing = true;
			break;
		}
		this->params.push_back(word);
	}

	this->type = setType(this->params[0]);
	this->params.erase(this->params.begin());
}


int command::setType(std::string cmd)
{
	std::string commands[] =
	{
		"NICK",
		"USER",
		"QUIT",
		"JOIN",
		"PART",
		"PRIVMSG",
		"KICK",
		"INVITE",
		"TOPIC",
		"MODE",
		"CAP",
		"PASS",
		"WHO"
	};

	for (int i = 0; i < 13; i++)
	{
		if (commands[i] == cmd)
			return (i);
	}
	return (INVALID);
}

int 						command::getType(void) 		{ return (this->type); 		}
std::vector<std::string>	command::getParams(void)	{ return (this->params);	}
std::string					command::getTrailing(void)	{ return (this->trailing);	}


command::~command(){}

command::command(const command &src)
{
	this->params = src.params;
	this->type = src.type;
	this->has_trailing = src.has_trailing;
	this->trailing = src.trailing;
}

command &command::operator=(const command &src)
{
	this->params = src.params;
	this->type = src.type;
	this->has_trailing = src.has_trailing;
	this->trailing = src.trailing;
	return (*this);
}
