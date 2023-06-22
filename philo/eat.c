/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 11:02:42 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/06/21 15:13:55 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pick_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	print("\033[32m", philo, "has taken a fork");
	pthread_mutex_lock(philo->left_fork);
	print("\033[32m", philo, "has taken a fork");
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
	print("\033[1;33m", philo, "is eating");
	ft_msleep(philo->vars->time_to_eat);
	drop_forks(philo);
	philo->meals_count = philo->meals_count + 1;
}
