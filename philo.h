/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 01:37:21 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/06/04 08:47:11 by aaoutem-         ###   ########.fr       */
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
# include <sys/time.h>

typedef struct s_vars
{
	int			nbr_of_philos;
	u_int64_t	time_to_die;
	u_int64_t	time_to_eat;
	u_int64_t	time_to_sleep;
	int			nbrof_meals;
} t_vars;

typedef	struct s_philo
{
	int				id;
	int				state;
	int				*dead;
	pthread_mutex_t	*death_mutex;
	int				meals_count;
	u_int64_t		start_time;
	u_int64_t		last_meal_time;
	t_vars			*vars;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
}	t_philo;

typedef	 struct data
{
	t_vars			*vars;
	int				dead;
	pthread_mutex_t	*death_mutex;
	// t_philo			**philos;
	pthread_t		*philos_thread;
	pthread_mutex_t	*forks;
	u_int64_t		start_time;
}	t_data;

size_t		ft_strlen(char *s);
void		*ft_calloc(size_t count, size_t size);
int			ft_atoi(char *str);
void		init_args(int ac, char **av, t_data **data);
void	 	ft_msleep(unsigned int time);
int			error(char *str);
u_int64_t	ft_mstime(void);
void		*check_death(t_philo *philo);

#endif 
