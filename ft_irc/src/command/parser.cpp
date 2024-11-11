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

void command::checkTrailing(int required)
{
	if (required == YES && !this->has_trailing)
		throw ERR_NEEDMOREPARAMS;
	else if (required == NO && this->has_trailing)
		throw ERR_TOOMANYTARGETS;
}

void command::checkArgC(size_t min, size_t max)
{
	if (this->params.size() < min)
		throw ERR_NEEDMOREPARAMS;
	if (this->params.size() > max)
		throw ERR_TOOMANYTARGETS;
}

void command::parse(void)
{
	switch (this->type)
	{
		case NICK:
			checkArgC(1, 1);
			checkTrailing(NO);
				break;
		case USER:
			checkArgC(3, 3);
			checkTrailing(YES);
				break;
		case QUIT:
			checkArgC(0, 0);
			checkTrailing(OPTIONAL);
				break;
		case JOIN:
			checkArgC(1, 2);
			checkTrailing(OPTIONAL);
				break;
		case PART:
			checkArgC(1, 1);
			checkTrailing(OPTIONAL);
				break;
		case PRIVMSG:
			checkArgC(1, 1);
			checkTrailing(YES);
				break;
		case KICK:
			checkArgC(2, 2);
			checkTrailing(OPTIONAL);
				break;
		case INVITE:
			checkArgC(2, 2);
			checkTrailing(NO);
				break;
		case TOPIC:
			checkArgC(0, 1);
			checkTrailing(YES);
				break;
		case MODE:
			checkArgC(1, 3);
			checkTrailing(NO);
				break;
		case CAP:
			break;
		case PASS:
			checkArgC(1, 1);
			checkTrailing(NO);
				break;
		case WHO:
			checkArgC(1, 1);
			checkTrailing(NO);
			break;
		default:
			throw ERR_UNKNOWNCOMMAND;
			break;
	}
}
