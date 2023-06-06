/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:46:30 by kadigh            #+#    #+#             */
/*   Updated: 2023/06/05 09:01:34 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	init_vars_struct(t_data **data,int ac, char ** av)
{
	(*data)->vars->nbr_of_philos = ft_atoi(av[1]);
	(*data)->vars->time_to_die = ft_atoi(av[2]);
	(*data)->vars->time_to_eat = ft_atoi(av[3]);
	(*data)->vars->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		(*data)->vars->nbrof_meals = ft_atoi(av[5]);
	else
		(*data)->vars->nbrof_meals = -1;
}

void	init_args(int ac, char **av, t_data	**data)
{

	init_vars_struct(data, ac, av);
}
