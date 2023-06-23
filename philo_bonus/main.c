/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 01:39:28 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/06/23 12:56:54 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	eat(t_philo *philo)
{
	sem_wait(philo->vars->forks_sem);
	print("\033[32m ", philo, "has taken a fork");
	sem_wait(philo->vars->forks_sem);
	print("\033[32m ", philo, "has taken a fork");
	philo->last_meal_time = ft_gettime_inms();
	philo->meals_count++;
	print("\033[1;33m ", philo, "is eating");
	if (philo->vars->nbr_of_meals > 0
		&& philo->meals_count >= philo->vars->nbr_of_meals)
	{
		sem_post(philo->vars->forks_sem);
		sem_post(philo->vars->forks_sem);
		exit(0);
	}
	ft_msleep(philo->vars->time_to_eat);
	sem_post(philo->vars->forks_sem);
	sem_post(philo->vars->forks_sem);
}

void	*check_death(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		sem_wait(philo->vars->kill_lock);
		if (ft_gettime_inms() - philo->last_meal_time
			> philo->vars->time_to_die)
		{
			philo->death_switch = 1;
			print("\033[31m ", philo, "dead");
			kill(0, SIGINT);
		}
		sem_post(philo->vars->kill_lock);
	}
	return (NULL);
}

void	*routine(t_philo *philo)
{
	philo->last_meal_time = ft_gettime_inms();
	if (pthread_create(&philo->philo_thread, NULL, &check_death, philo))
	{
		printf("error\n");
		exit(1);
	}
	while (1)
	{
		// if (philo->vars->nbr_of_meals > 0
		// 	&& philo->meals_count >= philo->vars->nbr_of_meals)
		// 	exit(0);
		eat(philo);
		print("\033[34m ", philo, "is sleeping");
		ft_msleep(philo->vars->time_to_sleep);
		print("\033[0m ", philo, "is thinking");
	}
	pthread_detach(philo->philo_thread);
	return ((void *)1);
}


int	main(int ac, char **av)
{
	int					i;
	int					pid;
	t_philo				*philo;
	u_int64_t		start_timee;

	start_timee = ft_gettime_inms();
	philo = init_philo(ac, av);
	i = -1;
	while (++i < philo->vars->nbr_of_philos)
	{
		pid = ft_fork();
		if (pid == 0)
		{
			if (philo[i].id % 2 != 0)
				usleep(500);
			philo[i].start_time = start_timee;
			routine(&philo[i]);
			exit(0);
		}
	}
	while (wait(NULL) != -1)
		;
	sem_close(philo->vars->forks_sem);
	sem_unlink("/forks");
	free(philo->vars);
	free(philo);
	return (0);
}
