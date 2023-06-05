/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 21:50:25 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/06/05 04:00:51 by aaoutem-         ###   ########.fr       */
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
		printf("\033[31m %llu\t%d\tdead  %llu\n",ft_mstime() - philo->start_time,philo->id,ft_mstime() - philo->last_meal_time);
		pthread_mutex_unlock(philo->death_mutex);
		return NULL;
	}
	pthread_mutex_unlock(philo->death_mutex);
	return ((void *)1);
}

void	pick_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	printf("\033[32m %llu\t%d\thas taken a fork\n",ft_mstime() - philo->start_time, philo->id);
	pthread_mutex_lock(philo->left_fork);
	printf("\033[32m %llu\t%d\thas taken a fork\n",ft_mstime() - philo->start_time, philo->id);
	// philo->last_meal_time = ft_mstime();
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	eating(t_philo *philo)
{
	pick_forks(philo);
	philo->last_meal_time = ft_mstime();
	printf("\033[1;33m %llu\t%d\tis eating\n",ft_mstime() - philo->start_time, philo->id);
	ft_msleep(philo->vars->time_to_eat);
	drop_forks(philo);
	philo->meals_count++;
}

void	sleeping(u_int64_t sleep_time)
{
	u_int64_t	start;

	start = ft_mstime();
	while (ft_mstime() - start < sleep_time)
		ft_msleep(1);
}

void	*routine(void *arg)
{
	t_philo	*philo = (t_philo *)arg;

	if (philo->id % 2 == 0)
		usleep(100);
	while (1)
	{
		if (philo->meals_count >= philo->vars->nbrof_meals && philo->vars->nbrof_meals > -1)
			break;
		eating(philo);
		printf("\033[34m %llu\t%d\tis sleeping\n",ft_mstime() - philo->start_time,philo->id);
		sleeping(philo->vars->time_to_sleep);
		if (philo->last_meal_time + philo->vars->time_to_die > ft_mstime() - philo->start_time)
		{
			printf("\033[0m %llu\t%d\tis thinking\n",ft_mstime() - philo->start_time,philo->id);
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
	while(1)
	{
		i = 0;
		if (philos[i].meals_count >= philos[i].vars->nbrof_meals && philos[i].vars->nbrof_meals > -1)
			break;
		while (i < philos->vars->nbr_of_philos)
		{
			if (philos[i].meals_count >= philos[i].vars->nbrof_meals && philos[i].vars->nbrof_meals > -1)
				break;
			if (check_death(&philos[i]) == NULL)
				return NULL;
			i++;
		}
	}
	return NULL;
}

int	main(int ac, char *av[])
{
	t_data		*data;
	t_philo		*philos;
	void		*death_monitor_return;
	pthread_t	monitor;

	int i = 0;
	death_monitor_return = (void *)1;
	if (ac > 6 || ac < 5)
		error("invalid nbr of args\n");
	data = ft_calloc(1, sizeof(t_data));
	data->vars = ft_calloc(1,sizeof(t_vars));
	data->death_mutex = ft_calloc(1, sizeof(pthread_mutex_t));
	data->dead = 0;
	init_args(ac, av, &data);
	philos = ft_calloc((data)->vars->nbr_of_philos , sizeof(t_philo));
	data->philos_thread = ft_calloc((data)->vars->nbr_of_philos, sizeof(pthread_t));
	(data)->forks = ft_calloc((data)->vars->nbr_of_philos, sizeof(pthread_mutex_t));
	i = -1;
	pthread_mutex_init(data->death_mutex, NULL);
	while (++i < (data)->vars->nbr_of_philos)
		pthread_mutex_init(&(data)->forks[i], NULL);
	i = -1;
	while (++i < (data)->vars->nbr_of_philos)
	{
		if (i  == (data)->vars->nbr_of_philos - 1)
		{
			philos[i].right_fork = &(data)->forks[i];
			philos[i].left_fork = &(data)->forks[0];
		}
		else
		{
			philos[i].right_fork = &(data)->forks[i];
			philos[i].left_fork = &(data)->forks[i + 1];
		}
		philos[i].dead = &(data)->dead;
		philos[i].start_time = ft_mstime();
		philos[i].last_meal_time = ft_mstime();
		philos[i].meals_count = 0;
		philos[i].id = i;
		philos[i].death_mutex = (data)->death_mutex;
		philos[i].vars = (data)->vars;
	}
	i = -1;
	pthread_create(&monitor,NULL,death_monitor,philos);
	while (++i < (data)->vars->nbr_of_philos)
		pthread_create(&(data)->philos_thread[i], NULL, routine, &philos[i]);
	i = -1;
	pthread_join(monitor, &death_monitor_return);
	if (death_monitor_return == NULL)
		return 0;
	while (++i < (data)->vars->nbr_of_philos)
		pthread_join((data)->philos_thread[i], NULL);
	i = -1;
	while (++i < (data)->vars->nbr_of_philos)
		pthread_mutex_destroy(&(data)->forks[i]);
	pthread_mutex_destroy(data->death_mutex);		
	return  (0);
}
