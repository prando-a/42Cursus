/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:10:40 by prando-a          #+#    #+#             */
/*   Updated: 2024/01/03 18:16:14 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	get_cmd_pos(char **path)
{
	int	i;
	int	found;

	i = 0;
	found = 0;
	while (path && path[i] && !found)
		found = access(path[i++], F_OK) == 0;
	if (!found)
		return (-1);
	return (--i);
}

void	child(t_pipex **pipex, int child, char **env)
{
	int	valid;

	dup2((*pipex)->fd[WRITE], STDOUT_FILENO);
	(*pipex)->path = path_join((*pipex)->path, (*pipex)->cmdv[child - 1][0]);
	valid = get_cmd_pos((*pipex)->path);
	if (valid == -1)
		return (ft_err_msg("Command not found"), exit(1));
	if (execve((*pipex)->path[valid], (*pipex)->cmdv[child - 1], env) == -1)
		return (ft_err_msg("Couldn't execute command"), exit(1));
}
