/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 21:50:25 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/05/13 01:35:16 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	pick_forks(t_philo *philo)
// {
// 	philo->right_fork = philo->id;
// 	pthread_mutex_lock(philo->right_fork);
// 	print_status(philo, "has taken a fork");
// 	pthread_mutex_lock(philo->left_fork);
// 	print_status(philo, "has taken a fork");
// 	print_status(philo, "is eating");
// 	philo->last_meal = get_time();
// }
# define time_x 1
void	pick_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	printf("%llu\t%d\thas taken a fork\n",ft_mstime() - philo->start_time, philo->id);
	pthread_mutex_lock(philo->left_fork);
	printf("%llu\t%d\thas taken a fork\n",ft_mstime() - philo->start_time, philo->id);
	printf("%llu\t%d\tis eating\n",ft_mstime() - philo->start_time, philo->id);
	usleep(philo->vars.time_to_eat * 1000);
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	printf("%llu\t%d\tis sleeping\n",ft_mstime() - philo->start_time,philo->id);
	usleep(philo->vars.time_to_sleep * 1000);
}

void	eating(t_philo	*philo)
{
	pick_forks(philo);
	usleep(philo->vars.time_to_eat * 1000);
	drop_forks(philo);
}
void	*routine(void *arg)
{
	t_philo	*philo = (t_philo *)arg;
	int i = 0;
	if (philo->id % 2 != 0)
		usleep(5000);
	while (i++ <4)//philo->dead == 0 && philo->meals_count < philo->vars.nbrof_meals)
	{
		printf("hello from thead %d\n", philo->id);
		eating(philo);
	}
	return (NULL);
}

void	create_philos(t_data **data)
{
	int i;

	i = -1;
	while (++i < (*data)->vars.nbr_of_philos)
	{
		pthread_mutex_init((*data)->forks + i, NULL);
		// (*data)->philos[i].thread_id = &(*data)->philos_thread[i];
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
		((*data)->philos + i)->id = i;
		((*data)->philos + i)->dead = 0;
		// ((*data)->forks + i)->id = i;
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
}

int	main(int ac, char *av[])
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (ac > 6 || ac < 5)
		error("invalid nbr of args\n");
	init_args(ac, av, &data);
	create_philos(&data);
}

// creat a two threaded program that executs two routine functions and the first thread waits he other using the join function 

// int i=0;
// pthread_mutex_t mutex;

// void	*test(void *t)
// {
// 	int k =0;
// 	pthread_mutex_lock(&mutex);
// 	while (k < 100000000){
// 		// pthread_mutex_lock(&mutex);
// 		i++;
// 		k++;
// 		// pthread_mutex_unlock(&mutex);
// 	}
// 	pthread_mutex_unlock(&mutex);
// }

// int	main(int ac, char **av)
// {
	// pthread_t	t1;
// 	pthread_t	t2;
// 	pthread_mutex_init(&mutex, NULL);

// 	pthread_create(&t1,NULL,test,NULL);
// 	pthread_create(&t2,NULL,test,NULL);
	
// 	pthread_join(t1,NULL);
// 	pthread_join(t2,NULL);
	
// 	printf("%d\n",i);
	
// 	pthread_mutex_destroy(&mutex);
// 	return (0);
// }
