/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasingunay <yasingunay@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:53:57 by ygunay            #+#    #+#             */
/*   Updated: 2023/02/02 13:41:46 by yasingunay       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// // long	get_time(void)
// // {
// // 	struct timeval		tv;

// // 	gettimeofday(&tv, NULL);
	
// // 	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
// // }


// // void	ft_sleep(int time)
// // {
// // 	int	start;

// // 	start = get_time();
// // 	while (get_time() - start < time)
// // 		usleep(250);
// // }

// t_mutex mutex;

// void* routine(void *ptr)
// {
// 	t_philo *philo =	(t_philo *)ptr;
	
// 	int i = 0;
	
// 	while(i < 1)
// 	{
// 		pthread_mutex_lock(philo->left_fork);
// 		printf("Philo %d has taken a fork\n", philo->id);
// 		//pthread_mutex_lock(philo->right_fork);
// 		//printf("Philo %d has taken a fork\n", philo->id);
// 		printf("Philo %d is eating\n", philo->id);
// 		write(2,"e",1);
// 		sleep(1);
// 		//ft_sleep(philo->datas->t_eat);
// 		pthread_mutex_unlock(philo->left_fork);
// 		pthread_mutex_unlock(philo->right_fork);
// 		printf("Philo %d is sleeping\n", philo->id);
// 		//sleep(3);
// 		//ft_sleep(philo->datas->t_sleep);
// 		printf("Philo %d is thinking\n", philo->id);
		
// 		i++;
// 	}
// 	return NULL;
// }


// int create_forks(t_data *data)
// {
// 	int i;

// 	i = 0;
// 	data->forks = malloc(data->nb_philo * sizeof(t_mutex));
// 	if(!data->forks)
// 		return(-1);

// 	while(i < data->nb_philo)
// 	{
// 		if(pthread_mutex_init(&data->forks[i],NULL))
// 			return(-1);
		
// 		i++;
// 	}
// 	return (1);
	
// }


// int create_table(t_data *data)
// {
// 	int i = 0;
// 	data->philos = malloc(data->nb_philo *sizeof(t_philo));
// 	if(!data->philos)
// 		ft_error("philo malloc error");

// 	if(!create_forks(data))
// 		return(-1);	

// 	//data->start_time = get_time();
// 	while(i < data->nb_philo)
// 	{
// 		data->philos[i].id = i+1;
// 		//data->philos[i].left_fork = &data->forks[i];
// 		//data->philos[i].right_fork = &data->forks[(i + data->nb_philo -1) % data->nb_philo];
// 		//data->philos[i].datas = data;
		
// 		pthread_create(&data->philos[i].thread, NULL, &routine, &data->philos[i]);
		
// 		i++;
// 	}
// 	return (1);
// }

// int	free_threads(t_data *data)
// {
// 	int	i;

// 	i = 0;
// 	while (i < data->nb_philo)
// 	{
// 		pthread_mutex_destroy(&data->forks[i]);
// 		i++;
// 	}
// 	return (0);
// }


// int init_args(t_data *data, char **av)
// {
// 	data->nb_philo = ft_atoi(av[1]);
// 	// data->t_die = ft_atoi(av[2]);
// 	// data->t_eat = ft_atoi(av[3]);
// 	// data->t_sleep = ft_atoi(av[4]);
		
// 	// if(ac == 6)
// 	// 	data->nb_meal = ft_atoi(av[5]);
// 	// if(data->nb_philo < 1 || data->t_die < 1 || data->t_eat < 1 || data->t_sleep < 1)
// 	// 	return(-1);
// 	// if(ac == 6 &&  data->nb_meal < 1)
// 	// 	return(-1);
	
	
// 	return(0);
// }


// int main(int ac, char **av)
// {
// 	t_data data;
	
// 	if (ac ==2)
// 	{
// 		init_args(&data,av);
// 			//return(ft_error("At least one argument is invalid"));
// 	}
// 	// if(ac < 5 || ac > 6)
// 	// 	return(ft_error("Argument number is not correct"));
	

// 	create_table(&data);
	

	
// 	int i =0;
// 	while(i < data.nb_philo)
// 	{
		
// 		pthread_join(data.philos[i].thread, NULL);
// 		i++;
// 	}
	
// 	free_threads(&data);
// 	return (0);
// }
void parse_args(t_data *data, int ac, char **av)
{
	if (ac ==2)
		data->nb_philo = ft_atoi(av[1]);
}



void init_philos(t_data *data)
{
	int i;
	
	data->philos = malloc(data->nb_philo * sizeof(t_philo));
	if(!data->philos)
		{
			free(data->philos);
			printf("malloc error\n");
			exit(1);
		}

	data->forks = malloc(data->nb_philo * sizeof(t_mutex));
	if(!data->forks)
		{
			free(data->forks);
			printf("malloc error\n");
			exit(1);
		}
		i = 0;
	 while (i < data->nb_philo)
	{
		 pthread_mutex_init(&data->forks[i] , NULL);
		i++;
	
	}
	
	i = 0;
	while (i < data->nb_philo)
	{
		data->philos[i].id = i+1;
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + data->nb_philo -1) % data->nb_philo];
		
		data->philos[i].data = data;
		
		
		i++;

	}

	
	
}

int counter = 0 ;

static void routine(t_philo *philo) 
{
   pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->right_fork);
   
   printf("%d philo is eating\n",philo->id);
   sleep(1);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);

}

void	*philo_life(void *arg)
{
	t_philo	*philo;

	int i = 0;
	philo = (t_philo *) arg;
	if (philo->id % 2 == 0)
		sleep(2);
	while (i < 1)
	{
		routine(philo);
		i++;
	}
		
	return (NULL);
}


int main(int ac, char **av) 
{
  t_data data;
  int i = 0;
  parse_args(&data,ac,av);

  

 
	init_philos(&data);
  
	
	while (i < data.nb_philo)
	{
		 pthread_create(&data.philos[i].thread, NULL, philo_life, &data.philos[i]);
		i++;
	
	}
 
  i = 0;
  while (i < data.nb_philo)
	{
		 pthread_join(data.philos[i].thread, NULL);
		i++;
	}

 
  i = 0;
  while (i < data.nb_philo)
	{
		 pthread_mutex_destroy(&data.forks[i]);
		i++;
	
	}
  

  free(data.philos);
  return 0;
}