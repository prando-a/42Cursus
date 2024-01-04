/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:08:19 by prando-a          #+#    #+#             */
/*   Updated: 2024/01/03 18:22:43 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	get_heredoc(char *limiter, int fd)
{
	char	*aux;
	char	*limiter_nl;

	fd = open("tmp_heredoc", O_RDWR | O_CREAT | O_TRUNC, 0666);
	limiter_nl = gnl_strjoin(limiter, "\n", 0, 0);
	ft_putstr_fd("> ", STDOUT_FILENO);
	aux = get_next_line(STDIN_FILENO);
	while (aux && limiter_nl && !ft_strequ(aux, limiter_nl))
	{
		ft_putstr_fd(aux, fd);
		free(aux);
		ft_putstr_fd("> ", 1);
		aux = get_next_line(STDIN_FILENO);
	}
	close(fd);
	fd = open("tmp_heredoc", O_RDONLY);
	return (free(limiter_nl), fd);
}

char	***set_cmdv(char **argv, int cmdc, int cmd)
{
	char	***cmdv;
	int		i;

	cmdv = ft_calloc(cmdc + 1, sizeof(char **));
	i = 0;
	while (cmdv && argv[cmd + 1])
	{
		if (ft_strnequ(argv[cmd], "awk", 3) || ft_strnequ(argv[cmd], "sed", 3))
		{
			if (ft_chrcnt(argv[cmd], '\'') % 2)
				return (ft_tridel(cmdv), NULL);
			cmdv[i] = ft_split(argv[cmd++], '\'');
			if (cmdv[i])
				cmdv[i][0] = ft_chrdel(cmdv[i][0], ' ', 1);
		}
		else
			cmdv[i] = ft_split(argv[cmd++], ' ');
		if (!cmdv[i++])
			return (ft_tridel(cmdv), NULL);
	}
	return (cmdv);
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

char	**get_path(char **env)
{
	int		i;
	char	**path;
	char	*aux;

	i = 0;
	while (env[i] && !ft_strnequ(env[i], "PATH=", 5))
		i++;
	path = ft_split(env[i], ':');
	aux = ft_strdup(ft_strchr(path[0], '/'));
	free(path[0]);
	path[0] = aux;
	path = path_join(path, "/");
	return (path);
}

t_pipex	*init_data(int argc, char **argv, char **env, int heredoc)
{
	t_pipex	*pipex;
	int		i;

	i = -1;
	while (argv[++i])
	{
		if (!((i == 2 && heredoc) || argv[i][0]))
			return (NULL);
	}
	pipex = ft_calloc(1, sizeof(t_pipex));
	if (!pipex)
		return (NULL);
	if (heredoc)
		pipex->fd_i = get_heredoc(argv[2], pipex->fd_i);
	else
		pipex->fd_i = open(argv[1], O_RDONLY);
	pipex->cmdc = argc - (3 + heredoc);
	pipex->fd_o = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	pipex->cmdv = set_cmdv(argv, pipex->cmdc, 2 + heredoc);
	pipex->path = get_path(env);
	if (pipex->fd_i < 0 || pipex->fd_o < 0 || !pipex->cmdv || !pipex->path)
		return (clean_pipex(&pipex, heredoc), NULL);
	return (pipex);
}
