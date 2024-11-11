/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 19:14:06 by prando-a          #+#    #+#             */
/*   Updated: 2024/09/02 19:14:06 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "ft_irc.hpp"


class server
{
	private:
		std::string				pass;
		int						port;
		int 					_socket;
		struct sockaddr_in		address;
		socklen_t				addrlen;
		int						sockopt;
		std::string				hostname;
		fd_set					readfds;
		int 					sockets[512];
		std::string				sockbuff[512];
		std::vector<client*>	clientList;
		std::vector<channel*>	channelList;

		std::string				logo[11];

		typedef void			(server::*funcPTR)(command, int);
		funcPTR					func[13];
		void 					cmdNICK(command, int);
		void 					cmdUSER(command, int);
		void 					cmdQUIT(command, int);
		void 					cmdJOIN(command, int);
		void 					cmdPART(command, int);
		void 					cmdPRIVMSG(command, int);
		void 					cmdKICK(command, int);
		void 					cmdINVITE(command, int);
		void 					cmdTOPIC(command, int);
		void 					cmdMODE(command, int);
		void 					cmdCAP(command, int);
		void 					cmdPASS(command, int);
		void					cmdWHO(command, int);
		void					sendResponse(std::string, int);
		bool					isRegistered(int);
		void 					registerUser(int);
		void 					unregisterUser(int);
		client*					getClientbySock(int);
		client*					getClientbyNick(std::string);
		channel*				createChannel(std::string, std::string, int);
		void					deleteChannel(std::string _name);
		channel*				getChannelbyName(std::string);
		bool					nickExists(std::string);

		void 					setCommandPTRs(void);
		void 					setSocket(void);
		void 					setHostname(void);
		void					printLogo(void);
		std::string				getPass(void) const;


	public:
		server(std::string, int);
		int						getSocket(void) const;
		std::string				getHostname(void) const;
		
		void					manageSockets(void);
		void 					acceptConnection(void);
		void					readData(void);
		void					processData(std::string, int*);
		void					useCommand(command, int);
		~server();
		server(const server &src);
		server &operator=(const server &src);
};

#endif