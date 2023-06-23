/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadigh <kadigh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 21:50:25 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/06/23 23:19:55 by kadigh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	join_threads(t_data *data, t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < (data)->vars->nbr_of_philos)
		pthread_join((data)->philos_thread[i], NULL);
	i = -1;
	while (++i < (data)->vars->nbr_of_philos)
		pthread_mutex_destroy(&(data)->forks[i]);
	pthread_mutex_destroy(data->death_mutex);
	free(philos);
	free(data->death_mutex);
	free(data->forks);
	free(data->philos_thread);
	free(data->vars);
	free(data);
}

void	*check_death(t_philo *philo)
{
	usleep(500);
	pthread_mutex_lock(*philo->death_mutex);
	if (ft_mstime() - philo->last_meal_time >= philo->vars->time_to_die)
	{
		**philo->dead = 1;
		printf("\033[31m%llu\t%d\tdead\n",
			ft_mstime() - philo->start_time, philo->id);
		pthread_mutex_unlock(*philo->death_mutex);
		return (NULL);
	}
	pthread_mutex_unlock(*philo->death_mutex);
	return ((void *)1);
}

void	*death_monitor(t_data *data, t_philo *philos)
{
	int		i;

	i = 0;
	while (i <= philos->vars->nbr_of_philos)
	{
		// usleep(500);
		// pthread_mutex_lock(data->vars->eat_lock);
		if (i == philos->vars->nbr_of_philos)
			i = 0;
		if (philos[i].meals_count >= philos[i].vars->nbrof_meals
			&& philos[i].vars->nbrof_meals > -1)
		{
			join_threads(data, philos);
			return (NULL);
		}
		if (check_death(&philos[i]) == NULL)
			return (NULL);
		// pthread_mutex_unlock(data->vars->eat_lock);
		i++;
	}
	return (NULL);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 != 0)
		usleep(100);
	while (1)
	{
		if (philo->meals_count >= philo->vars->nbrof_meals
			&& philo->vars->nbrof_meals > -1)
			break ;
		eating(philo);
		print("\033[34m", philo, "is sleeping");
		sleeping(philo->vars->time_to_sleep);
		print("\033[0m", philo, "is thinking");
	}
	return (NULL);
}

int	main(int ac, char *av[])
{
	int			i;
	t_data		*data;
	t_philo		*philos;
	u_int64_t	time_zero;
	// protect the functions pthread_function 
	data = init_args(ac, av);
	if (!data)
		return (1);
	philos = init_philo(data);
	if (!philos)
		return (1);
	i = -1;
	time_zero = ft_mstime();
	pthread_mutex_init(data->death_mutex, NULL);
	while (++i < (data)->vars->nbr_of_philos)
		pthread_mutex_init(&(data)->forks[i], NULL);
	i = -1;
	while (++i < (data)->vars->nbr_of_philos)
	{
		philos[i].start_time = time_zero;
		philos[i].last_meal_time = ft_mstime();
		if (pthread_create(&data->philos_thread[i], NULL, routine, &philos[i]))
			return (1);
	}
	if (!death_monitor(data, philos))
		return (0);
	return (0);
}
