/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:43:02 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/06/22 14:27:33 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parse(int ac, char **av)
{
	int	i;

	if (ft_atoi(av[1]) <= 0 || ft_atoi(av[1]) > 200)
	{
		write(2, "Invalid argument\n", 17);
		return (-1);
	}
	i = 2;
	while (i < ac)
	{
		if (ft_atoi(av[i]) < 60)
		{
			write(2, "Invalid argument\n", 17);
			return (-1);
		}
		i++;
	}
	return (1);
}
