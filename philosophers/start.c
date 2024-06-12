/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:30:36 by prando-a          #+#    #+#             */
/*   Updated: 2024/03/21 12:31:14 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eating(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&(data->philos[philo->id - 1].fork));
	philo_msg(data, philo->id, "has taken a fork");
	pthread_mutex_lock(&(data->philos[philo->other_fork_id].fork));
	philo_msg(data, philo->id, "has taken a fork");
	pthread_mutex_lock(&(data->mutex_b));
	philo_msg(data, philo->id, "is eating");
	philo->last_meal = get_time();
	pthread_mutex_unlock(&(data->mutex_b));
	ft_usleep(data->eating_time, data);
	philo->times_eaten++;
	pthread_mutex_unlock(&(data->philos[philo->id - 1].fork));
	pthread_mutex_unlock(&(data->philos[philo->other_fork_id].fork));
}

void	philo_clear(t_data *data, t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < data->philos_num)
	{
		pthread_join(philos[i].thread_id, NULL);
		pthread_mutex_destroy(&(data->philos[i].fork));
	}
	pthread_mutex_destroy(&(data->mutex_a));
	pthread_mutex_destroy(&(data->mutex_b));
}

void	philo_monitor(t_data *data, t_philo *philos)
{
	int	i;

	while (1)
	{
		i = -1;
		while (++i < data->philos_num && !(data->death_flag))
		{
			if ((get_time() - philos[i].last_meal) > data->life_time)
			{
				philo_msg(data, i, "died");
				data->death_flag = 1;
			}
		}
		i = 0;
		while (data->times_to_eat != -1 && i < data->philos_num
			&& philos[i].times_eaten >= data->times_to_eat)
			i++;
		if (i == data->philos_num || data->death_flag)
			return ;
	}
}

void	*routine(void *arg)
{
	t_philo			*philo;
	t_data			*data;

	philo = arg;
	data = philo->data;
	if (philo->id % 2)
		ft_usleep(data->eating_time, data);
	while (!(data->death_flag))
	{
		if (data->all_ate || philo->times_eaten == data->times_to_eat)
			break ;
		philo_eating(philo);
		philo_msg(data, philo->id, "is sleeping");
		ft_usleep(data->sleep_time, data);
		philo_msg(data, philo->id, "is thinking");
	}
	return (NULL);
}

int	philo_start(t_data *data)
{
	int				i;
	t_philo			*philos;

	i = 0;
	philos = data->philos;
	data->start_time = get_time();
	printf(BOLD);
	if (data->philos_num == 1)
	{
		printf("%lld 1 has taken a fork\n", get_time() - data->start_time);
		ft_usleep(data->life_time, data);
		i++;
	}
	while (i < data->philos_num)
	{
		if (pthread_create(&(philos[i].thread_id), NULL, routine, &philos[i]))
			return (free(data->philos),
				printf(RED BOLD"ERROR\n"RED"Critical pthread fail\n"), 1);
		philos[i].last_meal = get_time();
		i++;
	}
	philo_monitor(data, data->philos);
	philo_clear(data, philos);
	return (printf(RESET), free(data->philos), 0);
}
