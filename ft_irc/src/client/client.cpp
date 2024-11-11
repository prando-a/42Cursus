/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 17:41:39 by prando-a          #+#    #+#             */
/*   Updated: 2024/10/06 17:41:39 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/client.hpp"

client::client(int socket) : socket(socket)
{
	this->nickName = "";
	this->realName = "";
	this->userName = "";
	setAddress();
}

std::vector<std::string>	client::getChannels() const
{
	return this->invitedChannels;
}

void	client::setChannel(std::string _channel)
{
	this->invitedChannels.push_back(_channel);
}

void	client::deleteChannel(std::string _name)
{
	std::vector<std::string>::iterator it;

	it = this->invitedChannels.begin();
	while (it != invitedChannels.end())
	{
		if (invitedChannels[std::distance(invitedChannels.begin(), it)] == _name)
			it = invitedChannels.erase(it);
		else
			++it;
	}
}

bool	client::isInvited(std::string _name)
{
	std::vector<std::string>::iterator it;

	for (it = this->invitedChannels.begin(); it != invitedChannels.end(); ++it)
		if (invitedChannels[std::distance(invitedChannels.begin(), it)] == _name)
			return true;
	return false;
}

void client::setAddress(void)
{
	this->addr_len = sizeof(this->address);
	getpeername(this->socket, (struct sockaddr*)&this->address, &this->addr_len);
	host_entry = gethostbyaddr(&address.sin_addr, sizeof(address.sin_addr), AF_INET);
	std::cout << "Cliente conectado desde " << host_entry->h_name << std::endl;
}

void	client::setNickName(std::string nickName)	{ this->nickName = nickName;}
void	client::setUserName(std::string userName)	{ this->userName = userName;}
void	client::setRealName(std::string realName)	{ this->realName = realName;}

void	client::setHostName(void)
{
	this->hostName =  this->getNickName() + "!"
					+ this->getUserName() + "@"
					+ this->host_entry->h_name;
}

std::string	client::getNickName(void) const			{ return (this->nickName); }
std::string	client::getUserName(void) const			{ return (this->userName); }
std::string	client::getRealName(void) const			{ return (this->realName); }
std::string	client::getHostName(void) const			{ return (this->hostName); }


int		client::getSocket(void){ return (this->socket); }

client::~client()
{
	
}

client::client(const client &src)
{
	*this = src;
}

client &client::operator=(const client &src)
{
	if (this == &src)
		return (*this);
	return (*this);
}