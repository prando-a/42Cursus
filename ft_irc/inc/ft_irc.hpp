/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   webserv.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 19:09:21 by prando-a          #+#    #+#             */
/*   Updated: 2024/09/02 19:09:21 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IRC_H
# define IRC_H

# include <iostream>
# include <cstdio>
# include <string>
# include <cstdlib>
# include <string.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netdb.h>
# include <netinet/in.h>
# include <unistd.h>
# include <arpa/inet.h>
# include <sstream>
# include <vector>
# include <map>
# include <poll.h>
# include <fcntl.h>
# include <signal.h>
# include <cerrno>
# include <ctime>

# define RED     	"\x1b[31m"
# define GREEN   	"\x1b[32m"
# define YELLOW  	"\x1b[33m"
# define BLUE    	"\x1b[34m"
# define MAGENTA	"\x1b[35m"
# define CYAN    	"\x1b[36m"
# define WHITE		"\033[37m"
# define BOLD		"\033[1m"
# define RESET   	"\x1b[0m"
# define CLEAR		"\033[2J"

enum commandType
{
	NICK,
	USER,
	QUIT,
	JOIN,
	PART,
	PRIVMSG,
	KICK,
	INVITE,
	TOPIC,
	MODE,
	CAP,
	PASS,
    WHO,
	INVALID = -1
};

enum IrcErrCode {
    ERR_PASSWDMISMATCH = 464,
    ERR_UNKNOWNCOMMAND = 421,
	ERR_TOOMANYTARGETS = 407,
    ERR_NEEDMOREPARAMS = 461,
    ERR_NOTREGISTERED = 451,
    ERR_CHANOPRIVSNEEDED = 482,
    ERR_NOTONCHANNEL = 442,
    ERR_USERNOTINCHANNEL = 441,
    ERR_NOSUCHNICK = 401,
    ERR_NOSUCHCHANNEL = 403,
    ERR_UNKNOWNMODE = 472,
    ERR_ALREADYREGISTRED = 462,
    ERR_NICKNAMEINUSE = 433,
    ERR_BADCHANMASK = 476,
    ERR_INVITEONLYCHAN = 473,
    ERR_USERONCHANNEL = 443,
    RPL_TOPIC = 332,
    RPL_WELCOME = 001,
    RPL_YOURHOST = 002,
    RPL_CREATED = 003,
    RPL_MYINFO = 004,
    RPL_BOUNCE = 005,
    RPL_NAMREPLY = 353,
    RPL_ENDOFNAMES = 366,
    ERR_CANNOTSENDTOCHAN = 404,
    ERR_NOTEXTTOSEND = 412,
    ERR_NONICKNAMEGIVEN = 431,
    ERR_ERRONEUSNICKNAME = 432,
    CUSTOM_PANIC_EPIC_EXIT = 666
};

class server;
class channel;
class client;
class command;

# include "server.hpp"
# include "channel.hpp"
# include "client.hpp"
# include "command.hpp"

std::string intToStr(int n);
void sendErrResponse(std::string host, int rplCode, int sock);
int	ft_atoi(const char *str);

#endif
