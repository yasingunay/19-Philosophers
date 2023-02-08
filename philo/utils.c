/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2023/02/08 10:01:44 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"



int	ft_error(char *str)
{
	printf("Error:\n%s\n", str);
	return (-1);
}


long	get_time(void)
{

	struct timeval		tv;
	
	gettimeofday(&tv, NULL);
	
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}


void	ft_usleep(int time)
{
	int	start;

	start = get_time();
	while (get_time() - start < time)
		usleep(100);
}



void print_philo_log(t_philo *philo, char *str)
{
	long time;

	time = get_time() - philo->data->start_time;
	pthread_mutex_lock(philo->log);
	// if()
	// {
	// 	pthread_mutex_unlock(philo->log);
	// 	return ;
	// }
	printf("%ld %d %s", time, philo->id, str);
	pthread_mutex_unlock(philo->log);
	
}
