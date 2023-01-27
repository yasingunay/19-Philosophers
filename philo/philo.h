/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:36:10 by ygunay            #+#    #+#             */
/*   Updated: 2023/01/27 11:40:34 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>



typedef struct s_philo
{
	int id;
	pthread_t thread;
} t_philo;

typedef struct s_data
{
	int nb_philo;
	t_philo *philos;
} t_data;




int ft_atoi(const char *str);
int	ft_error(char *str);