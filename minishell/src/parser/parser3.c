/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:13:10 by jose-mgo          #+#    #+#             */
/*   Updated: 2024/02/10 00:12:41 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_metachar(char *c)
{
	if (!*c)
		return (0);
	if ((*c == '>' && c[1] == '>') || (*c == '<' && c[1] == '<'))
		return (2);
	if (*c == '|' || *c == '>' || *c == '<')
		return (1);
	return (0);
}

t_parserk	init_parse_iter(void)
{
	t_parserk	ret;

	ret.dquotes = 0;
	ret.quotes = 0;
	ret.len = 0;
	ret.i = 0;
	return (ret);
}

int	iter_str(char *command)
{
	t_parserk	p;

	p = init_parse_iter();
	if (is_metachar(command + p.i))
		return (is_metachar(command + p.i));
	while (command[p.i] && !((command[p.i] == ' '
				|| command[p.i] == '\t') && p.dquotes % 2 == 0
			&& p.quotes % 2 == 0))
	{
		if (command[p.i] == '"' && p.quotes % 2 == 0)
			p.dquotes++;
		else if (command[p.i] == '\'' && p.dquotes % 2 == 0)
			p.quotes++;
		p.len++;
		p.i++;
		if (is_metachar(command + p.i) && p.dquotes % 2 == 0
			&& p.quotes % 2 == 0)
			break ;
	}
	return (p.len);
}

int	check_cnt(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != 32 && s[i] != '\t')
			return (0);
		i++;
	}
	return (add_history(s), 1);
}

int	syntax_check(t_cmd *p)
{
	int	i;

	i = 0;
	if (!p->cmd[0])
		return (ft_err_msg(RED": command not found"RESET), 0);
	if (p->pipe[0])
		return (ft_err_msg(RED"Syntax error"RESET), 0);
	while (p->cmd[i])
	{
		if ((p->cmd[i + 1] && (p->pipe[i] || p->heredoc[i]
					|| p->append[i] || p->infile[i] || p->outfile[i]))
			&& (p->pipe[i + 1] || p->heredoc[i + 1]
				|| p->append[i + 1] || p->infile[i + 1] || p->outfile[i + 1]))
		{
			if (!(p->pipe[i]) || (p->pipe[i] && p->pipe[i + 1]))
				return (ft_err_msg(RED"Syntax error"RESET), 0);
		}
		i++;
	}
	if (p->pipe[i - 1] || p->heredoc[i - 1]
		|| p->append[i - 1] || p->infile[i - 1] || p->outfile[i - 1])
		return (ft_err_msg(RED"syntax error near unexpected token `newline'"),
			ft_printf(RESET), 0);
	return (1);
}
