/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built-in2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:13:34 by prando-a          #+#    #+#             */
/*   Updated: 2024/02/06 00:01:35 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	cd_checkpath(char *path)
{
	struct stat	path_data;

	if (stat(path, &path_data) == -1)
		return (ft_err_msg(RED"cd: No such file or directory"GREEN), 0);
	if (!S_ISDIR(path_data.st_mode))
		return (ft_err_msg(RED"cd: Not a directory"GREEN), 0);
	if (access(path, X_OK) == -1)
		return (ft_err_msg(RED"cd: Permission denied"GREEN), 0);
	if (chdir(path) == -1)
		return (ft_err_msg(RED"cd: chdir() unknown error"GREEN), 0);
	return (1);
}

int	ft_cd(char **new_pwd, t_env **env)
{
	char	*aux;
	char	*pwd;

	if (ft_arrnum(new_pwd) > 2)
		return (ft_err_msg(RED"cd: Only one argument is allowed"GREEN), 1);
	if (!new_pwd[1] || (new_pwd[1][0] == '~' && !new_pwd[1][1]))
	{
		aux = ft_getenv(*env, "HOME", 0);
		if (!aux)
			return (0);
		return (chdir(aux), free(aux), 0);
	}
	pwd = getcwd(NULL, 0);
	if (new_pwd[1][0] == '/')
		aux = ft_strdup(new_pwd[1]);
	else
		aux = gnl_strjoin(gnl_strjoin(pwd, "/", 0, 0), new_pwd[1], 1, 0);
	if (!cd_checkpath(aux))
		return (free(aux), free(pwd), 1);
	aux = gnl_strjoin("PWD=", aux, 2, 0);
	pwd = gnl_strjoin("OLDPWD=", pwd, 2, 0);
	return (ft_export(aux, env), ft_export(pwd, env),
		free(aux), free(pwd), 0);
}

int	ft_unset(char *var, t_env *lst)
{
	t_env	*del;
	t_env	*aux;

	if (!var)
		return (0);
	del = lst;
	aux = lst;
	while (del && !ft_strequ(del->env_name, var))
		del = del->next;
	while (del && aux->next && !ft_strequ(del->env_name, aux->next->env_name))
		aux = aux->next;
	if (del && aux && ft_strequ(del->env_name, var))
	{
		aux->next = del->next;
		free(del->env_name);
		free(del->env_content);
		free(del);
		return (0);
	}
	return (0);
}

int	ft_export(char *var, t_env **head)
{
	t_env	*p;

	p = *head;
	if (!ft_strchr(var, '='))
		return (0);
	while (p)
	{
		if (ft_strnequ(p->env_name, var, ft_strlen(p->env_name)))
		{
			free(p->env_content);
			p->env_content = ft_strdup(ft_strchr(var, '=') + 1);
			return (0);
		}
		p = p->next;
	}
	return (ft_add_env(var, head), 0);
}

int	env_manager(int mode, char **cmd, t_ms *ms)
{
	int		i;
	int		status;

	status = 0;
	i = 0;
	if (mode == EXPORT)
	{
		if (!cmd[1])
			return (ft_env(ms->e_lst));
		while (cmd[++i])
			status = ft_export(cmd[i], &ms->e_lst);
	}
	else if (mode == UNSET)
	{
		while (cmd[++i])
			status = ft_unset(cmd[i], ms->e_lst);
	}
	ms->path = get_path(ms);
	ft_strdel(ms->new_env);
	ms->new_env = set_env_matrix(ms->e_lst);
	return (status);
}
