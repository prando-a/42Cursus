/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-mgo <jose-mgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 10:21:37 by jose-mgo          #+#    #+#             */
/*   Updated: 2024/02/06 11:28:25 by jose-mgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_aux	init_aux_struct(void)
{
	t_aux	ret;

	ret.quotes = 0;
	ret.x = 0;
	ret.j = 0;
	ret.i = 0;
	ret.dquotes = 0;
	return (ret);
}

t_cl	update_cl(t_cl cl, t_env *envlst, int status, char *command)
{
	if (command[cl.i] == '"' && cl.quotes == 0 && ++cl.dquotes)
	{
		if (cl.dquotes == 2)
			cl.dquotes = 0;
	}
	else if (command[cl.i] == 39 && cl.dquotes == 0)
	{
		cl.quotes++;
		if (cl.quotes == 2)
			cl.quotes = 0;
	}
	else if (command[cl.i] == '$' && command[cl.i + 1] != ' '
		&& command[cl.i + 1] != '\t' && !is_metachar(command + cl.i + 1)
		&& cl.quotes == 0 && command[cl.i + 1])
	{
		cl.env = findenv(command + cl.i);
		cl.x += ft_strlen_free(ft_getenv(envlst, cl.env, status));
		if (cl.x <= 0)
			return (free(cl.env), cl);
		cl.i += ft_strlen(cl.env);
		free(cl.env);
	}
	else
		cl.x++;
	return (cl);
}

t_nw	update_nw_quotes(t_nw nw, char *s)
{
	if (nw.dquotes == 1)
	{
		nw.i++;
		while (s[nw.i] != '"')
			nw.i++;
		nw.dquotes = 0;
	}
	if (nw.quotes == 1)
	{
		nw.i++;
		while (s[nw.i] != '\'')
			nw.i++;
		nw.quotes = 0;
	}
	nw.i++;
	return (nw);
}

t_nw	update_nw(t_nw nw, char *s, int c)
{
	while (s[nw.i] != '\0' && (s[nw.i] != c && s[nw.i] != '\t'
			&& (nw.dquotes % 2 == 0 || nw.quotes % 2 == 0)))
	{
		if (is_metachar(s + nw.i) && nw.quotes % 2 == 0
			&& nw.dquotes % 2 == 0)
		{
			if ((nw.i == 0)
				|| (s[nw.i - 1] != '\t' && s[nw.i - 1] != ' '))
				nw.numwords++;
			if (s[nw.i + is_metachar(s + 1)] != c)
				nw.numwords++;
			if (s[nw.i + is_metachar(s + nw.i)])
				nw.i += is_metachar(s + nw.i);
		}
		if (s[nw.i] == '\'' && nw.dquotes == 0)
			nw.quotes++;
		else if (s[nw.i] == '"' && nw.quotes == 0)
			nw.dquotes++;
		nw = update_nw_quotes(nw, s);
	}
	return (nw);
}
