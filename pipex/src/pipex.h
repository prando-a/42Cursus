/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 19:58:24 by prando-a          #+#    #+#             */
/*   Updated: 2024/01/03 18:38:40 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../libft/libft.h"
# include <sys/wait.h>

# define READ_END 0
# define WRITE_END 1

typedef struct s_pipex
{
	pid_t	pid;
	char	**path_i;
	char	**path_o;
	char	**cmd_i;
	char	**cmd_o;
	char	*infile;
	char	*outfile;
	int		fd_i;
	int		fd_o;
	int		fd[2];
}	t_pipex;

int		get_cmd_pos(char **path);

int		father(t_pipex **pipex, char **env);
int		child(t_pipex **pipex, char **env);

#endif