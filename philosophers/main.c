/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:10:58 by prando-a          #+#    #+#             */
/*   Updated: 2024/03/21 07:53:32 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	current;

	gettimeofday(&current, NULL);
	return ((current.tv_sec * 1000) + (current.tv_usec / 1000));
}

void	ft_usleep(long long time, t_data *data)
{
	long long	aux;

	aux = get_time();
	while (1)
	{
		if ((get_time() - aux) >= time)
			return ;
	}
}

void	philo_msg(t_data *data, int id, char *status)
{
	pthread_mutex_lock(&(data->mutex_a));
	if (!(data->death_flag))
		printf("%lld %i %s\n", get_time() - data->start_time, id + 1, status);
	pthread_mutex_unlock(&(data->mutex_a));
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (!parse_init(&data, ++argv, argc))
		return (1);
	return (philo_start(&data));
}
