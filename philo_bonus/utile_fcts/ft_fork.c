/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 12:51:37 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/06/23 12:54:26 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

int	ft_fork(void)
{
	int pid;

	pid = fork();
	if (pid < 0)
	{
		printf("Error: fork failed\n");
		exit(EXIT_FAILURE);
	}
	return (pid);
}