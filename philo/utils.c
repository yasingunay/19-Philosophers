/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2023/02/08 14:16:01 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"



int	ft_error(char *str)
{
	printf("Error:\n%s\n", str);
	return (-1);
}


long	get_time(void)
{

	struct timeval		tv;
	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}




void print_philo_log(t_philo *philo,t_mutex *mutex, char *str)
{
	long time;

	time = get_time() - philo->data->start_time;
	pthread_mutex_lock(mutex);
	if (philo->data->died_philo == 0)
		printf("%ld %d %s", time, philo->id, str);
	pthread_mutex_unlock(mutex);
	
}

void	ft_check_death(t_data *data)
{
	int		i;
	long	now;

	while (data->died_philo == 0 )
	{
		
		usleep(100);
		i = 0;
		while (i < data->nb_philo)
		{
			now = get_time();
			if (now >= data->philos[i].last_eat + data->t_die)
			{
				pthread_mutex_lock(data->death);
				pthread_mutex_lock(data->log);
				data->died_philo = 1;
				printf("%ld %d %s", now - data->start_time, i + 1, "died\n");
				pthread_mutex_unlock(data->log);
				pthread_mutex_unlock(data->death);
				break ;
			}
			i++;
		}
		
	}
}

void	ft_usleep(t_data *data, int time)
{
	long	start;
	long now;

	start = get_time();
	while (data->died_philo == 0)
	{
		now = get_time();
		if(now - start  >= time)
			break;
		usleep(100);
	}
		
}