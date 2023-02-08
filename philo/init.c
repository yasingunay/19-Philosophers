/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:31:02 by ygunay            #+#    #+#             */
/*   Updated: 2023/02/08 14:15:43 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_free(t_data *data)
{
	int	i;
	i = 0;
	if(data->forks)
	{
		 while (i < data->nb_philo)
		{
			 pthread_mutex_destroy(&data->forks[i]);
			i++;
	
		}
	}
	pthread_mutex_destroy(data->log) ;
	pthread_mutex_destroy(data->death);
	free(data->philos);
	free(data->forks);
	free(data->log);
	free(data->death);
	return (-1);
}


int  init_mutexes(t_data *data)
{
	int i;
	
	i = 0;
	
	
	while (i < data->nb_philo)
	{
		if( pthread_mutex_init(&data->forks[i] , NULL) != 0)
			return (-1);
		i++;
	
	}
	if (pthread_mutex_init(data->log, NULL) != 0)
		return (-1);
	if (pthread_mutex_init(data->death, NULL) != 0)
		return (-1);
	return (0);
}


void init_philos(t_data *data)
{
	int i;
	
	i = 0;
	while (i < data->nb_philo)
	{
		data->philos[i].last_eat = get_time();
		data->philos[i].id = i+1;
		data->philos[i].left_fork = &data->forks[i];  
		if (i == 0)
			data->philos[i].right_fork = &data->forks[(data->nb_philo -1) % data->nb_philo];
		else
			data->philos[i].right_fork = &data->forks[i -1];
		data->philos[i].data = data;
		i++;

	}
	
}


void	launch_philos(t_data *data)
{
	int	i;

	i = 0;
	data->start_time = get_time();
	while (i < data->nb_philo)
	{
		pthread_create(&data->philos[i].thread, NULL, (void *)philo_life, &data->philos[i]);
		i++;
	
	}

	ft_check_death(data);
	
  i = 0;
  while (i < data->nb_philo)
	{
		 pthread_join(data->philos[i].thread, NULL);
		i++;
	}

}


int init_and_launch (t_data	*data)
{
	data->philos = malloc(data->nb_philo * sizeof(t_philo));
	data->forks = malloc(data->nb_philo  * sizeof(t_mutex));
	data->log = malloc(sizeof(t_mutex));
	data->death = malloc(sizeof(t_mutex));
	if( !data->philos || !data->forks || !data->log || !data->death) 
		return (ft_free(data));
	if(init_mutexes(data) == -1)
		return (ft_free(data));
	init_philos(data);
	launch_philos(data);
	ft_free(data);
		
	return (0);
}






