/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 01:39:28 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/06/05 09:17:48 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo_bonus.h"

int main(int ac, char **av)
{
	t_vars	*vars;

	vars = ft_calloc(1, sizeof(t_vars));
	if (ac > 6 || ac < 5)
	{
		// error
		return (0);
	}
	init_args(ac, av, vars);
	while (1)
}