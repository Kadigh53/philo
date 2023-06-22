/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 23:17:35 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/06/22 16:51:21 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

u_int64_t	ft_gettime_inms(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		error("gettimeofday failed\n");
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_msleep(unsigned int time)
{
	u_int64_t	start;

	start = ft_gettime_inms();
	while (ft_gettime_inms() - start < time)
		usleep(100);
}
