/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadigh <kadigh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 01:37:21 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/05/08 17:26:26 by kadigh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stddef.h>

typedef struct vars
{
	int nbr_of_philos;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int nbr_of_times_each_philo_must_eat;
} t_vars;

void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(char *s);
int	ft_atoi(char *str);


void	init_args(int ac, char **av, t_vars *vars);
int error(char *str);

#endif 