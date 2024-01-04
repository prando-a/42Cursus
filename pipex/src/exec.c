/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:56:56 by prando-a          #+#    #+#             */
/*   Updated: 2023/12/15 22:33:04 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_cmd_pos(char **path)
{
	int	i;
	int	found;

	i = 0;
	found = 0;
	while (path[i] && !found)
		found = access(path[i++], F_OK) == 0;
	if (!found)
		return (-1);
	return (--i);
}

int	father(t_pipex **pipex, char **env)
{
	int	path_cmd_i;

	path_cmd_i = get_cmd_pos((*pipex)->path_i);
	if (path_cmd_i == -1)
		return (ft_putendl_fd("Input command was not found", 2), 1);
	dup2((*pipex)->fd[WRITE_END], STDOUT_FILENO);
	dup2((*pipex)->fd_i, STDIN_FILENO);
	close((*pipex)->fd[READ_END]);
	close((*pipex)->fd[WRITE_END]);
	close((*pipex)->fd_i);
	if (execve((*pipex)->path_i[path_cmd_i], (*pipex)->cmd_i, env) == -1)
		return (ft_putendl_fd("Failed to execute input command", 2), 0);
	return (1);
}

int	child(t_pipex **pipex, char **env)
{
	int	path_cmd_o;

	path_cmd_o = get_cmd_pos((*pipex)->path_o);
	if (path_cmd_o == -1)
		return (ft_putendl_fd("Output command was not found", 2), 1);
	dup2((*pipex)->fd[READ_END], STDIN_FILENO);
	dup2((*pipex)->fd_o, STDOUT_FILENO);
	close((*pipex)->fd[READ_END]);
	close((*pipex)->fd[WRITE_END]);
	close((*pipex)->fd_o);
	if (execve((*pipex)->path_o[path_cmd_o], (*pipex)->cmd_o, env) == -1)
		return (ft_putendl_fd("Failed to execute output command", 2), 1);
	return (1);
}
