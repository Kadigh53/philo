/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:33:35 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/06/07 16:37:51 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

u_int64_t	ft_gettime_inms(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
	{
		printf("Error : gettimeofday failed\n");
		exit (1);
	}
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
