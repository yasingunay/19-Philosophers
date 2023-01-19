/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:36:10 by ygunay            #+#    #+#             */
/*   Updated: 2023/01/19 16:26:22 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 2

typedef struct s_philo {
    int id;
    pthread_t thread;
    pthread_mutex_t left_fork;
    pthread_mutex_t right_fork;
} t_philo;