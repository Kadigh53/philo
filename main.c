/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 21:50:25 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/04/17 05:02:49 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int i=0;
void	test()
{
	i++;
	sleep(3);
	printf("wali iewaren %d \n",i);
	sleep(2);
	printf("\n");
	printf("wali iewaren %d \n",i);
}
void	test2()
{
	sleep(3);
	printf("wissin ayd  %d \n",i);
	sleep(1);
	i--;
	printf("wissin ayd2 %d \n",i);
}

int	main(int ac, char **av)
{
	pthread_t	t1;
	pthread_t	t2;
	pthread_create(&t1,NULL,&test,NULL);
	pthread_create(&t2,NULL,&test2,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	return (0);
}
