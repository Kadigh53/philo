/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 23:15:45 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/06/20 23:36:27 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	print(char *color, t_philo *philo, char *str)
{
	sem_wait(philo->vars->print_lock);
	printf("%s%llu\t%d\t%s\n",color,
		ft_gettime_inms() - philo->start_time, philo->id, str);
	sem_post(philo->vars->print_lock);
}
