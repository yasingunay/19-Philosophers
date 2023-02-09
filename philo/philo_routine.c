/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:25:20 by ygunay            #+#    #+#             */
/*   Updated: 2023/02/09 18:14:25 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void routine(t_philo *philo) 
{
	
	pthread_mutex_lock(philo->left_fork);
	
	print_philo_log(philo, 0);
	
	if (philo->data->died_philo == 1)
	{
		ft_usleep(philo->data->t_die * 2);
		return ;
	}
	
	pthread_mutex_lock(philo->right_fork);
	print_philo_log(philo, 0);
	print_philo_log(philo, 1);
	philo->last_eat = get_time();
	ft_usleep(philo->data->t_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	philo->meal_count += 1;
	print_philo_log(philo, 2);
	ft_usleep(philo->data->t_sleep);
	print_philo_log(philo, 3);
	
}

void	*philo_life(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->t_eat / 2);
	while(!philo->data->died_philo)
		routine(philo);
	return (NULL);
}
