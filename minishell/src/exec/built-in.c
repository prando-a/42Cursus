/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built-in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:58:13 by jose-mgo          #+#    #+#             */
/*   Updated: 2024/02/09 19:05:56 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_env(t_env *lst)
{
	t_env	*p;

	p = lst;
	while (p)
	{
		ft_printf("%s=%s\n", p->env_name, p->env_content);
		p = p->next;
	}
	return (0);
}

int	ft_echo(char **cmd)
{
	int	n_option;
	int	i;

	n_option = cmd[1] && ft_strequ(cmd[1], "-n");
	i = 1 + n_option;
	while (cmd[1] && cmd[i])
	{
		ft_printf("%s", cmd[i++]);
		if (cmd[i])
			ft_printf(" ");
	}
	if (!n_option)
		ft_printf("\n");
	return (0);
}

int	ft_pwd(void)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!pwd)
		return (ft_msg(RED"pwd: Critical error"GREEN), 1);
	ft_printf("%s\n", pwd);
	free(pwd);
	return (0);
}

int	ft_exit(char **code, t_ms *ms)
{
	if (ft_arrnum(code) > 2)
		return (ft_err_msg(RED"exit: Too many arguments"GREEN), 1);
	if (!code[1])
		return (ms->status);
	if (ft_str_islf(code[1]) == 1)
	{
		if (ft_atoll(code[1]) < 256)
			return (ft_atoi(code[1]));
		else
			return (ft_atoi(code[1]) % 256);
	}
	else
		return (ft_err_msg(RED"exit: Wrong value entered"GREEN), 2);
}

int	exec_built_ins(char **cmd, t_ms *ms, t_exec *exc)
{
	if (ft_strequ(cmd[0], "echo"))
		exc->status = ft_echo(cmd);
	else if (ft_strequ(cmd[0], "cd"))
		exc->status = ft_cd(cmd, &(ms->e_lst));
	else if (ft_strequ(cmd[0], "pwd"))
		exc->status = ft_pwd();
	else if (ft_strequ(cmd[0], "unset"))
		exc->status = env_manager(UNSET, cmd, ms);
	else if (ft_strequ(cmd[0], "export"))
		exc->status = env_manager(EXPORT, cmd, ms);
	else if (ft_strequ(cmd[0], "env"))
		exc->status = ft_env(ms->e_lst);
	else if (ft_strequ(cmd[0], "exit"))
		exc->status = ft_exit(cmd, ms);
	return (1);
}
