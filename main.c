/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 21:50:25 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/05/17 15:56:27 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pick_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	printf("\033[32m %llu\t%d\thas taken a fork\n",ft_mstime() - philo->start_time, philo->id);
	pthread_mutex_lock(philo->left_fork);
	printf("\033[32m %llu\t%d\thas taken a fork\n",ft_mstime() - philo->start_time, philo->id);
	printf("\033[1;33m %llu\t%d\tis eating\n",ft_mstime() - philo->start_time, philo->id);
	philo->meals_count++;
	philo->last_meal_time = ft_mstime();
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	eating(t_philo	*philo)
{
	pick_forks(philo);
	usleep(philo->vars->time_to_eat * 1000);
	drop_forks(philo);
}

void	check_death(t_philo *philo)
{
	pthread_mutex_lock(philo->death_mutex);
	if (ft_mstime() - philo->last_meal_time >= philo->vars->time_to_die && *philo->dead != 1)
	{
		*philo->dead = 1;
		usleep(2000);
		printf("\033[31m %llu\t%d\tdead\n",ft_mstime() - philo->start_time,philo->id);
		exit(0);
	}
	pthread_mutex_unlock(philo->death_mutex);
}

void	*routine(void *arg)
{
	t_philo	*philo = (t_philo *)arg;

	if (philo->id % 2 != 0)
		usleep(500);
	while (1)
	{
		if (philo->meals_count >= philo->vars->nbrof_meals && philo->vars->nbrof_meals != -1)
			break;
		check_death(philo);
		eating(philo);
		printf("\033[34m %llu\t%d\tis sleeping\n",ft_mstime() - philo->start_time,philo->id);
		usleep(philo->vars->time_to_sleep * 1000);
		check_death(philo);
		if (philo->last_meal_time + philo->vars->time_to_die > ft_mstime() - philo->start_time)
		{
			printf("\033[0m %llu\t%d\tis thinking\n",ft_mstime() - philo->start_time,philo->id);
		}
	}
	return (NULL);
}

// void	create_philos(t_data **data, t_philo **philos)
// {
// 	int i;

// }

int	main(int ac, char *av[])
{
	t_data	*data;
	t_philo	*philos;

	int i = 0;
	if (ac > 6 || ac < 5)
		error("invalid nbr of args\n");
	data = ft_calloc(1, sizeof(t_data));
	data->vars = malloc(sizeof(t_vars));
	data->death_mutex = calloc(1, sizeof(pthread_mutex_t));
	data->dead = 0;
	init_args(ac, av, &data);
	philos = calloc((data)->vars->nbr_of_philos , sizeof(t_philo));
	data->philos_thread = malloc((data)->vars->nbr_of_philos * sizeof(pthread_t));
	(data)->forks = malloc((data)->vars->nbr_of_philos * sizeof(pthread_mutex_t));
	// while (i < (data)->vars->nbr_of_philos)
	// 	philos[i++] = (t_philo *)calloc(1,sizeof(t_philo));
	i= -1;
	pthread_mutex_init(data->death_mutex, NULL);
	while (++i < (data)->vars->nbr_of_philos)
		pthread_mutex_init(&(data)->forks[i], NULL);
	i= -1;
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
		// printf("%d\t%p\n",i,philos[i].dead);
	}
	// printf("%d\t%p \n\n",data->dead,&data->dead);
	i = -1;
	while (++i < (data)->vars->nbr_of_philos)
	{
		pthread_create(&(data)->philos_thread[i], NULL, routine, &philos[i]);
	}
	i = -1;
	while (++i < (data)->vars->nbr_of_philos)
		pthread_join((data)->philos_thread[i], NULL);
	i = -1;
	while (++i < (data)->vars->nbr_of_philos)
		pthread_mutex_destroy(&(data)->forks[i]);
	pthread_mutex_destroy(data->death_mutex);
	return  (0);
}
