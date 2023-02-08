/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:36:10 by ygunay            #+#    #+#             */
/*   Updated: 2023/02/08 15:51:04 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>
# include <stdatomic.h>



typedef pthread_mutex_t	t_mutex;

typedef struct s_philo
{
	int id;
	pthread_t thread;
	struct s_data *data;
	t_mutex *left_fork;
	t_mutex *right_fork;
	long int last_eat;
	int meal_count;
	

} t_philo;

typedef struct s_data
{
	int nb_philo;
	int t_die;
	t_philo *philos; 
	t_mutex *forks;
	int t_eat;
	int t_sleep;
	int must_eat;
	int died_philo;
	pthread_t	th_monitor;
	
	long int start_time;

} t_data;


int ft_atoi(const char *str);
int parse_args(t_data *data, int ac, char **av);
void routine(t_philo *philo) ;
int	philo_life(t_philo	*philo);
int  init_mutexes(t_data *data);
void init_philos(t_data *data);
void	launch_philos(t_data *data);
int ft_free(t_data *data);
long	get_time(void);
int	ft_error(char *str);
int init_and_launch (t_data	*data);
void	ft_usleep(int time);
void print_philo_log(t_philo *philo, char *str);
void	*thread_monitor(void *arg);