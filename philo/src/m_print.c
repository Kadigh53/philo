/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 23:24:27 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/06/21 18:06:15 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print(char *color, t_philo *philo, char *str)
{
	pthread_mutex_lock(philo->vars->print_lock);
	if (*philo->vars->dead == 1)
	{
		pthread_mutex_unlock(philo->vars->print_lock);
		return ;
	}
	printf("%s%llu\t%d\t%s\n", color,
		ft_mstime() - philo->start_time, philo->id, str);
	pthread_mutex_unlock(philo->vars->print_lock);
}
