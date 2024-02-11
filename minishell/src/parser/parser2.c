/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:06:44 by jose-mgo          #+#    #+#             */
/*   Updated: 2024/02/09 20:44:30 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	update_parse_info(t_parser *parse_info, int quotes, int dquotes)
{
	parse_info->outfile = 0;
	parse_info->infile = 0;
	parse_info->pipe = 0;
	parse_info->heredoc = 0;
	parse_info->append = 0;
	if (quotes != 0 || dquotes != 0)
		return ;
	if (ft_strequ(parse_info->cmd, "|"))
		parse_info->pipe = 1;
	if (ft_strequ(parse_info->cmd, "<<"))
		parse_info->heredoc = 1;
	if (ft_strequ(parse_info->cmd, ">"))
		parse_info->outfile = 1;
	if (ft_strequ(parse_info->cmd, "<"))
		parse_info->infile = 1;
	if (ft_strequ(parse_info->cmd, ">>"))
		parse_info->append = 1;
}

static	int	ft_numwords(char *s, char c)
{
	t_nw	nw;

	nw.quotes = 0;
	nw.dquotes = 0;
	nw.numwords = 0;
	nw.i = 0;
	while (s[nw.i] != '\0')
	{
		if (s[nw.i] != c && s[nw.i] != '\t')
		{
			nw.numwords++;
			nw = update_nw(nw, s, c);
		}
		else
			while (s[nw.i] == c || s[nw.i] == '\t')
				nw.i++;
	}
	return (nw.numwords);
}

t_cmd	*init_cmd_lst(char *command)
{
	t_cmd	*cmd;
	int		args;

	cmd = ft_calloc(sizeof(t_cmd), 1);
	args = ft_numwords(command, 32);
	cmd->cmd = malloc((args + 1) * sizeof(char *));
	cmd->cmd[args] = 0;
	cmd->heredoc = malloc(args * sizeof(int));
	cmd->pipe = malloc(args * sizeof(int));
	cmd->infile = malloc(args * sizeof(int));
	cmd->outfile = malloc(args * sizeof(int));
	cmd->append = malloc(args * sizeof(int));
	return (cmd);
}

void	ft_free_cmd(t_cmd *cmd)
{
	if (cmd)
	{
		ft_strdel(cmd->cmd);
		free(cmd->append);
		free(cmd->outfile);
		free(cmd->infile);
		free(cmd->pipe);
		free(cmd->heredoc);
		free(cmd);
	}
}

t_cmd	*ms_parser(char *command, t_env *envlst, int status)
{
	t_mix	aux;

	aux.i = 0;
	aux.len = 0;
	aux.numargs = ft_numwords(command, 32);
	aux.cmd = init_cmd_lst(command);
	while (aux.numargs--)
	{
		while ((command[aux.len] == 32 || command[aux.len] == '\t'))
			aux.len++;
		aux.info = parse_command(command + aux.len, envlst, status);
		aux.len += iter_str(command + aux.len);
		if (aux.info.cmd)
		{
			aux.cmd->cmd[aux.i] = aux.info.cmd;
			aux.cmd->infile[aux.i] = aux.info.infile;
			aux.cmd->outfile[aux.i] = aux.info.outfile;
			aux.cmd->heredoc[aux.i] = aux.info.heredoc;
			aux.cmd->append[aux.i] = aux.info.append;
			aux.cmd->pipe[aux.i] = aux.info.pipe;
			aux.i++;
		}
	}
	return (aux.cmd->cmd[aux.i] = NULL, aux.cmd);
}
