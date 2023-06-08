/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 11:06:21 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/06/08 11:06:44 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleeping(u_int64_t sleep_time)
{
	u_int64_t	start;

	start = ft_mstime();
	while (ft_mstime() - start < sleep_time)
		ft_msleep(1);
}
