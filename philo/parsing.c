/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:21:50 by ygunay            #+#    #+#             */
/*   Updated: 2023/02/02 15:36:17 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_atoi(const char *str)
{
	int nbr;
	int i;

	nbr = 0;
	i = 0;
	
	while(str[i])
	{
		if(str[i] < 48 || str[i] > 57)
			return (-1);
		i++;
	}
	i = 0;
	while(str[i])
	{
		nbr = (nbr * 10) +str[i] - 48;
		i++;
	}
	return(nbr);
}

void parse_args(t_data *data, int ac, char **av)
{
	if (ac == 2)
	{
		data->nb_philo = ft_atoi(av[1]);
		//data->t_die = ft_atoi(av[2]);
	}
		
}