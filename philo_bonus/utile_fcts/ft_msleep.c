/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:31:01 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/06/07 16:38:08 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	ft_msleep(u_int64_t time)
{	
	u_int64_t	start;

	start = ft_gettime_inms();
	while (ft_gettime_inms() - start < time)
		usleep(100);
}
