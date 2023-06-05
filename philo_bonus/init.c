/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 09:11:51 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/06/05 09:16:33 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo_bonus.h"

void	init_args(int ac, char **av, t_vars *vars)
{
	vars->nbr_of_philos = ft_atoi(av[1]);
	vars->time_to_die = ft_atoi(av[2]);
	vars->time_to_eat = ft_atoi(av[3]);
	vars->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		vars->nbrof_meals = ft_atoi(av[5]);
	else
		vars->nbrof_meals = -1;
}