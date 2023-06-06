/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 23:17:35 by kadigh            #+#    #+#             */
/*   Updated: 2023/06/03 08:26:37 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"
// #include "time.h"

u_int64_t   ft_gettime_inms()
{
    struct timeval tv;
    
    if (gettimeofday(&tv, NULL) == -1)
        exit(1);
    return((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void    ft_msleep(unsigned int time)
{
	u_int64_t	start;

	start = ft_gettime_inms();
	while (ft_gettime_inms() - start < time )
		usleep(100);
}

// int main(){
// 	printf("befer\n");
// 	ft_msleep(2000);
// 	printf("tozomt\n");
// 	usleep(2000000);
// 	printf("yazn\n");
// }