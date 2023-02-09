/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:53:57 by ygunay            #+#    #+#             */
/*   Updated: 2023/02/09 14:12:16 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av) 
{
  t_data data;

int i ;

  if (ac < 5 || ac > 6)
	return(ft_error("Argument number is not correct"));
  if(parse_args(&data,ac,av) == -1)
	return(ft_error("At least one argumet is invalid"));
  if(init_and_launch(&data) == -1)
	return(ft_error("Memory allocation failed"));

	pthread_join(data.th_monitor, NULL);
 i = 0;
  while (i < data.nb_philo && data.died_philo == 0)
	{
		 pthread_join(data.philos[i].thread, NULL);
		i++;
	}

	ft_free(&data);

  return 0;
}