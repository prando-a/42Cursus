/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:10:45 by prando-a          #+#    #+#             */
/*   Updated: 2024/01/03 18:16:24 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	clean_pipex(t_pipex **pipex, int heredoc)
{
	if ((*pipex)->cmdv)
		ft_tridel((*pipex)->cmdv);
	if ((*pipex)->path)
		ft_strdel((*pipex)->path);
	close((*pipex)->fd_i);
	close((*pipex)->fd_o);
	close((*pipex)->fd[READ]);
	close((*pipex)->fd[WRITE]);
	if (heredoc && (*pipex)->fd_i > 0)
		unlink("tmp_heredoc");
	free(*pipex);
}

void	father_output(t_pipex **pipex)
{
	char	*output;

	output = ft_file_to_str((*pipex)->fd[READ]);
	if (!output)
		ft_err_msg("ERROR\n");
	ft_putstr_fd(output, (*pipex)->fd_o);
	free(output);
}

void	father_input(t_pipex **pipex)
{
	dup2((*pipex)->fd[READ], STDIN_FILENO);
	close((*pipex)->fd[WRITE]);
	waitpid((*pipex)->pid, NULL, 0);
}

int	main(int argc, char **argv, char **env)
{
	int			heredoc;
	t_pipex		*pipex;

	heredoc = (argc > 1) && ft_strequ(argv[1], "here_doc");
	if (argc < 5 || (heredoc && argc < 6))
		return (ft_err_msg("Wrong args number or bad awk use"), 1);
	pipex = init_data(argc, argv, env, heredoc);
	if (!pipex)
		return (ft_err_msg("Failed to proccess data"), 1);
	dup2(pipex->fd_i, STDIN_FILENO);
	while (pipex->child++ < pipex->cmdc)
	{
		if (pipe(pipex->fd) == -1)
			return (clean_pipex(&pipex, heredoc), ft_err_msg("pipe() fail"), 1);
		pipex->pid = fork();
		if (pipex->pid == -1)
			return (ft_err_msg("Critical fork() failure"), 1);
		if (pipex->pid == 0)
			child(&pipex, pipex->child, env);
		father_input(&pipex);
	}
	return (father_output(&pipex), clean_pipex(&pipex, heredoc), 0);
}
