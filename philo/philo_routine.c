/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasingunay <yasingunay@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:25:20 by ygunay            #+#    #+#             */
/*   Updated: 2023/02/02 16:44:41 by yasingunay       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void routine(t_philo *philo) 
{
   pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->right_fork);
   
    if((get_time() - philo->data->start_time) >= philo->data->t_die) {
		philo->data->die = 1;
		return ;
	}
   	printf("%d philo is eating\n",philo->id);
   	//philo->last_eat = get_time();
   	sleep(1);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);

}

void	*philo_life(void *arg)
{
	t_philo	*philo;
	
	
	philo = (t_philo *) arg;
	if (philo->id % 2 == 0)
		sleep(2);
	while (1)
	{
		if (philo->data->die == 1)
			exit(0);
		routine(philo);
		
		
	}
		
	return (NULL);
}
