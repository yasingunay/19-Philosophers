/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasingunay <yasingunay@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:36:10 by ygunay            #+#    #+#             */
/*   Updated: 2023/02/02 11:10:11 by yasingunay       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdatomic.h>




// typedef struct s_philo
// {
// 	int id;
// 	atomic_long last_eat;
// 	pthread_t thread;
// 	t_mutex	*left_fork;
// 	t_mutex	*right_fork;
// 	struct s_data *datas;
	
// } t_philo;


// typedef struct s_data
// {
// 	int nb_philo;
// 	t_philo *philos;
// 	t_mutex *forks;
// 	int t_die;
// 	int t_eat;
// 	int t_sleep;
// 	int nb_meal;
// 	long start_time;
// 	int die;
// } t_data;



// int	ft_error(char *str);

typedef pthread_mutex_t	t_mutex;

typedef struct s_philo
{
	int id;
	pthread_t thread;
	struct s_data *data;
	t_mutex *left_fork;
	t_mutex *right_fork;
	

} t_philo;

typedef struct s_data
{
	int nb_philo;
	t_philo *philos; 
	t_mutex *forks;

} t_data;


int ft_atoi(const char *str);