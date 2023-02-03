/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasingunay <yasingunay@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:53:57 by ygunay            #+#    #+#             */
/*   Updated: 2023/02/03 10:03:36 by yasingunay       ###   ########.fr       */
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