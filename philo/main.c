/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasingunay <yasingunay@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:53:57 by ygunay            #+#    #+#             */
/*   Updated: 2023/02/10 09:49:53 by yasingunay       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av) 
{
  t_data data;

  if (ac < 5 || ac > 6)
	return(ft_error("Argument number is not correct"));
  if(parse_args(&data,ac,av) == -1)
	return(ft_error("At least one argumet is invalid"));
  if(init_and_launch(&data) == -1)
	return(ft_error("Memory allocation failed"));
	system("leaks philo");
  return 0;
}