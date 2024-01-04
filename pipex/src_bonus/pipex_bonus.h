/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 19:58:24 by prando-a          #+#    #+#             */
/*   Updated: 2024/01/03 18:49:37 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include "../libft/libft.h"
# include <sys/wait.h>

# define READ 0
# define WRITE 1

typedef struct s_pipex
{
	pid_t	pid;
	int		child;
	int		cmdc;
	int		fd_i;
	int		fd_o;
	int		fd[2];
	char	***cmdv;
	char	**path;
}	t_pipex;

t_pipex	*init_data(int argc, char **argv, char **env, int heredoc);
char	**get_path(char **env);
char	**path_join(char **arr, char *str);
char	***set_cmdv(char **argv, int cmdc, int cmd);
int		get_heredoc(char *limiter, int fd);

void	clean_pipex(t_pipex **pipex, int heredoc);

void	child(t_pipex **pipex, int child, char **env);
int		get_cmd_pos(char **path);

#endif