/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 01:39:28 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/06/08 12:24:56 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	eat(t_philo *philo)
{
	sem_wait(philo->vars->forks_sem);
	sem_wait(philo->vars->print_lock);
	printf("\033[32m %llu\t%d\thas taken a fork\n",
		ft_gettime_inms() - philo->start_time, philo->id);
	sem_post(philo->vars->print_lock);
	sem_wait(philo->vars->forks_sem);
	sem_wait(philo->vars->print_lock);
	printf("\033[32m %llu\t%d\thas taken a fork\n",
		ft_gettime_inms() - philo->start_time, philo->id);
	sem_post(philo->vars->print_lock);
	philo->last_meal_time = ft_gettime_inms();
	philo->meals_count++;
	if (philo->vars->nbrof_meals > 0
		&& philo->meals_count >= philo->vars->nbrof_meals)
		exit(0);
	sem_wait(philo->vars->print_lock);
	printf("\033[1;33m %llu\t%d\tis eating\n",
		ft_gettime_inms() - philo->start_time, philo->id);
	sem_post(philo->vars->print_lock);
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
			sem_wait(philo->vars->print_lock);
			printf("\033[31m %llu\t%d\tdead\n",
				ft_gettime_inms() - philo->start_time, philo->id);
			sem_post(philo->vars->print_lock);
			kill(0, SIGINT);
		}
		sem_post(philo->vars->kill_lock);
	}
	return (NULL);
}

void	*routine(t_philo *philo)
{
	if (pthread_create(&philo->philo_thread, NULL, &check_death, philo))
	{
		printf("error\n");
		exit(1);
	}
	if (philo->id % 2 == 0)
		usleep(100);
	while (philo->death_switch != 1)
	{
		eat(philo);
		sem_wait(philo->vars->print_lock);
		printf("\033[34m %llu\t%d\tis sleeping\n",
			ft_gettime_inms() - philo->start_time, philo->id);
		sem_post(philo->vars->print_lock);
		ft_msleep(philo->vars->time_to_sleep);
	}
	pthread_detach(philo->philo_thread);
	return ((void *)1);
}

int	main(int ac, char **av)
{
	int					i;
	int					pid;
	t_philo				*philo;

	philo = init_philo(ac, av);
	i = -1;
	while (++i < philo->vars->nbr_of_philos)
	{
		pid = fork();
		if (pid == -1)
			printf("error\n");
		else if (pid == 0)
		{
			philo[i].start_time = ft_gettime_inms();
			philo[i].last_meal_time = ft_gettime_inms();
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
