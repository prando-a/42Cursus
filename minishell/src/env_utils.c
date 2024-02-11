/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:33:37 by prando-a          #+#    #+#             */
/*   Updated: 2024/02/01 19:14:42 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	clear_env_lst(t_env *lst)
{
	t_env	*current;
	t_env	*temp;

	current = lst;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp->env_name);
		free(temp->env_content);
		free(temp);
	}
}

char	*ft_getenv(t_env *env, char *haystack, int status)
{
	t_env	*p;

	p = env;
	if (haystack[0] == '?' && haystack[1] == 0)
		return (ft_itoa(status));
	while (p && !ft_strequ(p->env_name, haystack))
		p = p->next;
	if (!p)
		return (NULL);
	return (ft_strdup(p->env_content));
}

char	**set_env_matrix(t_env *env)
{
	int		i;
	t_env	*p;
	char	**res;

	i = 0;
	p = env;
	while (p)
	{
		i++;
		p = p->next;
	}
	res = ft_calloc(i + 1, sizeof(char *));
	i = 0;
	p = env;
	while (res && p)
	{
		res[i] = gnl_strjoin(p->env_name, "=", 0, 0);
		res[i] = gnl_strjoin(res[i], p->env_content, 1, 0);
		i++;
		p = p->next;
	}
	return (res);
}

int	ft_add_env(char *env, t_env **head)
{
	int		i;
	t_env	*p;
	t_env	*last;

	p = ft_calloc(sizeof(t_env), 1);
	i = 0;
	while (env[i] && env[i] != '=')
		i++;
	p->env_name = ft_substr(env, 0, i);
	p->env_content = ft_strdup(ft_strchr(env, '=') + 1);
	if (!*head)
		*head = p;
	else
	{
		last = *head;
		while (last->next)
			last = last->next;
		last->next = p;
	}
	return (1);
}

t_env	*set_env_list(char **env)
{
	int		i;
	t_env	*head;

	i = -1;
	head = NULL;
	while (env[++i])
	{
		if (!ft_add_env(env[i], &head))
			return (clear_env_lst(head),
				ft_err_msg("FAILED TO SET UP ENV"), NULL);
	}
	return (head);
}
