/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_init_and_io.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:00:59 by prando-a          #+#    #+#             */
/*   Updated: 2024/02/09 23:42:48 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*heredoc_parse(char *buffer, t_ms *ms, char *limiter, int fd)
{
	t_cmd	*parsed_info;
	char	*res;

	if (buffer)
		free(buffer);
	buffer = readline(GREEN"> "RESET);
	if (!buffer)
		return (NULL);
	if (!*buffer)
		return (ft_putstr_fd("\n", fd), buffer);
	parsed_info = ms_parser(buffer, ms->e_lst, ms->status);
	res = ft_merge(parsed_info->cmd, ' ', 1);
	if (!ft_strequ(limiter, res))
		ft_putendl_fd(res, fd);
	return (ft_free_cmd(parsed_info), free(buffer), res);
}

int	get_heredoc(char *limiter, t_exec *exc, t_ms *ms)
{
	pid_t	pid;
	int		fd[2];
	char	*buffer;

	if (pipe(fd) == -1)
		return (-1);
	g_signal = 1;
	pid = fork();
	if (pid)
		return (g_signal = 2, waitpid(pid, &exc->status, WUNTRACED),
			close(fd[WRITE]), fd[READ]);
	dup2(exc->dup_std[OUT], STDOUT_FILENO);
	dup2(exc->dup_std[IN], STDIN_FILENO);
	buffer = NULL;
	while (!ft_strequ(limiter, buffer))
	{
		buffer = heredoc_parse(buffer, ms, limiter, fd[WRITE]);
		if (!buffer)
			return (ft_printf(GREEN), exit(1), 1);
	}
	return (free(buffer), ft_printf(GREEN), exit(0), 1);
}

int	set_final_output(t_exec *exc, int i)
{
	int	j;

	j = -1;
	while (exc->outpath[i][++j])
	{
		if (exc->file[OUT] > 0)
			close(exc->file[OUT]);
		if (exc->output[i][j] == OUTFILE)
			exc->file[OUT] = open(exc->outpath[i][j],
					O_WRONLY | O_CREAT | O_TRUNC, 0666);
		else if (exc->output[i][j] == APPEND)
			exc->file[OUT] = open(exc->outpath[i][j],
					O_WRONLY | O_CREAT | O_APPEND, 0666);
		dup2(exc->file[OUT], STDOUT_FILENO);
	}
	return (1);
}

int	exec_set_final_io(t_exec *exc, int i, int j, t_ms *ms)
{
	while (exc->inpath[i][++j])
	{
		if (exc->file[IN] > 0)
			close(exc->file[IN]);
		if (exc->input[i][j] == INFILE)
			exc->file[IN] = open(exc->inpath[i][j], O_RDONLY);
		else if (exc->input[i][j] == HEREDOC)
			exc->file[IN] = get_heredoc(exc->inpath[i][j], exc, ms);
		if (exc->file[IN] == -1)
			return (ft_err_msg(RED"No such file or directory"GREEN), 0);
		dup2(exc->file[IN], STDIN_FILENO);
	}
	return (set_final_output(exc, i));
}

int	exec_init(t_exec *exc, t_cmd *cmd)
{
	exc->cmdc = 1;
	exc->status = 0;
	exc->cmdv = set_cmdv(cmd, &exc->cmdc);
	exc->inpath = ft_calloc(exc->cmdc + 1, sizeof(char **));
	exc->input = ft_calloc(exc->cmdc, sizeof(int *));
	set_input_vector(cmd, exc, 0, -1);
	exc->outpath = ft_calloc(exc->cmdc + 1, sizeof(char **));
	exc->output = ft_calloc(exc->cmdc, sizeof(int *));
	set_output_vector(cmd, exc, 0, -1);
	exc->file[IN] = -2;
	exc->file[OUT] = -2;
	exc->dup_std[IN] = dup(STDIN_FILENO);
	exc->dup_std[OUT] = dup(STDOUT_FILENO);
	return (ft_printf(GREEN), 1);
}
