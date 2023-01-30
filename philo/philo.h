/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:36:10 by ygunay            #+#    #+#             */
/*   Updated: 2023/01/30 10:54:38 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef pthread_mutex_t	t_mutex;

typedef struct s_philo
{
	int id;
	pthread_t thread;
	t_mutex	*left_fork;
	t_mutex	*right_fork;
	
	
} t_philo;

typedef struct s_data
{
	int nb_philo;
	t_philo *philos;
	t_mutex *forks;
} t_data;




int ft_atoi(const char *str);
int	ft_error(char *str);