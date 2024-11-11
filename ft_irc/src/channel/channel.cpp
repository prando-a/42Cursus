/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 17:00:11 by prando-a          #+#    #+#             */
/*   Updated: 2024/10/06 17:00:11 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/channel.hpp"

channel::channel(std::string name, std::string topic, int sock) : name(name), topic(topic)
{
	if (this->name[0] != '#' || this->name.length() < 2)
		throw ERR_BADCHANMASK;
	this->usrLimit = NO_LIMIT;
	this->inviteOnly = false;
	this->topicLock = false;
	this->uList.push_back(sock);
	this->opList.push_back(sock);
	if (topic.length() == 0)
		this->topic = "No topic set";
}

bool		channel::getInviteOnly() const
{
	return this->inviteOnly;
}

bool channel::isRegistered(int sock)
{
	for (size_t i = 0 ; i < this->uList.size() ; i++)
	{
		if (this->uList[i] == sock)
			return (true);
	}
	return (false);
}

bool channel::isOperator(int sock)
{
	for (size_t i = 0 ; i < this->opList.size() ; i++)
	{
		if (this->opList[i] == sock)
			return (true);
	}
	return (false);
}

void channel::addUser(int sock)
{
	if (isRegistered(sock))
		throw ERR_USERONCHANNEL;
	this->uList.push_back(sock);
}

void channel::setOperator(int sock)
{
	if (isOperator(sock))
		throw ERR_CHANOPRIVSNEEDED;
	this->opList.push_back(sock);
}

std::string	channel::getPass(void) const
{
	return this->password;
}

void		channel::setTopicLock(bool b)
{
	topicLock = b;
}

void channel::setPass(std::string password)
{
	this->password = password;
}

void		channel::deletePass()
{
	this->password.clear();
}

void		channel::setInviteOnly(bool b)
{
	this->inviteOnly = b;
}

void channel::deleteOp(int sock)
{
	std::vector<int>::iterator it;

	it = this->opList.begin();
	while (it != opList.end())
	{
		if (opList[std::distance(opList.begin(), it)] == sock)
			it = opList.erase(it);
		else
			++it;
	}
}

void		channel::deleteUser(int sock)
{
	std::vector<int>::iterator it;

	it = this->uList.begin();
	while (it != uList.end())
	{
		if (uList[std::distance(uList.begin(), it)] == sock)
			it = uList.erase(it);
		else
			++it;
	}
}

void channel::setTopic(std::string topic, int sock)
{
	if (this->topicLock)
	{
		for (size_t i = 0 ; i < this->opList.size() ; i++)
		{
			if (this->opList[i] == sock)
				break;
		}
	}
	this->topic = topic;
}

std::vector<int> &channel::getUList()
{
	return this->uList;
}

std::vector<int> channel::getOpList() const
{
	return this->opList;
}

bool		channel::sendToChannel(std::string to_send, int exc)
{
	std::vector<int>::iterator it;

	for (it = uList.begin(); it != this->uList.end(); ++it)
	{
		if (uList[std::distance(uList.begin(), it)] != exc
			&& send(uList[std::distance(uList.begin(), it)],
			to_send.c_str(), to_send.length(), 0) == -1)
			return false;
	}
	return true;
}

void	channel::setLimit(int l)
{
	this->usrLimit = l;
}

bool		channel::getTopicLock() const
{
	return this->topicLock;
}

std::string channel::getName(void)  const { return (this->name);  }
std::string channel::getTopic(void) const { return (this->topic); }
int	channel::getLimit() const { return (this->usrLimit); }

channel::~channel()
{
	std::cout << YELLOW << "[INFO] Deleted channel with name -> " << this->name << "\n" << RESET; 
}

channel::channel(const channel &src)
{
	*this = src;
}

channel &channel::operator=(const channel &src)
{
	if (this == &src)
		return (*this);
	return (*this);
}