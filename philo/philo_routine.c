/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasingunay <yasingunay@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:25:20 by ygunay            #+#    #+#             */
/*   Updated: 2023/02/03 10:35:20 by yasingunay       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void routine(t_philo *philo) 
{
	
   	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->right_fork);
  	printf("[% .6ld] %d philo is eating\n", get_time() - philo->data->start_time ,philo->id);
   	sleep(1);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	*philo_life(void *arg)
{
	t_philo	*philo;
	int i = 0;
	
	philo = (t_philo *) arg;
	if (philo->id % 2 == 0)
		sleep(2);
	while (i < 1)
	{
		routine(philo);
		i++;
	}
	return (NULL);
}
