/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 05:01:30 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/06/23 14:26:35 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# define ERROR_MESSAGE " program should take the following arguments:\n\
number_of_philos time_to_die time_to_eat time_to_sleep \
[number_of_times_each_philosopher_must_eat](optional)"

# include <semaphore.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_vars
{
	int				nbr_of_philos;
	u_int64_t		time_to_die;
	u_int64_t		time_to_eat;
	u_int64_t		time_to_sleep;
	int				nbr_of_meals;
	sem_t			*forks_sem;
	sem_t			*print_lock;
	sem_t			*kill_lock;
	// u_int64_t	start_time;
}	t_vars;

typedef struct s_philo
{
	int			id;
	int			death_switch;
	int			meals_count;
	u_int64_t	last_meal_time;
	pthread_t	philo_thread;
	u_int64_t	start_time;
	t_vars		*vars;
}	t_philo;

void		print(char *color, t_philo *philo, char *str);
t_vars		*init_args(int ac, char **av, t_vars *vars);
void		*ft_calloc(size_t count, size_t size);
t_philo		*init_philo(int ac, char **av);
void		ft_msleep(u_int64_t time);
u_int64_t	ft_gettime_inms(void);
int			ft_atoi(char *str);
int			ft_fork(void);
#endif