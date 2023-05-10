/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadigh <kadigh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 21:50:25 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/05/10 23:05:19 by kadigh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char *av[])
{
	t_vars	*vars;
	if (ac > 6 || ac < 5)
		error("invalid nbr of args\n");
	vars = ft_calloc(1, sizeof(vars));
	init_args(ac, av, vars);
	free(vars);
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
