/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:31:02 by ygunay            #+#    #+#             */
/*   Updated: 2023/02/09 18:52:15 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_free(t_data *data)
{
	int	i;

	if(data->forks)
	{
		i = 0;
		 while (i < data->nb_philo + 1 )
		 {
			 pthread_mutex_destroy(&data->forks[i]);
			i++;
	
		}
	}
	free(data->threads);
	free(data->philos);
	free(data->forks);
	
	return (-1);
}


int  init_mutexes(t_data *data)
{
	int i;
	
	i = 0;
	
	
	while (i < data->nb_philo + 1)
	{
		if( pthread_mutex_init(&data->forks[i] , NULL) != 0)
			return (-1);
		i++;
	
	}

	
	return (0);
}


void init_philos(t_data *data)
{
	int i;
	
	i = 0;
	while (i < data->nb_philo)
	{
		data->philos[i].id = i + 1;
		data->philos[i].thread = &data->threads[i];
		data->philos[i].left_fork = &data->forks[i];  
		if (i == 0)
			data->philos[i].right_fork = &data->forks[(data->nb_philo -1) % data->nb_philo];
		else
			data->philos[i].right_fork = &data->forks[i -1];
		data->philos[i].print = &data->forks[data->nb_philo];
		data->philos[i].meal_count = 0;
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
		data->philos[i].last_eat = data->start_time;
		pthread_create(data->philos[i].thread, NULL, philo_life, &(data->philos[i]));
		i++;
	}

	pthread_create(&data->threads[data->nb_philo], NULL, death_thread, data->philos);
	
	
  	pthread_join(data->threads[data->nb_philo], NULL);
 	i = 0;
  	while (i < data->nb_philo )
	{
		 pthread_join(*(data->philos[i].thread), NULL);
		i++;
	}

}


int init_and_launch (t_data	*data)
{
	data->philos = malloc(data->nb_philo * sizeof(t_philo));
	data->threads = malloc((data->nb_philo + 1) * sizeof(pthread_t));
	data->forks = malloc((data->nb_philo + 1)  * sizeof(t_mutex));
	
	if( !data->philos || !data->forks || !data->threads ) 
		return (ft_free(data));
	if(init_mutexes(data) == -1)
		return (ft_free(data));
	init_philos(data);
	launch_philos(data);
	ft_free(data);
		
	return (0);
}






