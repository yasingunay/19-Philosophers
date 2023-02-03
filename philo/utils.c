/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2023/02/03 11:24:39 by ygunay           ###   ########.fr       */
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