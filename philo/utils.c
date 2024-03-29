/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:20:02 by ygunay            #+#    #+#             */
/*   Updated: 2023/02/14 14:50:16 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(int time)
{
	atomic_int	start;

	start = get_time();
	while (get_time() - start < time)
		usleep(100);
}

int	ft_error(char *str)
{
	printf("Error:\n%s\n", str);
	return (-1);
}

atomic_int	get_time(void)
{
	struct timeval		tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

static int	check_death_thread(t_philo *philo)
{
	if (get_time() - philo->last_eat >= philo->data->t_die)
	{
		print_philo_log(philo, 4);
		philo->data->died_philo = 1;
		return (0);
	}
	if (philo->meal_count >= philo->data->must_eat
		&& philo->data->must_eat != -1)
		return (1);
	return (2);
}

void	*death_thread(void *arg)
{
	t_philo	*philo;
	int		i;
	int		nb_done;
	int		ret;

	philo = (t_philo *) arg;
	nb_done = 0;
	while (nb_done != philo->data->nb_philo)
	{
		i = 0;
		nb_done = 0;
		while (i < philo->data->nb_philo)
		{
			ret = check_death_thread(&philo[i]);
			if (ret == 0)
				return (NULL);
			if (ret == 1)
				nb_done++;
			i++;
		}
	}
	philo->data->died_philo = 1;
	return (NULL);
}
