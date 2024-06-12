/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:42:45 by prando-a          #+#    #+#             */
/*   Updated: 2024/03/21 07:49:44 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philos(t_data *data)
{
	int	i;

	data->philos = malloc(sizeof(t_philo) * data->philos_num);
	if (!data->philos)
		return (printf(RED"Malloc error\n"RESET), 0);
	i = data->philos_num;
	while (--i >= 0)
	{
		data->philos[i].id = i;
		data->philos[i].times_eaten = 0;
		data->philos[i].other_fork_id = i % data->philos_num;
		data->philos[i].last_meal = 0;
		data->philos[i].data = data;
		if (pthread_mutex_init(&(data->philos[i].fork), NULL))
			return (printf(RED"Mutex error\n"RESET), 0);
	}
	if (pthread_mutex_init(&(data->mutex_a), NULL))
		return (printf(RED"Mutex error\n"RESET), 0);
	if (pthread_mutex_init(&(data->mutex_b), NULL))
		return (printf(RED"Mutex error\n"RESET), 0);
	return (1);
}

ssize_t	ft_atoll(const char *str)
{
	int				i;
	int				sig;
	ssize_t			res;

	if (!str)
		return (0);
	i = -1;
	sig = 1;
	res = 0;
	while (str[++i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sig = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + (str[i++] - '0');
	return (res * sig);
}

int	valid_nums(char **argv)
{
	int	i;
	int	j;

	j = -1;
	while (argv[++j])
	{
		i = -1;
		if (!argv[j][0])
			return (0);
		while (argv[j][++i])
			if (!(argv[j][i] >= '0' && argv[j][i] <= '9'))
				return (0);
	}
	return (1);
}

int	parse_init(t_data *data, char **argv, int argc)
{
	if (argc < 5 || argc > 6 || !valid_nums(argv))
		return (printf(RED BOLD"ERROR\n"RESET RED"Invalid arguments\n"), 0);
	data->philos_num = ft_atoll(*argv++);
	data->life_time = ft_atoll(*argv++);
	data->eating_time = ft_atoll(*argv++);
	data->sleep_time = ft_atoll(*argv++);
	if (*argv)
		data->times_to_eat = ft_atoll(*argv);
	else
		data->times_to_eat = -1;
	if (data->philos_num == 0 || data->times_to_eat == 0)
		return (0);
	if (!init_philos(data))
		return (0);
	return (data->death_flag = 0, data->all_ate = 0, 1);
}
