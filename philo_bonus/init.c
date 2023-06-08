/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 09:11:51 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/06/08 12:30:13 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_vars	*init_args(int ac, char **av, t_vars *vars)
{
	vars = ft_calloc(1, sizeof(t_vars));
	vars->nbr_of_philos = ft_atoi(av[1]);
	vars->time_to_die = ft_atoi(av[2]);
	vars->time_to_eat = ft_atoi(av[3]);
	vars->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		vars->nbrof_meals = ft_atoi(av[5]);
	else
		vars->nbrof_meals = -1;
	sem_unlink("/forks");
	vars->forks_sem = sem_open("/forks", O_CREAT, 0600, vars->nbr_of_philos);
	sem_unlink("/kill_lock");
	vars->kill_lock = sem_open("/kill_lock", O_CREAT, 0600, 1);
	sem_unlink("/print_lock");
	vars->print_lock = sem_open("/print_lock", O_CREAT, 0600, 1);
	if (vars->forks_sem == SEM_FAILED || vars->kill_lock == SEM_FAILED
		|| vars->print_lock == SEM_FAILED)
	{
		printf("error\n");
		exit (0);
	}
	return (vars);
}

t_philo	*init_philo(int ac, char **av)
{
	t_philo	*philo;
	t_vars	*vars;
	int		i;

	if (ac > 6 || ac < 5)
	{
		printf("Error:invalide number of arguments\n");
		exit (0);
	}
	vars = NULL;
	vars = init_args(ac, av, vars);
	philo = ft_calloc(vars->nbr_of_philos, sizeof(t_philo));
	i = 0;
	while (i < vars->nbr_of_philos)
	{
		philo[i].id = i;
		philo[i].meals_count = 0;
		philo[i].death_switch = 0;
		// philo[i].last_meal_time = ft_gettime_inms();
		philo[i].vars = vars;
		i++;
	}
	return (philo);
}
