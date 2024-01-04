/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 20:04:42 by prando-a          #+#    #+#             */
/*   Updated: 2024/01/03 18:48:45 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	clean_pipex(t_pipex **pipex)
{
	if ((*pipex)->path_i)
		ft_strdel((*pipex)->path_i);
	if ((*pipex)->path_o)
		ft_strdel((*pipex)->path_o);
	if ((*pipex)->cmd_i)
		ft_strdel((*pipex)->cmd_i);
	if ((*pipex)->cmd_o)
		ft_strdel((*pipex)->cmd_o);
	close((*pipex)->fd_i);
	close((*pipex)->fd_o);
	free(*pipex);
}

char	**path_join(char **arr, char *str)
{
	char	**res;
	int		i;

	if (!arr || !str || !*str)
		return (ft_strdel(arr), NULL);
	res = ft_calloc(ft_arrnum(arr) + 1, sizeof(char *));
	if (!res)
		return (ft_strdel(arr), NULL);
	i = 0;
	while (arr[i])
	{
		res[i] = gnl_strjoin(arr[i], str, 0, 0);
		if (!res[i++])
			return (ft_strdel(res), ft_strdel(arr), NULL);
	}
	return (ft_strdel(arr), res);
}

int	get_paths(t_pipex **pipex, char **env)
{
	int		i;
	char	*aux;

	i = 0;
	while (env[i] && !ft_strnequ(env[i], "PATH=", 5))
		i++;
	(*pipex)->path_i = ft_split(env[i], ':');
	aux = ft_strdup(ft_strchr((*pipex)->path_i[0], '/'));
	if (!(*pipex)->path_i || !aux)
		return (0);
	free((*pipex)->path_i[0]);
	(*pipex)->path_i[0] = aux;
	(*pipex)->path_i = path_join((*pipex)->path_i, "/");
	(*pipex)->path_o = ft_arrdup((*pipex)->path_i);
	(*pipex)->path_i = path_join((*pipex)->path_i, (*pipex)->cmd_i[0]);
	(*pipex)->path_o = path_join((*pipex)->path_o, (*pipex)->cmd_o[0]);
	if (!(*pipex)->path_i || !(*pipex)->path_o)
		return (0);
	return (1);
}

t_pipex	*init_data(char **argv, char **env)
{
	t_pipex	*pipex;

	pipex = ft_calloc(1, sizeof(t_pipex));
	if (!pipex)
		return (NULL);
	pipex->infile = *argv++;
	if (ft_strnequ(*argv, "awk", 3))
	{
		if (ft_chrcnt(*argv, '\'') % 2)
			return (clean_pipex(&pipex), NULL);
		pipex->cmd_i = ft_split(*argv++, '\'');
		pipex->cmd_i[0] = ft_chrdel(pipex->cmd_i[0], ' ', 1);
	}
	else
		pipex->cmd_i = ft_split(*argv++, ' ');
	pipex->cmd_o = ft_split(*argv++, ' ');
	pipex->outfile = *argv;
	pipex->fd_i = open(pipex->infile, O_RDONLY);
	pipex->fd_o = open(pipex->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (!pipex->cmd_i || !pipex->cmd_o || !pipex->infile || !pipex->outfile
		|| pipex->fd_i < 0 || pipex->fd_o < 0 || !get_paths(&pipex, env))
		return (clean_pipex(&pipex), NULL);
	return (pipex);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	*pipex;

	if (!*++argv || argc != 5)
		return (ft_err_msg("Wrong args number or bad awk use"), 1);
	pipex = init_data(argv, env);
	if (!pipex)
		return (ft_err_msg("Failed to process data"), 1);
	if (pipe(pipex->fd) == -1)
		return (clean_pipex(&pipex), ft_err_msg("pipe() failure"), 1);
	pipex->pid = fork();
	if (pipex->pid == -1)
		return (ft_err_msg("Failed to get PID\n"), clean_pipex(&pipex), 1);
	else if (pipex->pid == 0)
	{
		if (!child(&pipex, env))
			return (clean_pipex(&pipex), 1);
	}
	else
	{
		if (!father(&pipex, env))
			return (clean_pipex(&pipex), 1);
	}
	return (clean_pipex(&pipex), 0);
}
