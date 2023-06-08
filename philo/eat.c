/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 11:02:42 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/06/08 11:09:33 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pick_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	printf("\033[32m %llu\t%d\thas taken a fork\n",
		ft_mstime() - philo->start_time, philo->id);
	pthread_mutex_lock(philo->left_fork);
	printf("\033[32m %llu\t%d\thas taken a fork\n",
		ft_mstime() - philo->start_time, philo->id);
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
	printf("\033[1;33m %llu\t%d\tis eating\n",
		ft_mstime() - philo->start_time, philo->id);
	ft_msleep(philo->vars->time_to_eat);
	drop_forks(philo);
	philo->meals_count++;
}
