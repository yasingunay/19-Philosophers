/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:53:57 by ygunay            #+#    #+#             */
/*   Updated: 2023/01/30 11:11:52 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


pthread_mutex_t mutex;



void* routine(void *ptr)
{
	t_philo *philo =	(t_philo *)ptr;
	int i = 0;
	while(i < 1)
	{
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(philo->right_fork);
		printf("Philo %d is eating\n", philo->id);
		sleep(1);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		
		i++;
	}
	return 	NULL;
}


int create_forks(t_data *data)
{
	int i;

	i = 0;
	data->forks = malloc(data->nb_philo * sizeof(t_mutex));
	if(!data->forks)
		return(-1);

	while(i < data->nb_philo)
	{
		if(pthread_mutex_init(&data->forks[i],NULL))
			return(-1);
		
		i++;
	}
	return (1);
	
}


int create_table(t_data *data)
{
	int i = 0;
	data->philos = malloc(data->nb_philo *sizeof(t_philo));
	if(!data->philos)
		ft_error("philo malloc error");

	if(!create_forks(data))
		return(-1);	

	while(i < data->nb_philo)
	{
		data->philos[i].id = i+1;
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + data->nb_philo -1) % data->nb_philo];
		
		pthread_create(&data->philos[i].thread, NULL, &routine, &data->philos[i]);
		
		i++;
	}
	return (1);
}

int	free_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	return (0);
}

int main(int ac, char **av)
{
	t_data data;

	if(ac == 2)
		data.nb_philo = ft_atoi(av[1]);
	else	
	{
		printf("argument number is not correct\n");
		return 1;	
	}
	

	create_table(&data);
	

	
	

	int i =0;
	
	while(i < data.nb_philo)
	{
		
		pthread_join(data.philos[i].thread, NULL);
		i++;
	}
	
	
	free_threads(&data);
	
	
	return (0);
}


