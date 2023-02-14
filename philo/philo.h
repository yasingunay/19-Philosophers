/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:25:03 by ygunay            #+#    #+#             */
/*   Updated: 2023/02/14 14:29:32 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHILO_H
# define PHILO_H

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
	int				id;
	pthread_t		*thread;
	struct s_data	*data;
	t_mutex			*left_fork;
	t_mutex			*right_fork;
	t_mutex			*print;
	atomic_int		last_eat;
	atomic_int		meal_count;
}	t_philo;

typedef struct s_data
{
	atomic_int	start_time;
	int			nb_philo;
	int			t_die;
	t_philo		*philos;
	t_mutex		*forks;
	int			t_eat;
	int			t_sleep;
	int			must_eat;
	atomic_int	died_philo;
	pthread_t	*threads;
}	t_data;

atomic_int	get_time(void);
void		print_philo_log(t_philo *philo, int action);
void		*death_thread(void *arg);
int			ft_atoi(const char *str);
int			parse_args(t_data *data, int ac, char **av);
void		*philo_life(void *arg);
int			init_mutexes(t_data *data);
void		init_philos(t_data *data);
void		launch_philos(t_data *data);
int			ft_free(t_data *data);
int			ft_error(char *str);
int			init_and_launch(t_data *data);
void		ft_usleep(int time);

#endif
