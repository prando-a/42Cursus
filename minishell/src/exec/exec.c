/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:33:49 by prando-a          #+#    #+#             */
/*   Updated: 2024/02/10 00:14:48 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	exec_clear(t_exec *exc, char *last_cmd, t_ms *ms)
{
	int	i;

	i = 0;
	if (ft_strequ(last_cmd, "exit") && exc->cmdc == 1
		&& ft_arrnum(exc->cmdv[exc->cmdc - 1]) <= 2)
		ms->exit_flag = 1;
	dup2(exc->dup_std[IN], STDIN_FILENO);
	dup2(exc->dup_std[OUT], STDOUT_FILENO);
	close(exc->dup_std[IN]);
	close(exc->dup_std[OUT]);
	if (exc->file[IN] > 0)
		close(exc->file[IN]);
	if (exc->file[OUT] > 0)
		close(exc->file[OUT]);
	while (i < exc->cmdc)
	{
		free(exc->input[i]);
		free(exc->output[i++]);
	}
	if (exc->status > 256)
		exc->status /= 256;
	return (ft_tridel(exc->cmdv), ft_tridel(exc->inpath), free(exc->input),
		ft_tridel(exc->outpath), free(exc->output), exc->status);
}

int	exec_not_cmd(t_ms *ms, char **cmd, char *abs_path)
{
	struct stat	abs_stat;
	struct stat	rel_stat;

	abs_stat.st_mode = 0;
	rel_stat.st_mode = 0;
	if ((stat(abs_path, &abs_stat) == 0 || stat(cmd[0], &rel_stat) == 0)
		&& ft_strchr(cmd[0], '/'))
	{
		if (S_ISDIR(abs_stat.st_mode) || S_ISDIR(rel_stat.st_mode))
			return (ft_printf(RED"%s is a directory\n"GREEN, cmd[0]),
				exit(126), 1);
		else if ((access(abs_path, X_OK) == 0 || access(cmd[0], X_OK) == 0)
			&& execve(cmd[0], cmd, ms->new_env) == -1
			&& execve(abs_path, cmd, ms->new_env) == -1)
			return (exit(1), 1);
		else
			return (ft_err_msg(RED"Permission denied"GREEN), exit(126), 0);
	}
	else if (ft_strchr(cmd[0], '/'))
		return (ft_err_msg(RED"No such file or directory"GREEN), exit(126), 0);
	return (ft_printf(RED), ft_putstr_fd(cmd[0], 2),
		ft_err_msg(RED": command not found"GREEN), exit(127), 1);
}

void	exec_child(t_ms *ms, char **cmd, t_exec *exc)
{
	int		i;
	int		found;
	char	*abs_path;

	i = 0;
	found = 0;
	if (exc->file[IN] == -1)
		exit(1);
	if (!cmd[0] || ft_strequ(cmd[0], "echo") || ft_strequ(cmd[0], "cd")
		|| ft_strequ(cmd[0], "pwd") || ft_strequ(cmd[0], "unset")
		|| ft_strequ(cmd[0], "export") || ft_strequ(cmd[0], "env")
		|| ft_strequ(cmd[0], "exit"))
		exit(0);
	ms->path = path_join(ms->path, cmd[0]);
	while (ms->path && ms->path[i] && !found)
		found = access(ms->path[i++], F_OK) == 0;
	abs_path = gnl_strjoin(getcwd(NULL, 0), "/", 1, 0);
	abs_path = gnl_strjoin(abs_path, cmd[0], 1, 0);
	if (!found)
		exec_not_cmd(ms, cmd, abs_path);
	if (!ft_strchr(cmd[0], '/'))
		execve(ms->path[--i], cmd, ms->new_env);
	exec_not_cmd(ms, cmd, abs_path);
}

int	exec_father(t_exec *exc, int i, t_ms *ms)
{
	dup2(exc->pipe_fd[READ], STDIN_FILENO);
	waitpid(exc->pid, &exc->status, WUNTRACED);
	exec_built_ins(exc->cmdv[i - 1], ms, exc);
	close(exc->pipe_fd[READ]);
	close(exc->pipe_fd[WRITE]);
	dup2(exc->dup_std[OUT], STDOUT_FILENO);
	return (1);
}

int	ms_exec(t_ms *ms, t_cmd *cmd)
{
	t_exec	exc;
	int		i;

	if (!exec_init(&exc, cmd))
		return (1);
	i = 0;
	while (i++ < exc.cmdc)
	{
		if (pipe(exc.pipe_fd) == -1)
			return (ft_err_msg(RED"pipe() fail"RESET), 1);
		if (i != exc.cmdc)
			dup2(exc.pipe_fd[WRITE], STDOUT_FILENO);
		exec_set_final_io(&exc, i - 1, -1, ms);
		if (g_signal == 2 && exc.status / 256 == 42)
			return (ft_printf(RESET), exec_clear(&exc, " ", ms));
		exc.pid = fork();
		if (exc.pid == -1)
			return (ft_err_msg(RED"Critical fork() failure"RESET), 1);
		if (exc.pid == 0)
			exec_child(ms, exc.cmdv[i - 1], &exc);
		exec_father(&exc, i, ms);
	}
	return (ft_printf(RESET), exec_clear(&exc, exc.cmdv[i - 2][0], ms));
}
