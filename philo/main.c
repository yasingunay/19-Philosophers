/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygunay <ygunay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:53:57 by ygunay            #+#    #+#             */
/*   Updated: 2023/02/02 14:45:20 by ygunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av) 
{
  t_data data;

  parse_args(&data,ac,av);
  init_mutexes(&data);
  init_philos(&data);
  launch_philos(&data);
  ft_free(&data);
	
  return 0;
}