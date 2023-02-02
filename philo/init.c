/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasingunay <yasingunay@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:31:02 by ygunay            #+#    #+#             */
/*   Updated: 2023/02/02 16:35:22 by yasingunay       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init_mutexes(t_data *data)
{
	int i;
	
	i = 0;
	data->forks = malloc(data->nb_philo * sizeof(t_mutex));
	if(!data->forks)
		{
			free(data->forks);
			printf("malloc error\n");
			exit(1);
		}
	while (i < data->nb_philo)
	{
		 pthread_mutex_init(&data->forks[i] , NULL);
		i++;
	
	}
		
}


void init_philos(t_data *data)
{
	int i;
	
	data->philos = malloc(data->nb_philo * sizeof(t_philo));
	if(!data->philos)
		{
			free(data->philos);
			printf("malloc error\n");
			exit(1);
		}
		
	i = 0;
	while (i < data->nb_philo)
	{
		data->philos[i].id = i+1;
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + data->nb_philo -1) % data->nb_philo];
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
		 pthread_create(&data->philos[i].thread, NULL, philo_life, &data->philos[i]);
		i++;
	
	}
	
	
  i = 0;
  while (i < data->nb_philo)
	{
		 pthread_join(data->philos[i].thread, NULL);
		i++;
	}

}


void ft_free(t_data *data)
{
	int	i;
	i = 0;
   while (i < data->nb_philo)
	{
		 pthread_mutex_destroy(&data->forks[i]);
		i++;
	
	}
	free(data->philos);
	free(data->philos);
	
}