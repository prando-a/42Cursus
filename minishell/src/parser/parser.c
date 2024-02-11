/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-mgo <jose-mgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 15:19:50 by jose-mgo          #+#    #+#             */
/*   Updated: 2024/02/06 11:08:35 by jose-mgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

size_t	ft_strlen_free(const char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (0);
	while (str && str[++i])
		;
	return (free((void *)str), i);
}

t_parser	parse_command(char *command, t_env *envlst, int status)
{
	t_aux		aux;
	t_parser	parse_info;

	aux = init_aux_struct();
	if (!get_command_len(command, envlst, status) || !command)
		return (parse_info.cmd = NULL, parse_info);
	aux.line = ft_calloc((get_command_len(command, envlst, status)
				+ 1), 1);
	if (!aux.line)
		return (parse_info.cmd = NULL, parse_info);
	while ((command[aux.i] == 32 || command[aux.i] == '\t'
			|| command[aux.i] == '\r') && command[aux.i])
		aux.i++;
	aux = update_for_metachar(aux, command);
	while (command[aux.i])
	{
		aux = update_struct_parse(aux, envlst, status, command);
		if ((command[aux.i] == 32 || command[aux.i] == '\t'
				|| is_metachar(command + aux.i))
			&& aux.dquotes % 2 == 0 && aux.quotes % 2 == 0)
			break ;
	}
	return (aux.line[aux.j] = '\0', parse_info.cmd = aux.line,
		update_parse_info(&parse_info, aux.quotes, aux.dquotes), parse_info);
}

char	*findenv(char *str)
{
	int		i;
	char	*find;
	int		x;

	i = 0;
	while (str[i] != '$')
		i++;
	x = i;
	while ((str[i] != 32 && str[i] != '"' && str[i] != 39) && str[i])
		i++;
	find = malloc(i - x);
	x++;
	i = x;
	x = 0;
	while ((str[i] != 32 && str[i] != '"' && str[i] != 39) && str[i])
	{
		find[x] = str[i];
		x++;
		i++;
	}
	return (find[x] = 0, find);
}

int	get_command_len(char *command, t_env *envlst, int status)
{
	t_cl	cl;

	cl.i = 0;
	cl.x = 0;
	cl.dquotes = 0;
	cl.quotes = 0;
	while ((command[cl.i] == 32 || command[cl.i] == '\t'
			|| command[cl.i] == '\r') && cl.dquotes == 0 && cl.x == 0)
		cl.i++;
	while (command[cl.i])
	{
		cl = update_cl(cl, envlst, status, command);
		if (cl.x < 0)
			return (0);
		if (is_metachar(command + cl.i) && cl.dquotes == 0 && cl.quotes == 0)
		{
			if (is_metachar(command + cl.i) == 2)
				cl.x++;
			break ;
		}
		cl.i++;
	}
	return (cl.x);
}
