/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:20:02 by ygunay            #+#    #+#             */
/*   Updated: 2023/02/09 18:15:05 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"

void ft_usleep(int time)
{
	int	start;

	start = get_time();
	while (get_time() - start < time)
		usleep(100);
}



int	ft_error(char *str)
{
	printf("Error:\n%s\n", str);
	return (-1);
}


int	get_time(void)
{
	struct timeval		tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}




void print_philo_log(t_philo *philo, int action)
{
	int	time;

	time = get_time() - philo->data->start_time;
	pthread_mutex_lock(philo->print);
	if (philo->data->died_philo)
	{
		pthread_mutex_unlock(philo->print);
		return ;
	}
	if (action == 0)
		printf("%d %d has taken a fork\n", time, philo->id);
	else if (action == 1)
		printf("%d %d is eating\n", time, philo->id);
	else if (action == 2)
		printf("%d %d is sleeping\n", time, philo->id);
	else if (action == 3)
		printf("%d %d is thinking\n", time, philo->id);
	else if (action == 4)
		printf("%d %d died\n", time, philo->id);
	pthread_mutex_unlock(philo->print);
	
	
	
}


static int	check_death_thread(t_philo *philo)
{
	//write(2,"e",1);
	if (get_time() - philo->last_eat >= philo->data->t_die)
	{
		print_philo_log(philo, 4);
		philo->data->died_philo = 1;
		return (0);
	}
	if (philo->meal_count>= philo->data->must_eat
		&& philo->data->must_eat != -1)
		return (1);
	return (2);
}

void	*death_thread(void *arg)
{
	t_philo *philos;
	int		i;
	int		nb_done;
	int		ret;

	
	philos = (t_philo *) arg;
	nb_done = 0;
	while (nb_done != philos[0].data->nb_philo)
	{
		i = 0;
		nb_done = 0;
		while (i < philos[0].data->nb_philo)
		{
			ret = check_death_thread(&philos[i]);
			if (ret == 0)
				{
					
					return (NULL);
				}
				
			if (ret == 1)
				nb_done++;
			i++;
		}
	}
	philos[0].data->died_philo =1;
	return (NULL);
}
