/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-mgo <jose-mgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:08:24 by jose-mgo          #+#    #+#             */
/*   Updated: 2024/02/06 10:21:14 by jose-mgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_aux	aux_for_update(t_aux aux, char *command, t_env *envlst, int status)
{
	aux.envindex = 0;
	aux.freeme = findenv(command + aux.i);
	aux.env = ft_getenv(envlst, aux.freeme, status);
	while (aux.env && aux.env[aux.envindex])
	{
		aux.line[aux.j] = aux.env[aux.envindex];
		aux.envindex++;
		aux.j++;
	}
	aux.i += ft_strlen(aux.freeme);
	free(aux.freeme);
	if (aux.env)
		free(aux.env);
	return (aux);
}

t_aux	update_for_metachar(t_aux aux, char *command)
{
	if (is_metachar(command + aux.i))
	{
		aux.j = 1;
		if (is_metachar(command + aux.i) == 1)
			aux.line[0] = command[aux.i];
		else
		{
			aux.line[0] = command[aux.i];
			aux.line[1] = command[aux.i + 1];
			aux.j++;
		}
		aux.i = ft_strlen(command);
	}
	return (aux);
}

t_aux	update_struct_parse(t_aux aux, t_env *envlst, int status, char *command)
{
	if (command[aux.i] == 39 && aux.dquotes % 2 == 0)
		aux.quotes++;
	else if (command[aux.i] == '"' && aux.quotes % 2 == 0)
		aux.dquotes++;
	else if (command[aux.i] == '$' && command[aux.i + 1] != ' '
		&& command[aux.i + 1] != '\t' && !is_metachar(command + aux.i + 1)
		&& aux.quotes % 2 == 0 && command[aux.i + 1])
	{
		aux = aux_for_update(aux, command, envlst, status);
	}
	else if (!((command[aux.i] == 32 || command[aux.i] == '\t')
			&& aux.dquotes == 0))
	{
		aux.x = 1;
		aux.line[aux.j] = command[aux.i];
		aux.j++;
	}
	aux.i++;
	return (aux);
}

static int	check(char *s, char c)
{
	int	quotes;
	int	dquotes;

	quotes = 0;
	dquotes = 0;
	while (*s)
	{
		if (*s == '\'' && dquotes % 2 == 0)
			quotes++;
		else if (*s == '"' && quotes % 2 == 0)
			dquotes++;
		if (*s == c && dquotes % 2 == 0 && quotes % 2 == 0)
			return (0);
		s++;
	}
	return (1);
}

int	check_illegal_char(char *s)
{
	if (!check(s, '\\'))
		return (add_history(s), ft_err_msg(RED"Illegal character: \\"RESET), 0);
	else if (!check(s, ';'))
		return (add_history(s), ft_err_msg(RED"Illegal character: ;"RESET), 0);
	return (add_history(s), 1);
}
