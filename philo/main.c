/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:53:57 by ygunay            #+#    #+#             */
/*   Updated: 2023/01/27 12:06:28 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


pthread_mutex_t mutex;



void* routine()
{
	t_data *data;

	int i = 0;
	while(i < 1)
	{
		pthread_mutex_lock(&mutex);
		printf("Philo %d says hello\n", data->philos[i].id);
		pthread_mutex_unlock(&mutex);
		
		i++;
	}
	return 	NULL;
}

void create_philos(t_data *data)
{
	int i = 0;
	data->philos = malloc(data->nb_philo *sizeof(t_philo));

	while(i < data->nb_philo)
	{
		
		pthread_create(&data->philos[i].thread, NULL, &routine, NULL);
		data->philos[i].id = i+1;
		//printf("%d\n",data->philos[i].id);
		i++;
	}
	
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
	
	create_philos(&data);
	
	pthread_mutex_init(&mutex,NULL);


	int i =0;
	while(i < data.nb_philo)
	{
		
		pthread_join(data.philos[i].thread, NULL);
		i++;
	}
	
	
	pthread_mutex_destroy(&mutex);
	
	return (0);
}


