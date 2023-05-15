/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 21:50:25 by aaoutem-          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/05/15 03:56:19 by aaoutem-         ###   ########.fr       */
=======
/*   Updated: 2023/05/15 03:26:06 by aaoutem-         ###   ########.fr       */
>>>>>>> 3c8b842e50451754597ffb549f1b81175ccb5b50
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
	// usleep(philo->vars->time_to_eat * 1000);
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
<<<<<<< HEAD
		usleep(1000);
=======
		usleep(3000);
>>>>>>> 3c8b842e50451754597ffb549f1b81175ccb5b50
		printf("\033[31m %llu\t%d\tdead\n",ft_mstime() - philo->start_time,philo->id);
		exit(0);
	}
	pthread_mutex_unlock(philo->death_mutex);
}

void	*routine(void *arg)
{
	t_philo	*philo = (t_philo *)arg;

	if (philo->id % 2 != 0)
<<<<<<< HEAD
		usleep(500);
=======
		usleep(1000);
>>>>>>> 3c8b842e50451754597ffb549f1b81175ccb5b50
	while (1)
	{
		if (philo->meals_count >= philo->vars->nbrof_meals && philo->vars->nbrof_meals != -1)
			break;
		check_death(philo);
		eating(philo);
		printf("\033[34m %llu\t%d\tis sleeping\n",ft_mstime() - philo->start_time,philo->id);
		usleep(philo->vars->time_to_sleep * 1000);
		if (philo->last_meal_time + philo->vars->time_to_die > ft_mstime() - philo->start_time)
		{
			printf("\033[0m %llu\t%d\tis thinking\n",ft_mstime() - philo->start_time,philo->id);
		}
	}
	return (NULL);
}

void	create_philos(t_data **data)
{
	int i;

	i = -1;
	(*data)->dead = 0;
	pthread_mutex_init(&(*data)->death_mutex, NULL);
	while (++i < (*data)->vars.nbr_of_philos)
	{
		pthread_mutex_init((*data)->forks + i, NULL);
		(*data)->philos[i].thread_id = &(*data)->philos_thread[i];
		if (i  == (*data)->vars.nbr_of_philos - 1)
		{
			(*data)->philos[i].right_fork = &(*data)->forks[i];
			(*data)->philos[i].left_fork = &(*data)->forks[0];
		}
		else
		{
			(*data)->philos[i].right_fork = &(*data)->forks[i];
			(*data)->philos[i].left_fork = &(*data)->forks[i + 1];
		}
		((*data)->philos + i)->start_time = ft_mstime();
		((*data)->philos + i)->last_meal_time = ft_mstime();
		((*data)->philos + i)->meals_count = 0;
		((*data)->philos + i)->id = i + 1;
		((*data)->philos + i)->dead = &(*data)->dead;
		((*data)->philos + i)->death_mutex = &(*data)->death_mutex;
		((*data)->philos + i)->vars = &(*data)->vars;
	}
	i = -1;
	while (++i < (*data)->vars.nbr_of_philos)
	{
		pthread_create((*data)->philos_thread + i, NULL, routine, &(*data)->philos[i]);
	}
	i = -1;
	while (++i < (*data)->vars.nbr_of_philos)
		pthread_join((*data)->philos_thread[i], NULL);
	i = -1;
	while (++i < (*data)->vars.nbr_of_philos)
		pthread_mutex_destroy((*data)->forks + i);
	pthread_mutex_destroy(&(*data)->death_mutex);
}

void check_leaks() {
    pid_t pid = getpid();
    char cmd[256];
	sprintf(cmd, "leaks %d", pid);
    system(cmd);
}

int	main(int ac, char *av[])
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (ac > 6 || ac < 5)
		error("invalid nbr of args\n");
	init_args(ac, av, &data);
	create_philos(&data);
<<<<<<< HEAD
=======
	// atexit(check_leaks);
>>>>>>> 3c8b842e50451754597ffb549f1b81175ccb5b50
	while(1);
}
