/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 01:37:21 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/05/12 01:24:07 by aaoutem-         ###   ########.fr       */
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

// struct s_philo ;

// typedef	struct s_philo t_philo;

// typedef struct s_vars
// {
// 	int nbr_of_philos;
// 	int time_to_die;
// 	int time_to_eat;
// 	int time_to_sleep;
// 	int nbr_of_times_each_philo_must_eat;
// } t_vars;

typedef struct s_forks
{
	int				id;
	pthread_mutex_t	*forks;
}	t_forks;


typedef	struct s_philo
{
	int			id;
	int			state;
	pthread_t	*thread;
	pthread_mutex_t	right_fork;
	pthread_mutex_t	left_fork;
}	t_philo;

typedef	 struct data
{
	int nbr_of_philos;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int nbr_of_times_each_philo_must_eat;
	pthread_t		*philos_thread;
	t_philo			*philos;
	t_forks			*forks;
}	t_data;

size_t	ft_strlen(char *s);
void	*ft_calloc(size_t count, size_t size);
int		ft_atoi(char *str);

void	init_args(int ac, char **av, t_data **data);
int		error(char *str);

#endif 
