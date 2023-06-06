/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 01:39:28 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/06/06 15:08:36 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo_bonus.h"

void	eat(t_philo *philo)
{
	sem_wait(philo->forks_sem);
	printf("\033[32m %llu\t%d\thas taken a fork\n",ft_gettime_inms() - philo->start_time, philo->id);
	sem_wait(philo->forks_sem);
	printf("\033[32m %llu\t%d\thas taken a fork\n",ft_gettime_inms() - philo->start_time, philo->id);
	philo->last_meal_time = ft_gettime_inms();
	printf("\033[1;33m %llu\t%d\tis eating\n",ft_gettime_inms() - philo->start_time, philo->id);
	ft_msleep(philo->vars->time_to_eat);
	sem_post(philo->forks_sem);
	sem_post(philo->forks_sem);
}

void	*routine(t_philo *philo)
{
	// sem_t *forks_sem = (sem_t *)arg;
	int i = 0;

	while (i< 4)
	{
		eat(philo);
		printf("\033[34m %llu\t%d\tis sleeping\n",ft_gettime_inms() - philo->start_time,philo->id);
		ft_msleep(philo->vars->time_to_eat);
		// think()
		i++;
	}
	return NULL;
}

int main(int ac, char **av)
{
	int 				i;
	int					pid;
	t_vars				*vars;
	t_data				*data;
	t_philo				*philos;
	sem_t				*forks_sem;
	unsigned int		forks_pair;

	vars = ft_calloc(1, sizeof(t_vars));
	if (ac > 6 || ac < 5)
	{
		// error
		return (0);
	}
	init_args(ac, av, vars);
	philos = ft_calloc(vars->nbr_of_philos, sizeof(t_philo));
	forks_pair = (vars->nbr_of_philos / 2) + 1;
	forks_sem = sem_open("/forks", O_CREAT | O_RDWR, 0700, forks_pair);
	i = -1;
	while (++i < vars->nbr_of_philos)
	{
		philos[i].id = i;
		philos[i].meals_count = 0;
		philos[i].start_time = ft_gettime_inms();
		philos[i].last_meal_time = ft_gettime_inms();
		philos[i].vars = vars;
		philos[i].forks_sem = forks_sem;
	}
	i = -1;
	while (++i < vars->nbr_of_philos)
	{
		pid = fork();
		if (pid == -1)
			printf("error\n");
		else if (pid == 0)
		{
			routine(&philos[i]);
			exit(0);
		}
	}
	while (wait(NULL) != -1)
		;
	sem_close(forks_sem);
	sem_unlink("/forks");
}