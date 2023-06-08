/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 21:50:25 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/06/08 11:09:26 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*check_death(t_philo *philo)
{
	pthread_mutex_lock(philo->death_mutex);
	if (ft_mstime() - philo->last_meal_time >= philo->vars->time_to_die)
	{
		*philo->dead = 1;
		ft_msleep(2);
		printf("\033[31m %llu\t%d\tdead\n",
			ft_mstime() - philo->start_time, philo->id);
		pthread_mutex_unlock(philo->death_mutex);
		return (NULL);
	}
	pthread_mutex_unlock(philo->death_mutex);
	return ((void *)1);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(100);
	while (1)
	{
		if (philo->meals_count >= philo->vars->nbrof_meals
			&& philo->vars->nbrof_meals > -1)
			break ;
		eating(philo);
		printf("\033[34m %llu\t%d\tis sleeping\n",
			ft_mstime() - philo->start_time, philo->id);
		sleeping(philo->vars->time_to_sleep);
		if (philo->last_meal_time + philo->vars->time_to_die
			> ft_mstime() - philo->start_time)
		{
			printf("\033[0m %llu\t%d\tis thinking\n",
				ft_mstime() - philo->start_time, philo->id);
		}
	}
	return (NULL);
}

void	*death_monitor(void *arg)
{
	t_philo	*philos;
	int		i;

	philos = (t_philo *)arg;
	i = 0;
	while (1)
	{
		i = 0;
		if (philos[i].meals_count >= philos[i].vars->nbrof_meals
			&& philos[i].vars->nbrof_meals > -1)
			break ;
		while (i < philos->vars->nbr_of_philos)
		{
			if (philos[i].meals_count >= philos[i].vars->nbrof_meals
				&& philos[i].vars->nbrof_meals > -1)
				break ;
			if (check_death(&philos[i]) == NULL)
				return (NULL);
			i++;
		}
	}
	return (NULL);
}

void	threads_join(t_data *data)
{
	int	i;

	i = -1;
	while (++i < (data)->vars->nbr_of_philos)
		pthread_join((data)->philos_thread[i], NULL);
	i = -1;
	while (++i < (data)->vars->nbr_of_philos)
		pthread_mutex_destroy(&(data)->forks[i]);
	pthread_mutex_destroy(data->death_mutex);
}

int	main(int ac, char *av[])
{
	int			i;
	void		*death_monitor_return;
	t_data		*data;
	t_philo		*philos;
	pthread_t	monitor;

	death_monitor_return = (void *)1;
	data = init_args(ac, av);
	philos = init_philo(data);
	i = -1;
	pthread_mutex_init(data->death_mutex, NULL);
	while (++i < (data)->vars->nbr_of_philos)
		pthread_mutex_init(&(data)->forks[i], NULL);
	pthread_create(&monitor, NULL, death_monitor, philos);
	i = -1;
	while (++i < (data)->vars->nbr_of_philos)
		pthread_create(&(data)->philos_thread[i], NULL, routine, &philos[i]);
	pthread_join(monitor, &death_monitor_return);
	if (death_monitor_return == NULL)
		return (0);
	threads_join(data);
	return (0);
}
