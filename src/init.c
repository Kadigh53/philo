/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadigh <kadigh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:46:30 by kadigh            #+#    #+#             */
/*   Updated: 2023/05/09 14:50:29 by kadigh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	init_args(int ac, char **av, t_vars *vars)
{
	vars->nbr_of_philos = ft_atoi(av[1]);
	vars->time_to_die = ft_atoi(av[2]);
	vars->time_to_eat = ft_atoi(av[3]);
	vars->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		vars->nbr_of_times_each_philo_must_eat = ft_atoi(av[5]);
	else
		vars->nbr_of_times_each_philo_must_eat = -1;
}

	// printf("nb%d\ndie%d\neat%d\nslp%d\nlas %d ",vars->nbr_of_philos ,vars->time_to_die ,vars->time_to_eat ,vars->time_to_sleep,vars->nbr_of_times_each_philo_must_eat);