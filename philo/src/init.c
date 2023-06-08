/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:46:30 by kadigh            #+#    #+#             */
/*   Updated: 2023/06/08 11:28:08 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	init_vars_struct(t_data **data, int ac, char **av)
{
	(*data)->vars = ft_calloc(1, sizeof(t_vars));
	(*data)->vars->nbr_of_philos = ft_atoi(av[1]);
	(*data)->vars->time_to_die = ft_atoi(av[2]);
	(*data)->vars->time_to_eat = ft_atoi(av[3]);
	(*data)->vars->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		(*data)->vars->nbrof_meals = ft_atoi(av[5]);
	else
		(*data)->vars->nbrof_meals = -1;
}

t_philo	*init_philo(t_data *data)
{
	int		i;
	t_philo	*philos;

	i = -1;
	philos = ft_calloc((data)->vars->nbr_of_philos, sizeof(t_philo));
	while (++i < (data)->vars->nbr_of_philos)
	{
		philos[i].right_fork = &(data)->forks[i];
		philos[i].left_fork = &(data)->forks[(i + 1)
			% data->vars->nbr_of_philos];
		philos[i].dead = &(data)->dead;
		philos[i].start_time = ft_mstime();
		philos[i].last_meal_time = ft_mstime();
		philos[i].meals_count = 0;
		philos[i].id = i;
		philos[i].death_mutex = (data)->death_mutex;
		philos[i].vars = (data)->vars;
	}
	return (philos);
}

t_data	*init_args(int ac, char **av)
{
	t_data	*data;

	if (ac > 6 || ac < 5)
		error("invalid nbr of args\n");
	data = ft_calloc(1, sizeof(t_data));
	init_vars_struct(&data, ac, av);
	data->dead = 0;
	data->death_mutex = ft_calloc(1, sizeof(pthread_mutex_t));
	data->philos_thread = ft_calloc((data)->vars->nbr_of_philos,
			sizeof(pthread_t));
	(data)->forks = ft_calloc((data)->vars->nbr_of_philos,
			sizeof(pthread_mutex_t));
	return (data);
}
