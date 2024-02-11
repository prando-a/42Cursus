/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:22:40 by prando-a          #+#    #+#             */
/*   Updated: 2024/02/05 22:24:41 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	get_matrix_len(t_cmd *cmd, int *k, int mode)
{
	int	len;

	len = 0;
	while (cmd->cmd[(*k)] && cmd->pipe[(*k)] == 0)
	{
		if ((mode == IN && (cmd->infile[(*k)] || cmd->heredoc[(*k)]))
			|| (mode == OUT && (cmd->outfile[(*k)] || cmd->append[(*k)])))
			len++;
		(*k)++;
	}
	return (len);
}

void	set_output_vector(t_cmd *cmd, t_exec *exc, int i, int j)
{
	int		k;
	int		len;

	while (++j < exc->cmdc)
	{
		k = i;
		len = get_matrix_len(cmd, &k, OUT);
		exc->outpath[j] = ft_calloc(len + 1, sizeof(char *));
		exc->output[j] = ft_calloc(len, sizeof(int));
		len = 0;
		while (exc->outpath[j] && i < k)
		{
			if (cmd->outfile[i] || cmd->append[i])
			{
				if (cmd->outfile[i])
					exc->output[j][len] = OUTFILE;
				else if (cmd->append[i])
					exc->output[j][len] = APPEND;
				exc->outpath[j][len++] = ft_strdup(cmd->cmd[i + 1]);
			}
			i++;
		}
		i++;
	}
}

void	set_input_vector(t_cmd *cmd, t_exec *exc, int i, int j)
{
	int	k;
	int	len;

	while (++j < exc->cmdc)
	{
		k = i;
		len = get_matrix_len(cmd, &k, IN);
		exc->inpath[j] = ft_calloc(len + 1, sizeof(char *));
		exc->input[j] = ft_calloc(len, sizeof(int));
		len = 0;
		while (exc->inpath[j] && i < k)
		{
			if (cmd->infile[i] || cmd->heredoc[i])
			{
				if (cmd->infile[i])
					exc->input[j][len] = INFILE;
				else if (cmd->heredoc[i])
					exc->input[j][len] = HEREDOC;
				exc->inpath[j][len++] = ft_strdup(cmd->cmd[i + 1]);
			}
			i++;
		}
		i++;
	}
}

char	**cmd_to_vector(t_cmd *cmd, int *index, int k, int len)
{
	char	**res;
	int		index_backup;

	index_backup = *index;
	while (cmd->cmd[*index] && cmd->pipe[*index] == 0)
	{
		if (cmd->infile[*index] || cmd->heredoc[*index]
			|| cmd->outfile[*index] || cmd->append[*index])
			(*index)++;
		else
			len++;
		(*index)++;
	}
	res = ft_calloc(len + 1, sizeof(char *));
	k = 0;
	while (res && len--)
	{
		while (cmd->infile[index_backup] || cmd->heredoc[index_backup]
			|| cmd->outfile[index_backup] || cmd->append[index_backup])
			index_backup += 2;
		res[k++] = ft_strdup(cmd->cmd[index_backup++]);
	}
	if (cmd->cmd[*index] && cmd->pipe[*index] == 1)
		(*index)++;
	return (res);
}

char	***set_cmdv(t_cmd *cmd, int *cmdc)
{
	char	***cmdv;
	int		i;
	int		j;

	i = -1;
	while (cmd->cmd[++i])
	{
		if (cmd->pipe[i] == 1)
			(*cmdc)++;
	}
	cmdv = ft_calloc(*cmdc + 1, sizeof(char **));
	i = 0;
	j = 0;
	while (cmd->cmd[i])
		cmdv[j++] = cmd_to_vector(cmd, &i, 0, 0);
	return (cmdv);
}
