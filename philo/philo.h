/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:36:10 by ygunay            #+#    #+#             */
/*   Updated: 2023/01/26 16:38:04 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_rules
{
	int nb_philo;
} t_rules;

typedef struct s_philo
{
	int id;
	t_rules *rules;
} t_philo;


typedef struct s_setup
{
	t_rules			*rules;
	t_philo			*philos;
	pthread_t		*threads;
	pthread_mutex_t	*mutexes;
}					t_setup;




int ft_atoi(const char *str);
int	ft_error(char *str);