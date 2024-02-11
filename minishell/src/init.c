/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:00:43 by prando-a          #+#    #+#             */
/*   Updated: 2024/02/09 20:46:25 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	intro(void)
{
	ft_msg(""GREEN"");
	ft_msg("⢀⡴⠑⡄⠀⠀⠀⠀⠀⠀⠀⣀⣀⣤⣤⣤⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀         :::      ::::::::");
	ft_msg("⠸⡇⠀⠿⡀⠀⠀⠀⣀⡴⢿⣿⣿⣿⣿⣿⣿⣿⣷⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀       :+:      :+:    :+:");
	ft_msg("⠀⠀⠀⠀⠑⢄⣠⠾⠁⣀⣄⡈⠙⣿⣿⣿⣿⣿⣿⣿⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀     +:+ +:+         +:+  ");
	ft_msg("⠀⠀⠀⠀⢀⡀⠁⠀⠀⠈⠙⠛⠂⠈⣿⣿⣿⣿⣿⠿⡿⢿⣆⠀⠀⠀⠀⠀⠀⠀   +#+  +:+       +#+     ");
	ft_msg("⠀⠀⠀⢀⡾⣁⣀⠀⠴⠂⠙⣗⡀⠀⢻⣿⣿⠭⢤⣴⣦⣤⣹⠀⠀⠀⢀⢴⣶⣆ +#+#+#+#+#+   +#+        ");
	ft_msg("⠀⠀⢀⣾⣿⣿⣿⣷⣮⣽⣾⣿⣥⣴⣿⣿⡿⢂⠔⢚⡿⢿⣿⣦⣴⣾⠁⠸⣼⡿      #+#    #+#          ");
	ft_msg("⠀⢀⡞⠁⠙⠻⠿⠟⠉⠀⠛⢹⣿⣿⣿⣿⣿⣌⢤⣼⣿⣾⣿⡟⠉⠀⠀⠀⠀⠀     ###   ########       ");
	ft_msg("⠀⣾⣷⣶⠇⠀⠀⣤⣄⣀⡀⠈⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀                          ");
	ft_msg("⠀⠉⠈⠉⠀⠀⢦⡈⢻⣿⣿⣿⣶⣶⣶⣶⣤⣽⡹⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀                          ");
	ft_msg("⠀⠀⠀⠀⠀⠀⠀⠉⠲⣽⡻⢿⣿⣿⣿⣿⣿⣿⣷⣜⣿⣿⣿⡇    "BOLD"by          "RESET GREEN);
	ft_msg("⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣷⣶⣮⣭⣽⣿⣿⣿⣿⣿⣿⣿         "BOLD"prando-a"RESET GREEN);
	ft_msg("⠀⠀⠀⠀⠀⠀⣀⣀⣈⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇         "BOLD"jose-mgo"RESET GREEN);
	ft_msg("⠀⠀⠀⠀⠀⠀⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀⠀⠀⠀⠀                            ");
	ft_msg("⠀⠀⠀⠀⠀⠀⠀⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀                          ");
	ft_msg("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⠻⠿⠿⠿⠿⠛⠉"RESET);
	ft_msg(BOLD"\nWELCOME TO\t\t\t\t\t\t"GREEN"© 2024"RESET RED BOLD);
	ft_msg("___  ________ _   _ _____ _____ _   _ ______ _____ _   __");
	ft_msg("|  \\/  |_   _| \\ | |_   _/  ___| | | || ___ \\  ___| | / /");
	ft_msg("| .  . | | | |  \\| | | | \\ `--.| |_| || |_/ / |__ | |/ / ");
	ft_msg("| |\\/| | | | | . ` | | |  `--. \\  _  ||    /|  __||    \\ ");
	ft_msg("| |  | |_| |_| |\\  |_| |_/\\__/ / | | || |\\ \\| |___| |\\  \\");
	ft_printf("\\_|  |_/\\___/\\_| \\_/\\___/\\____/\\_| |_/\\_| \\_\\____/");
	ft_msg("\\_| \\_/\n\n"RESET);
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

char	**get_path(t_ms *ms)
{
	char		**path;
	char		*path_env;
	static int	warning;

	if (ms->path)
		ft_strdel(ms->path);
	path_env = ft_getenv(ms->e_lst, "PATH", 0);
	path = ft_split(path_env, ':');
	path = path_join(path, "/");
	if (!path && !warning++)
	{
		ft_err_msg(RED BOLD "WARNING!\n" RESET
			RED"Missing PATH. Only built-ins will work."RESET);
		ft_err_msg(RED"To fix this, please set up the PATH."RESET);
	}
	else
		warning = 0;
	if (path_env)
		free(path_env);
	return (path);
}

int	set_shlvl(t_ms *ms)
{
	char	*shlvl;
	int		lvl;

	shlvl = ft_getenv(ms->e_lst, "SHLVL", 0);
	if (!shlvl)
		return (ft_export("SHLVL=1", &ms->e_lst));
	lvl = ft_atoi(shlvl);
	lvl++;
	free(shlvl);
	shlvl = gnl_strjoin("SHLVL=", ft_itoa(lvl), 2, 1);
	ft_export(shlvl, &ms->e_lst);
	return (free(shlvl), 1);
}

int	ms_init(t_ms *ms, char **env)
{
	int	i;

	i = 0;
	while (i++ < 1500)
		ft_printf("\n");
	intro();
	ms->prompt = NULL;
	ms->buffer = NULL;
	ms->status = 0;
	ms->exit_flag = 0;
	ms->e_lst = set_env_list(env);
	if (!ms->e_lst)
		return (ms->status = 2, 0);
	ms->path = NULL;
	ms->path = get_path(ms);
	ft_export("SHELL=minishell", &ms->e_lst);
	set_shlvl(ms);
	ms->new_env = set_env_matrix(ms->e_lst);
	if (!ms->new_env || !ms->path)
		return (ft_strdel(ms->path), ft_strdel(ms->new_env),
			ms->status = 2, 0);
	signal(SIGINT, ms_sigcatch);
	signal(SIGQUIT, ms_sigcatch);
	g_signal = 0;
	return (kill(0, SIGQUIT), 1);
}
