/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:53:57 by ygunay            #+#    #+#             */
/*   Updated: 2023/01/26 16:37:53 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


pthread_mutex_t mutex;



void* routine()
{
	int i = 0;
	while(i < 1)
	{
		pthread_mutex_lock(&mutex);
		printf("Philo says hello\n");
		pthread_mutex_unlock(&mutex);
		
		i++;
	}
	return 	NULL;
}



int main(int ac, char **av)
{
	t_setup setup;

	setup.rules= malloc(sizeof(t_rules));
	if(!setup.rules)
		ft_error("Memory allocayion is failed");

	if(ac == 2)
		setup.rules->nb_philo= ft_atoi(av[1]);
	else	
	{
		printf("argument number is not correct\n");
		return 1;	
	}
		
	pthread_t philo[setup.rules->nb_philo];
	int i = 0;
	pthread_mutex_init(&mutex,NULL);
	while(i < setup.rules->nb_philo)
	{
		pthread_create(&philo[i], NULL, &routine, NULL);
		i++;
	}
	i = 0;
	while(i < setup.rules->nb_philo)
	{
		pthread_join(philo[i], NULL);
		i++;
	}
	pthread_mutex_destroy(&mutex);
	
	return (0);
}


