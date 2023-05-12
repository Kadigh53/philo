/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 21:50:25 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/05/12 01:39:08 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_data	*data =  (t_data *)arg;
	printf("%d hello\n", data->nbr_of_philos);
	return (NULL);
}

void	create_philos(t_data **data)
{
	int i;

	i = -1;
	while (++i < (*data)->nbr_of_philos)
	{
		pthread_mutex_init(((*data)->forks + i)->forks, NULL);
		((*data)->philos + 1)->id = i;
		((*data)->forks + i)->id = i;
	}
	while (++i < (*data)->nbr_of_philos)
	{
		pthread_create((*data)->philos_thread + i, NULL, routine, *data);
	}
	i = -1;
	while (++i < (*data)->nbr_of_philos)
		pthread_join((*data)->philos_thread[i], NULL);
	i = -1;
	while (++i < (*data)->nbr_of_philos)
		pthread_mutex_destroy(((*data)->forks + i)->forks);
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
