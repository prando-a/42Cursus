/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:30:58 by gsmets            #+#    #+#             */
/*   Updated: 2024/03/21 07:52:41 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

# define RED     	"\x1b[31m"
# define GREEN   	"\x1b[32m"
# define YELLOW  	"\x1b[33m"
# define BLUE    	"\x1b[34m"
# define MAGENTA	"\x1b[35m"
# define CYAN    	"\x1b[36m"
# define WHITE		"\033[37m"
# define BOLD		"\033[1m"
# define RESET   	"\x1b[0m"
# define CLEAR		"\033[2J"

struct	s_data;

typedef struct s_philo
{
	int					id;
	pthread_t			thread_id;
	pthread_mutex_t		fork;
	int					other_fork_id;
	int					times_eaten;
	long long			last_meal;
	struct s_data		*data;
}						t_philo;

typedef struct s_data
{
	int					philos_num;
	int					life_time;
	int					eating_time;
	int					sleep_time;
	int					times_to_eat;
	long long			start_time;
	int					all_ate;
	int					death_flag;
	pthread_mutex_t		mutex_a;
	pthread_mutex_t		mutex_b;
	t_philo				*philos;
}						t_data;

int						parse_init(t_data *data, char **argv, int argc);
void					philo_msg(t_data *data, int id, char *status);
long long				get_time(void);
void					ft_usleep(long long time, t_data *data);
int						philo_start(t_data *data);

#endif