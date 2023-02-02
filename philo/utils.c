/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:37:36 by ygunay            #+#    #+#             */
/*   Updated: 2023/02/02 14:59:51 by ygunay           ###   ########.fr       */
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