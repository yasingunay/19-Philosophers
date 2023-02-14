/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:21:50 by ygunay            #+#    #+#             */
/*   Updated: 2023/02/14 14:38:01 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	nbr;
	int	i;

	nbr = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (-1);
		i++;
	}
	i = 0;
	while (str[i])
	{
		nbr = (nbr * 10) + str[i] - 48;
		i++;
	}
	return (nbr);
}

int	parse_args(t_data *data, int ac, char **av)
{
	data->died_philo = 0;
	data->nb_philo = ft_atoi(av[1]);
	data->t_die = ft_atoi(av[2]);
	data->t_eat = ft_atoi(av[3]);
	data->t_sleep = ft_atoi(av[4]);
	data->must_eat = -1;
	if (ac == 6)
		data->must_eat = ft_atoi(av[5]);
	if (data->nb_philo < 1 || data->t_die < 1 || data->t_eat < 1
		|| data->t_sleep < 1)
		return (-1);
	if (ac == 6 && data->must_eat < 1)
		return (-1);
	return (0);
}
