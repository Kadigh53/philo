/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:46:30 by kadigh            #+#    #+#             */
/*   Updated: 2023/05/11 20:49:19 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	init_args(int ac, char **av, t_data	**data)
{
	(*data)->nbr_of_philos = ft_atoi(av[1]);
	(*data)->time_to_die = ft_atoi(av[2]);
	(*data)->time_to_eat = ft_atoi(av[3]);
	(*data)->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		(*data)->nbr_of_times_each_philo_must_eat = ft_atoi(av[5]);
	else
		(*data)->nbr_of_times_each_philo_must_eat = -1;
	(*data)->philos = (t_philo *)ft_calloc((*data)->nbr_of_philos, sizeof(t_philo) );
	(*data)->forks = (t_forks *)ft_calloc((*data)->nbr_of_philos, sizeof(t_forks));
	(*data)->philos_thread = (pthread_t *)ft_calloc((*data)->nbr_of_philos, sizeof(pthread_t));
}
	// printf("nb\t%d\ndie\t%d\neat\t%d\nslp\t%d\nlas \t%d ",(*data)->nbr_of_philos ,(*data)->time_to_die ,(*data)->time_to_eat ,(*data)->time_to_sleep,(*data)->nbr_of_times_each_philo_must_eat);



	// (*data)->philos = (t_philo *)ft_calloc(1, sizeof(t_philo) * (*data)->nbr_of_philos);
	// (*data)->forks = (pthread_mutex_t *)ft_calloc(1, sizeof(pthread_mutex_t) * (*data)->nbr_of_philos);