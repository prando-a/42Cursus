/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:42:57 by prando-a          #+#    #+#             */
/*   Updated: 2024/09/27 16:42:57 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H
# include "ft_irc.hpp"

# define OPTIONAL	-1
# define YES 		1
# define NO 		0

enum modeCommand
{
	I,
	T, 
	K, 
	O, 
	L,
	NONE = -1
};

enum commandErr
{
	WRONG_CMD,
	WRONG_ARGC,
	MISSING_TRAILING,
	INVALID_TRAILING
};

class command
{
	private:
		int							type;
		std::vector<std::string>	params;
		bool						has_trailing;
		std::string					trailing;
		int 						setType(std::string);
		void						checkArgC(size_t, size_t);
		void						checkTrailing(int);

	public:
		command(std::string);
		void						parse(void);
		int							getType(void);
		std::vector<std::string>	getParams(void);
		std::string					getTrailing(void);
		command(const command &src);
		command &operator=(const command &src);
		~command();
};

# endif