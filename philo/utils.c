/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:20:02 by ygunay            #+#    #+#             */
/*   Updated: 2023/02/09 16:37:42 by ygunay           ###   ########.fr       */
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

// void	ft_check_death(t_data *data)
// {
// 	int		i;
// 	long	now;

// 	while (data->died_philo == 0 )
// 	{
		
// 		usleep(100);
// 		i = 0;
// 		while (i < data->nb_philo)
// 		{
// 			now = get_time();
// 			if (now >= data->philos[i].last_eat + data->t_die)
// 			{
// 				pthread_mutex_lock(data->death);
// 				pthread_mutex_lock(data->log);
// 				data->died_philo = 1;
// 				printf("%ld %d %s", now - data->start_time, i + 1, "died\n");
// 				pthread_mutex_unlock(data->log);
// 				pthread_mutex_unlock(data->death);
// 				break ;
// 			}
// 			i++;
// 		}
		
// 	}
// }






// void	*thread_monitor(void *arg)
// {
// 	int		row;
// 	t_data	*data;

// 	data = (t_data *)arg;
// 	ft_usleep(data->t_die * 0.9);
// 	while (1)
// 	{
// 		row = 0;
		
// 		while (row < data->nb_philo)
// 		{
				
// 				if (get_time() - data->philos[row].last_eat >= data->t_die)
// 				{
// 					data->died_philo = 1;
// 					print_philo_log(&data->philos[row], "died\n");
// 					return ((void *)0);
// 				}
				
	
// 			row++;
// 		}
// 		usleep(200);
// 	}
// }




static int	check_death_thread(t_philo *philo)
{
	if (get_time() - philo->last_eat >= philo->data->t_die)
	{
		philo_print_log(philo, 4);
		philo->data->died_philo = 1;
		return (0);
	}
	if (philo->last_eat >= philo->data->must_eat
		&& philo->data->must_eat != -1)
		return (1);
	return (2);
}

void	*death_thread(void *arg)
{
	t_philo	*philos;
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
				return (NULL);
			if (ret == 1)
				nb_done++;
			i++;
		}
	}
	philos[0].data->died_philo = 1;
	return (NULL);
}
