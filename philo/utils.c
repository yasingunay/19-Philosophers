/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:37:36 by ygunay            #+#    #+#             */
/*   Updated: 2023/01/26 16:37:02 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_error(char *str)
{
	printf("Error:\n%s\n", str);
	return (-1);
}

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