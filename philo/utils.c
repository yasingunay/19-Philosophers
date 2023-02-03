/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasingunay <yasingunay@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2023/02/03 10:19:14 by yasingunay       ###   ########.fr       */
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