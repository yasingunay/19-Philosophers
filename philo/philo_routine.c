/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:25:20 by ygunay            #+#    #+#             */
/*   Updated: 2023/02/08 15:57:41 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void routine(t_philo *philo) 
{
	while(philo->data->died_philo == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		print_philo_log(philo, "has taken a fork\n");
		pthread_mutex_lock(philo->right_fork);
		print_philo_log(philo,"has taken a fork\n");
		print_philo_log(philo,"is eating\n");
		philo->last_eat = get_time();
		ft_usleep(philo->data->t_eat);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		//philo->meal_count += 1;
		print_philo_log(philo, "is sleeping\n");
		ft_usleep(philo->data->t_sleep);
		print_philo_log(philo, "is thinking\n");
	}
	return ;
   	
	
}

int	philo_life(t_philo	*philo)
{

	if (philo->id % 2 == 0)
		ft_usleep(philo->data->t_eat / 2);
	if(philo->data->died_philo == 0)
		routine(philo);
	return (1);
}
