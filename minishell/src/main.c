/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:40:11 by jose-mgo          #+#    #+#             */
/*   Updated: 2024/02/10 00:11:26 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	g_signal;

void	ms_sigcatch(int sig)
{
	struct sigaction	sa;

	sa.sa_handler = SIG_IGN;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (sig == SIGINT && g_signal == 0)
	{
		ft_msg(RESET"");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else if (sig == SIGINT && g_signal == 1)
	{
		ft_msg("");
		exit(42);
	}
	if (sig == SIGQUIT)
		sigaction(SIGQUIT, &sa, NULL);
}

char	*set_prompt(char *str, int status, t_env *env)
{
	char		*prompt;
	char		*aux;

	if (str)
		free(str);
	aux = ft_getenv(env, "USER", 0);
	if (!aux)
		aux = ft_getenv(env, "LOGNAME", 0);
	if (!aux)
		aux = ft_strdup("minishell");
	prompt = gnl_strjoin(BOLD, aux, 2, 0);
	if (status == 0)
		prompt = gnl_strjoin(prompt, GREEN"$ "RESET, 1, 0);
	else
		prompt = gnl_strjoin(prompt, RED"$ "RESET, 1, 0);
	return (prompt);
}

int	minishell(t_ms *ms, t_cmd *cmd)
{
	while (!ms->exit_flag)
	{
		g_signal = 0;
		if (ms->buffer)
			free(ms->buffer);
		ms->prompt = set_prompt(ms->prompt, ms->status, ms->e_lst);
		ms->buffer = readline(ms->prompt);
		if (!ms->buffer)
			break ;
		if (!*ms->buffer || !ms_quotes(ms) || check_cnt(ms->buffer)
			|| !check_illegal_char(ms->buffer))
			continue ;
		add_history(ms->buffer);
		cmd = ms_parser(ms->buffer, ms->e_lst, ms->status);
		if (syntax_check(cmd))
			ms->status = ms_exec(ms, cmd);
		else
			ms->status = 1;
		ft_free_cmd(cmd);
	}
	if (ms->buffer)
		free(ms->buffer);
	return (free(ms->prompt), clear_env_lst(ms->e_lst),
		ft_strdel(ms->path), ft_strdel(ms->new_env), 0);
}

int	main(int argc, char **argv, char **env)
{
	t_ms	ms;

	(void)argc;
	(void)argv;
	if (!ms_init(&ms, env))
		return (ms.status);
	return (minishell(&ms, NULL), ms.status);
}
