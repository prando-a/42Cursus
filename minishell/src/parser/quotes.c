/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-mgo <jose-mgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:09:30 by jose-mgo          #+#    #+#             */
/*   Updated: 2024/02/05 18:44:08 by jose-mgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_chrqts(char *str)
{
	int	i;
	int	quotes;
	int	dquotes;

	quotes = 0;
	dquotes = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' && dquotes % 2 == 0)
			quotes++;
		if (str[i] == '"' && quotes % 2 == 0)
			dquotes++;
		i++;
	}
	if (quotes % 2 != 0)
		return (1);
	else if (dquotes % 2 != 0)
		return (2);
	return (0);
}

int	ms_quotes(t_ms *ms)
{
	if ((ft_chrqts(ms->buffer)))
	{
		if (ft_chrqts(ms->buffer) == 1)
			ft_err_msg(RED"minishell: \' syntax error"RESET);
		else
			ft_err_msg(RED"minishell: \" syntax error"RESET);
		add_history(ms->buffer);
		ms->status = 1;
		return (0);
	}
	return (1);
}
