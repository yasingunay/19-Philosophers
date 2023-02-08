/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:20:02 by ygunay            #+#    #+#             */
/*   Updated: 2023/02/08 15:55:13 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "philo.h"

void ft_usleep(int time)
{
	long	start;

	start = get_time();
	while (get_time() - start < time)
		usleep(100);
}



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




void print_philo_log(t_philo *philo, char *str)
{
	long time;

	time = get_time() - philo->data->start_time;
	if (philo->data->died_philo == 0)
		printf("%ld %d %s", time, philo->id, str);
	
}

// void	ft_check_death(t_data *data)
// {
// 	int		i;
// 	long	now;

// 	while (data->died_philo == 0 )
// 	{
		
// 		usleep(100);
// 		i = 0;
// 		while (i < data->nb_philo)
// 		{
// 			now = get_time();
// 			if (now >= data->philos[i].last_eat + data->t_die)
// 			{
// 				pthread_mutex_lock(data->death);
// 				pthread_mutex_lock(data->log);
// 				data->died_philo = 1;
// 				printf("%ld %d %s", now - data->start_time, i + 1, "died\n");
// 				pthread_mutex_unlock(data->log);
// 				pthread_mutex_unlock(data->death);
// 				break ;
// 			}
// 			i++;
// 		}
		
// 	}
// }






void	*thread_monitor(void *arg)
{
	int		row;
	
	t_data	*data;

	data = (t_data *)arg;
	ft_usleep(data->t_die * 0.9);
	while (1)
	{
		row = 0;
		
		while (row < data->nb_philo)
		{
			
				if (get_time() - data->philos[row].last_eat >= data->t_die)
				{
					printf("died\n");
					data->died_philo = 1;
					return ((void *)0);
				}
	
			row++;
		}
		usleep(200);
	}
}


